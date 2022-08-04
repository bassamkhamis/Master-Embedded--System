/*
 * main.c
 *
 *  Created on: Jul 10, 2022
 *      Author: bassam
 */

//#include "HAL/keypad.h"
//#include "HAL/lcd.h"

#include "MCAL/UART.h"
#include "MCAL/SPI.h"
#include <util/delay.h>
#include "STD_TYPES.h"
#include "HAL/MAX7221.h"
#include "MCAL/TWI.h"



#undef F_CPU
#define F_CPU 8000000UL









int main()
{

    // Set pin 0,7 as output
    DDRC |= 1<<0 | 1<<7 ;

       _delay_ms(400);  // delay to see pin 7 at reset state

        PORTC |= 1<<7 ;


		while (1)
		{
          MCAL_WDT_ON();
          PORTC |= 1<<0 ;
          _delay_ms(1010);
          MCAL_WDT_OFF();
		}

}


//LAB 1  MASTER Send =======> Slave Receive
//			// Master
//			MCAL_TWI_Write(arr[count++]  );
//
//			if(count == 9)
//				count = 0 ;
//			_delay_ms(500);



//
//			count = MCAL_TWI_Read()           ;
//			PORTA = count ;
//            _delay_ms(500);




