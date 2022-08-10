/*
 * ADC.h
 *
 *  Created on: Aug 10, 2022
 *      Author: bassa
 */

#ifndef MCAL_ADC_H_
#define MCAL_ADC_H_

//*************************************************************
//********************* Includes **********************
//*************************************************************

#include <avr/io.h>
//#include <util/delay.h>
#include <avr/interrupt.h>
#include "../STD_TYPES.h"
#include "../utils.h"



//*************************************************************
//********************* Macros Define **********************
//*************************************************************

#define Vref           5000
#define Res            1024

//*************************************************************
//********************* Define Data types**********************
//*************************************************************

typedef enum{
	VREF_AREF,
	VREF_AVCC = 0x40,
	VREF_265 = 0xC0

}ADC_VREF_t;

typedef enum{
	 ADC_Prescaler2,
	 ADC_Prescaler4 =0x2,
	 ADC_Prescaler8,
	 ADC_Prescaler16,
	 ADC_Prescaler32,
	 ADC_Prescaler64,
	 ADC_Prescaler128,

}ADC_PRESCALER_t;

typedef enum{
	ADC_CH0 = 0,
	ADC_CH1,
	ADC_CH2,
	ADC_CH3,
	ADC_CH4,
	ADC_CH5,
	ADC_CH6,
	ADC_CH7

}ADC_CHANNEL_t;


//*************************************************************
//*********************       APIs       **********************

void MCAL_ADC_Init(ADC_VREF_t  LVref,ADC_PRESCALER_t Lprescaller);
u16 MCAL_ADC_READ(ADC_CHANNEL_t LCHn);



//*************************************************************

#endif /* MCAL_ADC_H_ */
