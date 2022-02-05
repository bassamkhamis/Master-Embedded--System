/****************************************************/
/*** Auther : Bassam
/** Date    : 15-Dec 2021
/****************************************************/


#include "uart.h"
unsigned char string_buffer[100]= "learn-in-depth:<Bassam>";
volatile unsigned const char string_buffer_2[100]={1,2,3,4,5,6,7,8,9,10};
volatile unsigned  string_buffer_3;
volatile unsigned  string_buffer_4;
void main(){
	
Uart_Send_string(string_buffer);	
}
