/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>

int main(){

	int repo[10][10],row,columns,repo2[10][10];
	int i=0,j=0;

	printf("Enter the values of row, culomns\n");
	fflush(stdout);fflush(stdin);
	scanf("%d%d",&row,&columns);
	for(i=0; i<row; i++){

		for(j=0 ;j<columns; j++){

			printf("Enter the element a%d%d\n",i+1,j+1);
			fflush(stdout);fflush(stdin);
			scanf("%d",&repo[i][j]);

		}

	}
	printf("Array is:\n");
	for(i=0; i<row; i++){

		for(j=0 ;j<columns; j++){

			printf("%d ",repo[i][j]);

		}
		printf("\n");
	}

	for(i=0; i<row; i++){

		for(j=0 ;j<columns; j++){

			repo2[j][i] = repo[i][j];

		}

	}

	for(i=0; i<columns; i++){

		for(j=0 ;j<row; j++){

			printf("%d ",repo2[i][j]);

		}
		printf("\n");
	}




	return 0;

}
