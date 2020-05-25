/*
 * @file ds1307.c
 * @author xpress_embedo
 * @date 1 Feb, 2020
 * 
 * @brief DS1307 RTC Functions
 *
 */

#include "ds1307.h"

/* Local Macros */
#define DS1307_ADDRESS        0xD0

/**
 * @brief Initialize I2C and Start RTC
 */
void DS1307_Init( void )
{
  I2C_Init(I2C_STANDARD_SPEED);
  I2C_Start();
  I2C_Send(DS1307_ADDRESS);
  I2C_Send(DS1307_OSC_HLT_ADD);
  I2C_Send(DS1307_EN_OSC);
  I2C_Stop();
}

/**
 * @brief Read Data from the specified address from the RTC
 * @param data_to_read address of the data to be read
 * @return BCD value of the read data
 */
uint8_t DS1307_Read( uint8_t data_to_read )
{
  uint8_t data = 0x00;
  I2C_Start ();
  I2C_Send (DS1307_ADDRESS);
  I2C_Send (data_to_read);
  I2C_Restart ();
  I2C_Send (DS1307_ADDRESS | 0x01);
  data = I2C_Read ();
  I2C_Stop ();
  return data;
}

/**
 * @brief Set the Date Time Information in the RTC
 * @param year Year to Set
 * @param month Month to Set
 * @param date Date to Set
 * @param day Day to Set
 * @param hour Hour to Set
 * @param minute Minute to Set
 * @param second Seconds to Set
 */
void DS1307_Set( uint8_t year, uint8_t month, uint8_t date, \
                uint8_t day, uint8_t hour, uint8_t min, uint8_t sec )
{
  // TODO:
}

/**
 * @brief Set the Date Information in the RTC
 * @param year Year to Set
 * @param month Month to Set
 * @param date Date to Set
 */
void DS1307_Set_Date( uint8_t year, uint8_t month, uint8_t date )
{
  // TODO:
}

/**
 * @brief Set the Time Information in the RTC
 * @param hour Hour to Set
 * @param minute Minute to Set
 * @param second Seconds to Set
 */
void DS1307_Set_Time( uint8_t hour, uint8_t min, uint8_t sec )
{
  // TODO:
}

/**
 * @brief Convert BCD Data into Lower Character
 * @param bcd_value BCD Value
 * @return Character value of BCD Lower Nipple
 */
uint8_t BCD2LowerCh( uint8_t bcd_value )
{
  uint8_t temp;
  temp = bcd_value & 0x0F;  // Mask Lower Nibble
  temp = temp | 0x30;       // Convert to Character
  return temp;
}

/**
 * @brief Convert BCD Data into Upper Character
 * @param bcd_value BCD Value
 * @return Character value of BCD Upper Nipple
 */
uint8_t BCD2UpperCh( uint8_t bcd_value )
{
  uint8_t temp;
  temp = bcd_value >> 4u;   // Extract Upper Nibble
  temp = temp | 0x30;       // Convert to Character
  return temp;
}

/**
 * @brief Convert BCD Data into Decimal Number
 * @param bcd_value BCD Value
 * @return Decimal Value
 */
uint8_t BCD2Decimal( uint8_t bcd_value )
{
  uint8_t decimal;
  // TODO: check BCD Limits
  decimal = ((bcd_value & 0xF0) >> 4) * 10 + (bcd_value & 0x0F);
  return decimal;
}

