#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#include "nestetrisclockcyclesuint8_t.h"
#include "printplayfield.h"

typedef enum {
    UNMODIFIED,
    SEVENDIGITS,
    NOMAXOUTCODE,
    ENEOOGEZ,
    CRASHFIX
} Modifications;

uint8_t fixes = 0;

Modifications modification = CRASHFIX;

uint8_t* tmp1;
uint8_t* tmp2;
uint8_t* tmp3;
uint8_t* tmpBulkCopyToPpuReturnAddr;
uint8_t* patchToPpuAddr;
uint8_t* rng_seed;
uint8_t* spawnID;
uint8_t* spawnCount;
uint8_t* verticalBlankingInterval;
uint8_t* unused_0E;
uint8_t* tetriminoX;
uint8_t* tetriminoY;
uint8_t* currentPiece;
uint8_t* levelNumber;
uint8_t* fallTimer;
uint8_t* autorepeatX;
uint8_t* startLevel;
uint8_t* playState;
uint8_t* vramRow;
uint8_t* completedRow;
uint8_t* autorepeatY;
uint8_t* holdDownPoints;
uint8_t* lines;
uint8_t* rowY;
uint8_t* score;
uint8_t* completedLines;
uint8_t* lineIndex;
uint8_t* curtainRow;
uint8_t* startHeight;
uint8_t* garbageHole;
uint8_t* player1_tetriminoX;
uint8_t* player1_tetriminoY;
uint8_t* player1_currentPiece;
uint8_t* player1_levelNumber;
uint8_t* player1_fallTimer;
uint8_t* player1_autorepeatX;
uint8_t* player1_startLevel;
uint8_t* player1_playState;
uint8_t* player1_vramRow;
uint8_t* player1_completedRow;
uint8_t* player1_autorepeatY;
uint8_t* player1_holdDownPoints;
uint8_t* player1_lines;
uint8_t* player1_rowY;
uint8_t* player1_score;
uint8_t* player1_completedLines;
uint8_t* player1_curtainRow;
uint8_t* player1_startHeight;
uint8_t* player1_garbageHole;
uint8_t* player2_tetriminoX;
uint8_t* player2_tetriminoY;
uint8_t* player2_currentPiece;
uint8_t* player2_levelNumber;
uint8_t* player2_fallTimer;
uint8_t* player2_autorepeatX;
uint8_t* player2_startLevel;
uint8_t* player2_playState;
uint8_t* player2_vramRow;
uint8_t* player2_completedRow;
uint8_t* player2_autorepeatY;
uint8_t* player2_holdDownPoints;
uint8_t* player2_lines;
uint8_t* player2_rowY;
uint8_t* player2_score;
uint8_t* player2_completedLines;
uint8_t* player2_curtainRow;
uint8_t* player2_startHeight;
uint8_t* player2_garbageHole;
uint8_t* spriteXOffset;
uint8_t* spriteYOffset;
uint8_t* spriteIndexInOamContentLookup;
uint8_t* outOfDateRenderFlags;
uint8_t* twoPlayerPieceDelayCounter;
uint8_t* twoPlayerPieceDelayPlayer;
uint8_t* twoPlayerPieceDelayPiece;
uint8_t* gameModeState;
uint8_t* generalCounter;
uint8_t* generalCounter2;
uint8_t* generalCounter3;
uint8_t* generalCounter4;
uint8_t* generalCounter5;
uint8_t* selectingLevelOrHeight;
uint8_t* originalY;
uint8_t* dropSpeed;
uint8_t* tmpCurrentPiece;
uint8_t* frameCounter;
uint8_t* oamStagingLength;
uint8_t* newlyPressedButtons;
uint8_t* heldButtons;
uint8_t* activePlayer;
uint8_t* playfieldAddr;
uint8_t* allegro;
uint8_t* pendingGarbage;
uint8_t* pendingGarbageInactivePlayer;
uint8_t* renderMode;
uint8_t* numberOfPlayers;
uint8_t* nextPiece;
uint8_t* gameMode;
uint8_t* gameType;
uint8_t* musicType;
uint8_t* sleepCounter;
uint8_t* ending;
uint8_t* ending_customVars;
uint8_t* ending_currentSprite;
uint8_t* ending_typeBCathedralFrameDelayCounter;
uint8_t* demo_heldButtons;
uint8_t* demo_repeats;
uint8_t* demoButtonsAddr;
uint8_t* demoIndex;
uint8_t* highScoreEntryNameOffsetForLetter;
uint8_t* highScoreEntryRawPos;
uint8_t* highScoreEntryNameOffsetForRow;
uint8_t* highScoreEntryCurrentLetter;
uint8_t* lineClearStatsByType;
uint8_t* displayNextPiece;
uint8_t* AUDIOTMP1;
uint8_t* AUDIOTMP2;
uint8_t* AUDIOTMP3;
uint8_t* AUDIOTMP4;
uint8_t* AUDIOTMP5;
uint8_t* musicChanTmpAddr;
uint8_t* music_unused2;
uint8_t* soundRngSeed;
uint8_t* currentSoundEffectSlot;
uint8_t* musicChannelOffset;
uint8_t* currentAudioSlot;
uint8_t* unreferenced_buttonMirror;
uint8_t* newlyPressedButtons_player1;
uint8_t* newlyPressedButtons_player2;
uint8_t* heldButtons_player1;
uint8_t* heldButtons_player2;
uint8_t* joy1Location;
uint8_t* ppuScrollY;
uint8_t* ppuScrollX;
uint8_t* currentPpuMask;
uint8_t* currentPpuCtrl;
uint8_t* stack;
uint8_t* oamStaging;
uint8_t* statsByType;
uint8_t* playfield;
uint8_t* playfieldForSecondPlayer;
uint8_t* musicStagingSq1Lo;
uint8_t* musicStagingSq1Hi;
uint8_t* audioInitialized;
uint8_t* resetSq12ForMusic;
uint8_t* musicPauseSoundEffectLengthCounter;
uint8_t* musicStagingSq2Lo;
uint8_t* musicStagingSq2Hi;
uint8_t* musicStagingTriLo;
uint8_t* musicStagingTriHi;
uint8_t* musicPauseSoundEffectCounter;
uint8_t* musicStagingNoiseLo;
uint8_t* musicStagingNoiseHi;
uint8_t* musicDataNoteTableOffset;
uint8_t* musicDataDurationTableOffset;
uint8_t* musicDataChanPtr;
uint8_t* musicChanControl;
uint8_t* musicChanVolume;
uint8_t* musicDataChanPtrDeref;
uint8_t* musicDataChanPtrOff;
uint8_t* musicDataChanInstructionOffset;
uint8_t* musicDataChanInstructionOffsetBackup;
uint8_t* musicChanNoteDurationRemaining;
uint8_t* musicChanNoteDuration;
uint8_t* musicChanProgLoopCounter;
uint8_t* musicStagingSq1Sweep;
uint8_t* musicChanNote;
uint8_t* musicChanInhibit;
uint8_t* musicTrack_dec;
uint8_t* musicChanVolFrameCounter;
uint8_t* musicChanLoFrameCounter;
uint8_t* soundEffectSlot0FrameCount;
uint8_t* soundEffectSlot0FrameCounter;
uint8_t* soundEffectSlot0SecondaryCounter;
uint8_t* soundEffectSlot1SecondaryCounter;
uint8_t* soundEffectSlot2SecondaryCounter;
uint8_t* soundEffectSlot3SecondaryCounter;
uint8_t* soundEffectSlot0TertiaryCounter;
uint8_t* soundEffectSlot1TertiaryCounter;
uint8_t* soundEffectSlot2TertiaryCounter;
uint8_t* soundEffectSlot3TertiaryCounter;
uint8_t* soundEffectSlot0Tmp;
uint8_t* soundEffectSlot1Tmp;
uint8_t* soundEffectSlot2Tmp;
uint8_t* soundEffectSlot3Tmp;
uint8_t* soundEffectSlot0Init;
uint8_t* soundEffectSlot1Init;
uint8_t* soundEffectSlot2Init;
uint8_t* soundEffectSlot3Init;
uint8_t* soundEffectSlot4Init;
uint8_t* musicTrack;
uint8_t* soundEffectSlot0Playing;
uint8_t* soundEffectSlot1Playing;
uint8_t* soundEffectSlot2Playing;
uint8_t* soundEffectSlot3Playing;
uint8_t* soundEffectSlot4Playing;
uint8_t* currentlyPlayingMusicTrack;
uint8_t* unreferenced_soundRngTmp;
uint8_t* highScoreNames;
uint8_t* highScoreScoresA;
uint8_t* highScoreScoresB;
uint8_t* highScoreLevels;
uint8_t* initMagic;
uint8_t* defaultHighScoresTable;
uint8_t* byteToBcdTable;
uint8_t* stackBasePointer;
uint8_t* totalScore;

//registers
uint8_t* accumulator;
uint8_t* registerX;
uint8_t* registerY;
uint16_t* PPUADDR;
uint8_t* PPUMASK;
uint8_t* PPUSTATUS;
uint8_t* fine_x;
uint16_t* tram_addr;
uint16_t* vram_addr;
uint8_t* PPUControlRegister;
bool* channel1DisableFlag;
bool* channel2DisableFlag;
bool* noiseDisableFlag;
bool* noiseHaltFlag;
bool* pulse1Start;
bool* pulse2Start;
bool* noiseStart;
bool* pulse1SweepEnabled;
bool* pulse1SweepReload;
bool* pulse2SweepReload;
bool* pulse1SweepDown;
bool* pulse2SweepDown;
bool* pulse1Halt;
bool* pulse2SweepEnabled;
uint16_t* pulse1SeqTimer;
uint16_t* pulse2SeqTimer;
uint16_t* pulse1SeqReload;
uint16_t* channel1Volume;
uint16_t* channel2Volume;
uint16_t* noiseVolume;
uint16_t* noiseReload;
uint16_t* pulse2SeqReload;
uint32_t* channel1Sequence;
uint32_t* channel2Sequence;
uint32_t* pulse1Sequence;
uint32_t* pulse2Sequence;
uint8_t* controller1;
uint8_t* controller2;
uint8_t* pulse1Counter;
uint8_t* pulse2Counter;
uint8_t* pulse1SweepShift;
uint8_t* pulse2SweepShift;
uint8_t* pulse1SweepPeriod;
uint8_t* pulse2SweepPeriod;
uint8_t* oam_addr;
uint8_t* oamdma;
uint8_t* oamaddr;
uint8_t* noiseCounter;
double* pulse1OscDutycycle;
bool* dmatransfer;

//ROM

uint8_t* musicSelectionTable;
uint8_t* garbageLines;
uint8_t* orientationTable;
uint8_t* rotationTable;
uint8_t* framesPerDropTable;
uint8_t* pointsTable;
uint8_t* tetriminoTypeFromOrientation;
uint8_t* spawnTable;
uint8_t* demoTetriminoTypeTable;
uint8_t* spawnOrientationFromOrientation;
uint8_t* oamContentLookup;
uint8_t* orientationToSpriteTable;
uint8_t* colorTable;
uint8_t* multBy10Table;
uint8_t* vramPlayfieldRows;
uint8_t* leftColumns;
uint8_t* rightColumns;
uint8_t* highScorePpuAddrTable;
uint8_t* highScoreCharToTile;
uint8_t* ending_typeBCathedralAnimSpeed;
uint8_t* ending_typeBCathedralSpriteTable;
uint8_t* LA735;
uint8_t* LA73D;
uint8_t* LA745;
uint8_t* LAA2A;
uint8_t* domeNumberToXOffsetTable;
uint8_t* domeNumberToXSpriteTable;
uint8_t* marioFrameToYOffsetTable;
uint8_t* luigiFrameToYOffsetTable;
uint8_t* luigiFrameToSpriteTable;
uint8_t* levelToSpriteYOffset;
uint8_t* levelToSpriteXOffset;
uint8_t* heightToPpuLowAddr;
uint8_t* heightToPpuHighAddr;
uint8_t* levelDisplayTable;
uint8_t* pieceToPpuStatAddr;
uint8_t* soundEffectSlot1_chirpChirpSq1Vol_table;
uint8_t* soundEffectSlot1_lineClearing_lo;
uint8_t* soundEffectSlot1_lineClearing_vol;
uint8_t* soundEffectSlot1_levelUp_lo;
uint8_t* soundEffectSlot1_menuScreenSelectInitData;
uint8_t* loOffTrillNeg2To2Table;
uint8_t* loOffSlowStartTrillTable;
uint8_t* loOffDescendToNeg11BounceToNeg9Table;
uint8_t* loOff9To0FallTable;
uint8_t* typebSuccessGraphic;
uint8_t* rocketToXOffsetTable;
uint8_t* rocketToSpriteTable;
uint8_t* game_typeb_nametable_patch;
uint8_t* typeBBlankInitCountByHeightTable;
uint8_t* rngTable;
uint8_t* highScoreIndexToHighScoreNamesOffset;
uint8_t* highScoreIndexToHighScoreScoresOffset;
uint8_t* highScoreNamePosToX;
uint8_t* highScorePosToY;
uint8_t* rocketToJetSpriteTable;
uint8_t* rocketToJetXOffsetTable;
uint8_t* ending_typeBCathedralFrameDelayTable;
uint8_t* ending_typeBCathedralYTable;
uint8_t* ending_typeBCathedralVectorTable;
uint8_t* ending_typeBCathedralXTable;

//CHR Banks
uint8_t* CHRBank0;
uint8_t* CHRBank1;

//lenght table for the APU
uint8_t length_table[] = { 10, 254, 20,  2, 40,  4, 80,  6,
                                    160,   8, 60, 10, 14, 12, 26, 14,
                                     12,  16, 24, 18, 48, 20, 96, 22,
                                    192,  24, 72, 26, 16, 28, 32, 30 };

//base addresses
//uint8_t* baseAddressROM;
uint8_t* baseAddressROM;
uint8_t* baseAddressTBL;
uint8_t* tablePalette;
uint8_t* tablePattern;
uint8_t* tablePattern2;

//the NES Addressspace
uint8_t* addressSpaces[4]; //currently not used; intendet to for running multiple instances in seperate threads
uint8_t* addressSpace;
uint8_t* possibleAddressSpace; //allocation of double the space need to garantie that there is an address ending
//in 0x0000 and has 64 KiByte of space after it;
//ROMs can be larger than 64KiByte; Tetris is not

uint8_t* getAddressSpace(uint8_t id) {
    return addressSpaces[id];
}

uint8_t* calculateBaseAddress(uint8_t id) {
    possibleAddressSpace = (uint8_t* )malloc(0x20000);
    addressSpace = (uint8_t*)(((uint64_t)possibleAddressSpace) & (uint64_t)0xFFFFFFFFFFFF0000) + (uint64_t)0x10000; //idk if this defined behavior in C or Cpp
    addressSpaces[id] = addressSpace;
    baseAddressTBL = addressSpace + 0x2000;
    setBaseAddressRAM();
    setBaseAddressROM();
    return addressSpace;
}

void apply_game_genie_code(const char code[], int characters) {//source of information: http://tuxnes.sourceforge.net/gamegenie.html
    //char temp[characters]; //doesn't work in CPP
    char temp[8];
    for (int i = 0; i < characters; i++) {
        switch (code[i]) {
        case 65: temp[i] = 0; break;
        case 80: temp[i] = 1; break;
        case 90: temp[i] = 2; break;
        case 76: temp[i] = 3; break;
        case 71: temp[i] = 4; break;
        case 73: temp[i] = 5; break;
        case 84: temp[i] = 6; break;
        case 89: temp[i] = 7; break;
        case 69: temp[i] = 8; break;
        case 79: temp[i] = 9; break;
        case 88: temp[i] = 10; break;
        case 85: temp[i] = 11; break;
        case 75: temp[i] = 12; break;
        case 83: temp[i] = 13; break;
        case 86: temp[i] = 14; break;
        case 78: temp[i] = 15; break;
        }
    }
    code = temp;
    uint16_t address = 0x8000 +
        ((code[3] & 7) << 12)
        | ((code[5] & 7) << 8) | ((code[4] & 8) << 8)
        | ((code[2] & 7) << 4) | ((code[1] & 8) << 4)
        | (code[4] & 7) | (code[3] & 8);
    uint16_t data = 0;
    if (characters == 6) {
        data =
            ((code[1] & 7) << 4) | ((code[0] & 8) << 4)
            | (code[0] & 7) | (code[5] & 8);
        printf("address: %0x Data: %0x\r\n", address, data);
    }
    if (characters == 8) {
        data =
            ((code[1] & 7) << 4) | ((code[0] & 8) << 4)
            | (code[0] & 7) | (code[7] & 8);
        uint16_t compare =
            ((code[7] & 7) << 4) | ((code[6] & 8) << 4)
            | (code[6] & 7) | (code[5] & 8);
        printf("address: %0x Data: %0x Compare: %0x\r\n", address, data, compare);
    }
    //address is only set once! at runtime nothing else will be checked
    addressSpace[address] = (uint8_t)data;
}

void setCHRBanks(uint8_t* nCHRBankSelect4Lo, uint8_t* nCHRBankSelect4Hi) {
    CHRBank0 = nCHRBankSelect4Lo;
    CHRBank1 = nCHRBankSelect4Hi;
    *CHRBank0 = 0;
    *CHRBank1 = 0;
}

void setAPURegisters(bool* channel1Disable, bool* channel2Disable, bool* noiseDisable,
                    uint16_t* channel1Vol, uint16_t* channel2Vol, uint16_t* noiseVol,
                    uint32_t* channel1Seq, uint32_t* channel2Seq, uint16_t* noiseRel,
                    bool* noiseHalt, bool* pulse1Sta, bool* pulse2Sta,
                    bool* noiseSta, uint8_t* noiseCou, uint16_t* pulse1Reload,
                    uint16_t* pulse1Timer, uint32_t* pulse1Seq, uint8_t* pulse1Cou,
                    bool* pulse1SweepEna, uint8_t* pulse1SweepPer, bool* pulse1SweepDow,
                    uint8_t* pulse1SweepShi, bool* pulse1SweepRel, bool* pulse1Hal,
                    double* pulse1Dutycycle, uint16_t* pulse2SeqRel, bool* pulse2SweepEna,
                    uint8_t* pulse2SweepPer, bool* pulse2SweepDow, uint8_t* pulse2SweepShi,
                    bool* pulse2SweepRel, uint16_t* pulse2SeqTim, uint32_t* pulse2Seq,
                    uint8_t* pulse2Cou){
    channel1DisableFlag = channel1Disable;
    channel2DisableFlag = channel2Disable;
    noiseDisableFlag = noiseDisable;
    channel1Volume = channel1Vol;
    channel2Volume = channel2Vol;
    noiseVolume = noiseVol;
    channel1Sequence = channel1Seq;
    channel2Sequence = channel2Seq;
    noiseReload = noiseRel;
    noiseHaltFlag = noiseHalt;
    pulse1Start = pulse1Sta;
    pulse2Start = pulse2Sta;
    noiseStart = noiseSta;
    noiseCounter = noiseCou;
    pulse1SeqReload = pulse1Reload;
    pulse1SeqTimer = pulse1Timer;
    pulse1Sequence = pulse1Seq;
    pulse1Counter = pulse1Cou;
    pulse1SweepDown = pulse1SweepDow;
    pulse1SweepEnabled = pulse1SweepEna;
    pulse1SweepReload = pulse1SweepRel;
    pulse1SweepShift = pulse1SweepShi;
    pulse1SweepPeriod = pulse1SweepPer;
    pulse1Halt = pulse1Hal;
    pulse1OscDutycycle = pulse1Dutycycle;
    pulse2SeqReload = pulse2SeqRel;
    pulse2SweepEnabled = pulse2SweepEna;
    pulse2SweepPeriod = pulse2SweepPer;
    pulse2SweepDown = pulse2SweepDow;
    pulse2SweepShift = pulse2SweepShi;
    pulse2SweepReload = pulse2SweepRel;
    pulse2SeqTimer = pulse2SeqTim;
    pulse2Sequence = pulse2Seq;
    pulse2Counter = pulse2Cou;
}

void setBaseAddressROM() {//baseAddress = 0x8000
    baseAddressROM = addressSpace + 0x8000;

    musicSelectionTable = addressSpace + 0x85D2;
    garbageLines = addressSpace + 0x9B53;
    orientationTable = addressSpace + 0x8A9C;
    rotationTable = addressSpace + 0x88EE;
    framesPerDropTable = addressSpace + 0x898E;
    pointsTable = addressSpace + 0x9CA5;
    tetriminoTypeFromOrientation = addressSpace + 0x993B;
    spawnTable = addressSpace + 0x994E;
    rocketToXOffsetTable = addressSpace + 0xAA25;
    demoTetriminoTypeTable = addressSpace + 0xDF00;
    spawnOrientationFromOrientation = addressSpace + 0x9956;
    game_typeb_nametable_patch = addressSpace + 0x86B0;
    rngTable = addressSpace + 0x887C;
    oamContentLookup = addressSpace + 0x8C6C;
    orientationToSpriteTable = addressSpace + 0x8BE5;
    colorTable = addressSpace + 0x984C;
    multBy10Table = addressSpace + 0x96D6;
    vramPlayfieldRows = addressSpace + 0x96EA;
    leftColumns = addressSpace + 0x97FE;
    rightColumns = addressSpace + 0x9803;
    highScorePpuAddrTable = addressSpace + 0xA086;
    highScoreCharToTile = addressSpace + 0xA08C;
    byteToBcdTable = addressSpace + 0xA0BC;
    highScoreIndexToHighScoreNamesOffset = addressSpace + 0xA1F1;
    highScoreIndexToHighScoreScoresOffset = addressSpace + 0xA1F9;
    highScorePosToY = addressSpace + 0xA33B;
    highScoreNamePosToX = addressSpace + 0xA33E;
    ending_typeBCathedralVectorTable = addressSpace + 0xA771;
    ending_typeBCathedralAnimSpeed = addressSpace + 0xA749;
    ending_typeBCathedralXTable = addressSpace + 0xA77B;
    ending_typeBCathedralYTable = addressSpace + 0xA7B7;
    ending_typeBCathedralSpriteTable = addressSpace + 0xA7F3;
    LA735 = addressSpace + 0xA735;
    LA73D = addressSpace + 0xA73D;
    LA745 = addressSpace + 0xA745;
    LAA2A = addressSpace + 0xAA2A;
    domeNumberToXOffsetTable = addressSpace + 0xA739;
    domeNumberToXSpriteTable = addressSpace + 0xA741;
    ending_typeBCathedralFrameDelayTable = addressSpace + 0xA753;
    marioFrameToYOffsetTable = addressSpace + 0xA80A;
    luigiFrameToYOffsetTable = addressSpace + 0xA80E;
    luigiFrameToSpriteTable = addressSpace + 0xA818;
    rocketToSpriteTable = addressSpace + 0xAA11;
    rocketToJetSpriteTable = addressSpace + 0xAA16;
    rocketToJetXOffsetTable = addressSpace + 0xAA20;
    levelToSpriteYOffset = addressSpace + 0x85B2;
    levelToSpriteXOffset = addressSpace + 0x85BC;
    heightToPpuLowAddr = addressSpace + 0x85C6;
    heightToPpuHighAddr = addressSpace + 0x85CC;
    typeBBlankInitCountByHeightTable = addressSpace + 0x8876;
    levelDisplayTable = addressSpace + 0x96B8;
    pieceToPpuStatAddr = addressSpace + 0x96AA;
    defaultHighScoresTable = addressSpace + 0xAD67;
    typebSuccessGraphic = addressSpace + 0xA42E;
    soundEffectSlot1_chirpChirpSq1Vol_table = addressSpace + 0xE150;
    soundEffectSlot1_lineClearing_lo = addressSpace + 0xE4B9;
    soundEffectSlot1_lineClearing_vol = addressSpace + 0xE4B0;
    soundEffectSlot1_levelUp_lo = addressSpace + 0xE4F3;
    soundEffectSlot1_menuScreenSelectInitData = addressSpace + 0xE12C;
    loOffTrillNeg2To2Table = addressSpace + 0xE6BF;
    loOffSlowStartTrillTable = addressSpace + 0xE6B5;
    loOffDescendToNeg11BounceToNeg9Table = addressSpace + 0xE6CF;
    loOff9To0FallTable = addressSpace + 0xE694;
}

void setControllers(uint8_t* controller1Input, uint8_t* controller2Input, uint8_t* dma_page, uint8_t* dma_addr, bool* dma_transfer) {
    controller1 = controller1Input;
    controller2 = controller2Input;
    oamdma = dma_page;
    oamaddr = oam_addr;
    dmatransfer = dma_transfer;
}

void setRegisters(uint8_t* acc, uint8_t* X, uint8_t* Y) {
    accumulator = acc;
    registerX = X;
    registerY = Y;
}

void setVRAM(uint16_t* ppuaddr, uint8_t* tblPalette, uint8_t* fineX, uint16_t* tramaddr, uint16_t* vramaddr, uint8_t* oamAddr, uint8_t* PPUCTRRegister, uint8_t* PPUMaskAddr, uint8_t* PPUStatusReg, uint8_t *tblPattern, uint8_t* tblPattern2) {
    PPUADDR = ppuaddr;
    tablePalette = tblPalette;
    fine_x = fineX;
    tram_addr = tramaddr;
    vram_addr = vramaddr;
    oam_addr = oamAddr;
    PPUControlRegister = PPUCTRRegister;
    PPUMASK = PPUMaskAddr;
    PPUSTATUS = PPUStatusReg;
    tablePattern = tblPattern;
    tablePattern2 = tblPattern2;
}

