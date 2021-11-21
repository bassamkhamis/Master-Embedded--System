/*
 * main.c
 *
 *  Created on: Oct 13, 2021
 *      Author: bassam
 */

#include <stdio.h>


int main(void){

   char val='a';
   char* p_val=&val;
   int count;

   for(count=0;count<26;count++){
	   printf("%c ",val);
	   *p_val+=1;

   }






 return 0;
}





