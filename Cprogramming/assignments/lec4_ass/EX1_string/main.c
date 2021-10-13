/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>
#include <string.h>

int main(){

   char string[100], character,count=0,num=0;
   printf("Enter string: ");
 //  fflush(stdout);fflush(stdin);
   gets(string);
//   fflush(stdout);fflush(stdin);
   printf("Enter character to be found");

   character = getchar();
   putchar(character);
   while(string[(int)count]!=0){

	   if(string[(int)count]==character){
		   num++;
	   }
        count++;
   }

   printf("the character %c is found %d times",character,num);


	return 0;

}