void setBaseAddressRAM() {
    tmp1 = addressSpace + 0x0000;
    tmp2 = addressSpace + 0x0001;
    tmp3 = addressSpace + 0x0002;
    tmpBulkCopyToPpuReturnAddr = addressSpace + 0x0005;
    patchToPpuAddr = addressSpace + 0x0014;
    rng_seed = addressSpace + 0x0017;
    spawnID = addressSpace + 0x0019;
    spawnCount = addressSpace + 0x001A;
    verticalBlankingInterval = addressSpace + 0x0033;
    unused_0E = addressSpace + 0x0034;
    tetriminoX = addressSpace + 0x0040;
    tetriminoY = addressSpace + 0x0041;
    currentPiece = addressSpace + 0x0042;
    levelNumber = addressSpace + 0x0044;
    fallTimer = addressSpace + 0x0045;
    autorepeatX = addressSpace + 0x0046;
    startLevel = addressSpace + 0x0047;
    playState = addressSpace + 0x0048;
    vramRow = addressSpace + 0x0049;
    completedRow = addressSpace + 0x004A;
    autorepeatY = addressSpace + 0x004E;
    holdDownPoints = addressSpace + 0x004F;
    lines = addressSpace + 0x0050;
    rowY = addressSpace + 0x0052;
    score = addressSpace + 0x0053;
    completedLines = addressSpace + 0x0056;
    lineIndex = addressSpace + 0x0057;
    curtainRow = addressSpace + 0x0058;
    startHeight = addressSpace + 0x0059;
    garbageHole = addressSpace + 0x005A;
    player1_tetriminoX = addressSpace + 0x0060;
    player1_tetriminoY = addressSpace + 0x0061;
    player1_currentPiece = addressSpace + 0x0062;
    player1_levelNumber = addressSpace + 0x0064;
    player1_fallTimer = addressSpace + 0x0065;
    player1_autorepeatX = addressSpace + 0x0066;
    player1_startLevel = addressSpace + 0x0067;
    player1_playState = addressSpace + 0x0068;
    player1_vramRow = addressSpace + 0x0069;
    player1_completedRow = addressSpace + 0x006A;
    player1_autorepeatY = addressSpace + 0x006E;
    player1_holdDownPoints = addressSpace + 0x006F;
    player1_lines = addressSpace + 0x0070;
    player1_rowY = addressSpace + 0x0072;
    player1_score = addressSpace + 0x0073;
    player1_completedLines = addressSpace + 0x0076;
    player1_curtainRow = addressSpace + 0x0078;
    player1_startHeight = addressSpace + 0x0079;
    player1_garbageHole = addressSpace + 0x007A;
    player2_tetriminoX = addressSpace + 0x0080;
    player2_tetriminoY = addressSpace + 0x0081;
    player2_currentPiece = addressSpace + 0x0082;
    player2_levelNumber = addressSpace + 0x0084;
    player2_fallTimer = addressSpace + 0x0085;
    player2_autorepeatX = addressSpace + 0x0086;
    player2_startLevel = addressSpace + 0x0087;
    player2_playState = addressSpace + 0x0088;
    player2_vramRow = addressSpace + 0x0089;
    player2_completedRow = addressSpace + 0x008A;
    player2_autorepeatY = addressSpace + 0x008E;
    player2_holdDownPoints = addressSpace + 0x008F;
    player2_lines = addressSpace + 0x0090;
    player2_rowY = addressSpace + 0x0092;
    player2_score = addressSpace + 0x0093;
    player2_completedLines = addressSpace + 0x0096;
    player2_curtainRow = addressSpace + 0x0098;
    player2_startHeight = addressSpace + 0x0099;
    player2_garbageHole = addressSpace + 0x009A;
    spriteXOffset = addressSpace + 0x00A0;
    spriteYOffset = addressSpace + 0x00A1;
    spriteIndexInOamContentLookup = addressSpace + 0x00A2;
    outOfDateRenderFlags = addressSpace + 0x00A3;
    twoPlayerPieceDelayCounter = addressSpace + 0x00A4;
    twoPlayerPieceDelayPlayer = addressSpace + 0x00A5;
    twoPlayerPieceDelayPiece = addressSpace + 0x00A6;
    gameModeState = addressSpace + 0x00A7;
    generalCounter = addressSpace + 0x00A8;
    generalCounter2 = addressSpace + 0x00A9;
    generalCounter3 = addressSpace + 0x00AA;
    generalCounter4 = addressSpace + 0x00AB;
    generalCounter5 = addressSpace + 0x00AC;
    selectingLevelOrHeight = addressSpace + 0x00AD;
    originalY = addressSpace + 0x00AE;
    dropSpeed = addressSpace + 0x00AF;
    tmpCurrentPiece = addressSpace + 0x00B0;
    frameCounter = addressSpace + 0x00B1;
    oamStagingLength = addressSpace + 0x00B3;
    newlyPressedButtons = addressSpace + 0x00B5;
    heldButtons = addressSpace + 0x00B6;
    activePlayer = addressSpace + 0x00B7;
    playfieldAddr = addressSpace + 0x00B8;
    allegro = addressSpace + 0x00BA;
    pendingGarbage = addressSpace + 0x00BB;
    pendingGarbageInactivePlayer = addressSpace + 0x00BC;
    renderMode = addressSpace + 0x00BD;
    numberOfPlayers = addressSpace + 0x00BE;
    nextPiece = addressSpace + 0x00BF;
    gameMode = addressSpace + 0x00C0;
    gameType = addressSpace + 0x00C1;
    musicType = addressSpace + 0x00C2;
    sleepCounter = addressSpace + 0x00C3;
    ending = addressSpace + 0x00C4;
    ending_customVars = addressSpace + 0x00C5;
    ending_currentSprite = addressSpace + 0x00CC;
    ending_typeBCathedralFrameDelayCounter = addressSpace + 0x00CD;
    demo_heldButtons = addressSpace + 0x00CE;
    demo_repeats = addressSpace + 0x00CF;
    demoButtonsAddr = addressSpace + 0x00D1;
    demoIndex = addressSpace + 0x00D3;
    highScoreEntryNameOffsetForLetter = addressSpace + 0x00D4;
    highScoreEntryRawPos = addressSpace + 0x00D5;
    highScoreEntryNameOffsetForRow = addressSpace + 0x00D6;
    highScoreEntryCurrentLetter = addressSpace + 0x00D7;
    lineClearStatsByType = addressSpace + 0x00D8;
    totalScore = addressSpace + 0x00DC;
    displayNextPiece = addressSpace + 0x00DF;
    AUDIOTMP1 = addressSpace + 0x00E0;
    AUDIOTMP2 = addressSpace + 0x00E1;
    AUDIOTMP3 = addressSpace + 0x00E2;
    AUDIOTMP4 = addressSpace + 0x00E3;
    AUDIOTMP5 = addressSpace + 0x00E4;
    musicChanTmpAddr = addressSpace + 0x00E6;
    music_unused2 = addressSpace + 0x00EA;
    soundRngSeed = addressSpace + 0x00EB;
    currentSoundEffectSlot = addressSpace + 0x00ED;
    musicChannelOffset = addressSpace + 0x00EE;
    currentAudioSlot = addressSpace + 0x00EF;
    unreferenced_buttonMirror = addressSpace + 0x00F1;
    newlyPressedButtons_player1 = addressSpace + 0x00F5;
    newlyPressedButtons_player2 = addressSpace + 0x00F6;
    heldButtons_player1 = addressSpace + 0x00F7;
    heldButtons_player2 = addressSpace + 0x00F8;
    joy1Location = addressSpace + 0x00FB;
    ppuScrollY = addressSpace + 0x00FC;
    ppuScrollX = addressSpace + 0x00FD;
    currentPpuMask = addressSpace + 0x00FE;
    currentPpuCtrl = addressSpace + 0x00FF;
    stack = addressSpace + 0x0100;
    oamStaging = addressSpace + 0x0200;
    statsByType = addressSpace + 0x03F0;
    playfield = addressSpace + 0x0400;
    playfieldForSecondPlayer = addressSpace + 0x0500;
    musicStagingSq1Lo = addressSpace + 0x0680;
    musicStagingSq1Hi = addressSpace + 0x0681;
    audioInitialized = addressSpace + 0x0682;
    musicPauseSoundEffectLengthCounter = addressSpace + 0x0683;
    musicStagingSq2Lo = addressSpace + 0x0684;
    musicStagingSq2Hi = addressSpace + 0x0685;
    musicStagingTriLo = addressSpace + 0x0688;
    musicStagingTriHi = addressSpace + 0x0689;
    resetSq12ForMusic = addressSpace + 0x068A;
    musicPauseSoundEffectCounter = addressSpace + 0x068B;
    musicStagingNoiseLo = addressSpace + 0x068C;
    musicStagingNoiseHi = addressSpace + 0x068D;
    musicDataNoteTableOffset = addressSpace + 0x0690;
    musicDataDurationTableOffset = addressSpace + 0x0691;
    musicDataChanPtr = addressSpace + 0x0692;
    musicChanControl = addressSpace + 0x069A;
    musicChanVolume = addressSpace + 0x069D;
    musicDataChanPtrDeref = addressSpace + 0x06A0;
    musicDataChanPtrOff = addressSpace + 0x06A8;
    musicDataChanInstructionOffset = addressSpace + 0x06AC;
    musicDataChanInstructionOffsetBackup = addressSpace + 0x06B0;
    musicChanNoteDurationRemaining = addressSpace + 0x06B4;
    musicChanNoteDuration = addressSpace + 0x06B8;
    musicChanProgLoopCounter = addressSpace + 0x06BC;
    musicStagingSq1Sweep = addressSpace + 0x06C0;
    musicChanNote = addressSpace + 0x06C3;
    musicChanInhibit = addressSpace + 0x06C8;
    musicTrack_dec = addressSpace + 0x06CC;
    musicChanVolFrameCounter = addressSpace + 0x06CD;
    musicChanLoFrameCounter = addressSpace + 0x06D1;
    soundEffectSlot0FrameCount = addressSpace + 0x06D5;
    soundEffectSlot0FrameCounter = addressSpace + 0x06DA;
    soundEffectSlot0SecondaryCounter = addressSpace + 0x06DF;
    soundEffectSlot1SecondaryCounter = addressSpace + 0x06E0;
    soundEffectSlot2SecondaryCounter = addressSpace + 0x06E1;
    soundEffectSlot3SecondaryCounter = addressSpace + 0x06E2;
    soundEffectSlot0TertiaryCounter = addressSpace + 0x06E3;
    soundEffectSlot1TertiaryCounter = addressSpace + 0x06E4;
    soundEffectSlot2TertiaryCounter = addressSpace + 0x06E5;
    soundEffectSlot3TertiaryCounter = addressSpace + 0x06E6;
    soundEffectSlot0Tmp = addressSpace + 0x06E7;
    soundEffectSlot1Tmp = addressSpace + 0x06E8;
    soundEffectSlot2Tmp = addressSpace + 0x06E9;
    soundEffectSlot3Tmp = addressSpace + 0x06EA;
    soundEffectSlot0Init = addressSpace + 0x06F0;
    soundEffectSlot1Init = addressSpace + 0x06F1;
    soundEffectSlot2Init = addressSpace + 0x06F2;
    soundEffectSlot3Init = addressSpace + 0x06F3;
    soundEffectSlot4Init = addressSpace + 0x06F4;
    musicTrack = addressSpace + 0x06F5;
    soundEffectSlot0Playing = addressSpace + 0x06F8;
    soundEffectSlot1Playing = addressSpace + 0x06F9;
    soundEffectSlot2Playing = addressSpace + 0x06FA;
    soundEffectSlot3Playing = addressSpace + 0x06FB;
    soundEffectSlot4Playing = addressSpace + 0x06FC;
    currentlyPlayingMusicTrack = addressSpace + 0x06FD;
    unreferenced_soundRngTmp = addressSpace + 0x06FF;
    highScoreNames = addressSpace + 0x0700;
    highScoreScoresA = addressSpace + 0x0730;
    highScoreScoresB = addressSpace + 0x073C;
    highScoreLevels = addressSpace + 0x0748;
    initMagic = addressSpace + 0x0750;
}
    

int endingAnimation(int (*endFrame)()) {
    *spriteIndexInOamContentLookup = 2;
    *renderMode = 4;
    if (*gameType == 0) { //must be set to 0 to fix it later

        updateAudioWaitForNmiAndDisablePpuRendering(endFrame);
        disableNmi();
        *accumulator = 2;
        changeCHRBank0();
        *accumulator = 2;
        changeCHRBank1();

        bulkCopyToPpu(0xF7, 0xA939, endFrame);
        bulkCopyToPpu(0xF7, 0xA93E, endFrame);

        selectEndingScreen();
        waitForVBlankAndEnableNmi(endFrame);
        updateAudioWaitForNmiAndResetOamStaging(endFrame);
        updateAudioWaitForNmiAndEnablePpuRendering(endFrame);
        updateAudioWaitForNmiAndResetOamStaging(endFrame);
        *renderMode = 4;
        setMusicTrack(10);
        *accumulator = 0x33;
        render_endingUnskippable(endFrame);
        do {
            render_ending();
            updateAudioWaitForNmiAndResetOamStaging(endFrame);
        } while (ending_customVars[0] != 0 || *newlyPressedButtons_player1 != 0x10);
    }
    else{
        *levelNumber = levelDisplayTable[*player1_levelNumber] & 0x0F;
        totalScore[0] = 0;
        totalScore[1] = 0;
        totalScore[2] = 0;
        *generalCounter4 = *levelNumber << 4;
        *generalCounter5 = *player1_startHeight << 4;
        updateAudioWaitForNmiAndDisablePpuRendering(endFrame);
        disableNmi();
        if (*levelNumber == 9) {
            *accumulator = 1;
            changeCHRBank0();
            *accumulator = 1;
            changeCHRBank1();
            bulkCopyToPpu(0xF7, 0x9E83, endFrame); //todo
        }
        else {
            *registerX = 3;
            if (*levelNumber != 2) {
                if (*levelNumber != 6) {
                    *registerX = 2;
                }
            }
            *accumulator = *registerX;
            changeCHRBank0();
            *accumulator = 2;
            changeCHRBank1();
            bulkCopyToPpu(0xF7, 0x9EA2, endFrame);
        }
        bulkCopyToPpu(0xF7, 0x9EA7, endFrame);
        ending_initTypeBVars();
        waitForVBlankAndEnableNmi(endFrame);
        updateAudioWaitForNmiAndResetOamStaging(endFrame);
        updateAudioWaitForNmiAndEnablePpuRendering(endFrame);
        updateAudioWaitForNmiAndResetOamStaging(endFrame);
        *renderMode = 4;
        setMusicTrack(10);
        *accumulator = 0x66;
        render_endingUnskippable(endFrame);
        totalScore[0] = player1_score[0];
        totalScore[1] = player1_score[1];
        totalScore[2] = player1_score[2];
        *soundEffectSlot1Init = 2;
        player1_score[0] = 0;
        player1_score[1] = 0;
        player1_score[2] = 0;
        *accumulator = 0x33;
        render_endingUnskippable(endFrame);
        if (*generalCounter4 != 0) {
            do {
                (*generalCounter4)--;
                if (((*generalCounter4) & 0x0F) == 0x0F) {
                    *generalCounter4 = ((*generalCounter4) & 0xF0) | 9;
                }
                *accumulator = *generalCounter4;
                add100Points();
                *soundEffectSlot1Init = 1;
                *accumulator = 0x1;
                render_endingUnskippable(endFrame);
            } while (*generalCounter4 != 0);
            *accumulator = 0x33;
            render_endingUnskippable(endFrame);
        }
        if (*generalCounter5 != 0) {
            do {
                (*generalCounter5)--;
                if (((*generalCounter5) & 0x0F) == 0x0F) {
                    *generalCounter5 = ((*generalCounter5) & 0xF0) | 9;
                }
                *accumulator = *generalCounter5;
                add100Points();
                *soundEffectSlot1Init = 1;
                *accumulator = 0x1;
                render_endingUnskippable(endFrame);
            } while (*generalCounter5 != 0);
            *accumulator = 0x33;
            render_endingUnskippable(endFrame);
        }
        do {
            render_ending();
            updateAudioWaitForNmiAndResetOamStaging(endFrame);
        } while (*newlyPressedButtons_player1 != 0x10);
        *levelNumber = *player1_levelNumber;
        score[0] = totalScore[0];
        score[1] = totalScore[1];
        score[2] = totalScore[2];
    }
    return 50;
}

int render_ending() {
    int clockcycles = 5;
    if (*gameType == 0) {
        if (*ending_customVars != 0) {
            *spriteYOffset = *ending_customVars;
            *spriteXOffset = rocketToXOffsetTable[*ending];
            *spriteIndexInOamContentLookup = rocketToSpriteTable[*ending];
            clockcycles += loadSpriteIntoOamStaging();
            *generalCounter = *ending << 1;
            *registerX = ((*frameCounter & 2) >> 1) + *generalCounter;
            *spriteIndexInOamContentLookup = rocketToJetSpriteTable[*registerX];
            *spriteXOffset += rocketToJetXOffsetTable[*ending];
            loadSpriteIntoOamStaging();
            if (ending_customVars[1] == 0xF0) {
                if (ending_customVars[0] < 0xB0) {
                    if ((*frameCounter & 1) == 0) {
                        return clockcycles + 12;
                    }
                }
                *soundEffectSlot0Init = 3;
                ending_customVars[0]--;
                if (ending_customVars[0] >= 0x80) {
                    ending_customVars[0]--;
                }
            }
            else {
                ending_customVars[1]++;
                clockcycles += 6;
            }
        }
        else {
            clockcycles += 1;
        }
    }
    else {
        if (*levelNumber != 9) {
            ending_typeBCathedralSetSprite();
            (*ending_typeBCathedralFrameDelayCounter)++;
            for (*ending_currentSprite = 0; *ending_currentSprite < *startHeight; (*ending_currentSprite)++) {
                *generalCounter = addressSpace[0xA767 + *levelNumber];
                if (ending_customVars[1 + *ending_currentSprite] != *generalCounter) {
                    *spriteXOffset = ending_customVars[1 + *ending_currentSprite];
                    ending_computeTypeBCathedralYTableIndex();
                    *spriteYOffset = ending_typeBCathedralYTable[*registerX];
                    loadSpriteIntoOamStaging();
                    if (ending_typeBCathedralFrameDelayTable[*levelNumber] == *ending_typeBCathedralFrameDelayCounter) {
                        *spriteXOffset += ending_typeBCathedralVectorTable[*levelNumber];
                        ending_customVars[1 + *ending_currentSprite] = *spriteXOffset;
                        ending_computeTypeBCathedralYTableIndex();
                        if (ending_typeBCathedralXTable[*registerX] == *spriteXOffset) {
                            ending_customVars[2 + *ending_currentSprite] = addressSpace[0xA75D + *levelNumber];
                        }    
                    }
                }
            }
            (*ending_currentSprite)--;
            if (ending_typeBCathedralFrameDelayTable[*levelNumber] == *ending_typeBCathedralFrameDelayCounter) {
                *ending_typeBCathedralFrameDelayCounter = 0;
            }
        }
        else {
            int clockcycles = 9;
            *accumulator = *player1_startHeight;
            switch (*accumulator) {
            case 0: clockcycles += kidIcarus(); break;
            case 1: clockcycles += link(); break;
            case 2: clockcycles += samus(); break;
            case 3: clockcycles += donkeyKong(); break;
            case 4: clockcycles += bowser(); break;
            case 5: clockcycles += marioLuigiPeach(); break;
            default: printf("Switch Currupted!\r\n");
            }
            return clockcycles;
        }
    }
    return clockcycles + 6;
}

int ending_typeBConcertPatchToPpuForHeight() {
    int clockcycles = 9;
    *accumulator = *ending;
    if (*accumulator == 6) {
        clockcycles += 6;
    }
    else {
        if (*accumulator < 6) {
            clockcycles += 10;
            switch (*accumulator) {
            case 0: patchToPpuAddr[0] = 0x22; break;
            case 1: patchToPpuAddr[0] = 0x34; break;
            case 2: patchToPpuAddr[0] = 0x4A; break;
            case 3: patchToPpuAddr[0] = 0x62; break;
            case 4: patchToPpuAddr[0] = 0x7A; break;
            case 5: patchToPpuAddr[0] = 0x96; break;
            }
            patchToPpuAddr[1] = 0xA8;
        }
        else {
            printf("Switch Currupted!\r\n");
        }
    }
    return clockcycles + 6;
}

int ending_initTypeBVars() {
    *ending = 0;
    *ending_customVars = 0;
    *ending_typeBCathedralFrameDelayCounter = 0;
    *spriteIndexInOamContentLookup = 0;
    if (*levelNumber == 9) {
        *ending = *player1_startHeight + 1;
        ending_typeBConcertPatchToPpuForHeight();
        *ending = 0;
        ending_customVars[2] = 0;
        ending_customVars[3] = addressSpace[0xA73D];
        ending_customVars[4] = addressSpace[0xA73E];
        ending_customVars[5] = addressSpace[0xA73F];
        ending_customVars[6] = addressSpace[0xA740];
    }
    else {
        ending_customVars[1] = addressSpace[0xA75D + *levelNumber];
        ending_customVars[2] = addressSpace[0xA767 + *levelNumber];
        ending_customVars[3] = addressSpace[0xA767 + *levelNumber];
        ending_customVars[4] = addressSpace[0xA767 + *levelNumber];
        ending_customVars[5] = addressSpace[0xA767 + *levelNumber];
        ending_customVars[6] = addressSpace[0xA767 + *levelNumber];
    }
    return 6;
}

int add100Points() {
    totalScore[1]++;
    if ((totalScore[1] & 0x0F) >= 10) {
        totalScore[1] += 6;
        if ((totalScore[1] & 0xF0) >= 0xA0) {
            totalScore[1] += 0x60;
            totalScore[2]++;
            if ((totalScore[2] & 0x0F) >= 10) {
                totalScore[2] += 6;
            }
        }
    }
    return 6;
}

int ending_computeTypeBCathedralYTableIndex() {
    *generalCounter = *levelNumber << 1;
    *registerX = *ending_currentSprite + *generalCounter * 2;
    return 32;
}

int branchOnGameMode(int (*endFrame)(), int (*endFrameNoNMI)()) {
    int clockcycles = 9;
    *accumulator = *gameMode;
    switch (*accumulator) {
        case 0: clockcycles += gamemode_legalScreen(endFrame); break;
        case 1: clockcycles += gameMode_titleScreen(endFrame); break;
        case 2: clockcycles += gameMode_gameTypeMenu(endFrame, endFrameNoNMI); break;
        case 3: clockcycles += gameMode_levelMenu(endFrame, endFrameNoNMI); break;
        case 4: clockcycles += gameMode_playAndEndingHighScore(endFrame, endFrameNoNMI); break;
        case 5: clockcycles += gameMode_playAndEndingHighScore(endFrame, endFrameNoNMI); break;
        case 6: clockcycles += gameMode_startDemo(endFrame, endFrameNoNMI); break;
        default: printf("Switch Currupted!\r\n");
    }
    return clockcycles;
}


int gameMode_playAndEndingHighScore(int (*endFrame)(), int (*endFrameNoNMI)()) {
    int clockcycles = 9;
    *accumulator = *gameModeState;
    switch (*accumulator) {
        case 0: clockcycles += gameModeState_initGameBackground(endFrame, endFrameNoNMI); break;
        case 1: clockcycles += gameModeState_initGameState(endFrame); break;
        case 2: clockcycles += gameModeState_updateCountersAndNonPlayerState(); break;
        case 3: clockcycles += gameModeState_handleGameOver(endFrame, endFrameNoNMI); break;
        case 4: clockcycles += gameModeState_updatePlayer1(endFrame); break;
        case 5: clockcycles += gameModeState_updatePlayer2(endFrame); break;
        case 6: clockcycles += gameModeState_checkForResetKeyCombo(); break;
        case 7: clockcycles += gameModeState_startButtonHandling(endFrame); break;
        case 8: clockcycles += gameModeState_vblankThenRunState2(); break;
    default: printf("Switch Currupted!\r\n");
    }
    return clockcycles;
}

int branchOnPlayStatePlayer1(int (*endFrame)()) {
    int clockcycles = 9;
    *accumulator = *playState;
    switch (*accumulator) {
    case 0: clockcycles += playState_unassignOrientationId(); break;
    case 1: clockcycles += playState_playerControlsActiveTetrimino(); break;
    case 2: clockcycles += playState_lockTetrimino(); break;
    case 3: clockcycles += playState_checkForCompletedRows(); break;
    case 4: clockcycles += 6; break; //noop
    case 5: clockcycles += playState_updateLinesAndStatistics(); break;
    case 6: clockcycles += playState_bTypeGoalCheck(endFrame); break;
    case 7: clockcycles += playState_receiveGarbage(); break;
    case 8: clockcycles += playState_spawnNextTetrimino(); break;
    case 9: clockcycles += 6; break; //noop
    case 10: clockcycles += playState_updateGameOverCurtain(endFrame); break;
    case 11: clockcycles += playState_incrementPlayState(); break;
    default: printf("Switch Currupted!\r\n");
    }
    return clockcycles;
}

int branchOnPlayStatePlayer2(int (*endFrame)()) {
    int clockcycles = 9;
    *accumulator = *playState;
    switch (*accumulator) {
    case 0: clockcycles += playState_unassignOrientationId(); break;
    case 1: clockcycles += playState_playerControlsActiveTetrimino(); break;
    case 2: clockcycles += playState_lockTetrimino(); break;
    case 3: clockcycles += playState_checkForCompletedRows(); break;
    case 4: clockcycles += 6; break; //noop
    case 5: clockcycles += playState_updateLinesAndStatistics(); break;
    case 6: clockcycles += playState_bTypeGoalCheck(endFrame); break;
    case 7: clockcycles += playState_receiveGarbage(); break;
    case 8: clockcycles += playState_spawnNextTetrimino(); break;
    case 9: clockcycles += 6; break; //noop
    case 10: clockcycles += playState_updateGameOverCurtain(endFrame); break;
    case 11: clockcycles += playState_incrementPlayState(); break;
    default: printf("Switch Currupted!\r\n");
    }
    return clockcycles;
}

#include <time.h>

clock_t end;
clock_t start;

void mainLoop(int (*endFrame)(), int (*endFrameNoNMI)()) {
    start = clock();
    while (true) { //game vever stops; there is no hard reset or power of implemented
        if (frameCounter[0] == 0xFF && frameCounter[1] == 0xFF) {
            //print_playfield();
        }
        branchOnGameMode(endFrame, endFrameNoNMI);
        if (*accumulator == *gameModeState) {
            updateAudioWaitForNmiAndResetOamStaging(endFrame);
        }
        if (*gameMode == 5) {
            if (demoButtonsAddr[1] != 0xDF) {
                demoButtonsAddr[1] = 0xDD;
                frameCounter[1] = 0;
                *gameMode = 1;
            }
        }
    }
}

