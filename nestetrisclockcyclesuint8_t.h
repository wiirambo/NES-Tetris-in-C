#pragma once

#include <stdbool.h>

int updateMusicSpeed();
int setMusicTrack(uint8_t number);
int playState_checkForCompletedRows();
int rotate_tetrimino();
int isPositionValid();
int drop_tetrimino();
int updatePlayfield();
int playState_updateLinesAndStatistics();
int shift_tetrimino();
int incrementPieceStat();
int generateNextPseudorandomNumber();
int realStart();
int playState_spawnNextTetrimino();
int chooseNextTetrimino();
int demoButtonsTable_indexIncr();
int playState_playerControlsActiveTetrimino();
int playState_lockTetrimino();
int updatePaletteForLevel();
int startButtonPressed();
int timeout();
int makePlayer1Active();
int makePlayer2Active();
int stageSpriteForCurrentPiece();
int stageSpriteForNextPiece();
int noop_disabledVramRowIncr();
int gameModeState_vblankThenRunState2();
int playState_unassignOrientationId();
int playState_incrementPlayState();
int playState_noop();
int copyHighScoreNameToNextIndex();
int copyHighScoreScoreToNextIndex();
int copyHighScoreLevelToNextIndex();
int twoDigsToPPU();
int copyPlayfieldRowToVRAM();
int updateLineClearingAnimation();
int render_mode_congratulations_screen();
int ending_typeBCathedralSetSprite();
int loadSpriteIntoOamStaging();
int memset_page();
int advanceAudioSlotFrame();
int patchToPpu();
int LA6BC();
int kidIcarus();
int link();
int samus();
int donkeyKong();
int bowser();
int marioLuigiPeach();
int selectEndingScreen();
int render_mode_legal_and_title_screens();
int gameMode_levelMenu_handleLevelHeightNavigation();
int savePlayer1State();
int savePlayer2State();
int musicGetNextInstructionByte();
int render_mode_play_and_demo();
int render_mode_ending_animation();
int render_mode_congratulations_screen();
int muteAudio();
int muteAudioAndClearTriControl();
int soundEffectSlot2_makesNoSound();
int updateAudio2();
int pollController_actualRead();
int addExpansionPortInputAsControllerInput();
int pollController();
int pollControllerButtons();
int render_mode_menu_screens();
int render();
int switch_s_plus_2a();
int copyOamStagingToOam();
int gameModeState_checkForResetKeyCombo();
int playState_player2ControlsActiveTetrimino();
int computeSoundEffMethod();
int initAudioAndMarkInited();
int stopSoundEffectSlot0();
int getSoundEffectNoiseNibble();
int loadNoiseLo();
int LE33B();
int copyToSq1Channel();
int copyToTriChannel();
int copyToNoiseChannel();
int copyToSq2Channel();
int initSoundEffectShared();
int soundEffectSlot0_makesNoSound();
int soundEffectSlot1_lockTetriminoInit();
int soundEffectSlot1_shiftTetriminoInit();
int soundEffectSlot1_rotateTetriminoInit();
int soundEffectSlot1_rotateTetriminoPlaying();
int soundEffectSlot1Playing_stop();
int soundEffectSlot1_tetrisAchievedPlaying();
int soundEffectSlot1_lineClearingPlaying();
int soundEffectSlot1_lineClearingInit();
int soundEffectSlot1_tetrisAchievedInit();
int soundEffectSlot1_levelUpPlaying();
int soundEffectSlot1_levelUpInit();
int soundEffectSlot1_menuScreenSelectInit();
int soundEffectSlot1_menuScreenSelectPlaying();
int updateMusicFrame_setChanLoOffset();
int advanceSoundEffectSlot0WithoutUpdate();
int updateSoundEffectSlot0_apu();
int soundEffectSlot0_gameOverCurtainInit();
int soundEffectSlot0_endingRocketInit();
int soundEffectSlot1_menuOptionSelectInit();
int initSq12IfTrashedBySoundEffect();
int soundEffectSlot1_chirpChirpPlaying();
int soundEffectSlot1_menuOptionSelectPlaying();
int memset_ppu_page_and_more();
int LAA82();
int playState_receiveGarbage();
int selectEndingScreen();
int render_ending();
int gameModeState_updateCountersAndNonPlayerState();


