/*
 * alarm.c
 *
 *  Created on: Feb 15, 2022
 *      Author: bassa
 */
#include "alarm.h"

/*communication API(sent_alarm_state)
 * Module Algorithms send to Alarm module
 *
 * */

void sent_alarm_state(int state){


	(state)?(state_alarm=STATE_NAME(alarm_on)):(state_alarm=STATE_NAME(alarm_off));


}
/*Her, We have two state machine Alarm on and Alarm off
 * below, The requirement was 60 second, but i put it approximated 10 second for better
 * result on simulation
 * */
STATE(alarm_on){

	Set_Alarm_actuator(LED_ON);
	Delay(10000);
	Set_Alarm_actuator(LED_OFF);
	Delay(10000);
}
STATE(alarm_off){

	Set_Alarm_actuator(LED_OFF);
}