int playState_updateGameOverCurtain(int (*endFrame)()) {
    int clockcycles = 7;
    if (*curtainRow != 0x14) {
        if ((*frameCounter & 3) == 0) {
            if (((int8_t)*curtainRow) >= 0) {
                *registerY = multBy10Table[*curtainRow];
                *generalCounter3 = 0;
                *currentPiece = 0x13;
                do {
                    playfield[*registerY] = 0x4F;
                    (*registerY)++;
                    (*generalCounter3)++;
                } while (*generalCounter3 < 10);
                *vramRow = *curtainRow;
            }
            else {
                clockcycles += 1;
            }
            (*curtainRow)++;
        }
        else {
            clockcycles += 1;
        }
    }
    else {
        if (*numberOfPlayers != 2) {
            if (player1_score[2] >= 3) {
                for (int i = 0; i < 0x66; i++) {
                    endFrame();
                }
                endingAnimation(endFrame);
                *playState = 0;
                *newlyPressedButtons_player1 = 0;
            }
            else {
                if (*newlyPressedButtons_player1 == 0x10) {
                    *playState = 0;
                    *newlyPressedButtons_player1 = 0;
                }
            }
        }
        else {
            *playState = 0;
            *newlyPressedButtons_player1 = 0;
        }
        clockcycles += 1;
    }
    return clockcycles + 6;
}

int render_endingUnskippable (int(*endFrame)()) {
    *sleepCounter = *accumulator;
    do {
        render_ending();
        updateAudioWaitForNmiAndResetOamStaging(endFrame);
    } while (*sleepCounter != 0);
    return 15;
}

int gameMode_startDemo(int(*endFrame)(), int(*endFrameNoNMI)()) {
    *gameType = 0;
    *player1_startLevel = 0;
    *gameModeState = 0;
    *player1_playState = 0;
    *gameMode = 5;
    gameMode_playAndEndingHighScore(endFrame, endFrameNoNMI);
    return 6;
}

int gameModeState_updatePlayer1(int (*endFrame)()) {
    int clockcycles = 25;
    clockcycles += makePlayer1Active();
    clockcycles += branchOnPlayStatePlayer1(endFrame);
    clockcycles += stageSpriteForCurrentPiece();
    clockcycles += savePlayer1State();
    clockcycles += stageSpriteForNextPiece();
    (*gameModeState)++;
    return clockcycles + 6;
}
int gameModeState_updatePlayer2(int (*endFrame)()) {
    int clockcycles = 7;
    if (*numberOfPlayers == 2) {
        clockcycles += 24;
        clockcycles += makePlayer2Active();
        clockcycles += branchOnPlayStatePlayer2(endFrame);
        clockcycles += stageSpriteForCurrentPiece();
        clockcycles += savePlayer2State();
    }
    else {
        clockcycles += 1;
    }
    (*gameModeState)++;
    return clockcycles + 6;
}






int gameModeState_handleGameOver(int (*endFrame)(), int (*endFrameNoNMI)()) {
    *generalCounter2 = 5;
    if (*player1_playState != 0) {
        if (*numberOfPlayers == 1) {
            (*gameModeState)++;
            return 6;
        }
        else {
            *generalCounter2 = 4;
            if (*player2_playState != 0) {
                (*gameModeState)++;
                return 6;
            }
        }
        
    }
    if (*numberOfPlayers != 1) {
        *gameModeState = 9;
    }
    else {
        *renderMode = 3;
        if (*numberOfPlayers == 1) { //always the case?
            handleHighScoreIfNecessary(endFrame, endFrameNoNMI);
        }
        *player1_playState = 1;
        *player2_playState = 1;
        *registerX = 4;
        *registerY = 5;
        *accumulator = 0xEF;
        memset_page();
        *player1_vramRow = 0;
        *player2_vramRow = 0;
        *player1_playState = 1; //is set twice?
        *player2_playState = 1; //is set twice?
        updateAudioWaitForNmiAndResetOamStaging(endFrame);
        *gameMode = 3;
    }
    int clockcycles = 0;
    return clockcycles + 6;
}

int highScoreEntryScreen(int (*endFrame)(), int (*endFrameNoNMI)()) {
    setMMC1Control();
    setMusicTrack(9);
    *renderMode = 2;
    updateAudioWaitForNmiAndDisablePpuRendering(endFrame);
    disableNmi();
    *accumulator = 0;
    changeCHRBank0();
    *accumulator = 0;
    changeCHRBank1();
    bulkCopyToPpu(0xF9, 0xA225, endFrameNoNMI);
    bulkCopyToPpu(0xF9, 0xA22A, endFrameNoNMI);
    *PPUADDR = 0x20 << 8;
    *PPUADDR |= 0x6D;
    baseAddressTBL[*PPUADDR & 0x3FF] = 10 + *gameType;
    showHighScores(endFrameNoNMI);
    *renderMode = 2;
    waitForVBlankAndEnableNmi(endFrame);//endFrameNoNMI?
    updateAudioWaitForNmiAndResetOamStaging(endFrame);
    updateAudioWaitForNmiAndEnablePpuRendering(endFrame);
    updateAudioWaitForNmiAndResetOamStaging(endFrame);
    *generalCounter = *highScoreEntryRawPos << 1;
    *highScoreEntryNameOffsetForRow = *highScoreEntryRawPos * 6;
    *highScoreEntryNameOffsetForLetter = 0;
    *oamStaging = 0;
    *spriteYOffset = highScorePosToY[*highScoreEntryRawPos & 3];
    while (true) {
        *oamStaging = 0;
        *spriteXOffset = highScoreNamePosToX[*highScoreEntryNameOffsetForLetter];
        *spriteIndexInOamContentLookup = 0x0E;
        if ((*frameCounter & 1) == 0) {
            *spriteIndexInOamContentLookup = 2;
        }
        loadSpriteIntoOamStaging();
        if ((*newlyPressedButtons_player1 & 0x10) != 0) {
            *soundEffectSlot1Init = 2;
            break;
        }
        else {
            if ((*newlyPressedButtons_player1 & 0x81) != 0) {
                *soundEffectSlot1Init = 1;
                (*highScoreEntryNameOffsetForLetter)++;
                if (*highScoreEntryNameOffsetForLetter == 6) {
                    *highScoreEntryNameOffsetForLetter = 0;
                }
            }
            if ((*newlyPressedButtons_player1 & 0x42) != 0) {
                *soundEffectSlot1Init = 1;
                (*highScoreEntryNameOffsetForLetter)--;
                if (((int8_t)*highScoreEntryNameOffsetForLetter) < 0) {
                    *highScoreEntryNameOffsetForLetter = 5;
                }
            }
            if ((*heldButtons_player1 & 4) != 0) {
                if ((*frameCounter & 7) == 0) {
                    *soundEffectSlot1Init = 1;
                    *generalCounter = *highScoreEntryNameOffsetForRow;
                    *registerX = *generalCounter + *highScoreEntryNameOffsetForLetter;
                    *generalCounter = highScoreNames[*registerX];
                    (*generalCounter)--;
                    if (((int8_t)*generalCounter) < 0) {
                        *generalCounter += 0x2C;
                    }
                    highScoreNames[*registerX] = *generalCounter;
                }
            }
            if ((*heldButtons_player1 & 8) != 0) {
                if ((*frameCounter & 7) == 0) {
                    *soundEffectSlot1Init = 1;
                    *generalCounter = *highScoreEntryNameOffsetForRow;
                    *registerX = *generalCounter + *highScoreEntryNameOffsetForLetter;
                    *generalCounter = highScoreNames[*registerX];
                    (*generalCounter)++;
                    if (((int8_t)*generalCounter) >= 0x2C) {
                        *generalCounter -= 0x2C;
                    }
                    highScoreNames[*registerX] = *generalCounter;
                }
            }

        }
        *highScoreEntryCurrentLetter = highScoreNames[*highScoreEntryNameOffsetForRow + *highScoreEntryNameOffsetForLetter];
        *outOfDateRenderFlags = 0x80;
        updateAudioWaitForNmiAndResetOamStaging(endFrame);
    }
    updateAudioWaitForNmiAndResetOamStaging(endFrame);
    int clockcycles = 0;
    return clockcycles + 6;
}

int handleHighScoreIfNecessary(int (*endFrame)(), int (*endFrameNoNMI)()) {
    int clockcycles = 0;
    bool adjustHighScores = false;
    *highScoreEntryRawPos = 0;
    if (*gameType != 0) {
        *highScoreEntryRawPos = 4;
    }
    do {
        *generalCounter2 = *highScoreEntryRawPos;
        *registerY = *highScoreEntryRawPos * 3;
        if (highScoreScoresA[*registerY] < player1_score[2]) {
            adjustHighScores = true;
            break;
        }
        else {
            if (highScoreScoresA[*registerY] == player1_score[2]) {
                (*registerY)++;
                if (highScoreScoresA[*registerY] < player1_score[1]) {
                    adjustHighScores = true;
                    break;
                }
                else {
                    if (highScoreScoresA[*registerY] == player1_score[1]) {
                        (*registerY)++;
                        if (highScoreScoresA[*registerY] <= player1_score[0]) {
                            adjustHighScores = true;
                            break;
                        }
                    }
                }
            }
        }
        (*highScoreEntryRawPos)++;
    } while ((*highScoreEntryRawPos != 3) && (*highScoreEntryRawPos != 7));
    if (adjustHighScores == true) {
        if ((*highScoreEntryRawPos & 3) < 2) {
            *accumulator = 6;
            copyHighScoreNameToNextIndex();
            *accumulator = 3;
            copyHighScoreScoreToNextIndex();
            *accumulator = 1;
            copyHighScoreLevelToNextIndex();
            if ((*highScoreEntryRawPos & 3) == 0) {
                *accumulator = 0;
                copyHighScoreNameToNextIndex();
                *accumulator = 0;
                copyHighScoreScoreToNextIndex();
                *accumulator = 0;
                copyHighScoreLevelToNextIndex();
            }
        }
        *accumulator = 0;
        *registerY = 6;
        *registerX = highScoreIndexToHighScoreNamesOffset[*highScoreEntryRawPos];
        do {
            highScoreNames[*registerX] = 0;
            (*registerX)++;
            (*registerY)--;

        } while (*registerY != 0);
        *registerX = highScoreIndexToHighScoreScoresOffset[*highScoreEntryRawPos];
        highScoreScoresA[*registerX] = player1_score[2];
        (*registerX)++;
        highScoreScoresA[*registerX] = player1_score[1];
        (*registerX)++;
        highScoreScoresA[*registerX] = player1_score[0];
        highScoreLevels[*highScoreEntryRawPos] = *player1_levelNumber;
        highScoreEntryScreen(endFrame, endFrameNoNMI);
    }
    return clockcycles + 6;
}

int gameModeState_startButtonHandling(int (*endFrame)()) {
    int clockcycles = 0;
    if (*gameMode == 5 && *newlyPressedButtons_player1 == 0x10) {
        *gameMode = 1;
    }
    else {
        if (*renderMode == 3 && (*newlyPressedButtons_player1 & 0x10) != 0) {
            if (*player1_playState != 10) {
                *musicStagingNoiseHi = 5;
                *renderMode = 0;
                updateAudioAndWaitForNmi(endFrame);
                *PPUMASK = 0x16;
                *accumulator = 0xFF;
                *registerX = 0x2;
                *registerY = 0x2;
                memset_page();

                while (true) {
                    *spriteXOffset = 0x70;
                    *spriteXOffset = 0x77;
                    *spriteIndexInOamContentLookup = 5;
                    loadSpriteIntoOamStaging();
                    if (*newlyPressedButtons_player1 == 0x10) {
                        break;
                    }
                    updateAudioWaitForNmiAndResetOamStaging(endFrame);
                }
                *PPUMASK = 0x1E;
                *musicStagingNoiseHi = 0;
                *player1_vramRow = 0;
                *renderMode = 3;
            }
        }
    }
    (*gameModeState)++;
    return clockcycles + 6;
}

int gameModeState_updateCountersAndNonPlayerState() {
    int clockcycles = 8;
    *accumulator = 3;
    clockcycles += changeCHRBank0();
    clockcycles += 8;
    *accumulator = 3;
    clockcycles += changeCHRBank1();
    *accumulator = 0;
    clockcycles += 20;
    *oamStagingLength = 0;
    (*player1_fallTimer)++;
    (*player2_fallTimer)++;
    if (*twoPlayerPieceDelayCounter != 0) {
        clockcycles += 5;
        (*twoPlayerPieceDelayCounter)++;
    }
    clockcycles += 5;
    if ((*newlyPressedButtons_player1 &  0x20) != 0) {
        *displayNextPiece = *displayNextPiece ^ 1;
    }
    clockcycles += 5;
    (*gameModeState)++;
    return clockcycles + 6;
}

int gameModeState_initGameState(int(*endFrame)()) {
    *accumulator = 0xEF;
    *registerX = 4;
    *registerY = 4;
    memset_page();
    *registerX = 0x0F;
    *accumulator = 0;
    for (uint8_t i = 0; i < 16; i++) {
        statsByType[i] = 0;
    }
    *player1_tetriminoX = 5;
    *player1_tetriminoX = 5;

    *player1_tetriminoY = 0;
    *player2_tetriminoY = 0;
    *player1_vramRow = 0;
    *player2_vramRow = 0;
    *player1_fallTimer = 0;
    *player2_fallTimer = 0;
    *pendingGarbage = 0;
    *pendingGarbageInactivePlayer = 0;
    player1_score[0] = 0;
    player1_score[1] = 0;
    player1_score[2] = 0;
    player2_score[0] = 0;
    player2_score[1] = 0;
    player2_score[2] = 0;
    player1_lines[0] = 0;
    player1_lines[1] = 0;
    player2_lines[0] = 0;
    player2_lines[1] = 0;
    *twoPlayerPieceDelayCounter = 0;
    lineClearStatsByType[0] = 0;
    lineClearStatsByType[1] = 0;
    lineClearStatsByType[2] = 0;
    lineClearStatsByType[3] = 0;
    *allegro = 0;
    *demo_heldButtons = 0;
    *demo_repeats = 0;
    *demoIndex = 0;
    *demoButtonsAddr = 0;
    *spawnID = 0;


    demoButtonsAddr[1] = 0xDD;
    *renderMode = 3;
    *player1_autorepeatY = 0xB4;
    *player2_autorepeatY = 0xB4;
    chooseNextTetrimino();
    *player1_currentPiece = *accumulator;
    *player2_currentPiece = *accumulator;
    incrementPieceStat();
    generateNextPseudorandomNumber();
    chooseNextTetrimino();
    *nextPiece = *accumulator;
    *twoPlayerPieceDelayPiece = *accumulator;
    if (*gameType == 1) {
        *player1_lines = 0x25;
        *player2_lines = 0x25;
    }
    *outOfDateRenderFlags = 0x47;
    int clockcycles = updateAudioWaitForNmiAndResetOamStaging(endFrame);
    initPlayfieldIfTypeB(endFrame);
    setMusicTrack(musicSelectionTable[*musicType]);
    (*gameModeState)++;
    clockcycles += 13;
    return clockcycles + 6; //only sometimes ends the frame B-Type!
}

int gameModeState_initGameBackground(int(*endFrame)(), int(*endFrameNoNMI)()) {
    updateAudioWaitForNmiAndDisablePpuRendering(endFrame);
    disableNmi();
    *currentPpuCtrl = 0x98;
    *PPUControlRegister = 0x98;
    *tram_addr = *vram_addr;
    *accumulator = 3;
    changeCHRBank0();
    *accumulator = 3;
    changeCHRBank1();
    bulkCopyToPpu(0xFB, 0x8603, endFrame);
    bulkCopyToPpu(0xFB, 0x8608, endFrame);
    *PPUADDR = 0x20 << 8;
    *PPUADDR |= 0x83;
    if (*gameType == 0) {
        baseAddressTBL[*PPUADDR & 0x3FF] = 10;
        *PPUADDR = 0x20 << 8;
        *PPUADDR |= 0xB8;
        *accumulator = highScoreScoresA[0];
        twoDigsToPPU();
        *accumulator = highScoreScoresA[1];
        twoDigsToPPU();
        *accumulator = highScoreScoresA[2];
        twoDigsToPPU();
    }
    else {
        baseAddressTBL[*PPUADDR & 0x3FF] = 11;
        *PPUADDR = 0x20 << 8;
        *PPUADDR |= 0xB8;
        *accumulator = highScoreScoresB[0];
        twoDigsToPPU();
        *accumulator = highScoreScoresB[1];
        twoDigsToPPU();
        *accumulator = highScoreScoresB[2];
        twoDigsToPPU();
        *registerX = 0;


        *PPUADDR = game_typeb_nametable_patch[*registerX] << 8;
        (*registerX)++;
        *PPUADDR |= game_typeb_nametable_patch[*registerX];
        (*registerX)++;

        while (true) {
            *accumulator = game_typeb_nametable_patch[*registerX];
            (*registerX)++;

            if (*accumulator != 0xFE) {
                if (*accumulator != 0xFD) {
                    baseAddressTBL[*PPUADDR & 0x3FF] = *accumulator;
                    (*PPUADDR)++;
                }
                else {
                    break;
                }
            }
            else {
                *PPUADDR = game_typeb_nametable_patch[*registerX] << 8;
                (*registerX)++;
                *PPUADDR |= game_typeb_nametable_patch[*registerX];
                (*registerX)++;
            }
        }

        *PPUADDR = 0x23 << 8;
        *PPUADDR |= 0x3B;
        baseAddressTBL[*PPUADDR & 0x3FF] = *startHeight & 0xF;
    }
    waitForVBlankAndEnableNmi(endFrame);
    updateAudioWaitForNmiAndResetOamStaging(endFrame);
    updateAudioWaitForNmiAndEnablePpuRendering(endFrame);
    int clockcycles = updateAudioWaitForNmiAndResetOamStaging(endFrame);
    clockcycles += 26;
    *player1_playState = 1;
    *player2_playState = 1;
    *player1_levelNumber = *player1_startLevel;
    *player2_levelNumber = *player2_startLevel;
    (*gameModeState)++;
    return clockcycles + 6;
}

int gameMode_levelMenu(int(*endFrame)(), int(*endFrameNoNMI)()) {
    //printf("gameMode_levelMenu\r\n");
    setMMC1Control();
    updateAudio2();
    *renderMode = 1;
    updateAudioWaitForNmiAndDisablePpuRendering(endFrame);
    disableNmi();
    *accumulator = 0;
    changeCHRBank0();
    *accumulator = 0;
    changeCHRBank1();
    bulkCopyToPpu(0xFD, 0x83FE, endFrameNoNMI);
    bulkCopyToPpu(0xFD, 0x83F9, endFrameNoNMI);
    if (*gameType != 1) {
        bulkCopyToPpu(0xFD, 0x8407, endFrameNoNMI);
    }
    showHighScores(endFrameNoNMI);
    waitForVBlankAndEnableNmi(endFrameNoNMI);
    updateAudioWaitForNmiAndResetOamStaging(endFrame);
    *ppuScrollY = 0;
    *ppuScrollX = 0;
    updateAudioWaitForNmiAndEnablePpuRendering(endFrame);
    updateAudioWaitForNmiAndResetOamStaging(endFrame);
    *originalY = 0;
    *dropSpeed = 0;
    while (*player1_startLevel >= 10) {
        *player1_startLevel -= 10;
    }
    while (true) {
        *activePlayer = 0;
        *startLevel = *player1_startLevel;
        *startHeight = *player1_startHeight;
        *selectingLevelOrHeight = *originalY;
        *newlyPressedButtons = *newlyPressedButtons_player1;
        gameMode_levelMenu_handleLevelHeightNavigation();
        *player1_startLevel = *startLevel;
        *player1_startHeight = *startHeight;

        *originalY = *selectingLevelOrHeight;
        if (*newlyPressedButtons_player1 == 0x10) {
            if (*heldButtons_player1 == 0x90) {
                *player1_startLevel += 10;
            }
            *gameModeState = 0;
            *soundEffectSlot1Init = 2;
            (*gameMode)++;
            return 6;//after NIM not figured out yet
        }
        else {
            if (*newlyPressedButtons_player1 == 0x40) {
                *soundEffectSlot1Init = 2;
                (*gameMode)--;
                return 6;//after NIM not figured out yet
            }
            else {
                do {
                    generateNextPseudorandomNumber();
                    *accumulator = *rng_seed & 0xF;
                } while (*accumulator >= 10);
                *player1_garbageHole = *accumulator;
                do {
                    generateNextPseudorandomNumber();
                    *accumulator = *rng_seed & 0xF;
                } while (*accumulator >= 10);
                *player2_garbageHole = *accumulator;
                updateAudioWaitForNmiAndResetOamStaging(endFrame);
            }
        }
    }
    int clockcycles = 0; //after NIM not figured out yet
    return clockcycles + 6;
}

int showHighScores(int(*endFrame)()) {
    int clockcycles = 8;
    if (*numberOfPlayers == 1) {
        bulkCopyToPpu(0xFB, 0x9FFE, endFrame);
        clockcycles += 8;
        *generalCounter2 = 0;
        if (*gameType == 1) {
            clockcycles += 6;
            *generalCounter2 = 4;
        }
        do {
            clockcycles += 50;
            *registerX = (*generalCounter2 & 3) << 1;
            *PPUADDR = highScorePpuAddrTable[*registerX] << 8;
            (*registerX)++;
            *PPUADDR |= highScorePpuAddrTable[*registerX];
            *generalCounter = *generalCounter2 << 1;
            *registerY = *generalCounter + (*generalCounter << 1);
            *registerX = 6;
            do{
                *accumulator = highScoreNames[*registerY];
                *generalCounter = *registerY;
                *registerY = *accumulator;
                *accumulator = highScoreCharToTile[*registerY];
                *registerY = *generalCounter;
                baseAddressTBL[*PPUADDR & 0x3FF] = *accumulator;            
                (*PPUADDR)++;
                clockcycles += 30;
                (*registerY)++;
                (*registerX)--;
            } while (*registerX != 0);
            baseAddressTBL[*PPUADDR & 0x3FF] = 0xFF;
            (*PPUADDR)++;
            clockcycles += 26;
            *generalCounter = *generalCounter2;
            *registerY = *generalCounter + (*generalCounter << 1);
            *accumulator = highScoreScoresA[*registerY];
            clockcycles += twoDigsToPPU();
            clockcycles += 15;
            (*registerY)++;
            *accumulator = highScoreScoresA[*registerY];
            clockcycles += twoDigsToPPU();
            clockcycles += 15;
            (*registerY)++;
            *accumulator = highScoreScoresA[*registerY];
            clockcycles += twoDigsToPPU();
            clockcycles += 25;
            baseAddressTBL[*PPUADDR & 0x3FF] = 0xFF;
            (*PPUADDR)++;
            *registerX = highScoreLevels[*generalCounter2];
            *accumulator = byteToBcdTable[*registerX];
            clockcycles += twoDigsToPPU();
            (*generalCounter2)++;
            clockcycles += 11;
        } while (*generalCounter2  != 3 && *generalCounter2 != 7);
    }
    else {
        clockcycles += 6;
    }
    return clockcycles + 6;
}

int playState_bTypeGoalCheck(int (*endFrame)()) {
    int clockcycles = 6;
    if (*gameType != 0) {
        if ((int8_t)(*lines) <= 0) {
            clockcycles += 12;
            setMusicTrack(*accumulator);
            *registerY = 0x46;
            *registerX = 0;
            while (typebSuccessGraphic[*registerX] != 0x80) {
                playfield[*registerY] = typebSuccessGraphic[*registerX];
                (*registerX)++;
                (*registerY)++;
            }
            *player1_vramRow = 0;
            for (int i = 0; i < 14; i++) {
                endFrame();
            }
            *renderMode = 0;
            for (int i = 0; i < 0x80; i++) {
                endFrame();
            }
            endingAnimation(endFrame);
            clockcycles = 9;
            (*gameModeState)++;
            *playState = 0;
            return clockcycles + 6;
        }
        else {
            clockcycles += 1;
        }
    }
    else {
        clockcycles += 1;
    }
    clockcycles += 6;
    (*playState)++;
    return clockcycles + 6;
}

int playState_receiveGarbage() {
    int clockcycles = 7;
    if (*numberOfPlayers != 1) {
        if (*pendingGarbage != 0) {
            if (*vramRow < 0x20) {
                clockcycles += 12;
                *generalCounter2 = multBy10Table[*pendingGarbage];
                *generalCounter = 0;
                *registerY = *pendingGarbage;
                do {
                    playfield[*generalCounter] = playfield[*generalCounter2];
                    (*generalCounter)++;
                    (*generalCounter2)++;
                    clockcycles += 38;
                } while (*generalCounter2 != 0xC8);
                clockcycles += 8;
                (*registerY)++;
                *registerX = 0;
                do {
                    if (*registerX != *garbageHole) {
                        *accumulator = 0x78;
                    }
                    else {
                        *accumulator = 0xFF;
                        clockcycles += 1;
                    }
                    playfield[*registerY] = *accumulator;
                    (*registerX)++;
                    if (*registerX == 0x0A) {
                        (*registerX)++;
                    }
                    else {
                        clockcycles += 1;
                    }
                    clockcycles += 16;
                } while (*registerY != 0xC8);
                *pendingGarbage = 0;
                *vramRow = 0;
                clockcycles += 15;
                (*playState)++;
            }
            else {
                clockcycles += 1;
            }
        }
        else {
            clockcycles += 6;
            (*playState)++;
        }
    }
    else {
        clockcycles += 6;
        (*playState)++;
    }
    return clockcycles + 6;
}

int copyAddrAtReturnAddressToTmp_incrReturnAddrBy2() {
    return 2;
}

int counter2 = 1;

