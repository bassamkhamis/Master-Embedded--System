/*
 * SPI.h
 *
 *  Created on: Jul 27, 2022
 *      Author: bassa
 */

#include "../STD_TYPES.h"


#ifndef MCAL_SPI_H_
#define MCAL_SPI_H_



//*************************************************************
//********************* Define Data types**********************
//*************************************************************
typedef enum {

	SPI_Mode_Slave = 0,
	SPI_MODE_Master = 1
}SPI_ModeType;

typedef enum {
	SPI_Fosc4,
	SPI_Fosc16,
	SPI_Fosc64,
	SPI_Fosc128
}SPI_CLK_RateType;

typedef enum {

	SPI_Enable_Off=0,
	SPI_Enable_ON=1
}SPI_Enable;

typedef enum {

	SPI_IDL_CLK_LOW=0,
	SPI_IDL_CLK_HIGH=1
}SPI_CLK_Polarity;

typedef enum {

	SPI_First_EDG=0,
	SPI_Second_EDG=1
}SPI_Sample_EDGType;

typedef enum {

	SPI_MSB=0,
	SPI_LSB

}SPI_DATA_OrderType;

typedef enum {

	SPI_DOUBLE_SPEED_ENABLE=1,
	SPI_DOUBLE_SPEDD_DISABLE=0
}SPI_DOUBLE_SPEEDType;

typedef enum {

	SPI_interruptEnable = 1,
	SPI_interruptDisable = 0
}SPI_INT_Type;
typedef struct {

	SPI_ModeType mode                    ;
	SPI_CLK_RateType CLK                 ;
	SPI_Enable Enable                    ;
	SPI_CLK_Polarity CLK_Polarity        ;
	SPI_Sample_EDGType Sampling_EDG      ;
	SPI_DATA_OrderType order             ;
	SPI_DOUBLE_SPEEDType DoubleSpedd     ;
	SPI_INT_Type interrupt_state         ;

}SPI_ConfigType;


//***********************************************
//*****************MAcros************************
// SPCR
#define  SPIE                         7
#define  SPE                          6
#define  DORD                         5
#define  MSTR                         4
#define  CPOL                         3
#define  CPHA                         2
#define  SPR1                         1
#define  SPR0                         0


//SPSR
#define  SPIF                         7
#define  WCOL                         6
#define  SPI2X                        0


//******************************************************
//**********Function Declaration*************************
//********************************************************

void MCAL_SPI_Init(SPI_ConfigType* config);
u8 MCAL_SPI_SendAndReceive(u8 Copy_Data);
u8 MCAL_SPI_CheckForCollsion(void);
void MCAL_SPI_AssignCallBack(void (*PCallBack)(void));

#endif /* MCAL_SPI_H_ */
