/*
 * main.c
 *
 *  Created on: Jul 10, 2022
 *      Author: bassam
 */

#include "HAL/keypad.h"
#include "HAL/lcd.h"
#include "MCAL/UART.h"
#include "utils.h"
#include "STD_TYPES.h"

#define F_CPU 8000000UL

int main()
{
   LCD_INIT();
 //  _delay_ms(30);
   UART_Init();
   Keypad_init();

 //  LCD_WRITE_STRING("UART Section:");
   _delay_ms(10);
  UART_Init();
  //UART_SendChar('B');
  //UART_SendChar(10);
 //UART_SendChar('A');
 //LCD_WRITE_STRING((char *)arr); u8 arr[16];
  u8 val;
  char count=0;


 // unsigned char X;
	while (1){
/*
     UART_ReceiveString(arr, 16);
        LCD_GOTO_XY(2,0);
      LCD_WRITE_STRING((char *)arr);
*/

		if(UART_Receive_periodChech(&val))
		{
			LCD_GOTO_XY(2,0);
			LCD_WRITE_CHAR(val);
		}

		LCD_GOTO_XY(1,0);
		LCD_WRITE_STRING("count = ");
		LCD_WRITE_CHAR('1');
		count++;
		if(count == 10 )
		{
			count =0;
		}

     _delay_ms(500);


	}


}
