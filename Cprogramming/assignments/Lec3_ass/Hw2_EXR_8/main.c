/*
 * main.c

 *
 *  Created on: Oct 9, 2021
 *      Author: bassam
 */

#include <stdio.h>

int main(){
	float  num1=0, num2=0,result ;
	char opreator ;

	printf("Enter Operator ether + , -, * or /");
	fflush(stdout);fflush(stdin);
	scanf("%c",&opreator);

	printf("Enter Tow number");
	fflush(stdout);fflush(stdin);
	scanf("%f%f",&num1,&num2);

   switch(opreator){

   case '+':
   result =num1+num2;
   break;

   case '-':
   result =num1-num2;
   break;

   case '*':
   result =num1*num2;
   break;

   case '/':
   result =num1/num2;
   break;
   default:
	   printf("ERROR 404!!!!!");


   }
   printf("Result is:%f",result);


   return 0;

}
