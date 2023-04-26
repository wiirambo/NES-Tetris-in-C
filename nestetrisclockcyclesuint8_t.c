#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdint-gcc.h>

uint8_t pointsTable[10] = {0,0,0x40,0,0,1,0,3,0,0x12};
uint8_t cleared_lines[]={0,0};
uint8_t current_level[] = {0};
uint8_t player1_levelNumber[] = {0};
uint8_t current_score[]={0,0,0,0};
uint8_t playField_index_list[]={0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190};
uint8_t playFieldAddr[1][256] = {0}; //length is supposed to be 200 but there are out of bounds reads
uint8_t *playField=playFieldAddr[0];
uint8_t playFieldForSecondPlayer[256] = {0}; //length is supposed to be 200 but there are out of bounds reads???
uint8_t demoButtonsAddr[1][0x200] = {0}; //I don't know the length
uint8_t *demoButtons=demoButtonsAddr[0];
uint8_t *demoButtonsBase_h = demoButtonsAddr[0]-0xDD00; // what is the actual base address? needs to end in 0x00!!! does making it constant matter?
uint8_t holdDownPoints[] = {0};
uint8_t outOfDateRenderFlags[] = {0};
uint8_t lineClearStatsByType[]={0,0,0,0};
uint8_t generalCounter[] = {0};
uint8_t generalCounter2[] = {0};
uint8_t generalCounter3[] = {0};
uint8_t generalCounter4[] = {0};
uint8_t generalCounter5[] = {0};
uint8_t soundEffectSlot0Init[] = {0};
uint8_t soundEffectSlot1Init[] = {0};
uint8_t gameType[] = {0};
uint8_t gameMode[] = {0};
uint8_t completedLines[] = {0};
uint8_t allegro[] = {0};
uint8_t musicType[] = {0};
uint8_t musicSelectionTable[] = {3,4,5,255,6,7,8,255};
uint8_t musicTrack[] = {0};
uint8_t vramRow[] = {0};
uint8_t rowY[] = {0};
uint8_t tetriminoY[] = {0};
uint8_t tetriminoX[] = {0};
uint8_t lineIndex[] = {0};
uint8_t completedRow[4] = {0};
uint8_t currentPiece[] = {0};
uint8_t nextPiece[] = {0};
uint8_t garbageLines[5] = {0,0,1,2,4};
uint8_t pendingGarbageInactivePlayer[] = {0};
uint8_t playState[] = {0};
uint8_t selectingLevelOrHeight[] = {0};
uint8_t curtainRow[] = {0};
uint8_t originalY[] = {0};
uint8_t newlyPressedButtons[] = {0};
uint8_t heldButtons[] = {0};
uint8_t autorepeatX[] = {0};
uint8_t autorepeatY[] = {0};
uint8_t dropSpeed[] = {0};
uint8_t fallTimer[] = {0};
uint8_t statsByType[14] = {0};
uint8_t tmp1[] = {0};
uint8_t tmp2[] = {0};
uint8_t tmp3[] = {0};
uint8_t rng_seed[] = {31,53};
uint8_t numberOfPlayers[] = {1};
uint8_t demoIndex[] = {0};
uint8_t spawnCount[] = {0};
uint8_t spawnID[] = {0};
uint8_t twoPlayerPieceDelayCounter[] = {0};
uint8_t twoPlayerPieceDelayPiece[] = {0};
uint8_t twoPlayerPieceDelayPlayer[] = {0};
uint8_t activePlayer[] = {0};
uint8_t frameCounter[] = {0,0};
uint8_t leftColums[] = {4,3,2,1,0};
uint8_t rightColums[] = {5,6,7,8,9};
uint8_t demoVarAtD0[] = {0};
uint8_t demo_heldButtons[] = {0};
uint8_t demo_repeats[] = {0};
uint8_t heldButtons_player1[] = {0};
uint8_t newlyPressedButtons_player1[] = {0};
uint8_t player1_vramRow[] = {0};
uint8_t player2_vramRow[] = {0};
uint8_t player1_startHeight[] = {0};
uint8_t player2_startHeight[] = {0};
uint8_t typeBBlankInitCountByHeightTable[] = {0xC8,0xAA,0x96,0x78,0x64,0x50};
uint8_t rngTable[] = {0xEF,0x7B,0xEF,0x7C,0x7D,0x7D,0xEF,0xEF};
uint16_t PPUADDR[] = {0};
uint8_t vram[0x4000] = {0}; //hope mirrioring is not needed!! Physical size 2048
uint8_t orientationTable[] = {0x00,0x7B,0xFF,0x00,0x7B,0x00,0x00,0x7B,
                                    0x01,0xFF,0x7B,0x00,0xFF,0x7B,0x00,0x00,
                                    0x7B,0x00,0x00,0x7B,0x01,0x01,0x7B,0x00,
                                    0x00,0x7B,0xFF,0x00,0x7B,0x00,0x00,0x7B,
                                    0x01,0x01,0x7B,0x00,0xFF,0x7B,0x00,0x00,
                                    0x7B,0xFF,0x00,0x7B,0x00,0x01,0x7B,0x00,
                                    0xFF,0x7D,0x00,0x00,0x7D,0x00,0x01,0x7D,
                                    0xFF,0x01,0x7D,0x00,0xFF,0x7D,0xFF,0x00,
                                    0x7D,0xFF,0x00,0x7D,0x00,0x00,0x7D,0x01,
                                    0xFF,0x7D,0x00,0xFF,0x7D,0x01,0x00,0x7D,
                                    0x00,0x01,0x7D,0x00,0x00,0x7D,0xFF,0x00,
                                    0x7D,0x00,0x00,0x7D,0x01,0x01,0x7D,0x01,
                                    0x00,0x7C,0xFF,0x00,0x7C,0x00,0x01,0x7C,
                                    0x00,0x01,0x7C,0x01,0xFF,0x7C,0x01,0x00,
                                    0x7C,0x00,0x00,0x7C,0x01,0x01,0x7C,0x00,
                                    0x00,0x7B,0xFF,0x00,0x7B,0x00,0x01,0x7B,
                                    0xFF,0x01,0x7B,0x00,0x00,0x7D,0x00,0x00,
                                    0x7D,0x01,0x01,0x7D,0xFF,0x01,0x7D,0x00,
                                    0xFF,0x7D,0x00,0x00,0x7D,0x00,0x00,0x7D,
                                    0x01,0x01,0x7D,0x01,0xFF,0x7C,0x00,0x00,
                                    0x7C,0x00,0x01,0x7C,0x00,0x01,0x7C,0x01,
                                    0x00,0x7C,0xFF,0x00,0x7C,0x00,0x00,0x7C,
                                    0x01,0x01,0x7C,0xFF,0xFF,0x7C,0xFF,0xFF,
                                    0x7C,0x00,0x00,0x7C,0x00,0x01,0x7C,0x00,
                                    0xFF,0x7C,0x01,0x00,0x7C,0xFF,0x00,0x7C,
                                    0x00,0x00,0x7C,0x01,0xFE,0x7B,0x00,0xFF,
                                    0x7B,0x00,0x00,0x7B,0x00,0x01,0x7B,0x00,
                                    0x00,0x7B,0xFE,0x00,0x7B,0xFF,0x00,0x7B,
                                    0x00,0x00,0x7B,0x01,0x00,0xFF,0x00,0x00,
                                    0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00};
