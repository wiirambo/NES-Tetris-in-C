/*
	olc::NES - Part #5 - PPU Rendering - Foregrounds
	"Thanks Dad for believing computers were gonna be a big deal..." - javidx9

	License (OLC-3)
	~~~~~~~~~~~~~~~

	Copyright 2018-2019 OneLoneCoder.com

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions
	are met:

	1. Redistributions or derivations of source code must retain the above
	copyright notice, this list of conditions and the following disclaimer.

	2. Redistributions or derivative works in binary form must reproduce
	the above copyright notice. This list of conditions and the following
	disclaimer must be reproduced in the documentation and/or other
	materials provided with the distribution.

	3. Neither the name of the copyright holder nor the names of its
	contributors may be used to endorse or promote products derived
	from this software without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
	"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
	A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
	HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
	LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
	DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
	THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


	Relevant Video: https://youtu.be/cksywUTZxlY

	Links
	~~~~~
	YouTube:	https://www.youtube.com/javidx9
				https://www.youtube.com/javidx9extra
	Discord:	https://discord.gg/WhwHUMV
	Twitter:	https://www.twitter.com/javidx9
	Twitch:		https://www.twitch.tv/javidx9
	GitHub:		https://www.github.com/onelonecoder
	Patreon:	https://www.patreon.com/javidx9
	Homepage:	https://www.onelonecoder.com

	Author
	~~~~~~
	David Barr, aka javidx9, ©OneLoneCoder 2019
*/

#include <iostream>
#include <sstream>
#include <deque>
#include <thread>
#include "nestetrisclockcyclesuint8_t.h"

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#define OLC_PGEX_SOUND
#include "olcPGEX_Sound.h"

#include "Bus.h"
class olcNES : public olc::PixelGameEngine
{
public:
	bool renderOutput = true;
	int speedFactor = 1;
	int frameCouterSpeedUp = 0;
	bool useCCode = false;
	bool outputAudio = true;
	int id;

private:
	std::vector<std::string> game_genie_codes;
	std::string pathToMovie = "";
	std::string pathToSave = "";
	bool playMovie = false;
	bool recordMovie = false;
	std::ifstream movieFile;
	std::ofstream saveFile;
	int readLines = 0;

public:
	olcNES() { 
		id = 0;
		sAppName = "NES Tetris in C";
		calculateBaseAddress(id);
		nes.connectNES(this);
	}
	//I realy just should make the copy constructor work
	olcNES(bool renderOutput, int speedFactor, bool useCCode, bool outputAudio, std::string pathToMovie, std::string pathToSave, bool playMovie, bool recordMovie, int id) {
		calculateBaseAddress(id);

		this->renderOutput = renderOutput;
		this->speedFactor = speedFactor;
		this->useCCode = useCCode;
		this->outputAudio = outputAudio;

		this->pathToMovie = pathToMovie;
		this->pathToSave = pathToSave;
		this->playMovie = playMovie;
		this->recordMovie = recordMovie;

		this->id = id;

		nes.connectNES(this);
		sAppName = "NES Tetris in C";
	}

	void use_game_genie_code(std::string game_genie_code) {
		game_genie_codes.push_back(game_genie_code);
	}

	void onFrameEnd() {
		if (playMovie == true) {
			std::string inputString;
			uint8_t buttonCode = 0;
			if (getline(movieFile, inputString)) {
				for (int i = 10; i > 2; i--) {
					buttonCode = buttonCode << 1;
					if (inputString[i] != '.') {
						buttonCode = buttonCode | 1;
					}
				}
				nes.controller[0] = buttonCode;
			}
			else {
				std::cout << "Movie finished playing" << std::endl;
			}
			//std::cout << inputString << std::endl;
		}

		if (recordMovie == true) {
			// Handle input for controller in port #1
			nes.controller[0] = 0x00;
			nes.controller[0] |= GetKey(olc::Key::X).bHeld ? 0x80 : 0x00;     // A Button
			nes.controller[0] |= GetKey(olc::Key::Y).bHeld ? 0x40 : 0x00;     // B Button
			nes.controller[0] |= GetKey(olc::Key::A).bHeld ? 0x20 : 0x00;     // Select
			nes.controller[0] |= GetKey(olc::Key::S).bHeld ? 0x10 : 0x00;     // Start
			nes.controller[0] |= GetKey(olc::Key::UP).bHeld ? 0x08 : 0x00;
			nes.controller[0] |= GetKey(olc::Key::DOWN).bHeld ? 0x04 : 0x00;
			nes.controller[0] |= GetKey(olc::Key::LEFT).bHeld ? 0x02 : 0x00;
			nes.controller[0] |= GetKey(olc::Key::RIGHT).bHeld ? 0x01 : 0x00;

			//reset not possible

			std::string inputString = "|0|";
			if ((nes.controller[0] & 0x01) != 0) {
				inputString += "R";
			}
			else {
				inputString += ".";
			}
			if ((nes.controller[0] & 0x02) != 0) {
				inputString += "L";
			}
			else {
				inputString += ".";
			}
			if ((nes.controller[0] & 0x04) != 0) {
				inputString += "D";
			}
			else {
				inputString += ".";
			}
			if ((nes.controller[0] & 0x08) != 0) {
				inputString += "U";
			}
			else {
				inputString += ".";
			}
			if ((nes.controller[0] & 0x10) != 0) {
				inputString += "T";
			}
			else {
				inputString += ".";
			}
			if ((nes.controller[0] & 0x20) != 0) {
				inputString += "S";
			}
			else {
				inputString += ".";
			}
			if ((nes.controller[0] & 0x40) != 0) {
				inputString += "B";
			}
			else {
				inputString += ".";
			}
			if ((nes.controller[0] & 0x80) != 0) {
				inputString += "A";
			}
			else {
				inputString += ".";
			}

			inputString += "|||";

			saveFile << inputString << std::endl;
		}
	}

private: 
	// The NES
	Bus nes;
	std::shared_ptr<Cartridge> cart;
	bool bEmulationRun = false;
	float fResidualTime = 0.0f;

	uint8_t nSelectedPalette = 0x00;

	std::list<uint16_t> audio[4];
	float fAccumulatedTime = 0.0f;

private: 
	// Support Utilities
	std::map<uint16_t, std::string> mapAsm;

	std::string hex(uint32_t n, uint8_t d)
	{
		std::string s(d, '0');
		for (int i = d - 1; i >= 0; i--, n >>= 4)
			s[i] = "0123456789ABCDEF"[n & 0xF];
		return s;
	};

	void DrawRam(int x, int y, uint16_t nAddr, int nRows, int nColumns)
	{
		int nRamX = x, nRamY = y;
		for (int row = 0; row < nRows; row++)
		{
			std::string sOffset = "$" + hex(nAddr, 4) + ":";
			for (int col = 0; col < nColumns; col++)
			{
				sOffset += " " + hex(nes.cpuRead(nAddr, true), 2);
				nAddr += 1;
			}
			DrawString(nRamX, nRamY, sOffset);
			nRamY += 10;
		}
	}

	void DrawCpu(int x, int y)
	{
		std::string status = "STATUS: ";
		DrawString(x , y , "STATUS:", olc::WHITE);
		DrawString(x  + 64, y, "N", nes.cpu.status & olc6502::N ? olc::GREEN : olc::RED);
		DrawString(x  + 80, y , "V", nes.cpu.status & olc6502::V ? olc::GREEN : olc::RED);
		DrawString(x  + 96, y , "-", nes.cpu.status & olc6502::U ? olc::GREEN : olc::RED);
		DrawString(x  + 112, y , "B", nes.cpu.status & olc6502::B ? olc::GREEN : olc::RED);
		DrawString(x  + 128, y , "D", nes.cpu.status & olc6502::D ? olc::GREEN : olc::RED);
		DrawString(x  + 144, y , "I", nes.cpu.status & olc6502::I ? olc::GREEN : olc::RED);
		DrawString(x  + 160, y , "Z", nes.cpu.status & olc6502::Z ? olc::GREEN : olc::RED);
		DrawString(x  + 178, y , "C", nes.cpu.status & olc6502::C ? olc::GREEN : olc::RED);
		DrawString(x , y + 10, "PC: $" + hex(nes.cpu.pc, 4));
		DrawString(x , y + 20, "A: $" +  hex(nes.cpu.a, 2) + "  [" + std::to_string(nes.cpu.a) + "]");
		DrawString(x , y + 30, "X: $" +  hex(nes.cpu.x, 2) + "  [" + std::to_string(nes.cpu.x) + "]");
		DrawString(x , y + 40, "Y: $" +  hex(nes.cpu.y, 2) + "  [" + std::to_string(nes.cpu.y) + "]");
		DrawString(x , y + 50, "Stack P: $" + hex(nes.cpu.stkp, 4));
	}

