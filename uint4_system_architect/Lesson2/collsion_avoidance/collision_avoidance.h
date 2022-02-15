/*
 * collsion_avoidance.h
 *
 *  Created on: Feb 13, 2022
 *      Author: bassa
 */

#ifndef COLLISION_AVOIDANCE_H_
#define COLLISION_AVOIDANCE_H_

#include "state.h"
//#define STATE_define(_stateFunc_)   void ST_##__stateFunc_()
//#define STATE(_stateFunc_)   ST_##__stateFunc_

enum{

	CA_waiting,
	CA_driven


}CA_state_ID;




STATE(ca_waiting);
STATE(ca_driven);

void (*CA_state)();


#endif /* COLLISION_AVOIDANCE_H_ */
