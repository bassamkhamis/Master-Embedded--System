/*
 * MAX7221.c
 *
 *  Created on: Jul 27, 2022
 *      Author: bassa
 */


#include "../MCAL/SPI.h"
#include "MAX7221.h"
#include <avr/io.h>


void HAL_MAX7221Init(){
	SPI_ConfigType config;
		config.CLK = SPI_Fosc4;
		config.DoubleSpedd = SPI_DOUBLE_SPEDD_DISABLE;
		config.CLK_Polarity = SPI_IDL_CLK_LOW;
		config.Sampling_EDG = SPI_First_EDG;
		config.Enable= SPI_Enable_ON;
		config.interrupt_state = SPI_interruptDisable;
		config.order = SPI_MSB;
		config.mode = SPI_MODE_Master;


		DDRB |=  1<<MOSI  | 1<<SS   | 1<<SCK;
		/* Set MISO input */
		DDRB &= ~(1<<MISO);

		 MCAL_SPI_Init(&config);
}

void HAL_MAX7221_Send(u8 cmd, u8 data){



	PORTB &= ~(1<<SS);  //drive low
	MCAL_SPI_Send(cmd);  //write CMD
	MCAL_SPI_Send(data); //Write Data
	PORTB |= (1<<SS);   // drive High




}