	void DrawCode(int x, int y, int nLines)
	{
		auto it_a = mapAsm.find(nes.cpu.pc);
		int nLineY = (nLines >> 1) * 10 + y;
		if (it_a != mapAsm.end())
		{
			DrawString(x, nLineY, (*it_a).second, olc::CYAN);
			while (nLineY < (nLines * 10) + y)
			{
				nLineY += 10;
				if (++it_a != mapAsm.end())
				{
					DrawString(x, nLineY, (*it_a).second);
				}
			}
		}

		it_a = mapAsm.find(nes.cpu.pc);
		nLineY = (nLines >> 1) * 10 + y;
		if (it_a != mapAsm.end())
		{
			while (nLineY > y)
			{
				nLineY -= 10;
				if (--it_a != mapAsm.end())
				{
					DrawString(x, nLineY, (*it_a).second);
				}
			}
		}
	}

	void DrawAudio(int channel, int x, int y)
	{
		FillRect(x, y, 120, 120, olc::BLACK);
		int i = 0;
		for (auto s : audio[channel])
		{
			Draw(x + i, y + (s >> (channel == 2 ? 5 : 4)), olc::YELLOW);
			i++;
		}
	}

	// This function is called by the underlying sound hardware
	// which runs in a different thread. It is automatically
	// synchronised with the sample rate of the sound card, and
	// expects a single "sample" to be returned, whcih ultimately
	// makes its way to your speakers, and then your ears, for that
	// lovely 8-bit bliss... but, that means we've some thread
	// handling to deal with, since we want both the PGE thread
	// and the sound system thread to interact with the emulator.

	static olcNES* pInstance; // Static variable that will hold a pointer to "this"

	static float SoundOut(int nChannel, float fGlobalTime, float fTimeStep)
	{
		if (nChannel == 0)
		{
			while (!pInstance->nes.clock()) {};
			return static_cast<float>(pInstance->nes.dAudioSample);
		}
		else
			return 0.0f;
	}

	bool OnUserCreate() override
	{
		if (playMovie == true) {
			std::string line;
			movieFile = std::ifstream(pathToMovie);
			if (movieFile.is_open())
			{
				getline(movieFile, line);
				while (line[0] != '|')
				{
					std::cout << line << std::endl;
					getline(movieFile, line);
				}
				getline(movieFile, line);//skip first input to syncronize with fceux
				std::cout << line << std::endl;
			}
			else {
				std::cout << "Unable to open file " << pathToMovie << std::endl;
			}
		}

		if (recordMovie == true) {
			saveFile = std::ofstream(pathToSave);
			if (saveFile.is_open())
			{
				saveFile << "version 3" << std::endl;
				saveFile << "emuVersion 20603" << std::endl;
				saveFile << "rerecordCount 0" << std::endl;
				saveFile << "palFlag 0" << std::endl;
				saveFile << "romFilename Tetris(USA)_C_Code" << std::endl;
				saveFile << "romChecksum base64 : Ww5XFVjIx5aTe5avRpVhxg==" << std::endl;
				saveFile << "guid 4AA77D98 - A0EA - 1431 - A39B - 2485A8A002AA" << std::endl; //for what?
				saveFile << "fourscore 0" << std::endl;
				saveFile << "microphone 0" << std::endl;
				saveFile << "port0 1" << std::endl;
				saveFile << "port1 0" << std::endl;
				saveFile << "port2 0" << std::endl;
				saveFile << "FDS 0" << std::endl;
				saveFile << "NewPPU 0" << std::endl;
				saveFile << "RAMInitOption 0" << std::endl;
				saveFile << "RAMInitSeed 6924" << std::endl;
				saveFile << "comment author WiiRambo" << std::endl;
				saveFile << "|0|........|||" << std::endl; //two extra input to sync with FCEUX
				saveFile << "|0|........|||" << std::endl; //two extra input to sync with FCEUX
			}
			else {
				std::cout << "Unable to open file " << pathToSave << std::endl;
			}
		}
		// Load the cartridge
		//cart = std::make_shared<Cartridge>("../nestest.nes");
		cart = std::make_shared<Cartridge>("C:/Users/User/Desktop/Tetris/Tetris (USA).nes", &nes);
		//cart = std::make_shared<Cartridge>("C:/Users/User/Desktop/Tetris/7DigitScore.nes", &nes);
		//cart = std::make_shared<Cartridge>("C:/Users/User/Desktop/Tetris/6to7DigitScore.nes", &nes);
		//cart = std::make_shared<Cartridge>("C:/Users/User/Desktop/Tetris/speedhack1.1.nes", &nes);
		//cart = std::make_shared<Cartridge>("C:/Users/User/Desktop/Tetris/palmode.nes");
		//cart = std::make_shared<Cartridge>("C:/Users/User/Desktop/Tetris/Super Mario Bros. (World).nes");
		//cart = std::make_shared<Cartridge>("C:/Users/User/Desktop/Tetris/Super Mario Bros. + Tetris + Nintendo World Cup (Europe).nes");
		//cart = std::make_shared<Cartridge>("C:/Users/User/Desktop/Tetris/Tetris (Europe).nes");

		if (!cart->ImageValid())
			return false;

		for (auto iterator = game_genie_codes.begin(); iterator != game_genie_codes.end(); iterator++) {
			apply_game_genie_code((*iterator).c_str(), (int)(*iterator).size());
		}

		cart->connectBus(&nes);
		// Insert into NES
		nes.insertCartridge(cart);
		
		// Extract dissassembly
		//mapAsm = nes.cpu.disassemble(0x0000, 0xFFFF);

		

		for (int i = 0; i < 4; i++)
		{			
			for (int j = 0; j < 120; j++)
				audio[i].push_back(0);
		}
		
		// Reset NES
		nes.reset();

		// Initialise PGEX sound system, and give it a function to 
		// call which returns a sound sample on demand
		pInstance = this;

		if (speedFactor == 1) { //no sound when in speedup mode
			nes.SetSampleFrequency(44100);
			olc::SOUND::InitialiseAudio(44100, 1, 8, 512);
			olc::SOUND::SetUserSynthFunction(SoundOut);
		}

		return true;
	}

	// We must play nicely now with the sound hardware, so unload
	// it when the application terminates
	bool OnUserDestroy() override
	{
		olc::SOUND::DestroyAudio();
		if (playMovie == true) {
			movieFile.close();
		}
		if (recordMovie == true) {
			saveFile.close();
		}

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		EmulatorUpdateWithAudio(fElapsedTime);
		return true;
	}

	// This performs an emulation update but synced to audio, so it cant
	// perform stepping through code or frames. Essentially, it runs
	// the emulation in real time now, so only accepts "controller" input
	// and updates the display
	bool EmulatorUpdateWithAudio(float fElapsedTime)
	{
		if (speedFactor > 1) {
			renderOutput = false;
			for (frameCouterSpeedUp = 1; frameCouterSpeedUp < speedFactor;) {
				frameCouterSpeedUp++;
				do {
					nes.clock();
				} while (!nes.ppu.frame_complete);
				nes.ppu.frame_complete = false;
			}
			renderOutput = true;
			do {
				nes.clock();
			} while (!nes.ppu.frame_complete);
			nes.ppu.frame_complete = false;
		}

		Clear(olc::DARK_BLUE);
		if (playMovie == false && recordMovie == false) {
			// Handle input for controller in port #1
			nes.controller[0] = 0x00;
			nes.controller[0] |= GetKey(olc::Key::X).bHeld ? 0x80 : 0x00;     // A Button
			nes.controller[0] |= GetKey(olc::Key::Y).bHeld ? 0x40 : 0x00;     // B Button
			nes.controller[0] |= GetKey(olc::Key::A).bHeld ? 0x20 : 0x00;     // Select
			nes.controller[0] |= GetKey(olc::Key::S).bHeld ? 0x10 : 0x00;     // Start
			nes.controller[0] |= GetKey(olc::Key::UP).bHeld ? 0x08 : 0x00;
			nes.controller[0] |= GetKey(olc::Key::DOWN).bHeld ? 0x04 : 0x00;
			nes.controller[0] |= GetKey(olc::Key::LEFT).bHeld ? 0x02 : 0x00;
			nes.controller[0] |= GetKey(olc::Key::RIGHT).bHeld ? 0x01 : 0x00;

			if (GetKey(olc::Key::R).bPressed) nes.reset();
			if (GetKey(olc::Key::P).bPressed) (++nSelectedPalette) &= 0x07;
		}


		
		//Sample audio channel output roughly once per frame
		if (speedFactor <= 1) {
			fAccumulatedTime += fElapsedTime;
			if (fAccumulatedTime >= 1.0f / 60.0f)
			{
				fAccumulatedTime -= (1.0f / 60.0f);
				audio[0].pop_front();
				audio[0].push_back(nes.apu.pulse1_visual);
				audio[1].pop_front();
				audio[1].push_back(nes.apu.pulse2_visual);
				audio[2].pop_front();
				audio[2].push_back(nes.apu.noise_visual);
			}
			DrawCpu(516, 2);
			//DrawCode(516, 72, 26);

			// Draw OAM Contents (first 26 out of 64) ======================================
			/*for (int i = 0; i < 26; i++)
			{
				std::string s = hex(i, 2) + ": (" + std::to_string(nes.ppu.pOAM[i * 4 + 3])
					+ ", " + std::to_string(nes.ppu.pOAM[i * 4 + 0]) + ") "
					+ "ID: " + hex(nes.ppu.pOAM[i * 4 + 1], 2) +
					+" AT: " + hex(nes.ppu.pOAM[i * 4 + 2], 2);
				DrawString(516, 72 + i * 10, s);
			}*/

			// Draw AUDIO Channels
			DrawAudio(0, 520, 72);
			DrawAudio(1, 644, 72);
			DrawAudio(2, 520, 196);
			DrawAudio(3, 644, 196);

			// Draw Palettes & Pattern Tables ==============================================
			const int nSwatchSize = 6;
			for (int p = 0; p < 8; p++) // For each palette
				for (int s = 0; s < 4; s++) // For each index
					FillRect(516 + p * (nSwatchSize * 5) + s * nSwatchSize, 340,
						nSwatchSize, nSwatchSize, nes.ppu.GetColourFromPaletteRam(p, s));

			// Draw selection reticule around selected palette
			DrawRect(516 + nSelectedPalette * (nSwatchSize * 5) - 1, 339, (nSwatchSize * 4), nSwatchSize, olc::WHITE);

			// Generate Pattern Tables
			DrawSprite(516, 348, &nes.ppu.GetPatternTable(0, nSelectedPalette));
			DrawSprite(648, 348, &nes.ppu.GetPatternTable(1, nSelectedPalette));
		}

		// Draw rendered output ========================================================
		DrawSprite(0, 0, &nes.ppu.GetScreen(), 2);
		
		return true;
	}

