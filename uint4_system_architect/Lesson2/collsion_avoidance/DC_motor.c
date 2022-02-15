/*
 * DC_motor.c
 *
 *  Created on: Feb 13, 2022
 *      Author: bassa
 */


#include "DC_motor.h"
unsigned int speed;


DC_motor(int s){

	speed = s;
	DC_state = STATE_NAME(dc_busy) ;
	printf("CA>>>>>>DC:speed=%d\n",speed);

}

void DC_init(){
	//init DC
	printf("DC_init\n");

}
STATE(dc_idle){
	DC_state_ID = DC_idle ;
	DC_state = STATE_NAME(dc_idle);
	printf("DC_idle state: speed=%d\n",speed);


}
STATE(dc_busy){
	DC_state_ID = DC_busy ;
	DC_state = STATE_NAME(dc_idle);
	printf("DC_busy state: speed=%d\n",speed);

}
