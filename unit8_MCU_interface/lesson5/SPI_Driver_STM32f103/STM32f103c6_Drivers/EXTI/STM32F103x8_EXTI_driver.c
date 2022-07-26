/*
 * STM32F103x8_EXTI_driver.c
 *
 *  Created on: May 2, 2022
 *      Author: bassam
 */

#include "STM32F103x8_EXTI_driver.h"
//----------------------------
//******* Generic MAcro *****

//0000: PA[x] pin
//0001: PB[x] pin
//0010: PC[x] pin
//0011: PD[x] pin
#define AFIO_GPIO_MAPPING(VAL)   (VAL==GPIOA) ? 0U:\
	                           	 (VAL==GPIOB) ? 1U:\
				                 (VAL==GPIOC) ? 2U:\
						         (VAL==GPIOD) ? 3U:0U


//-------------------------


//------------------------
//******Generic variable***

void (*GP_callback[16])(void);   // Array of 16 pointers To Function Take void And Return NOthing(void)
                                //So,Customer can Send Function Call Back As parameter to fun MCAL_EXTI_GPIO_Init


//------------------------

//-----------------------
//****Generic Function *****

/**================================================================
 * @Fn         - static IQR_Enable
 * @brief      - This fun enable NVIC controller
 * @param [in] - uint8_t line contains the wire Number NVIC controller(iqr number)
 * @retval     - none
 * Note        - private function only used on this file
 */
void static IQR_Enable(uint8_t line)
{
	switch(line){

	case EXTI0:
		NVIC_IQR6_EXTI0_Enable();
		break;
	case EXTI1:
		NVIC_IQR7_EXTI1_Enable();
		break;
	case EXTI2:
		NVIC_IQR8_EXTI2_Enable();
		break;
	case EXTI3:
		NVIC_IQR9_EXTI3_Enable();
		break;
	case EXTI4:
		NVIC_IQR10_EXTI4_Enable();
		break;
	case EXTI5:
	case EXTI6:
	case EXTI7:
	case EXTI8:
	case EXTI9:
		NVIC_IQR23_EXTI5_9_Enable();
		break;
	case EXTI10:
	case EXTI11:
	case EXTI12:
	case EXTI13:
	case EXTI14:
	case EXTI15:
		NVIC_IQR40_EXTI10_15_Enable();
		break;
	default:
		break;

	}
}
/**================================================================
 * @Fn         - IQR_Disable
 * @brief      - This fun Disable NVIC controller
 * @param [in] - uint8_t line contains the wire Number NVIC controller(iqr number)
 * @retval     - none
 * Note        - private function only used on this file
 */
void static IQR_Disable(uint8_t line)
{
	switch(line){

	case EXTI0:
		NVIC_IQR6_EXTI0_Disable();
		break;
	case EXTI1:
		NVIC_IQR7_EXTI1_Disable();
		break;
	case EXTI2:
		NVIC_IQR8_EXTI2_Disable();
		break;
	case EXTI3:
		NVIC_IQR9_EXTI3_Disable();
		break;
	case EXTI4:
		NVIC_IQR10_EXTI4_Disable();
		break;
	case EXTI5:
	case EXTI6:
	case EXTI7:
	case EXTI8:
	case EXTI9:
		NVIC_IQR23_EXTI5_9_Disable();
		break;
	case EXTI10:
	case EXTI11:
	case EXTI12:
	case EXTI13:
	case EXTI14:
	case EXTI15:
		NVIC_IQR40_EXTI10_15_Disable();
		break;
	default:
		break;

	}

}
//----------------------

/**================================================================
 * @Fn         - MCAL_EXTI_GPIO_Init
 * @brief      - This fun configure the EXTI LINE and specify the PORT, pin, trigger type.... according to PinConfig structure
 * @param [in] - EXTI_con is type definitions @ref EXTI_define
 * @retval     -none
 * Note        -NO enable clock consider in this Fun
 *              User MUST Enable clock for GPIO and AFIO
 */
