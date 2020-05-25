/*
 * @file ds1307.h
 * @author xpress_embedo
 * @date 1 Feb, 2020
 * 
 * @brief DS1307 RTC Functions
 *
 */

#ifndef DS1307_H
#define	DS1307_H

#include "I2C.h"

#ifdef	__cplusplus
extern "C"
{
#endif

/* Public Macros */
#define DS1307_OSC_HLT_ADD    0x00
#define DS1307_STOP_OSC       0x80
#define DS1307_EN_OSC         0x00
  
#define DS1307_SEC            0x00
#define DS1307_MIN            0x01
#define DS1307_HOUR           0x02
#define DS1307_DAY            0x03
#define DS1307_DATE           0x04
#define DS1307_MONTH          0x05
#define DS1307_YEAR           0x06
  
/* Public Functions */
void DS1307_Init( void );
uint8_t DS1307_Read( uint8_t data_to_read );
void DS1307_Set( uint8_t year, uint8_t month, uint8_t date, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec );
void DS1307_Set_Date( uint8_t year, uint8_t month, uint8_t date );
void DS1307_Set_Time( uint8_t hour, uint8_t min, uint8_t sec );
uint8_t BCD2LowerCh( uint8_t bcd_value );
uint8_t BCD2UpperCh( uint8_t bcd_value );
uint8_t BCD2Decimal( uint8_t bcd_value );
  
#ifdef	__cplusplus
}
#endif

#endif	/* DS1307_H */

