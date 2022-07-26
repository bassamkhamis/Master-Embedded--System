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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


uint16_t charater;
uint8_t charater2;
//#define MCU_ACTS_AS_MASTER
#define MCU_ACTS_AS_SLAVE


void SPI_CallBack(struct S_IRQ_SRC iqr_SRC){

#ifdef MCU_ACTS_AS_SLAVE
	if(iqr_SRC.RXNE){
        charater2 = 0xF;
		MCAL_SPI_TX_RX(SPI1, &(charater2), disablePOLLING_SPI);
		MCAL_UART_SendData(USART1,&charater2 , enable);

	}

#endif

}



void FunCallBack(void){
#ifdef MCU_ACTS_AS_MASTER
	MCAL_UART_ReceiveData(USART1, &charater,disable);
	MCAL_UART_SendData(USART1, &charater,enable);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN4, 0);
	MCAL_SPI_TX_RX(SPI1, &charater, enablePOLLING_SPI);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN4, 1);
#endif



}


int main(void)
{



	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_GPIOC_CLK_EN();

	//================UART Init===============
    USART_config uartConf;
    uartConf.BaudRate = UART_BaudRate_115200;
    uartConf.HwFlowCtl = UART_HwFlowCtl_NONE;
    uartConf.IRQ_Enable = UART_IRQ_Enable_RXNEIE;
    uartConf.P_IRQ_CallBack = FunCallBack;
    uartConf.Parity = UART_Parity_NONE;
    uartConf.Payload_Length = UART_Payload_Length_8B;
    uartConf.StopBits = UART_StopBits_1;
    uartConf.USART_Mode = UART_MODE_RX_TX;

    MCAL_UART_Init(USART1, &uartConf);
    MCAL_UART_GPIO_Set_Pins(USART1);

	//================SPI Init===============
//	 PA4 SPI1 NSS
//	  PA5 SPI1 CLK
//	 PA6 SPI1 MISO
//	 PA7 SPI1 MOSI

	SPI_config spiConf;
	spiConf.CLKphase = SPI_CLKphase_2ndEDG_DATA_Sample;
	spiConf.CLKpolarity = SPI_CLKpolarity_Ideal_High;
	spiConf.frame_format = SPI_Frame_Format_MSB_Frist;
	//Assume by default PCLK2 = 8Mhz
	spiConf.SPI_BAUDRATE_PRESCALERS = SPI_BAUDRATE_PRESCALERS_DIV8;
	spiConf.communication_Mode = SPI_2Lines_2fullDuplex;





#ifdef MCU_ACTS_AS_MASTER
	spiConf.Device_Mode = SPI_Device_Mode_Master;
	spiConf.IRQ_Enable = SPI_IRQ_Enable_NONE;
	spiConf.P_IRQ_CallBack = NULL;
	spiConf.NSS = SPI_NSS_internal_SOFT_Set;

	GPIO_configPin_t Pin_Config;
	Pin_Config.GPIO_PinNumber = GPIO_PIN4;
	Pin_Config.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	Pin_Config.GPIO_Output_Speed= GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &Pin_Config);
	// write high to SS
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN4, 1);
#endif


#ifdef MCU_ACTS_AS_SLAVE
	spiConf.Device_Mode = SPI_Device_Mode_Slave;
	spiConf.IRQ_Enable = SPI_IRQ_Enable_RXNEIE;
	spiConf.P_IRQ_CallBack = SPI_CallBack;
	spiConf.NSS = SPI_NSS_Hardware_Salve;
#endif

	MCAL_SPI_Init(SPI1, &spiConf);
	MCAL_SPI_GPIO_Set_Pins(SPI1);

	//config SS
	GPIO_configPin_t Pin_Config;
	Pin_Config.GPIO_PinNumber = GPIO_PIN4;
	Pin_Config.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	Pin_Config.GPIO_Output_Speed= GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &Pin_Config);
	// write high to SS
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN4, 1);






	/* Loop forever */


	while(1){





	}

}