uint8_t demoTetriminoTypeTable[] = {0x00,0x14,0x8A,0x45,0x22,0x11,0x88,0x44,
                                        0x22,0x91,0x48,0xA4,0x52,0x29,0x14,0x0A,
                                        0x85,0xC2,0xE1,0x70,0x38,0x9C,0x4E,0xA7,
                                        0x53,0xA9,0xD4,0x6A,0xB5,0x5A,0xAD,0xD6,
                                        0x6B,0x35,0x1A,0x8D,0xC6,0xE3,0x71,0x38,
                                        0x9C,0xCE,0xE7,0x73,0xB9,0xDC,0xEE,0xF7,
                                        0xFB,0xFD,0xFE,0x7F,0x3F,0x9F,0xCF,0x67,
                                        0x33,0x19,0x0C,0x86,0x43,0x21,0x90,0xC8,
                                        0xE4,0xF2,0xF9,0x7C,0xBE,0x5F,0xAF,0xD7,
                                        0xEB,0xF5,0xFA,0xFD,0x7E,0x3F,0x1F,0x0F,
                                        0x07,0x03,0x81,0xC0,0x60,0xB0,0xD8,0xEC,
                                        0xF6,0x7B,0x3D,0x1E,0x8F,0xC7,0xE3,0xF1,
                                        0x78,0xBC,0xDE,0xEF,0x77,0x3B,0x1D,0x8E,
                                        0xC7,0xE3,0xF1,0xF8,0xFC,0xFE,0x7F,0xBF,
                                        0x5F,0x2F,0x17,0x8B,0xC5,0x62,0x31,0x98,
                                        0xCC,0xE6,0x73,0x39,0x9C,0x4E,0x27,0x93,
                                        0xC9,0x64,0xB2,0x59,0x2C,0x16,0x0B,0x05,
                                        0x82,0xC1,0x60,0xB0,0x58,0x2C,0x96,0x4B,
                                        0xA5,0xD2,0xE9,0x74,0x3A,0x9D,0x4E,0x27,
                                        0x13,0x89,0xC4,0x62,0xB1,0xD8,0x6C,0xB6,
                                        0x5B,0x2D,0x16,0x8B,0x45,0x22,0x91,0x48,
                                        0xA4,0xD2,0xE9,0xF4,0xFA,0xFD,0xFE,0xFF,
                                        0xFF,0xFF,0x7F,0xBF,0xDF,0x6F,0xB7,0x5B,
                                        0x2D,0x96,0x4B,0x25,0x92,0x49,0xA4,0xD2,
                                        0x69,0x34,0x9A,0x4D,0x26,0x13,0x89,0x44,
                                        0xA2,0xD1,0x68,0xB4,0x5A,0x2D,0x96,0xCB,
                                        0xE5,0xF2,0xF9,0x7C,0x3E,0x1F,0x8F,0x47,
                                        0x23,0x91,0xC8,0x64,0x32,0x19,0x8C,0xC6,
                                        0x63,0x31,0x18,0x0C,0x06,0x03,0x81,0x40,
                                        0xA0,0xD0,0x68,0x34,0x1A,0x0D,0x86,0xC3,
                                        0x78,0xBC,0xDE,0xEF,0x77,0x3B,0x1D,0x8E,
                                        0xC7,0xE3,0xF1,0xF8,0xFC,0xFE,0x7F,0xBF};
uint8_t rotationTable[]= {0x03,0x01,0x00,0x02,0x01,0x03,0x02,0x00,
                                0x07,0x05,0x04,0x06,0x05,0x07,0x06,0x04,
                                0x09,0x09,0x08,0x08,0x0A,0x0A,0x0C,0x0C,
                                0x0B,0x0B,0x10,0x0E,0x0D,0x0F,0x0E,0x10,
                                0x0F,0x0D,0x12,0x12,0x11,0x11};
uint8_t framesPerDropTable[] = {0x30,0x2B,0x26,0x21,0x1C,0x17,0x12,0x0D,
                                        0x08,0x06,0x05,0x05,0x05,0x04,0x04,0x04,
                                        0x03,0x03,0x03,0x02,0x02,0x02,0x02,0x02,
                                        0x02,0x02,0x02,0x02,0x02,0x01};
uint8_t tetriminoTypeFromOrientation[]= {0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,
                                                0x02,0x02,0x03,0x04,0x04,0x05,0x05,0x05,
                                                0x05,0x06,0x06};
uint8_t spawnOrientationFromOrientation[] = {0x02,0x02,0x02,0x02,0x07,0x07,0x07,0x07,
                                                    0x08,0x08,0x0A,0x0B,0x0B,0x0E,0x0E,0x0E,
                                                    0x0E,0x12,0x12};
uint8_t spawnTable[] = {0x02,0x07,0x08,0x0A,0x0B,0x0E,0x12,0x02};
uint8_t colorTable [] = {0x0F,0x30,0x21,0x12,0x0F,0x30,0x29,0x1A,
                        0x0F,0x30,0x24,0x14,0x0F,0x30,0x2A,0x12,
                        0x0F,0x30,0x2B,0x15,0x0F,0x30,0x22,0x2B,
                        0x0F,0x30,0x00,0x16,0x0F,0x30,0x05,0x13,
                        0x0F,0x30,0x16,0x12,0x0F,0x30,0x27,0x16};//has out of bounds reads; causes bugged colors
uint8_t pieceToPpuStatAddr [] = {0x21,0x86,0x21,0xC6,0x22,0x06,0x22,0x46,
                                0x22,0x86,0x22,0xC6,0x23,0x06}; //these 4 are next to each other
uint8_t levelDisplayTable [] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
                                0x08,0x09,0x10,0x11,0x12,0x13,0x14,0x15,
                                0x16,0x17,0x18,0x19,0x20,0x21,0x22,0x23,
                                0x24,0x25,0x26,0x27,0x28,0x29,};//these 4 are next to each other
uint8_t multBy10Table [] = {0x00,0x0A,0x14,0x1E,0x28,0x32,0x3C,0x46,
                            0x50,0x5A,0x64,0x6E,0x78,0x82,0x8C,0x96,
                            0xA0,0xAA,0xB4,0xBE};//these 4 are next to each other
uint8_t vramPlayfieldRows [] = {0x20,0xC6,0x20,0xE6,0x21,0x06,0x21,0x26,
                                0x21,0x46,0x21,0x66,0x21,0x86,0x21,0xA6,
                                0x21,0xC6,0x21,0xE6,0x22,0x06,0x22,0x26,
                                0x22,0x46,0x22,0x66,0x22,0x86,0x22,0xA6,
                                0x22,0xC6,0x22,0xE6,0x23,0x06,0x23,0x26};//these 4 are next to each other


//registers
uint8_t accumulator[] = {0};
uint8_t registerX[] = {0};
uint8_t registerY[] = {0};

#include "nestetrishelperfunctionsuint8_t.c"
#include "nestetrisclockcyclesuint8_t.h"

