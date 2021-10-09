/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>

int main(){
	int a=0, b=0;

	printf("Enter value of a:");
	fflush(stdout);fflush(stdin);
	scanf("%d",&a);
	fflush(stdout);fflush(stdin);
	printf("Enter value of b:");
	fflush(stdout);fflush(stdin);
	scanf("%d",&b);
	a=a^b;
	b=a^b;
	a=a^b;

	printf("After swapping, a is:%d\n",a);
	printf("After swapping, b is:%d",b);


	return 0;

}
