/*
 * app.c
 *
 *  Created on: Feb 17, 2022
 *      Author: bassam
 */


#include <stdio.h>
#include "_queue.h"
#include "Student_MS.h"

int main(){

   int choose;
   Node_info arr_node[QUEUE_LENGTH];
   queue_t students_queue;
   FIFO_init(arr_node,&students_queue,QUEUE_LENGTH);

	DPRINTF("Welcome to the Student Management System\n\n");

		while(1)
		{
			DPRINTF("---------------------------------\n");
			DPRINTF("Choose the task that you want to perform\n");
			DPRINTF("1-  Add the student details manually\n");
			DPRINTF("2-  Add the student details from text file\n");
			DPRINTF("3-  Find the student details by roll number\n");
			DPRINTF("4-  Find the student details by first name\n");
			DPRINTF("5-  Find the student details by course id\n");
			DPRINTF("6-  Find the total number of students\n");
			DPRINTF("7-  Delete the student details by roll number\n");
			DPRINTF("8-  Update the student details by roll number\n");
			DPRINTF("9-  Show all information\n");
			DPRINTF("10- Exit\n");

			DPRINTF("\nEnter option number: ");
			scanf("%d", &choose);
			DPRINTF("---------------------------------\n");

			switch(choose)
			{
			case 1: add_student_manually(&students_queue);
			      break;
			case 2: add_student_from_file(&students_queue);
			      break;
			case 3: find_student_by_roll(&students_queue);
			      break;
			case 4: find_student_by_fname(&students_queue);
			      break;
			case 5: find_student_by_course(&students_queue);
			      break;
			case 6: print_students_num(&students_queue);
			      break;
			case 7: delete_student_by_roll(&students_queue);
			      break;
			case 8: update_student_by_roll(&students_queue);
			      break;
			case 9: show_students_info(&students_queue);
			      break;
			case 10: return 0;
			default: DPRINTF("[ERROR] Invalid Option! Try again\n");
			        break;
			}

		}

		return 0;



}
