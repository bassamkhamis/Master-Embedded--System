


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "stack.h"

stack_tpye static_stack[STACK_LENGTH];
uint32_t i = 0;
stack_tpye temp;
int main(void){
	// create a mechanism stack
	stack_t buffer1,buffer2;
	// initialize
    stack_init(static_stack,&buffer1, STACK_LENGTH);
	stack_tpye *dynamics_stack = (stack_tpye*) malloc(STACK_LENGTH*sizeof(stack_tpye));
	if(dynamics_stack){
		stack_init(dynamics_stack,&buffer2, STACK_LENGTH);

        printf("static buffer contain these elements:\n");
		for(i=0;i<7;i++){
			stack_push(&buffer1,i);

		}
		printf("dynamics buffer contain these elements:\n");
		for(i=0;i<7;i++){
			stack_push(&buffer2,i);
		}

		printf("print all elements in static buffer :\n");
	   stack_print(buffer1);
	   printf(" print all elements in dynamics buffer :\n");
		stack_print(buffer2);
		stack_pop(&buffer1,&temp);
		stack_pop(&buffer1,&temp);
		stack_pop(&buffer1,&temp);
		stack_pop(&buffer1,&temp);
		stack_pop(&buffer1,&temp);
		stack_pop(&buffer2,&temp);
		stack_pop(&buffer2,&temp);
		printf("print all elements in static buffer :\n");
		stack_print(buffer1);
		printf(" print all elements in dynamics buffer :\n");
		stack_print(buffer2);
	}

	free(dynamics_stack);
return 0;
}
