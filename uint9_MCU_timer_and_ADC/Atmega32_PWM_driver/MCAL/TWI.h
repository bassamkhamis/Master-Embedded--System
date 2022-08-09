/*
 * TWI.h
 *
 *  Created on: Jul 30, 2022
 *      Author: bassa
 */

#ifndef MCAL_TWI_H_
#define MCAL_TWI_H_

#include "../STD_TYPES.h"







//******************************************************
//********** Struct and enum data types ******************
//********************************************************



typedef enum {

	MASTER_TRANSMIT = 0,
	MASTER_RECEIVE,
	SLAVE_TRANSMIT,
	SLAVE_RECEIVE

}TWI_Mode;

typedef u8 SerialCLK_t;

typedef u8 Address_t;


typedef struct {

	TWI_Mode mode;
	SerialCLK_t SerialCLK;
	Address_t Address_Slave;

}TWI_typedef;



//******************************************************
//**********Function Declaration*************************
//********************************************************


void MCAL_TWI_Init(TWI_typedef *TWIconfig);

void MCAL_TWI_Write(u8 Ldata);

u8 MCAL_TWI_Read(void);






#endif /* MCAL_TWI_H_ */
