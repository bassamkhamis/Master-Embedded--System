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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


uint16_t charater;


void FunCallBack(void){
	MCAL_UART_ReceiveData(USART1, &charater,disable);
	MCAL_UART_SendData(USART1, &charater,enable);

}


int main(void)
{



	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
    RCC_GPIOC_CLK_EN();


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



	/* Loop forever */


	while(1){




	}

}
