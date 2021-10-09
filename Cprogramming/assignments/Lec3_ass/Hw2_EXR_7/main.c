/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>

int main(){
	int num1=0, count=0, sum=1;

	printf("Enter a Positive Value:");
	fflush(stdout);fflush(stdin);
	scanf("%i",&num1);

	if(num1>0){
		for(count=num1; count>0;  count--)
			sum *= count;
		printf("Factorial is:%i:",sum);

	}
	else if(num1==0)
		printf("Factorial 0 is:1");

	else
		printf("ERROR 404!!! Factorial of Negative number dosn't Exist");

	return 0;

}
