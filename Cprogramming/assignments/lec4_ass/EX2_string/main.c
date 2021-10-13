/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>
#include <string.h>

int main(){

   char string[100];
   int count=0,num=0;
   printf("Enter string: ");
   fflush(stdout);fflush(stdin);
   gets(string);  

   while(string[count]!=0){
        count++;
   }

   printf("the length is %d",count);


	return 0;

}
