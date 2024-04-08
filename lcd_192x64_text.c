#include "mcc_generated_files/mcc.h"
#include "sipo_reg595.h"
#include "lcd_192x64_text.h"


static uint8_t nColumn, nRow;				// Cursor coordinates
static uint8_t colPointer, rowPointer;		// Pointer coordinates
static char pointerSymbol;
static char localBackup[TOTAL_ROWS][TOTAL_COLUMNS];
static const char font5x7[96][5] = {
	{0x00, 0x00, 0x00, 0x00, 0x00},	// (espacio)
	{0x00, 0x00, 0x5F, 0x00, 0x00},	// !
	{0x00, 0x07, 0x00, 0x07, 0x00},	// "
	{0x14, 0x7F, 0x14, 0x7F, 0x14},	// #
	{0x24, 0x2A, 0x7F, 0x2A, 0x12},	// $
	{0x23, 0x13, 0x08, 0x64, 0x62},	// %
	{0x36, 0x49, 0x55, 0x22, 0x50},	// &
	{0x00, 0x05, 0x03, 0x00, 0x00},	// '
	{0x00, 0x1C, 0x22, 0x41, 0x00},	// (
	{0x00, 0x41, 0x22, 0x1C, 0x00},	// )
	{0x08, 0x2A, 0x1C, 0x2A, 0x08},	// *
	{0x08, 0x08, 0x3E, 0x08, 0x08},	// +
	{0x00, 0x50, 0x30, 0x00, 0x00},	// ,
	{0x08, 0x08, 0x08, 0x08, 0x08},	// -
	{0x00, 0x60, 0x60, 0x00, 0x00},	// .
	{0x20, 0x10, 0x08, 0x04, 0x02},	// /
	{0x3E, 0x51, 0x49, 0x45, 0x3E},	// 0
	{0x00, 0x42, 0x7F, 0x40, 0x00},	// 1
	{0x42, 0x61, 0x51, 0x49, 0x46},	// 2
	{0x21, 0x41, 0x45, 0x4B, 0x31},	// 3
	{0x18, 0x14, 0x12, 0x7F, 0x10},	// 4
	{0x27, 0x45, 0x45, 0x45, 0x39},	// 5
	{0x3C, 0x4A, 0x49, 0x49, 0x30},	// 6
	{0x01, 0x71, 0x09, 0x05, 0x03},	// 7
	{0x36, 0x49, 0x49, 0x49, 0x36},	// 8
	{0x06, 0x49, 0x49, 0x29, 0x1E},	// 9
	{0x00, 0x36, 0x36, 0x00, 0x00},	// :
	{0x00, 0x56, 0x36, 0x00, 0x00},	// ;
	{0x00, 0x08, 0x14, 0x22, 0x41},	// <
	{0x14, 0x14, 0x14, 0x14, 0x14},	// =
	{0x41, 0x22, 0x14, 0x08, 0x00},	// >
	{0x02, 0x01, 0x51, 0x09, 0x06},	// ?
	{0x32, 0x49, 0x79, 0x41, 0x3E},	// @
	{0x7E, 0x11, 0x11, 0x11, 0x7E},	// A
	{0x7F, 0x49, 0x49, 0x49, 0x36},	// B
	{0x3E, 0x41, 0x41, 0x41, 0x22},	// C
	{0x7F, 0x41, 0x41, 0x22, 0x1C},	// D
	{0x7F, 0x49, 0x49, 0x49, 0x41},	// E
	{0x7F, 0x09, 0x09, 0x01, 0x01},	// F
	{0x3E, 0x41, 0x41, 0x51, 0x32},	// G
	{0x7F, 0x08, 0x08, 0x08, 0x7F},	// H
	{0x00, 0x41, 0x7F, 0x41, 0x00},	// I
	{0x20, 0x40, 0x41, 0x3F, 0x01},	// J
	{0x7F, 0x08, 0x14, 0x22, 0x41},	// K
	{0x7F, 0x40, 0x40, 0x40, 0x40},	// L
	{0x7F, 0x02, 0x04, 0x02, 0x7F},	// M
	{0x7F, 0x04, 0x08, 0x10, 0x7F},	// N
	{0x3E, 0x41, 0x41, 0x41, 0x3E},	// O
	{0x7F, 0x09, 0x09, 0x09, 0x06},	// P
	{0x3E, 0x41, 0x51, 0x21, 0x5E},	// Q
	{0x7F, 0x09, 0x19, 0x29, 0x46},	// R
	{0x46, 0x49, 0x49, 0x49, 0x31},	// S
	{0x01, 0x01, 0x7F, 0x01, 0x01},	// T
	{0x3F, 0x40, 0x40, 0x40, 0x3F},	// U
	{0x1F, 0x20, 0x40, 0x20, 0x1F},	// V
	{0x7F, 0x20, 0x18, 0x20, 0x7F},	// W
	{0x63, 0x14, 0x08, 0x14, 0x63},	// X
	{0x03, 0x04, 0x78, 0x04, 0x03},	// Y
	{0x61, 0x51, 0x49, 0x45, 0x43},	// Z
	{0x00, 0x00, 0x7F, 0x41, 0x41},	// [
	{0x02, 0x04, 0x08, 0x10, 0x20},	// '\'
	{0x41, 0x41, 0x7F, 0x00, 0x00},	// ]
	{0x04, 0x02, 0x01, 0x02, 0x04},	// ^
	{0x40, 0x40, 0x40, 0x40, 0x40},	// _
	{0x00, 0x01, 0x02, 0x04, 0x00},	// `
	{0x20, 0x54, 0x54, 0x54, 0x78},	// a
	{0x7F, 0x48, 0x44, 0x44, 0x38},	// b
	{0x38, 0x44, 0x44, 0x44, 0x20},	// c
	{0x38, 0x44, 0x44, 0x48, 0x7F},	// d
	{0x38, 0x54, 0x54, 0x54, 0x18},	// e
	{0x08, 0x7E, 0x09, 0x01, 0x02},	// f
	{0x08, 0x14, 0x54, 0x54, 0x3C},	// g
	{0x7F, 0x08, 0x04, 0x04, 0x78},	// h
	{0x00, 0x44, 0x7D, 0x40, 0x00},	// i
	{0x20, 0x40, 0x44, 0x3D, 0x00},	// j
	{0x00, 0x7F, 0x10, 0x28, 0x44},	// k
	{0x00, 0x41, 0x7F, 0x40, 0x00},	// l
	{0x7C, 0x04, 0x18, 0x04, 0x78},	// m
	{0x7C, 0x08, 0x04, 0x04, 0x78},	// n
	{0x38, 0x44, 0x44, 0x44, 0x38},	// o
	{0x7C, 0x14, 0x14, 0x14, 0x08},	// p
	{0x08, 0x14, 0x14, 0x18, 0x7C},	// q
	{0x7C, 0x08, 0x04, 0x04, 0x08},	// r
	{0x48, 0x54, 0x54, 0x54, 0x20},	// s
	{0x04, 0x3F, 0x44, 0x40, 0x20},	// t
	{0x3C, 0x40, 0x40, 0x20, 0x7C},	// u
	{0x1C, 0x20, 0x40, 0x20, 0x1C},	// v
	{0x3C, 0x40, 0x30, 0x40, 0x3C},	// w
	{0x44, 0x28, 0x10, 0x28, 0x44},	// x
	{0x0C, 0x50, 0x50, 0x50, 0x3C},	// y
	{0x44, 0x64, 0x54, 0x4C, 0x44},	// z
	{0x00, 0x08, 0x36, 0x41, 0x00},	// {
	{0x00, 0x00, 0x7F, 0x00, 0x00},	// |
	{0x00, 0x41, 0x36, 0x08, 0x00},	// }
	{0x10, 0x08, 0x18, 0x10, 0x08},	// ~
	{0x1C, 0x3E, 0x3E, 0x3E, 0x1C}	// ■
};


