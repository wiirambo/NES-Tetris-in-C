#include <stdint.h>
#include <stdbool.h>

//functions to print the playfield to the console

void print_playfield();
void int_to_NES_format(int number, int digits, uint8_t* NES_number);
int int_to_C_format(uint8_t* number, int digits);
bool isPartOfTetrimino(uint8_t x, uint8_t y);
void print_statistics(int line);
char piece_to_letter(uint8_t piece);
