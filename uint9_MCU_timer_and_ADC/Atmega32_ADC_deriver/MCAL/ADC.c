/*
 * ADC.c
 *
 *  Created on: Aug 10, 2022
 *      Author: bassa
 */


//*************************************************************
//*********************       Includes   **********************
//*************************************************************
#include "ADC.h"


//*************************************************************
//******************* APIs Implementation**********************
//*************************************************************
void MCAL_ADC_Init(ADC_VREF_t  LVref, ADC_PRESCALER_t Lprescaller)
{
   // Set Volt Referrance
	ADMUX |= LVref ;

	// Set Prescaler
	ADCSRA &= 0xF8;
	ADCSRA |= Lprescaller;


	// Enable ADC
	ADCSRA |= 1<<ADEN ;   //bin 7
}


u16 MCAL_ADC_READ(ADC_CHANNEL_t LCHn)
{
   // select channel
	ADMUX &= 0xE0;  // Clear first 5 bit
	ADMUX |= LCHn;

	// Start conversion
	ADCSRA |= 1<<ADSC   ;    //bin 6

	while( (ADCSRA & 1<<ADSC) );

	return ADC;
}
