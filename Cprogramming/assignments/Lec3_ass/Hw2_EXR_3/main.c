/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>

int main(){
	float num1=0, num2=0, num3=0;

	printf("Enter three number:");
	fflush(stdout);fflush(stdin);
	scanf("%f%f%f",&num1,&num2,&num3);

	if(num1>num2){

		if(num1>num3)
			printf("number %f is greater one", num1);
		else
			printf("number %f is greater one", num3);

		}
	else {

		if(num2>num3)
			printf("number %f is greater one", num2);
		else
			printf("number %f is greater one", num3);


	}


	return 0;

}
