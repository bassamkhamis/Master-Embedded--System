/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>

int main(){
	float num1=0;

	printf("Enter a number:");
	fflush(stdout);fflush(stdin);
	scanf("%f",&num1);

        if(num1>0)
        	printf("Number:%f is positive",num1);
        else if (num1<0)
        	printf("Number:%f is Negative",num1);
        else
        	printf("Number:%f is Zero",num1);




	return 0;

}