int bulkCopyToPpu(uint8_t stackPointer, uint16_t PC, int(*endFrame)()) {
    //printf("PC: %0x SP: %0x \r\n", PC,(int)stackPointer);
    int clockcycles = 0;
    PC--;
    addressSpace[0x0100 + stackPointer] = (PC >> 8) & 0x00FF;
    stackPointer--;
    addressSpace[0x0100 + stackPointer] = PC & 0x00FF;
    stackPointer--;
    addressSpace[5] = addressSpace[0x103 + stackPointer - 2];
    addressSpace[6] = addressSpace[0x104 + stackPointer - 2];
    addressSpace[0] = addressSpace[addressSpace[5] + addressSpace[6] * 256 + 1];
    addressSpace[1] = addressSpace[addressSpace[5] + addressSpace[6] * 256 + 2];
    addressSpace[0x103 + stackPointer - 2] += 2;
    if (addressSpace[0x103 + stackPointer - 2] <= 1) {
        addressSpace[0x104 + stackPointer - 2] += 1; //carry
    }
    *registerX = *PPUSTATUS;
    *registerY = 0;
    *accumulator = addressSpace[*((uint16_t*)tmp1) + *registerY];
    int loopcounter = 0;
    while (*accumulator < 0x80) {
        loopcounter++;
        if (*accumulator == 0x60) {
            *tmp2 = addressSpace[stackPointer];
            stackPointer++;
            *tmp1 = addressSpace[stackPointer];
            stackPointer++;
            *registerY = 2;
            *tmp1 += 3;
            if (*tmp1 <= 2) {
                *tmp2 += 1;
            }
        }
        else {
            if (*accumulator == 0x4C) {
                stackPointer--;
                addressSpace[stackPointer] = *tmp1;
                stackPointer--;
                addressSpace[stackPointer] = *tmp2;
                (*registerY)++;
                *((uint16_t*)tmp1) = *((uint16_t*)tmp1 + *registerY);
                *registerY += 2;
            }
            else {
                stackPointer--;
                addressSpace[stackPointer] = *accumulator;
                *PPUADDR = *accumulator << 8;
                (*registerY)++;
                *PPUADDR |= addressSpace[*((uint16_t*)tmp1) + *registerY];
                (*registerY)++;
                *accumulator = addressSpace[*((uint16_t*)tmp1) + *registerY];
                bool carry = *accumulator >= 0x80;
                *accumulator = *accumulator << 1;
                bool isZero = *accumulator == 0;
                stackPointer--;
                addressSpace[stackPointer] = *accumulator;
                *accumulator = *currentPpuCtrl | 4;
                if (carry == false) {
                    *accumulator = *accumulator & 0xFB;
                }
                *currentPpuCtrl = *accumulator;
                *PPUControlRegister = *accumulator;
                *accumulator = addressSpace[stackPointer];
                stackPointer++;
                carry = *accumulator >= 0x80;
                *accumulator = *accumulator << 1;
                if (carry == true) {
                    *accumulator = *accumulator | 2;
                    (*registerY)++;
                }
                isZero;
                carry = *accumulator & 1;
                *accumulator = *accumulator >> 1;
                if (isZero == true) {
                    *accumulator = *accumulator | 0x80;
                }
                carry = *accumulator & 1;
                *accumulator = *accumulator >> 1;
                *registerX = *accumulator;

                do {
                    if (carry == false) {
                        (*registerY)++;
                    }
                    *accumulator = addressSpace[*((uint16_t*)tmp1) + *registerY];
                    if ((*PPUADDR >= 0x3F00 && *PPUADDR <= 0x3FFF)) {
                        tablePalette[*PPUADDR & 0x001F] = *accumulator;
                    }
                    else {
                        baseAddressTBL[*PPUADDR & 0x3FF] = *accumulator;
                        //printf("Address: %0x \r\n", *PPUADDR);
                    }
                    (*PPUADDR)++;
                    (*registerX)--;
                } while (*registerX > 0);

                *accumulator = addressSpace[stackPointer];
                stackPointer++;

                if (*accumulator != 0x3F) {
                    //extra writes to PPUADDR?
                    *PPUADDR = *accumulator << 8;
                    *PPUADDR |= *registerX;
                }

                *tmp1 += *registerY + 1;
                if (*tmp1 < *registerY) {
                    *tmp2 += 1;
                }
            }
        }
        *registerX = *PPUSTATUS;
        *registerY = 0;
        *accumulator = addressSpace[*((uint16_t*)tmp1) + *registerY];
    }
    //printf("Loops %i: \r\n", loopcounter);
    if (loopcounter == 10) {
       endFrame();
    }
    return clockcycles + 6;
}

int gameMode_gameTypeMenu(int (*endFrame)(), int (*endFrameNoNMI)()) {
    //inc init RAM, does this even work
    setMMC1Control();
    *renderMode = 1;
    updateAudioWaitForNmiAndDisablePpuRendering(endFrame);
    disableNmi();
    bulkCopyToPpu(0xFD, 0x82E6, endFrameNoNMI);
    bulkCopyToPpu(0xFD, 0x82EB, endFrameNoNMI);
    *accumulator = 0;
    changeCHRBank0();
    *accumulator = 0;
    changeCHRBank1();
    waitForVBlankAndEnableNmi(endFrame);
    updateAudioWaitForNmiAndResetOamStaging(endFrame);
    updateAudioWaitForNmiAndEnablePpuRendering(endFrame);
    updateAudioWaitForNmiAndResetOamStaging(endFrame);
    *accumulator = musicSelectionTable[*musicType];
    setMusicTrack;
    do {
        *accumulator = 0xFF;
        *registerX = 2;
        *registerY = 2;
        memset_page();
        if (*newlyPressedButtons_player1 == 0x1) { //rigth
            *gameType = 1;
            *soundEffectSlot1Init = 1;
        }
        else {
            if (*newlyPressedButtons_player1 == 0x2) { //left
                *gameType = 0;
                *soundEffectSlot1Init = 1;
            }
        }
        bool checkForUp_h = true;
        if (*newlyPressedButtons_player1 == 0x4) { //down
            *soundEffectSlot1Init = 1;
            *accumulator = *musicType;
            if (*accumulator != 3) {
                (*musicType)++;
                *accumulator = musicSelectionTable[*musicType];
                setMusicTrack(*accumulator);
            }
            else {
                checkForUp_h = false;
            }
        }
        if (checkForUp_h == true) {
            if (*newlyPressedButtons_player1 == 0x8) { //up
                *soundEffectSlot1Init = 1;
                if (*musicType != 0) {
                    (*musicType)--;
                    *accumulator = musicSelectionTable[*musicType];
                    setMusicTrack(*accumulator);
                }
            }
        }
        if (*newlyPressedButtons_player1 == 0x10) { //start
            *soundEffectSlot1Init = 2;
            (*gameMode)++;
            break;
        }
        if (*newlyPressedButtons_player1 == 0x40) { //B
            *soundEffectSlot1Init = 2;
            frameCounter[1] = 0;
            (*gameMode)--;
            break;
        }
        else {
            *registerY = 0;
            *accumulator = *gameType * 96 + 0x3F;
            *spriteXOffset = *accumulator;
            *spriteYOffset = 0x3F;
            *spriteIndexInOamContentLookup = 1;
            if (*frameCounter & 1 == 0) {
                *spriteIndexInOamContentLookup = 2;
            }
            loadSpriteIntoOamStaging();
            *accumulator = *musicType * 16 + 0x8F;
            *spriteYOffset = *accumulator;
            *spriteXOffset = 0x67;
            *spriteIndexInOamContentLookup = 0x53;
            if (*frameCounter & 1 == 0) {
                *spriteIndexInOamContentLookup = 2;
            }
        }
        loadSpriteIntoOamStaging();
        updateAudioWaitForNmiAndResetOamStaging(endFrame);
    } while (true);

    return 400; //guess
}

int gameMode_titleScreen(int (*endFrame)()) {
    updateAudio2();
    *renderMode = 0;
    addressSpace[0xD0] = 0;
    *displayNextPiece = 0;
    updateAudioWaitForNmiAndDisablePpuRendering(endFrame);
    disableNmi();
    *accumulator = 0;
    changeCHRBank0();
    *accumulator = 0;
    changeCHRBank1();
    bulkCopyToPpu(0xFD, 0x826D, endFrame);
    bulkCopyToPpu(0xFD, 0x8272, endFrame);
    waitForVBlankAndEnableNmi(endFrame);
    updateAudioWaitForNmiAndResetOamStaging(endFrame);
    updateAudioWaitForNmiAndEnablePpuRendering(endFrame);
    updateAudioWaitForNmiAndResetOamStaging(endFrame);
    *accumulator = 0;
    *registerX = 2;
    *registerY = 2;
    memset_page();
    frameCounter[1] = 0;

    while (*newlyPressedButtons_player1 != 0x10) {
        updateAudioWaitForNmiAndResetOamStaging(endFrame);
        if (frameCounter[1] == 5) {
            *soundEffectSlot1Init = 2;
            *gameMode = 6;
            return 100; //guess
        }
    }
    *soundEffectSlot1Init = 2;
    (*gameMode)++;
    return 100; //guess
}

int gamemode_legalScreen(int (*endFrame)()) {
    int clockcycles = 6;
    clockcycles += updateAudio2();
    clockcycles += 5;
    *renderMode = 0;
    clockcycles += 6;
    clockcycles += updateAudioWaitForNmiAndDisablePpuRendering(endFrame);
    clockcycles += 6;
    clockcycles += disableNmi();
    clockcycles += 8;
    *accumulator = 0;
    clockcycles += changeCHRBank0();
    clockcycles += 8;
    *accumulator = 0;
    clockcycles += changeCHRBank1();

    clockcycles += 8;
    clockcycles += bulkCopyToPpu(0xFB, 0x821A, endFrame);
    clockcycles += 8;
    clockcycles += bulkCopyToPpu(0xFB, 0x821F, endFrame);

    clockcycles += 6;
    clockcycles += waitForVBlankAndEnableNmi(endFrame);
    clockcycles += 6;
    clockcycles += updateAudioWaitForNmiAndResetOamStaging(endFrame);
    clockcycles += 6;
    clockcycles += updateAudioWaitForNmiAndEnablePpuRendering(endFrame);
    clockcycles += 6;
    clockcycles += updateAudioWaitForNmiAndResetOamStaging(endFrame);

    clockcycles += 12;
    *registerX = 2;
    *registerY = 2;
    memset_page();

    for (int i = 0; i < 255; i++) {
        endFrame();
    }
    *generalCounter = 0xFF;
    while (*generalCounter > 0 && *newlyPressedButtons_player1 != 0x10) {
        updateAudioWaitForNmiAndResetOamStaging(endFrame);
        (*generalCounter)--;
    }
    (*gameMode)++;

    return 100; //guess
}

int updateAudioWaitForNmiAndResetOamStaging(int (*endFrame)()) {
    int clockcycles = 6;
    //clockcycles += updateAudio_jmp();
    *verticalBlankingInterval = 0;
    endFrame();
    clockcycles = 18; //counting after NMI
    *accumulator = 0xFF;
    *registerX = 2;
    *registerY = 2;
    clockcycles += memset_page();
    return clockcycles;
}

/*int updateMusic() {
    int clockcycles = 9;
    if(*musicTrack != 0xFF){
        clockcycles += 4;
        if (*musicTrack == 0) {
            clockcycles += 6;
            if (*currentlyPlayingMusicTrack == 0) {

            }
            else {
                clockcycles += 4;
                clockcycles += updateMusicFrame();
            }
        }
        else {
            clockcycles += 32;
            *currentAudioSlot = *musicTrack;
            *musicTrack_dec = *musicTrack;
            (*musicTrack_dec)--;
            clockcycles += loadMusicTrack();
            clockcycles += updateMusicFrame();
            return clockcycles;
        }
    }
    else {
        clockcycles += 4;
        clockcycles += soundEffectSlot2_makesNoSound();
        return clockcycles;
    }
    return clockcycles + 6;
}*/

int LAA82() {
    int clockcycles = 4;
    *registerX = 0xFF;
    *registerY = 0x00;
    clockcycles += memset_ppu_page_and_more();
    return clockcycles += 6;
}

int memset_ppu_page_and_more() {
    int clockcycles = 44;
    *tmp1 = *accumulator;
    *tmp2 = *registerX;
    *tmp3 = *registerY;
    *PPUSTATUS = *PPUSTATUS & 0x60;
    *currentPpuCtrl &= 0xFB;
    *PPUControlRegister = *currentPpuCtrl;

    //printf("Adress: %i\r\n",(int)*accumulator);
    *PPUADDR = *accumulator << 8;
    *PPUADDR |= 0x00;
    *registerX = 4;
    if (*accumulator != 0x20) {
        *registerX = *tmp3;
    }else{
        clockcycles += 1;
    }
    clockcycles += 5;
    *registerY = 0;
    *accumulator = *tmp2;
    do {
        do {
            baseAddressTBL[*PPUADDR & 0x3FF] = *accumulator;
            (*PPUADDR)++;
            clockcycles += 9;
            (*registerY)--;
        } while (*registerY > 0);
        clockcycles += 5;
        (*registerX)--;
    } while (*registerX > 0);
    clockcycles += 9;
    *registerY = *tmp3;
    *accumulator = *tmp1;
    if (*accumulator >= 0x20) {
        clockcycles += 14;
        *PPUADDR = (*accumulator + 2) << 8;
        *PPUADDR |= 0xC0;
        *registerX = 0x40;
        do {
            baseAddressTBL[*PPUADDR & 0x3FF] = *registerY;
            (*PPUADDR)++;
            clockcycles += 9;
            (*registerX)--;
        } while (*registerX > 0);
        clockcycles--;
    }
    else {
        clockcycles += 1;
    }
    clockcycles += 3;
    *registerX = *tmp2;
        
    return clockcycles + 6;
}

int soundEffectSlot1_menuOptionSelectInit(){
    int clockcycles = 15;
    *accumulator = 0x03;
    *registerY = 0x24;
    clockcycles += initSoundEffectShared();
    return clockcycles + 6;
}

int soundEffectSlot0_endingRocketInit() {
    int clockcycles = 10;
    *accumulator = 0x20;
    *registerY = 0x08;
    clockcycles += initSoundEffectShared();
    return clockcycles;
}

int soundEffectSlot0_gameOverCurtainInit() {
    int clockcycles = 10;
    *accumulator = 0x40;
    *registerY = 0x04;
    clockcycles += initSoundEffectShared();
    return clockcycles;
}

int stopSoundEffectSlot0() {
    *soundEffectSlot0Playing = 0;
    *noiseVolume = 0x10;
    return 18;
}

int advanceSoundEffectSlot0WithoutUpdate() {
    int clockcyles = 6;
    clockcyles += advanceAudioSlotFrame();
    clockcyles += 2;
    if (*accumulator == 0) {
        clockcyles += 12;
        *soundEffectSlot0Playing = 0;
        *noiseVolume = 16;
    }
    else {
        clockcyles += 1;
    }
    return clockcyles + 6;
}

int musicLoOffset_setLo_h() {
    int clockcyles = 9;
    *accumulator = musicChanInhibit[*registerX];
    if (*accumulator == 0) {
        clockcyles += 17;
        *accumulator += *AUDIOTMP2;
        printf("Write to address %04x\r\nIngoring it...\r\n", 0x4002 + *registerY);
    }
    else {
        clockcyles += 3;
    }
    return clockcyles;
}

int musicLoOffset_setLoAndSaveFrameCounter_h() {
    int clockcyles = 13;
    musicChanLoFrameCounter[*registerX] = *registerY;
    clockcyles += musicLoOffset_setLo_h();
    return clockcyles;
}

int musicLoOffset_8AndC_h() {
    int clockcycles = 6;
    if (*AUDIOTMP3 == 0x31) {
        *registerY = 0x27;
    }
    else {
        clockcycles += 1;
        *registerY = *AUDIOTMP3;
    }
    clockcycles += 19;
    if (musicChanNote[*registerX] == 0x46) {
        clockcycles += 9;
        *accumulator = 0;
    }
    else {
        clockcycles += 7;
        *accumulator = loOff9To0FallTable[*registerY];
    }

    clockcycles += musicLoOffset_setLoAndSaveFrameCounter_h();
    return clockcycles;
}

int updateMusicFrame_setChanLoOffset() {
    int clockcyles = 14;
    *AUDIOTMP3 = musicChanLoFrameCounter[*registerX];
    if (*AUDIOTMP1 == 0x20) {
        clockcyles += 8;
        if (*AUDIOTMP3 == 10) {
            clockcyles += 2;
            *registerY = 0;
        }
        else {
            clockcyles += 1;
            *registerY = *AUDIOTMP3;
        }
        *accumulator = loOffTrillNeg2To2Table[*registerY];
        clockcyles += 10;
        clockcyles += musicLoOffset_setLoAndSaveFrameCounter_h();
    }
    else {
        clockcyles += 4;
        if (*AUDIOTMP1 == 0xA0) {
            clockcyles += 5;
            if (*AUDIOTMP3 == 0x2B) {
                clockcyles += 2;
                *registerY = 0x21;
            }
            else {
                *registerY = *AUDIOTMP3;
            }
            clockcyles += 6;
            *accumulator = loOffSlowStartTrillTable[*registerY];
            clockcyles += musicLoOffset_setLoAndSaveFrameCounter_h();
        }
        else {
            clockcyles += 4;
            if (*AUDIOTMP1 == 0x60) {
                clockcyles += 9;
                if (musicChanNote[*registerX] < 0x4C) {
                    //both branches do the same...
                }
                else {
                    clockcyles += 1;
                }
                *accumulator = 0xFE;
                clockcyles *= musicLoOffset_setLo_h();
            }
            else {
                clockcyles += 4;
                if (*AUDIOTMP1 == 0x40) {
                    clockcyles += 7;
                    if (*AUDIOTMP3 <= 0x10) {
                        clockcyles += 5;
                        *accumulator = loOffDescendToNeg11BounceToNeg9Table[*registerY];
                        clockcyles += musicLoOffset_setLo_h();
                    }
                    else {
                        clockcyles += 1;
                    }
                }
                else {
                    clockcyles += 4;
                    if (*AUDIOTMP1 == 0x80) {
                        clockcyles += 1;
                        clockcyles += musicLoOffset_8AndC_h();
                    }
                    else {
                        clockcyles += 4;
                        if (*AUDIOTMP1 == 0xC0) {
                            clockcyles += 1;
                            clockcyles += musicLoOffset_8AndC_h();
                        }
                        else {
                            //same as 0x20 case;
                            clockcyles += 8;
                            if (*AUDIOTMP3 == 10) {
                                clockcyles += 2;
                                *registerY = 0;
                            }
                            else {
                                clockcyles += 1;
                                *registerY = *AUDIOTMP3;
                            }
                            *accumulator = loOffTrillNeg2To2Table[*registerY];
                            clockcyles += 10;
                            clockcyles += musicLoOffset_setLoAndSaveFrameCounter_h();
                        }
                    }
                }
            }
        }
    }
    return clockcyles + 6;
}

int computeSoundEffMethod() {
    int clockcycles = 12;
    *currentAudioSlot = *accumulator;
    uint8_t temp = *accumulator;
    *AUDIOTMP2 = 0xE0;
    *registerY = 0;
    do {
        clockcycles += 5;
        (*currentAudioSlot)--;
        if (*currentAudioSlot == 0) {
            clockcycles += 18;
            *AUDIOTMP3 = addressSpace[*((uint16_t*)AUDIOTMP1) + *registerY];
            (*registerY)++;
            *AUDIOTMP4 = addressSpace[*((uint16_t*)AUDIOTMP1) + *registerY];
            *accumulator = temp;
            *currentAudioSlot = temp;

            //printf("Address: %02x %02x\r\n", *AUDIOTMP3, *AUDIOTMP4);

            return clockcycles + 12;
        }
        *registerY += 2;
        clockcycles += 12;
    } while (*registerY != 0x22);
    clockcycles += 15;
    *AUDIOTMP3 = 0x91;
    *AUDIOTMP4 = 0xE0;

    *accumulator = temp;
    *currentAudioSlot = temp;
    return clockcycles + 6;
}

int disableNmi() {
    *currentPpuCtrl = *currentPpuCtrl & 0x7F;
    *PPUControlRegister = *currentPpuCtrl;
    return 18;
}

int initSq12IfTrashedBySoundEffect() {
    int clockcycles = 5;
    if (*resetSq12ForMusic != 0) {
        clockcycles += 4;
        if (*resetSq12ForMusic != 1) {
            clockcycles += 22;
            //0x4001
            setsweep2(0x7F);
            //0x4002
            *pulse2SeqReload = (*pulse2SeqReload & 0xFF00) | *musicStagingSq2Lo;

            //0x4003
            setpulseSequence2(*musicStagingSq2Hi);
        }
        else {
            clockcycles += 1;
        }
        clockcycles += 26;
        //0x4001
        setsweep(0x7F);
        //0x4002
        *pulse1SeqReload = (*pulse1SeqReload & 0xFF00) | *musicStagingSq1Lo;

        //0x4003
        setpulseSequence(*musicStagingSq1Hi);

        *resetSq12ForMusic = 0;

    }
    else {
        clockcycles += 1;
    }
    return clockcycles + 6;
}

int soundEffectSlot1_menuScreenSelectPlaying() {
    int clockcycles = 6;
    clockcycles += advanceAudioSlotFrame();
    if (*accumulator == 0) {
        clockcycles += 13;
        (*soundEffectSlot1TertiaryCounter)++;
        if (*soundEffectSlot1TertiaryCounter == 4) {
            clockcycles += 3;
            clockcycles += soundEffectSlot1Playing_stop();
            return clockcycles;
        }else{
            clockcycles += 36;
            *soundEffectSlot1Tmp = *soundEffectSlot1SecondaryCounter >> 4;
            *soundEffectSlot1SecondaryCounter = *soundEffectSlot1SecondaryCounter - *soundEffectSlot1Tmp - 1;
            
            //0x4002
            *pulse1SeqReload = (*pulse1SeqReload & 0xFF00) | *soundEffectSlot1SecondaryCounter;

            //0x4003
            setpulseSequence(0x28);
        }
    }
    else {
        clockcycles += 7;
        return clockcycles;
    }
    return clockcycles + 6;
}

int soundEffectSlot1_menuScreenSelectInit() {
    int clockcycles = 10;
    *accumulator = 3;
    *registerY = 0x2C;
    clockcycles += initSoundEffectShared();
    *soundEffectSlot1SecondaryCounter = soundEffectSlot1_menuScreenSelectInitData[2];
    return clockcycles + 6;
}

int soundEffectSlot1_levelUpInit() {
    int clockcycles = 7;
    *accumulator = 6;
    *registerY = 0x1C;
    clockcycles += initSoundEffectShared();
    return clockcycles;
}

int soundEffectSlot1_levelUpPlaying() {
    int clockcycles = 6;
    clockcycles += advanceAudioSlotFrame();
    if (*accumulator == 0) {
        clockcycles += 16;
        *registerY = *soundEffectSlot1SecondaryCounter;
        (*soundEffectSlot1SecondaryCounter)++;
        *accumulator = soundEffectSlot1_levelUp_lo[*registerY];
        if (*accumulator != 0) {
            //0x4002
            clockcycles += 19;
            *pulse1SeqReload = (*pulse1SeqReload & 0xFF00) | *accumulator;
            setpulseSequence(0x28);
        }
        else {
            clockcycles += 4;
            clockcycles += soundEffectSlot1Playing_stop();
        }
    }
    else {
        return clockcycles + 7;
    }
    return clockcycles;
}

int soundEffectSlot1_tetrisAchievedInit() {
    //printf("soundEffectSlot1_tetrisAchievedinit\r\n");
    int clockcycles = 11;
    *registerY = 0x30;
    clockcycles += initSoundEffectShared();
    clockcycles += 7;
    *soundEffectSlot1TertiaryCounter = 0x10;
    return clockcycles + 6;
}

int soundEffectSlot1_tetrisAchievedPlaying() {
    //printf("soundEffectSlot1_tetrisAchievedPlaying\r\n");
    int clockcycles = 8;
    clockcycles += advanceAudioSlotFrame();
    if (*accumulator == 0) {
        clockcycles += 5;
        *registerY = 0x30;
        clockcycles += LE442();
    }
    else {
        return clockcycles + 7;
    }
    return clockcycles;
}

int soundEffectSlot1_lineClearingPlaying() {
    //printf("soundEffectSlot1_lineClearingPlaying\r\n");
    int clockcycles = 6;
    clockcycles += advanceAudioSlotFrame();
    if (*accumulator == 0) {
        *registerY = 0x38;
        clockcycles += LE442();
    }
    else {
        return clockcycles + 7;
    }
    return clockcycles;
}

int LE442() {
    int clockcycles = 6;
    clockcycles += copyToSq1Channel();
    clockcycles += 36;
    *registerY = *soundEffectSlot1SecondaryCounter + *soundEffectSlot1TertiaryCounter;
    //0x4002
    uint8_t temp = soundEffectSlot1_lineClearing_lo[*registerY];
    *pulse1SeqReload = (*pulse1SeqReload & 0xFF00) | temp;
     //0x4000
    *accumulator = soundEffectSlot1_lineClearing_vol[*registerY];
    setpulse(*accumulator);
    if (*accumulator == 0) {
        clockcycles += 7;
        if (*soundEffectSlot1Playing == 4) {
            clockcycles += 5;
            *currentAudioSlot = 9;
            clockcycles += soundEffectSlot1_lineClearingInit();
        }
        else {
            clockcycles += 4;
            clockcycles += soundEffectSlot1Playing_stop();
        }
    }
    else {
        clockcycles += 12;
        (*soundEffectSlot1SecondaryCounter)++;
        return clockcycles;
    }
    return clockcycles;
}

int soundEffectSlot1_lineClearingInit() {
    int clockcycles = 14;
    *accumulator = 4;
    *registerY = 0x38;
    clockcycles += initSoundEffectShared();
    clockcycles += 4;
    *soundEffectSlot1TertiaryCounter = 0;
    return clockcycles + 6;
}

int soundEffectSlot1_rotateTetriminoInit() {
    int clockcycles = 6;
    clockcycles += LE33B();
    if (!(*accumulator == 0 || *accumulator == 4 || *accumulator == 6 || *accumulator == 9 || *accumulator == 10)) { //Zero Flag is still set!
        clockcycles += 13;
        *accumulator = 0x04;
        *registerY = 0x14;
        clockcycles += initSoundEffectShared();
        clockcycles += soundEffectSlot1_rotateTetriminoPlaying();
    }
    else {
        clockcycles += 7;
    }

    return clockcycles;
}

int soundEffectSlot1_rotateTetriminoPlaying() {
    int clockcycles = 6;
    clockcycles += advanceAudioSlotFrame();
    if (*accumulator == 0) {
        clockcycles += 11;
        *accumulator = *soundEffectSlot1SecondaryCounter;
        (*soundEffectSlot1SecondaryCounter)++;
        switch (*accumulator) {
        case 0: *registerY = 0x18; clockcycles += copyToSq1Channel(); clockcycles += 4; break;
        case 1: *registerY = 0x14; clockcycles += copyToSq1Channel(); clockcycles += 8; break;
        case 2: *registerY = 0x18; clockcycles += copyToSq1Channel(); clockcycles += 12; break;
        case 3: clockcycles += soundEffectSlot1Playing_stop(); clockcycles += 16; break;
        default: return clockcycles + 6;
        }
    }
    else {
        clockcycles += 1;
    }

    return clockcycles;
}

int soundEffectSlot1Playing_stop() {
   setpulse(0x10);
    *musicChanInhibit = 0;
    *soundEffectSlot1Playing = 0;
    (*resetSq12ForMusic)++;
    return 27;
}

int soundEffectSlot1_shiftTetriminoInit() {
    int clockcycles = 6;
    clockcycles += LE33B();
    if (!(*accumulator == 4 || *accumulator == 6 || *accumulator == 9 || *accumulator == 10)) { //Zero Flag is still set!
        clockcycles += 7;
        *accumulator = 0x02;
        *registerY = 0x44;
        clockcycles += initSoundEffectShared();
    }
    else {
        clockcycles += 7;
    }
    return clockcycles;
}

