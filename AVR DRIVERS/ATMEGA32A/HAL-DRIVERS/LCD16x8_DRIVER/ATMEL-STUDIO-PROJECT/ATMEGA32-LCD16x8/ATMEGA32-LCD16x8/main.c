/**
 * @file main.c
 * @author Mohamed El Barbary (mohmbarbary@gmail.com)
 * @brief This is the main function that is used to test the functionality of our LCD16x8 Driver. !PLEASE DON'T FORGET TO USE DELAYS!
 * @version 1.0
 * @date 5-02-2021 9:57:56 PM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */

#include "LSTD_TYPES.h"
#include "LSTD_BITMATH.h"
#include "HAL_LCD_interface.h"

#define F_CPU 16000000UL
#include "util/delay.h"

#define PUSHB0 PIN0 //PORT B
#define PUSHB1 PIN4 //PORT B
#define PUSHB2 PIN2 //PORT D


int main(void)
{
    u8_t au8_i = 0;
	u8_t au8_gobk = au8_i;
	
	HAL_LCD_init();
	HAL_LCD_putAtLoc(HAL_LCD_ROW01, HAL_LCD_COL02);
	HAL_LCD_displayString((u8_t*)"Barbary");
	
	_delay_ms(500);
	
	HAL_LCD_clearDisplay();

    while (1) 
    {
		for(au8_i = 0, au8_gobk = 0; au8_i <= 125; au8_i++, au8_gobk++)
		{

			if(au8_gobk == 16)
			{
				au8_gobk = 0;
			}
			HAL_LCD_putAtLoc(HAL_LCD_ROW00, au8_gobk);
			HAL_LCD_displayCharacter(au8_i + 42);
			
			_delay_ms(50);
			HAL_LCD_putAtLoc(HAL_LCD_ROW01, au8_gobk);
			_delay_ms(50);
			HAL_LCD_displayCharacter(au8_i + 42);
			
			_delay_ms(1000);
			
			HAL_LCD_clearDisplay();
		}

    }
	return 0;
}