	// This performs emulation with no audio synchronisation, so it is just
	// as before, in all the previous videos
	bool EmulatorUpdateWithoutAudio(float fElapsedTime)
	{
		Clear(olc::DARK_BLUE);

		// Handle input for controller in port #1
		nes.controller[0] = 0x00;
		nes.controller[0] |= GetKey(olc::Key::X).bHeld ? 0x80 : 0x00;     // A Button
		nes.controller[0] |= GetKey(olc::Key::Z).bHeld ? 0x40 : 0x00;     // B Button
		nes.controller[0] |= GetKey(olc::Key::A).bHeld ? 0x20 : 0x00;     // Select
		nes.controller[0] |= GetKey(olc::Key::S).bHeld ? 0x10 : 0x00;     // Start
		nes.controller[0] |= GetKey(olc::Key::UP).bHeld ? 0x08 : 0x00;
		nes.controller[0] |= GetKey(olc::Key::DOWN).bHeld ? 0x04 : 0x00;
		nes.controller[0] |= GetKey(olc::Key::LEFT).bHeld ? 0x02 : 0x00;
		nes.controller[0] |= GetKey(olc::Key::RIGHT).bHeld ? 0x01 : 0x00;

		if (GetKey(olc::Key::SPACE).bPressed) bEmulationRun = !bEmulationRun;
		if (GetKey(olc::Key::R).bPressed) nes.reset();
		if (GetKey(olc::Key::P).bPressed) (++nSelectedPalette) &= 0x07;

		if (bEmulationRun)
		{
			if (fResidualTime > 0.0f)
				fResidualTime -= fElapsedTime;
			else
			{
				//std::cout << "New Frame " << fElapsedTime << std::endl;
				fResidualTime += (1.0f / 60.0f) - fElapsedTime;
				do { nes.clock(); } while (!nes.ppu.frame_complete);
				nes.ppu.frame_complete = false;
			}
		}
		else
		{
			// Emulate code step-by-step
			if (GetKey(olc::Key::C).bPressed)
			{
				// Clock enough times to execute a whole CPU instruction
				do { nes.clock(); } while (!nes.cpu.complete());
				// CPU clock runs slower than system clock, so it may be
				// complete for additional system clock cycles. Drain
				// those out
				do { nes.clock(); } while (nes.cpu.complete());
			}

			// Emulate one whole frame
			if (GetKey(olc::Key::F).bPressed)
			{
				// Clock enough times to draw a single frame
				do { nes.clock(); } while (!nes.ppu.frame_complete);
				// Use residual clock cycles to complete current instruction
				do { nes.clock(); } while (!nes.cpu.complete());
				// Reset frame completion flag
				nes.ppu.frame_complete = false;
			}
		}

		DrawCpu(516, 2);
		//DrawCode(516, 72, 26);

		// Draw OAM Contents (first 26 out of 64) ======================================
		/*for (int i = 0; i < 26; i++)
		{
			std::string s = hex(i, 2) + ": (" + std::to_string(nes.ppu.pOAM[i * 4 + 3])
				+ ", " + std::to_string(nes.ppu.pOAM[i * 4 + 0]) + ") "
				+ "ID: " + hex(nes.ppu.pOAM[i * 4 + 1], 2) +
				+" AT: " + hex(nes.ppu.pOAM[i * 4 + 2], 2);
			DrawString(516, 72 + i * 10, s);
		}*/

		// Draw Palettes & Pattern Tables ==============================================
		const int nSwatchSize = 6;
		for (int p = 0; p < 8; p++) // For each palette
			for (int s = 0; s < 4; s++) // For each index
				FillRect(516 + p * (nSwatchSize * 5) + s * nSwatchSize, 340,
					nSwatchSize, nSwatchSize, nes.ppu.GetColourFromPaletteRam(p, s));

		// Draw selection reticule around selected palette
		DrawRect(516 + nSelectedPalette * (nSwatchSize * 5) - 1, 339, (nSwatchSize * 4), nSwatchSize, olc::WHITE);

		// Generate Pattern Tables
		DrawSprite(516, 348, &nes.ppu.GetPatternTable(0, nSelectedPalette));
		DrawSprite(648, 348, &nes.ppu.GetPatternTable(1, nSelectedPalette));

		// Draw rendered output ========================================================
		DrawSprite(0, 0, &nes.ppu.GetScreen(), 2);
		return true;
	}
};

// Provide implementation for our static pointer
olcNES* olcNES::pInstance = nullptr;

void runModdedInstance();
void runUnmoddedInstance();

int main()
{
	runModdedInstance();
	//runUnmoddedInstance();

	return 0;
}

void runModdedInstance() {
	//std::string pathToMovie = "C:/Program Files/fceux-2.6.3-win32/movies/acmlm-tetris-fastest999999.fm2";
	//std::string pathToMovie = "C:/Program Files/fceux-2.6.3-win32/movies/BuggedLevelUp.fm2";
	//std::string pathToMovie = "C:/Program Files/fceux-2.6.3-win32/movies/LEVEL 256.fm2"; 
	//std::string pathToMovie = "C:/Program Files/fceux-2.6.3-win32/movies/Crash Fix.fm2";
	//std::string pathToMovie = "C:/Program Files/fceux-2.6.3-win32/movies/PushDown.fm2";
	//std::string pathToMovie = "C:/Program Files/fceux-2.6.3-win32/movies/BType.fm2";
	std::string pathToMovie = "C:/Program Files/fceux-2.6.3-win32/movies/r57shell_archanfel-tetris-maxscore.fm2";
	//std::string pathToMovie = "C:/Program Files/fceux-2.6.3-win32/movies/Test.fm2";
	std::string pathToSave = "C:/Program Files/fceux-2.6.3-win32/movies/Test.fm2";
	olcNES demo(true, 35, true, false, pathToMovie, pathToSave, true, false, 0);
	demo.Construct(780, 480, 2, 2);
	demo.Start();
}
void runUnmoddedInstance() {
	std::string pathToMovie = "C:/Program Files/fceux-2.6.3-win32/movies/r57shell_archanfel-tetris-maxscore.fm2";
	//std::string pathToMovie = "C:/Program Files/fceux-2.6.3-win32/movies/BuggedLevelUp.fm2";
	//std::string pathToMovie = "C:/Program Files/fceux-2.6.3-win32/movies/BType.fm2";
	//std::string pathToMovie = "C:/Program Files/fceux-2.6.3-win32/movies/acmlm-tetris-fastest999999.fm2";
	//std::string pathToMovie = "C:/Program Files/fceux-2.6.3-win32/movies/Crash Fix.fm2";
	std::string pathToSave = "C:/Program Files/fceux-2.6.3-win32/movies/test.fm2";
	olcNES demo2(true, 5, false, false, pathToMovie, pathToSave, true, false, 0);
	//demo2.use_game_genie_code("ASAPKG");
	//demo2.use_game_genie_code("TEAPSK");
	demo2.Construct(780, 480, 2, 2);
	demo2.Start();
}

//These functions were moved here so it is after the implementation of the olcNES

