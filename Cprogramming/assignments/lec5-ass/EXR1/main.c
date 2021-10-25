/*
 * main.c
 *
 *  Created on: Oct 13, 2021
 *      Author: bassam
 */

#include <stdio.h>

// fun to calculate prime number 
int funTocheck(int num){


	int count ,flag=1;

	for (count=2; count<num; count++){

		if (num%count == 0){
			flag=0;
			break;
		}
	}

	return flag;
}

int main(void){


	int num1,num2,count,flag;


	printf("enter two number (interval)");
	fflush(stdin);fflush(stdout);
	scanf("%d%d",&num1,&num2);
	printf("prime number btw %d and %d are\n",num1,num2);
for (count=num1+1; count<num2; count++){
	flag=funTocheck(count);
	if (flag){
		printf("%d ",count);
	}
}



}




