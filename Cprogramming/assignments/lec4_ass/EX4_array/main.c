/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>

int main(){

	int repo[10];
	int i=0,location,num,val;

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

	printf("Enter element to be inserted \n");
	fflush(stdout);fflush(stdin);
	scanf("%d",&val);

	printf("Enter location \n");
	fflush(stdout);fflush(stdin);
	scanf("%d",&location);
	--location;

	for(i=num;location<=i;i--){
		repo[i+1]=repo[i];
	}
	repo[location]=val;

	printf("elements after:\n");
	for(i=0; i<num+1; i++){

		printf("%d ",repo[i]);
	}


	return 0;

}
