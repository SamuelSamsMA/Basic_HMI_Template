/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47Q43
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSELB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSELB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSELB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set KEYBOARD_ROW1 aliases
#define KEYBOARD_ROW1_TRIS                 TRISCbits.TRISC0
#define KEYBOARD_ROW1_LAT                  LATCbits.LATC0
#define KEYBOARD_ROW1_PORT                 PORTCbits.RC0
#define KEYBOARD_ROW1_WPU                  WPUCbits.WPUC0
#define KEYBOARD_ROW1_OD                   ODCONCbits.ODCC0
#define KEYBOARD_ROW1_ANS                  ANSELCbits.ANSELC0
#define KEYBOARD_ROW1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define KEYBOARD_ROW1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define KEYBOARD_ROW1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define KEYBOARD_ROW1_GetValue()           PORTCbits.RC0
#define KEYBOARD_ROW1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define KEYBOARD_ROW1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define KEYBOARD_ROW1_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define KEYBOARD_ROW1_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define KEYBOARD_ROW1_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define KEYBOARD_ROW1_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define KEYBOARD_ROW1_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define KEYBOARD_ROW1_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set KEYBOARD_ROW2 aliases
#define KEYBOARD_ROW2_TRIS                 TRISCbits.TRISC1
#define KEYBOARD_ROW2_LAT                  LATCbits.LATC1
#define KEYBOARD_ROW2_PORT                 PORTCbits.RC1
#define KEYBOARD_ROW2_WPU                  WPUCbits.WPUC1
#define KEYBOARD_ROW2_OD                   ODCONCbits.ODCC1
#define KEYBOARD_ROW2_ANS                  ANSELCbits.ANSELC1
#define KEYBOARD_ROW2_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define KEYBOARD_ROW2_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define KEYBOARD_ROW2_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define KEYBOARD_ROW2_GetValue()           PORTCbits.RC1
#define KEYBOARD_ROW2_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define KEYBOARD_ROW2_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define KEYBOARD_ROW2_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define KEYBOARD_ROW2_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define KEYBOARD_ROW2_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define KEYBOARD_ROW2_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define KEYBOARD_ROW2_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define KEYBOARD_ROW2_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set KEYBOARD_ROW3 aliases
#define KEYBOARD_ROW3_TRIS                 TRISCbits.TRISC2
#define KEYBOARD_ROW3_LAT                  LATCbits.LATC2
#define KEYBOARD_ROW3_PORT                 PORTCbits.RC2
#define KEYBOARD_ROW3_WPU                  WPUCbits.WPUC2
#define KEYBOARD_ROW3_OD                   ODCONCbits.ODCC2
#define KEYBOARD_ROW3_ANS                  ANSELCbits.ANSELC2
#define KEYBOARD_ROW3_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define KEYBOARD_ROW3_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define KEYBOARD_ROW3_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define KEYBOARD_ROW3_GetValue()           PORTCbits.RC2
#define KEYBOARD_ROW3_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define KEYBOARD_ROW3_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define KEYBOARD_ROW3_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define KEYBOARD_ROW3_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define KEYBOARD_ROW3_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define KEYBOARD_ROW3_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define KEYBOARD_ROW3_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define KEYBOARD_ROW3_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSELC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set KEYBOARD_ROW4 aliases
#define KEYBOARD_ROW4_TRIS                 TRISCbits.TRISC7
#define KEYBOARD_ROW4_LAT                  LATCbits.LATC7
#define KEYBOARD_ROW4_PORT                 PORTCbits.RC7
#define KEYBOARD_ROW4_WPU                  WPUCbits.WPUC7
#define KEYBOARD_ROW4_OD                   ODCONCbits.ODCC7
#define KEYBOARD_ROW4_ANS                  ANSELCbits.ANSELC7
#define KEYBOARD_ROW4_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define KEYBOARD_ROW4_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define KEYBOARD_ROW4_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define KEYBOARD_ROW4_GetValue()           PORTCbits.RC7
#define KEYBOARD_ROW4_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define KEYBOARD_ROW4_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define KEYBOARD_ROW4_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define KEYBOARD_ROW4_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define KEYBOARD_ROW4_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define KEYBOARD_ROW4_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define KEYBOARD_ROW4_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define KEYBOARD_ROW4_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set OE_HC595 aliases
#define OE_HC595_TRIS                 TRISDbits.TRISD2
#define OE_HC595_LAT                  LATDbits.LATD2
#define OE_HC595_PORT                 PORTDbits.RD2
#define OE_HC595_WPU                  WPUDbits.WPUD2
#define OE_HC595_OD                   ODCONDbits.ODCD2
#define OE_HC595_ANS                  ANSELDbits.ANSELD2
#define OE_HC595_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define OE_HC595_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define OE_HC595_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define OE_HC595_GetValue()           PORTDbits.RD2
#define OE_HC595_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define OE_HC595_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define OE_HC595_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define OE_HC595_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define OE_HC595_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define OE_HC595_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define OE_HC595_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define OE_HC595_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set RCLK_HC595 aliases
#define RCLK_HC595_TRIS                 TRISDbits.TRISD3
#define RCLK_HC595_LAT                  LATDbits.LATD3
#define RCLK_HC595_PORT                 PORTDbits.RD3
#define RCLK_HC595_WPU                  WPUDbits.WPUD3
#define RCLK_HC595_OD                   ODCONDbits.ODCD3
#define RCLK_HC595_ANS                  ANSELDbits.ANSELD3
#define RCLK_HC595_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define RCLK_HC595_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define RCLK_HC595_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define RCLK_HC595_GetValue()           PORTDbits.RD3
#define RCLK_HC595_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define RCLK_HC595_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define RCLK_HC595_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define RCLK_HC595_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define RCLK_HC595_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define RCLK_HC595_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define RCLK_HC595_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define RCLK_HC595_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set KEYBOARD_COL1 aliases
#define KEYBOARD_COL1_TRIS                 TRISDbits.TRISD4
#define KEYBOARD_COL1_LAT                  LATDbits.LATD4
#define KEYBOARD_COL1_PORT                 PORTDbits.RD4
#define KEYBOARD_COL1_WPU                  WPUDbits.WPUD4
#define KEYBOARD_COL1_OD                   ODCONDbits.ODCD4
#define KEYBOARD_COL1_ANS                  ANSELDbits.ANSELD4
#define KEYBOARD_COL1_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define KEYBOARD_COL1_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define KEYBOARD_COL1_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define KEYBOARD_COL1_GetValue()           PORTDbits.RD4
#define KEYBOARD_COL1_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define KEYBOARD_COL1_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define KEYBOARD_COL1_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define KEYBOARD_COL1_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define KEYBOARD_COL1_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define KEYBOARD_COL1_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define KEYBOARD_COL1_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define KEYBOARD_COL1_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set KEYBOARD_COL2 aliases
#define KEYBOARD_COL2_TRIS                 TRISDbits.TRISD5
#define KEYBOARD_COL2_LAT                  LATDbits.LATD5
#define KEYBOARD_COL2_PORT                 PORTDbits.RD5
#define KEYBOARD_COL2_WPU                  WPUDbits.WPUD5
#define KEYBOARD_COL2_OD                   ODCONDbits.ODCD5
#define KEYBOARD_COL2_ANS                  ANSELDbits.ANSELD5
#define KEYBOARD_COL2_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define KEYBOARD_COL2_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define KEYBOARD_COL2_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define KEYBOARD_COL2_GetValue()           PORTDbits.RD5
#define KEYBOARD_COL2_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define KEYBOARD_COL2_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define KEYBOARD_COL2_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define KEYBOARD_COL2_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define KEYBOARD_COL2_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define KEYBOARD_COL2_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define KEYBOARD_COL2_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define KEYBOARD_COL2_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set KEYBOARD_COL3 aliases
#define KEYBOARD_COL3_TRIS                 TRISDbits.TRISD6
#define KEYBOARD_COL3_LAT                  LATDbits.LATD6
#define KEYBOARD_COL3_PORT                 PORTDbits.RD6
#define KEYBOARD_COL3_WPU                  WPUDbits.WPUD6
#define KEYBOARD_COL3_OD                   ODCONDbits.ODCD6
#define KEYBOARD_COL3_ANS                  ANSELDbits.ANSELD6
#define KEYBOARD_COL3_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define KEYBOARD_COL3_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define KEYBOARD_COL3_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define KEYBOARD_COL3_GetValue()           PORTDbits.RD6
#define KEYBOARD_COL3_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define KEYBOARD_COL3_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define KEYBOARD_COL3_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define KEYBOARD_COL3_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define KEYBOARD_COL3_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define KEYBOARD_COL3_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define KEYBOARD_COL3_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define KEYBOARD_COL3_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set KEYBOARD_COL4 aliases
#define KEYBOARD_COL4_TRIS                 TRISDbits.TRISD7
#define KEYBOARD_COL4_LAT                  LATDbits.LATD7
#define KEYBOARD_COL4_PORT                 PORTDbits.RD7
#define KEYBOARD_COL4_WPU                  WPUDbits.WPUD7
#define KEYBOARD_COL4_OD                   ODCONDbits.ODCD7
#define KEYBOARD_COL4_ANS                  ANSELDbits.ANSELD7
#define KEYBOARD_COL4_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define KEYBOARD_COL4_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define KEYBOARD_COL4_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define KEYBOARD_COL4_GetValue()           PORTDbits.RD7
#define KEYBOARD_COL4_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define KEYBOARD_COL4_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define KEYBOARD_COL4_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define KEYBOARD_COL4_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define KEYBOARD_COL4_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define KEYBOARD_COL4_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define KEYBOARD_COL4_SetAnalogMode()      do { ANSELDbits.ANSELD7 = 1; } while(0)
#define KEYBOARD_COL4_SetDigitalMode()     do { ANSELDbits.ANSELD7 = 0; } while(0)

