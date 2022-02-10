/*
 * main.c
 *
 *  Created on: Feb 10, 2022
 *      Author: Bassam
 */

#include "linked_list.h"

int main(){






char user_input[4];
char temp=1;


		while(temp){

			DPRINTF("\n*******************\n");
			DPRINTF("choose one of the following option:\n");
			DPRINTF("Add New student: 1\n");
	//		DPRINTF("Delete one student: 2\n");
			DPRINTF("Delete ALL students: 3\n");
			DPRINTF("View ALL students: 4\n");
	//		DPRINTF("get Nth node: 5\n");
	//		DPRINTF("get length of node by Iterative method: 6\n");
	//		DPRINTF("get length of node by Recursion method: 7\n");
			DPRINTF("get Nth node from end list: 8\n");
			DPRINTF("Reverse the list: 9\n");
			DPRINTF("exit: 0\n");
			gets(user_input);
			temp = atoi(user_input) ;
			switch(temp){

			case 1:
				Add_student();
				break;
			case 2:
				delete_student();
				break;
			case 3:
				delete_all();
				break;
			case 4:
				view_students();
				break;
			case 5:
				getNthnode();
				break;
			case 6:
				Length_Iterative();
				break;
		    case 7:
				LengthRecursive();
				break;
		    case 8:
		    	getNthfromEnd();
				break;
		    case 9:
		    	reverse_list();
				break;

			default:
				break;

			}


		}

return 0;
}

