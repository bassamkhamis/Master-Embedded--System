/*
 * main.c
 *
 *  Created on: Oct 13, 2021
 *      Author: bassam
 */

#include <stdio.h>

int factorial_Recursion(int num){


  if(num==0 || num==1)
	  return 1;

  return num*factorial_Recursion(num-1);
}

int main(void){
 int num,factorial;
 printf("Enter an positive integer ");
 fflush(stdout);fflush(stdin);
 scanf("%d",&num);
 factorial = factorial_Recursion(num);
 printf("The factorial is: %d",factorial);



}




