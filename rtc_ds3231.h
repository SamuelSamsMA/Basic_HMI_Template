/* 
 * File:   rtc_ds3231.h
 * Author: Samuel Muñoz Aguilar
 *
 * Created on March 26, 2024
 */

#ifndef RTC_DS3231_H
#define	RTC_DS3231_H


//
// I2C physical address
//
#define RTC_SLAVE_ADDR			0xD0>>1


//
// Structure to read/write time with module
//
typedef struct {
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;
	uint8_t date;
	uint8_t month;
	uint8_t year;
} TIME;


//
// Register addresses
//
#define RTC_SECONDS_REG         0x00
#define RTC_MINUTES_REG         0x01
#define RTC_HOURS_REG           0x02
#define RTC_DAY_REG             0x03
#define RTC_DATE_REG            0x04
#define RTC_MONTHCENTURY_REG    0x05
#define RTC_YEAR_REG            0x06
#define RTC_CONTROL_REG         0x0E
#define RTC_CONTROLSTATUS_REG   0x0F


void RTC_initialize(void);

void RTC_readHMS(TIME* t);

void RTC_writeHMS(TIME* t);

void RTC_readDMY(TIME* t);

void RTC_writeDMY(TIME* t);

#endif	/* RTC_DS3231_H */

