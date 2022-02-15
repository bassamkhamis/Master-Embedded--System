/*
 * DC_motor.h
 *
 *  Created on: Feb 13, 2022
 *      Author: bassa
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "state.h"

enum{
	DC_idle,
	DC_busy

}DC_state_ID;


void DC_init();
STATE(dc_idle);
STATE(dc_busy);

void (*DC_state)();


#endif /* DC_MOTOR_H_ */
