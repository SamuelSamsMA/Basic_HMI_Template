/* 
 * File:   main.h
 * Author: Samuel Muñoz Aguilar
 *
 * Created on March 25, 2024, 8:57 AM
 */

#ifndef MAIN_H
#define	MAIN_H


#include <stdio.h>
#include "rtc_ds3231.h"


typedef union {
	unsigned char all;
	struct {
		unsigned controlProcess : 1;
		unsigned updateScreen	: 1;
		unsigned screenPointer	: 1;
		unsigned keyboardEvent	: 1;
		unsigned keyboardScan	: 1;
		unsigned rtcReadTime	: 1;
	};
} TASKS;


typedef struct {
	// Pointer to the current menu function
	void (*currentMenu)(unsigned char, unsigned int);
	
	// Pointer to the current editing function
	// null if no editing
	void (*currentEdit)(unsigned char, void*);
	
	// Saves the Real Time Clock (RTC) data
	TIME currentTime;
	
	int LEDdutyCycle;
	bool LEDstate;
} APP_DATA;


void initApp(void);


//********************************************************************
//						  Interrupt functions
//********************************************************************
void KEYBOARD_event(void);
void KEYBOARD_eventDelayed(void);
void GLCD_pointerInterrupt(void);
void RTC_interrupt(void);

#endif	/* MAIN_H */

