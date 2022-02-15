/*
 * collsion_avoidance.c
 *
 *  Created on: Feb 13, 2022
 *      Author: bassa
 */


#include "collision_avoidance.h"

unsigned int speed;
unsigned int distance;
unsigned int threshold = 50;

STATE(ca_waiting){

	CA_state_ID = CA_waiting ;

	speed=0;
	printf("waiting state: dis=%d, speed=%d\n",distance,speed);
	DC_motor(speed);


}
STATE(ca_driven){

	CA_state_ID = CA_driven ;

	speed=30;
	printf("driven state: dis=%d, speed=%d\n",distance,speed);
	DC_motor(speed);



}

void US_distance_set(int s){

	distance = s;
	(distance <= threshold) ? (CA_state=STATE_NAME(ca_waiting)) : (CA_state=STATE_NAME(ca_driven)) ;
	printf("US>>>>>>CA:distance=%d\n",distance);


}