void olc2C02::ConnectBus(Bus* connectedBus) {
	bus = connectedBus;
	tblName[0] = getAddressSpace(bus->nes->id) + 0x2000;
}

void Bus::connectNES(olcNES* connectedNES) {
	nes = connectedNES;
	cpuRam = getAddressSpace(nes->id);
	// Connect CPU to communication bus
	cpu.ConnectBus(this);
	ppu.ConnectBus(this);
}

Cartridge::Cartridge(const std::string& sFileName, Bus* connectedBus)
{
	bus = connectedBus;
	vPRGMemory = getAddressSpace(bus->nes->id) + 0x8000;

	// iNES Format Header
	struct sHeader
	{
		char name[4];
		uint8_t prg_rom_chunks;
		uint8_t chr_rom_chunks;
		uint8_t mapper1;
		uint8_t mapper2;
		uint8_t prg_ram_size;
		uint8_t tv_system1;
		uint8_t tv_system2;
		char unused[5];
	} header;

	bImageValid = false;

	std::ifstream ifs;
	ifs.open(sFileName, std::ifstream::binary);
	if (ifs.is_open())
	{
		// Read file header
		ifs.read((char*)&header, sizeof(sHeader));

		// If a "trainer" exists we just need to read past
		// it before we get to the good stuff
		if (header.mapper1 & 0x04)
			ifs.seekg(512, std::ios_base::cur);

		// Determine Mapper ID
		nMapperID = ((header.mapper2 >> 4) << 4) | (header.mapper1 >> 4);
		hw_mirror = (header.mapper1 & 0x01) ? VERTICAL : HORIZONTAL;

		hw_mirror = ONESCREEN_LO; //forces correct mirroring for NES Tetris

		// "Discover" File Format
		uint8_t nFileType = 1;
		if ((header.mapper2 & 0x0C) == 0x08) nFileType = 2;

		if (nFileType == 0)
		{

		}

		if (nFileType == 1)
		{
			nPRGBanks = header.prg_rom_chunks;
			ifs.read((char*)vPRGMemory, nPRGBanks * 16384);

			nCHRBanks = header.chr_rom_chunks;
			if (nCHRBanks == 0)
			{
				// Create CHR RAM
				vCHRMemory.resize(8192);
			}
			else
			{
				// Allocate for ROM
				vCHRMemory.resize(nCHRBanks * 8192);
			}
			ifs.read((char*)vCHRMemory.data(), vCHRMemory.size());
		}

		if (nFileType == 2)
		{
			nPRGBanks = ((header.prg_ram_size & 0x07) << 8) | header.prg_rom_chunks;
			ifs.read((char*)vPRGMemory, nPRGBanks * 16384);

			nCHRBanks = ((header.prg_ram_size & 0x38) << 8) | header.chr_rom_chunks;
			vCHRMemory.resize(nCHRBanks * 8192);
			ifs.read((char*)vCHRMemory.data(), vCHRMemory.size());
		}

		// Load appropriate mapper
		uint8_t mapperID = nMapperID;
		switch (mapperID)
		{
		case   0: pMapper = std::make_shared<Mapper_000>(nPRGBanks, nCHRBanks); break;
		case   1: pMapper = std::make_shared<Mapper_001>(nPRGBanks, nCHRBanks); break;
		case   2: pMapper = std::make_shared<Mapper_002>(nPRGBanks, nCHRBanks); break;
		case   3: pMapper = std::make_shared<Mapper_003>(nPRGBanks, nCHRBanks); break;
		case   4: pMapper = std::make_shared<Mapper_004>(nPRGBanks, nCHRBanks); break;
		case  66: pMapper = std::make_shared<Mapper_066>(nPRGBanks, nCHRBanks); break;

		}

		bImageValid = true;
		ifs.close();
	}

}

void olc6502::ConnectBus(Bus* connectedBus) {
	bus = connectedBus;
	useCCode = bus->nes->useCCode;
	setRegisters(&a, &x, &y);
}

bool Bus::clock()
{
	// Clocking. The heart and soul of an emulator. The running
	// frequency is controlled by whatever calls this function.
	// So here we "divide" the clock as necessary and call
	// the peripheral devices clock() function at the correct
	// times.

	// The fastest clock frequency the digital system cares
	// about is equivalent to the PPU clock. So the PPU is clocked
	// each time this function is called...

	ppu.clock();

	// ...also clock the APU
	if (nes->outputAudio == true) {//disables audio output
		apu.clock();
	}

	// The CPU runs 3 times slower than the PPU so we only call its
	// clock() function every 3 times this function is called. We
	// have a global counter to keep track of this.
	if (nSystemClockCounter % 3 == 0)
	{
		// Is the system performing a DMA transfer form CPU memory to 
		// OAM memory on PPU?...
		if (dma_transfer)
		{
			// ...Yes! We need to wait until the next even CPU clock cycle
			// before it starts...
			if (dma_dummy)
			{
				// ...So hang around in here each clock until 1 or 2 cycles
				// have elapsed...
				if (nSystemClockCounter % 2 == 1)
				{
					// ...and finally allow DMA to start
					dma_dummy = false;
				}
			}
			else
			{
				// DMA can take place!
				if (nSystemClockCounter % 2 == 0)
				{
					// On even clock cycles, read from CPU bus
					dma_data = cpuRead(dma_page << 8 | dma_addr);
				}
				else
				{
					// On odd clock cycles, write to PPU OAM
					ppu.pOAM[dma_addr] = dma_data;
					// Increment the lo byte of the address
					dma_addr++;
					// If this wraps around, we know that 256
					// bytes have been written, so end the DMA
					// transfer, and proceed as normal
					if (dma_addr == 0x00)
					{
						dma_transfer = false;
						dma_dummy = true;
					}
				}
			}
		}
		else
		{
			// No DMA happening, the CPU is in control of its
			// own destiny. Go forth my friend and calculate
			// awesomeness for many generations to come...
			cpu.clock();
		}
	}

	// Synchronising with Audio
	bool bAudioSampleReady = false;
	if (nes->outputAudio == true) { //muted audio
		dAudioTime += dAudioTimePerNESClock;
		if (dAudioTime >= dAudioTimePerSystemSample)
		{
			dAudioTime -= dAudioTimePerSystemSample;
			dAudioSample = apu.GetOutputSample();
			bAudioSampleReady = true;
		}
	}

	// The PPU is capable of emitting an interrupt to indicate the
	// vertical blanking period has been entered. If it has, we need
	// to send that irq to the CPU.
	if (ppu.nmi)
	{
		ppu.nmi = false;
		cpu.nmi();
	}


	// Check if cartridge is requesting IRQ
	//IRQ instantly returns in NES Tetris
	if (nes->useCCode == false) {
		if (cart->GetMapper()->irqState())
		{
			cart->GetMapper()->irqClear();
			cpu.irq();
		}
	}

	nSystemClockCounter++;

	return bAudioSampleReady;
}

// Perform one clock cycles worth of emulation
void olc6502::clock()
{
	// Each instruction requires a variable number of clock cycles to execute.
	// In my emulation, I only care about the final result and so I perform
	// the entire computation in one hit. In hardware, each clock cycle would
	// perform "microcode" style transformations of the CPUs state.
	//
	// To remain compliant with connected devices, it's important that the 
	// emulation also takes "time" in order to execute instructions, so I
	// implement that delay by simply counting down the cycles required by 
	// the instruction. When it reaches 0, the instruction is complete, and
	// the next one is ready to be executed.
	if (cycles == 0)
	{
		if (pc == 0xAA32 && useCCode == true) { // wait for NMI Loop or pc == 0xAA4C
			//std::cout << "Wait for NMI PC:" << pc << std::endl;
			if (bus->nes->renderOutput == false && bus->nes->speedFactor > 1) {
				bus->ppu.scanline = 240;
				bus->ppu.cycle = 5;
			}
			else {
				if (bus->nes->speedFactor > 1) {
					while (bus->ppu.scanline < 240) {
						bus->ppu.clock();
					}
				}
			}
		}
		/*if (pc == 0xAA3B && useCCode == true) {
			std::cout << "Waited for NMI " << std::endl << std::endl;
		}*/
		// Read next instruction byte. This 8-bit value is used to index
		// the translation table to get the relevant information about
		// how to implement the instruction
		
		opcode = read(pc);

#ifdef LOGMODE
		uint16_t log_pc = pc;
#endif

		// Always set the unused status flag bit to 1
		SetFlag(U, true);

		// Increment program counter, we read the opcode byte
		pc++;

		// Get Starting number of cycles
		cycles = lookup[opcode].cycles;

		// Perform fetch of intermmediate data using the
		// required addressing mode
		uint8_t additional_cycle1 = (this->*lookup[opcode].addrmode)();

		// Perform operation
		uint8_t additional_cycle2 = (this->*lookup[opcode].operate)();

		// The addressmode and opcode may have altered the number
		// of cycles this instruction requires before its completed
		cycles += (additional_cycle1 & additional_cycle2);

		// Always set the unused status flag bit to 1
		SetFlag(U, true);

#ifdef LOGMODE
		// This logger dumps every cycle the entire processor state for analysis.
		// This can be used for debugging the emulation, but has little utility
		// during emulation. Its also very slow, so only use if you have to.
		if (logfile == nullptr)	logfile = fopen("olc6502.txt", "wt");
		if (logfile != nullptr)
		{
			fprintf(logfile, "%10d:%02d PC:%04X %s A:%02X X:%02X Y:%02X %s%s%s%s%s%s%s%s STKP:%02X\n",
				clock_count, 0, log_pc, "XXX", a, x, y,
				GetFlag(N) ? "N" : ".", GetFlag(V) ? "V" : ".", GetFlag(U) ? "U" : ".",
				GetFlag(B) ? "B" : ".", GetFlag(D) ? "D" : ".", GetFlag(I) ? "I" : ".",
				GetFlag(Z) ? "Z" : ".", GetFlag(C) ? "C" : ".", stkp);
		}
#endif
	}

	// Increment global clock count - This is actually unused unless logging is enabled
	// but I've kept it in because its a handy watch variable for debugging
	clock_count++;

	// Decrement the number of cycles remaining for this instruction
	cycles--;
}

