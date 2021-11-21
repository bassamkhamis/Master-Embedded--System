/*
 * main.c
 *
 *  Created on: Oct 13, 2021
 *      Author: bassam
 */

#include <stdio.h>
#include <string.h>

struct semploye{
	char* name;
	int id;
};
int main(void){

	struct semploye emp1={"Alex",99},emp2={"salah",200};
	struct semploye (*arr[])={&emp1,&emp2};
	struct semploye (*(*ptr)[2])=&arr;

	printf("%s\n",(**(*ptr)).name);
	printf("%d",(**(*ptr)).id);











 return 0;
}





