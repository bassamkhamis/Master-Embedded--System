/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>

int main(){
	char  num=0;

	printf("Enter alphabet:");
	fflush(stdout);fflush(stdin);
	scanf("%c",&num);
	if((num=='a')||(num=='i')||(num=='e') || (num=='o') || (num=='u'))
		printf("%c is Vowel",num);
	else
	   printf("%c is constant",num);



	return 0;

}
