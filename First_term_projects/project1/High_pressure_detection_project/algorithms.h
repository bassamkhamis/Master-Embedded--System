/*
 * algorithms.h
 *
 *  Created on: Feb 15, 2022
 *      Author: bassa
 */

#ifndef ALGORITHMSMODULE_ALGORITHMS_H_
#define ALGORITHMSMODULE_ALGORITHMS_H_


#include "state.h"


/* There are only 2 state machine */
STATE(wait);
STATE(action);


/* pointer to functin(state)*/
void (*state_algor)();





#endif /* ALGORITHMSMODULE_ALGORITHMS_H_ */
