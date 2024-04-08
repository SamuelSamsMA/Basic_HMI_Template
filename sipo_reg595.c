#include "mcc_generated_files/mcc.h"
#include "sipo_reg595.h"

// Keeps track of 74hc595 outputs registers
static uint16_t outputRegister_595;


void SIPO_REG_initialize(void)
{
	OE_HC595_SetHigh();			// Disnable outputs
	RCLK_HC595_SetLow();
	SPI1_Open(SPI1_DEFAULT);
	SIPO_REG_set(0);			// Clear all outputs
	OE_HC595_SetLow();			// Enable outputs
}


void SIPO_REG_setWithMask(uint16_t position, bool value)
{
    uint16_t temp;

    if (value)
        temp = outputRegister_595 | position;
    else
        temp = outputRegister_595 & (~position);
    
    SIPO_REG_set(temp);
}


void SIPO_REG_set(uint16_t output)
{
	uint8_t data[SIPO_REG_SIZE_IN_BYTES];
	data[0] = (uint8_t)(output & 0x00FF);
	data[1] = (uint8_t)((output >> 8) & 0x00FF);
//	data[2] = (uint8_t)((output >> 16) & 0x00FF);
	
	SPI1_WriteBlock((void*)data, SIPO_REG_SIZE_IN_BYTES);
	
	RCLK_HC595_SetHigh();
	__delay_us(2);
	RCLK_HC595_SetLow();
	
	outputRegister_595 = output;
}
