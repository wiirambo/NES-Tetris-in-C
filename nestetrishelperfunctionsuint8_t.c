typedef enum {
    UNMODIFIED,
    SEVENDIGITS,
    MAXOUTCODE,
    ENEOOGEZ,
    CRASHFIX
} Modifications;

void runGame(Modifications modification);
void convert_game_genie_code(char code[], int characters);
void print_playfield_extented();
void print_playfield();
void int_to_NES_format(int number, int digits, uint8_t* NES_number);
int int_to_C_format(uint8_t* number, int digits);
void print_playfield_extented();
void print_playfield(int digits, int frame);
bool isPartOfTetrimino(uint8_t x, uint8_t y);
void print_statistics(int line);
bool isPositionValid_h(uint8_t tetriminoY);

bool isPositionValid_h(uint8_t tetriminoY){//used for a hackfix
    int generalCounter = tetriminoY * 10  + *tetriminoX;
    int generalCounter2 = *currentPiece * 4;
    uint8_t x = generalCounter2 + (generalCounter2 << 1);
    int generalCounter3 = 4;
    uint8_t y=0;
    do{
        //uint8_t is converted to int -->  does not wrap around at 256!!!
        uint8_t temp = (uint8_t)(orientationTable[x] + tetriminoY);
        if(temp >= -2 && temp  < 20 || temp == 255 || temp ==  254){ // WHY + 2 and then compare with 22 ??
            int generalCounter4 = orientationTable[x] << 1;
            int temp = generalCounter + generalCounter4 + (generalCounter4 << 2);
            x += 2;
            y = orientationTable[x] + temp;
            if(playFieldAddr[0][y] >= 0xEF){//!= ???
                if((int8_t)(orientationTable[x] + *tetriminoX) < 10 && (int8_t)(orientationTable[x] + *tetriminoX) >= 0){
                    x++;
                    generalCounter3--;
                }else{
                    return false;
                }
            }else{
                return false;
            }

        }else{
            return false;
        }
    }while(generalCounter3 != 0);
    return true;
}

void int_to_NES_format(int number, int digits, uint8_t* NES_number){
    if(digits==3){
        NES_number[0] = number % 10;
        NES_number[0] = NES_number[0] + ((number / 10 % 10) * 16);
        NES_number[1] = number/100;
    }
	if(digits==6 || digits==7){
        uint8_t temp=0;
        int i = 0;
        for(i=0;i<3;i++){
            temp = number % 10;
            number = number / 10;
            temp += (number % 10) * 16;
            number = number / 10;
            NES_number[i] = temp;
        }
        if(digits==7){
            NES_number[3] = number;
		}
	}else{
		//
	}
}
int int_to_C_format(uint8_t* number, int digits){
	int c_number=0;
	if(digits==3){
        c_number += number[0]&0x0F;
        c_number += ((number[0]&0xF0)>>4)*10;
        c_number += number[1]*100;
	}
	if(number!=NULL && (digits==6 || digits==7)){
		int multiplier = 1;
		int i;
		for(i=0;i<3;i++){
			c_number += (number[i]&0x0F)*multiplier;
			c_number += ((number[i]&0xF0)>>4)*multiplier*10;
			multiplier *= 100;
		}
		if(digits==7){
			c_number += number[i]*multiplier;
		}
	}
	return c_number;
}

