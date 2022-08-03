/*
 * I2C_Slave_EEPPROM.h
 *
 *  Created on: Aug 3, 2022
 *      Author: bassa
 */

#ifndef INC_I2C_SLAVE_EEPPROM_H_
#define INC_I2C_SLAVE_EEPPROM_H_

#include "STM32F103x8_I2C_driver.h"


/*
 * EEPROM is an I2C Slave
 *
 * Idle Mode ================> The device is in high-Impedance state and waits for data.
 * Master Transmitter Mode ==> The device transmits data to a slave receiver.
 * Master Receiver Mode =====> The device receives data form a slave transmitter.
 */

#define EEPROM_Slave_Address 		  0x2A
/* ********************** */
/* ******** APIs ******** */
/* ********************** */

void HAL_EEPROM_Init(void);
uint8_t HAL_EEPROM_Write_NBytes(uint32_t Memory_Address, uint8_t *Byte, uint32_t Data_Length);
uint8_t HAL_EEPROM_Read_NBytes(uint32_t Memory_Address, uint8_t *DataOut, uint32_t DataLen);


#endif /* INC_I2C_SLAVE_EEPPROM_H_ */