int soundEffectSlot1_lockTetriminoInit() {
    int clockcycles = 6;
    clockcycles += LE33B();
    if (!(*accumulator == 4 || *accumulator == 6 || *accumulator == 9 || *accumulator == 10)) { //Zero Flag is still set!
        clockcycles += 7;
        *accumulator = 0x0F;
        *registerY = 0x20;
        clockcycles += initSoundEffectShared();
    }
    else {
        clockcycles += 7;
    }
    return clockcycles;
}

int soundEffectSlot0_makesNoSound() {
    //printf("soundEffectSlot0_makesNoSound\r\n");
    int clockcycles = 7;
    *accumulator = 10;
    *registerY = 0;
    clockcycles += initSoundEffectShared();
    return clockcycles;
}

int initSoundEffectShared() {
    int clockcycles = 18;
    *registerX = *currentSoundEffectSlot;
    soundEffectSlot0FrameCount[*registerX] = *accumulator;
    addressSpace[0x06C7 + *registerX] = *registerX;
    if (*registerY != 0) {
        switch (*registerX) {
            case 1: copyToSq1Channel(); clockcycles += 1; break;
            case 2: copyToSq2Channel(); clockcycles += 5; break;
            case 3: copyToTriChannel(); clockcycles += 9; break;
            case 0: copyToNoiseChannel(); clockcycles += 13; break;
            default: return clockcycles + 6;
        }
    }
    else {
        clockcycles += 1;
    }
    clockcycles += 43;
    soundEffectSlot0Playing[*registerX] = *currentAudioSlot;
    soundEffectSlot0FrameCounter[*registerX] = 0;
    soundEffectSlot0SecondaryCounter[*registerX] = 0;
    soundEffectSlot0TertiaryCounter[*registerX] = 0;
    soundEffectSlot0Tmp[*registerX] = 0;
    *resetSq12ForMusic = 0;
    return clockcycles + 6;
}

int soundEffectSlot1_menuOptionSelectPlaying() {
    int clockcycles = 6;
    clockcycles += advanceAudioSlotFrame();
    if (*accumulator == 0) {
        clockcycles += 12;
        (*soundEffectSlot1SecondaryCounter)++;
        if (*soundEffectSlot1SecondaryCounter == 2) {
            clockcycles += 6;
            *registerY = 0x2B;
            clockcycles += copyToSq1Channel();
        }
        else {
            clockcycles += 21;
            *channel1DisableFlag = true;
            *musicChanInhibit = 0;
            *soundEffectSlot1Playing = 0;
            (*resetSq12ForMusic)++;
        }
    }
    else {
        clockcycles += 1;
    }

    return clockcycles + 6;
}

int soundEffectSlot1_chirpChirpPlaying() {
    int clockcycles = 5;
    if (*soundEffectSlot1TertiaryCounter != 0) {
        (*soundEffectSlot1SecondaryCounter)++;
        if (*soundEffectSlot1SecondaryCounter == 0x16) {
            clockcycles += 17;
            *channel1DisableFlag = true;
            *musicChanInhibit = 0;
            *soundEffectSlot1Playing = 0;
        }
        else {
            clockcycles += 1;
        }
    }
    else {
        clockcycles += 28;
        *registerY = *soundEffectSlot1SecondaryCounter & 3;
        setpulse(soundEffectSlot1_chirpChirpSq1Vol_table[*registerY]);
        (*soundEffectSlot1SecondaryCounter)++;
        if (*soundEffectSlot1SecondaryCounter == 8) {
            clockcycles += 8;
            (*soundEffectSlot1TertiaryCounter)++;
            *registerY = 0x40;
            clockcycles += copyToSq1Channel();
        }
        else {
            clockcycles += 1;
        }
    }
    return clockcycles + 6;
}

int updateAudio_pause() {
    int clockcycles = 5;
    if (*audioInitialized != 0) {
        clockcycles += 5;
        if (*musicPauseSoundEffectLengthCounter != 0x12) {
            clockcycles += 7;
            if (((*musicPauseSoundEffectLengthCounter) & 3) == 3) {
                clockcycles += 14;
                (*musicPauseSoundEffectCounter)++;
                *registerY = 0x10;
                *accumulator = (*musicPauseSoundEffectCounter) & 1;
                if (*accumulator == 0) {
                    clockcycles += 8;
                    *registerY = 0x0C;
                }
                else {
                    clockcycles += 1;
                }
                clockcycles += copyToSq1Channel();
            }
            else {
                clockcycles += 6;
                (*musicPauseSoundEffectLengthCounter)++;
            }
        }
        else {
            clockcycles += 1;
        }
    }else{
        clockcycles += 12;
        (*audioInitialized)++;
        clockcycles += muteAudio();
        *musicPauseSoundEffectLengthCounter = 0;
    }
    return clockcycles + 6;
}

int copyToSq1Channel() {
    int clockcycles = 5;
    clockcycles = 18;
    *AUDIOTMP3 = *registerY;
    *AUDIOTMP4 = 0xE1;
    *registerY = 0;

    uint8_t temp;
    
    //0x4000
    temp = addressSpace[*((uint16_t*)AUDIOTMP3) + *registerY];
    setpulse(temp);
    (*registerY)++;
    clockcycles += 19;

    //0x4001
    temp = addressSpace[*((uint16_t*)AUDIOTMP3) + *registerY];
    setsweep(temp);
    (*registerY)++;
    clockcycles += 19;

    //0x4002
    temp = addressSpace[*((uint16_t*)AUDIOTMP3) + *registerY];
    *pulse1SeqReload = (*pulse1SeqReload & 0xFF00) | temp;
    (*registerY)++; 
    clockcycles += 19;

    //0x4003
    temp = addressSpace[*((uint16_t*)AUDIOTMP3) + *registerY];
    setpulseSequence(temp);
    (*registerY)++;
    clockcycles += 19;

    return clockcycles + 5;
}

void setpulse(uint8_t value) {//4000
    switch ((value & 0xC0) >> 6)
    {
        case 0x00: *channel1Sequence = 0b01000000; *pulse1OscDutycycle = 0.125; break;
        case 0x01: *channel1Sequence = 0b01100000; *pulse1OscDutycycle = 0.250; break;
        case 0x02: *channel1Sequence = 0b01111000; *pulse1OscDutycycle = 0.500; break;
        case 0x03: *channel1Sequence = 0b10011111; *pulse1OscDutycycle = 0.750; break;
    }
    *pulse1Sequence = *channel1Sequence;
    *pulse1Halt = (value & 0x20);
    *channel1Volume = (value & 0x0F);
    *channel1DisableFlag = (value & 0x10);
}

void setsweep(uint8_t value) {//4001
    *pulse1SweepEnabled = value & 0x80;
    *pulse1SweepPeriod = (value & 0x70) >> 4;
    *pulse1SweepDown = value & 0x08;
    *pulse1SweepShift = value & 0x07;
    *pulse1SweepReload = true;
}

void setsweep2(uint8_t value) {//4005
    *pulse2SweepEnabled = value & 0x80;
    *pulse2SweepPeriod = (value & 0x70) >> 4;
    *pulse2SweepDown = value & 0x08;
    *pulse2SweepShift = value & 0x07;
    *pulse2SweepReload = true;
}

void setpulseSequence(uint8_t value) {//4003
    *pulse1SeqReload = (uint16_t)((value & 0x07)) << 8 | (*pulse1SeqReload & 0x00FF);
    *pulse1SeqTimer =  *pulse1SeqReload;
    *pulse1Sequence = *channel1Sequence;
    *pulse1Counter = length_table[(value & 0xF8) >> 3];
    *pulse1Start = true;
}

void setpulseSequence2(uint8_t value) {//4007
    *pulse2SeqReload = (uint16_t)((value & 0x07)) << 8 | (*pulse2SeqReload & 0x00FF);
    *pulse2SeqTimer = *pulse2SeqReload;
    *pulse2Sequence = *channel2Sequence;
    *pulse2Counter = length_table[(value & 0xF8) >> 3];
    *pulse2Start = true;
}

int copyToTriChannel(){// does nothing; never called???
    //printf("Tri\r\n"); 
    int clockcycles = 5;
    clockcycles += 18;
    *AUDIOTMP3 = *registerY;
    *AUDIOTMP4 = 0xE1;
    *registerY = 0;
    do {
        (*registerY)++;
        clockcycles += 19;
    } while (*registerY != 4);
    return clockcycles + 5;
}

int copyToNoiseChannel() {
    int clockcycles = 5;
    clockcycles += 18;
    *AUDIOTMP3 = *registerY;
    *AUDIOTMP4 = 0xE1;
    *registerY = 0;

    uint8_t temp; 
    temp = addressSpace[*((uint16_t*)AUDIOTMP3) + *registerY];
    
    *noiseVolume = temp & 0x0F;
    *noiseDisableFlag = temp & 0x10;
    *noiseHaltFlag = temp & 0x20;
    (*registerY)++;
    clockcycles += 19;

    (*registerY)++;//write to 400D does nothing 
    clockcycles += 19;

    temp = addressSpace[*((uint16_t*)AUDIOTMP3) + *registerY];
    setNoiseReload(temp);
    (*registerY)++;
    clockcycles += 19;

    temp = addressSpace[*((uint16_t*)AUDIOTMP3) + *registerY];
    setLengthCouter(temp);
    (*registerY)++;
    clockcycles += 19;

    return clockcycles + 6;
}

void setLengthCouter(uint8_t value) {
    *pulse1Start = true;
    *pulse2Start = true;
    *noiseStart = true;
    *noiseCounter = length_table[(value & 0xF8) >> 3];
}

int copyToSq2Channel() {// does nothing; never called???
    //printf("Sq2\r\n");
    int clockcycles = 2;
    clockcycles += 18;
    *AUDIOTMP3 = *registerY;
    *AUDIOTMP4 = 0xE1;
    *registerY = 0;
    do {
        (*registerY)++;
        clockcycles += 19;
    } while (*registerY != 4);
    return clockcycles;
}

int LE33B() {
    int clockcycles = 7;
    *accumulator = *soundEffectSlot1Playing;
    switch (*accumulator) {
        case 4: clockcycles += 1; break;
        case 6: clockcycles += 5; break;
        case 9: clockcycles += 9; break;
        case 10: clockcycles += 13; break;
        default: clockcycles += 12; break;
    }
    return clockcycles + 6;
}

int updateSoundEffectSlot0_apu() {
    int clockcycles = 6;
    clockcycles += advanceAudioSlotFrame();
    clockcycles += 2;
    if (*accumulator == 0) {
    
    }
    else {
        clockcycles += 9;
        *registerX = 0x54;
        clockcycles += loadNoiseLo();
        clockcycles += 8;
        *registerX = 0x74;
        clockcycles += getSoundEffectNoiseNibble();
        //upper 4 bit of the return value will be 0
        clockcycles += 11;
        *noiseVolume = *accumulator & 0x0F; 
        *noiseDisableFlag = true;
        (*soundEffectSlot0SecondaryCounter)++;
    }
    return clockcycles + 6;
}

int loadNoiseLo() {
    int clockcycles = 6;
    clockcycles += getSoundEffectNoiseNibble();
    clockcycles += 10;
    setNoiseReload(*accumulator);
    return clockcycles + 6;
}

void setNoiseReload(uint8_t value) {
    switch (value & 0x0F)
    {
    case 0x00: *noiseReload = 0; break;
    case 0x01: *noiseReload = 4; break;
    case 0x02: *noiseReload = 8; break;
    case 0x03: *noiseReload = 16; break;
    case 0x04: *noiseReload = 32; break;
    case 0x05: *noiseReload = 64; break;
    case 0x06: *noiseReload = 96; break;
    case 0x07: *noiseReload = 128; break;
    case 0x08: *noiseReload = 160; break;
    case 0x09: *noiseReload = 202; break;
    case 0x0A: *noiseReload = 254; break;
    case 0x0B: *noiseReload = 380; break;
    case 0x0C: *noiseReload = 508; break;
    case 0x0D: *noiseReload = 1016; break;
    case 0x0E: *noiseReload = 2034; break;
    case 0x0F: *noiseReload = 4068; break;
    }
};

int getSoundEffectNoiseNibble() {
    int clockcycles = 22;
    *AUDIOTMP1 = *registerX;
    *AUDIOTMP2 = 0xE1;
    *registerY = *soundEffectSlot0SecondaryCounter >> 1;
    *AUDIOTMP5 = addressSpace[*((uint16_t *)AUDIOTMP1) + *registerY];
    if (((*soundEffectSlot0SecondaryCounter) & 1) != 0) {
        clockcycles += 5;
        *accumulator = *AUDIOTMP5 & 0x0F;
    }
    else {
        clockcycles += 11;
        *accumulator = *AUDIOTMP5 >> 4;
    }

    return clockcycles + 6;
}

int initAudioAndMarkInited() {
    //printf("initAudioAndMarkInited\r\n");
    int clockcycles = 11;
    (*audioInitialized)++;
    clockcycles += muteAudio();
    musicPauseSoundEffectLengthCounter = 0;
    return clockcycles + 6;
}

int playState_player2ControlsActiveTetrimino() {
    int clockcycles = 18;
    clockcycles += shift_tetrimino();
    clockcycles += rotate_tetrimino();
    clockcycles += drop_tetrimino();
    return clockcycles + 6;
}

int gameModeState_checkForResetKeyCombo() {
    int clockcycles = 7;
    *accumulator = *heldButtons_player1;
    if (*heldButtons_player1 != 0xF0) {
        clockcycles += 5;
        (*gameModeState)++;
    }
    else {
        clockcycles += 7;
        clockcycles += updateAudio2();
        *accumulator = 0;
        *gameMode = 0;
    }
    return clockcycles + 6;
}

int copyOamStagingToOam() {
    *oam_addr = 0;
    *oamdma = 2;
    *oamaddr = 0;
    *dmatransfer = true;
    return 18;
}

int render() {
    int clockcycles = 9;
    clockcycles += switch_s_plus_2a();
    switch (*renderMode) {
        case 0: clockcycles += render_mode_legal_and_title_screens(); break;
        case 1: clockcycles += render_mode_menu_screens(); break;
        case 2: clockcycles += render_mode_congratulations_screen(); break;
        case 3: clockcycles += render_mode_play_and_demo(); break;
        case 4: clockcycles += render_mode_ending_animation(); break;
        default: printf("Switch Currupted!\r\n");
    }
    return clockcycles;
}

int switch_s_plus_2a() { //invalid offsets etc. are not considered here! doesn't emulate the exact behavior
    return 45;
}

int setMMC1Control() {
    //can be ignored Mapper is hardcoded; mapping never changes
    return 24; // how long do writes to MMC1_Control take?
}
int changeCHRBank0(){
    //can be ignored Mapper is hardcoded; mapping never changes
    //broke somehow I now have to do something?
    *CHRBank0 = *accumulator;
    return 24; // how long do writes to MMC1_Control take?
}
int changeCHRBank1() {
    //can be ignored Mapper is hardcoded; mapping never changes
    //broke somehow I now have to do something?
    *CHRBank1 = *accumulator;
    return 24; // how long do writes to MMC1_Control take?
}
int changePRGBank() {
    //can be ignored Mapper is hardcoded; mapping never changes
    return 24; // how long do writes to MMC1_Control take?
}

int initRamContinued() {
    int clockcycles = 12;
    *tmp1 = 0;
    *tmp2 = 0;
    *accumulator = 0;
    clockcycles += 16907;
    memset(addressSpace + 0x100, 0, 0x600);
    clockcycles += 8;
    bool coldBoot_h = false;
    if (initMagic[0] == 0x12) {
        clockcycles += 8;
        if (initMagic[1] == 0x34) {
            clockcycles += 8;
            if (initMagic[2] == 0x56) {
                clockcycles += 8;
                if (initMagic[3] == 0x78) {
                    clockcycles += 8;
                    if (initMagic[4] == 0x9A) {
                        clockcycles += 6;
                        //warmBoot
                    }
                    else {
                        clockcycles += 1;
                        coldBoot_h = true;
                    }
                }
                else {
                    clockcycles += 1;
                    coldBoot_h = true;
                }
            }
            else {
                clockcycles += 1;
                coldBoot_h = true;
            }
        }
        else {
            clockcycles += 1;
            coldBoot_h = true;
        }
    }
    else {
        clockcycles += 1;
        coldBoot_h = true;
    }
    if (coldBoot_h == true) {
        *registerX = 0;
        clockcycles += 2;
        while (defaultHighScoresTable[*registerX] != 0xFF) {
            clockcycles += 24;
            highScoreNames[*registerX] = defaultHighScoresTable[*registerX];
            (*registerX)++;
        }
        clockcycles += 10;
        initMagic[0] = 0x12;
        initMagic[1] = 0x34;
        initMagic[2] = 0x56;
        initMagic[3] = 0x78;
        initMagic[4] = 0x9A;
        clockcycles += 30;
    }
    clockcycles += 10;
    rng_seed[0] = 0x89;
    rng_seed[1] = 0x88;
    *registerY = 0;
    return clockcycles;
}

int initRAM2(int (*endFrame)()) {
    int clockcycles = 14;
    clockcycles += 16;
    *ppuScrollX = 0;
    *ppuScrollY = 0;
    *fine_x = 0;
    *accumulator = 0x90;
    *currentPpuCtrl = *accumulator;
    *PPUControlRegister = *accumulator;
    tram_addr[0] = 0;
    vram_addr[0] = 0;
    *PPUMASK = 0x06;
    clockcycles += 6;
    //clockcycles += LE006();
    clockcycles += updateAudio2();
    clockcycles += 24;
    stack[0] = 0xC0;
    stack[1] = 0x80;
    stack[3] = 0x35;
    stack[4] = 0xAC;
    clockcycles += 6;
    clockcycles += updateAudioWaitForNmiAndDisablePpuRendering(endFrame);
    clockcycles += 6;
    clockcycles += disableNmi();
    clockcycles += 8;
    *accumulator = 0x20;
    clockcycles = LAA82();
    *accumulator = 0x24;
    clockcycles = LAA82();
    *accumulator = 0x28;
    clockcycles = LAA82();
    *accumulator = 0x2c;
    clockcycles = LAA82();

    clockcycles += 12;
    *accumulator = 0xEF;
    *registerX = 0x04;
    *registerY = 0x05;
    clockcycles += memset_page();

    clockcycles += 6;
    clockcycles += waitForVBlankAndEnableNmi(endFrame);
    clockcycles += 6;
    clockcycles += updateAudioWaitForNmiAndResetOamStaging(endFrame);
    clockcycles += 6;
    clockcycles += updateAudioWaitForNmiAndEnablePpuRendering(endFrame);
    clockcycles += 6;
    clockcycles += updateAudioWaitForNmiAndResetOamStaging(endFrame);

    clockcycles += 23;
    addressSpace[0x34] = 0x0E;
    *gameModeState = 0;
    *gameMode = 0;
    *numberOfPlayers = 1;
    frameCounter[1] = 0;
    return clockcycles;
}

int updateAudioWaitForNmiAndEnablePpuRendering(int (*endFrame)()) {
    int clockcycles = 0; //jsr happens before NMI
    clockcycles += updateAudioAndWaitForNmi(endFrame);
    clockcycles += 29;

    *fine_x = 0;
    *tram_addr = 0x0000;

    *PPUControlRegister = *currentPpuCtrl;

    clockcycles += 7;
    *accumulator = *currentPpuMask | 0x1E;
    if (accumulator == 0 ) {
        clockcycles += waitForVBlankAndEnableNmi(endFrame); //incorrect cyclecounting
        return clockcycles;
    }
    else {
        clockcycles += 12;
        *PPUMASK = *accumulator;
        return clockcycles + 6;
    }
}

int counter = 0;

int waitForVBlankAndEnableNmi(int (*endFrame)()) {// only cycles after NMI
    //printf("Enable the NMI %i\r\n", counter);
    int clockcycles = 16;
    if (counter > 6) {
        endFrame(); //doesn't end the frame? Because of timing within the vblank?
    }
    counter++;
    if (*currentPpuCtrl == *currentPpuCtrl | 0x80) {
        clockcycles += disableNmi();
        return clockcycles;
    }
    else {
        clockcycles += 8;
        *currentPpuCtrl = *currentPpuCtrl | 0x80;
        *PPUControlRegister = *currentPpuCtrl;
    }
    
    return clockcycles + 6;
}

int updateAudioAndWaitForNmi(int (*endFrame)()) {// only cycles after NMI
    //updateAudioJMP();
    //printf("Ending the Frame !\r\n");
    endFrame();
    return 12; //depends on the exakt cycle the nmi happens
}

int updateAudioWaitForNmiAndDisablePpuRendering(int (*endFrame)()) {// only cycles after NMI
    int clockcycles = updateAudioAndWaitForNmi(endFrame);
    clockcycles += 12;
    //*currentPpuMask &= 0xE1;
    //*PPUMASK = *currentPpuMask;
    return clockcycles + 6;
}

int NMI(){
    /*if (((int)addressSpace[0x17] == 5 && (int)addressSpace[0x18] == 0x35) || ((int)addressSpace[0x17] == 2 && (int)addressSpace[0x18] == 0xA9)) {
        printf("Frame %02x%02x\r\n", addressSpace[0xB2], addressSpace[0xB1]);
        printf("RNG: %X %X \r\n", (int)addressSpace[0x17], (int)addressSpace[0x18]);
    }*/
    int clockcycles = 24;
    *oamStagingLength = 0;
    clockcycles += render();
    clockcycles += 12;
    (*sleepCounter)--;
    if (*sleepCounter == 0xFF) {
        clockcycles += 5;
        (*sleepCounter)++;
    }
    else {
        clockcycles += 1;
    }
    clockcycles += 6;
    clockcycles += copyOamStagingToOam();
    clockcycles += 28;
    if (frameCounter[0] == 0xFF) {
        frameCounter[1]++;
    }
    (*frameCounter)++;
    clockcycles += generateNextPseudorandomNumber();
    clockcycles += 25;
    *ppuScrollX = 0;
    *ppuScrollY = 0;
    *verticalBlankingInterval = 1;
    clockcycles += pollControllerButtons();
    clockcycles += 13;
    return clockcycles + 6;
}

int pollControllerButtons() {
    int clockcycles = 7;
    if (*gameMode != 5) {
        clockcycles += 6;
        clockcycles += pollController();
    }
    else {
        clockcycles += 7;
        if (addressSpace[0xD0] != 0xFF) {
            clockcycles += 6;
            clockcycles += pollController();
            clockcycles += 7;
            if (*newlyPressedButtons_player1 != 0x10) {
                clockcycles += 5;
                if (*demo_repeats != 0) {
                    clockcycles += 13;
                    (*demo_repeats)--;
                    *newlyPressedButtons_player1 = 0;
                }
                else {
                    clockcycles += 18;
                    *generalCounter = addressSpace[*((uint16_t* )demoButtonsAddr)];
                    clockcycles += demoButtonsTable_indexIncr();
                    clockcycles += 35;
                    *newlyPressedButtons_player1 = (*demo_heldButtons ^ *generalCounter) & *generalCounter;
                    *demo_heldButtons = *generalCounter;
                    *demo_repeats = addressSpace[*((uint16_t*)demoButtonsAddr)];
                    clockcycles += demoButtonsTable_indexIncr();
                    clockcycles += 5;
                    if (demoButtonsAddr[1] == 0xDF) {
                        *newlyPressedButtons_player1 = 0;
                    }
                    else {
                        clockcycles += 1;
                    }
                }
            }
            else {
                clockcycles += 15;
                demoButtonsAddr[1] = 0xDE; 
                frameCounter[1] = 0;
                *gameMode = 1;
            }
        }
        else {
            printf("Record DEMO???");
            clockcycles += 7;
            clockcycles += pollController();
            clockcycles += 7;
            if (*gameMode != 5) {
                clockcycles += 7;
                if(addressSpace[0xD0] != 0xFF) {
                    clockcycles += 8;
                    if (*heldButtons_player1 != *demo_heldButtons) {
                        clockcycles += 14;
                        addressSpace[*((uint16_t*)demoButtonsAddr)] = *demo_heldButtons;
                        clockcycles += demoButtonsTable_indexIncr();
                        clockcycles += 14;
                        addressSpace[*((uint16_t*)demoButtonsAddr)] = *demo_repeats;
                        clockcycles += demoButtonsTable_indexIncr();
                        clockcycles += 5;
                        if (demoButtonsAddr[1] == 0xDF) {
                            addressSpace[0xD0] = 0x00;//record Mode
                            *demo_repeats = 0;
                        }
                        else {
                            clockcycles += 1;
                        }
                    }
                    else {
                        clockcycles += 6;
                        (*demo_repeats)++;
                    }
                }
                else {
                    clockcycles += 1;
                }
            }
            else {
                clockcycles += 1;
            }
        }
        clockcycles += 6;
        *heldButtons_player1 = *demo_heldButtons;
    }
    return clockcycles + 6;
}

int pollController() {
    //controller reads are alway the same!
    int clockcycles = 12;
    clockcycles += pollController_actualRead();
    clockcycles += addExpansionPortInputAsControllerInput();
    clockcycles += 12;
    *generalCounter2 = *newlyPressedButtons_player1;
    *generalCounter3 = *newlyPressedButtons_player2;
    clockcycles += 12;
    clockcycles += pollController_actualRead();
    clockcycles += addExpansionPortInputAsControllerInput();
    clockcycles += 20;
    *newlyPressedButtons_player1 &= *generalCounter2;
    *newlyPressedButtons_player2 &= *generalCounter3;
    for (int i = 0; i < 2; i++) {
        uint8_t temp = newlyPressedButtons_player1[i];
        newlyPressedButtons_player1[i] &= newlyPressedButtons_player1[i] ^ heldButtons_player1[i];
        heldButtons_player1[i] = temp;
    }
    return clockcycles + 5;
}

int addExpansionPortInputAsControllerInput() {
    *newlyPressedButtons_player1 = *newlyPressedButtons_player1 | *tmp1;
    *newlyPressedButtons_player2 = *newlyPressedButtons_player2 | *tmp2;
    return 24;
}

int pollController_actualRead() {
    //internalState of the controller read is not emulated
    //printf("controller Read\r\n");
    int clockcycles = 17;
    *registerX = 8;
    do{
        clockcycles += 48;
        (*registerX)--;
    } while (*registerX != 0);
    *newlyPressedButtons_player1 = *controller1;
    *newlyPressedButtons_player2 = *controller2;
    *tmp1 = 0; //no extension pack???
    *tmp2 = 0; //no extension pack???
    return clockcycles + 5;
}

