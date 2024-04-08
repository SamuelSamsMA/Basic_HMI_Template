/*
 * File: sipo_reg595.h
 * Author: Samuel Muñoz Aguilar
 * 
 * This library was made for driving the 74HC595 registers connected in
 * serie, so many digital outputs are obtained with only four control
 * pins and the SPI peripheral.
 * 
 * Created on February 5th, 2024
 */

#ifndef SIPO_REG595_H
#define	SIPO_REG595_H


// Number of registers installed on the board
#define SIPO_REG_SIZE_IN_BYTES	2


// Pin assignment for modules
#define GLCD_RS         (1U << 7)
#define GLCD_EN         (1U << 6)
#define GLCD_DB0        (1U << 5)
#define GLCD_DB1        (1U << 4)
#define GLCD_DB2        (1U << 3)
#define GLCD_DB3        (1U << 2)
#define GLCD_DB4        (1U << 1)
#define GLCD_DB5        (1U << 0)
#define GLCD_DB6        (1U << 15)
#define GLCD_DB7        (1U << 14)
#define GLCD_CS1        (1U << 13)
#define GLCD_RST        (1U << 12)
#define GLCD_CS2        (1U << 11)
#define GLCD_CS3        (1U << 10)


//********************************************************************
//						SIPO_REG_initialize()
//  Description:
//      Configures the output pins and the SPI peripherial for driving
//      the Serial-In Parallel-Out (SIPO) register.
//********************************************************************
void SIPO_REG_initialize(void);


//********************************************************************
//						SIPO_REG_setWithMask()
//  Description:
//      Changes the logic state of one or more outputs at time.
//  Parameters:
//      position: word whose high bits indicate the outputs to
//                be updated.
//      value: 0 -> outputs are reset
//             1 -> outputs are set
//********************************************************************
void SIPO_REG_setWithMask(uint16_t position, bool value);


//********************************************************************
//							SIPO_REG_set()
//  Description:
//		Envía una palabra que representa el estado de las
//		salidas del registro de corrimiento.
//  Parameters:
//      outputs: valor lógico de las salidas.
//********************************************************************
void SIPO_REG_set(uint16_t output);

#endif	/* SIPO_REG595_H */