void mainLoop(int (*endFrame)(), int (*endFrameNoNMI)());


int handleHighScoreIfNecessary(int (*endFrame)(), int (*endFrameNoNMI)());
int highScoreEntryScreen(int (*endFrame)(), int (*endFrameNoNMI)());
int gameModeState_handleGameOver(int (*endFrame)(), int (*endFrameNoNMI)());
int gameModeState_startButtonHandling(int (*endFrame)());
int gameModeState_updatePlayer1(int (*endFrame)());
int gameModeState_updatePlayer2(int (*endFrame)());
int gameModeState_initGameState(int(*endFrame)());
int initPlayfieldIfTypeB(int(*endFrame)());
int gameModeState_initGameBackground(int(*endFrame)(), int(*endFrameNoNMI)());
int gameMode_startDemo(int (*endFrame)(), int(*endFrameNoNMI)());
int gameMode_playAndEndingHighScore(int (*endFrame)(), int(*endFrameNoNMI)());
int branchOnGameMode(int (*endFrame)(), int(*endFrameNoNMI)());
int showHighScores(int(*endFrame)());
int gameMode_levelMenu(int(*endFrame)(), int(*endFrameNoNMI)());
int render_endingUnskippable(int(*endFrame)());
int endingAnimation(int (*endFrame)());
int playState_bTypeGoalCheck(int (*endFrame)());
int playState_updateGameOverCurtain(int (*endFrame)());
int branchOnPlayStatePlayer1(int (*endFrame)());
int branchOnPlayStatePlayer2(int (*endFrame)());
int gameMode_gameTypeMenu(int (*endFrame)(),int (*endFrameNoNMI)());
int gameMode_titleScreen(int (*endFrame)());
int gamemode_legalScreen(int (*endFrame)());
int bulkCopyToPpu(uint8_t stackPointer, uint16_t PC, int (*endFrame)());

int updateAudioWaitForNmiAndResetOamStaging(int (*endFrame)());
int updateAudioWaitForNmiAndDisablePpuRendering(int (*endFrame)());
int updateAudioAndWaitForNmi(int (*endFrame)());
int waitForVBlankAndEnableNmi(int (*endFrame)());
int updateAudioWaitForNmiAndEnablePpuRendering(int (*endFrame)());
int initRAM2(int (*endFrame)());

int disableNmi();
int setMMC1Control();
int changeCHRBank0();
int changeCHRBank1();
int changePRGBank();
int initRamContinued();
int NMI();

int updateAudio_pause();
void setNoiseReload(uint8_t value);
void setpulse(uint8_t value);
void setsweep(uint8_t value);
void setpulseSequence(uint8_t value);
void setsweep2(uint8_t value);
void setpulseSequence2(uint8_t value);
void setLengthCouter(uint8_t value);
int update_level();
int LE442();
int calculate_score();


void setCHRBanks(uint8_t* nCHRBankSelect4Lo, uint8_t* nCHRBankSelect4Hi);
void setRegisters(uint8_t* acc, uint8_t* X, uint8_t* Y);
void setVRAM(uint16_t* ppuaddr, uint8_t* tblPalette, uint8_t* fine_x, uint16_t* tramaddr, uint16_t* vramaddr, uint8_t* oamAddr, uint8_t* PPUCTRRegister, uint8_t* PPUMaskAddr, uint8_t* PPUStatusReg, uint8_t* tblPattern, uint8_t* tblPattern2);
void setBaseAddressRAM();
void setBaseAddressROM();
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
                    uint8_t* pulse2Cou);
void setControllers(uint8_t* controller1Input, uint8_t* controller2Input, uint8_t* dma_page, uint8_t* dma_addr, bool* dma_transfer);
uint8_t* getAddressSpace(uint8_t id);
uint8_t* calculateBaseAddress(uint8_t id);//argument needs to be const char in CPP

void apply_game_genie_code(const char code[], int characters);