//********************************************************************
//							GLCD_sendByte()
//  Description:
//      Send a data byte to the display through the serial registers
//      74HC595.
//      This function should NOT be called outside the library as it
//      could cause a malfunction of the display.
//  Parameters:
//      data: byte to send
//      data_nCommand: 1 -> send as data
//                     0 -> send as command
//      segment: part of the display
//  Notes:
//      The display's resolution is 192x64 pixels and is divided into
//      three segments of 64x64 controlled by identical chips. That's
//      why there are three pins of segment selection (GLCD_CS1,
//      GLCD_CS2 and GLCD_CS3).
//********************************************************************
static void GLCD_sendByte(char data, char data_nCommand, char segment)
{
	uint16_t byteOfZeros = 0;
	uint16_t byteOfOnes = 0;
	(data & 0x01) ? (byteOfOnes |= GLCD_DB0) : (byteOfZeros |= GLCD_DB0);
	(data & 0x02) ? (byteOfOnes |= GLCD_DB1) : (byteOfZeros |= GLCD_DB1);
	(data & 0x04) ? (byteOfOnes |= GLCD_DB2) : (byteOfZeros |= GLCD_DB2);
	(data & 0x08) ? (byteOfOnes |= GLCD_DB3) : (byteOfZeros |= GLCD_DB3);
	(data & 0x10) ? (byteOfOnes |= GLCD_DB4) : (byteOfZeros |= GLCD_DB4);
	(data & 0x20) ? (byteOfOnes |= GLCD_DB5) : (byteOfZeros |= GLCD_DB5);
	(data & 0x40) ? (byteOfOnes |= GLCD_DB6) : (byteOfZeros |= GLCD_DB6);
	(data & 0x80) ? (byteOfOnes |= GLCD_DB7) : (byteOfZeros |= GLCD_DB7);
	SIPO_REG_setWithMask(byteOfZeros, 0);
	
//	SIPO_REG_setWithMask(byteOfOnes, 1);
//	SIPO_REG_setWithMask(GLCD_CS1 | GLCD_CS2 | GLCD_CS3, 1);
//	These two instructions are equivalent to:
	byteOfOnes |= GLCD_CS1 | GLCD_CS2 | GLCD_CS3;
	SIPO_REG_setWithMask(byteOfOnes, 1);

    switch (segment)
    {
    case SEGMENT1:
        SIPO_REG_setWithMask(GLCD_CS1, 0);  break;
    case SEGMENT2:
        SIPO_REG_setWithMask(GLCD_CS2, 0);  break;
    case SEGMENT3:
        SIPO_REG_setWithMask(GLCD_CS3, 0);  break;
    case ALL_SEGMENTS:
        SIPO_REG_setWithMask(GLCD_CS1 | GLCD_CS2 | GLCD_CS3, 0);	break;
    }

    if (data_nCommand)
        SIPO_REG_setWithMask(GLCD_RS, 1);
    else
        SIPO_REG_setWithMask(GLCD_RS, 0);
    
    SIPO_REG_setWithMask(GLCD_EN, 1);
    __delay_us(5);
    SIPO_REG_setWithMask(GLCD_EN, 0);
    __delay_us(5);
}


