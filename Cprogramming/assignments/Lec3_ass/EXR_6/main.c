/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>

int main(){
	float a=0, b=0,temp=0;

	printf("Enter value of a:");
	fflush(stdout);fflush(stdin);
	scanf("%f",&a);
	fflush(stdout);fflush(stdin);
	printf("Enter value of b:");
	fflush(stdout);fflush(stdin);
	scanf("%f",&b);
	temp = a;
	a=b;
	b=temp;

	printf("After swapping, a is:%f\r\n",a);
	printf("After swapping, b is:%f",b);


	return 0;

}
