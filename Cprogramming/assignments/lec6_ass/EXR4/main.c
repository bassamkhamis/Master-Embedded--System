/*
 * main.c
 *
 *  Created on: Oct 13, 2021
 *      Author: bassam
 */

#include <stdio.h>

struct Sstudent{
	char s_name[50];
	float s_Mark;
};


int main(void){
	struct Sstudent array[10];
	int count;
	float mark;

	printf("Enter information of the students:\n");
	for(count=0; count<10; count++){
		printf("for Roll number %d\n",count+1);
		printf("Enter name:");
		fflush(stdin);fflush(stdout);
		scanf("%s",array[count].s_name);
		fflush(stdin);fflush(stdout);
		printf("Enter Mark:");
		fflush(stdin);fflush(stdout);
		scanf("%f",&array[count].s_Mark);



	}
	printf(" display  information:");
	for(count=0; count<10; count++){
		printf("information for Roll number %d\n",count+1);
		printf("name:%s\n",array[count].s_name);
		printf("Mark:%f\n",array[count].s_Mark);
		printf("\n");

	}

 return 0;
}





