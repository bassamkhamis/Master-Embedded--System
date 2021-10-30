/*
 * main.c
 *
 *  Created on: Oct 13, 2021
 *      Author: bassam
 */

#include <stdio.h>
struct Sstudent{
	char s_name[50];
	int s_roll;
	float s_Mark;
};

int main(void){
	struct Sstudent student;

	printf("Enter information of student :\n\n");
	printf("Enter Name:");
	fflush(stdin);fflush(stdout);
	scanf("%s",&student.s_name);
	printf("Enter Roll Number:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&student.s_roll);
	printf("Enter Mark:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&student.s_Mark);
	printf("\n\nDispaly information ");
	printf("Name:%s\n",student.s_name);
	printf("Roll:%d\n",student.s_roll);
	printf("Marks:%f\n",student.s_Mark);




return 0;
}






