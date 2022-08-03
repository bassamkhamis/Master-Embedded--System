/*
 * STM32F103x8_gpio_driver.c
 *
 *  Created on: Apr 28, 2022
 *      Author: bassam
 */

#include "STM32F103x8_gpio_driver.h"



uint8_t get_Pin_Postion(uint16_t GPIO_PinNumber ){
	switch(GPIO_PinNumber){
	case GPIO_PIN0:
		return 0;
		break;
	case GPIO_PIN1:
			return 4;
			break;
	case GPIO_PIN2:
			return 8;
			break;
	case GPIO_PIN3:
			return 12;
			break;
	case GPIO_PIN4:
			return 16;
			break;
	case GPIO_PIN5:
			return 20;
			break;
	case GPIO_PIN6:
			return 24;
			break;
	case GPIO_PIN7:
			return 28;
			break;
	case GPIO_PIN8:
			return 0;
			break;
	case GPIO_PIN9:
			return 4;
			break;
	case GPIO_PIN10:
			return 8;
			break;
	case GPIO_PIN11:
			return 12;
			break;
	case GPIO_PIN12:
			return 16;
			break;
	case GPIO_PIN13:
			return 20;
			break;
	case GPIO_PIN14:
			return 24;
			break;
	case GPIO_PIN15:
			return 28;
			break;


	}

	return 0;
}

/**================================================================
* @Fn-MCAL_GPIO_Init
* @brief      - This fun configure the GPIO pin as input pull up/down output push pull open drain... according to PinConfig structure
* @param [in] - GPIOx is type definitions (x=A,B...)
* @param [in] - PinConfig is type definitions @ref GPIO_configPin_t_define
* @retval     -none
* Note        -In PinConfig must determine the mode and pin number and speed in case pin output only,
*              when configure the GPIO, first check TRM and data sheet of MCU and kit to know available Ports
*/


void MCAL_GPIO_Init(GPIOx_typeDef* GPIOx, GPIO_configPin_t* PinConfig)
{

	volatile uint32_t *cofigReg =NULL;  //((void *)0)
	cofigReg = ((PinConfig->GPIO_PinNumber < GPIO_PIN8)? &GPIOx->CRL : &GPIOx->CRH);
	*cofigReg &= ~(0xf<<get_Pin_Postion(PinConfig->GPIO_PinNumber)) ; //Reset the nibble in CRL Or CRH
	uint8_t pinConfigLoc = 0;
	if((PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_AF_OD) || (PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_AF_PP) || (PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_OD) || (PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_PP))
	{
       // subtract 4 from GPIO Mode according to TRM :
		//00: General purpose output push-pull (4-4=0)
		//01: General purpose output Open-drain (5-4=1)
		//10: Alternate function output Push-pull (6-4=1)
		//11: Alternate function output Open-drain (7-4=1)

		pinConfigLoc = ( ( (PinConfig->GPIO_Mode)-4 )<<2 | (PinConfig->GPIO_Output_Speed) ) & 0xf;


	}
	else //GPIO_MODE_ANALOG or GPIO_MODE_INPUT_FLO or GPIO_MODE_INPUT_AF Or GPIO_MODE_INPUT_PD OR GPIO_MODE_INPUT_PU
	{
/*		In input mode (MODE[1:0]=00):
        CNF[3:2]:
		00: Analog mode
		01: Floating input (reset state)
		10: Input with pull-up / pull-dow*/



			if((PinConfig->GPIO_Mode == GPIO_MODE_ANALOG || PinConfig->GPIO_Mode ==GPIO_MODE_INPUT_FLO))
			{
				pinConfigLoc = ((PinConfig->GPIO_Mode)<<2 | (0x00)) & 0xf;
			}
			else if(PinConfig->GPIO_Mode == GPIO_MODE_INPUT_AF)  // Considered that GPIO_MODE_AF_INPUT = GPIO_MODE_INPUT_FLO in data sheet
			{

				pinConfigLoc = ((PinConfig->GPIO_Mode - 7U)<<2 | (0x00)) & 0xf;    // 8-7 = 1 == Floating input
			}
			else{


				pinConfigLoc = ((PinConfig->GPIO_Mode)<<2 | (0x00)) & 0xf;

				if(PinConfig->GPIO_Mode == GPIO_MODE_INPUT_PU){
					//Pull up (set bit according to pin number)
					GPIOx->ODR |= PinConfig->GPIO_PinNumber;

				}
				else{
					// PxODR = 0 Input pull-down: Table 20. Port bit configuration table
					GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);// Pull down (reset bit according to pin number)
				}

			}

	}
// Set configuration to CRL OR CRH
(*cofigReg) |= ((pinConfigLoc) << get_Pin_Postion(PinConfig->GPIO_PinNumber)) ;


}
/**================================================================
* @Fn          -MCAL_GPIO_Deinit
* @brief       -This fun reset the GPIO pin
* @param [in]  -GPIOx is type definitions (x=A,B...)
* @retval      -None
* Note         -There two method (technique) manually OR Reset Peripheral
*/

