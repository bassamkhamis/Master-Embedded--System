/*
 * main.c
 *
 *  Created on: Apr 9, 2022
 *      Author: bassa
 */


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(INT0_vect)
{
	PORTA |= 0x01;
	_delay_ms(500);
	PORTA &= ~(0x01);
	_delay_ms(500);

}
ISR(INT1_vect)
{
	PORTA |= 0x02;
	_delay_ms(500);
	PORTA &= ~(0x02);
	_delay_ms(500);

}

ISR(INT2_vect)
{
	PORTA |= 0x04;
	_delay_ms(500);
	PORTA &= ~(0x04);
	_delay_ms(500);

}




int main()
{
	//set pin 0,1,2 in PORTA as a output
	DDRA |= 0x07;
	//set pin 2,3 in PORTA as a input
	DDRD &= ~(0b00<<2);
	// set pin 2 in PORTB as a input
	DDRB &= ~(1<<2);
    // enable global interrupt
	SREG |= 1<<7;
	//Enable 3 interrupt EXTI0,ETI1,EXTI2
    GICR  |= (0b111<<5);
    //EXTI0 as a Any logical change, EXTI1 as a rising edge
    MCUCR |= (0b1101);
    //EXTI2 as a falling edge
    MCUCSR= (0b0)<<6;
   // PORTA |= 0x01;
   while(1)
   {



   }

}
