#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"
#include "rtc_ds3231.h"


static unsigned char bcd_to_binary(unsigned char num)
{
  return ((num >> 4) * 10 + (num & 0x0F));
}

static unsigned char binary_to_bcd(unsigned char num)
{
  return (unsigned char)(((num / 10) << 4) + (num % 10));
}


void RTC_initialize(void)
{
	uint8_t buffer[] = {RTC_CONTROL_REG, 0};
	I2C1_WriteNBytes(RTC_SLAVE_ADDR, buffer, sizeof(buffer));
}


void RTC_readHMS(TIME* t)
{
	// Send the address of the register
	uint8_t reg = RTC_SECONDS_REG;
	I2C1_WriteNBytes(RTC_SLAVE_ADDR, &reg, 1);
	
	// Read three consecutive bytes (HH, MM, SS)
	uint8_t buffer[3];
	I2C1_ReadNBytes(RTC_SLAVE_ADDR, buffer, sizeof(buffer));
	
	t->seconds = bcd_to_binary(buffer[0]);
	t->minutes = bcd_to_binary(buffer[1]);
	t->hours = bcd_to_binary(buffer[2]);
}


void RTC_writeHMS(TIME* t)
{
	uint8_t buffer[] = {
		RTC_SECONDS_REG,
		binary_to_bcd(t->seconds),
		binary_to_bcd(t->minutes),
		binary_to_bcd(t->hours)
	};
	
	I2C1_WriteNBytes(RTC_SLAVE_ADDR, buffer, sizeof(buffer));
}


void RTC_readDMY(TIME* t)
{
	// Send the address of the register
	uint8_t reg = RTC_DATE_REG;
	I2C1_WriteNBytes(RTC_SLAVE_ADDR, &reg, 1);
	
	// Read three consecutive bytes (DD, MM, YY)
	uint8_t buffer[3];
	I2C1_ReadNBytes(RTC_SLAVE_ADDR, buffer, sizeof(buffer));
	
	t->date = bcd_to_binary(buffer[0]);
	t->month = bcd_to_binary(buffer[1]);
	t->year = bcd_to_binary(buffer[2]);
}


void RTC_writeDMY(TIME* t)
{
	uint8_t buffer[] = {
		RTC_DATE_REG,
		binary_to_bcd(t->date),
		binary_to_bcd(t->month),
		binary_to_bcd(t->year)
	};
	
	I2C1_WriteNBytes(RTC_SLAVE_ADDR, buffer, sizeof(buffer));
}