int updateAudio2() {
    return soundEffectSlot2_makesNoSound() + 3;
}

int soundEffectSlot2_makesNoSound() {
    int clockcycles = 24;
    musicChanInhibit[0] = 0;
    musicChanInhibit[1] = 0;
    musicChanInhibit[2] = 0;
    *musicStagingNoiseLo = 0;
    *resetSq12ForMusic = 0;
    for (uint8_t i = 0; i != 6; i++) {
        soundEffectSlot0Playing[i] = 0;
        clockcycles += 15;
    }
    clockcycles += 5;
    clockcycles += muteAudioAndClearTriControl();
    return clockcycles;
}

int muteAudioAndClearTriControl() {
    int clockcycles = 6;
    clockcycles += muteAudio();
    clockcycles += 10;
    musicChanControl[2] = 0;
    return clockcycles + 6;
}

int muteAudio() {
    //writes to 0x4011/DMC_RAW and 0x4008/TRI_LINEAR are discarded in the emulator
    *channel1DisableFlag = true;
    *channel2DisableFlag = true;
    *noiseDisableFlag = true;
    *channel1Volume = 0;
    *channel2Volume = 0;
    *noiseVolume = 0;
    return 31;
}

int render_mode_ending_animation() {
    int clockcycles = 31;
    *PPUADDR = 0x20 << 8;
    *PPUADDR |= 0x8E;
    if (modification == SEVENDIGITS) {
        *PPUADDR = 0x20 << 8;
        *PPUADDR |= 0x8D;
        baseAddressTBL[*PPUADDR & 0x3FF] = addressSpace[0x0F];
        (*PPUADDR)++;
        clockcycles += 7;
    }
    *accumulator = player1_score[2];
    clockcycles += twoDigsToPPU();
    *accumulator = player1_score[1];
    clockcycles += twoDigsToPPU();
    *accumulator = player1_score[0];
    clockcycles += twoDigsToPPU();
    if (*gameType != 0) {
        clockcycles += 19;
        *PPUADDR = 0x20 << 8;
        *PPUADDR |= 0xB0;
        *accumulator = *generalCounter4;
        clockcycles += twoDigsToPPU();
        clockcycles += 19;
        *PPUADDR = 0x20 << 8;
        *PPUADDR |= 0xD0;
        *accumulator = *generalCounter5;
        clockcycles += twoDigsToPPU();
        clockcycles += 19;
        *PPUADDR = 0x21 << 8;
        *PPUADDR |= 0x2E;
        *accumulator = addressSpace[0xDE];
        clockcycles += twoDigsToPPU();
        clockcycles += 9;
        *accumulator = addressSpace[0xDD];
        clockcycles += twoDigsToPPU();
        clockcycles += 9;
        *accumulator = addressSpace[0xDC];
        clockcycles += twoDigsToPPU();
    }
    else {
        clockcycles += 1;
    }
    clockcycles += 8;//PPUSCROLL register is not used here
    return clockcycles + 6;
}

int render_mode_play_and_demo() {
    int clockcycles = 7;
    if (*player1_playState == 4) {
        clockcycles += 49;
        *(playfieldAddr + 1) = 4;
        *rowY = *player1_rowY;
        completedRow[0] = player1_completedRow[0];
        completedRow[1] = player1_completedRow[1];
        completedRow[2] = player1_completedRow[2];
        completedRow[3] = player1_completedRow[3];
        *playState = *player1_playState;
        clockcycles += updateLineClearingAnimation();
        *player1_rowY = *rowY;
        *player1_playState = *playState;
        *player1_vramRow = 0;
        clockcycles += 20;
    }
    else {
        clockcycles += 12;
        *(playfieldAddr + 1) = 4;
        *vramRow = *player1_vramRow;
        clockcycles += 24;
        clockcycles += copyPlayfieldRowToVRAM();
        clockcycles += copyPlayfieldRowToVRAM();
        clockcycles += copyPlayfieldRowToVRAM();
        clockcycles += copyPlayfieldRowToVRAM();
        *player1_vramRow = *vramRow;
    }
    clockcycles += 7;
    if (*numberOfPlayers == 2) {
        clockcycles += 7;
        if (*player2_playState == 4) {
            clockcycles += 49;
            *(playfieldAddr + 1) = 5;
            *rowY = *player2_rowY;
            completedRow[0] = player2_completedRow[0];
            completedRow[1] = player2_completedRow[1];
            completedRow[2] = player2_completedRow[2];
            completedRow[3] = player2_completedRow[3];
            *playState = *player2_playState;
            clockcycles += updateLineClearingAnimation();
            *player2_rowY = *rowY;
            *player2_playState = *playState;
            *player2_vramRow = 0;
            clockcycles += 20;
        }
        else {
            clockcycles += 12;
            *(playfieldAddr + 1) = 5;
            *rowY = *player2_rowY;
            clockcycles += 24;
            clockcycles += copyPlayfieldRowToVRAM();
            clockcycles += copyPlayfieldRowToVRAM();
            clockcycles += copyPlayfieldRowToVRAM();
            clockcycles += copyPlayfieldRowToVRAM();
            *player2_vramRow = *vramRow;
        }
    }
    else {
        clockcycles += 1;
    }
    clockcycles += 7;
    if ((*outOfDateRenderFlags & 1) != 0) {
        clockcycles += 7;
        if (*numberOfPlayers != 2) {
            clockcycles += 29;
            if ((fixes & 4) == 4) {
                clockcycles += 31;
                *PPUADDR = 0x20 << 8;
                *PPUADDR |= 0x6C;
                baseAddressTBL[*PPUADDR & 0x3FF] = 21;
                (*PPUADDR)++;
                baseAddressTBL[*PPUADDR & 0x3FF] = 18;
                (*PPUADDR)++;
                baseAddressTBL[*PPUADDR & 0x3FF] = 23;
                (*PPUADDR)++;
                baseAddressTBL[*PPUADDR & 0x3FF] = 14;
                (*PPUADDR)++;
                baseAddressTBL[*PPUADDR & 0x3FF] = 28;
                (*PPUADDR)++;
                baseAddressTBL[*PPUADDR & 0x3FF] = 36;
                (*PPUADDR)++;
                baseAddressTBL[*PPUADDR & 0x3FF] = *(player1_lines + 1) / 10;
                (*PPUADDR)++;
                baseAddressTBL[*PPUADDR & 0x3FF] = *(player1_lines + 1) % 10;
                (*PPUADDR)++;
                *accumulator = *player1_lines;
                clockcycles += twoDigsToPPU();
                clockcycles += 8;
            }
            else {
                *PPUADDR = 0x20 << 8;
                *PPUADDR |= 0x73;
                baseAddressTBL[*PPUADDR & 0x3FF] = *(player1_lines + 1);
                (*PPUADDR)++;
                *accumulator = *player1_lines;
                clockcycles += twoDigsToPPU();
                clockcycles += 8;
            }
            *outOfDateRenderFlags = *outOfDateRenderFlags & 0xFE;
        }
        else {
            clockcycles += 25;
            *PPUADDR = 0x20 << 8;
            *PPUADDR |= 0x68;
            baseAddressTBL[*PPUADDR & 0x3FF] = *(player1_lines + 1);
            (*PPUADDR)++;
            *accumulator = *player1_lines;
            clockcycles += twoDigsToPPU();
            clockcycles += 29;
            *PPUADDR = 0x20 << 8;
            *PPUADDR |= 0x7A;
            baseAddressTBL[*PPUADDR & 0x3FF] = *(player2_lines + 1);
            (*PPUADDR)++;
            *accumulator = *player2_lines;
            clockcycles += twoDigsToPPU();
            clockcycles += 8;
            *outOfDateRenderFlags = *outOfDateRenderFlags & 0xFE;
        }
    }
    else {
        clockcycles += 1;
    }

    clockcycles += 7;
    if ((*outOfDateRenderFlags & 2) != 0) {
        clockcycles += 7;
        if (*numberOfPlayers != 2) {
            if ((fixes & 2) == 0) {
                clockcycles += 31;
                *generalCounter = levelDisplayTable[*player1_levelNumber];
                *PPUADDR = 0x22 << 8;
                *PPUADDR |= 0xBA;
                *accumulator = *generalCounter;
                clockcycles += twoDigsToPPU();
            }
            else {
                clockcycles += 31;
                *generalCounter = levelDisplayTable[*player1_levelNumber];
                *PPUADDR = 0x22 << 8;
                *PPUADDR |= 0xB9;
                baseAddressTBL[*PPUADDR & 0x3FF] = *player1_levelNumber / 100;
                (*PPUADDR)++;
                baseAddressTBL[*PPUADDR & 0x3FF] = (*player1_levelNumber % 100 / 10);
                (*PPUADDR)++;
                baseAddressTBL[*PPUADDR & 0x3FF] = *player1_levelNumber % 10;
                (*PPUADDR)++;
            }
            clockcycles += updatePaletteForLevel();
            clockcycles += 8;
            *outOfDateRenderFlags = *outOfDateRenderFlags & 0xFD;
        }
        else {
            clockcycles += 1;
        }
    }
    else {
        clockcycles += 1;
    }
    clockcycles += 7;
    if ( *numberOfPlayers != 2) {
        clockcycles += 7;
        if ((*outOfDateRenderFlags & 4) != 0 ){
            clockcycles += 28;
            *PPUADDR = 0x21 << 8;
            *PPUADDR |= 0x18;

            if (modification == SEVENDIGITS) {
                baseAddressTBL[*PPUADDR & 0x3FF] = addressSpace[0x0F];
                (*PPUADDR)++;
                clockcycles += 7;
            }

            *accumulator = player1_score[2];
            clockcycles += twoDigsToPPU();
            *accumulator = player1_score[1];
            clockcycles += twoDigsToPPU();
            *accumulator = player1_score[0];
            clockcycles += twoDigsToPPU();
            clockcycles += 8;
            *outOfDateRenderFlags = *outOfDateRenderFlags & 0xFB;
        }
        else {
            clockcycles += 1;
        }
    }
    else {
        clockcycles += 1;
    }

    clockcycles += 7;
    if (*numberOfPlayers != 2) {
        clockcycles += 7;
        if ((*outOfDateRenderFlags & 0x40) != 0) {
            clockcycles += 5;
            *tmpCurrentPiece = 0;
            do{
                clockcycles += 38;
                *registerX = *tmpCurrentPiece << 1;
                *PPUADDR = pieceToPpuStatAddr[*registerX] << 8;
                *PPUADDR |= pieceToPpuStatAddr[*registerX + 1];
                if ((fixes & 1) == 0) {
                    baseAddressTBL[*PPUADDR & 0x3FF] = statsByType[*registerX + 1];
                    (*PPUADDR)++;
                }
                else {
                    baseAddressTBL[*PPUADDR & 0x3FF] = statsByType[*registerX + 1] / 10;
                    (*PPUADDR)++;
                    baseAddressTBL[*PPUADDR & 0x3FF] = statsByType[*registerX + 1] % 10;
                    (*PPUADDR)++;
                }
                *accumulator = statsByType[*registerX];
                clockcycles += twoDigsToPPU();
                clockcycles += 12;
                (*tmpCurrentPiece)++;
            }while (*tmpCurrentPiece != 7);

            clockcycles += 7;
            *outOfDateRenderFlags = *outOfDateRenderFlags & 0xBF;
        }
        else {
            clockcycles += 1;
        }
    }
    else {
        clockcycles += 1;
    }
    clockcycles += 28;
    *PPUADDR = 0x3F << 8;
    *PPUADDR |= 0x0E;
    *registerX = 0x00;
    if (*completedLines == 4) {
        clockcycles += 7;
        if ((*frameCounter & 3) == 0) {
            clockcycles += 9;
            *registerX = 0x30;
            if ((*frameCounter & 7) == 0) {
                clockcycles += 5;
                *soundEffectSlot1Init = 9;
            }
            else {
                clockcycles += 1;
            }
        }
        else {
            clockcycles += 1;
        }
    }
    else {
        clockcycles += 1;
    }


    clockcycles += 19;
    tablePalette[0x0E] = *registerX;
    (*PPUADDR)++;
    *ppuScrollX = 0;
    *ppuScrollY = 0;
    return clockcycles + 6;
}

int savePlayer2State() {
    int clockcycles = 2;
    *registerX = 0x1F;
    do {
        clockcycles += 15;
        player1_tetriminoX[*registerX] = tetriminoX[*registerX];
        (*registerX)--;
    } while (*registerX != 0xFF);
    clockcycles += 11;
    uint8_t temp = *pendingGarbage;
    *pendingGarbage = *pendingGarbageInactivePlayer;
    *pendingGarbageInactivePlayer = temp;
    return clockcycles + 6;
}

int savePlayer1State() {
    int clockcycles = 2;
    *registerX = 0x1F;
    do {
        clockcycles += 15;
        player1_tetriminoX[*registerX] = tetriminoX[*registerX];
        (*registerX)--;
    } while (*registerX != 0xFF);
    clockcycles += 6;
    if (*numberOfPlayers != 1) {
        clockcycles += 12;
        uint8_t temp = *pendingGarbage;
        *pendingGarbage = *pendingGarbageInactivePlayer;
        *pendingGarbageInactivePlayer = temp;
    }
    else {
        clockcycles += 1;
    }
    return clockcycles + 6;
}

int gameMode_levelMenu_handleLevelHeightNavigation() {
    int clockcycles = 7;
    if (*newlyPressedButtons == 1) {
        clockcycles += 10;
        *soundEffectSlot1Init = 1;
        if (*selectingLevelOrHeight == 0) {
            clockcycles += 7;
            if (*startLevel != 9) {
                clockcycles += 8;
                (*startLevel)++;
            }
            else {
                clockcycles += 1;
            }
        }
        else {
            clockcycles += 8;
            if (*startHeight != 5) {
                clockcycles += 8;
                (*startHeight)++;
            }
            else {
                clockcycles += 1;
            }
        }
    }
    else {
        clockcycles += 1;
    }
    clockcycles += 7;
    if (*newlyPressedButtons == 2) {
        clockcycles += 10;
        *soundEffectSlot1Init = 1;
        if (*selectingLevelOrHeight == 0) {
            clockcycles += 5;
            if (*startLevel != 0) {
                clockcycles += 5;
                (*startLevel)--;
            }
            else {
                clockcycles += 1;
            }
        }
        else {
            clockcycles += 8;
            if (*startHeight != 0) {
                clockcycles += 5;
                (*startHeight)--;
            }
            else {
                clockcycles += 1;
            }
        }
    }
    else {
        clockcycles += 1;
    }

    clockcycles += 7;
    if (*newlyPressedButtons == 4) {
        clockcycles += 10;
        *soundEffectSlot1Init = 1;
        if (*selectingLevelOrHeight == 0) {
            clockcycles += 5;
            if (*startLevel < 5) {
                clockcycles += 10;
                *startLevel += 5;
            }
            else {
                clockcycles += 1;
            }
        }
        else {
            clockcycles += 8;
            if (*startHeight < 3) {
                clockcycles += 15;
                *startHeight += 3;
            }
            else {
                clockcycles += 1;
            }
        }
    }
    else {
        clockcycles += 1;
    }
    clockcycles += 7;
    if (*newlyPressedButtons == 8) {
        clockcycles += 10;
        *soundEffectSlot1Init = 1;
        if (*selectingLevelOrHeight == 0) {
            clockcycles += 5;
            if (*startLevel >= 5) {
                clockcycles += 10;
                *startLevel -= 5;
            }
            else {
                clockcycles += 1;
            }
        }
        else {
            clockcycles += 8;
            if (*startHeight >= 3) {
                clockcycles += 15;
                *startHeight -= 3;
            }
            else {
                clockcycles += 1;
            }
        }
    }
    else {
        clockcycles += 1;
    }
    clockcycles += 5;
    if (*gameType != 0) {
        if (*newlyPressedButtons == 0x80) {
            clockcycles += 13;
            *soundEffectSlot1Init = 1;
            *selectingLevelOrHeight = *selectingLevelOrHeight ^ 1;
        }
        else {
            clockcycles += 1;
        }
    }
    else {
        clockcycles += 1;
    }
    if (*selectingLevelOrHeight == 0) {
        clockcycles += 7;
        if ((*frameCounter & 3) != 0) {
            clockcycles += 32;
            *spriteYOffset = levelToSpriteYOffset[*startLevel];
            *spriteIndexInOamContentLookup = 0;
            *spriteXOffset = levelToSpriteXOffset[*startLevel];
            if (*activePlayer == 1) {
                clockcycles += 10;
                *spriteYOffset += 0x50;
            }
            else {
                clockcycles += 1;
            }
            clockcycles += 6;
            clockcycles += loadSpriteIntoOamStaging();
        }
        else {
            clockcycles += 1;
        }
    }
    else {
        clockcycles += 33;
        *spriteYOffset = levelToSpriteYOffset[*startLevel];
        *spriteIndexInOamContentLookup = 0;
        *spriteXOffset = levelToSpriteXOffset[*startLevel];
        if (*activePlayer == 1) {
            clockcycles += 10;
            *spriteYOffset += 0x50;
        }
        else {
            clockcycles += 1;
        }
        clockcycles += 6;
        clockcycles += loadSpriteIntoOamStaging();
    }
    clockcycles += 5;
    if (*gameType != 0) {
        clockcycles += 5;
        if (*selectingLevelOrHeight != 0) {
            clockcycles += 7;
            if ((*frameCounter & 3) == 0) {
                return clockcycles + 7;
            }
        }
        else {
            clockcycles += 1;
        }
        clockcycles += 32;
        *spriteXOffset = heightToPpuHighAddr[*startHeight];
        *spriteIndexInOamContentLookup = 0;
        *spriteYOffset = heightToPpuLowAddr[*startHeight];
        if (*activePlayer == 1) {
            clockcycles += 10;
            *spriteYOffset += 0x50;
        }
        else {
            clockcycles += 1;
        }
        clockcycles += 6;
        clockcycles += loadSpriteIntoOamStaging();
    }
    else {
        clockcycles += 1;
    }
    return clockcycles + 6;
}

int render_mode_menu_screens() {
    *currentPpuCtrl = *currentPpuCtrl & 0xFC;
    *ppuScrollX = 0;
    *ppuScrollY = 0;
    return 28;
}

int render_mode_legal_and_title_screens() {
    *currentPpuCtrl = *currentPpuCtrl & 0xFC;
    *ppuScrollX = 0;
    *ppuScrollY = 0;
    return 28;
}

int selectEndingScreen() {
    int clockcycles = 12;
    *ending = 0;
    if (player1_score[2] >= 5) {
        clockcycles += 13;
        *ending = 1;
        if (player1_score[2] >= 7) {
            clockcycles += 13;
            *ending = 2;
            if (player1_score[2] >= 0x10) {
                clockcycles += 13;
                *ending = 3;
                if (player1_score[2] >= 0x12) {
                    clockcycles += 18;
                    *ending = 4;
                    *patchToPpuAddr = 0xCC;
                    *(patchToPpuAddr + 1) = 0xA8;
                    clockcycles += patchToPpu();
                }
                else {
                    clockcycles += 1;
                }
            }
            else {
                clockcycles += 1;
            }
        }
        else {
            clockcycles += 1;
        }
    }
    else {
        clockcycles += 1;
    }



    *ending_customVars = LAA2A[*ending];
    *(ending_customVars + 1) = 0;
    return clockcycles + 20;
}

int marioLuigiPeach() {
    int clockcycles = 28;
    *spriteXOffset = 0xC8;
    *spriteYOffset = 0x47;
    *spriteIndexInOamContentLookup = ((*frameCounter & 0x08) >> 3) + 0x21;
    clockcycles += loadSpriteIntoOamStaging();
    clockcycles += 34;
    *spriteXOffset = 0xA0;
    *spriteYOffset = 0x27;
    *spriteIndexInOamContentLookup = 0x27;
    *registerX = (*frameCounter & 18) >> 3;
    *spriteYOffset = marioFrameToYOffsetTable[*registerX];
    if (*spriteYOffset != 0x97) {
        clockcycles += 5;
        *spriteIndexInOamContentLookup = 0x28;
    }
    else {
        clockcycles += 1;
    }
    clockcycles += 6;
    clockcycles += loadSpriteIntoOamStaging();
    while (true) {
        clockcycles += 18;
        *spriteXOffset = 0xC0;
        *registerX = *ending >> 3;
        if (*registerX == 0x0A) {
            clockcycles += 11;
            *ending = 0;
            (*ending_customVars)++;
        }
        else {
            clockcycles += 1;
            break;
        }
    }
    clockcycles += 22;
    *spriteYOffset = luigiFrameToYOffsetTable[*registerX];
    *spriteIndexInOamContentLookup = luigiFrameToSpriteTable[*registerX];
    clockcycles += loadSpriteIntoOamStaging();
    (*ending)++;
    clockcycles += bowser();
    return clockcycles;
}

int bowser() {
    int clockcycles = 36;
    *spriteXOffset = 0x30;
    *spriteYOffset = 0xA7;
    *spriteIndexInOamContentLookup = ((*frameCounter & 0x10) >> 4) + 0x1F;
    clockcycles += loadSpriteIntoOamStaging();
    clockcycles += donkeyKong();
    return clockcycles;
}

int donkeyKong() {
    int clockcycles = 36;
    *spriteXOffset = 0x40;
    *spriteYOffset = 0x77;
    *spriteIndexInOamContentLookup = ((*frameCounter & 0x10) >> 4) + 0x1D;
    clockcycles += loadSpriteIntoOamStaging();
    clockcycles += samus();
    return clockcycles;
}

int samus() {
    int clockcycles = 36;
    *spriteXOffset = 0xA8;
    *spriteYOffset = 0xD7;
    *spriteIndexInOamContentLookup = ((*frameCounter & 0x10) >> 4) + 0x1A;
    clockcycles += loadSpriteIntoOamStaging();
    clockcycles += link();
    return clockcycles;
}

int link() {
    int clockcycles = 36;
    *spriteXOffset = 0xC8;
    *spriteYOffset = 0xD7;
    *spriteIndexInOamContentLookup = ((*frameCounter & 0x10) >> 4) + 0x18;
    clockcycles += loadSpriteIntoOamStaging();
    clockcycles += kidIcarus();
    return clockcycles;
}

int kidIcarus() {
    int clockcycles = 42;
    *spriteXOffset = 0x28;
    *spriteYOffset = 0x77;
    *spriteIndexInOamContentLookup = ((*frameCounter & 0x10) >> 4) + 0x16;
    clockcycles += loadSpriteIntoOamStaging();
    clockcycles += LA6BC();
    return clockcycles + 6;
}

int LA6BC() {//needs more testing
    int clockcycles = 2;
    *registerX = 0;
    do {
        clockcycles += 8;
        if (LA735[*registerX] == *ending_customVars) {
            if (ending_customVars[*registerX + 3] != 0) {
                clockcycles += 13;
                ending_customVars[*registerX + 3]--;
                (*ending_customVars)++;
            }
            else {
                clockcycles += 1;
            }
        }
        else {
            clockcycles += 1;
        }
        (*registerX)++;
    } while (*registerX != 4);
    clockcycles += 5;
    *ending_currentSprite = 0;
    do {
        clockcycles += 9;
        if (ending_customVars[*ending_currentSprite + 3] != 0) {
            clockcycles += 9;
            *generalCounter = ending_customVars[*ending_currentSprite + 3];
            if (*generalCounter != LA73D[*ending_currentSprite]) {
                clockcycles += 17;
                *soundEffectSlot0Init = 3;
                (*generalCounter)--;
                if (*generalCounter >= 0xA0) {
                    clockcycles += 5;
                    (*generalCounter)--;
                }
                else {
                    clockcycles += 1;
                }
            }
            else {
                clockcycles += 1;
            }
            clockcycles += 30;
            ending_customVars[*ending_currentSprite + 3] = *generalCounter;
            *spriteYOffset = *generalCounter;
            *spriteXOffset = domeNumberToXOffsetTable[*ending_currentSprite];
            *spriteIndexInOamContentLookup = domeNumberToXSpriteTable[*ending_currentSprite];
            clockcycles += loadSpriteIntoOamStaging();
            clockcycles += 18;
            *generalCounter = ending_customVars[*ending_currentSprite + 3];
            if (*generalCounter != LA73D[*ending_currentSprite]) {
                clockcycles += 26;
                *spriteXOffset += LA745[*ending_currentSprite];
                *spriteIndexInOamContentLookup = ((*frameCounter & 2) > 1) + 0x51;
                clockcycles += loadSpriteIntoOamStaging();
            }
            else {
                clockcycles += 1;
            }
        }
        else {
            clockcycles += 1;
        }
        clockcycles += 13;
        (*ending_currentSprite)++;
    } while (*ending_currentSprite != 4);
  
    return clockcycles + 5;
}

int patchToPpu() {
    int clockcycles = 2;
    *registerY = 0;
    bool skiploading_h = false;
    while (true) {
        if (skiploading_h == false) {
            clockcycles += 20;
            *PPUADDR = baseAddressROM[(*(patchToPpuAddr + 1) << 8) + *patchToPpuAddr + *registerY - 0x8000] << 8;
            (*registerY)++;
            *PPUADDR |= baseAddressROM[(*(patchToPpuAddr + 1) << 8) + *patchToPpuAddr + *registerY - 0x8000];
            (*registerY)++;
        }
        clockcycles += 11;
        *accumulator = baseAddressROM[(*(patchToPpuAddr + 1) << 8) + *patchToPpuAddr + *registerY - 0x8000];
        (*registerY)++;
        if (*accumulator != 0xFE) {
            clockcycles += 4;
            if (*accumulator == 0xFD) {
                clockcycles += 1;
                break;
            }
            else {
                clockcycles += 6;
                baseAddressTBL[*PPUADDR & 0x3FF] = *accumulator;
                (*PPUADDR)++;
                skiploading_h = true;
            }

        }
        else {
            clockcycles += 1;
            skiploading_h = false;
        }
    }
    return clockcycles + 6;
}

int musicGetNextInstructionByte() {
    *accumulator = baseAddressROM[(*(musicChanTmpAddr+1) << 8) + *musicChanTmpAddr + musicDataChanInstructionOffset[*registerX] - 0x8000];
    musicDataChanInstructionOffset[*registerX]++;
    return 23;
}

int advanceAudioSlotFrame() {
    int clockcycles = 19;
    soundEffectSlot0FrameCounter[*currentSoundEffectSlot] += 1;
    *accumulator = soundEffectSlot0FrameCounter[*currentSoundEffectSlot];
    if (*accumulator == soundEffectSlot0FrameCount[*currentSoundEffectSlot]) {
        soundEffectSlot0FrameCounter[*currentSoundEffectSlot] = 0;
        *accumulator = 0;
        clockcycles += 6;
    }
    else {
        clockcycles += 1;
    }
    return clockcycles + 6;
}