int calculate_score_with_clockcycles_and_mods(uint8_t level, uint8_t completedLines, uint8_t* score, Modifications modification){
    int count_clockcycles = 16; //Setup the loop
    for(int i = 0; i <= level; i++) {
        unsigned points[2];
        count_clockcycles += 21;
		points[0] = pointsTable[2 * completedLines];
		score[0] += points[0];
		if (score[0] > 0x9F) { //upper digit of score > 9
            count_clockcycles +=7;
			score[0] -= 0xA0;
			score[1]++;
		}else{
		    count_clockcycles +=3;
		}
		points[1] = pointsTable[2 * completedLines + 1];
		count_clockcycles +=18;
		score[1] += points[1];
		if ((score[1] & 0x0F) > 9) {
            count_clockcycles +=12;
			score[1] -= 10;
			score[1] += 0x10;
		}else{
            count_clockcycles +=3;
		}
		count_clockcycles +=7;
		if (score[1] > 0x9F) {
            count_clockcycles +=17;
			score[1] -= 0xA0;
			score[2]++;
        }else{
            count_clockcycles +=3;
        }
        count_clockcycles +=7;
        if ((score[2] & 0x0F) > 9) {
            count_clockcycles +=12;
			score[2] -= 10;
			score[2] += 0x10;
		}else{
            count_clockcycles +=3;
		}
        if(modification==UNMODIFIED){
            count_clockcycles +=7;
            if (score[2] > 0x99) {
                count_clockcycles +=13;
                score[0] = 0x99;
                score[1] = 0x99;
                score[2] = 0x99;
                }else{
                    count_clockcycles +=3;
                }
        }
        if(modification==SEVENDIGITS){
            count_clockcycles +=7;
            if (score[2] > 0x99) {
            count_clockcycles +=13;
            score[2] -= 0xA0;
            score[3]++;// this is actually located at adress 0x15!
            }else{
                count_clockcycles +=3;
            }
        }
        if(modification==MAXOUTCODE){
            count_clockcycles +=7;
            if (score[2] > 0xFA) {
                count_clockcycles +=13;
                score[0] = 0x99;
                score[1] = 0x99;
                score[2] = 0x99;
           }else{
               count_clockcycles +=3;
            }
        }
        if(modification==ENEOOGEZ){
            count_clockcycles +=7;
            if (score[2] >= 0xF0) { //other game genie code!!!
                count_clockcycles +=13;
                score[0] = 0x99;
                score[1] = 0x99;
                score[2] = 0x99;
           }else{
               count_clockcycles +=3;
            }
        }
        if(modification==CRASHFIX){
            count_clockcycles +=3;
        }
        count_clockcycles +=8;
    }
    return count_clockcycles +2;
}

int update_level_with_clockcycles(int lines_cleared){
    int count_clockcycles = 0;
    for(int i=0;i<lines_cleared;i++){
        count_clockcycles += 12;
        cleared_lines[0]++;
        if((cleared_lines[0] & 0x0F) > 9){
            count_clockcycles +=9;
            cleared_lines[0] += 6; //adding 6 to convert from Hex to Dec
        }else{
            count_clockcycles += 3;
        }
        count_clockcycles += 7;
        if((cleared_lines[0] & 0xF0) > 0x90){
            count_clockcycles += 15;
            cleared_lines[0] -= 0xA0;
            cleared_lines[1]++;
        }else{
            count_clockcycles += 3;
        }
        count_clockcycles += 5;
        if((cleared_lines[0] & 0x0F) == 0){
            count_clockcycles += 55;
            uint8_t level = (cleared_lines[0] >> 4);
            level = level | (cleared_lines[1] << 4);
            uint8_t difference = (uint8_t)(*current_level) - (uint8_t)level;
            difference=difference & 0x80;
            if(difference == 0x80){
                count_clockcycles += 7;
                current_level[0]++;
            }else{
                count_clockcycles += 3;
            }
        }else{
            count_clockcycles += 3;
        }
        *soundEffectSlot1Init = 6;
        *outOfDateRenderFlags = *outOfDateRenderFlags | 2;
        count_clockcycles += 22;
    }
    return count_clockcycles;
}

int playState_updateLinesAndStatistics_with_clockcycles_and_mods(Modifications modification){
    int clockcycles = 0;
    //completedlines is in the acuumulator!
    updateMusicSpeed();
    lineClearStatsByType[*completedLines-1]++;
    int8_t temp = lineClearStatsByType[*completedLines-1] & 15; //signed int8_t!
    clockcycles += 22;
    if(temp==10){
        lineClearStatsByType[*completedLines-1] += 6;
        clockcycles += 12;
    }else{
        clockcycles++;
    }
    *outOfDateRenderFlags = *outOfDateRenderFlags | 4;
    clockcycles += 13;
    if(*gameType!=0){//gamemode not A!
        *generalCounter = *completedLines;//is Total correct?, shouldn't be
        clockcycles += 19;
        cleared_lines[0] = cleared_lines[0] - *generalCounter;
        if(cleared_lines[0] > 127){ // cleared_lines[0] <0 with signed numbers
            cleared_lines[0] = 0;
            clockcycles += 5;
        }else{
            clockcycles += 5;
            temp = cleared_lines[0] & 15;
            if(temp<10){
                //break out of the 2 outer it statements
            }else{
                cleared_lines[0] = cleared_lines[0] - 6;
                clockcycles += 13;
            }
        }
    }else{
        clockcycles += 4;
        clockcycles += update_level_with_clockcycles(*completedLines);
    }
    temp = *holdDownPoints;
    clockcycles += 7;
    if(temp-2 >= 0){//??? WHAT !!! ARE PUSHDOWN POINTS F*D?
        clockcycles += 19;
        current_score[0]--;
        current_score[0] += temp;
        uint8_t temp2 = current_score[0] & 15; //unsigned!!!
        if(temp2-10 >= 0){
            clockcycles += 10;
            current_score[0] += 6;
        }else{
            clockcycles++;
        }
        clockcycles += 9;
        temp2 = current_score[0] & 0xF0; //unsigned!!!
        if(temp2-0xA0 >= 0){
            clockcycles += 12;
            current_score[0] += 0x60;
            current_score[1]++;
        }else{
            clockcycles++;
        }
        *outOfDateRenderFlags = *outOfDateRenderFlags | 4;
        clockcycles += 8;
    }else{
        clockcycles++;
    }
    *holdDownPoints=0;
    clockcycles += 5;
    clockcycles += calculate_score_with_clockcycles_and_mods(*current_level, *completedLines, current_score, modification);
    return clockcycles;
}

int updateMusicSpeed(){
    int clockcycles = 10;
    int8_t counter=10;
    int8_t offset=50;
    do{
        clockcycles += 9;
        if(playFieldAddr[0][offset] != 0xEF){
            clockcycles += 1;
            if(*allegro == 0){
                clockcycles += 24;
                *allegro = 0xFF;
                clockcycles += setMusicTrack(musicSelectionTable[*musicType + 4]);
                clockcycles += 3;
            }else{
                clockcycles += 1;
            }
            clockcycles += 6;
            return clockcycles;
        }
        offset++;
        counter--;
        clockcycles += 7;
    }while(counter > 0);
    clockcycles += 4; //last jump did not happen!
    if(*allegro != 0){
        clockcycles += 18;
        *allegro = 0;
        clockcycles+=setMusicTrack(musicSelectionTable[*musicType]);

        clockcycles += 3;
    }else{
        clockcycles += 1;
    }
    clockcycles += 6;
    return clockcycles;
}

int setMusicTrack(uint8_t number){
    int clockcycles = 11;
    *musicTrack = number;
    if(*gameMode == 5){
        *musicTrack = 255;
        clockcycles += 6;
    }else{
        clockcycles += 1;
    }
    return clockcycles+6;
}

int updatePlayfield(){
    //printf("Should LOCK\r\n");
    int clockcycles = 11;
    uint8_t a = *tetriminoY - 2;
    // the x register is set to the same value as the accumulator!
    if(*tetriminoY - 2 <= 0){
        a = 0;
        clockcycles += 2;
    }else{
        clockcycles += 1;
    }
    clockcycles += 5;
    if(a <= *vramRow){
        *vramRow = a;
        clockcycles += 3;
    }else{
        clockcycles += 1;
    }
    return clockcycles + 6;
}

