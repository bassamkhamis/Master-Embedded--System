/*
 * main.c
 *
 *  Created on: Oct 13, 2021
 *      Author: bassam
 */

#include <stdio.h>
#include <string.h>


int main(void){

  char data[50];
  char* p_data=data;
  int len,count;
  printf("Input a string");
  fflush(stdin);fflush(stdout);
  scanf("%s", data);
  len=strlen(data);
  p_data+=len-1;
  for(count=0;count<len;count++){
	  printf("%c",*p_data);
	  p_data--;
  }






 return 0;
}





