/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>

int main(){
	int num=0;

	printf("Enter an integer:");
	fflush(stdout);fflush(stdin);
	scanf("%d",&num);
	printf("Your entered:%d",num);

	return 0;

}