void convert_game_genie_code(char code[], int characters){//source of information: http://tuxnes.sourceforge.net/gamegenie.html
    char temp[characters];
        for(int i=0;i<characters;i++){
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
        short address = 0x8000 +
                  ((code[3] & 7) << 12)
                | ((code[5] & 7) << 8) | ((code[4] & 8) << 8)
                | ((code[2] & 7) << 4) | ((code[1] & 8) << 4)
                |  (code[4] & 7)       |  (code[3] & 8);
    if(characters==6){
        short data =
                 ((code[1] & 7) << 4) | ((code[0] & 8) << 4)
                | (code[0] & 7)       |  (code[5] & 8);
        printf("adress: %0x Data: %0x\r\n", address-0xffff0000, data);
    }
    if(characters==8){
        short data =
                 ((code[1] & 7) << 4) | ((code[0] & 8) << 4)
                | (code[0] & 7)       |  (code[7] & 8);
        short compare =
             ((code[7] & 7) << 4) | ((code[6] & 8) << 4)
            | (code[6] & 7)       |  (code[5] & 8);
        printf("adress: %0x Data: %0x Compare: %0x\r\n", address-0xffff0000, data, compare);
    }
}

char piece_to_letter(uint8_t piece){
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

void print_playfield_extented(){
    for(int i=23;i<25;i++){
        printf("%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\r\n",playField[i*10+6],playField[i*10+7],playField[i*10+8],playField[i*10+9],playField[i*10+10],playField[i*10+11],playField[i*10+12],playField[i*10+13],playField[i*10+14],playField[i*10+15]);
    }
    printf("Stuff above is not visible\r\n");
    for(int i=0;i<25;i++){
        printf("Line %i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\r\n",i,playField[i*10+0],playField[i*10+1],playField[i*10+2],playField[i*10+3],playField[i*10+4],playField[i*10+5],playField[i*10+6],playField[i*10+7],playField[i*10+8],playField[i*10+9]);
    }
    printf("\r\n\r\n");
}

void print_playfield(int digits, int frame){
    int points = int_to_C_format(current_score, digits);
    int lines = int_to_C_format(cleared_lines, 3);
    //system("clear");
    //Frame is paused before the draw core in the emulator
    printf("Score: %i\tDAS: %i\tMusic: %i\tLevel: %i\tLines: %i\tNext: %c\tFrame of variables: %i\r\nFrame of Graphics: %i\r\n", points,*autorepeatX,*musicTrack,*current_level,lines,piece_to_letter(*nextPiece),frame,frame+1);
    for(int i=0;i<20;i++){
        print_statistics(i);
        for(int j=0;j<10;j++){
            if(isPartOfTetrimino(j,i)==true){
                printf("222\t");
            }else{
                if(playField[i*10+j] != 0xEF){
                    printf("%X\t",playField[i*10+j]);
                }else{
                    printf("0\t");
                }
            }
        }
        printf("\r\n");
    }
    printf("\r\n");
}

void print_statistics(int line){
    switch (line){
        case 7: printf("T: %i\t",int_to_C_format(statsByType+(line-7)*2,3)); break;
        case 8: printf("J: %i\t",int_to_C_format(statsByType+(line-7)*2,3)); break;
        case 9: printf("Z: %i\t",int_to_C_format(statsByType+(line-7)*2,3)); break;
        case 10: printf("O: %i\t",int_to_C_format(statsByType+(line-7)*2,3)); break;
        case 11: printf("S: %i\t",int_to_C_format(statsByType+(line-7)*2,3)); break;
        case 12: printf("L: %i\t",int_to_C_format(statsByType+(line-7)*2,3)); break;
        case 13: printf("I: %i\t",int_to_C_format(statsByType+(line-7)*2,3)); break;
        default: printf("\t");
    }
}

bool isPartOfTetrimino(uint8_t x, uint8_t y){
    switch(*currentPiece){
        case 0: if((y==*tetriminoY && x >= *tetriminoX - 1 && x <= *tetriminoX + 1) || (y==*tetriminoY-1 && x == *tetriminoX) ){
                    return true;
                }
                break;
        case 1: if((x==*tetriminoX && y >= *tetriminoY - 1 && y <= *tetriminoY + 1) || (x==*tetriminoX+1 && y == *tetriminoY) ){
                    return true;
                }
                break;
        case 2: if((y==*tetriminoY && x >= *tetriminoX - 1 && x <= *tetriminoX + 1) || (y==*tetriminoY+1 && x == *tetriminoX) ){
                    return true;
                }
                break;
        case 3: if((x==*tetriminoX && y >= *tetriminoY - 1 && y <= *tetriminoY + 1) || (x==*tetriminoX-1 && y == *tetriminoY) ){
                    return true;
                }
                break;
        case 4: if((x==*tetriminoX && y >= *tetriminoY - 1 && y <= *tetriminoY + 1) || (y==*tetriminoY+1 && x == *tetriminoX-1) ){
                    return true;
                }
                break;
        case 5: if((y==*tetriminoY && x >= *tetriminoX - 1 && x <= *tetriminoX + 1) || (x==*tetriminoX-1 && y == *tetriminoY-1) ){
                    return true;
                }
                break;
        case 6: if((x==*tetriminoX && y >= *tetriminoY - 1 && y <= *tetriminoY + 1) || (y==*tetriminoY-1 && x == *tetriminoX+1) ){
                    return true;
                }
                break;
        case 7: if((y==*tetriminoY && x >= *tetriminoX - 1 && x <= *tetriminoX + 1) || (x==*tetriminoX+1 && y == *tetriminoY+1) ){
                    return true;
                }
                break;
        case 8: if((y==*tetriminoY && x >= *tetriminoX-1 && x <= *tetriminoX) || (y==*tetriminoY+1 && x >= *tetriminoX && x <= *tetriminoX+1) ){
                    return true;
                }
                break;
        case 9: if((x==*tetriminoX && y >= *tetriminoY && y <= *tetriminoY+1) || (x==*tetriminoX+1 && y >= *tetriminoY-1 && y <= *tetriminoY) ){
                    return true;
                }
                break;
        case 10: if(x>=*tetriminoX-1 && x<=*tetriminoX && y <= *tetriminoY + 1 && y >= *tetriminoY){
                    return true;
                }
                break;
        case 11: if((y==*tetriminoY && x >= *tetriminoX && x <= *tetriminoX+1) || (y==*tetriminoY+1 && x >= *tetriminoX-1 && x <= *tetriminoX) ){
                    return true;
                }
                break;
        case 12: if((x==*tetriminoX && y >= *tetriminoY - 1 && y <= *tetriminoY) || (x==*tetriminoX+1 && y >= *tetriminoY && y <= *tetriminoY+1) ){
                    return true;
                }
                break;
        case 13: if((x==*tetriminoX && y >= *tetriminoY - 1 && y <= *tetriminoY + 1) || (y==*tetriminoY+1 && x == *tetriminoX+1) ){
                    return true;
                }
                break;
        case 14: if((y==*tetriminoY && x >= *tetriminoX - 1 && x <= *tetriminoX + 1) || (x==*tetriminoX-1 && y == *tetriminoY+1) ){
                    return true;
                }
                break;
        case 15: if((x==*tetriminoX && y >= *tetriminoY - 1 && y <= *tetriminoY + 1) || (y==*tetriminoY-1 && x == *tetriminoX-1) ){
                    return true;
                }
                break;
        case 16: if((y==*tetriminoY && x >= *tetriminoX - 1 && x <= *tetriminoX + 1) || (x==*tetriminoX+1 && y == *tetriminoY-1) ){
                    return true;
                }
                break;
        case 17: if(x==*tetriminoX && y >= *tetriminoY - 2 && y < *tetriminoY + 2 ){
                    return true;
                }
                break;
        case 18: if(y==*tetriminoY && x >= *tetriminoX - 2 && x < *tetriminoX + 2 ){
                    return true;
                }
                break;
    }
    return false;
}
