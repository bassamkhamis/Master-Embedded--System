/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>

int main(){

	int repo[10];
	int i=0,found=-1,num,val;

	printf("Enter the values of element\n");
	fflush(stdout);fflush(stdin);
	scanf("%d",&num);
	for(i=0; i<num; i++){
		printf("Enter element %d:",i+1);
		fflush(stdout);fflush(stdin);
		scanf("%d",&repo[i]);

	}
	printf("elements are:\n");
	for(i=0; i<num; i++){

		printf("%d ",repo[i]);
	}

	printf("Enter element to be search \n");
	fflush(stdout);fflush(stdin);
	scanf("%d",&val);


	for(i=0;i<num;i++){
		if(repo[i]==val){
			found=i+1;
			break;
		}

	}

	if(found>0)
		printf("Number foun at location %d",found);
	else
		printf("Number not found!!");

	return 0;

}
