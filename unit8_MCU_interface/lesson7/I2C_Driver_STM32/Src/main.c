/*
 * Keypad.h
 *
 *  Created on: Apr 30, 2022
 *      Author: bassam
 */

#include <stdint.h>
#include "STM32F103x8_gpio_driver.h"
#include "STM32F103x8_EXTI_driver.h"
#include "Lcd.h"
#include "STM32F103x8_USART_driver.h"
#include "STM32F103x8_RCC_driver.h"
#include "STM32F103x8_SPI_driver.h"
#include "STM32F103x8_I2C_driver.h"
#include "I2C_Slave_EEPPROM.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


//uint16_t charater;
//uint8_t charater2;
////#define MCU_ACTS_AS_MASTER
//#define MCU_ACTS_AS_SLAVE
//
//
//void SPI_CallBack(struct S_IRQ_SRC iqr_SRC){
//
//#ifdef MCU_ACTS_AS_SLAVE
//	if(iqr_SRC.RXNE){
//        charater2 = 0xF;
//		MCAL_SPI_TX_RX(SPI1, &(charater2), disablePOLLING_SPI);
//		MCAL_UART_SendData(USART1,&charater2 , enable);
//
//	}
//
//#endif
//
//}
//
//
//
//void FunCallBack(void){
//#ifdef MCU_ACTS_AS_MASTER
//	MCAL_UART_ReceiveData(USART1, &charater,disable);
//	MCAL_UART_SendData(USART1, &charater,enable);
//	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN4, 0);
//	MCAL_SPI_TX_RX(SPI1, &charater, enablePOLLING_SPI);
//	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN4, 1);
//#endif
//
//
//
//}


int main(void)
{



	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_GPIOC_CLK_EN();

   // Test Case 1
	uint8_t ch1 [] = {0x01,0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
	uint8_t ch2 [7] = {0};
	HAL_EEPROM_Init();

	HAL_EEPROM_Write_NBytes(0xAF, ch1, 7) ;

	HAL_EEPROM_Read_NBytes(0xAF, ch2, 7);


    // Test case 2
	ch1[0] = 0xA ;
	ch1[1] = 0xB ;
	ch1[2] = 0xC;
	ch1[3] = 0xD ;

	HAL_EEPROM_Write_NBytes(0xFF, ch1, 4) ;

	HAL_EEPROM_Read_NBytes(0xFF, ch2, 4);




	/* Loop forever */


	while(1){





	}

}
