/*
 * main.c
 *
 *  Created on: Oct 13, 2021
 *      Author: bassam
 */

#include <stdio.h>
struct Scomplex{
	float s_real;
	float s_imag;

};

struct Scomplex add_structure(struct Scomplex num1, struct Scomplex num2);

int main(void){
	struct Scomplex num1, num2, result;

	printf("for 1st complex number:\n");
	printf("Enter real and imaginary number respectively:");
	fflush(stdin);fflush(stdout);
	scanf("%f%f",&num1.s_real,&num1.s_imag);


	printf("for 2nd complex number:\n");
	printf("Enter real and imaginary number respectively:");
	fflush(stdin);fflush(stdout);
	scanf("%f%f",&num2.s_real,&num2.s_imag);


	result= add_structure(num1,num2);
	printf("sum=%f+j%f",result.s_real,result.s_imag);





 return 0;
}


struct Scomplex add_structure(struct Scomplex num1, struct Scomplex num2){

	struct Scomplex result;
	result.s_real=num1.s_real + num2.s_real;
	result.s_imag=num1.s_imag + num2.s_imag;

	return result;
}




