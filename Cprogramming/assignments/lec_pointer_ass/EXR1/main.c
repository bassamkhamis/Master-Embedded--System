/*
 * main.c
 *
 *  Created on: Oct 13, 2021
 *      Author: bassam
 */

#include <stdio.h>


int main(void){

    int m=29;

    printf("Address of m :0X%x\n",&m);
    printf("Value of m : %d\n",m);

    int* ab=&m;

    printf("Address of pointer ab :0X%x\n",ab);
    printf("Content of pointer ab : %d\n",*ab);

    m=34;
    printf("Address of pointer ab :0X%x\n",ab);
    printf("Content of pointer ab : %d\n",*ab);

    *ab=7;
    printf("Address of m :0X%x\n",&m);
    printf("Value of m : %d",m);







 return 0;
}





