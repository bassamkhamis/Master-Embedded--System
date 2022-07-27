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
#define F_CPU 1000000UL


#define MASTER_MODE
//#define SLAVE_MODE


// port b
#define SS             4
#define MOSI           5
#define MISO           6
#define  SCK           7

u8 arr[]={0x01,0x12,0x23,0x34,0x45,0x56,0x67,0x78,0x89,0x90};

int main()
{
	SPI_ConfigType config;
	config.CLK = SPI_Fosc4;
	config.DoubleSpedd = SPI_DOUBLE_SPEDD_DISABLE;
	config.CLK_Polarity = SPI_IDL_CLK_LOW;
	config.Sampling_EDG = SPI_Second_EDG;
	config.Enable= SPI_Enable_ON;
	config.interrupt_state = SPI_interruptDisable;
	config.order = SPI_MSB;

	#ifdef MASTER_MODE
	config.mode = SPI_MODE_Master;
	DDRB |=  1<<MOSI  | 1<<SS   | 1<<SCK;
	/* Set MISO input */
	DDRB &= ~(1<<MISO);
	#endif

	#ifdef SLAVE_MODE

	config.mode = SPI_Mode_Slave;
	DDRB |=  1<<MISO;
	/* Set MOSI, SCK and SS input*/
	DDRB &= ~(1<<MOSI) & ~(1<<SCK) & ~(1<<SS);
	#endif

	//port A as Output
	DDRA = 0xFF;
	//port C as Output
	DDRC = 0xFF;
    MCAL_SPI_Init(&config);

	while (1){



		for(char i=0; i<10; i++){

		PORTA = MCAL_SPI_SendAndReceive(arr[i]);


		_delay_ms(150);
		}

	}


}
