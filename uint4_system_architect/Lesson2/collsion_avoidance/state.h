/*
 * state.h
 *
 *  Created on: Feb 13, 2022
 *      Author: bassa
 */

#ifndef STATE_H_
#define STATE_H_




#include <stdio.h>
#include <stdlib.h>


#define STATE(_ST_Name_) void State_##_ST_Name_()
#define STATE_NAME(_ST_Name_) State_##_ST_Name_

void DC_motor(int s);
void US_distance_set();

#endif /* STATE_H_ */