int playState_checkForCompletedRows(){
    int clockcycles = 7;
    if(*vramRow < 20){
        clockcycles += 9;
        uint8_t temp;
        if(*tetriminoY >= 2){
            clockcycles += 1;
            temp = *tetriminoY-2;
        }else{
            clockcycles += 2;
            temp = 0;
        }

        clockcycles += 27;
        *generalCounter2 = temp + *lineIndex;
        *generalCounter = (*generalCounter2) << 1;
        *generalCounter = *generalCounter + ((*generalCounter) << 2); // multiplying by 10 with bitshifts when you have a lookup table for that BRUH
        uint8_t y = *generalCounter;//y register
        uint8_t x = 10;//x regsiter
        bool lineCompleted_h = true;
        do{
            clockcycles += 9;
            //printf("Cell: %X y: %i\r\n",playFieldAddr[0][y],y);
            if(playFieldAddr[0][y]==0xEF){
                clockcycles += 10;
                completedRow[*lineIndex] = 0;
                lineCompleted_h=false;
            }
            y++;
            x--;
            clockcycles += 7;
        }while(x>0);
        if(lineCompleted_h == true){
            clockcycles += 22;//last jump did not happen!
            *soundEffectSlot1Init = 10; // not in Zeropage
            (*completedLines)++;
            completedRow[*lineIndex] = *generalCounter2;
            y = *generalCounter;
            y--;
            do{
                playFieldAddr[0][(uint8_t)(y+10)]= playFieldAddr[0][y];//playfieldAddr is modified during that process idk how to represent that in C!
                y--;
                clockcycles += 28;
            }while(y != 255); //overflow!
            clockcycles += 3;//last jump did not happen!
            for(int8_t i=0;i<10;i++){
                playFieldAddr[0][i]=0xEF;
                clockcycles += 13;
            }
            clockcycles += 7;//last jump did not happen!
            *currentPiece = 19;
        }
        (*lineIndex)++;
        clockcycles += 12;
        if(*lineIndex > 4){
            clockcycles += 31;
            *pendingGarbageInactivePlayer = *pendingGarbageInactivePlayer + garbageLines[(*completedLines)];
            *rowY = 0;
            *vramRow = 0;
            if(*completedLines >= 4){
                *soundEffectSlot1Init=4;
                clockcycles += 6;
            }else{
                clockcycles += 1;
            }
            clockcycles += 10;
            *playState = *playState + 1;
            if(completedLines != 0){
                clockcycles += 11;
                (*playState)++;
                *soundEffectSlot1Init=7;
            }else{
                clockcycles += 1;
            }
        }else{
            clockcycles += 1;
        }
    }else{
        clockcycles += 3;
    }
    return clockcycles+6;
}

int isPositionValid(){
    int clockcycles = 49;
    *generalCounter = *tetriminoY << 1;
    *generalCounter = (*generalCounter << 2) + *generalCounter + *tetriminoX;
    *generalCounter2 = *currentPiece << 2;
    uint8_t x = *generalCounter2 + (*generalCounter2 << 1);
    *generalCounter3 = 4;
    uint8_t y=0;
    do{
        clockcycles += 15;
        //uint8_t is converted to int -->  does not wrap around at 256!!!
        uint8_t temp = (uint8_t)(orientationTable[x] + *tetriminoY);
        if(temp >= -2 && temp  < 20 || temp == 255 || temp ==  254){ // WHY + 2 and then compare with 22 ??
            *generalCounter4 = orientationTable[x] << 1;
            *selectingLevelOrHeight = *generalCounter + *generalCounter4 + (*generalCounter4 << 2);
            x += 2;
            y = orientationTable[x] + *selectingLevelOrHeight;
            clockcycles += 50;
            if(playFieldAddr[0][y] >= 0xEF){//!= ???
                clockcycles += 13;
                if((int8_t)(orientationTable[x] + *tetriminoX) < 10 && (int8_t)(orientationTable[x] + *tetriminoX) >= 0){
                    x++;
                    (*generalCounter3)--;
                    clockcycles += 10;
                }else{
                    *generalCounter = 255;
                    *accumulator = 255;
                    return clockcycles + 12;
                }
            }else{
                *generalCounter = 255;
                *accumulator = 255;
                return clockcycles + 12;
            }

        }else{
            *generalCounter = 255;
            *accumulator = 255;
            return clockcycles + 12;
        }
    }while(*generalCounter3 != 0);
    *generalCounter = 0;
    *accumulator = 0;
    return clockcycles + 10;
}

int playState_lockTetrimino(){
    int clockcycles = 6;
    clockcycles += isPositionValid();
    clockcycles += 2;
    if(*accumulator == 0){
        clockcycles += 8;
        if(*vramRow >= 20){
            *generalCounter = *tetriminoY << 1;
            *generalCounter = *generalCounter + *tetriminoX + (*generalCounter << 2);
            *generalCounter2 = *currentPiece << 2;
            uint8_t x = *generalCounter2 + (*generalCounter2 << 1);
            uint8_t y = 0;
            *generalCounter3 = 4;
            clockcycles += 49;
            do{
                *generalCounter4 = orientationTable[x]<<1;
                *selectingLevelOrHeight = *generalCounter4 + (*generalCounter4 << 2) + *generalCounter;
                x++;
                *generalCounter5 = orientationTable[x];
                x++;
                y = orientationTable[x] + *selectingLevelOrHeight;
                playFieldAddr[0][y] = *generalCounter5;
                x++;
                (*generalCounter3)--;
                clockcycles += 66;
            }while(*generalCounter3>0);
            *lineIndex = 0;
            clockcycles += 10; //last jump doesnt happen !
            clockcycles += updatePlayfield();
            clockcycles += updateMusicSpeed();
            clockcycles += 11;
            (*playState)++;
        }else{
            return clockcycles += 7;
        }
    }else{
        *soundEffectSlot0Init = 2;
        *playState = 10;
        *curtainRow = 0xF0;
        //clockcycles += updateAudio2(); // not yet implmented
        clockcycles += 22;
    }
    return clockcycles + 6;
}

int playState_playerControlsActiveTetrimino(){
    /*if(*fallTimer == *dropSpeed){
        if(isPositionValid_h(*tetriminoY+1)==false){
            *vramRow = 19; //hackfix for some problem where pieces can be moved out last frame even if it should lock
            return 0; //!!!
        }else{
            uint8_t xtemp = *tetriminoX;
            int clockcycles = 6;
            clockcycles += shift_tetrimino();
            clockcycles += 6;
            clockcycles += rotate_tetrimino();
            if(isPositionValid_h(*tetriminoY+1)==false){
                //hackfix for some problem where pieces can be moved out last frame even if it should lock
                (*tetriminoY)++;
                *tetriminoX = xtemp;
                *fallTimer = 0;
                return clockcycles;
            }
            clockcycles += 6;
            clockcycles += drop_tetrimino();
            return clockcycles + 6;
        }

    }else{*/
        int clockcycles = 6;
        clockcycles += shift_tetrimino();
        clockcycles += 6;
        clockcycles += rotate_tetrimino();
        clockcycles += 6;
        clockcycles += drop_tetrimino();
        return clockcycles + 6;
    //}
}

