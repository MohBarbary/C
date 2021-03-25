/**
 * @file main.c
 * @author Mohamed El Barbary (Mohmbarbary@gmail.com)
 * @brief This is the main file for the AVR-ATMEGA32A GPIO DRIVER.
 * @version 1.0
 * @date 2021-01-29 10:19:20 PM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */

#include "LSTD_BITMATH.h"		 /*Including bit-math operations. */
#include "LSTD_TYPES.h"			 /*Including the standard types.  */
#include "MCAL_GPIO_interface.h" /*Including custom GPIO commands.*/

//#define F_CPU 16000000UL		 /*Don't forget to include the AVR delay.h or make your own delay*/
//#include <utils/delay.h>


#define LED0 (PIN2)					/*Port C*/
#define LED1 (PIN7)					/*Port C*/
#define LED2 (PIN3)					/*Port D*/

#define PUSHB0  (PIN0)				/*Port B*/
#define PUSHB1  (PIN4)				/*Port B*/
#define PUSHB2  (PIN2)				/*Port D*/

/**
 * @brief This main functions tests the GPIO DRIVER driver functions MCAL_GPIO_PinMode and MCAL_GPIO_PinState.
 * 
 * @return returns 0 on successful and -1 if an error occurs  
 */
int main(void)
{
	
	MCAL_GPIO_PinMode(PORTC, (LED0 | LED1), OUTPUT);	
	MCAL_GPIO_PinMode(PORTD, LED2, OUTPUT);
	
	MCAL_GPIO_PinMode(PORTB, (PUSHB0 | PUSHB1), INPUT_FLOAT);
	MCAL_GPIO_PinMode(PORTD, PUSHB2, INPUT_FLOAT);
	
	MCAL_GPIO_PinMode(PORTA, PIN2, OUTPUT);

	
	
	while (1)				
    {
		
		MCAL_GPIO_PinState(PORTA, PIN2, HIGH);
		//_delay_ms(3000);
		MCAL_GPIO_PinState(PORTA, PIN2, LOW);
		//_delay_ms(3000);
		
			
    }
	return 0;
}

