/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>

int main(){
	float num1=0, num2=0;

	printf("Enter two numbers:");
	fflush(stdout);fflush(stdin);
	scanf("%f%f",&num1,&num2);
	printf("Sum:%f",num1*num2);

	return 0;

}
