/*
 * _queue.h
 *
 *  Created on: Feb 10, 2022
 *      Author: bassa
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// student information
typedef struct {

	char fname[40];
	char lname[40];
	int cid[5];
	int roll;
	float GPA;

}Node_info;

// user configuration (uint8_t, uint16_t,....)
#define queue_tpye Node_info
// number of node in each QUEUE buffer
#define QUEUE_LENGTH  50
//structure of QUEUE
typedef struct {
	uint8_t leangth;
	uint8_t count;
	queue_tpye *base;
	queue_tpye *head;
	queue_tpye *tail;

}queue_t;
// return status of all methods of QUEUE mechanism
typedef enum{
QUEUE_NO_ERROR,
QUEUE_FULL,
QUEUE_EMPTY,
QUEUE_NOT_FULL,
QUEUE_NOT_EMPTY,
QUEUE_NULL
}queue_satus_t;

queue_satus_t FIFO_enqueue(queue_t* queue,queue_tpye item);
queue_satus_t FIFO_dequeue(queue_t* queue,queue_tpye* item);
queue_satus_t FIFO_init(queue_tpye* buffer,queue_t* queue,uint8_t  length);
queue_satus_t FIFO_print(queue_t* queue);

/*******************/
#define DPRINTF(...)              fflush(stdout);\
		                          fflush(stdin);\
		                          printf(__VA_ARGS__);\
		                          fflush(stdout);\
		                          fflush(stdin)

#endif /* QUEUE_H_ */
