//#include <stdint.h>
//#include <stdio.h>

#include "driver.h"
#include "pressureSensor.h"
#include "algorithms.h"
#include "alarm.h"


void setup(){

	state_algor = STATE_NAME(wait);
	state_alarm = STATE_NAME(alarm_off);
	state_sensor = STATE_NAME(get_value);

}


int main (){
	GPIO_INITIALIZATION();
	setup();
	while (1)
	{
		//Implement your Design 
		state_sensor();
		state_algor();
		state_alarm();

	}


	return 0;
}