int drop_tetrimino(){
    int clockcycles = 5;
    bool notBeginningOfGame_h = false;
    bool lookupDropSpeed_h = false;
    if((int8_t)*autorepeatY < (int8_t) 0){
        clockcycles += 7;
        if((uint8_t)(*newlyPressedButtons & (uint8_t)4) != (uint8_t)0){
            *autorepeatY = 0;
            clockcycles += 5;
            notBeginningOfGame_h = true;
        }else{
            (*autorepeatY)++;
            clockcycles += 9;
        }
    }else{
        clockcycles += 1;
        notBeginningOfGame_h = true;
    }
    if(notBeginningOfGame_h == true){
        clockcycles += 2;
        if((uint8_t)*autorepeatY == (uint8_t)0){
            clockcycles += 7;
            if((uint8_t)(*heldButtons & (uint8_t)3) == (uint8_t)0){
                if((uint8_t)(*newlyPressedButtons & (uint8_t)15) == (uint8_t)4){
                    *autorepeatY = 1;
                    clockcycles += 5;
                    lookupDropSpeed_h = true;
                }else{
                    clockcycles += 1;
                    lookupDropSpeed_h = true;
                }
            }else{
                clockcycles += 1;
                lookupDropSpeed_h = true;
            }
        }else{
            clockcycles += 10;
            if((uint8_t)(*heldButtons & (uint8_t)15) != (uint8_t)4){
                *autorepeatY = 0;
                *holdDownPoints = 0;
                lookupDropSpeed_h = true;
            }else{
                clockcycles += 14;
                (*autorepeatY)++;
                if((uint8_t)*autorepeatY >= (uint8_t)3){
                    *autorepeatY = 1;
                    (*holdDownPoints)++;
                    clockcycles += 10;
                    *fallTimer=-1;
                    *originalY = *tetriminoY;
                    (*tetriminoY)++;
                    clockcycles += 22;
                    clockcycles += isPositionValid();
                    if(*accumulator != 0){
                        *tetriminoY = *originalY;
                        *playState = 2;
                        clockcycles += 17;
                        clockcycles += updatePlayfield();
                    }else{
                        clockcycles += 1;
                    }
                }else{
                    clockcycles += 1;
                    lookupDropSpeed_h = true;
                }
            }
        }
    }
    //printf("Dropspeed: %i\tFalltimer: %i\tautorepeatY: %i\r\n",*dropSpeed,*fallTimer,*autorepeatY);
    if(lookupDropSpeed_h == true){
        clockcycles += 9;
        if(*current_level <= 29){
            clockcycles += 4;
            *dropSpeed = framesPerDropTable[*current_level];
        }else{
            clockcycles += 1;
            *dropSpeed = 1;
        }
        clockcycles += 11;
        if(*fallTimer < *dropSpeed){//should that be < ???
            clockcycles += 3;
        }else{
            clockcycles += 1;
            //@drop
            *fallTimer=0;
            *originalY = *tetriminoY;
            (*tetriminoY)++;
            clockcycles += 22;
            clockcycles += isPositionValid();
            if(*accumulator != 0){
                *tetriminoY = *originalY;
                *playState = 2;
                clockcycles += 17;
                clockcycles += updatePlayfield();
            }else{
                clockcycles += 1;
            }
        }
    }
    return clockcycles + 6;
}

int shift_tetrimino(){
    int clockcycles = 13;
    *originalY = *tetriminoX;
    bool buttonHeldDown_h = false;
    if((uint8_t)(*heldButtons & (uint8_t)0x04) == (uint8_t)0){//is down not pressed
        clockcycles += 7;
        if((uint8_t)(*newlyPressedButtons & (uint8_t)0x3) == (uint8_t)0){//was left or right pressed
            clockcycles += 7;
            if((uint8_t)(*heldButtons & (uint8_t)0x3) != (uint8_t)0){
                (*autorepeatX)++;
                clockcycles += 12;
                if(*autorepeatX >= 16){
                    *autorepeatX = 10; //has to be 10!
                    clockcycles += 11;
                    buttonHeldDown_h =  true;
                }else{
                    clockcycles += 1;
                }
            }else{
                clockcycles += 4;
            }
        }else{
            clockcycles += 6;
            *autorepeatX = 1; //should be 0 ???
            buttonHeldDown_h = true;
        }
    }else{
        clockcycles += 1;
    }
    if(buttonHeldDown_h == true){
        clockcycles += 7;
        if((uint8_t)(*heldButtons & (uint8_t)1) != (uint8_t)0){
            (*tetriminoX)++;
            clockcycles += 11;
            clockcycles += isPositionValid();
            if(*accumulator == 0){
                *soundEffectSlot1Init == 3;
                clockcycles += 9;
            }else{
                clockcycles += 1;
                *tetriminoX = *originalY;
                *autorepeatX = 16;
                clockcycles += 11;
            }
        }else{
            clockcycles += 7;
            if((uint8_t)(*heldButtons & (uint8_t)2) != (uint8_t)0){
                (*tetriminoX)--;
                clockcycles += 11;
                clockcycles += isPositionValid();
                if(*accumulator == 0){
                    *soundEffectSlot1Init == 3;
                    clockcycles += 9;
                }else{
                    clockcycles += 1;
                    *tetriminoX = *originalY;
                    *autorepeatX = 16;
                    clockcycles += 11;
                }
            }else{
                clockcycles += 1;
            }
        }
    }
    return clockcycles + 6;
}

int rotate_tetrimino(){
    int clockcycles = 24;
    *originalY = *currentPiece;
    uint8_t x = *currentPiece << 1;
    if((uint8_t)(*newlyPressedButtons & (uint8_t)0x80) == (uint8_t)0x80){
        x++;
        *currentPiece = rotationTable[x];
        *accumulator = *currentPiece;
        clockcycles += isPositionValid();
        clockcycles += 14;
        if(*accumulator == 0){
            clockcycles += 9;
            *soundEffectSlot1Init = 5;
        }else{
            clockcycles += 7;
            *currentPiece = *originalY;
        }
    }else{
        clockcycles += 10;
        if((uint8_t)(*newlyPressedButtons & (uint8_t)0x40) == (uint8_t)0x40){
            *currentPiece = rotationTable[x];
            *accumulator = *currentPiece;
            clockcycles += 13;
            clockcycles += isPositionValid();
            if(*accumulator == 0){
                *soundEffectSlot1Init = 5;
                clockcycles += 5;
            }else{
                clockcycles += 7;
                *currentPiece = *originalY;
            }
        }else{
            clockcycles += 1;
        }
    }

    return clockcycles + 6;
}

int incrementPieceStat(){
    int clockcycles = 27;
    *generalCounter=statsByType[tetriminoTypeFromOrientation[*accumulator]*2] + 1;
    if((uint8_t)(*generalCounter & (uint8_t)15) >= (uint8_t)10){
        clockcycles += 14;
        *generalCounter += 6;
        if(*generalCounter & 0xF0 >= 0xA0){
            *generalCounter += (uint8_t)0x60;
            statsByType[tetriminoTypeFromOrientation[*accumulator]*2 + 1]++;
            clockcycles += 19;
        }else{
            clockcycles += 1;
        }
    }else{
        clockcycles +=1;
    }
    clockcycles += 15;
    statsByType[tetriminoTypeFromOrientation[*accumulator]*2] = *generalCounter;
    *outOfDateRenderFlags = *outOfDateRenderFlags | 0x40;
    return clockcycles + 6;
}

