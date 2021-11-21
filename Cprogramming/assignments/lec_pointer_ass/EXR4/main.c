/*
 * main.c
 *
 *  Created on: Oct 13, 2021
 *      Author: bassam
 */

#include <stdio.h>
#include <string.h>


int main(void){

  int data[50],max;
  int* p_data=data;
  int count;
  printf("Input the number of elements to store in the array (max 15) :");
  fflush(stdin);fflush(stdout);
  scanf("%d", &max);
  for(count=0; count<max; count++){
	  printf("element- %d ",count+1);
	  fflush(stdin);fflush(stdout);
	  scanf("%d", &data[count]);

  }
  p_data+=max-1;
  for(count=0;count<max;count++){
	  printf("%d ",*p_data);
	  p_data--;
  }






 return 0;
}





