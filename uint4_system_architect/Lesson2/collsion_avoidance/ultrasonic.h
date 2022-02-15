/*
 * ultrasonic.h
 *
 *  Created on: Feb 13, 2022
 *      Author: bassa
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "state.h"

enum{
	US_busy
}US_state_ID;

void US_init();
STATE(us_busy);
void (*US_state)();




#endif /* ULTRASONIC_H_ */
