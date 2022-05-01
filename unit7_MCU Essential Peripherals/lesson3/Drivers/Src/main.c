/*
 * Keypad.h
 *
 *  Created on: Apr 30, 2022
 *      Author: bassam
 */

#include <stdint.h>
#include "STM32F103x8_gpio_driver.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


GPIO_configPin_t GConfigPin;

void pseudo_delay(uint32_t time){
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++);
}

void GPIO_init(){


	// GPIOA pin 1 AS input floating
	GPIO_configPin_t PinConfig;
	PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	PinConfig.GPIO_PinNumber= GPIO_PIN1;
	MCAL_GPIO_Init(GPIOA, &PinConfig);

	// GPIOA pin 13 AS input floating
	PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	PinConfig.GPIO_PinNumber= GPIO_PIN13;
	MCAL_GPIO_Init(GPIOA, &PinConfig);

	// GPIOB pin 1 AS output PUSH-PULL
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_PinNumber= GPIO_PIN1;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinConfig);

	// GPIOB pin 13 AS output PUSH-PULL
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_PinNumber= GPIO_PIN13;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinConfig);


}

int main(void)
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();


  GPIO_init();




	/* Loop forever */


	while(1){

		if(MCAL_GPIO_ReadPin(GPIOA,GPIO_PIN1) == GPIO_LOW)
		{   MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN1);
		while(MCAL_GPIO_ReadPin(GPIOA,GPIO_PIN1) == GPIO_LOW);
		}

		if(MCAL_GPIO_ReadPin(GPIOA,GPIO_PIN13) == 1)
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN13);
		}

		pseudo_delay(1000);

	}

}
