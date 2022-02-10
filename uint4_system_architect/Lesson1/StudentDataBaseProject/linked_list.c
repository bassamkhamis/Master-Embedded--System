/*
 * linked_list.c
 *
 *  Created on: Feb 10, 2022
 *      Author: bassa
 */

#include "linked_list.h"

struct Sstudent *gp_head = NULL;
struct Sstudent *gp_tail = NULL;

status_t Add_student(void){
	status_t status = NO_ERROR ;
    char temp[40]={0};
	struct Sstudent *newStudent = (struct Sstudent *) malloc(sizeof(struct Sstudent));

	if(newStudent){

		        // first node
				if(gp_head == NULL && gp_tail == NULL ){
					gp_head = newStudent ;
					gp_tail = newStudent ;
				}//there is (are) previous node(s)
				else{
					gp_tail->pnext = newStudent ;
					gp_tail = newStudent ;
				}
                // interact with user, store all information
				DPRINTF("\nEnter her(has) ID\n");
				gets(temp);
				newStudent->info.ID=atoi(temp);
				DPRINTF("Enter her(has) Name\n");
				gets(newStudent->info.Name);
				DPRINTF("Enter her(has) Height\n");
				gets(temp);
				newStudent->info.height=atof(temp);
		        // make Pnext of new node points to NULL
				newStudent->pnext = NULL ;

	      }
	 else
	   status = ERROR;



return status;
}
status_t delete_student(void){
	status_t status = NO_ERROR ;
	struct Sstudent *pprevious ,*pcurrent = gp_head;
    char temp[40]={0};
    int ID;
if(pcurrent)  {
    DPRINTF("\nEnter ID you want to deleted");
    gets(temp);
    ID = atoi(temp);
     //check!! first element
    if(gp_head->info.ID == ID){
    	pcurrent = gp_head;
    	gp_head = gp_head->pnext;
    }

    else{

    	 while(pcurrent){

    		  pprevious = pcurrent;
    		  pcurrent = pcurrent->pnext;

        	  if(ID == pcurrent->info.ID){
        		  pprevious->pnext = pcurrent->pnext ;
             	}



           }

       }
    free(pcurrent);
}

else{
	status = ERROR;
	DPRINTF("!!!!!!!! Empty!!!!");

}
return status;
}
status_t delete_all(void){
	status_t status = NO_ERROR ;
	struct Sstudent *ptemp, *pcurrent = gp_head;
		if(pcurrent){
			while(pcurrent){

				ptemp = pcurrent;
				pcurrent = pcurrent->pnext;
				free(ptemp);


			}
			gp_head = NULL;
			gp_tail = NULL;

		}
		else{
			status = ERROR;
			DPRINTF("!!!!!EMPTY!!!!!");

		}


	return status;
}
status_t view_students(void){
	status_t status = NO_ERROR ;
	struct Sstudent *pcurrent = gp_head;
	int count=1;
	if(pcurrent){
		while(pcurrent){

			DPRINTF("\nStudent Number:%d\n",count);
			DPRINTF("Student ID:%d\n",pcurrent->info.ID);
			DPRINTF("Student Name:%s\n",pcurrent->info.Name);
			DPRINTF("Student Height:%f\n\n",pcurrent->info.height);
			count++;
			pcurrent = pcurrent->pnext;


		}
	}
	else{
		status = ERROR;
		DPRINTF("!!!!!EMPTY!!!!!");

	}




	return status;

}

status_t  getNthnode(void){
	status_t status = NO_ERROR ;
	struct Sstudent *pcurrent = gp_head;
	int count=0,nth;
	char temp[4];

	if(pcurrent){

		DPRINTF("Enter Nth node you want get it, (ex 1 or 2 ....) \n");
		gets(temp);
		nth = atoi(temp);
		for(count=1; count<nth; count++){
			pcurrent = pcurrent->pnext;
		}
		DPRINTF("Student ID:%d\n",pcurrent->info.ID);
		DPRINTF("Student Name:%s\n",pcurrent->info.Name);
		DPRINTF("Student Height:%f\n\n",pcurrent->info.height);
	}
	else{
		status = ERROR;
		DPRINTF("!!!!!EMPTY!!!!!");

	}




	return status;



}

status_t  Length_Iterative(void){
	status_t status = NO_ERROR ;
	struct Sstudent *pcurrent = gp_head;
	int count=0;


	if(pcurrent){

		while(pcurrent){
			pcurrent = pcurrent->pnext;
			count++;
		}
		DPRINTF("linked list length by Iterative method = %d\n",count);

	}
	else{
		status = ERROR;
		DPRINTF("!!!!!EMPTY!!!!!");

	}




	return status;




}

int length_Recursive(struct Sstudent * ptr){


		//struct Sstudent *pcurrent = ptr;



		if(ptr){


			return 1 + length_Recursive(ptr->pnext);



		}
		else{

			//DPRINTF("!!!!!EMPTY!!!!!");
            return 0;
		}

}

status_t  LengthRecursive(void){
	status_t status = NO_ERROR ;

	DPRINTF("linked list length by Recursion method = %d\n",length_Recursive(gp_head));
	return status;
}

status_t  getNthfromEnd(void){
	status_t status = NO_ERROR ;
	char temp[4];
	int nth;
	struct Sstudent *pfast = gp_head;
	struct Sstudent *pslow = gp_head;
	if(pfast){
		DPRINTF("Enter Nth node from end you need to got it\n");
		nth=atoi(gets(temp));
		// move pointer fast to Nth node from a front
		while(nth){
			pfast = pfast->pnext;
			nth--;
		}
		// now, we can start
		while(pfast){
			pfast = pfast->pnext;
			pslow = pslow->pnext;
		}
		// now, we can start
		DPRINTF("information of Nth from end is:\n");
		DPRINTF("Student ID:%d\n",pslow->info.ID);
		DPRINTF("Student Name:%s\n",pslow->info.Name);
		DPRINTF("Student Height:%f\n\n",pslow->info.height);

	}
	else{
		status = ERROR ;
	}



	return status;
}

status_t  reverse_list(void){
	status_t status = NO_ERROR ;
	struct Sstudent *Pprev,*Pcuur,*Pnext;
	Pprev = Pcuur = Pnext = gp_head;


	if(gp_head){
		while(Pcuur){
			Pnext = Pcuur->pnext ;
			Pcuur->pnext = Pprev ;
			Pprev = Pcuur ;
			Pcuur = Pnext ;

		}
		// first node points to Null
		gp_head->pnext = NULL ;
		gp_head = Pprev;

	}
	else{
		status = ERROR ;
		DPRINTF("!!!!!EMPTY!!!!!");
	}


	return status;
}