int memset_page() {//needs more testing
    //could use memset
    //printf("memset a: %i x: %i y: %i\r\n",*accumulator, *registerX, *registerY);
    int clockcycles = 24;
    //accumulator is pushed and popped from the stack; not implemented here
    uint8_t temp = *accumulator;
    *tmp2 = *registerY;
    *registerX = *registerX - *tmp2 - 1;
    *tmp1 = 0;
    *registerY = 0;
    do{
        clockcycles += 10;
        addressSpace[(*tmp2 << 8) + *tmp1 + *registerY] = temp;
        (*registerY)--;
        if (*registerY == 0) {
            clockcycles += 9;
            (*tmp2)--;
            (*registerX)++;
            if (*registerX == 0) {
                break;
            }
            else {
                clockcycles += 1;
            }
        }
        else {
            clockcycles += 1;
        }

    }while (true);
    return clockcycles + 5;
}

int loadSpriteIntoOamStaging() {
    int clockcycles = 30;
    *registerX = *spriteIndexInOamContentLookup << 1;
    *generalCounter = oamContentLookup[*registerX];
    (*registerX)++;
    *generalCounter2 = oamContentLookup[*registerX];
    *registerX = *oamStagingLength;
    *registerY = 0;
    while (true) {
        clockcycles += 10;
        *accumulator = baseAddressROM[(*generalCounter2 << 8) + *generalCounter + *registerY - 0x8000];
        if (*accumulator == 0xFF) {
            break;
        }
        clockcycles += 73;
        oamStaging[*registerX] = *accumulator + *spriteYOffset;
        (*registerX)++;
        (*registerY)++;
        oamStaging[*registerX] = baseAddressROM[(*generalCounter2 << 8) + *generalCounter + *registerY - 0x8000];
        (*registerX)++;
        (*registerY)++;
        oamStaging[*registerX] = baseAddressROM[(*generalCounter2 << 8) + *generalCounter + *registerY - 0x8000];
        (*registerX)++;
        (*registerY)++;
        oamStaging[*registerX] = baseAddressROM[(*generalCounter2 << 8) + *generalCounter + *registerY - 0x8000] + *spriteXOffset;
        (*registerX)++;
        (*registerY)++;
        *oamStagingLength += 4;
    }
    return clockcycles + 6;
}

int ending_typeBCathedralSetSprite() {
    int clockcycles = 17;
    (*ending)++;
    if (ending_typeBCathedralAnimSpeed[*levelNumber] == *ending) {
        clockcycles += 13;
        *ending_customVars ^= 1;
        *ending = 0;
    }
    else {
        clockcycles += 1;
    }
    clockcycles += 12;
    *spriteIndexInOamContentLookup = ending_typeBCathedralSpriteTable[*levelNumber] + *ending_customVars;
    return clockcycles + 6;
}

int render_mode_congratulations_screen() {
    int clockcycles = 7;
    if ((*outOfDateRenderFlags & 0x80) != 0) {
        clockcycles += 62;
        *registerX = (*highScoreEntryRawPos & 3) << 1;
        *PPUADDR = highScorePpuAddrTable[*registerX] << 8;
        *registerX = ((*highScoreEntryRawPos & 3) << 1) + 1;
        *generalCounter = highScorePpuAddrTable[*registerX];
        *PPUADDR |= *generalCounter + *highScoreEntryNameOffsetForLetter;
        baseAddressTBL[*PPUADDR & 0x3FF] = highScoreCharToTile[*highScoreEntryCurrentLetter];
        *ppuScrollX = 0;
        *fine_x = 0;
        *tram_addr &= 0x07FF;
        *ppuScrollX = 0;
        *tram_addr &= 0xF83F;
        *tram_addr &= 0xF83F;
        *tram_addr &= 0xFFF1;
        *outOfDateRenderFlags = 0;
    }
    else {
        clockcycles += 1;
    }
    return clockcycles + 6;
}

int updateLineClearingAnimation() {
    int clockcycles = 7;
    if ((*frameCounter & 3) == 0) {
        *generalCounter3 = 0;
        do {
            clockcycles += 9;
            *accumulator = completedRow[*generalCounter3];
            if (*accumulator != 0) {
                clockcycles += 18;
                *registerY = *accumulator << 1;
                *generalCounter = vramPlayfieldRows[*registerY];
                if (*numberOfPlayers == 1) {
                    clockcycles += 13;
                    *generalCounter = *generalCounter + 6;
                }
                else {
                    clockcycles += 9;
                    if (*(playfieldAddr + 1) == 4) {
                        clockcycles += 13;
                        *generalCounter = *generalCounter - 2;
                    }
                    else {
                        clockcycles += 11;
                        *generalCounter = *generalCounter + 12;
                    }
                }
                clockcycles += 61;
                (*registerY)++;
                *generalCounter2 = vramPlayfieldRows[*registerY];
                *PPUADDR = vramPlayfieldRows[*registerY] << 8;
                *PPUADDR |= *generalCounter + leftColumns[*rowY];
                baseAddressTBL[*PPUADDR & 0x3FF] = 0xFF;
                *PPUADDR = *generalCounter2 << 8;
                *PPUADDR |= *generalCounter + rightColumns[*rowY];
                baseAddressTBL[*PPUADDR & 0x3FF] = 0xFF;
            }
            else {
                clockcycles += 1;
            }
            (*generalCounter3)++;
        } while (*generalCounter3 < 4);
        clockcycles += 8;
        (*rowY)++;
        if (*rowY >= 5) {
            clockcycles += 5;
            (*playState)++;
        }
        else {
            clockcycles += 1;
        }
        
    }
    else {
        clockcycles += 1;
    }
    return clockcycles + 6;
}

int copyPlayfieldRowToVRAM() {
    int clockcycles = 7;
    if (*vramRow < 21) {
        *registerX = *vramRow;
        clockcycles += 33;
        *registerY = multBy10Table[*registerX];
        *registerX = (*registerX << 1) + 1;
        *PPUADDR = vramPlayfieldRows[*registerX] << 8;
        (*registerX)--;
        if (*numberOfPlayers != 1) {
            clockcycles += 5;
            if ((*playfieldAddr+1) != 5) {
                clockcycles += 14;
                *PPUADDR = *PPUADDR | (vramPlayfieldRows[*registerX] - 2);
            }
            else {
                clockcycles += 15;
                *PPUADDR = *PPUADDR | (vramPlayfieldRows[*registerX] + 12);
            }
        }
        else {
            clockcycles += 12;
            *PPUADDR = *PPUADDR | (vramPlayfieldRows[*registerX] + 6);
        }
        clockcycles += 2;
        for (uint8_t i = 0; i < 10;i++) {
            clockcycles += 15;
            baseAddressTBL[*PPUADDR & 0x3FF] = addressSpace[*((uint16_t*)playfieldAddr) + *registerY];
            (*PPUADDR)++;
            (*registerY)++;
        }
        clockcycles += 11;
        (*vramRow)++;
        if (*vramRow >= 20) {
            *vramRow = 32;
        }
        else {
            clockcycles += 1;
        }
    }
    else
    {
        clockcycles += 1;
    }
    return clockcycles + 6;
}

int twoDigsToPPU() {
    *generalCounter = *accumulator;//!!!
    //*accumulator = *accumulator & 0xF0;
    baseAddressTBL[*PPUADDR & 0x3FF] = *accumulator >> 4; //expects one screen mirroring
    (*PPUADDR)++;
    baseAddressTBL[*PPUADDR & 0x3FF] = *accumulator & 0x0F;
    (*PPUADDR)++;
    return 32;
}

int updatePaletteForLevel() {
    int clockcycles = 3;
    *accumulator = *player1_levelNumber;
    while ((int8_t)(*accumulator - 10) >= 0) {//values over 128 are considered negative
        clockcycles += 11;
        *accumulator -= 10;
    }
    clockcycles += 12;
    *registerX = *accumulator << 2;
    *generalCounter = 0;
    do {
        *PPUADDR = 0x3F00;
        *PPUADDR += *generalCounter + 8;
        tablePalette[*generalCounter + 8] = colorTable[*registerX];
        tablePalette[*generalCounter + 9] = colorTable[*registerX + 1];
        tablePalette[*generalCounter + 10] = colorTable[*registerX + 2];
        tablePalette[*generalCounter + 11] = colorTable[*registerX + 3];
        *PPUADDR += 4;//next index
        *generalCounter += 16;
        clockcycles += 63;
    } while (*generalCounter != 32);
    return clockcycles + 5;//last jump did not happen
}

int initPlayfieldIfTypeB(int(*endFrame)()){
    int clockcycles = 5;
    if(*gameType == 0){
        *accumulator = 0;
        return clockcycles + 9;
    }else{
        clockcycles += 6;
        for(*generalCounter = 12;*generalCounter>0;(*generalCounter)--){
            clockcycles += 5;
            if(*generalCounter == 0){
                clockcycles += 1;
                break;
            }else{
                clockcycles += 23;
                *generalCounter2 = 20 - *generalCounter;
                *player1_vramRow = 0;
                *player2_vramRow = 0;
                *generalCounter3 = 9;
                do{
                    clockcycles += 10;
                    clockcycles += generateNextPseudorandomNumber();
                    clockcycles += 42;
                    *registerY = rng_seed[0] & 7;
                    *generalCounter4 = rngTable[*registerY];
                    *registerX = *generalCounter2;
                    *registerY = multBy10Table[*registerX]+*generalCounter3;
                    playfield[*registerY] = *generalCounter4;
                    (*generalCounter3)--;
                }while((int8_t)*generalCounter3 >= 0);
                clockcycles += 1;//exiting the loop
                do{
                    clockcycles += 10;
                    clockcycles += generateNextPseudorandomNumber();
                    clockcycles += 10;
                }while((int8_t)(rng_seed[0] & (uint8_t)0x0F) >= 10);//signed numbers! bpl is used! shouldn't make a difference because of the AND
                clockcycles += 29;
                *generalCounter5 = rng_seed[0] & 0x0F;
                *registerX = *generalCounter2;
                *registerY = multBy10Table[*registerX]+*generalCounter5;
                playfield[*registerY] = 0xEF;
                clockcycles += updateAudioWaitForNmiAndResetOamStaging(endFrame); // not yet implemented
            }
        }
        for(int i=200;i>0;i--){//it starts with 200; offset 0 is not copied!
            clockcycles += 13;
            playfieldForSecondPlayer[i] = playfield[i];
        }

        clockcycles += 10;
        for(*registerY = typeBBlankInitCountByHeightTable[*player1_startHeight]; *registerY > 0 ;(*registerY)--){
            playfield[*registerY] = 0xEF;
            clockcycles += 11;
        }
        playfield[*registerY] = 0xEF;
        clockcycles += 11;
        clockcycles += -1;//last jump does not happen
        //below here the register have be set so they are correct after the return!
        clockcycles += 9;
        *registerX = *player2_startHeight;
        for(*registerY = typeBBlankInitCountByHeightTable[*registerX]; *registerY > 0;(*registerY)--){
            playfieldForSecondPlayer[*registerY] = 0xEF;
            clockcycles += 11;
        }
        playfieldForSecondPlayer[*registerY] = 0xEF;
        clockcycles += 11;
        clockcycles += -1;//last jump does not happen
    }
    return clockcycles + 6;
}

int copyHighScoreLevelToNextIndex() {
    int clockcycles = 7;
    *registerX = *accumulator;
    if (*gameType != 0) {
        clockcycles += 8;
        *registerX += 4;
    }
    else {
        clockcycles += 1;
    }
    highScoreLevels[*registerX + 1] = highScoreLevels[*registerX];
    return clockcycles + 16;
}

int copyHighScoreScoreToNextIndex() {
    int clockcycles = 7;
    *registerX = *accumulator;
    if (*gameType != 0) {
        clockcycles += 8;
        *registerX += 12;
    }
    else {
        clockcycles += 1;
    }
    highScoreScoresA[*registerX + 3] = highScoreScoresA[*registerX];
    (*registerX)++;
    highScoreScoresA[*registerX + 3] = highScoreScoresA[*registerX];
    (*registerX)++;
    highScoreScoresA[*registerX + 3] = highScoreScoresA[*registerX];
    return clockcycles + 40;
}

int copyHighScoreNameToNextIndex() {
    int clockcycles = 7;
    *generalCounter = *accumulator;
    if (*gameType != 0) {
        clockcycles += 10;
        *generalCounter += 24;
    }
    else {
        clockcycles += 1;
    }
    clockcycles += 5;
    *generalCounter2 = 5;
    do {
        clockcycles += 44;
        *generalCounter3 = highScoreNames[*generalCounter + *generalCounter2];
        highScoreNames[*generalCounter + *generalCounter2 + 6] = *generalCounter3;
        (*generalCounter2)--;
    } while (*generalCounter2 != 255);
    *accumulator = *generalCounter2;
    return clockcycles += 5;

}

int playState_noop() {
    return 6;
}

int playState_incrementPlayState() {
    (*playState)++;
    return 11;
}

int playState_unassignOrientationId() {
    *currentPiece = 19;
    return 11;
}

int gameModeState_vblankThenRunState2() {
    int clockcycles = 11;
    *gameModeState = 2;
    *accumulator = 2;
    clockcycles += noop_disabledVramRowIncr();
    return clockcycles + 6;
}

int noop_disabledVramRowIncr() {
    return 6; //instant return statement
}

int stageSpriteForNextPiece() {
    int clockcycles = 5;
    if (*displayNextPiece == 0) {
        clockcycles += 56;
        *spriteXOffset = 0xC8;
        *spriteYOffset = 0x77;
        *spriteIndexInOamContentLookup = orientationToSpriteTable[*nextPiece];
        *registerX = *spriteIndexInOamContentLookup * 2;
        *generalCounter = oamContentLookup[*registerX];
        (*registerX)++;
        *generalCounter2 = oamContentLookup[*registerX];
        *registerX = *oamStagingLength;
        *registerY = 0;
        do{
            clockcycles += 9;
            //in ROM
            *accumulator = baseAddressROM[(*generalCounter2 << 8) + *generalCounter + *registerY - 0x8000];
            if (*accumulator != 0xFF) {
                clockcycles += 74;
                oamStaging[*registerX] = *accumulator + *spriteYOffset;
                (*registerX)++;
                (*registerY)++;
                oamStaging[*registerX] = baseAddressROM[(*generalCounter2 << 8) + *generalCounter + *registerY - 0x8000];
                (*registerX)++;
                (*registerY)++;
                oamStaging[*registerX] = baseAddressROM[(*generalCounter2 << 8) + *generalCounter + *registerY - 0x8000];
                (*registerX)++;
                (*registerY)++;
                oamStaging[*registerX] = baseAddressROM[(*generalCounter2 << 8) + *generalCounter + *registerY - 0x8000] + *spriteXOffset;
                (*registerX)++;
                (*registerY)++;
                *oamStagingLength += 4;
            }
            else {
                clockcycles += 1;
                break;
            }
        }while (true);
    }
    else {
        clockcycles += 1;
    }
    return clockcycles + 6;
}

int stageSpriteForCurrentPiece() {
    int clockcycles = 17;
    *generalCounter3 = (*tetriminoX << 3) + 0x60;
    if (*numberOfPlayers  != 1) {
        clockcycles += 16;
        *generalCounter3 -= 0x40;
        if (*activePlayer != 1) {
            clockcycles += 8;
            if (*activePlayer == 0) {//carry flag set
                *generalCounter3 += 0x70;
            }
            else {
                *generalCounter3 += 0x6F;
            }
        }
        else {
            clockcycles += 1;
        }
    }
    else {
        clockcycles += 1;
    }
    clockcycles += 49;
    *generalCounter4 = *tetriminoY * 8 + 0x2F;
    *generalCounter5 = *currentPiece;
    *generalCounter = *generalCounter5 * 4;
    *registerX = *generalCounter * 2  + *generalCounter;
    *registerY = *oamStagingLength;
    *generalCounter2 = 4;
    do {
        clockcycles += 59;
        *originalY = (orientationTable[*registerX] * 8) + *generalCounter4;
        oamStaging[*registerY] = *originalY;
        (*oamStagingLength)++;
        (*registerY)++;
        (*registerX)++;
        oamStaging[*registerY] = orientationTable[*registerX];
        (*oamStagingLength)++;
        (*registerY)++;
        (*registerX)++;
        oamStaging[*registerY] = 0x2;
        if (*originalY < 0x2F) {
            clockcycles += 28;
            (*oamStagingLength)++;
            (*registerY)--;
            oamStaging[*registerY] = 0xFF;
            *registerY += 2;
            oamStaging[*registerY] = 0;
        }
        else {
            clockcycles += 29;
            (*oamStagingLength)++;
            (*registerY)++;
            oamStaging[*registerY] = (orientationTable[*registerX] << 3) + *generalCounter3;
        }
        clockcycles += 16;
        (*oamStagingLength)++;
        (*registerY)++;
        (*registerX)++;
        (*generalCounter2)--;
    } while (*generalCounter2 != 0);
    return clockcycles + 5;
}

int makePlayer1Active() {
    int clockcycles = 24;
    *activePlayer = 1;
    *(playfieldAddr + 1) = 4;
    *newlyPressedButtons = *newlyPressedButtons_player1;
    *heldButtons = *heldButtons_player1;
    int8_t x = 31;
    do{
        tetriminoX[x] = player1_tetriminoX[x];
        x--;
        clockcycles += 14;
    }while(x >= 0);
    return clockcycles + 7;
}

int makePlayer2Active() {
    int clockcycles = 24;
    *activePlayer = 2;
    *(playfieldAddr + 1) = 5;
    *newlyPressedButtons = *newlyPressedButtons_player2;
    *heldButtons = *heldButtons_player2;
    int8_t x = 31;
    do {
        tetriminoX[x] = player2_tetriminoX[x];
        x--;
        clockcycles += 14;
    } while (x >= 0);
    return clockcycles + 7;
}

int startButtonPressed() {
    *soundEffectSlot1Init = 2;
    (*gameMode)++;
    //*accumulator = *gameMode;
    return 17;
}

int timeout() {
    *soundEffectSlot1Init = 2;
    *gameMode = 6;
    //*accumulator = *gameMode;
    return 17;
}

int playState_lockTetrimino() {
    int clockcycles = 6;
    clockcycles += isPositionValid();
    clockcycles += 2;
    if (*accumulator == 0) {
        clockcycles += 8;
        if (*vramRow >= 20) {
            *generalCounter = *tetriminoY << 1;
            *generalCounter = *generalCounter + *tetriminoX + (*generalCounter << 2);
            *generalCounter2 = *currentPiece << 2;
            uint8_t x = *generalCounter2 + (*generalCounter2 << 1);
            uint8_t y = 0;
            *generalCounter3 = 4;
            clockcycles += 49;
            do {
                *generalCounter4 = orientationTable[x] << 1;
                *selectingLevelOrHeight = *generalCounter4 + (*generalCounter4 << 2) + *generalCounter;
                x++;
                *generalCounter5 = orientationTable[x];
                x++;
                y = orientationTable[x] + *selectingLevelOrHeight;
                addressSpace[*((uint16_t*)playfieldAddr) + y] = *generalCounter5;
                x++;
                (*generalCounter3)--;
                clockcycles += 66;
            } while (*generalCounter3 > 0);
            *lineIndex = 0;
            clockcycles += 10; //last jump doesnt happen !
            clockcycles += updatePlayfield();
            clockcycles += updateMusicSpeed();
            clockcycles += 11;
            (*playState)++;
        }
        else {
            return clockcycles += 7;
        }
    }
    else {
        end = clock();
        //printf("Playing Movie took: %llu ms\r\n", (uint64_t)(end - start));
        //print_playfield();
        *soundEffectSlot0Init = 2;
        *playState = 10;
        *curtainRow = 0xF0;
        clockcycles += updateAudio2();
        clockcycles += 22;
    }
    return clockcycles + 6;
}

int demoButtonsTable_indexIncr() {
    if (*demoButtonsAddr == 255) {
        (*(demoButtonsAddr + 1))++;
    }
    (*demoButtonsAddr)++;
    return 22;
}

int playState_playerControlsActiveTetrimino() {
    int clockcycles = 6;
    clockcycles += shift_tetrimino();
    clockcycles += 6;
    clockcycles += rotate_tetrimino();
    clockcycles += 6;
    clockcycles += drop_tetrimino();
    return clockcycles + 6;
}

bool firstTime = false;

int chooseNextTetrimino() {
    //printf("Next\r\nFrame: %i %i \r\n", (int)addressSpace[0xB1], (int)addressSpace[0xB2]);
    //printf("RNG: %X %X \r\n", (int)addressSpace[0x17], (int)addressSpace[0x18]);
    /*if (firstTime == false) {
        firstTime = true;
        addressSpace[0x17] = 0x05;
        addressSpace[0x18] = 0x35;
    }*/
    int clockcycles = 7;
    if (*gameMode == 5) {
        clockcycles += 28;
        *accumulator = demoTetriminoTypeTable[*demoIndex];
        (*demoIndex)++;
        *accumulator = *accumulator >> 4;
        *accumulator = *accumulator & 7;
        *accumulator = spawnTable[*accumulator];
        return clockcycles + 6;
    }
    else {
        clockcycles += 9;
        clockcycles += realStart();
        return clockcycles + 6;
    }
    return clockcycles + 6;
}

int playState_spawnNextTetrimino() {
    int clockcycles = 7;
    bool spawnPiece_h = false;
    if (*vramRow >= 20) {
        clockcycles += 7;
        if (*numberOfPlayers != 1) {
            clockcycles += 7;
            if (*twoPlayerPieceDelayCounter == 0) {
                (*twoPlayerPieceDelayCounter)++;
                *twoPlayerPieceDelayPiece = *activePlayer;
                clockcycles += 12;
                clockcycles += chooseNextTetrimino();
                clockcycles += 6;
            }
            else {
                clockcycles += 7;
                if (*twoPlayerPieceDelayPlayer == *activePlayer) {
                    //return
                }
                else {
                    clockcycles += 1;
                    if (*twoPlayerPieceDelayCounter == 0x1C) {
                        //return
                    }
                    else {
                        clockcycles += 1;
                        spawnPiece_h = true;
                    }
                }
            }
        }
        else {
            clockcycles += 1;
            spawnPiece_h = true;
        }
    }
    else {
        clockcycles += 1;
    }
    if (spawnPiece_h == true) {
        *twoPlayerPieceDelayCounter = 0;
        *fallTimer = 0;
        *tetriminoY = 0;
        *playState = 1;
        *tetriminoX = 5;
        *currentPiece = spawnOrientationFromOrientation[*nextPiece];
        clockcycles += 31;
        *accumulator = *currentPiece;
        clockcycles += incrementPieceStat();
        clockcycles += 7;
        if (*numberOfPlayers != 1) {
            *nextPiece = *twoPlayerPieceDelayPiece;
            clockcycles += 9;
        }
        else {
            clockcycles += 7;
            clockcycles += chooseNextTetrimino();
            *nextPiece = *accumulator;
            clockcycles += 3;
        }
        *autorepeatY = 0;
        clockcycles += 5;
    }
    return clockcycles + 5;
}

int realStart() {
    int clockcycles = 19;
    (*spawnCount)++;
    *accumulator = (uint8_t)((uint8_t)(rng_seed[0] + *spawnCount) & 7);
    bool invalidIndex_h = false;
    if (*accumulator != 7) {
        clockcycles += 10;
        if (spawnTable[*accumulator] == *spawnID) {
            invalidIndex_h = true;
        }
        else {
            clockcycles += 4;
            *spawnID = spawnTable[*accumulator];
        }
    }
    else {
        clockcycles += 1;
        invalidIndex_h = true;
    }
    if (invalidIndex_h == true) {
        clockcycles += 10;
        clockcycles += generateNextPseudorandomNumber();
        *accumulator = (rng_seed[0] & 7) + *spawnID;
        while (true) {
            clockcycles += 4;
            if (*accumulator >= 7) {
                clockcycles += 7;
                *accumulator -= 7;
            }
            else {
                clockcycles += 1;
                break;
            }
        }
        *spawnID = spawnTable[*accumulator];
        clockcycles += 9;
    }
    *accumulator = *spawnID;
    return clockcycles + 6;
}

int generateNextPseudorandomNumber() {
    int clockcycles = 0;
    *tmp1 = rng_seed[0] & 2;
    uint8_t a = (rng_seed[1] & (uint8_t)2) ^ *tmp1;
    clockcycles += 22;
    uint8_t carry;
    if (a != 0) {
        carry = 1;
        clockcycles += 2;
    }
    else {
        clockcycles += 1;
        carry = 0;
    }
    for (int8_t i = 0; i < 2; i++) {
        uint8_t carry_new = rng_seed[i] & 1;
        rng_seed[i] = (uint8_t)(rng_seed[i] >> 1) | (uint8_t)(carry << 7);
        carry = carry_new;
        clockcycles += 12;
    }
    return clockcycles + 5; //last jump does not happen
}

int incrementPieceStat() {
    int clockcycles = 27;
    *generalCounter = statsByType[tetriminoTypeFromOrientation[*accumulator] * 2] + 1;
    if ((uint8_t)(*generalCounter & (uint8_t)15) >= (uint8_t)10) {
        clockcycles += 14;
        *generalCounter += 6;
        if (((*generalCounter) & 0xF0) >= 0xA0) {
            *generalCounter += (uint8_t)0x60;
            statsByType[tetriminoTypeFromOrientation[*accumulator] * 2 + 1]++;
            clockcycles += 19;
        }
        else {
            clockcycles += 1;
        }
    }
    else {
        clockcycles += 1;
    }
    clockcycles += 15;
    statsByType[tetriminoTypeFromOrientation[*accumulator] * 2] = *generalCounter;
    *outOfDateRenderFlags = *outOfDateRenderFlags | 0x40;
    return clockcycles + 6;
}

