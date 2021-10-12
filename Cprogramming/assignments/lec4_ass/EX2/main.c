/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>

int main(){

	float repo[100], average,sum=0;
	int i=0,j=0;

	printf("Enter the number of elements\n");
	fflush(stdout);fflush(stdin);
	scanf("%d",&j);
	for(i=0; i<j; i++){

		printf("Enter data:");
		fflush(stdout);fflush(stdin);
		scanf("%f",&repo[i]);

	}

	for(i=0; i<j; i++){

		sum += repo[i];
	}

	average= sum/j;

	printf("The Average = %f",average);



	return 0;

}
