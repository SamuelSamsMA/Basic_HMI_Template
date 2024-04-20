/**
  Company:
    Microchip Technology Inc.

  Author:
	Samuel Muñoz Aguilar

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47Q43
        Driver Version    :  2.00
*/

#include "mcc_generated_files/mcc.h"
#include "sipo_reg595.h"
#include "lcd_192x64_text.h"
#include "matrix_keyboard_5x4.h"
#include "main.h"
#include "menu.h"


volatile TASKS tasks;
APP_DATA appData;



void main(void)
{
    initApp();
	
    while (1)
    {
		if (tasks.all)
		{
			if (tasks.controlProcess)
			{
				if (appData.LEDstate)
					PWM1_LoadDutyValue(appData.LEDdutyCycle);
				else
					PWM1_LoadDutyValue(0);
				
				tasks.controlProcess = 0;	/* Done */
			}
			
			else if (tasks.rtcReadTime)
			{
				static uint8_t prevDate = 0;
				RTC_readHMS(&appData.currentTime);
				RTC_readDMY(&appData.currentTime);
				
				if (prevDate != appData.currentTime.date)
				{
					prevDate = appData.currentTime.date;
					appData.currentMenu(NULL_KEY, PAINT_DATE_TIME);
				}
				else
					appData.currentMenu(NULL_KEY, PAINT_TIME);
				
				tasks.rtcReadTime = 0;		/* Done */
			}
			
			else if (tasks.updateScreen)
			{
				appData.currentMenu(NULL_KEY, PAINT_ALL);
				
				tasks.updateScreen = 0;		/* Done */
			}
			
			else if (tasks.keyboardScan)
			{
				char key = KEYBOARD_scan();
				if (key != ERROR_KEY)
				{
					if (appData.currentEdit != NULL)
							appData.currentEdit(key, NULL);
					else
						appData.currentMenu(key, NO_PAINT);
				}
				
				tasks.keyboardScan = 0;		/* Done */
			}
			
			else if (tasks.screenPointer)
			{
				GLCD_managePointer(MANAGE_POINTER);
				
				tasks.screenPointer = 0;	/* Done */
			}
			
			else if (tasks.keyboardEvent)
			{
				TMR4_Start();
				tasks.keyboardEvent = 0;	/* Done */
			}
			
			else
				continue;
		}
		else
		{ /* There's nothing to do */
//			SLEEP();
			continue;
		} /* There's nothing to do */
    }
}


void initApp(void)
{
	SYSTEM_Initialize();
	SIPO_REG_initialize();
	GLCD_initialize();
	RTC_initialize();
	
	IOCCF0_SetInterruptHandler(KEYBOARD_event);
	IOCCF1_SetInterruptHandler(KEYBOARD_event);
	IOCCF2_SetInterruptHandler(KEYBOARD_event);
	IOCCF7_SetInterruptHandler(KEYBOARD_event);
	
	TMR4_SetInterruptHandler(KEYBOARD_eventDelayed);
	TMR6_SetInterruptHandler(GLCD_pointerInterrupt);
	INT0_SetInterruptHandler(RTC_interrupt);
	
	appData.currentMenu = MENU_start;
	appData.currentEdit = NULL;
	appData.LEDdutyCycle = 250;
	appData.LEDstate = false;
	
	tasks.all = 0;
	tasks.controlProcess = 1;
	tasks.updateScreen = 1;
	tasks.rtcReadTime = 1;

	// Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
}


void KEYBOARD_event(void)
{
	tasks.keyboardEvent = 1;
}

void KEYBOARD_eventDelayed(void)
{
	tasks.keyboardScan = 1;
}

void GLCD_pointerInterrupt(void)
{
	tasks.screenPointer = 1;
}

void RTC_interrupt(void)
{
	tasks.rtcReadTime = 1;
}


/*********************************************************************
 *								putch()
 * Description:
 *		Function used by printf to direct standard output to any
 *		peripheral. In this case it is redirected to the LCD screen.
 *********************************************************************/
void putch(unsigned char data)
{
	GLCD_printChar(data);
}