int generateNextPseudorandomNumber(){
    int clockcycles = 0;
    *tmp1 = rng_seed[0] & 2;
    uint8_t a = (rng_seed[1] & (uint8_t)2) ^ *tmp1;
    clockcycles += 22;
    uint8_t carry;
    if(a!=0){
        carry = 1;
        clockcycles += 2;
    }else{
        clockcycles += 1;
        carry = 0;
    }
    for(int8_t i = 0; i < 2; i++){
        uint8_t carry_new = rng_seed[i] & 1;
        rng_seed[i] = (uint8_t)(rng_seed[i] >> 1) | (uint8_t)(carry << 7);
        carry = carry_new;
        clockcycles += 12;
    }
    return clockcycles + 5; //last jump does not happen
}

int chooseNextTetrimino(){
    int clockcycles = 7;
    if(*gameMode == 5){
        clockcycles += 28;
        *accumulator = demoTetriminoTypeTable[*demoIndex];
        (*demoIndex)++;
        *accumulator = *accumulator >> 4;
        *accumulator = *accumulator & 7;
        *accumulator = spawnTable[*accumulator];
        return clockcycles + 6;
    }else{
        clockcycles += 6;
        clockcycles += realStart();
        return clockcycles + 6;
    }
    return clockcycles + 6;
}

int realStart(){
    int clockcycles = 19;
    (*spawnCount)++;
    *accumulator = (uint8_t)((uint8_t)(rng_seed[0] + *spawnCount) & 7);
    bool invalidIndex_h = false;
    if(*accumulator != 7){
        clockcycles += 10;
        if(spawnTable[*accumulator] == *spawnID){
            invalidIndex_h = true;
        }else{
            clockcycles += 4;
            *spawnID = spawnTable[*accumulator];
        }
    }else{
        clockcycles += 1;
        invalidIndex_h = true;
    }
    if(invalidIndex_h == true){
        clockcycles += 10;
        clockcycles += generateNextPseudorandomNumber();
        *accumulator = (rng_seed[0] & 7) + *spawnID;
        //*accumulator = rng_seed[0] & 7;
        while(true){
            clockcycles += 4;
            if(*accumulator >= 7){
                clockcycles += 7;
                *accumulator -= 7;
            }else{
                clockcycles+=1;
                break;
            }
        }
        *spawnID = spawnTable[*accumulator];
        *accumulator = *spawnID;
        clockcycles += 9;
    }
    *accumulator = *spawnID;
    return clockcycles + 6;
}

