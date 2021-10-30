/*
 * main.c
 *
 *  Created on: Oct 13, 2021
 *      Author: bassam
 */

#include <stdio.h>
struct Sdistance{
	float s_feet;
	float s_inch;

};

int main(void){
	struct Sdistance distance1, distance2,result;

	printf("Enter information of 1st distance :\n");
	printf("Enter feet:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&distance1.s_feet);
	printf("Enter inch:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&distance1.s_inch);

	printf("Enter information of 2st distance :\n");
	printf("Enter feet:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&distance2.s_feet);
	printf("Enter inch:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&distance2.s_inch);

	result.s_feet=distance1.s_feet + distance2.s_feet;
	result.s_inch=distance1.s_inch + distance2.s_inch;
	if(result.s_inch>12.0f){
		result.s_inch -=12;
		result.s_feet++;

	}

	printf("\n");
	printf("Sum of distance=%0.2f feet and %0.2f inch",result.s_feet,result.s_inch);






return 0;
}






