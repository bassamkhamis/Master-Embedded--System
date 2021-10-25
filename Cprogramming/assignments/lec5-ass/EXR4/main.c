/*
 * main.c
 *
 *  Created on: Oct 13, 2021
 *      Author: bassam
 */

#include <stdio.h>

int Recursion(int base, int power){
if(power == 0){
	return 1;
}

else {
	return base*Recursion(base,power-1);
}


}

int main(void){

int base ,power,val;
printf("Enter The base number:\n");
fflush(stdin);fflush(stdout);
scanf("%d",&base);
fflush(stdin);fflush(stdout);
printf("Enter The power number:\n");
fflush(stdin);fflush(stdout);
scanf("%d",&power);
fflush(stdin);fflush(stdout);
val = Recursion(base,power);
printf("The result = %d\n",val);


}




