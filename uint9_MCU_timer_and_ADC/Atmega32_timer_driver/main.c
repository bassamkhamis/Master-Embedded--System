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



#undef F_CPU
#define F_CPU 1000000UL





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

int main()
{


	 DDRB |= 1<<3; //CO0
	 ST_PWM0Config_t configPWM = {PWM_PHASE_CORRECT,PWM_PRESCALING_CLK64,PWM_TOF_DISABLE,PWM_Non_Inverted};
	 PWM0_SetComapreValue(128);  // Duty cycle = 0.5
	 PWM0_Init(&configPWM);




//	    DDRA = 0xFF ;
//	   DDRB |= 1<<3; //CO0
//
//	 TIMER0_SetCallBack_OVERFLOW(TIMER0_OVF_CallBack);
//	ST_TIMER0Config_t config = {NORMAL, PRESCALING_CLK1024,OCMI_DISABLE,TOF_ENABLE};
//	TIMER0_SetOverflowValue(10);
//	//TIMER0_SetComapreValue(0xFF);
//	SET_BIT(TCCR0,COM00);
//	TIMER0_Init(&config);


//    DDRA = 0xFF ;
//    DDRB |= 1<<3; //CO0
//    sei();
//	TIMER0_SetCallBack_CompareMatch(TIMER0_CopareMatch_CallBack);
//	ST_TIMER0Config_t config = {CTC, PRESCALING_CLK1024,OCMI_ENABLE,TOF_DISABLE};
//	TIMER0_SetComapreValue(0xFF);
//	SET_BIT(TCCR0,COM00);
//    TIMER0_Init(&config);

	while(1)
	{


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




