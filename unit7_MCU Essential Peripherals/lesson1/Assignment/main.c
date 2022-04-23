/*
 * main.c
 *
 *  Created on: Apr 23, 2022
 *      Author: bassam
 */


#include "GPIO_private.h"
#include "utils.h"
#define F_CPU 1000000UL


void pseudo_delay(int s){


	for(int i=0; i<(s*1000); i++);
}

int main()
{
  // set pin 4,5,6 and 7 as output
  SET_BIT(DDRD,4);
  SET_BIT(DDRD,5);
  SET_BIT(DDRD,6);
  SET_BIT(DDRD,7);

  while (1)
  {

	  SET_BIT(POTRD,4);
	  CLEAR_BIT(POTRD,5);
	  CLEAR_BIT(POTRD,6);
	  CLEAR_BIT(POTRD,7);
	  pseudo_delay(1000);

	  CLEAR_BIT(POTRD,4);
	  SET_BIT(POTRD,5);
	  CLEAR_BIT(POTRD,6);
	  CLEAR_BIT(POTRD,7);
	  pseudo_delay(1000);

	  CLEAR_BIT(POTRD,4);
	  CLEAR_BIT(POTRD,5);
	  SET_BIT(POTRD,6);
	  CLEAR_BIT(POTRD,7);
	  pseudo_delay(1000);

	  CLEAR_BIT(POTRD,4);
	  CLEAR_BIT(POTRD,5);
	  CLEAR_BIT(POTRD,6);
	  SET_BIT(POTRD,7);
	  pseudo_delay(1000);


  }




}
