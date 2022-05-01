/*
 * keypad.c
 *
 *  Created on: Apr 23, 2022
 *      Author: bassam
 */


#include "keypad.h"

char key_row[]={R0, R1, R2, R3};
uint16_t key_column[]={C0, C1, C2, C3};



GPIO_configPin_t GConfigPin;
void Keypad_init()
{


	GConfigPin.GPIO_PinNumber=R0;
	GConfigPin.GPIO_Mode=GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(KEYPAD_PORT, &GConfigPin);

	GConfigPin.GPIO_PinNumber=R1;
	GConfigPin.GPIO_Mode=GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(KEYPAD_PORT, &GConfigPin);

	GConfigPin.GPIO_PinNumber=R2;
	GConfigPin.GPIO_Mode=GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(KEYPAD_PORT, &GConfigPin);

	GConfigPin.GPIO_PinNumber=R3;
	GConfigPin.GPIO_Mode=GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(KEYPAD_PORT, &GConfigPin);
	//	DataDir_KEYPAD_PORT &= ~(1<<R0 | 1<<R1 | 1<<R2 | 1<<R3);

	GConfigPin.GPIO_PinNumber=C0;
	GConfigPin.GPIO_Mode=GPIO_MODE_OUTPUT_PP;
	GConfigPin.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &GConfigPin);

	GConfigPin.GPIO_PinNumber=C1;
	GConfigPin.GPIO_Mode=GPIO_MODE_OUTPUT_PP;
	GConfigPin.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &GConfigPin);

	GConfigPin.GPIO_PinNumber=C2;
	GConfigPin.GPIO_Mode=GPIO_MODE_OUTPUT_PP;
	GConfigPin.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &GConfigPin);

	GConfigPin.GPIO_PinNumber=C3;
	GConfigPin.GPIO_Mode=GPIO_MODE_OUTPUT_PP;
	GConfigPin.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &GConfigPin);
	//	DataDir_KEYPAD_PORT |= (1<<C0 | 1<<C1 | 1<<C2 | 1<<C3);
	//	KEYPAD_PORT =0xff; //active PUR for input pins



}
char Keypad_getkey()
{
	int i,j;
	for(i=0; i<4; i++){


		MCAL_GPIO_WritePin(KEYPAD_PORT, C0, GPIO_HIGH);
		MCAL_GPIO_WritePin(KEYPAD_PORT, C1, GPIO_HIGH);
		MCAL_GPIO_WritePin(KEYPAD_PORT, C2, GPIO_HIGH);
		MCAL_GPIO_WritePin(KEYPAD_PORT, C3, GPIO_HIGH);
		//		KEYPAD_PORT |=  ((1<<C0 | 1<<C1 | 1<<C2 | 1<<C3));

		MCAL_GPIO_WritePin(KEYPAD_PORT, key_column[i], GPIO_LOW);
		//		KEYPAD_PORT &= ~(1<<key_column[i]);

		for(j=0; j<4; j++){

			if(!(MCAL_GPIO_ReadPin(KEYPAD_PORT, key_row[j]))){
				//if(!(keypadPIN & (1<<key_row[j]))){

				while(!(MCAL_GPIO_ReadPin(KEYPAD_PORT, key_row[j])));

				switch(i){

				case 0:
					if(0 == j) return '7';
					else if(1 == j) return '4';
					else if(2 == j) return '1';
					else if(3 == j) return '@';
					break;
				case 1:
					if(0 == j) return '8';
					else if(1 == j) return '5';
					else if(2 == j) return '2';
					else if(3 == j) return '0';
					break;
				case 2:
					if(0 == j) return '9';
					else if(1 == j) return '6';
					else if(2 == j) return '3';
					else if(3 == j) return '=';
					break;
				case 3:
					if(0 == j) return '/';
					else if(1 == j) return '*';
					else if(2 == j) return '-';
					else if(3 == j) return '+';
					break;
				default:
					return 'A';
					break;



				}
			}
		}


	}

	return 'A';

}


