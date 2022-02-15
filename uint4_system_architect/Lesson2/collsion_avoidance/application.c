/*
 * application.c
 *
 *  Created on: Feb 13, 2022
 *      Author: bassa
 */


#include "collision_avoidance.h"
#include "DC_motor.h"
#include "ultrasonic.h"


void setup(){


	US_init();
	DC_init();
	CA_state = STATE_NAME(ca_waiting);
	US_state =STATE_NAME(us_busy);
	DC_state = STATE_NAME(dc_idle);
}

int main(){

	volatile int time;
	setup();

	while(1){

		US_state();
		CA_state();
		DC_state();
		for(time=0; time<1000;time++);


	}

return 0;
}