int drop_tetrimino() {
    int clockcycles = 5;
    bool notBeginningOfGame_h = false;
    bool lookupDropSpeed_h = false;
    if ((int8_t)*autorepeatY < (int8_t)0) {
        clockcycles += 7;
        if ((uint8_t)(*newlyPressedButtons & (uint8_t)4) != (uint8_t)0) {
            *autorepeatY = 0;
            clockcycles += 5;
            notBeginningOfGame_h = true;
        }
        else {
            (*autorepeatY)++;
            clockcycles += 9;
        }
    }
    else {
        clockcycles += 1;
        notBeginningOfGame_h = true;
    }
    if (notBeginningOfGame_h == true) {
        clockcycles += 2;
        if ((uint8_t)*autorepeatY == (uint8_t)0) {
            clockcycles += 7;
            if ((uint8_t)(*heldButtons & (uint8_t)3) == (uint8_t)0) {
                if ((uint8_t)(*newlyPressedButtons & (uint8_t)15) == (uint8_t)4) {
                    *autorepeatY = 1;
                    clockcycles += 5;
                    lookupDropSpeed_h = true;
                }
                else {
                    clockcycles += 1;
                    lookupDropSpeed_h = true;
                }
            }
            else {
                clockcycles += 1;
                lookupDropSpeed_h = true;
            }
        }
        else {
            clockcycles += 10;
            if ((uint8_t)(*heldButtons & (uint8_t)15) != (uint8_t)4) {
                *autorepeatY = 0;
                *holdDownPoints = 0;
                lookupDropSpeed_h = true;
            }
            else {
                clockcycles += 14;
                (*autorepeatY)++;
                if ((uint8_t)*autorepeatY >= (uint8_t)3) {
                    *autorepeatY = 1;
                    (*holdDownPoints)++;
                    clockcycles += 10;
                    *fallTimer = 0;
                    *originalY = *tetriminoY;
                    (*tetriminoY)++;
                    clockcycles += 22;
                    clockcycles += isPositionValid();
                    if (*accumulator != 0) {
                        *tetriminoY = *originalY;
                        *playState = 2;
                        clockcycles += 17;
                        clockcycles += updatePlayfield();
                    }
                    else {
                        clockcycles += 1;
                    }
                }
                else {
                    clockcycles += 1;
                    lookupDropSpeed_h = true;
                }
            }
        }
    }
    if (lookupDropSpeed_h == true) {
        clockcycles += 9;
        if (*levelNumber <= 29) {
            clockcycles += 4;
            *dropSpeed = framesPerDropTable[*levelNumber];
        }
        else {
            clockcycles += 1;
            *dropSpeed = 1;//change back
        }
        clockcycles += 11;
        if (*fallTimer < *dropSpeed) {
            clockcycles += 3;
        }
        else {
            clockcycles += 1;
            //@drop
            *fallTimer = 0;
            *originalY = *tetriminoY;
            (*tetriminoY)++;
            clockcycles += 22;
            clockcycles += isPositionValid();
            if (*accumulator != 0) {
                *tetriminoY = *originalY;
                *playState = 2;
                clockcycles += 17;
                clockcycles += updatePlayfield();
            }
            else {
                clockcycles += 1;
            }
        }
    }
    return clockcycles + 6;
}

int shift_tetrimino() {
    int clockcycles = 13;
    *originalY = *tetriminoX;
    bool buttonHeldDown_h = false;
    if ((uint8_t)(*heldButtons & (uint8_t)0x04) == (uint8_t)0) {//down is not pressed
        clockcycles += 7;
        if ((uint8_t)(*newlyPressedButtons & (uint8_t)0x3) == (uint8_t)0) {//was left or right pressed
            clockcycles += 7;
            if ((uint8_t)(*heldButtons & (uint8_t)0x3) != (uint8_t)0) {
                (*autorepeatX)++;
                clockcycles += 12;
                if (*autorepeatX >= 16) {
                    *autorepeatX = 10;
                    clockcycles += 11;
                    buttonHeldDown_h = true;
                }
                else {
                    clockcycles += 1;
                }
            }
            else {
                clockcycles += 4;
            }
        }
        else {
            clockcycles += 6;
            *autorepeatX = 0;
            buttonHeldDown_h = true;
        }
    }
    else {
        clockcycles += 1;
    }
    if (buttonHeldDown_h == true) {
        clockcycles += 7;
        if ((uint8_t)(*heldButtons & (uint8_t)1) != (uint8_t)0) {
            (*tetriminoX)++;
            clockcycles += 11;
            clockcycles += isPositionValid();
            if (*accumulator == 0) {
                *soundEffectSlot1Init = 3;
                clockcycles += 9;
            }
            else {
                clockcycles += 1;
                *tetriminoX = *originalY;
                *autorepeatX = 16;
                clockcycles += 11;
            }
        }
        else {
            clockcycles += 7;
            if ((uint8_t)(*heldButtons & (uint8_t)2) != (uint8_t)0) {
                (*tetriminoX)--;
                clockcycles += 11;
                clockcycles += isPositionValid();
                if (*accumulator == 0) {
                    *soundEffectSlot1Init = 3;
                    clockcycles += 9;
                }
                else {
                    clockcycles += 1;
                    *tetriminoX = *originalY;
                    *autorepeatX = 16;
                    clockcycles += 11;
                }
            }
            else {
                clockcycles += 1;
            }
        }
    }
    return clockcycles + 6;
}

int playState_updateLinesAndStatistics(){
    int clockcycles = 6;
    //print_playfield();
    //completedlines is in the accumulator!
    clockcycles += updateMusicSpeed();
    *accumulator = *completedLines;
    if (*completedLines != 0) {
        lineClearStatsByType[*completedLines - 1]++;
        clockcycles += 22;
        if ((lineClearStatsByType[*completedLines - 1] & 15) == 10) {
            lineClearStatsByType[*completedLines - 1] += 6;
            clockcycles += 12;
        }
        else {
            clockcycles++;
        }
        *outOfDateRenderFlags = *outOfDateRenderFlags | 1;
        clockcycles += 13;
        if (*gameType != 0) {//gamemode not A!
            *generalCounter = *completedLines;
            clockcycles += 19;
            lines[0] = lines[0] - *generalCounter;
            if (lines[0] > 127) { // cleared_lines[0] <0 with signed numbers
                lines[0] = 0;
                clockcycles += 5;
            }
            else {
                clockcycles += 5;
                if ((lines[0] & 15) < 10) {
                    //break out of the 2 outer it statements
                }
                else {
                    lines[0] = lines[0] - 6;
                    clockcycles += 13;
                }
            }
        }
        else {
            clockcycles += 4;
            clockcycles += update_level();
        }
    }
    else {
        clockcycles += 6; //JMP instruction
    }
    clockcycles += 7;
    if (*holdDownPoints - 2 >= 0) {
        clockcycles += 19;
        score[0]--;
        score[0] += *holdDownPoints;
        if ((score[0] & 0x0F) - 10 >= 0) {//unsigned!!!
            clockcycles += 10;
            score[0] += 6;
        }
        else {
            clockcycles++;
        }
        clockcycles += 9;
        if ((score[0] & 0xF0) - 0xA0 >= 0) {//unsigned!!!
            clockcycles += 12;
            score[0] = score[0] & 0xF0; // uses the value computed for the comparison
            score[0] += 0x60;
            score[1]++;
        }
        else {
            clockcycles++;
        }
        *outOfDateRenderFlags = (*outOfDateRenderFlags) | 4;
        clockcycles += 8;
    }
    else {
        clockcycles++;
    }
    *holdDownPoints = 0;
    clockcycles += 5;
    clockcycles += calculate_score();
    *outOfDateRenderFlags = (*outOfDateRenderFlags) | 4;
    *completedLines = 0;
    (*playState)++;
    return clockcycles + 19;
}

int calculate_score() {
    int clockcycles = 16; //Setup the loop

    /*if (*completedLines == 4) {
        printf("Tetris!\r\n");
        print_playfield();
    }*/
    for (int i = 0; i <= *levelNumber; i++) { 
        clockcycles += 21;
        score[0] += pointsTable[2 * *completedLines];
        if (score[0] >= 0xA0) { //upper digit of score > 9
            clockcycles += 7;
            score[0] += 0x60;
            score[1]++;
        }
        else {
            clockcycles += 3;
        }
        clockcycles += 18;
        score[1] += pointsTable[2 * *completedLines + 1];
        if ((score[1] & 0x0F) > 9) {
            clockcycles += 12;
            score[1] += 6;
        }
        else {
            clockcycles += 3;
        }
        clockcycles += 7;
        if (score[1] >= 0xA0) {
            clockcycles += 17;
            score[1] += 0x60;
            score[2]++;
        }
        else {
            clockcycles += 3;
        }
        clockcycles += 7;
        if ((score[2] & 0x0F) > 9) {
            clockcycles += 12;
            score[2] += 6;
        }
        else {
            clockcycles += 3;
        }
        if (modification == UNMODIFIED) {
            clockcycles += 7;
            if (score[2] > 0x99) {
                clockcycles += 13;
                score[0] = 0x99;
                score[1] = 0x99;
                score[2] = 0x99;
            }
            else {
                clockcycles += 3;
            }
        }
        if (modification == SEVENDIGITS) {
            clockcycles += 7;
            if (score[2] > 0x99) {
                clockcycles += 13;
                score[2] -= 0xA0;
                addressSpace[0x0F]++;
                //print_playfield();
            }
            else {
                clockcycles += 3;
            }
        }
        if (modification == NOMAXOUTCODE) {
            clockcycles += 7;
            if (score[2] > 0xFA) {
                clockcycles += 13;
                score[0] = 0x99;
                score[1] = 0x99;
                score[2] = 0x99;
            }
            else {
                clockcycles += 3;
            }
        }
        if (modification == ENEOOGEZ) {
            clockcycles += 7;
            if (score[2] >= 0xF0) {
                clockcycles += 13;
                score[0] = 0x99;
                score[1] = 0x99;
                score[2] = 0x99;
            }
            else {
                clockcycles += 3;
            }
        }
        if (modification == CRASHFIX) {
            clockcycles += 3;
        }
        clockcycles += 8;
    }
    /*if (clockcycles > 10000) { //Hackfix Crashfix
        return 10000;
    }*/
    return clockcycles + 2;
}

int update_level() {
    int clockcycles = 0;
    for (uint8_t i = 0; i < *completedLines; i++) {
        clockcycles += 12;
        lines[0]++;
        if ((lines[0] & 0x0F) > 9) {
            clockcycles += 9;
            lines[0] += 6; //adding 6 to convert from Hex to Dec
        }
        else {
            clockcycles += 3;
        }
        clockcycles += 7;
        if ((lines[0] & 0xF0) > 0x90) {
            clockcycles += 15;
            lines[0] -= 0xA0;
            lines[1]++;
        }
        else {
            clockcycles += 3;
        }
        clockcycles += 5;
        if ((lines[0] & 0x0F) == 0) {
            clockcycles += 55;
            uint8_t level = (lines[0] >> 4);
            level = level | (lines[1] << 4);
            uint8_t difference = (uint8_t)(*levelNumber) - (uint8_t)level;
            difference = (uint8_t)difference & (uint8_t)0x80;
            if (difference == (uint8_t)0x80) {
                clockcycles += 7;
                (*levelNumber)++;
                *soundEffectSlot1Init = 6;
                *outOfDateRenderFlags = (*outOfDateRenderFlags) | 2;
                clockcycles += 22;
            }
            else {
                clockcycles += 3;
            }
        }
        else {
            clockcycles += 3;
        }
    }
    return clockcycles;
}

int updatePlayfield() {
    int clockcycles = 11;
    *registerX = (*tetriminoY) - 2;
    *accumulator = (*tetriminoY) - 2;
    if ((*tetriminoY) - 2 < 0) { //signed compare
        *accumulator = 0;
        clockcycles += 2;
    }
    else {
        clockcycles += 1;
    }
    clockcycles += 5;
    if (*accumulator < *vramRow) {
        *vramRow = *accumulator;
        clockcycles += 3;
    }
    else {
        clockcycles += 1;
    }
    return clockcycles + 6;
}

int rotate_tetrimino() {
    int clockcycles = 24;
    *originalY = *currentPiece;
    *registerX = *currentPiece << 1;
    if ((uint8_t)(*newlyPressedButtons & (uint8_t)0x80) == (uint8_t)0x80) {
        (*registerX)++;
        *currentPiece = rotationTable[*registerX];
        *accumulator = *currentPiece;
        clockcycles += isPositionValid();
        clockcycles += 14;
        if (*accumulator == 0) {
            clockcycles += 9;
            *soundEffectSlot1Init = 5;
        }
        else {
            clockcycles += 7;
            *currentPiece = *originalY;
        }
    }
    else {
        clockcycles += 10;
        if ((uint8_t)(*newlyPressedButtons & (uint8_t)0x40) == (uint8_t)0x40) {
            *currentPiece = rotationTable[*registerX];
            *accumulator = *currentPiece;
            clockcycles += 13;
            clockcycles += isPositionValid();
            if (*accumulator == 0) {
                *soundEffectSlot1Init = 5;
                clockcycles += 5;
            }
            else {
                clockcycles += 7;
                *currentPiece = *originalY;
            }
        }
        else {
            clockcycles += 1;
        }
    }

    return clockcycles + 6;
}

int isPositionValid() {
    int clockcycles = 49;
    *generalCounter = *tetriminoY << 1;
    *generalCounter = (*generalCounter << 2) + *generalCounter + *tetriminoX;
    *generalCounter2 = *currentPiece << 2;
    *registerX = *generalCounter2 + (*generalCounter2 << 1);
    *generalCounter3 = 4;
    *registerY = 0;
    do {
        clockcycles += 15;
        //uint8_t is converted to int -->  does not wrap around at 256!!!
        uint8_t temp = (uint8_t)(orientationTable[*registerX] + *tetriminoY);
        if (temp >= -2 && temp < 20 || temp == 255 || temp == 254) { // WHY + 2 and then compare with 22 ??
            *generalCounter4 = orientationTable[*registerX] << 1;
            *selectingLevelOrHeight = *generalCounter + *generalCounter4 + (*generalCounter4 << 2);
            *registerX += 2;
            *registerY = orientationTable[*registerX] + *selectingLevelOrHeight;
            clockcycles += 50;
            if (addressSpace[*((uint16_t*)playfieldAddr) + *registerY] >= 0xEF) {//!= ???
                clockcycles += 13;
                if ((int8_t)(orientationTable[*registerX] + *tetriminoX) < 10 && (int8_t)(orientationTable[*registerX] + *tetriminoX) >= 0) {
                    (*registerX)++;
                    (*generalCounter3)--;
                    clockcycles += 10;
                }
                else {
                    *generalCounter = 255;
                    *accumulator = 255;
                    return clockcycles + 12;
                }
            }
            else {
                *generalCounter = 255;
                *accumulator = 255;
                return clockcycles + 12;
            }

        }
        else {
            *generalCounter = 255;
            *accumulator = 255;
            return clockcycles + 12;
        }
    } while (*generalCounter3 != 0);
    *generalCounter = 0;
    *accumulator = 0;
    return clockcycles + 10;
}

int playState_checkForCompletedRows() {
    int clockcycles = 7;
    *accumulator = *vramRow;
    if (*vramRow >= 32) {
        clockcycles += 9;
        uint8_t temp;
        if (*tetriminoY >= 2) {
            clockcycles += 1;
            temp = *tetriminoY - 2;
        }
        else {
            clockcycles += 2;
            temp = 0;
        }

        clockcycles += 27;
        *generalCounter2 = temp + *lineIndex;
        *generalCounter = (*generalCounter2) << 1;
        *generalCounter = *generalCounter + ((*generalCounter) << 2);
        *registerY = *generalCounter;
        *registerX = 10;//x regsiter
        bool lineCompleted_h = true;
        do {
            clockcycles += 9;
            if (addressSpace[*((uint16_t*)playfieldAddr) + *registerY] == 0xEF) {
                clockcycles += 10;
                completedRow[*lineIndex] = 0;
                lineCompleted_h = false;
                break;
            }
            (*registerY)++;
            (*registerX)--;
            clockcycles += 7;
        } while (*registerX > 0);
        if (lineCompleted_h == true) {
           clockcycles += 22;//last jump did not happen!
            *soundEffectSlot1Init = 10; // not in Zeropage
            (*completedLines)++;
            completedRow[*lineIndex] = *generalCounter2;
            *registerY = *generalCounter;
            (*registerY)--;
            do {
                addressSpace[*((uint16_t*)playfieldAddr) + *registerY + 10] = addressSpace[*((uint16_t*)playfieldAddr) + *registerY];//playfieldAddr is modified during that process idk how to represent that in C!
                //overflows to next ram region? YES!
                (*registerY)--;
                clockcycles += 28;
            } while ((uint8_t)*registerY != 255); //overflow!
            clockcycles += 3;//last jump did not happen!
            for (int8_t i = 0; i < 10; i++) {
                addressSpace[*((uint16_t*)playfieldAddr) + i] = 0xEF;
                clockcycles += 13;
            }
            playfieldAddr;
            clockcycles += 7;//last jump did not happen!
            *currentPiece = 0x13;
        }
        else {
            clockcycles += 9;
            completedRow[*lineIndex] = 0;
        }
        (*lineIndex)++;
        clockcycles += 12;
        *accumulator = *lineIndex;
        if (*lineIndex >= 4) {
            clockcycles += 31;
            *pendingGarbageInactivePlayer = *pendingGarbageInactivePlayer + garbageLines[(*completedLines)];
            *rowY = 0;
            *vramRow = 0;
            if (*completedLines >= 4) {
                *soundEffectSlot1Init = 4;
                clockcycles += 6;
            }
            else {
                clockcycles += 1;
            }
            clockcycles += 10;
            (*playState)++;
            *accumulator = *completedLines;
            if (*completedLines == 0) { //check exact condition
                clockcycles += 11;
                (*playState)++;
                *soundEffectSlot1Init = 7;
                *accumulator = 7;
            }
            else {
                clockcycles += 1;
            }
        }
        else {
            clockcycles += 1;
        }
    }
    else {
        clockcycles += 3;
    }
    return clockcycles + 6;
}


int updateMusicSpeed() {
    int clockcycles = 10;
    int8_t counter = 10;
    int8_t offset = 50;
    do {
        clockcycles += 9;
        if (addressSpace[*((uint16_t*)playfieldAddr) + offset] != 0xEF) {
            clockcycles += 1;
            if (*allegro == 0) {
                clockcycles += 24;
                *allegro = 0xFF;
                clockcycles += setMusicTrack(musicSelectionTable[*musicType + 4]);
                clockcycles += 3;
            }
            else {
                clockcycles += 1;
            }
            clockcycles += 6;
            return clockcycles;
        }
        offset++;
        counter--;
        clockcycles += 7;
    } while (counter > 0);
    clockcycles += 4; //last jump did not happen!
    if (*allegro != 0) {
        clockcycles += 18;
        *allegro = 0;
        clockcycles += setMusicTrack(musicSelectionTable[*musicType]);

        clockcycles += 3;
    }
    else {
        clockcycles += 1;
    }
    clockcycles += 6;
    return clockcycles;
}

int setMusicTrack(uint8_t number) {
    int clockcycles = 11;
    *musicTrack = number;
    if (*gameMode == 5) {
        *musicTrack = 255;
        clockcycles += 6;
    }
    else {
        clockcycles += 1;
    }
    return clockcycles + 6;
}

//functions to print the playfield to the console

void print_playfield() {
    int digits;
    int points;
    if (modification == SEVENDIGITS) {
        digits = 7;
        uint8_t sevendigitScore[4] = { score[0], score[1], score[2] ,addressSpace[0x0F]};
        points = int_to_C_format(sevendigitScore, digits);
    }
    else {
        digits = 6;
        points = int_to_C_format(score, digits);
    }
    int lines_c = int_to_C_format(lines, 3);
    //system("clear");
    //Frame is paused before the draw call in the FCEUX emulator
    printf("Score: %i\tDAS: %i\tMusic: %i\tLevel: %i\tLines: %i\tNext: %c\tFrame: %i\r\n", points, *autorepeatX, *musicTrack, *levelNumber, lines_c, piece_to_letter(*nextPiece), *((uint16_t*)frameCounter));
    for (int i = 0; i < 20; i++) {
        print_statistics(i);
        for (int j = 0; j < 10; j++) {
            if (isPartOfTetrimino(j, i) == true) {
                printf("222\t");
            }
            else {
                if (playfield[i * 10 + j] != 0xEF) {
                    printf("%X\t", playfield[i * 10 + j]);
                }
                else {
                    printf("0\t");
                }
            }
        }
        printf("\r\n");
    }
    printf("\r\n");
}

void print_statistics(int line) {
    switch (line) {
    case 7: printf("T: %i\t", int_to_C_format(statsByType + (line - 7) * 2, 3)); break;
    case 8: printf("J: %i\t", int_to_C_format(statsByType + (line - 7) * 2, 3)); break;
    case 9: printf("Z: %i\t", int_to_C_format(statsByType + (line - 7) * 2, 3)); break;
    case 10: printf("O: %i\t", int_to_C_format(statsByType + (line - 7) * 2, 3)); break;
    case 11: printf("S: %i\t", int_to_C_format(statsByType + (line - 7) * 2, 3)); break;
    case 12: printf("L: %i\t", int_to_C_format(statsByType + (line - 7) * 2, 3)); break;
    case 13: printf("I: %i\t", int_to_C_format(statsByType + (line - 7) * 2, 3)); break;
    default: printf("\t");
    }
}

bool isPartOfTetrimino(uint8_t x, uint8_t y) {
    switch (*currentPiece) {
    case 0: if ((y == *tetriminoY && x >= *tetriminoX - 1 && x <= *tetriminoX + 1) || (y == *tetriminoY - 1 && x == *tetriminoX)) {
        return true;
    }
          break;
    case 1: if ((x == *tetriminoX && y >= *tetriminoY - 1 && y <= *tetriminoY + 1) || (x == *tetriminoX + 1 && y == *tetriminoY)) {
        return true;
    }
          break;
    case 2: if ((y == *tetriminoY && x >= *tetriminoX - 1 && x <= *tetriminoX + 1) || (y == *tetriminoY + 1 && x == *tetriminoX)) {
        return true;
    }
          break;
    case 3: if ((x == *tetriminoX && y >= *tetriminoY - 1 && y <= *tetriminoY + 1) || (x == *tetriminoX - 1 && y == *tetriminoY)) {
        return true;
    }
          break;
    case 4: if ((x == *tetriminoX && y >= *tetriminoY - 1 && y <= *tetriminoY + 1) || (y == *tetriminoY + 1 && x == *tetriminoX - 1)) {
        return true;
    }
          break;
    case 5: if ((y == *tetriminoY && x >= *tetriminoX - 1 && x <= *tetriminoX + 1) || (x == *tetriminoX - 1 && y == *tetriminoY - 1)) {
        return true;
    }
          break;
    case 6: if ((x == *tetriminoX && y >= *tetriminoY - 1 && y <= *tetriminoY + 1) || (y == *tetriminoY - 1 && x == *tetriminoX + 1)) {
        return true;
    }
          break;
    case 7: if ((y == *tetriminoY && x >= *tetriminoX - 1 && x <= *tetriminoX + 1) || (x == *tetriminoX + 1 && y == *tetriminoY + 1)) {
        return true;
    }
          break;
    case 8: if ((y == *tetriminoY && x >= *tetriminoX - 1 && x <= *tetriminoX) || (y == *tetriminoY + 1 && x >= *tetriminoX && x <= *tetriminoX + 1)) {
        return true;
    }
          break;
    case 9: if ((x == *tetriminoX && y >= *tetriminoY && y <= *tetriminoY + 1) || (x == *tetriminoX + 1 && y >= *tetriminoY - 1 && y <= *tetriminoY)) {
        return true;
    }
          break;
    case 10: if (x >= *tetriminoX - 1 && x <= *tetriminoX && y <= *tetriminoY + 1 && y >= *tetriminoY) {
        return true;
    }
           break;
    case 11: if ((y == *tetriminoY && x >= *tetriminoX && x <= *tetriminoX + 1) || (y == *tetriminoY + 1 && x >= *tetriminoX - 1 && x <= *tetriminoX)) {
        return true;
    }
           break;
    case 12: if ((x == *tetriminoX && y >= *tetriminoY - 1 && y <= *tetriminoY) || (x == *tetriminoX + 1 && y >= *tetriminoY && y <= *tetriminoY + 1)) {
        return true;
    }
           break;
    case 13: if ((x == *tetriminoX && y >= *tetriminoY - 1 && y <= *tetriminoY + 1) || (y == *tetriminoY + 1 && x == *tetriminoX + 1)) {
        return true;
    }
           break;
    case 14: if ((y == *tetriminoY && x >= *tetriminoX - 1 && x <= *tetriminoX + 1) || (x == *tetriminoX - 1 && y == *tetriminoY + 1)) {
        return true;
    }
           break;
    case 15: if ((x == *tetriminoX && y >= *tetriminoY - 1 && y <= *tetriminoY + 1) || (y == *tetriminoY - 1 && x == *tetriminoX - 1)) {
        return true;
    }
           break;
    case 16: if ((y == *tetriminoY && x >= *tetriminoX - 1 && x <= *tetriminoX + 1) || (x == *tetriminoX + 1 && y == *tetriminoY - 1)) {
        return true;
    }
           break;
    case 17: if (x == *tetriminoX && y >= *tetriminoY - 2 && y < *tetriminoY + 2) {
        return true;
    }
           break;
    case 18: if (y == *tetriminoY && x >= *tetriminoX - 2 && x < *tetriminoX + 2) {
        return true;
    }
           break;
    }
    return false;
}

void int_to_NES_format(int number, int digits, uint8_t* NES_number) {
    if (digits == 3) {
        NES_number[0] = number % 10;
        NES_number[0] = NES_number[0] + ((number / 10 % 10) * 16);
        NES_number[1] = number / 100;
    }
    if (digits == 6 || digits == 7) {
        uint8_t temp = 0;
        int i = 0;
        for (i = 0; i < 3; i++) {
            temp = number % 10;
            number = number / 10;
            temp += (number % 10) * 16;
            number = number / 10;
            NES_number[i] = temp;
        }
        if (digits == 7) {
            NES_number[3] = number;
        }
    }
    else {

    }
}
int int_to_C_format(uint8_t* number, int digits) {
    int c_number = 0;
    if (digits == 3) {
        c_number += number[0] & 0x0F;
        c_number += ((number[0] & 0xF0) >> 4) * 10;
        c_number += number[1] * 100;
    }
    if (number != NULL && (digits == 6 || digits == 7)) {
        int multiplier = 1;
        int i;
        for (i = 0; i < 3; i++) {
            c_number += (number[i] & 0x0F) * multiplier;
            c_number += ((number[i] & 0xF0) >> 4) * multiplier * 10;
            multiplier *= 100;
        }
        if (digits == 7) {
            c_number += number[i] * multiplier;
        }
    }
    return c_number;
}

char piece_to_letter(uint8_t piece) {
    switch (piece) {
    case 2: return 'T';
    case 7: return 'J';
    case 8: return 'Z';
    case 10: return 'O';
    case 11: return 'S';
    case 14: return 'L';
    case 18: return 'I';
    default: return 'X';
    }
}