// A Non-Maskable Interrupt cannot be ignored. It behaves in exactly the
// same way as a regular IRQ, but reads the new program counter address
// form location 0xFFFA.

/*int olc6502::skipPastNMI() {
	testCounter++;
	std::cout << "NMI! Test: " << bus->ppu.scanline << " " << bus->nes->frameCouterSpeedUp << std::endl;

	skipNMI = true;
	bus->ppu.frame_complete = false;
	bus->ppu.scanline = -1;
	bus->ppu.cycle = 2;
	bus->ppu.status.vertical_blank = 1;
	bus->nes->frameCouterSpeedUp += 1;
	bus->nes->onFrameEnd();
	//printf("NMI!\r\n");
	return 8 + NMI();
}*/

void olc6502::nmi()
{
	if (true) {
		if (useCCode == true) {
			//printf("nmi: Frame %02x%02x\r\n",bus->cpuRam[0xB2], bus->cpuRam[0xB1]);
			bus->nes->onFrameEnd();
			//printf("nmi\r\n");
			cycles += NMI();
		}
		else {
			write(0x0100 + stkp, (pc >> 8) & 0x00FF);
			stkp--;
			write(0x0100 + stkp, pc & 0x00FF);
			stkp--;

			SetFlag(B, 0);
			SetFlag(U, 1);
			SetFlag(I, 1);
			write(0x0100 + stkp, status);
			stkp--;

			addr_abs = 0xFFFA;
			uint16_t lo = read(addr_abs + 0);
			uint16_t hi = read(addr_abs + 1);
			pc = (hi << 8) | lo;

			cycles += 8;
		}
	}
	skipNMI = false;
}

