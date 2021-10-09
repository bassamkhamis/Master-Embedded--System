/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>

int main(){
	char num;

	printf("Enter a numbers:");
	fflush(stdout);fflush(stdin);
	scanf("%c",&num);
	printf("Sum:%d",num);

	return 0;

}
