/* 
 * File:   eeprom_24c32.h
 * Author: Samuel Muñoz Aguilar
 *
 * Created on April 20, 2024
 */

#ifndef EEPROM_24C32_H
#define	EEPROM_24C32_H

//
// I2C physical address
//
#define EEPROM_SLAVE_ADDR		0xAE>>1

#define EEPROM_PAGE_SIZE		32


void EEPROM_writePage(uint8_t page, uint8_t* dataArray);


void EEPROM_readPage(uint8_t page, uint8_t* dataArray);

#endif	/* EEPROM_24C32_H */

