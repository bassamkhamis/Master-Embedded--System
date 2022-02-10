/*
 * linked_list.h
 *
 *  Created on: Feb 10, 2022
 *      Author: bassa
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <conio.h>

/**************define new data type********************/
typedef struct {
	char Name[40];
	int ID;
	float height;

}data_t;


struct Sstudent{

	data_t info;
	struct Sstudent *pnext;

};

typedef enum {

	NO_ERROR,
	ERROR


}status_t;

/******************** API prototype *************************/
status_t  Add_student(void);
status_t  delete_student(void);
status_t  delete_all(void);
status_t  view_students(void);
// option API
status_t  getNthnode(void);
status_t  Length_Iterative(void);
int length_Recursive(struct Sstudent * ptr);
status_t  LengthRecursive(void);
status_t  getNthfromEnd(void);
status_t  reverse_list(void);




/*********************************************************/

#define DPRINTF(...)              fflush(stdout);\
		                          fflush(stdin);\
		                          printf(__VA_ARGS__);\
		                          fflush(stdout);\
		                          fflush(stdin)

#endif /* LINKED_LIST_H_ */
