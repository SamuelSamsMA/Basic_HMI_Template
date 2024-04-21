#include "mcc_generated_files/mcc.h"
#include "eeprom_24c32.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"


void EEPROM_writePage(uint8_t page, uint8_t* dataArray)
{
	unsigned int regDir = page * EEPROM_PAGE_SIZE;
	uint8_t buffer[EEPROM_PAGE_SIZE + 2];
	
	*(buffer + 0) = (uint8_t)((regDir & 0x0F00) >> 8);
	*(buffer + 1) = (uint8_t)(regDir & 0x00FF);
	
	for (uint8_t i = 0; i < EEPROM_PAGE_SIZE; i++)
		*(buffer + i + 2) = *(dataArray + i);
	
	I2C1_WriteNBytes(EEPROM_SLAVE_ADDR, buffer, sizeof(buffer));
}


void EEPROM_readPage(uint8_t page, uint8_t* dataArray)
{
	unsigned int regDir = page * EEPROM_PAGE_SIZE;
	uint8_t buffer[2];
	
	*(buffer + 0) = (uint8_t)((regDir & 0x0F00) >> 8);
	*(buffer + 1) = (uint8_t)(regDir & 0x00FF);
	
	I2C1_WriteNBytes(EEPROM_SLAVE_ADDR, buffer, sizeof(buffer));
	
	I2C1_ReadNBytes(EEPROM_SLAVE_ADDR, dataArray, sizeof(dataArray));
}