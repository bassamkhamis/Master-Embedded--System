/*
 * ultrasonic.c
 *
 *  Created on: Feb 13, 2022
 *      Author: bassa
 */

#include "ultrasonic.h"
unsigned int distance=0;
int generate_random(int l, int h, int count){

	int i,rand_num=0;
	for(i=0; i<count; i++){
		rand_num = (rand() % (h - l + 1)) + l;

	}
	return rand_num ;

}

void US_init(){

	// init US_sensor
	// call the Driver of function
	printf("US_init\n");

}
STATE(us_busy){

	US_state_ID = US_busy;
	distance = generate_random(45, 55, 1) ;
	printf("US_busy state: distance=%d\n",distance);
	// send distance
	US_distance_set(distance);
	US_state = STATE_NAME(us_busy);



}
