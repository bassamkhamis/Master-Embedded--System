/*
 * MAX7221.h
 *
 *  Created on: Jul 27, 2022
 *      Author: bassa
 */

#ifndef HAL_MAX7221_H_
#define HAL_MAX7221_H_


//***********************************************
//********* Function declaration ****************
//***********************************************

void HAL_MAX7221Init();
void HAL_MAX7221_Send(u8 cmd, u8 data);


//***********************************************
//********* Macros  *****************************
//***********************************************

// port b
#define SS             4
#define MOSI           5
#define MISO           6
#define  SCK           7

#endif /* HAL_MAX7221_H_ */
