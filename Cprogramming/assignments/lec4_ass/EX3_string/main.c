/*
 ============================================================================
 Name        : 2_Cprogramming.c
 Author      : Bassam
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char string[100], rev_string[100];
	int count=0,len;
	printf("Enter string: ");
	fflush(stdout);fflush(stdin);
	gets(string);
	len = strlen(string);
	printf("the len is %d \n",len);
	for(count=0; count<len; count++){

		rev_string[count] = string[len-count-1];
	}
	rev_string[count]=0;

	printf("the reverse is %s",rev_string);

	return EXIT_SUCCESS;
}