// get/set KEYBOARD_COL5 aliases
#define KEYBOARD_COL5_TRIS                 TRISEbits.TRISE2
#define KEYBOARD_COL5_LAT                  LATEbits.LATE2
#define KEYBOARD_COL5_PORT                 PORTEbits.RE2
#define KEYBOARD_COL5_WPU                  WPUEbits.WPUE2
#define KEYBOARD_COL5_OD                   ODCONEbits.ODCE2
#define KEYBOARD_COL5_ANS                  ANSELEbits.ANSELE2
#define KEYBOARD_COL5_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define KEYBOARD_COL5_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define KEYBOARD_COL5_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define KEYBOARD_COL5_GetValue()           PORTEbits.RE2
#define KEYBOARD_COL5_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define KEYBOARD_COL5_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define KEYBOARD_COL5_SetPullup()          do { WPUEbits.WPUE2 = 1; } while(0)
#define KEYBOARD_COL5_ResetPullup()        do { WPUEbits.WPUE2 = 0; } while(0)
#define KEYBOARD_COL5_SetPushPull()        do { ODCONEbits.ODCE2 = 0; } while(0)
#define KEYBOARD_COL5_SetOpenDrain()       do { ODCONEbits.ODCE2 = 1; } while(0)
#define KEYBOARD_COL5_SetAnalogMode()      do { ANSELEbits.ANSELE2 = 1; } while(0)
#define KEYBOARD_COL5_SetDigitalMode()     do { ANSELEbits.ANSELE2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF0 pin functionality
 * @Example
    IOCCF0_ISR();
 */
