/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>

int main(){
	int num1=0, num2=0;

	printf("Enter two integers:");
	fflush(stdout);fflush(stdin);
	scanf("%d%d",&num1,&num2);
	printf("Sum:%d",num1+num2);

	return 0;

}