//********************************************************************
//						 GLCD_printCharacter()
//  Description:
//      Prints a character at the position of the cursor and moves it
//      one place to the right so you can write continuously in the
//      same row.
//  Parameters:
//      character: ASCII character to print.
//      saveLocal: 1 -> the character is saved in local array.
//                 0 -> prints temporary (local array not changed)
//********************************************************************
static void GLCD_printCharacter(char character, bool saveLocal)
{
    uint8_t pixel_x = (uint8_t)((FONT_WIDTH + 1) * (nColumn - 1));
	uint8_t segment = (pixel_x / 64) + 1;
	uint8_t index = character - ' ';

    // Due to the segmentation of the screen, characters 11 and 22
    // of each row are printed in special way since they are right
    // in the division of two segments.
    switch (nColumn)
    {
    case 11:
    {
        uint8_t nextSegment = segment + 1;
		for (uint8_t i = 0; i < 4; i++)
			GLCD_sendByte(font5x7[index][i], DATA, segment);
		
        // Changes to the next segment and continuous printing the rest
        // of the character in the same row.
		GLCD_sendByte(Y_ADDRESS | 0, COMMAND, nextSegment);
		GLCD_sendByte(X_ADDRESS | (nRow - 1), COMMAND, nextSegment);
		GLCD_sendByte(font5x7[index][4], DATA, nextSegment);
		
		// White space as character separator
		GLCD_sendByte(0x00, DATA, nextSegment);
    }
        break;

    case 22:
    {
        // Something similar to case 11
        uint8_t nextSegment = segment + 1;
		GLCD_sendByte(font5x7[index][0], DATA, segment);
		GLCD_sendByte(font5x7[index][1], DATA, segment);
		
		GLCD_sendByte(Y_ADDRESS | 0, COMMAND, nextSegment);
		GLCD_sendByte(X_ADDRESS | (nRow - 1), COMMAND, nextSegment);
		
		for (uint8_t i = 2; i < 5; i++)
			GLCD_sendByte(font5x7[index][i], DATA, nextSegment);
		
		GLCD_sendByte(0x00, DATA, nextSegment);
    }
        break;
    default:
        for (uint8_t i = 0; i < 5; i++)
			GLCD_sendByte(font5x7[index][i], DATA, segment);
		
		GLCD_sendByte(0x00, DATA, segment);
        break;
    }

    // Save the character in the local array
	if (saveLocal)
		localBackup[nRow - 1][nColumn - 1] = character;
	
	// Increments the column number for the next character
    nColumn++;
}


