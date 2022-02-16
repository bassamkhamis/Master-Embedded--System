/*
 * alarm.h
 *
 *  Created on: Feb 15, 2022
 *      Author: bassam
 */

#ifndef ALARM_H_
#define ALARM_H_



#include "state.h"
/* There are only 2 state machine */
STATE(alarm_on);
STATE(alarm_off);

/* pointer to functin(state)*/
void (*state_alarm)();



#endif /* ALARM_H_ */