void MCAL_GPIO_Deinit(GPIOx_typeDef* GPIOx )
{   //Method 1
	// by reset all register manually

	GPIOx->CRL = 0x44444444;
	GPIOx->CRH = 0x44444444;
	//Method 2
	//Reset Clock
	if(GPIOx == GPIOA){
		RCC->APB2RSTR |= 1<<2;
	}
	else if(GPIOx == GPIOB){
		RCC->APB2RSTR |= 1<<2;
	}
	else if(GPIOx == GPIOC){
		RCC->APB2RSTR |= 1<<3;
	}
	else if(GPIOx == GPIOD){
		RCC->APB2RSTR |= 1<<4;
	}
	else if(GPIOx == GPIOE){
		RCC->APB2RSTR |= 1<<5;
	}

}
/**================================================================
* @Fn         -MCAL_GPIO_WritePort
* @brief      -Write on whole Port(ALL Pins)
* @param [in] -GPIOx_typeDef GPIOx is type definitions (x=A,B...) Like GPIOA,GPIOB...
* @param [in] -uint8_t value the value to be written
* @retval     -None
* Note        -The argument MUST be AS Reference
*/
void MCAL_GPIO_WritePort(GPIOx_typeDef* GPIOx,uint16_t value)
{
//	GPIOx->ODR &= ~(0xff);
	GPIOx->ODR = (uint32_t)value ;
}
/**================================================================
* @Fn         -MCAL_GPIO_WritePin
* @brief      -Write to specific pins High Or Low
* @param [in] -GPIOx_typeDef GPIOx is type definitions (x=A,B...) Like GPIOA,GPIOB...
* @param [in] -uint8_t Pinvalue the value to be written @ref GPIO_pin_vlaue_define
* @param [in] -pin number @ref GPIO_pinNumber_define
* @retval     -None
* Note        -The argument MUST be AS Reference
*/
void MCAL_GPIO_WritePin(GPIOx_typeDef* GPIOx,uint16_t PinNumber,uint8_t Pinvalue)
{

	if(GPIO_HIGH == Pinvalue){
		GPIOx->BSRR = (uint32_t)PinNumber;
	}
	else {
		GPIOx->BRR = (uint32_t)PinNumber;
	}
}
/**================================================================
* @Fn         -MCAL_GPIO_ReadPin
* @brief      -Read specific pin from specific port
* @param [in] -GPIOx_typeDef GPIOx is type definitions (x=A,B...) Like GPIOA,GPIOB...
* @param [in] -pin number @ref GPIO_pinNumber_define
* @retval     -uint8_t GPIO_HIGH or GPIO_LOW according to the status of pin
* Note        -The argument MUST be AS Reference
*/
uint8_t MCAL_GPIO_ReadPin(GPIOx_typeDef* GPIOx, uint16_t PinNumber)
{
	if( ( (GPIOx->IDR)&PinNumber ) !=(uint32_t) GPIO_LOW)
	{
		return GPIO_HIGH;
	}
	else{
		return GPIO_LOW;
	}
}

/**================================================================
* @Fn         -MCAL_GPIO_ReadPort
* @brief      -Read from whole Port(ALL Pins)
* @param [in] -GPIOx_typeDef GPIOx is type definitions (x=A,B...) Like GPIOA,GPIOB...
* @param [in] -uint8_t value the value to be written
* @retval     -uint16_t value of all pins
* Note        -The argument MUST be AS Reference
*/
uint16_t MCAL_GPIO_ReadPort(GPIOx_typeDef* GPIOx)
{
	return (uint16_t)GPIOx->IDR;

}
/**================================================================
* @Fn         -MCAL_GPIO_TogglePin
* @brief      -TOggle(change the status of pin) specific pin from specific port
* @param [in] -GPIOx_typeDef GPIOx is type definitions (x=A,B...) Like GPIOA,GPIOB...
* @param [in] -pin number @ref GPIO_pinNumber_define
* @retval     -None
* Note        -The argument MUST be AS Reference
*/
void MCAL_GPIO_TogglePin(GPIOx_typeDef* GPIOx,uint16_t PinNumber)
{
	GPIOx->ODR ^= PinNumber;
}

/**================================================================
 * @Fn         -MCAL_GPIO_LockPin
 * @brief      -lock specific pin so, has configuration not change until reset the GPIO
 * @param [in] -GPIOx_typeDef GPIOx is type definitions (x=A,B...) Like GPIOA,GPIOB...
 * @param [in] -pin number @ref GPIO_pinNumber_define
 * @retval     -flag to confirm Lock Active or No @ref  Lock_Is_Active_define
 * Note        -The argument MUST be AS Reference
 */
uint8_t MCAL_GPIO_LockPin(GPIOx_typeDef* GPIOx,uint16_t PinNumber){

	//Each lock bit freezes the corresponding 4 bits of the control register (CRL, CRH)
/*	LOCK key writing sequence:
	Write 1
	Write 0
	Write 1
	Read 0
	Read 1 (this read is optional but confirms that the lock is active)
	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	Any error in the lock sequence will abort the lock.*/

	uint32_t LCKK = 1<<16;
	GPIOx->LCKR = PinNumber;
	GPIOx->LCKR |= LCKK;
	GPIOx->LCKR &= ~LCKK;
	GPIOx->LCKR |= LCKK;
	LCKK = GPIOx->LCKR ;
	LCKK = GPIOx->LCKR ;
	if((LCKK & (1<<16)) != 0)
	{
		return GPIO_LOCK_ACTIVE;

	}

	return GPIO_LOCK_NOT_ACTIVE;
}
