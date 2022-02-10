/*
 * main.c
 *
 *  Created on: Feb 10, 2022
 *      Author: Bassam
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "_queue.h"
queue_tpye buffer1[QUEUE_LENGTH];
uint8_t i;
queue_tpye temp;
int main(void) {

	queue_t lifo1;
	FIFO_init(buffer1,&lifo1,QUEUE_LENGTH);
	for(i=1; i<8; i++)
		FIFO_enqueue(&lifo1,i);

	FIFO_print(&lifo1);
	FIFO_dequeue(&lifo1,&temp);
	FIFO_dequeue(&lifo1,&temp);
	FIFO_dequeue(&lifo1,&temp);

	FIFO_print(&lifo1);

	FIFO_dequeue(&lifo1,&temp);
	FIFO_dequeue(&lifo1,&temp);
	FIFO_dequeue(&lifo1,&temp);
	FIFO_dequeue(&lifo1,&temp);



	return 0;
}


