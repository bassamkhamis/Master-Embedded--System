/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>

int main(){

	float A[2][2],B[2][2];
	int i=0,j=0;
	printf("Enter the elements of 1st matrix\n");
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			printf("Enter a%d%d",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&A[i][j]);
		}

	}
	printf("Enter the elements of 2nd matrix\n");
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			printf("Enter a%d%d",i+1,j+1);
			fflush(stdout);fflush(stdin);
			scanf("%f",&B[i][j]);
		}

	}

	printf("Sum of Matrixes:\n");
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			printf("%f ",A[i][j]+B[i][j]);
			fflush(stdout);
		}
		printf("\n");
	}











	return 0;

}