void Local_EXTI_Update(EXTI_pinCofig_t *EXTI_con)
{

	//1- configure pin as input floating

	GPIO_configPin_t pinConfig;
	pinConfig.GPIO_PinNumber = EXTI_con->EXTI_pin.GPIO_pin;
	pinConfig.GPIO_Mode      =GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(EXTI_con->EXTI_pin.GPIO_PORT, &pinConfig);

	//2- Set the AFIO

	//volatile uint32_t EXTICR[4];
	//AFIO_EXTICR1 control EXTL line [0:3]
	//AFIO_EXTICR2 control EXTL line [4:7]
	//AFIO_EXTICR3 control EXTL line [8:11]
	//AFIO_EXTICR4 control EXTL line [11:15]
	//Devided by 4 to get Index [0:3]  ex1 3/4=0, ex2 6/4=1
	uint8_t EXTI_Line_Index = (EXTI_con->EXTI_pin.EXTR_InputLineNumber) / 4;
	// modulus 4 to get position
	// AFIO_EXTICRx each pin in register take 4 bits field
	//EXTICR1[0:3], EXTICR1[4:7],EXTICR2[8:11],EXTICR3[12:15]....
	uint8_t EXTI_Line_position = ((EXTI_con->EXTI_pin.EXTR_InputLineNumber) % 4) * 4;
	//	 EXTIx: EXTI x configuration (x= 0 to 15)
	//	These bits are written by software to select the source input for EXTIx external interrupt.
	//	0000: PA[x] pin
	//	0001: PB[x] pin
	//	0010: PC[x] pin
	//	0011: PD[x] pin
	//	0100: PE[x] pin
	//	0101: PF[x] pin
	//	0110: PG[x] pin
	AFIO->EXTICR[EXTI_Line_Index] &= ~((0xf)<<EXTI_Line_position);
	AFIO->EXTICR[EXTI_Line_Index] |= ((AFIO_GPIO_MAPPING(EXTI_con->EXTI_pin.GPIO_PORT)&0xf)<<EXTI_Line_position);

	//3- Trigger selection
	//rest value
	EXTI->RTSR &=  ~(1<<EXTI_con->EXTI_pin.EXTR_InputLineNumber);
	EXTI->FTSR &=  ~(1<<EXTI_con->EXTI_pin.EXTR_InputLineNumber);
	if(EXTI_con->Trigger == EXTR_RAISING)
	{
		EXTI->RTSR |=  (1<<(EXTI_con->EXTI_pin.EXTR_InputLineNumber));
	}
	else if(EXTI_con->Trigger == EXTR_FALLING)
	{
		EXTI->FTSR |=  (1<<EXTI_con->EXTI_pin.EXTR_InputLineNumber);
	}
	else if(EXTI_con->Trigger == EXTR_FALLING_AND_RAISING) // Falling AND Raising
	{
		EXTI->RTSR |=  (1<<EXTI_con->EXTI_pin.EXTR_InputLineNumber);
		EXTI->FTSR |=  (1<<EXTI_con->EXTI_pin.EXTR_InputLineNumber);

	}

	//4- Fun call back

	GP_callback[EXTI_con->EXTI_pin.EXTR_InputLineNumber]=EXTI_con->p_EXTIcallback;



	//5-Enable EXTI AND NVIC
	if(EXTI_con->IQR_Enable == EXTI_ENABLE)
	{
		EXTI->IMR |= (1<<EXTI_con->EXTI_pin.EXTR_InputLineNumber);
		IQR_Enable(EXTI_con->EXTI_pin.EXTR_InputLineNumber);
	}else
	{
		EXTI->IMR &= ~(1<<EXTI_con->EXTI_pin.EXTR_InputLineNumber);
		IQR_Disable(EXTI_con->EXTI_pin.EXTR_InputLineNumber);
	}

}



/**================================================================
 * @Fn         - MCAL_EXTI_GPIO_Init
 * @brief      - This fun configure the EXTI LINE and specify the PORT, pin, trigger type.... according to PinConfig structure
 * @param [in] - EXTI_con is type definitions @ref EXTI_define
 * @retval     -none
 * Note        -NO enable clock consider in this Fun
 *              User MUST Enable clock for GPIO and AFIO
 */
