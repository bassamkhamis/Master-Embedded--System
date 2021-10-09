/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>

int main(){
	int num=0;

	printf("Enter integer number:");
	fflush(stdout);fflush(stdin);
	scanf("%d",&num);
    if(num%2==0)
    	printf("%d is Even",num);
    else
    	printf("%d is Odd",num);



	return 0;

}
