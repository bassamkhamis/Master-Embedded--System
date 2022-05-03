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


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


GPIO_configPin_t GConfigPin;

void pseudo_delay(uint32_t time){
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++);
}



void fun_callback(void)
{
   LCD_WRITE_STRING("EXTI9PB9 IS Released _|-");
   pseudo_delay(700);
   LCD_clear_screen();
}
void GPIO_EXTI_init(){

		EXTI_pinCofig_t LPinConfig;
		LPinConfig.EXTI_pin = EXTI9PB9;
		LPinConfig.IQR_Enable=EXTI_ENABLE;
		LPinConfig.Trigger=EXTR_RAISING;
		LPinConfig.p_EXTIcallback=fun_callback;
		MCAL_EXTI_GPIO_Init(&LPinConfig);


}

int main(void)
{



	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
    RCC_GPIOC_CLK_EN();




	LCD_INIT();
	GPIO_EXTI_init();
	LCD_WRITE_STRING("Hey_|-");
	pseudo_delay(30);
	LCD_clear_screen();





	/* Loop forever */


	while(1){


		pseudo_delay(1);

	}

}
