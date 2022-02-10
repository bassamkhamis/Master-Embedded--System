/*
 ============================================================================
 Name        : _queue_.c
 Author      : Bassam
 Version     :01v
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "_queue.h"


queue_satus_t FIFO_enqueue(queue_t* queue,queue_tpye item){
	queue_satus_t status = QUEUE_NO_ERROR ;
	// check! if queue still has empty element
	if((queue->count) < (queue->leangth)){
		// check! if queue reach to last element
		if((queue->base + sizeof(queue_tpye)*QUEUE_LENGTH)<(queue->head + 1)){
			*(queue->head)= item ;
			 queue->head =  queue->base;
		}
		// else!! queue till at beginning or any position except last one
		else{
			*(queue->head)= item;
			queue->head++;
		}

        queue->count++;
        printf("one element added into the enqueue:%d\n",item);
	}// is full
	else{

		status = QUEUE_FULL;
	}

  return status;
}
queue_satus_t FIFO_dequeue(queue_t* queue,queue_tpye* item){
	queue_satus_t status = QUEUE_NO_ERROR ;

	if(queue->count == 0){
		status = QUEUE_EMPTY;
		printf("\n!!!!! QUEUE IS EMPTY !!!!!\n");
	}
	else{
		if((queue->base + sizeof(queue_tpye)*QUEUE_LENGTH)<(queue->tail + 1)){
			*item = *(queue->tail);
			queue->tail = queue->base;
		}
		else{
			*item = *(queue->tail);
			queue->tail++;
		}
		queue->count--;
		printf("\nthis element goes out of queue :%d\n",*item);
	}

	return status;
}
queue_satus_t FIFO_init(queue_tpye* buffer,queue_t* queue,queue_tpye length){

	queue_satus_t status = QUEUE_NO_ERROR ;

	if(buffer){
		queue->leangth = length;
		queue->count = 0 ;
		queue->base = buffer;
		queue->head = buffer;
		queue->tail = buffer;

	}else{
		status = QUEUE_NULL ;

	}

	return status;
}
queue_satus_t FIFO_print(queue_t* queue){
	queue_satus_t status = QUEUE_NO_ERROR ;
	queue_tpye i,*ptail=queue->tail;
	if(queue->count == 0){
		status=QUEUE_EMPTY;
		printf("\n!!!! IS EMPTY!!!!\n");
	}
	else{
		printf("*****FIFO PRINT*****");
		for(i=0; i<queue->count; i++){
			printf("\n%d\n",*ptail);
			if((queue->base + sizeof(queue_tpye)*QUEUE_LENGTH)<(ptail + 1))
				ptail=queue->base;
			else
				ptail++;
		}
	printf("****************");
	}
	queue_tpye ptemp = queue->tail;

	return status;
}
