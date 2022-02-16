/*
 * pressureSensor.c
 *
 *  Created on: Feb 15, 2022
 *      Author: bassa
 */


#include "pressureSensor.h"

int pressureVal;

/*
 * This module can be only one state machine but for UMI implementation
 * i decided to be 2 state
 * */

STATE(get_value){


	pressureVal = getPressureVal();
	state_sensor = STATE_NAME(send_value);
	state_sensor();  // @ not proper

}
/*
 * I know above state_sensor() this will open NEW STACK but so far so good,
 * get_value ---> send_value
 * */
STATE(send_value){

	pressure_value(pressureVal);
	state_sensor = STATE_NAME(get_value);

}
