/*
 * SPI.c
 *
 *  Created on: Jul 27, 2022
 *      Author: bassa
 */

#include "SPI.h"
#include <avr/io.h>
#include "../utils.h"
#include "../STD_TYPES.h"
#include "avr/interrupt.h"



static void (*SPI_ISR)(void);

void MCAL_SPI_Init(SPI_ConfigType* config){

	u8 tempConfig = 0;
	//Set mode Master/Slave
	tempConfig |= (config->mode)<<MSTR;

	//Set CLK polarity
	tempConfig |= (config->CLK_Polarity)<<CPOL ;// operate only IDEL low// its a bug in software (proteus)


	//Set CLK Phase
	tempConfig |= (config->Sampling_EDG)<<CPHA ;

	//Set CLK polarity
	tempConfig |= (config->order)<<DORD ;

	//Set CLK polarity
	tempConfig |= (config->CLK)<<SPR0 ;

	//Set Double SPEED
	SPSR |= (config->DoubleSpedd)<<SPI2X;

	//Set interrupt
	tempConfig |= (config->interrupt_state)<<SPIE ;


	//Enable SPI
	tempConfig |= (config->Enable)<<SPE;

	SPCR |= tempConfig;

}

u8 MCAL_SPI_SendAndReceive(u8 Copy_Data){

	//PORTC ^= 0xFF;
	SPDR = Copy_Data; //write dtat

	while( !( SPSR&(1<<SPIF) ) );

	return SPDR ;

}
void MCAL_SPI_Send(u8 Copy_Data){

	   SPDR = Copy_Data; //write dtat

		while( !( SPSR&(1<<SPIF) ) );
}
u8 MCAL_SPI_CheckForCollsion(void){

  u8 localData = READ_BIT(SPSR, WCOL);

  return localData;
}
void MCAL_SPI_AssignCallBack(void (*PCallBack)(void)){

	SPI_ISR = PCallBack;

}
ISR(SPI_STC_vect){

	SPI_ISR();

}
