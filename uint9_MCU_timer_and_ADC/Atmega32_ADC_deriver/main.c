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
//#include "MCAL/Timer.h"
#include "MCAL/PWM.h"
#include "MCAL/ADC.h"
#include "HAL/lcd.h"



#undef F_CPU
#define F_CPU 8000000UL





//volatile u8 u8_OVF_Value = 0 ;
//
//void TIMER0_OVF_CallBack(void)
//{
//
//	TIMER0_GetOverflowValue( &u8_OVF_Value );
//    if(  (u8_OVF_Value % 10)  ==  0 )
//	  PORTA = ~PORTA ;
//}
//
//void TIMER0_CopareMatch_CallBack(void)
//{
//	TIMER0_GetOverflowValue( &u8_OVF_Value );
//    if(  (u8_OVF_Value % 10)  ==  0 )
//	  PORTA = ~PORTA ;
//}


void itoa(int val, char buffer[] ){

	int reminder;
    int count=0;
    int num = val;
    int Len =0 ;


    if( 0 == val)
    {
        buffer[count++] = '0';
        buffer[count] ='\0';

    }
    else
    {

    	while(num > 0)
    	    {
                Len++;
    	        num = num / 10 ;
    	    }

       for(int i=0; i<Len; i++)
       {
        reminder = val % 10 ;
        buffer[(Len -1) - (count++)] = reminder + '0' ;
        val = val / 10 ;
       }
    buffer[Len] ='\0';
    }
}
int main()
{
    LCD_INIT();
    MCAL_ADC_Init(VREF_AVCC,ADC_Prescaler64);
   // LCD_GOTO_XY(1,0);
    LCD_WRITE_STRING("ADC Reading ");
    _delay_ms(20);

   // int adc_val;
    long int adc_VOLT;
    char buffer[6];



	while(1)
	{
		//Test one
//        LCD_clear_screen();
//        adc_val = MCAL_ADC_READ(ADC_CH0);
//        itoa(adc_val,buffer,4);
//        LCD_WRITE_STRING(buffer);
//       _delay_ms(200);
            
			// Test Two
		        LCD_clear_screen();
		        adc_VOLT = ( (u32)MCAL_ADC_READ(ADC_CH0)*5000 )/Res  ;
		        itoa(adc_VOLT,buffer);
		        LCD_WRITE_STRING(buffer);
		        LCD_WRITE_STRING(" mv");
		       _delay_ms(100);


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




