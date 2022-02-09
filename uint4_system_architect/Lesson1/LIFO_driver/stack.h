/*
 * stack.h
 *
 *  Created on: Feb 9, 2022
 *      Author: bassa
 */

#ifndef STACK_H_
#define STACK_H_



#include <stdio.h>
#include <stdint.h>

// user configuration (uint8_t, uint16_t,....)
#define stack_tpye uint8_t
// number of node in each stack buffer
#define STACK_LENGTH  5
//structure of stack
typedef struct {
	stack_tpye leangth;
	stack_tpye count;
	stack_tpye *base;
	stack_tpye *head;

}stack_t;
// return status of all methods of stack mechanism
typedef enum{
STACK_NO_ERROR,
STACK_FULL,
STACK_EMPTY,
STACK_NOT_FULL,
STACK_NOT_EMPTY,
STACK_NULL
}stack_satus_t;
// API declarations
stack_satus_t stack_push(stack_t* stack,stack_tpye item);
stack_satus_t stack_pop(stack_t* stack,stack_tpye* item);
stack_satus_t stack_init(stack_tpye* buffer,stack_t* stack,stack_tpye length);
stack_satus_t stack_is_full(stack_t* stack);
stack_satus_t stack_is_empty(stack_t* stack);
stack_satus_t stack_print(stack_t buffer);

#endif /* STACK_H_ */
