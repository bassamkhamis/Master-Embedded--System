/*
 * Keypad.h
 *
 *  Created on: Apr 30, 2022
 *      Author: bassam
 */

#include <stdint.h>
#include "STM32F103x8_gpio_driver.h"
#include "Lcd.h"
#include "keypad.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define ZERO 0x01
#define ONE 0x79
#define TWO 0x24
#define THREE 0x30
#define FOUR 0x4C
#define FIVE 0x12
#define SIX 0x02
#define SEVEN 0x19
#define EIGHT 0x00
#define NINE 0x10

GPIO_configPin_t GConfigPin;

void pseudo_delay(uint32_t time){
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++);
}

void GPIO_init(){



	GConfigPin.GPIO_PinNumber=GPIO_PIN9;
	GConfigPin.GPIO_Mode=GPIO_MODE_OUTPUT_PP;
	GConfigPin.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &GConfigPin);
	GConfigPin.GPIO_PinNumber=GPIO_PIN10;
	GConfigPin.GPIO_Mode=GPIO_MODE_OUTPUT_PP;
	GConfigPin.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &GConfigPin);
	GConfigPin.GPIO_PinNumber=GPIO_PIN11;
	GConfigPin.GPIO_Mode=GPIO_MODE_OUTPUT_PP;
	GConfigPin.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &GConfigPin);
	GConfigPin.GPIO_PinNumber=GPIO_PIN12;
	GConfigPin.GPIO_Mode=GPIO_MODE_OUTPUT_PP;
	GConfigPin.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &GConfigPin);
	GConfigPin.GPIO_PinNumber=GPIO_PIN13;
	GConfigPin.GPIO_Mode=GPIO_MODE_OUTPUT_PP;
	GConfigPin.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &GConfigPin);
	GConfigPin.GPIO_PinNumber=GPIO_PIN14;
	GConfigPin.GPIO_Mode=GPIO_MODE_OUTPUT_PP;
	GConfigPin.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &GConfigPin);
	GConfigPin.GPIO_PinNumber=GPIO_PIN15;
	GConfigPin.GPIO_Mode=GPIO_MODE_OUTPUT_PP;
	GConfigPin.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &GConfigPin);




}

int main(void)
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();

	LCD_INIT();
	GPIO_init();

	unsigned char key_pressed;
	LCD_WRITE_STRING("1234");
	pseudo_delay(30);
	LCD_clear_screen();


	unsigned char LCD_DISPLAY [11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
	unsigned char DISPLAY [11] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO};
	for (unsigned char i = 0; i < 11; i++) {
		LCD_WRITE_CHAR(LCD_DISPLAY[i]);
		MCAL_GPIO_WritePort(GPIOB, DISPLAY[i] << 9); /* write data on to the LED port */
		pseudo_delay(100);
	}
	/* Loop forever */

	LCD_clear_screen();
	Keypad_init();
	LCD_WRITE_STRING("Keypad is ready");
	pseudo_delay(30);
	LCD_clear_screen();

	while(1){


		key_pressed = Keypad_getkey();
		switch (key_pressed) {
		case 'A':
			break;
		case '@':
			LCD_clear_screen();
			break;
		default:
			LCD_WRITE_CHAR(key_pressed);
			break;
		}

	}

}
