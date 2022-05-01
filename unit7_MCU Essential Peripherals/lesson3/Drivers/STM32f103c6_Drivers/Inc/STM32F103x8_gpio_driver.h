/*
 * STM32F103x8_gpio_driver.h
 *
 *  Created on: Apr 28, 2022
 *      Author: bassam
 */

#ifndef INC_STM32F103X8_GPIO_DRIVER_H_
#define INC_STM32F103X8_GPIO_DRIVER_H_


//-----------------------------
//Includes
//-----------------------------
#include "STM32F103x8.h"
//-----------------------------
//User type definitions (structures)
//-----------------------------
//@ref GPIO_configPin_t_define
typedef struct {
	uint16_t GPIO_PinNumber;     //specifies the GPIO number pin to be configured
	                            // the value of this parameter can be find at @ref GPIO_pinNumber_define

	uint8_t GPIO_Mode;           //specifies the mode of GPIO pin to be configured
                                 // the value of this parameter can be find at @ref GPIO_MODE_define

	uint8_t GPIO_Output_Speed;   //specifies the output speed of each Pin
	                             //the value of this parameter can be find at @ref GPIO_Output_Speed_define

}GPIO_configPin_t;

//-----------------------------
//Macros Configuration References
//-----------------------------
//@ref GPIO_pinNumber_define
#define GPIO_PIN0                ((uint16_t)0x0001)
#define GPIO_PIN1                ((uint16_t)0x0002)
#define GPIO_PIN2                (uint16_t)0x0004
#define GPIO_PIN3                (uint16_t)0x0008
#define GPIO_PIN4                (uint16_t)0x0010
#define GPIO_PIN5                (uint16_t)0x0020
#define GPIO_PIN6                (uint16_t)0x0040
#define GPIO_PIN7                (uint16_t)0x0080
#define GPIO_PIN8                (uint16_t)0x0100
#define GPIO_PIN9                (uint16_t)0x0200
#define GPIO_PIN10               (uint16_t)0x0400
#define GPIO_PIN11               (uint16_t)0x0800
#define GPIO_PIN12               (uint16_t)0x1000
#define GPIO_PIN13               ((uint16_t)0x2000)
#define GPIO_PIN14               (uint16_t)0x4000
#define GPIO_PIN15               (uint16_t)0x8000
/*----------------------------------------------*/
 /* @ref GPIO_MODE_define
	0: Analog mode
	1: Floating input (reset state)
	2: Input with pull-up
	3: Input with pull-down
	4: General purpose output push-pull
	5: General purpose output Open-drain
	6: Alternate function output Push-pull
	7: Alternate function output Open-drain
	8: Alternate function input
  */

#define GPIO_MODE_ANALOG               0U
#define GPIO_MODE_INPUT_FLO            1U
#define GPIO_MODE_INPUT_PU             2U
#define GPIO_MODE_INPUT_PD             3U
#define GPIO_MODE_OUTPUT_PP            4U
#define GPIO_MODE_OUTPUT_OD            5U
#define GPIO_MODE_OUTPUT_AF_PP         6U
#define GPIO_MODE_OUTPUT_AF_OD         7U
#define GPIO_MODE_INPUT_AF             8U


/*@ref GPIO_Output_Speed_define
01: Output mode, max speed 10 MHz.
10: Output mode, max speed 2 MHz.
11: Output mode, max speed 50 MHz.
 */
#define GPIO_SPEED_10M               1U
#define GPIO_SPEED_2M                2U
#define GPIO_SPEED_50M               3U


//@ref GPIO_pin_vlaue_define
#define GPIO_HIGH                   1U
#define GPIO_LOW                    0U

// @ref  Lock_Is_Active_define
#define GPIO_LOCK_ACTIVE            1
#define GPIO_LOCK_NOT_ACTIVE        0

/*@ref Module_REF_NAME_define
*/
/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/
void MCAL_GPIO_Init(GPIOx_typeDef* GPIOx, GPIO_configPin_t* PinConfig   );
void MCAL_GPIO_Deinit(GPIOx_typeDef* GPIOx                                );

void MCAL_GPIO_WritePort(GPIOx_typeDef* GPIOx,uint16_t value                  );
void MCAL_GPIO_WritePin(GPIOx_typeDef* GPIOx,uint16_t PinNumber,uint8_t Pinvalue);

uint8_t MCAL_GPIO_ReadPin(GPIOx_typeDef* GPIOx,uint16_t PinNumber              );
uint16_t MCAL_GPIO_ReadPort(GPIOx_typeDef* GPIOx                                );

void MCAL_GPIO_TogglePin(GPIOx_typeDef* GPIOx,uint16_t PinNumber          );
uint8_t MCAL_GPIO_LockPin(GPIOx_typeDef* GPIOx,uint16_t PinNumber            );
#endif /* INC_STM32F103X8_GPIO_DRIVER_H_ */
