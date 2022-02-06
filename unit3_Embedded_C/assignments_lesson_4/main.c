/*
Auther ::bassam
Date   ::Feb 5 2022

*/
#include <stdint.h>
#define SYSCTL_RCG2_R       (*((volatile unsigned long *)0x400FE108))  
#define GPIO_PORTF_DATA_R    (*((volatile unsigned long *)0x400253FC))    
#define GPIO_PORTF_DIR_R    (*((volatile unsigned long *)0x40025400))     
#define GPIO_PORTF_DEN_R    (*((volatile unsigned long *)0x4002551c)) 

uint32_t volatile g32= sizeof(uint32_t);
uint16_t volatile g16= sizeof(uint16_t);
uint8_t volatile g8= sizeof(uint8_t);
void main(){
	volatile unsigned long counter;
	SYSCTL_RCG2_R=0x00000020;
	//delay to take sure GPIOF is up and Running 
	for(counter=0; counter<200; counter++);
	// direction is out for port f pin 3
	GPIO_PORTF_DIR_R |= 1<<3;    
	GPIO_PORTF_DEN_R |= 1<<3;
	
	while(1){
		GPIO_PORTF_DATA_R |=1<<3;
    	for(counter=0; counter<200000; counter++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
    	for(counter=0; counter<200000; counter++);
		
		
		
	}
	
	
	
	
	
}