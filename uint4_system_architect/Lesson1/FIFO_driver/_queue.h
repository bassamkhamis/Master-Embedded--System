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

// user configuration (uint8_t, uint16_t,....)
#define queue_tpye uint8_t
// number of node in each QUEUE buffer
#define QUEUE_LENGTH  5
//structure of QUEUE
typedef struct {
	queue_tpye leangth;
	queue_tpye count;
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
queue_satus_t FIFO_init(queue_tpye* buffer,queue_t* queue,queue_tpye length);
queue_satus_t FIFO_print(queue_t* queue);


#endif /* QUEUE_H_ */