void olc2C02::clock()
{
	if (bus->nes->renderOutput == false) {
		cycle++;
		if (cycle >= 341)
		{
			cycle = 0;
			scanline++;
			if (scanline >= 261)
			{
				scanline = -1;
				frame_complete = true;
				odd_frame = !odd_frame;
			}
		}
		if (scanline == 241 && cycle == 1)
		{
			// Effectively end of frame, so set vertical blank flag
			status.vertical_blank = 1;

			// If the control register tells us to emit a NMI when
			// entering vertical blanking period, do it! The CPU
			// will be informed that rendering is complete so it can
			// perform operations with the PPU knowing it wont
			// produce visible artefacts
			if (control.enable_nmi) {
				nmi = true;
				if (bus->nes->useCCode == false) {
					bus->nes->onFrameEnd();
				}
			}
			else {
				bus->nes->onFrameEnd();
			}
		}
		return;
	}
	// As we progress through scanlines and cycles, the PPU is effectively
	// a state machine going through the motions of fetching background 
	// information and sprite information, compositing them into a pixel
	// to be output.

	// The lambda functions (functions inside functions) contain the various
	// actions to be performed depending upon the output of the state machine
	// for a given scanline/cycle combination

	// ==============================================================================
	// Increment the background tile "pointer" one tile/column horizontally
	auto IncrementScrollX = [&]()
	{
		// Note: pixel perfect scrolling horizontally is handled by the 
		// data shifters. Here we are operating in the spatial domain of 
		// tiles, 8x8 pixel blocks.

		// Ony if rendering is enabled
		if (mask.render_background || mask.render_sprites)
		{
			// A single name table is 32x30 tiles. As we increment horizontally
			// we may cross into a neighbouring nametable, or wrap around to
			// a neighbouring nametable
			if (vram_addr.coarse_x == 31)
			{
				// Leaving nametable so wrap address round
				vram_addr.coarse_x = 0;
				// Flip target nametable bit
				vram_addr.nametable_x = ~vram_addr.nametable_x;
			}
			else
			{
				// Staying in current nametable, so just increment
				vram_addr.coarse_x++;
			}
		}
	};

	// ==============================================================================
	// Increment the background tile "pointer" one scanline vertically
	auto IncrementScrollY = [&]()
	{
		// Incrementing vertically is more complicated. The visible nametable
		// is 32x30 tiles, but in memory there is enough room for 32x32 tiles.
		// The bottom two rows of tiles are in fact not tiles at all, they
		// contain the "attribute" information for the entire table. This is
		// information that describes which palettes are used for different 
		// regions of the nametable.

		// In addition, the NES doesnt scroll vertically in chunks of 8 pixels
		// i.e. the height of a tile, it can perform fine scrolling by using
		// the fine_y component of the register. This means an increment in Y
		// first adjusts the fine offset, but may need to adjust the whole
		// row offset, since fine_y is a value 0 to 7, and a row is 8 pixels high

		// Ony if rendering is enabled
		if (mask.render_background || mask.render_sprites)
		{
			// If possible, just increment the fine y offset
			if (vram_addr.fine_y < 7)
			{
				vram_addr.fine_y++;
			}
			else
			{
				// If we have gone beyond the height of a row, we need to
				// increment the row, potentially wrapping into neighbouring
				// vertical nametables. Dont forget however, the bottom two rows
				// do not contain tile information. The coarse y offset is used
				// to identify which row of the nametable we want, and the fine
				// y offset is the specific "scanline"

				// Reset fine y offset
				vram_addr.fine_y = 0;

				// Check if we need to swap vertical nametable targets
				if (vram_addr.coarse_y == 29)
				{
					// We do, so reset coarse y offset
					vram_addr.coarse_y = 0;
					// And flip the target nametable bit
					vram_addr.nametable_y = ~vram_addr.nametable_y;
				}
				else if (vram_addr.coarse_y == 31)
				{
					// In case the pointer is in the attribute memory, we
					// just wrap around the current nametable
					vram_addr.coarse_y = 0;
				}
				else
				{
					// None of the above boundary/wrapping conditions apply
					// so just increment the coarse y offset
					vram_addr.coarse_y++;
				}
			}
		}
	};

	// ==============================================================================
	// Transfer the temporarily stored horizontal nametable access information
	// into the "pointer". Note that fine x scrolling is not part of the "pointer"
	// addressing mechanism
	auto TransferAddressX = [&]()
	{
		// Ony if rendering is enabled
		if (mask.render_background || mask.render_sprites)
		{
			vram_addr.nametable_x = tram_addr.nametable_x;
			vram_addr.coarse_x = tram_addr.coarse_x;
		}
	};

	// ==============================================================================
	// Transfer the temporarily stored vertical nametable access information
	// into the "pointer". Note that fine y scrolling is part of the "pointer"
	// addressing mechanism
	auto TransferAddressY = [&]()
	{
		// Ony if rendering is enabled
		if (mask.render_background || mask.render_sprites)
		{
			vram_addr.fine_y = tram_addr.fine_y;
			vram_addr.nametable_y = tram_addr.nametable_y;
			vram_addr.coarse_y = tram_addr.coarse_y;
		}
	};


	// ==============================================================================
	// Prime the "in-effect" background tile shifters ready for outputting next
	// 8 pixels in scanline.
	auto LoadBackgroundShifters = [&]()
	{
		// Each PPU update we calculate one pixel. These shifters shift 1 bit along
		// feeding the pixel compositor with the binary information it needs. Its
		// 16 bits wide, because the top 8 bits are the current 8 pixels being drawn
		// and the bottom 8 bits are the next 8 pixels to be drawn. Naturally this means
		// the required bit is always the MSB of the shifter. However, "fine x" scrolling
		// plays a part in this too, whcih is seen later, so in fact we can choose
		// any one of the top 8 bits.
		bg_shifter_pattern_lo = (bg_shifter_pattern_lo & 0xFF00) | bg_next_tile_lsb;
		bg_shifter_pattern_hi = (bg_shifter_pattern_hi & 0xFF00) | bg_next_tile_msb;

		// Attribute bits do not change per pixel, rather they change every 8 pixels
		// but are synchronised with the pattern shifters for convenience, so here
		// we take the bottom 2 bits of the attribute word which represent which 
		// palette is being used for the current 8 pixels and the next 8 pixels, and 
		// "inflate" them to 8 bit words.
		bg_shifter_attrib_lo = (bg_shifter_attrib_lo & 0xFF00) | ((bg_next_tile_attrib & 0b01) ? 0xFF : 0x00);
		bg_shifter_attrib_hi = (bg_shifter_attrib_hi & 0xFF00) | ((bg_next_tile_attrib & 0b10) ? 0xFF : 0x00);
	};


	// ==============================================================================
	// Every cycle the shifters storing pattern and attribute information shift
	// their contents by 1 bit. This is because every cycle, the output progresses
	// by 1 pixel. This means relatively, the state of the shifter is in sync
	// with the pixels being drawn for that 8 pixel section of the scanline.
	auto UpdateShifters = [&]()
	{
		if (mask.render_background)
		{
			// Shifting background tile pattern row
			bg_shifter_pattern_lo <<= 1;
			bg_shifter_pattern_hi <<= 1;

			// Shifting palette attributes by 1
			bg_shifter_attrib_lo <<= 1;
			bg_shifter_attrib_hi <<= 1;
		}

		if (mask.render_sprites && cycle >= 1 && cycle < 258)
		{
			for (int i = 0; i < sprite_count; i++)
			{
				if (spriteScanline[i].x > 0)
				{
					spriteScanline[i].x--;
				}
				else
				{
					sprite_shifter_pattern_lo[i] <<= 1;
					sprite_shifter_pattern_hi[i] <<= 1;
				}
			}
		}
	};



	// All but 1 of the secanlines is visible to the user. The pre-render scanline
	// at -1, is used to configure the "shifters" for the first visible scanline, 0.
	if (scanline >= -1 && scanline < 240)
	{
		// Background Rendering ======================================================

		if (scanline == 0 && cycle == 0 && odd_frame && (mask.render_background || mask.render_sprites))
		{
			// "Odd Frame" cycle skip
			cycle = 1;
		}

		if (scanline == -1 && cycle == 1)
		{
			// Effectively start of new frame, so clear vertical blank flag
			status.vertical_blank = 0;

			// Clear sprite overflow flag
			status.sprite_overflow = 0;

			// Clear the sprite zero hit flag
			status.sprite_zero_hit = 0;

			// Clear Shifters
			for (int i = 0; i < 8; i++)
			{
				sprite_shifter_pattern_lo[i] = 0;
				sprite_shifter_pattern_hi[i] = 0;
			}
		}


		if ((cycle >= 2 && cycle < 258) || (cycle >= 321 && cycle < 338))
		{
			UpdateShifters();


			// In these cycles we are collecting and working with visible data
			// The "shifters" have been preloaded by the end of the previous
			// scanline with the data for the start of this scanline. Once we
			// leave the visible region, we go dormant until the shifters are
			// preloaded for the next scanline.

			// Fortunately, for background rendering, we go through a fairly
			// repeatable sequence of events, every 2 clock cycles.
			switch ((cycle - 1) % 8)
			{
			case 0:
				// Load the current background tile pattern and attributes into the "shifter"
				LoadBackgroundShifters();

				// Fetch the next background tile ID
				// "(vram_addr.reg & 0x0FFF)" : Mask to 12 bits that are relevant
				// "| 0x2000"                 : Offset into nametable space on PPU address bus
				bg_next_tile_id = ppuRead(0x2000 | (vram_addr.reg & 0x0FFF));

				// Explanation:
				// The bottom 12 bits of the loopy register provide an index into
				// the 4 nametables, regardless of nametable mirroring configuration.
				// nametable_y(1) nametable_x(1) coarse_y(5) coarse_x(5)
				//
				// Consider a single nametable is a 32x32 array, and we have four of them
				//   0                1
				// 0 +----------------+----------------+
				//   |                |                |
				//   |                |                |
				//   |    (32x32)     |    (32x32)     |
				//   |                |                |
				//   |                |                |
				// 1 +----------------+----------------+
				//   |                |                |
				//   |                |                |
				//   |    (32x32)     |    (32x32)     |
				//   |                |                |
				//   |                |                |
				//   +----------------+----------------+
				//
				// This means there are 4096 potential locations in this array, which 
				// just so happens to be 2^12!
				break;
			case 2:
				// Fetch the next background tile attribute. OK, so this one is a bit
				// more involved :P

				// Recall that each nametable has two rows of cells that are not tile 
				// information, instead they represent the attribute information that
				// indicates which palettes are applied to which area on the screen.
				// Importantly (and frustratingly) there is not a 1 to 1 correspondance
				// between background tile and palette. Two rows of tile data holds
				// 64 attributes. Therfore we can assume that the attributes affect
				// 8x8 zones on the screen for that nametable. Given a working resolution
				// of 256x240, we can further assume that each zone is 32x32 pixels
				// in screen space, or 4x4 tiles. Four system palettes are allocated
				// to background rendering, so a palette can be specified using just
				// 2 bits. The attribute byte therefore can specify 4 distinct palettes.
				// Therefore we can even further assume that a single palette is
				// applied to a 2x2 tile combination of the 4x4 tile zone. The very fact
				// that background tiles "share" a palette locally is the reason why
				// in some games you see distortion in the colours at screen edges.

				// As before when choosing the tile ID, we can use the bottom 12 bits of
				// the loopy register, but we need to make the implementation "coarser"
				// because instead of a specific tile, we want the attribute byte for a 
				// group of 4x4 tiles, or in other words, we divide our 32x32 address
				// by 4 to give us an equivalent 8x8 address, and we offset this address
				// into the attribute section of the target nametable.

				// Reconstruct the 12 bit loopy address into an offset into the
				// attribute memory

				// "(vram_addr.coarse_x >> 2)"        : integer divide coarse x by 4, 
				//                                      from 5 bits to 3 bits
				// "((vram_addr.coarse_y >> 2) << 3)" : integer divide coarse y by 4, 
				//                                      from 5 bits to 3 bits,
				//                                      shift to make room for coarse x

				// Result so far: YX00 00yy yxxx

				// All attribute memory begins at 0x03C0 within a nametable, so OR with
				// result to select target nametable, and attribute byte offset. Finally
				// OR with 0x2000 to offset into nametable address space on PPU bus.				
				bg_next_tile_attrib = ppuRead(0x23C0 | (vram_addr.nametable_y << 11)
					| (vram_addr.nametable_x << 10)
					| ((vram_addr.coarse_y >> 2) << 3)
					| (vram_addr.coarse_x >> 2));

				// Right we've read the correct attribute byte for a specified address,
				// but the byte itself is broken down further into the 2x2 tile groups
				// in the 4x4 attribute zone.

				// The attribute byte is assembled thus: BR(76) BL(54) TR(32) TL(10)
				//
				// +----+----+			    +----+----+
				// | TL | TR |			    | ID | ID |
				// +----+----+ where TL =   +----+----+
				// | BL | BR |			    | ID | ID |
				// +----+----+			    +----+----+
				//
				// Since we know we can access a tile directly from the 12 bit address, we
				// can analyse the bottom bits of the coarse coordinates to provide us with
				// the correct offset into the 8-bit word, to yield the 2 bits we are
				// actually interested in which specifies the palette for the 2x2 group of
				// tiles. We know if "coarse y % 4" < 2 we are in the top half else bottom half.
				// Likewise if "coarse x % 4" < 2 we are in the left half else right half.
				// Ultimately we want the bottom two bits of our attribute word to be the
				// palette selected. So shift as required...				
				if (vram_addr.coarse_y & 0x02) bg_next_tile_attrib >>= 4;
				if (vram_addr.coarse_x & 0x02) bg_next_tile_attrib >>= 2;
				bg_next_tile_attrib &= 0x03;
				break;

				// Compared to the last two, the next two are the easy ones... :P

			case 4:
				// Fetch the next background tile LSB bit plane from the pattern memory
				// The Tile ID has been read from the nametable. We will use this id to 
				// index into the pattern memory to find the correct sprite (assuming
				// the sprites lie on 8x8 pixel boundaries in that memory, which they do
				// even though 8x16 sprites exist, as background tiles are always 8x8).
				//
				// Since the sprites are effectively 1 bit deep, but 8 pixels wide, we 
				// can represent a whole sprite row as a single byte, so offsetting
				// into the pattern memory is easy. In total there is 8KB so we need a 
				// 13 bit address.

				// "(control.pattern_background << 12)"  : the pattern memory selector 
				//                                         from control register, either 0K
				//                                         or 4K offset
				// "((uint16_t)bg_next_tile_id << 4)"    : the tile id multiplied by 16, as
				//                                         2 lots of 8 rows of 8 bit pixels
				// "(vram_addr.fine_y)"                  : Offset into which row based on
				//                                         vertical scroll offset
				// "+ 0"                                 : Mental clarity for plane offset
				// Note: No PPU address bus offset required as it starts at 0x0000
				bg_next_tile_lsb = ppuRead((control.pattern_background << 12)
					+ ((uint16_t)bg_next_tile_id << 4)
					+ (vram_addr.fine_y) + 0);

				break;
			case 6:
				// Fetch the next background tile MSB bit plane from the pattern memory
				// This is the same as above, but has a +8 offset to select the next bit plane
				bg_next_tile_msb = ppuRead((control.pattern_background << 12)
					+ ((uint16_t)bg_next_tile_id << 4)
					+ (vram_addr.fine_y) + 8);
				break;
			case 7:
				// Increment the background tile "pointer" to the next tile horizontally
				// in the nametable memory. Note this may cross nametable boundaries which
				// is a little complex, but essential to implement scrolling
				IncrementScrollX();
				break;
			}
		}

		// End of a visible scanline, so increment downwards...
		if (cycle == 256)
		{
			IncrementScrollY();
		}

		//...and reset the x position
		if (cycle == 257)
		{
			LoadBackgroundShifters();
			TransferAddressX();
		}

		// Superfluous reads of tile id at end of scanline
		if (cycle == 338 || cycle == 340)
		{
			bg_next_tile_id = ppuRead(0x2000 | (vram_addr.reg & 0x0FFF));
		}

		if (scanline == -1 && cycle >= 280 && cycle < 305)
		{
			// End of vertical blank period so reset the Y address ready for rendering
			TransferAddressY();
		}


		// Foreground Rendering ========================================================
		// I'm gonna cheat a bit here, which may reduce compatibility, but greatly
		// simplifies delivering an intuitive understanding of what exactly is going
		// on. The PPU loads sprite information successively during the region that
		// background tiles are not being drawn. Instead, I'm going to perform
		// all sprite evaluation in one hit. THE NES DOES NOT DO IT LIKE THIS! This makes
		// it easier to see the process of sprite evaluation.
		if (cycle == 257 && scanline >= 0)
		{
			// We've reached the end of a visible scanline. It is now time to determine
			// which sprites are visible on the next scanline, and preload this info
			// into buffers that we can work with while the scanline scans the row.

			// Firstly, clear out the sprite memory. This memory is used to store the
			// sprites to be rendered. It is not the OAM.
			std::memset(spriteScanline, 0xFF, 8 * sizeof(sObjectAttributeEntry));

			// The NES supports a maximum number of sprites per scanline. Nominally
			// this is 8 or fewer sprites. This is why in some games you see sprites
			// flicker or disappear when the scene gets busy.
			sprite_count = 0;

			// Secondly, clear out any residual information in sprite pattern shifters
			for (uint8_t i = 0; i < 8; i++)
			{
				sprite_shifter_pattern_lo[i] = 0;
				sprite_shifter_pattern_hi[i] = 0;
			}

			// Thirdly, Evaluate which sprites are visible in the next scanline. We need
			// to iterate through the OAM until we have found 8 sprites that have Y-positions
			// and heights that are within vertical range of the next scanline. Once we have
			// found 8 or exhausted the OAM we stop. Now, notice I count to 9 sprites. This
			// is so I can set the sprite overflow flag in the event of there being > 8 sprites.
			uint8_t nOAMEntry = 0;

			// New set of sprites. Sprite zero may not exist in the new set, so clear this
			// flag.
			bSpriteZeroHitPossible = false;

			while (nOAMEntry < 64 && sprite_count < 9)
			{
				// Note the conversion to signed numbers here
				int16_t diff = ((int16_t)scanline - (int16_t)OAM[nOAMEntry].y);

				// If the difference is positive then the scanline is at least at the
				// same height as the sprite, so check if it resides in the sprite vertically
				// depending on the current "sprite height mode"
				// FLAGGED

				if (diff >= 0 && diff < (control.sprite_size ? 16 : 8) && sprite_count < 8)
				{
					// Sprite is visible, so copy the attribute entry over to our
					// scanline sprite cache. Ive added < 8 here to guard the array
					// being written to.
					if (sprite_count < 8)
					{
						// Is this sprite sprite zero?
						if (nOAMEntry == 0)
						{
							// It is, so its possible it may trigger a 
							// sprite zero hit when drawn
							bSpriteZeroHitPossible = true;
						}

						memcpy(&spriteScanline[sprite_count], &OAM[nOAMEntry], sizeof(sObjectAttributeEntry));
					}
					sprite_count++;
				}
				nOAMEntry++;
			} // End of sprite evaluation for next scanline

			// Set sprite overflow flag
			status.sprite_overflow = (sprite_count >= 8);

			// Now we have an array of the 8 visible sprites for the next scanline. By 
			// the nature of this search, they are also ranked in priority, because
			// those lower down in the OAM have the higher priority.

			// We also guarantee that "Sprite Zero" will exist in spriteScanline[0] if
			// it is evaluated to be visible. 
		}

		if (cycle == 340)
		{
			// Now we're at the very end of the scanline, I'm going to prepare the 
			// sprite shifters with the 8 or less selected sprites.

			for (uint8_t i = 0; i < sprite_count; i++)
			{
				// We need to extract the 8-bit row patterns of the sprite with the
				// correct vertical offset. The "Sprite Mode" also affects this as
				// the sprites may be 8 or 16 rows high. Additionally, the sprite
				// can be flipped both vertically and horizontally. So there's a lot
				// going on here :P

				uint8_t sprite_pattern_bits_lo, sprite_pattern_bits_hi;
				uint16_t sprite_pattern_addr_lo, sprite_pattern_addr_hi;

				// Determine the memory addresses that contain the byte of pattern data. We
				// only need the lo pattern address, because the hi pattern address is always
				// offset by 8 from the lo address.
				if (!control.sprite_size)
				{
					// 8x8 Sprite Mode - The control register determines the pattern table
					if (!(spriteScanline[i].attribute & 0x80))
					{
						// Sprite is NOT flipped vertically, i.e. normal    
						sprite_pattern_addr_lo =
							(control.pattern_sprite << 12)  // Which Pattern Table? 0KB or 4KB offset
							| (spriteScanline[i].id << 4)  // Which Cell? Tile ID * 16 (16 bytes per tile)
							| (scanline - spriteScanline[i].y); // Which Row in cell? (0->7)

					}
					else
					{
						// Sprite is flipped vertically, i.e. upside down
						sprite_pattern_addr_lo =
							(control.pattern_sprite << 12)  // Which Pattern Table? 0KB or 4KB offset
							| (spriteScanline[i].id << 4)  // Which Cell? Tile ID * 16 (16 bytes per tile)
							| (7 - (scanline - spriteScanline[i].y)); // Which Row in cell? (7->0)
					}

				}
				else
				{
					// 8x16 Sprite Mode - The sprite attribute determines the pattern table
					if (!(spriteScanline[i].attribute & 0x80))
					{
						// Sprite is NOT flipped vertically, i.e. normal
						if (scanline - spriteScanline[i].y < 8)
						{
							// Reading Top half Tile
							sprite_pattern_addr_lo =
								((spriteScanline[i].id & 0x01) << 12)  // Which Pattern Table? 0KB or 4KB offset
								| ((spriteScanline[i].id & 0xFE) << 4)  // Which Cell? Tile ID * 16 (16 bytes per tile)
								| ((scanline - spriteScanline[i].y) & 0x07); // Which Row in cell? (0->7)
						}
						else
						{
							// Reading Bottom Half Tile
							sprite_pattern_addr_lo =
								((spriteScanline[i].id & 0x01) << 12)  // Which Pattern Table? 0KB or 4KB offset
								| (((spriteScanline[i].id & 0xFE) + 1) << 4)  // Which Cell? Tile ID * 16 (16 bytes per tile)
								| ((scanline - spriteScanline[i].y) & 0x07); // Which Row in cell? (0->7)
						}
					}
					else
					{
						// Sprite is flipped vertically, i.e. upside down
						if (scanline - spriteScanline[i].y < 8)
						{
							// Reading Top half Tile
							sprite_pattern_addr_lo =
								((spriteScanline[i].id & 0x01) << 12)    // Which Pattern Table? 0KB or 4KB offset
								| (((spriteScanline[i].id & 0xFE) + 1) << 4)    // Which Cell? Tile ID * 16 (16 bytes per tile)
								| (7 - (scanline - spriteScanline[i].y) & 0x07); // Which Row in cell? (0->7)
						}
						else
						{
							// Reading Bottom Half Tile
							sprite_pattern_addr_lo =
								((spriteScanline[i].id & 0x01) << 12)    // Which Pattern Table? 0KB or 4KB offset
								| ((spriteScanline[i].id & 0xFE) << 4)    // Which Cell? Tile ID * 16 (16 bytes per tile)
								| (7 - (scanline - spriteScanline[i].y) & 0x07); // Which Row in cell? (0->7)
						}
					}
				}

				// Phew... XD I'm absolutely certain you can use some fantastic bit 
				// manipulation to reduce all of that to a few one liners, but in this
				// form it's easy to see the processes required for the different
				// sizes and vertical orientations

				// Hi bit plane equivalent is always offset by 8 bytes from lo bit plane
				sprite_pattern_addr_hi = sprite_pattern_addr_lo + 8;

				// Now we have the address of the sprite patterns, we can read them
				sprite_pattern_bits_lo = ppuRead(sprite_pattern_addr_lo);
				sprite_pattern_bits_hi = ppuRead(sprite_pattern_addr_hi);

				// If the sprite is flipped horizontally, we need to flip the 
				// pattern bytes. 
				if (spriteScanline[i].attribute & 0x40)
				{
					// This little lambda function "flips" a byte
					// so 0b11100000 becomes 0b00000111. It's very
					// clever, and stolen completely from here:
					// https://stackoverflow.com/a/2602885
					auto flipbyte = [](uint8_t b)
					{
						b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
						b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
						b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
						return b;
					};

					// Flip Patterns Horizontally
					sprite_pattern_bits_lo = flipbyte(sprite_pattern_bits_lo);
					sprite_pattern_bits_hi = flipbyte(sprite_pattern_bits_hi);
				}

				// Finally! We can load the pattern into our sprite shift registers
				// ready for rendering on the next scanline
				sprite_shifter_pattern_lo[i] = sprite_pattern_bits_lo;
				sprite_shifter_pattern_hi[i] = sprite_pattern_bits_hi;
			}
		}
	}

	if (scanline == 240)
	{
		// Post Render Scanline - Do Nothing!
	}

	if (scanline >= 241 && scanline < 261)
	{
		if (scanline == 241 && cycle == 1)
		{
			if (bus->nes->useCCode == false) {
				bus->nes->onFrameEnd();
				// Effectively end of frame, so set vertical blank flag
				status.vertical_blank = 1;

				// If the control register tells us to emit a NMI when
				// entering vertical blanking period, do it! The CPU
				// will be informed that rendering is complete so it can
				// perform operations with the PPU knowing it wont
				// produce visible artefacts
				if (control.enable_nmi) {
					nmi = true;
				}
			}
			else {
				// Effectively end of frame, so set vertical blank flag
				status.vertical_blank = 1;

				// If the control register tells us to emit a NMI when
				// entering vertical blanking period, do it! The CPU
				// will be informed that rendering is complete so it can
				// perform operations with the PPU knowing it wont
				// produce visible artefacts
				if (control.enable_nmi) {
					nmi = true;
				}
				else {
					bus->nes->onFrameEnd();
				}
			}
		}
	}



	// Composition - We now have background & foreground pixel information for this cycle

	// Background =============================================================
	uint8_t bg_pixel = 0x00;   // The 2-bit pixel to be rendered
	uint8_t bg_palette = 0x00; // The 3-bit index of the palette the pixel indexes

	// We only render backgrounds if the PPU is enabled to do so. Note if 
	// background rendering is disabled, the pixel and palette combine
	// to form 0x00. This will fall through the colour tables to yield
	// the current background colour in effect
	if (mask.render_background)
	{
		if (mask.render_background_left || (cycle >= 9))
		{
			// Handle Pixel Selection by selecting the relevant bit
			// depending upon fine x scolling. This has the effect of
			// offsetting ALL background rendering by a set number
			// of pixels, permitting smooth scrolling
			uint16_t bit_mux = 0x8000 >> fine_x;

			// Select Plane pixels by extracting from the shifter 
			// at the required location. 
			uint8_t p0_pixel = (bg_shifter_pattern_lo & bit_mux) > 0;
			uint8_t p1_pixel = (bg_shifter_pattern_hi & bit_mux) > 0;

			// Combine to form pixel index
			bg_pixel = (p1_pixel << 1) | p0_pixel;

			// Get palette
			uint8_t bg_pal0 = (bg_shifter_attrib_lo & bit_mux) > 0;
			uint8_t bg_pal1 = (bg_shifter_attrib_hi & bit_mux) > 0;
			bg_palette = (bg_pal1 << 1) | bg_pal0;
		}
	}

	// Foreground =============================================================
	uint8_t fg_pixel = 0x00;   // The 2-bit pixel to be rendered
	uint8_t fg_palette = 0x00; // The 3-bit index of the palette the pixel indexes
	uint8_t fg_priority = 0x00;// A bit of the sprite attribute indicates if its
	// more important than the background
	if (mask.render_sprites)
	{
		// Iterate through all sprites for this scanline. This is to maintain
		// sprite priority. As soon as we find a non transparent pixel of
		// a sprite we can abort
		if (mask.render_sprites_left || (cycle >= 9))
		{

			bSpriteZeroBeingRendered = false;

			for (uint8_t i = 0; i < sprite_count; i++)
			{
				// Scanline cycle has "collided" with sprite, shifters taking over
				if (spriteScanline[i].x == 0)
				{
					// Note Fine X scrolling does not apply to sprites, the game
					// should maintain their relationship with the background. So
					// we'll just use the MSB of the shifter

					// Determine the pixel value...
					uint8_t fg_pixel_lo = (sprite_shifter_pattern_lo[i] & 0x80) > 0;
					uint8_t fg_pixel_hi = (sprite_shifter_pattern_hi[i] & 0x80) > 0;
					fg_pixel = (fg_pixel_hi << 1) | fg_pixel_lo;

					// Extract the palette from the bottom two bits. Recall
					// that foreground palettes are the latter 4 in the 
					// palette memory.
					fg_palette = (spriteScanline[i].attribute & 0x03) + 0x04;
					fg_priority = (spriteScanline[i].attribute & 0x20) == 0;

					// If pixel is not transparent, we render it, and dont
					// bother checking the rest because the earlier sprites
					// in the list are higher priority
					if (fg_pixel != 0)
					{
						if (i == 0) // Is this sprite zero?
						{
							bSpriteZeroBeingRendered = true;
						}

						break;
					}
				}
			}
		}
	}

	// Now we have a background pixel and a foreground pixel. They need
	// to be combined. It is possible for sprites to go behind background
	// tiles that are not "transparent", yet another neat trick of the PPU
	// that adds complexity for us poor emulator developers...

	uint8_t pixel = 0x00;   // The FINAL Pixel...
	uint8_t palette = 0x00; // The FINAL Palette...

	if (bg_pixel == 0 && fg_pixel == 0)
	{
		// The background pixel is transparent
		// The foreground pixel is transparent
		// No winner, draw "background" colour
		pixel = 0x00;
		palette = 0x00;
	}
	else if (bg_pixel == 0 && fg_pixel > 0)
	{
		// The background pixel is transparent
		// The foreground pixel is visible
		// Foreground wins!
		pixel = fg_pixel;
		palette = fg_palette;
	}
	else if (bg_pixel > 0 && fg_pixel == 0)
	{
		// The background pixel is visible
		// The foreground pixel is transparent
		// Background wins!
		pixel = bg_pixel;
		palette = bg_palette;
	}
	else if (bg_pixel > 0 && fg_pixel > 0)
	{
		// The background pixel is visible
		// The foreground pixel is visible
		// Hmmm...
		if (fg_priority)
		{
			// Foreground cheats its way to victory!
			pixel = fg_pixel;
			palette = fg_palette;
		}
		else
		{
			// Background is considered more important!
			pixel = bg_pixel;
			palette = bg_palette;
		}

		// Sprite Zero Hit detection
		if (bSpriteZeroHitPossible && bSpriteZeroBeingRendered)
		{
			// Sprite zero is a collision between foreground and background
			// so they must both be enabled
			if (mask.render_background & mask.render_sprites)
			{
				// The left edge of the screen has specific switches to control
				// its appearance. This is used to smooth inconsistencies when
				// scrolling (since sprites x coord must be >= 0)
				if (!(mask.render_background_left | mask.render_sprites_left))
				{
					if (cycle >= 9 && cycle < 258)
					{
						status.sprite_zero_hit = 1;
					}
				}
				else
				{
					if (cycle >= 1 && cycle < 258)
					{
						status.sprite_zero_hit = 1;
					}
				}
			}
		}
	}

	// Now we have a final pixel colour, and a palette for this cycle
	// of the current scanline. Let's at long last, draw that ^&%*er :P
	sprScreen->SetPixel(cycle - 1, scanline, GetColourFromPaletteRam(palette, pixel));

	// Advance renderer - it never stops, it's relentless
	cycle++;
	if (mask.render_background || mask.render_sprites)
		if (cycle == 260 && scanline < 240)
		{
			cart->GetMapper()->scanline();
		}



	if (cycle >= 341)
	{
		cycle = 0;
		scanline++;
		if (scanline >= 261)
		{
			scanline = -1;
			frame_complete = true;
			odd_frame = !odd_frame;
		}
	}
}
