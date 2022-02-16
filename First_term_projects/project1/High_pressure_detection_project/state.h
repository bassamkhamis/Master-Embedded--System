/*
 * state.h
 *
 *  Created on: Feb 15, 2022
 *      Author: bassa
 */

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>
#include "driver/driver.h"
enum{
	LED_ON,
	LED_OFF


}state_t;


#define STATE(_ST_Name_) void State_##_ST_Name_()
#define STATE_NAME(_ST_Name_) State_##_ST_Name_

void pressure_value(int pVal);
void sent_alarm_state(int state);

#endif /* STATE_H_ */
