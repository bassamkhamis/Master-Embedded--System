/*
 * Timer.c
 *
 *  Created on: Aug 9, 2022
 *      Author: bassa
 */


//*************************************************************
//*********************       Includes   **********************
//*************************************************************
#include "Timer.h"


//*************************************************************
//********************* GLOBALE Variable **********************
//*************************************************************
Ptr_VoidFunVoid CallBack_OverFlow = null ;
Ptr_VoidFunVoid CallBack_Cmpare_Match = null ;

u8 u8_TOFNUMBER;

ST_TIMER0Config_t *TIMER0config ;



//*************************************************************
//********************APIs Implementation**********************
//*************************************************************

E_Status_t TIMER0_Init(ST_TIMER0Config_t *config)
{
	E_Status_t u8_retVal = E_NOK;

	if( null == config )
	{
		u8_retVal = E_NOK;
	}
	else
	{
		TIMER0config = config ;

		if(NORMAL == config->Mode || CTC == config->Mode )
		{
			TCCR0 &= ~(config->Mode ) ;
			TCCR0 |= config->Mode ;
			u8_retVal = E_OK;
		}
		else
		{
			u8_retVal = E_NOK;
		}

		if(NO_CLCK <= config->Clok && EXTERNAL_CLK_RISING >= config->Clok )
		{
			TCCR0 &= ~(config->Clok) ;
			TCCR0 |= config->Clok ;
			u8_retVal = E_OK;
		}
		else
		{
			u8_retVal = E_NOK;
		}

		if( OCMI_ENABLE == config->OCME_Interrupt || OCMI_DISABLE == config->OCME_Interrupt )
		{
			TIMSK &= ~(OCMI_ENABLE) ;
			TIMSK |= config->OCME_Interrupt ;
			u8_retVal = E_OK;
		}
		else
		{
			u8_retVal = E_NOK;
		}

		if(TOF_ENABLE == config->TOFE_Interrupt || TOF_DISABLE == config->TOFE_Interrupt )
		{

			TIMSK &= ~(TOF_ENABLE) ;
			TIMSK |= config->TOFE_Interrupt ;
			u8_retVal = E_OK;
		}
		else
		{
			u8_retVal = E_NOK;
		}



	}

return 	u8_retVal;

}
E_Status_t TIMER0_STOP(void)
{
	E_Status_t u8_retVal = E_OK;
	// CLOCK No source
	// TCCR0 = NO_CLCK
	CLEAR_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
	return 	u8_retVal;
}


E_Status_t TIMER0_GetComapreValue(ptr_uint8_t pu8_Ticks)
{
	E_Status_t u8_retVal = E_NOK;
	*pu8_Ticks = OCR0 ;
	return 	u8_retVal;

}
E_Status_t TIMER0_SetComapreValue(u8 u8_Ticks)
{
	E_Status_t u8_retVal = E_OK;
    OCR0 = u8_Ticks ;
	return 	u8_retVal;
}

E_Status_t TIMER0_GetCounterValue(ptr_uint8_t pu8_Ticks)
{
	E_Status_t u8_retVal = E_OK;
	*pu8_Ticks = TCNT0 ;
	return 	u8_retVal;
}
E_Status_t TIMER0_SetCounterValue(u8 u8_Ticks)
{
	E_Status_t u8_retVal = E_OK;
	TCNT0 = u8_Ticks ;
	return 	u8_retVal;
}

E_Status_t TIMER0_GetOverflowValue(ptr_uint8_t pu8_Ticks)
{
	E_Status_t u8_retVal = E_OK;
   *pu8_Ticks = u8_TOFNUMBER ;
	return 	u8_retVal;

}
E_Status_t TIMER0_SetOverflowValue(u8 u8_Ticks)
{
	E_Status_t u8_retVal = E_OK;
	u8_TOFNUMBER = u8_Ticks;
	return 	u8_retVal;
}

E_Status_t TIMER0_SetCallBack_OVERFLOW(Ptr_VoidFunVoid CallBack )
{
	E_Status_t u8_retVal = E_OK;
    CallBack_OverFlow = CallBack ;
	return 	u8_retVal;
}
E_Status_t TIMER0_SetCallBack_CompareMatch(Ptr_VoidFunVoid CallBack )
{
	E_Status_t u8_retVal = E_OK;
    CallBack_Cmpare_Match = CallBack;
	return 	u8_retVal;
}


// ISR

ISR(TIMER0_COMP_vect)
{   u8_TOFNUMBER++;
	CallBack_Cmpare_Match();
}


ISR(TIMER0_OVF_vect)
{
	u8_TOFNUMBER++;
	CallBack_OverFlow();


}