void IOCCF0_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF0 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF0 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF0_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF0 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF0_SetInterruptHandler() method.
    This handler is called every time the IOCCF0 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF0_SetInterruptHandler(IOCCF0_InterruptHandler);

*/
extern void (*IOCCF0_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF0 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF0_SetInterruptHandler() method.
    This handler is called every time the IOCCF0 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF0_SetInterruptHandler(IOCCF0_DefaultInterruptHandler);

*/
void IOCCF0_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF1 pin functionality
 * @Example
    IOCCF1_ISR();
 */
void IOCCF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF1_SetInterruptHandler() method.
    This handler is called every time the IOCCF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(IOCCF1_InterruptHandler);

*/
extern void (*IOCCF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF1_SetInterruptHandler() method.
    This handler is called every time the IOCCF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(IOCCF1_DefaultInterruptHandler);

*/
void IOCCF1_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF2 pin functionality
 * @Example
    IOCCF2_ISR();
 */
void IOCCF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF2_SetInterruptHandler() method.
    This handler is called every time the IOCCF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(IOCCF2_InterruptHandler);

*/
extern void (*IOCCF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF2_SetInterruptHandler() method.
    This handler is called every time the IOCCF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(IOCCF2_DefaultInterruptHandler);

*/
void IOCCF2_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF7 pin functionality
 * @Example
    IOCCF7_ISR();
 */
void IOCCF7_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF7 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF7 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF7_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF7_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF7 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF7_SetInterruptHandler() method.
    This handler is called every time the IOCCF7 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF7_SetInterruptHandler(IOCCF7_InterruptHandler);

*/
extern void (*IOCCF7_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF7 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF7_SetInterruptHandler() method.
    This handler is called every time the IOCCF7 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF7_SetInterruptHandler(IOCCF7_DefaultInterruptHandler);

*/
void IOCCF7_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/