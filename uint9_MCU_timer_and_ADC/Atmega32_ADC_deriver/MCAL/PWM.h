/*
 * PWM.h
 *
 *  Created on: Aug 9, 2022
 *      Author: bassa
 */

#ifndef MCAL_PWM_H_
#define MCAL_PWM_H_



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

	PWM_FAST = 0x48,
	PWM_PHASE_CORRECT = 0x40,
}PWM0_MODE_t;

typedef enum {
	PWM_NO_CLCK,
	PWM_NO_PRESCALING,
	PWM_PRESCALING_CLK8,
	PWM_PRESCALING_CLK64,
	PWM_PRESCALING_CLK256,
	PWM_PRESCALING_CLK1024,
	PWM_EXTERNAL_CLK_FALLING,
	PWM_EXTERNAL_CLK_RISING

}PWM0_CLOCK_t;

typedef enum{
	//Timer/Counter0 Overflow Interrupt Enable
	PWM_TOF_ENABLE = 0x01,
	PWM_TOF_DISABLE = 0x0,

}PWM0_TOFIE_t;

typedef enum{

	PWM_Non_Inverted = 0x20,
	PWM_Inverted = 0x30,

}PWM0_Waveform_t;


typedef struct {
	PWM0_MODE_t Mode;
	PWM0_CLOCK_t Clok;
	PWM0_TOFIE_t TOFE_Interrupt;
	PWM0_Waveform_t Waveform;

}ST_PWM0Config_t;



//*************************************************************
//*********************       APIs       **********************
//*************************************************************

E_Status_t PWM0_Init(ST_PWM0Config_t *config);
E_Status_t PWM0_STOP(void);


E_Status_t PWM0_GetComapreValue(ptr_uint8_t pu8_Ticks);
E_Status_t PWM0_SetComapreValue(u8 u8_Ticks);

void PWM0_SetCallBack_OVERFLOW(Ptr_VoidFunVoid CallBack );


#endif /* MCAL_PWM_H_ */

