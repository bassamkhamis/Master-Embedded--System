/*
 * STM32F103x8_RCC_driver.h
 *
 *  Created on: Jul 11, 2022
 *      Author: bassa
 */

#ifndef INC_STM32F103X8_RCC_DRIVER_H_
#define INC_STM32F103X8_RCC_DRIVER_H_

#include "STM32F103x8.h"
#define HSI_RC_CLK     (uint32_t)8000000
#define HSE_CLK        (uint32_t)16000000

uint32_t MCAL_RCC_GetSYS_CLKFreq(void);
uint32_t MCAL_RCC_GetHCLKFreq(void);
uint32_t MCAL_RCC_GetPCLK2Freq(void);
uint32_t MCAL_RCC_GetPCLK1Freq(void);


#endif /* INC_STM32F103X8_RCC_DRIVER_H_ */
