/*
 * TWI.c
 *
 *  Created on: Jul 30, 2022
 *      Author: bassa
 */


#include "TWI.h"
#include <avr/io.h>
#include "../utils.h"
#include "../STD_TYPES.h"
#include "avr/interrupt.h"

#undef F_CPU
#define F_CPU 1000000UL

TWI_typedef *GTWIconfig ;

void MCAL_TWI_Init(TWI_typedef *TWIconfig)
{
	GTWIconfig = TWIconfig;

	// check master:
	if(TWIconfig->mode == MASTER_RECEIVE || TWIconfig->mode == MASTER_TRANSMIT )
	{
		TWBR =  ( (  (F_CPU/TWIconfig->SerialCLK) -16 ) / 2 )  ;  //Per scaler always 1
	}


	// check slave:
	else if(TWIconfig->mode == SLAVE_RECEIVE || TWIconfig->mode == SLAVE_TRANSMIT)
	{
		TWAR = TWIconfig->Address_Slave;
	}


}


void MCAL_TWI_Write(u8 Ldata)
{
	if(GTWIconfig->mode == MASTER_TRANSMIT)
	{
		TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);   // send Start Condition
		while (!(TWCR & (1<<TWINT)));                 // wait until flag set
		while ( TWSR  != 0x08 );                      // wait status register to confirm

		TWDR = GTWIconfig->Address_Slave + 0 ;       // write address of slave + W =0 write
		TWCR = (1<<TWINT) | (1<<TWEN);              // Reset flag of interrupt
		while (!(TWCR & (1<<TWINT)));              // wait until flag set
		while ( TWSR  != 0x18 );                    // wait status register to confirm

		TWDR = Ldata;                             //write data
		TWCR = (1<<TWINT) | (1<<TWEN);             // Reset flag of interrupt and Enable TWI
		while (!(TWCR & (1<<TWINT)));              // wait until flag set
		while ( TWSR  != 0x28 );                   // wait status register to confirm

		TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO); // stop condition


	}
	else if(GTWIconfig->mode == MASTER_RECEIVE)
	{
		TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);   // send Start Condition
		while (!(TWCR & (1<<TWINT)));                 // wait until flag set
		while ( TWSR  != 0x08 );                      // wait status register to confirm
       // _delay_ms(10);
		TWDR = GTWIconfig->Address_Slave + 0x01 ;       // write address of slave + W =0 write
		TWCR = (1<<TWINT) | (1<<TWEN);              // Reset flag of interrupt
		while (!(TWCR & (1<<TWINT)));              // wait until flag set
		//while ( TWSR  != 0x40 );                    // wait status register to confirm
	}
	if(GTWIconfig->mode == SLAVE_TRANSMIT)
	{
//		TWCR = (1<<TWINT) | (1<<TWEN);               // Enable TWI and Clear flag
//		while (!(TWCR & (1<<TWINT)));                 // wait until flag set
//		while ( TWSR  != 0xA8 );                      // wait status register to confirm

		TWDR = Ldata;                             //write data
		TWCR = (1<<TWINT) | (1<<TWEN);             // Reset flag of interrupt and Enable TWI
		while (!(TWCR & (1<<TWINT)));              // wait until flag set
	  // while ( TWSR  != 0xB8 );                   // wait status register to confirm

	}
	//	if(GTWIconfig->mode == SLAVE_RECEIVE)  // N/A
	//	{
	//
	//	}

}


u8 MCAL_TWI_Read(void)
{
	u8 Ldata = 0;

	if(GTWIconfig->mode == MASTER_RECEIVE)
	{
		TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
		while (!(TWCR & (1<<TWINT)));              // wait until flag set
		//while ( TWSR  != 0x50 );                   // wait status register to confirm
		Ldata = TWDR ;

		TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO); // stop condition
	}

	else if(GTWIconfig->mode == SLAVE_RECEIVE)
	{
		TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
		while (!(TWCR & (1<<TWINT)));              // wait until flag set
		while ( TWSR  != 0x60 );                   // wait status register to confirm

		TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
		while (!(TWCR & (1<<TWINT)));              // wait until flag set
		//while ( TWSR  != 0x80 );                   // wait status register to confirm
		//Ldata = TWDR ;
	}


	else if(GTWIconfig->mode == SLAVE_TRANSMIT)
	{
		TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
		while (!(TWCR & (1<<TWINT)));              // wait until flag set
		while ( TWSR  != 0xA8 );                   // wait status register to confirm
		Ldata = TWDR ;


	}

	return Ldata;
}


