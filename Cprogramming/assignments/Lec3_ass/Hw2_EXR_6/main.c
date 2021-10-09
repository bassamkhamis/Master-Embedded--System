/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>

int main(){
	unsigned num1=0, count=0, sum=0;

	printf("Enter a Positive Value:");
	fflush(stdout);fflush(stdin);
	scanf("%i",&num1);

	for(count=0; count<=num1; count++)
		sum+=count;

	printf("sum %i is ",sum);







	return 0;

}
