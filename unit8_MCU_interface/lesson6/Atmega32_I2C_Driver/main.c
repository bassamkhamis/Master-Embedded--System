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

//#define F_CPU 1000000UL


//#define MASTER_MODE
//#define SLAVE_MODE






int main()
{


	// init TWI


	TWI_typedef LTWIconfig;
	LTWIconfig.SerialCLK =72 ;
	LTWIconfig.mode = SLAVE_TRANSMIT;
	LTWIconfig.Address_Slave = 0b11010000;

	MCAL_TWI_Init(&LTWIconfig);



    // DDRA
	DDRA=0xFF;

	// variables
	int  count = 0;
	u8 arr[]={0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39};

		while (1)
		{

          // for Master Receive
//            MCAL_TWI_Write(0b11010000 + 1) ;  //The address is Dummy
//
//            PORTA = MCAL_TWI_Read();      // read and write on port A
//
//            _delay_ms(500);


			//for Slave Send
            MCAL_TWI_Read() ;
			MCAL_TWI_Write(arr[count++]) ;
			if(count == 9)
				count = 0 ;
			//_delay_ms(400);



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