void GLCD_initialize(void)
{
    SIPO_REG_setWithMask(GLCD_RST, 0);
    __delay_ms(50);

    SIPO_REG_setWithMask(GLCD_RST, 1);
    __delay_ms(50);

    GLCD_sendByte(DISPLAY_ON, COMMAND, ALL_SEGMENTS);
    GLCD_sendByte(Z_ADDRESS | 0, COMMAND, ALL_SEGMENTS);

    colPointer = 1;
    rowPointer = 1;
	pointerSymbol = ' ';
    
	GLCD_clear();
	GLCD_moveCursor(1,1);
}


void GLCD_printChar(char c)
{
	GLCD_printCharacter(c, SAVE_CHAR);
}


void GLCD_moveCursor(unsigned char column, unsigned char row)
{
    if (column > TOTAL_COLUMNS || row > TOTAL_ROWS)
		return;
	
	unsigned char pixel_x = (uint8_t)((FONT_WIDTH + 1) * (column - 1));
	unsigned char segment = (pixel_x / 64) + 1;
	unsigned char hori_dir = pixel_x % 64;
	unsigned char vert_dir = row - 1;
	
	GLCD_sendByte(Y_ADDRESS | hori_dir, COMMAND, segment);
	GLCD_sendByte(X_ADDRESS | vert_dir, COMMAND, segment);
	
	nColumn = column;
	nRow = row;
}


void GLCD_clear(void)
{
	for (uint8_t row = 0; row < TOTAL_ROWS; row++)
	{
		GLCD_sendByte(X_ADDRESS | row, COMMAND, ALL_SEGMENTS);
		GLCD_sendByte(Y_ADDRESS | 0, COMMAND, ALL_SEGMENTS);
		
		for (uint8_t j = 0; j < 64; j++)
			GLCD_sendByte(0, DATA, ALL_SEGMENTS);
		
		for (uint8_t col = 0; col < TOTAL_COLUMNS; col++)
			localBackup[row][col] = ' ';
	}
}


void GLCD_managePointer(bool resetPointer)
{
	enum pointerState {VISIBLE, HIDDEN};
	static enum pointerState state = HIDDEN;
	uint8_t oldColumn, oldRow;

	// Back up the original row and column
	oldColumn = nColumn;
	oldRow = nRow;

	GLCD_moveCursor(colPointer, rowPointer);

	if (resetPointer || (state == HIDDEN))
	{	// Prints the character corresponding to the pointer position
		GLCD_printCharacter(localBackup[rowPointer - 1][colPointer - 1],
			DONT_SAVE_CHAR);
	}
	else
	{	// Prints the pointer symbol
		GLCD_printCharacter(pointerSymbol, DONT_SAVE_CHAR);
	}

	GLCD_moveCursor(oldColumn, oldRow);
	(state == VISIBLE) ? (state = HIDDEN) : (state = VISIBLE);
}


void GLCD_turnOnPointer(void)
{
	TMR6_Counter8BitSet(0);
	TMR6_Start();
}


void GLCD_turnOffPointer(void)
{
	TMR6_Stop();
	GLCD_managePointer(RESET_POINTER);
}


void GLCD_movePointer(unsigned char column, unsigned char row)
{
	GLCD_managePointer(RESET_POINTER);
	colPointer = column;
	rowPointer = row;
}