int playState_spawnNextTetrimino(){
    int clockcycles = 7;
    bool spawnPiece_h = false;
    if(*vramRow >= 20){
        clockcycles += 7;
        if(*numberOfPlayers != 1){
            clockcycles += 7;
            if(*twoPlayerPieceDelayCounter == 0){
                (*twoPlayerPieceDelayCounter)++;
                *twoPlayerPieceDelayPiece = *activePlayer;
                clockcycles += 12;
                clockcycles += chooseNextTetrimino();
                clockcycles += 6;
            }else{
                clockcycles += 7;
                if(*twoPlayerPieceDelayPlayer == *activePlayer){
                    //return
                }else{
                    clockcycles += 1;
                    if(*twoPlayerPieceDelayCounter == 0x1C){
                        //return
                    }else{
                        clockcycles += 1;
                        spawnPiece_h = true;
                    }
                }
            }
        }else{
            clockcycles += 1;
            spawnPiece_h = true;
        }
    }else{
        clockcycles += 1;
    }
    if(spawnPiece_h == true){
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
        if(*numberOfPlayers != 1){
            *nextPiece = *twoPlayerPieceDelayPiece;
            clockcycles += 9;
        }else{
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

int updateLineClearingAnimation(){
    int clockcycles = 7;
    if(frameCounter[0] % 4 == 0){
        *generalCounter3 = 0;
        clockcycles += 5;
        do{
            clockcycles += 5;
            if(completedRow[*generalCounter3] != 0){
                *generalCounter = vramPlayfieldRows[(uint8_t)completedRow[*generalCounter3]*2];//keep offset in the range of 255!
                clockcycles += 18;
                if(*numberOfPlayers == 1){
                    *generalCounter += 6;
                    clockcycles += 13;
                }else{
                    clockcycles += 7;
                    //if(playFieldAddr[1]==4)//should be true if the playfield adress was incremented by 4
                    if(true){//cannot be implemented because of pointer logic difference
                        *generalCounter -= 2;
                        clockcycles += 13;
                    }else{
                        *generalCounter += 12;
                        clockcycles += 14;
                    }
                    *generalCounter2 = vramPlayfieldRows[(uint8_t)completedRow[*generalCounter3]*2+1];
                    *PPUADDR = *generalCounter2 << 8;
                    clockcycles += 52;
                    *PPUADDR += leftColums[*rowY] + *generalCounter;
                    vram[*PPUADDR] = 0xFF;
                    *PPUADDR = *generalCounter2 << 8;
                    *PPUADDR += rightColums[*rowY] + *generalCounter;
                    vram[*PPUADDR] = 0xFF;
                }
            }else{
                clockcycles += 1;
            }
            clockcycles += 5;
            (*generalCounter3)++;
        }while(*generalCounter3 != 4);
        (*rowY)++;
        clockcycles += 11;//last jump does not happen
        if(*rowY>=5){//bmi ??!!
            (*playState)++;
        }else{
            clockcycles += 1;
        }
    }else{
        clockcycles += 1;
    }
    return clockcycles + 6;
}

int updatePaletteForLevel(){
    int clockcycles = 3;
    *accumulator = *player1_levelNumber;
    while((int8_t)(*accumulator - 10) > 0){//values over 128 are considered negative
        clockcycles += 11;
        *accumulator -= 10;
    }
    clockcycles += 12;
    *registerX = *accumulator << 2;
    *generalCounter = 0;
    do{
        *PPUADDR = 0x3F00;
        *PPUADDR += *generalCounter + 8;
        vram[*PPUADDR] = colorTable[*registerX];
        vram[*PPUADDR+1] = colorTable[*registerX+1];
        vram[*PPUADDR+2] = colorTable[*registerX+2];
        vram[*PPUADDR+3] = colorTable[*registerX+3];
        *PPUADDR += 4;//next index???
        *generalCounter += 16;
        clockcycles += 63;
    }while(*generalCounter != 32);
    return clockcycles + 5;//last jump did not happen
}

int twoDigsToPPU(){
    *generalCounter = *accumulator;//!!!
    *accumulator = * accumulator & 0xF0;
    vram[*PPUADDR] = *accumulator >> 4;
    (*PPUADDR)++;
    vram[*PPUADDR] = *accumulator & 0x0F;
    (*PPUADDR)++;
    return 32;
}

int copyPlayfieldRowToVRAM(){
    int clockcycles = 7;
    if((int8_t)*vramRow >= 21){
        clockcycles += 31;
        *registerY = multBy10Table[*vramRow];
        *PPUADDR = vramPlayfieldRows[(*vramRow << 1) + 1];
        if(*numberOfPlayers != 1){
            clockcycles += 7;
            //if(playfliedAddr[1] != 5){ //diffemt pointer logic!
            if(true){
                clockcycles += 12;
                *PPUADDR = vramPlayfieldRows[(uint8_t)((*vramRow) * 2 - 2)] << 8; //keep in 8 bit range! upper byte?
            }else{
                clockcycles += 13;
                *PPUADDR = vramPlayfieldRows[(uint8_t)((*vramRow) * 2 + 12)] << 8; //keep in 8 bit range! upper byte?
            }
            clockcycles += 5;
            for(int i=0;i<10;i++){
                vram[*PPUADDR] = playFieldAddr[0][*registerY+i];
                (*PPUADDR)++;
                clockcycles += 16;
            }
            clockcycles += 11; //last jump does not happen
            (*vramRow)++;
            if((int8_t)*vramRow < 20){
                clockcycles += 1;
            }else{
                *vramRow = 32;
                clockcycles += 5;
            }
        }else{
            clockcycles += 13;
            *PPUADDR = vramPlayfieldRows[(uint8_t)(*vramRow*2 + 6)]; //keep in 8 bit range!
        }
    }else{
        clockcycles += 1;
    }
    return clockcycles +6;
}

int demoButtonsTable_indexIncr(){
    demoButtons = demoButtons + 1;
    return 22;
}

int pollControllerButtons(){
    int clockcycles = 7;
    if(*gameMode != 5){
        clockcycles += 6;
        clockcycles += pollController();
    }else{
        clockcycles += 8;
        if(*demoVarAtD0 != 0xFF){
            clockcycles += pollController();
            clockcycles += 7;
            if(*newlyPressedButtons_player1 != 16){
                if(*demo_repeats != 0){
                    (*demo_repeats)--;
                    *newlyPressedButtons_player1 = 0;
                    clockcycles += 13;
                }else{
                    clockcycles += 17;
                    *generalCounter=demoButtonsAddr[0][0];
                    clockcycles += demoButtonsTable_indexIncr();
                    *newlyPressedButtons_player1 = *demo_heldButtons ^ *generalCounter;
                    *newlyPressedButtons_player1 = *newlyPressedButtons_player1 & *generalCounter;
                    *demo_heldButtons = *generalCounter;
                    *demo_repeats = demoButtonsAddr[0][0];
                    clockcycles += 35;
                    clockcycles += demoButtonsTable_indexIncr();
                    clockcycles += 7;
                    if(demoButtons - demoButtonsBase_h != 0xDF00){
                        clockcycles += 3;
                    }else{
                        clockcycles += 1;
                    }
                }
                *heldButtons_player1 = *demoButtons;
                clockcycles += 6;
            }else{
                clockcycles += 1;
                demoButtons = demoButtonsBase_h + 0xDD00;
                frameCounter[1] = 0;//framecounter is reset???
                *gameMode = 1;
                clockcycles += 15;
            }
        }else{
            clockcycles += 7;
            clockcycles += pollController();
            clockcycles += 7;
            if(*gameMode == 5){
                clockcycles += 7;
                if(*demoVarAtD0 == 0xFF){ //why does this compare exist?
                    clockcycles += 8;
                    if(*heldButtons_player1 != *demo_heldButtons){
                        clockcycles += 17;
                        demoButtonsAddr[0][0]=*demo_heldButtons;
                        clockcycles += demoButtonsTable_indexIncr();
                        clockcycles += 16;
                        demoButtonsAddr[0][0]=*demo_repeats;
                        clockcycles += demoButtonsTable_indexIncr();
                        clockcycles += 7;
                        if(((demoButtons-demoButtonsBase_h) & 0xFF00) != 0xDF){
                            *demo_heldButtons = *heldButtons_player1;
                            *demo_repeats = 0;
                            clockcycles = 11;
                        }else{
                            clockcycles += 1;
                        }
                    }else{
                        clockcycles += 6;
                        (*demo_repeats)++;
                    }
                }else{
                    clockcycles += 1;
                }
            }else{
                clockcycles += 1;
            }
        }
    }
    return clockcycles + 6;
}
int initPlayfieldIfTypeB(){
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
}

int playState_bTypeGoalCheck(){
    int clockcycles = 0;

    return clockcycles + 6;
}

int pollController(){ //not finished
    int clockcycles = 0;
    return clockcycles +6;
}

void runGame(Modifications modification){


    int digits;
    int clockcycles = 0;
    if(modification == SEVENDIGITS){
        digits = 7;
    }else{
        digits = 6;
    }
    FILE *filehandle;
    size_t length = 0;
    ssize_t read_length;

    int frame= 836;
    int limit = 4010;
    rng_seed[0]=0xEA;
    rng_seed[1]=0xA5;
    *currentPiece = 18;
    *nextPiece = 11;
    filehandle = fopen("Test2.fm2", "r");

    /*int frame= 676;
    int limit = 1900;
    rng_seed[0]=0x34;
    rng_seed[1]=0xBA;
    *currentPiece = 11;
    *nextPiece = 18;
    filehandle = fopen("FinalTest.fm2", "r");*/

    if (filehandle == NULL){
        exit(EXIT_FAILURE);
    }else{
        int8_t line[16];
        int counter = 1;
        int spawndelay = 0;
        bool paused = false;
        *tetriminoX = 5; // first piece was moved before game started
        *tetriminoY = 0;
        *autorepeatY = 0xA1; //before the start of the game
        *vramRow = 20;
        *heldButtons = 0;
        *newlyPressedButtons = 0;
        *fallTimer = 0;
        *autorepeatX = 0;
        *spawnCount = 2;
        *musicTrack = 3;
        statsByType[8]=1;
        bool lineclear_h = false;
        for(int i=0;i<frame;i++){// headers + frames to skip!
            if(fgets(line, sizeof(line), filehandle) == NULL){//skip the beginning lines
                exit(EXIT_FAILURE);
            }
        }
        *newlyPressedButtons = 0;
        uint8_t newlyPressedButtonstemp = 0;
        uint8_t heldButtonsOld;
        uint8_t newlyPressedButtonsOld;
        if(fgets(line, sizeof(line), filehandle) != NULL){
            for(int i=10;i>=3;i--){
                *newlyPressedButtons = *newlyPressedButtons*2;
                if(line[i]!='.'){
                    *newlyPressedButtons += 1;
                }
            }
            uint8_t input = *newlyPressedButtons;
            uint8_t temp = *heldButtons;
            heldButtonsOld = *newlyPressedButtons;
            newlyPressedButtonsOld = *newlyPressedButtons & (~temp);

        }else{
            exit(EXIT_FAILURE);
        }
        //frame++; //inputlag?
        while(fgets(line, sizeof(line), filehandle) != NULL) {
            newlyPressedButtonstemp = 0;
            *heldButtons = heldButtonsOld;
            *newlyPressedButtons = newlyPressedButtonsOld;
            uint8_t newlyPressedButtons_temp = 0;
            for(int i=10;i>=3;i--){
                newlyPressedButtons_temp = newlyPressedButtons_temp*2;
                if(line[i] != '.'){
                    newlyPressedButtons_temp += 1;
                }
            }
            uint8_t input = *newlyPressedButtons;
            uint8_t temp = *heldButtons;
            heldButtonsOld = newlyPressedButtons_temp;
            newlyPressedButtonsOld = newlyPressedButtons_temp & (~temp);
            frame++;
            if(frame>limit){
                break;
            }
            if(paused == false){
                if(frame >= limit-350){
                    printf("RNG:%X%X\tNew: %X\tHold: %X\tSpawndelay: %i\t%s",rng_seed[1],rng_seed[0],*newlyPressedButtons, *heldButtons,spawndelay,line);
                    print_playfield(digits,frame);
                }
                if((uint8_t)(input & (uint8_t)7) != (uint8_t)7){//check for r+l+d
                    //printf("Frame: %i\tnew: %i\theld: %i\tautorepeatY: %X\tFallTimer: %i\r\n",frame,*newlyPressedButtons,*heldButtons,*autorepeatY,*fallTimer);
                    if(spawndelay == 1){
                        //printf("RNG:%X%X\tNEXT PIECE!\r\n",rng_seed[1],rng_seed[0]);
                        clockcycles += generateNextPseudorandomNumber();
                        clockcycles += playState_spawnNextTetrimino();
                        lineclear_h = false;
                        spawndelay--;
                        //printf("Frame: %i\t Next Frame: piece Spawn\r\n",frame);
                    }else{

                            if(spawndelay == 0){
                                clockcycles += playState_playerControlsActiveTetrimino();
                                //printf("Frame: %i, vramrow: %i\r\n",frame,*vramRow);
                                *playState = 0;
                                if(*vramRow != 20){
                                    *vramRow = 20;
                                    clockcycles += playState_lockTetrimino();
                                    while(*playState < 2){
                                        clockcycles += playState_checkForCompletedRows();
                                    }
                                    *vramRow = 20;
                                    clockcycles += playState_updateLinesAndStatistics_with_clockcycles_and_mods(modification);
                                    *vramRow = 20;
                                    if(*completedLines != 0){
                                        spawndelay = 21;
                                        if(*tetriminoY > 17){
                                            spawndelay += 9 - ((frame + 3) % 4);
                                            if((frame + 3) % 4 == 0){
                                                spawndelay -= 4;
                                            }
                                        }else{
                                            if(*tetriminoY > 13){
                                                spawndelay += 11 - ((frame + 1) % 4);
                                                if((frame + 1) % 4 == 0){
                                                    spawndelay -= 4;
                                                }
                                            }else{
                                                if(*tetriminoY > 9){
                                                    spawndelay += 12 - ((frame+2) % 4);
                                                }else{
                                                    if(*tetriminoY > 5){
                                                        spawndelay += 13 - ((frame+2) % 4);
                                                    }else{
                                                        /*if(*tetriminoY > 1){
                                                            spawndelay += 14 - ((frame+1) % 4);
                                                        }else{*/
                                                            spawndelay += 11;
                                                            if((frame+1)%4 == 0){
                                                                spawndelay += 0;
                                                            }else{
                                                                spawndelay += (4-(frame+1)%4);
                                                            }
                                                        //}
                                                    }
                                                }
                                            }
                                        }
                                        /*spawndelay += 17;
                                        spawndelay += (4-(frame+3)%4);*/
                                        lineclear_h=true;
                                    }
                                    *completedLines = 0;
                                    counter++;
                                    if(lineclear_h==false){
                                        switch(*tetriminoY){
                                            case 0: spawndelay += 18; break; // ??? sould be 20?
                                            case 1: spawndelay += 18; break;
                                            case 2: spawndelay += 18; break;
                                            case 3: spawndelay += 18; break;
                                            case 4: spawndelay += 18; break;
                                            case 5: spawndelay += 18; break;
                                            case 6: spawndelay += 16; break;
                                            case 7: spawndelay += 16; break;
                                            case 8: spawndelay += 16; break;
                                            case 9: spawndelay += 16; break;
                                            case 10: spawndelay += 14; break;
                                            case 11: spawndelay += 14; break;
                                            case 12: spawndelay += 14; break;
                                            case 13: spawndelay += 14; break;
                                            case 14: spawndelay += 12; break;
                                            case 15: spawndelay += 12; break;
                                            case 16: spawndelay += 12; break;
                                            case 17: spawndelay += 12; break;
                                            case 18: spawndelay += 10; break;
                                            case 19: spawndelay += 10; break;
                                        }
                                        spawndelay += -1;
                                    }
                                }
                                (*fallTimer)++;
                                generateNextPseudorandomNumber();
                            }else{
                                generateNextPseudorandomNumber(); //update RNG
                                spawndelay--;
                            }

                    }
                }else{
                    generateNextPseudorandomNumber(); //pressing left+right+down lags the game for 1 frame!
                }
            }else{
                generateNextPseudorandomNumber(); //game is paused
            }
            if(*curtainRow == 0xF0){
                print_playfield(digits,frame);
                break;
            }
            if((uint8_t)(*newlyPressedButtons & (uint8_t)32) == (uint8_t)32){
                if(paused == false){
                    paused = true;
                    //printf("Game unpaused\r\n");
                }else{
                    paused = false;
                    //printf("Game unpaused\r\n");
                }
            }
        }
    }
    fclose(filehandle);
}

void test_line_clear(){
    *outOfDateRenderFlags = 0;
    *holdDownPoints = 0;
    Modifications modification = MAXOUTCODE;
    int_to_NES_format(0,3,cleared_lines);
    int_to_NES_format(0,7,current_score);
    *current_level=9;
    *gameType = 0;
    int clockcycles = 0;
    memset(playField, 0xEF, 256);

    int i;
    for(i=0;i<985600;i++){
        *completedLines=4;
        int clockcycles = playState_updateLinesAndStatistics_with_clockcycles_and_mods(CRASHFIX);
        if(*current_level==0 && int_to_C_format(cleared_lines,3) == 0){
            printf("Linestotal: %i\r\n",i*4+4);
            printf("Level: %i\tLines: %i\tScore:%i\tclockcycles:%i\r\n",*current_level,int_to_C_format(cleared_lines,3),int_to_C_format(current_score,6),clockcycles);
        }
    }
    printf("Fertig!!\r\nLinestotal: %i\r\n",i*4);
    printf("Level: %i\tLines: %i\tScore:%i\tclockcycles:%i\r\n",*current_level,int_to_C_format(cleared_lines,3),int_to_C_format(current_score,6),clockcycles);

    //runGame(MAXOUTCODE);
}

int main(){
    *player1_startHeight = 3;
    *player2_startHeight = 3;
    *current_level=9;
    *gameType = 1;

    rng_seed[0]=0xCD;
    rng_seed[1]=0x0E;
    *tetriminoX = 20;
    initPlayfieldIfTypeB();


    /*int i;
    for(i=2;i<65536;i++){
        memset(playField, 0xEF, 256);
        rng_seed[0]=i%256;
        rng_seed[1]=i/256;
        initPlayfieldIfTypeB();

        int minholes = 10;
        int gaps = 0;
        int mingaps = 5;
        int linemingaps = 0;
        int lineminholes = 0;
        for(int j=12;j<20;j++){
            int holes = 0;
            gaps = 0;
            bool gap = false;
            for(int k=0;k<10;k++){
                if(playField[10*j+k]==0xEF){
                    holes++;
                    if(gap == false){
                        gap = true;
                        gaps++;
                    }
                }else{
                    gap = false;
                }
            }
            if(holes < minholes){
                minholes = holes;
                lineminholes = j;
            }
            if(gaps < mingaps){
                mingaps = gaps;
                linemingaps = j;
            }
            //printf("%i\r\n",mingaps);
        }
        //printf("%i\r\n",minholes);
        if(minholes<5 && mingaps == 1 && linemingaps == lineminholes){
            break;
        }
    }
    printf("%i\r\n",i);*/
    print_playfield(6,123);
    //test_line_clear();
    //simulate_tetris();
	/*convert_game_genie_code("XNAOOK",6); //
	convert_game_genie_code("ENEOOGEZ",8); //this code is different from XNAOOK
	convert_game_genie_code("ASAPKG",6);
	convert_game_genie_code("TEEPSK",6);*/
}
