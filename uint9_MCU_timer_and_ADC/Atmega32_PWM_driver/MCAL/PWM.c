/*
 * PWM.c
 *
 *  Created on: Aug 9, 2022
 *      Author: bassa
 */

//*************************************************************
//*********************       Includes   **********************
//*************************************************************
#include "PWM.h"


//*************************************************************
//********************* GLOBALE Variable **********************
//*************************************************************

ST_PWM0Config_t *PWM0config ;

Ptr_VoidFunVoid PWM0CallBack_OverFlow = null ;

//*************************************************************
//******************* APIs Implementation**********************
//*************************************************************

E_Status_t PWM0_Init(ST_PWM0Config_t *config)
{
	E_Status_t u8_retVal = E_NOK;
	if( null == config)
	{
		u8_retVal = E_NOK;
	}
	else
	{
		PWM0config = config;
		if( PWM_FAST == PWM0config->Mode  ||  PWM_PHASE_CORRECT == PWM0config->Mode )
		{
			TCCR0 |=  PWM0config->Mode;
			u8_retVal = E_OK;
		}
		else
		{
			u8_retVal = E_NOK;
		}


		if( PWM_NO_CLCK <= PWM0config->Clok  &&  PWM_EXTERNAL_CLK_RISING >= PWM0config->Clok )
		{
			TCCR0 |=  PWM0config->Clok;
			u8_retVal = E_OK;
		}
		else
		{
			u8_retVal = E_NOK;
		}


		if( PWM_TOF_ENABLE == PWM0config->TOFE_Interrupt  ||  PWM_TOF_DISABLE == PWM0config->TOFE_Interrupt )
		{
			TIMSK |=  PWM0config->TOFE_Interrupt;
			u8_retVal = E_OK;
		}
		else
		{
			u8_retVal = E_NOK;
		}


		if( PWM_Non_Inverted == PWM0config->Waveform ||  PWM_Inverted == PWM0config->Waveform )
		{
			TCCR0 |=  PWM0config->Waveform;
			u8_retVal = E_OK;
		}
		else
		{
			u8_retVal = E_NOK;
		}


	}

	return u8_retVal;
}
E_Status_t PWM0_STOP(void)
{
	E_Status_t u8_retVal = E_NOK;
	// CLOCK No source
	// TCCR0 = NO_CLCK
	CLEAR_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);

	return u8_retVal;
}


E_Status_t PWM0_GetComapreValue(ptr_uint8_t pu8_Ticks)
{
	E_Status_t u8_retVal = E_NOK;
	*pu8_Ticks = OCR0 ;
	return u8_retVal;
}
E_Status_t PWM0_SetComapreValue(u8 u8_Ticks)
{
	E_Status_t u8_retVal = E_NOK;
	OCR0 = u8_Ticks ;
	return u8_retVal;
}

void PWM0_SetCallBack_OVERFLOW(Ptr_VoidFunVoid CallBack )
{
	PWM0CallBack_OverFlow = CallBack ;
}

