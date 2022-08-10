/*
 * WDT.c
 *
 *  Created on: Aug 4, 2022
 *      Author: bassa
 */

#include <avr/io.h>
#include "../utils.h"
#include <util/delay.h>




void MCAL_WDT_ON(void)
{
	WDTCR |= ( 1 << WDE | 1 << WDP1 | 1<<WDP2);    // Time out 1sec
}

void MCAL_WDT_OFF(void)
{
	WDTCR |= (1<<WDE | 1<<WDTOE);
	WDTCR = 0x00;
}
