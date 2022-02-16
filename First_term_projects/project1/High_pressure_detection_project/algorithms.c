/*
 * algorithms.c
 *
 *  Created on: Feb 15, 2022
 *      Author: bassa
 */
#include "algorithms.h"
int pressureValue=0;
int threshlod =20;
int state = 0 ;
/*communication API(pressure_value(int pVal)) 
 * send pressure value from pressure_sensor module to Algorithms module
 *
 * */
void pressure_value(int pVal){

	pressureValue = pVal ;
	(threshlod >= pressureValue)?(state_algor=STATE_NAME(wait)):(state_algor=STATE_NAME(action));
}

STATE(wait){

	state = 0;
	sent_alarm_state(state);
}
STATE(action){
	state = 1;
	sent_alarm_state(state);
}
