/* 
 * File:   matrix_keyboard_5x4.h
 * Author: Samuel Muñoz Aguilar
 *
 * This library 
 * Created on March 15, 2024, 12:09 AM
 */

#ifndef MATRIX_KEYBOARD_5X4_H
#define	MATRIX_KEYBOARD_5X4_H


// Key codes
#define KEY_0			0
#define KEY_1			1
#define KEY_2			2
#define KEY_3			3
#define KEY_4			4
#define KEY_5			5
#define KEY_6			6
#define KEY_7			7
#define KEY_8			8
#define KEY_9			9
#define KEY_F1			10
#define KEY_ESC			11
#define KEY_F2			12
#define KEY_ENT			13
#define KEY_LEFT		14
#define KEY_RIGHT		15
#define KEY_UP			16
#define KEY_DOWN		17
#define KEY_HASH		18
#define KEY_ASTERISK	19
#define ERROR_KEY		20
#define NULL_KEY		255



char KEYBOARD_scan(void);


#endif	/* MATRIX_KEYBOARD_5X4_H */

