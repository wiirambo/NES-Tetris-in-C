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
int LA96E();
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

int NMI();

int update_level();
int calculate_score();


void setRegisters(uint8_t* acc, uint8_t* X, uint8_t* Y);
void setVRAM(uint16_t* ppuaddr, uint8_t* tblPalette, uint8_t* fine_x, uint16_t* tram_addr, uint8_t* oamAddr);
void setBaseAddressRAM();
void setBaseAddressROM();
void setAPURegisters(bool* channel1Disable, bool* channel2Disable, bool* noiseDisable, uint16_t* channel1Vol, uint16_t* channel2Vol, uint16_t* noiseVol, uint32_t* channel1Seq, uint32_t* channel2Seq);
void setControllers(uint8_t* controller1Input, uint8_t* controller2Input, uint8_t* dma_page, uint8_t* dma_addr, bool* dma_transfer);
uint8_t* getAddressSpace(uint8_t id);
uint8_t* calculateBaseAddress(uint8_t id);//argument needs to be const char in CPP

void apply_game_genie_code(const char code[], int characters);