void MCAL_EXTI_GPIO_Init(EXTI_pinCofig_t *EXTI_con)
{
	Local_EXTI_Update(EXTI_con);



}
/**================================================================
 * @Fn         - MCAL_EXTI_GPIO_Denit
 * @brief      - This fun Reset the EXTI for all LINE
 * @param [in] - none
 * @retval     - none
 * Note        - Reset register to their value according to TRM
 */
void MCAL_EXTI_GPIO_Denit()
{
	//Reset all Register
	EXTI->EMR   = 0X00;
	EXTI->IMR   = 0X00;
	EXTI->RTSR  = 0X00;
	EXTI->FTSR  = 0X00;
	EXTI->SWIER = 0X00;
	//Undefined Reset value
	EXTI->PR = 0Xffff;

	// disable NCIV
	NVIC_IQR6_EXTI0_Disable();
	NVIC_IQR7_EXTI1_Disable();
	NVIC_IQR8_EXTI2_Disable();
	NVIC_IQR9_EXTI3_Disable();
	NVIC_IQR10_EXTI4_Disable();
	NVIC_IQR23_EXTI5_9_Disable();
	NVIC_IQR40_EXTI10_15_Disable();
}
/**================================================================
 * @Fn         - MCAL_EXTI_GPIO_Update
 * @brief      - This fun Update the configure of the EXTI LINE and specify the PORT, pin, trigger type.... according to PinConfig structure
 * @param [in] - EXTI_con is type definitions @ref EXTI_define
 * @retval     -none
 * Note        -NO enable clock consider in this Fun
 *              User MUST Enable clock for GPIO and AFIO
 */
void MCAL_EXTI_GPIO_Update(EXTI_pinCofig_t *EXTI_con)
{
	void Local_EXTI_Update(EXTI_pinCofig_t *EXTI_con);
}




/*------------------------------------
 *          ISR-Function
 *-----------------------------------         -
 */
//PRx: Pending bit
//0: No trigger request occurred
//1: selected trigger request occurred
//This bit is set when the selected edge event arrives on the external interrupt line. This bit is
void EXTI0_IRQHandler(void)
{  //This bit rc_w1
	EXTI->PR |= (1<<0);
	GP_callback[0]();
}

void EXTI1_IRQHandler(void)
{
	//This bit rc_w1
	EXTI->PR |= (1<<1);
	GP_callback[1]();

}

void EXTI2_IRQHandler(void)
{
	//This bit rc_w1
	EXTI->PR |= (1<<2);
	GP_callback[2]();
}
void EXTI3_IRQHandler(void)
{
	//This bit rc_w1
	EXTI->PR |= (1<<3);
	GP_callback[3]();
}
void EXTI4_IRQHandler(void)
{
	//This bit rc_w1
	EXTI->PR |= (1<<4);
	GP_callback[4]();
}

void EXTI9_5_IRQHandler(void)
{
	if((EXTI->PR)& (1<<5)){EXTI->PR |= 1<<5; GP_callback[5]();}
	if((EXTI->PR)& (1<<6)){EXTI->PR |= 1<<6; GP_callback[6]();}
	if((EXTI->PR)& (1<<7)){EXTI->PR |= 1<<7; GP_callback[7]();}
	if((EXTI->PR)& (1<<8)){GP_callback[8]();EXTI->PR |= 1<<8;}
	if((EXTI->PR)& (1<<9)){EXTI->PR |= 1<<9; GP_callback[9]();}
}

void EXTI15_10_IRQHandler(void)
{
	if((EXTI->PR)& (1<<10)){EXTI->PR |= 1<<10; GP_callback[10]();}
	if((EXTI->PR)& (1<<11)){EXTI->PR |= 1<<11; GP_callback[11]();}
	if((EXTI->PR)& (1<<12)){EXTI->PR |= 1<<12; GP_callback[12]();}
	if((EXTI->PR)& (1<<13)){EXTI->PR |= 1<<13; GP_callback[13]();}
	if((EXTI->PR)& (1<<14)){EXTI->PR |= 1<<14; GP_callback[14]();}
	if((EXTI->PR)& (1<<15)){EXTI->PR |= 1<<15; GP_callback[15]();}

}
//--------------------------------------------------------




