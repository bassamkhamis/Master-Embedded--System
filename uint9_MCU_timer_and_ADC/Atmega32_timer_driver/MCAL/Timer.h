/*
 * Timer.h
 *
 *  Created on: Aug 9, 2022
 *      Author: bassa
 */

#ifndef MCAL_TIMER_H_
#define MCAL_TIMER_H_



//*************************************************************
//********************* Includes **********************
//*************************************************************

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "../STD_TYPES.h"
#include "../utils.h"



//*************************************************************
//********************* Define Data types**********************
//*************************************************************

typedef enum {

	NORMAL,
	CTC = 0x08,
}TIMER0_MODE_t;

typedef enum {
   NO_CLCK,
   NO_PRESCALING,
   PRESCALING_CLK8,
   PRESCALING_CLK64,
   PRESCALING_CLK256,
   PRESCALING_CLK1024,
   EXTERNAL_CLK_FALLING,
   EXTERNAL_CLK_RISING

}TIMER0_CLOCK_t;



typedef enum{
	//Output Compare Match Interrupt Enable
	OCMI_ENABLE = 0x02,
	OCMI_DISABLE = 0x0,
	//Timer/Counter0 Overflow Interrupt Enable
}TIMER0_OCMIE_t;

typedef enum{
	//Timer/Counter0 Overflow Interrupt Enable
	TOF_ENABLE = 0x01,
	TOF_DISABLE = 0x0,

}TIMER0_TOFIE_t;


typedef struct {
	TIMER0_MODE_t Mode;
	TIMER0_CLOCK_t Clok;
	TIMER0_OCMIE_t OCME_Interrupt;
	TIMER0_TOFIE_t TOFE_Interrupt;

}ST_TIMER0Config_t;



//*************************************************************
//*********************       APIs       **********************
//*************************************************************

E_Status_t TIMER0_Init(ST_TIMER0Config_t *config);
E_Status_t TIMER0_STOP(void);


E_Status_t TIMER0_GetComapreValue(ptr_uint8_t pu8_Ticks);
E_Status_t TIMER0_SetComapreValue(u8 u8_Ticks);

E_Status_t TIMER0_GetCounterValue(ptr_uint8_t pu8_Ticks);
E_Status_t TIMER0_SetCounterValue(u8 u8_Ticks);

E_Status_t TIMER0_GetOverflowValue(ptr_uint8_t pu8_Ticks);
E_Status_t TIMER0_SetOverflowValue(u8 u8_Ticks);

E_Status_t TIMER0_SetCallBack_OVERFLOW(Ptr_VoidFunVoid CallBack );
E_Status_t TIMER0_SetCallBack_CompareMatch(Ptr_VoidFunVoid CallBack );





#endif /* MCAL_TIMER_H_ */
