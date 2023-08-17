#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "nestetrisclockcyclesuint8_t.h"
#include "printplayfield.h"

typedef enum {
    UNMODIFIED,
    SEVENDIGITS, //score display does not work correctly
    NOMAXOUTCODE,
    ENEOOGEZ,
    CRASHFIX
} Modifications;

Modifications modification = SEVENDIGITS;

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
uint8_t* musicPauseSoundEffectLengthCounter;
uint8_t* musicStagingSq2Lo;
uint8_t* musicStagingSq2Hi;
uint8_t* musicStagingTriLo;
uint8_t* musicStagingTriHi;
uint8_t* resetSq12ForMusic;
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

//registers
uint8_t* accumulator;
uint8_t* registerX;
uint8_t* registerY;
uint16_t* PPUADDR;
uint8_t* fine_x;
uint16_t* tram_addr;
bool* channel1DisableFlag;
bool* channel2DisableFlag;
bool* noiseDisableFlag;
uint16_t* channel1Volume;
uint16_t* channel2Volume;
uint16_t* noiseVolume;
uint32_t* channel1Seqence;
uint32_t* channel2Seqence;
uint8_t* controller1;
uint8_t* controller2;
uint8_t* oam_addr;
uint8_t* oamdma;
uint8_t* oamaddr;
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

//base addresses
//uint8_t* baseAddressROM;
uint8_t* baseAddressROM;
uint8_t* baseAddressTBL;
uint8_t* tablePalette;

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

void setAPURegisters(bool* channel1Disable, bool* channel2Disable, bool* noiseDisable,
                    uint16_t* channel1Vol, uint16_t* channel2Vol, uint16_t* noiseVol,
                    uint32_t* channel1Seq, uint32_t* channel2Seq){
    channel1DisableFlag = channel1Disable;
    channel2DisableFlag = channel2Disable;
    noiseDisableFlag = noiseDisable;
    channel1Volume = channel1Vol;
    channel2Volume = channel2Vol;
    noiseVolume = noiseVol;
    channel1Seqence = channel1Seq;
    channel2Seqence = channel2Seq;
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
    demoTetriminoTypeTable = addressSpace + 0xDF00;
    spawnOrientationFromOrientation = addressSpace + 0x9956;
    oamContentLookup = addressSpace + 0x8C6C;
    orientationToSpriteTable = addressSpace + 0x8BE5;
    colorTable = addressSpace + 0x984C;
    multBy10Table = addressSpace + 0x96D6;
    vramPlayfieldRows = addressSpace + 0x96EA;
    leftColumns = addressSpace + 0x97FE;
    rightColumns = addressSpace + 0x9803;
    highScorePpuAddrTable = addressSpace + 0xA086;
    highScoreCharToTile = addressSpace + 0xA08C;
    ending_typeBCathedralAnimSpeed = addressSpace + 0xA749;
    ending_typeBCathedralSpriteTable = addressSpace + 0xA7F3;
    LA735 = addressSpace + 0xA735;
    LA73D = addressSpace + 0xA73D;
    LA745 = addressSpace + 0xA745;
    LAA2A = addressSpace + 0xAA2A;
    domeNumberToXOffsetTable = addressSpace + 0xA739;
    domeNumberToXSpriteTable = addressSpace + 0xA741;
    marioFrameToYOffsetTable = addressSpace + 0xA80A;
    luigiFrameToYOffsetTable = addressSpace + 0xA80E;
    luigiFrameToSpriteTable = addressSpace + 0xA818;
    levelToSpriteYOffset = addressSpace + 0x85B2;
    levelToSpriteXOffset = addressSpace + 0x85BC;
    heightToPpuLowAddr = addressSpace + 0x85C6;
    heightToPpuHighAddr = addressSpace + 0x85CC;
    levelDisplayTable = addressSpace + 0x96B8;
    pieceToPpuStatAddr = addressSpace + 0x96AA;
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

void setVRAM(uint16_t* ppuaddr, uint8_t* tblPalette, uint8_t* fineX, uint16_t* tramaddr, uint8_t* oamAddr) {
    PPUADDR = ppuaddr;
    tablePalette = tblPalette;
    fine_x = fineX;
    tram_addr = tramaddr;
    oam_addr = oamAddr;
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

int NMI(){
    //printf("Frame %02x%02x\r\n", addressSpace[0xB2], addressSpace[0xB1]);
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
            *PPUADDR = 0x20 << 8;
            *PPUADDR |= 0x73;
            baseAddressTBL[*PPUADDR & 0x3FF] = *(player1_lines+1);
            (*PPUADDR)++;
            *accumulator = *player1_lines;
            clockcycles += twoDigsToPPU();
            clockcycles += 8;
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
            clockcycles += 31;
            *generalCounter = levelDisplayTable[*player1_levelNumber];
            *PPUADDR = 0x22 << 8;
            *PPUADDR |= 0xBA;
            *accumulator = *generalCounter;
            clockcycles += twoDigsToPPU();
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
                baseAddressTBL[*PPUADDR & 0x3FF] = statsByType[*registerX + 1];
                (*PPUADDR)++;
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

int LA96E() {
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

/*int initPlayfieldIfTypeB(){
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
                    playField[*registerY] = *generalCounter4;
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
                playField[*registerY] = 0xEF;
                //clockcycles += updateAudioWaitForNmiAndResetOamStaging(); // not yet implemented
                generateNextPseudorandomNumber();//goes to next frame? Not part of the code !!
            }
        }
        for(int i=200;i>0;i--){//it starts with 200; offset 0 is not copied!
            clockcycles += 13;
            playFieldForSecondPlayer[i] = playField[i];
        }
        clockcycles += 10;
        for(*registerY = typeBBlankInitCountByHeightTable[*player1_startHeight];(int8_t)*registerY>=0;(*registerY)--){
            playField[*registerY]=0xEF;
            clockcycles += 11;
        }
        clockcycles += -1;//last jump does not happen
        //below here the register have be set so they are correct after the return!
        clockcycles += 9;
        *registerX = *player2_startHeight;
        for(*registerY = typeBBlankInitCountByHeightTable[*registerX];(int8_t)*registerY>=0;(*registerY)--){
            playField[*registerY]=0xEF;
            clockcycles += 11;
        }
        clockcycles += -1;//last jump does not happen
    }
}*/

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

int chooseNextTetrimino() {
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
    if (clockcycles > 10000) { //Hackfix Crashfix
        return 10000;
    }
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
    int digits = 6;
    if (modification == SEVENDIGITS) {
        digits = 7;
    }
    int points = int_to_C_format(score, digits);
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