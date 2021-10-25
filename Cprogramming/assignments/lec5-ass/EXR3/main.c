/*
 * main.c
 *
 *  Created on: Oct 13, 2021
 *      Author: bassam
 */

#include <stdio.h>

void Recursion(void){

char ch;
scanf("%c",&ch);
if(ch != '\n'){
    Recursion();
    printf("%c",ch);
	
	

}

}

int main(void){

printf("Enter a sentence:");
fflush(stdin);fflush(stdin);
Recursion();

}



