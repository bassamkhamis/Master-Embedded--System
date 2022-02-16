/*
 * pressureSensor.h
 *
 *  Created on: Feb 15, 2022
 *      Author: bassam
 */

#ifndef PRESSURESENSOR_H_
#define PRESSURESENSOR_H_


#include "state.h"
#include <stdint.h>
/* There are only 2 state machine */
STATE(get_value);
STATE(send_value);

/* pointer to functin(state)*/
void (*state_sensor)();


#endif /* PRESSURESENSOR_H_ */
