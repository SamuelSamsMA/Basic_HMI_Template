/* 
 * File:   lcd_192x64_text.h
 * Author: Samuel Muñoz Aguilar
 * 
 * This library can drive a 192x64 pixel LCD graphic display with
 * the KS0108B driver only for printing text, not graphics.
 * This results in small and fast code suitable for microcontrollers with
 * limited resources and applications where a large screen is required.
 *
 * Created on March 9, 2024
 */

#ifndef LCD_192X64_TEXT_H
#define	LCD_192X64_TEXT_H


#define SEGMENT1		0x01
#define SEGMENT2		0x02
#define SEGMENT3		0x03
#define ALL_SEGMENTS	0xFF
#define COMMAND			0
#define DATA			1
#define RESET_POINTER	1
#define MANAGE_POINTER	0
#define DONT_SAVE_CHAR  0
#define SAVE_CHAR       1


// Display commands
#define DISPLAY_ON		0x3F
#define DISPLAY_OFF		0x3E
#define Y_ADDRESS		0x40	// Horizontal position in characters (0-63)
#define X_ADDRESS		0xB8	// Vertical position in characters (0-7)
#define Z_ADDRESS		0xC0


// Font definitions
#define TOTAL_COLUMNS	32						// The maximum text length is
#define TOTAL_ROWS		8						// 32 columns by 8 rows
#define TEXT_LENGTH		MAX_COLUMNS*MAX_ROWS	//
#define FONT_WIDTH  	5						// In pixels
#define FONT_HEIGHT		7						// In pixels



//********************************************************************
//						   GLCD_initialize()
//  Description:
//      Configures the display with 8 bit communication.
//********************************************************************
void GLCD_initialize(void);


//********************************************************************
//					       GLCD_printChar()
//  Description:
//      Prints a character at the current cursor position.
//********************************************************************
void GLCD_printChar(char c);


//********************************************************************
//						  GLCD_printString()
//  Description:
//      Prints a string of characters at the current cursor position.
//********************************************************************
//void GLCD_printString(char* str);


//********************************************************************
//						  GLCD_moveCursor()
//  Definition:
//      The cursor is the invisible position on the screen where
//		characters are printed and is automatically moved one place
//		to the right to write continuously on a single line.
//  Description:
//      Moves the cursor to a new position.
//  Parameters:
//      column: horizontal position form 1 to 32
//      row: vertical position from 1 to 8
//********************************************************************
void GLCD_moveCursor(unsigned char column, unsigned char row);


//********************************************************************
//						    GLCD_clear()
//  Description:
//      Clears all content on the screen
//********************************************************************
void GLCD_clear(void);


//********************************************************************
//						 GLCD_managePointer()
//	Definition:
//		The pointer is a flashing symbol that indicates a position on
//		the screen.
//  Description:
//      
//  Parameters:
//      resetPointer: true -> disable and hide to the pointer
//					  false -> Normal operation
//********************************************************************
void GLCD_managePointer(bool resetPointer);


void GLCD_turnOnPointer(void);


void GLCD_turnOffPointer(void);


void GLCD_movePointer(unsigned char column, unsigned char row);


#endif	/* LCD_192X64_TEXT_H */

