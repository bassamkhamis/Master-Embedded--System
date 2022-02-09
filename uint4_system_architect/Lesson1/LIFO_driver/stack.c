/*
 * stack.c
 *
 *  Created on: Feb 9, 2022
 *      Author: bassa
 */
#include "stack.h"
stack_satus_t stack_push(stack_t* stack,stack_tpye item){

	stack_satus_t return_tatus = STACK_NO_ERROR;
	if(stack && (stack_is_full(stack)==STACK_NOT_FULL)){
    *(stack->head) = item ;
    stack->count++;
    stack->head++;
    printf("pushed a %d\n", item);
	}else{
		return_tatus = STACK_NULL;
	}
return return_tatus ;

}
stack_satus_t stack_pop(stack_t* stack,stack_tpye* item){
	stack_satus_t return_tatus = STACK_NO_ERROR;
	if(stack && (stack_is_empty(stack)==STACK_NOT_EMPTY)){
		stack->head--;
		*item =*(stack->head);
		stack->count--;
		printf("popped a %d\n", *item);
	}else{
		return_tatus = STACK_NULL;
	}
return return_tatus ;

}
stack_satus_t stack_init(stack_tpye* buffer,stack_t* stack,stack_tpye length){

	stack_satus_t return_tatus = STACK_NO_ERROR;
	if(buffer){

	stack->leangth=length ;
	stack->count = 0 ;
    stack->base = buffer ;
    stack->head = buffer ;
	}else{
		return_tatus = STACK_NULL;
	}
return return_tatus ;
}
stack_satus_t stack_is_full(stack_t* stack){


	stack_satus_t return_tatus = STACK_NO_ERROR;
	if(stack->count>=stack->leangth){

		return_tatus=STACK_FULL;
	}else{
		return_tatus = STACK_NOT_FULL;
	}
return return_tatus ;

}
stack_satus_t stack_is_empty(stack_t* stack){
	stack_satus_t return_status = STACK_NO_ERROR;
	if(stack->count == 0U){

		return_status=STACK_EMPTY;
	}else{
		return_status = STACK_NOT_EMPTY;
	}
return return_status ;

}
stack_satus_t stack_print(stack_t buffer){
	stack_tpye i;
	stack_satus_t return_status = STACK_NO_ERROR;
	if(buffer.head&&buffer.count){

	for(i=0; i<buffer.count; i++){
		buffer.head--;
		printf("Elemnt number %d is >>> ",buffer.count-i);
		printf("%d\n",*(buffer.head));
    	}
  }else{
	  printf("\n!!!!!STACK IS EMPTY!!!!!!\n\n");
	  return_status = STACK_NULL ;
  }
return return_status;
}


