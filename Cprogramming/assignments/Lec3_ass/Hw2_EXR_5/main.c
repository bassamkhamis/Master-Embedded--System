/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>

int main(){
	char num1=0;

	printf("Enter a Character:");
	fflush(stdout);fflush(stdin);
	scanf("%c",&num1);

	if(num1>=65 && num1<=122)           // 65:122 ASCII code
		printf("%c is a alphabet",num1);
	else
		printf("%c is Not alphabet",num1);






	return 0;

}
