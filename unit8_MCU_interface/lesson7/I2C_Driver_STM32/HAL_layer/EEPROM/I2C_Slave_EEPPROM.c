/*
 * I2C_Slave_EEPPROM.c
 *
 *  Created on: Aug 3, 2022
 *      Author: bassa
 */


#include "I2C_Slave_EEPPROM.h"

void HAL_EEPROM_Init(void)
{
	//Init EEPROM

	//PB6     SCLK
	//PB7     SDATA

	I2C_configtypeDef I2C11CFG;
	I2C11CFG.General_Call_Adrress_Detection = General_Call_Adrress_Detection_Enable;
	I2C11CFG.I2C_ACK_Control = I2C_ACK_Control_Enable ;
	I2C11CFG.I2C_CLOCK = I2C_SCLK_SM_100K ;
	I2C11CFG.I2C_Mode = I2C_Mode_I2C ;
	I2C11CFG.P_Slave_EV_CallBack = NULL;
	I2C11CFG.stretchClok = stretchClok_Enable ;

    //Set Pins
	MACL_I2C_GPIO_Set_PINs(I2C1);
	//Init
	MCAL_I2C_Init(I2C1, &I2C11CFG);


}
uint8_t HAL_EEPROM_Write_NBytes(uint32_t Memory_Address, uint8_t *Byte, uint32_t Data_Length)
{
	uint8_t i = 0;
	//MASIR 2008 C++ 18-4-1, Memory heap dynamic allocation should be not be Used

	uint8_t buffer[256];
	buffer[0] = (uint8_t)(Memory_Address>>8);
	buffer[1] = (uint8_t)Memory_Address;


	for(i = 2; i< (Data_Length+2); i++)
	{
      buffer[i]  =  Byte[i-2] ;
	}

	MCAL_I2C_Master_TX(I2C1, EEPROM_Slave_Address, buffer, Data_Length + 2, withStop, start);

	return 0 ;

}
uint8_t HAL_EEPROM_Read_NBytes(uint32_t Memory_Address, uint8_t *DataOut, uint32_t DataLen)
{

	uint8_t buffer[2];
	buffer[0] = (uint8_t)(Memory_Address>>8);
	buffer[1] = (uint8_t)Memory_Address;

	//Send address of EEPROM
	MCAL_I2C_Master_TX(I2C1, EEPROM_Slave_Address, buffer, 2, WithoutStop, start);

   //Receive Data from EEPROM
	MCAL_I2C_Master_RX(I2C1, EEPROM_Slave_Address, DataOut, DataLen, withStop, repeateStart);

	return 0 ;

}
