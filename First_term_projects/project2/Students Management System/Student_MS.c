/*
 * Student_MS.c
 *
 *  Created on: Feb 17, 2022
 *      Author: Bassam
 */


#include "Student_MS.h"


void add_student_manually(queue_t *students_queue){

	Node_info newStudent;
	 int i;

	 if(students_queue->count >= students_queue->leangth){
		 DPRINTF("No space for a new incoming\n");
		 return ;
	 }
	 else {

			 DPRINTF("Add the student details\n");
			 DPRINTF("Enter the roll number:");
			 scanf("%d",&newStudent.roll);
			 // if no there same roll in queue
			if ( !search_by_roll(students_queue,newStudent.roll) ){

					DPRINTF("Enter the first name: ");
					scanf("%s", newStudent.fname);

					DPRINTF("Enter the last name: ");
					scanf("%s", newStudent.lname);

					DPRINTF("Enter the GPA obtained: ");
					scanf("%f", &newStudent.GPA);

					DPRINTF("Enter the course ID for each course\n");
					for(i = 0; i < NUM_COURSES; i++)
					{
						DPRINTF("Course %d id: ", i + 1);
						scanf("%d", &newStudent.cid[i]);
					}
		    	}
			// if the roll is already exist
			else {

				 DPRINTF("\n[ERROR] Roll number %d is already exist\n", newStudent.roll);
				 DPRINTF("\n[ERROR] Adding students manually failed\n");
				 return ;
			}


	 }
    // check!, if every thing is done and inform the user
	 if (FIFO_enqueue(students_queue,newStudent) == QUEUE_NO_ERROR){
		 DPRINTF("\n[INFO] Student details are added successfully\n");
		 DPRINTF("[INFO] the total number of student is:%d\n",students_queue->count);
		 DPRINTF("[INFO] you can add up to:%d\n",students_queue->leangth);
		 DPRINTF("[INFO] you can add %d more students:\n",(students_queue->leangth) - (students_queue->count));

	   }
	 else {

		 DPRINTF("\n[ERROR] Adding students manually failed\n");
	 }
 }
void add_student_from_file(queue_t *students_queue){

	Node_info newStudent;
	int i;
	FILE *pstudent= fopen("students.txt", "r");

	if(pstudent == NULL){
		DPRINTF("[ERROR] failed to open file\n");

	}
	while(!feof(pstudent)){

		fscanf(pstudent,"%d",&newStudent.roll);
		// if no there same roll in queue
		if ( !search_by_roll(students_queue,newStudent.roll) ){


				fscanf(pstudent,"%s", newStudent.fname);

				fscanf(pstudent,"%s", newStudent.lname);

				fscanf(pstudent,"%f", &newStudent.GPA);

				//the course ID for each course
				for(i = 0; i < NUM_COURSES; i++)
				{

					fscanf(pstudent,"%d", &newStudent.cid[i]);
				}
			    // check!, if every thing is done and inform the user
				 if (FIFO_enqueue(students_queue,newStudent) == QUEUE_NO_ERROR){
					 DPRINTF("\n[INFO] Student details are added successfully\n");
					 DPRINTF("[INFO] the total number of student is:%d\n",students_queue->count);
					 DPRINTF("[INFO] you can add up to:%d\n",students_queue->leangth);
					 DPRINTF("[INFO] you can add %d more students:\n",(students_queue->leangth) - (students_queue->count));

				   }
				 else {

					 DPRINTF("\n[ERROR] Adding students from file failed\n");
				 }

	    	}
		// if the roll is already exist
		else {

			 DPRINTF("\n[ERROR] Roll number %d is already exist\n", newStudent.roll);
			 DPRINTF("\n[ERROR] Adding students failed\n");
				fscanf(pstudent, "%*[^\n]");
				continue;
	    	}

	  }

// close file
	fclose(pstudent);

}
void find_student_by_roll(queue_t *students_queue){

	// local variable will be used
	int roll,i;
	Node_info *findStudent;

	DPRINTF("Enter the roll number of the student:\n");
	scanf("%d",&roll);
	findStudent = search_by_roll(students_queue, roll);
	if(findStudent != NULL){

		DPRINTF("The student details are:\n");
		DPRINTF("the first name is:%s\n", findStudent->fname);
		DPRINTF("the last name is:%s\n", findStudent->lname);
		DPRINTF("the last name is:%f\n", findStudent->GPA);

		// the courses
		for( i = 0; i<NUM_COURSES; i++ ){

			DPRINTF("the course ID is:%d\n", findStudent->cid[i]);
		}

	}
	else{

		DPRINTF("[ERROR] the roll number %d not found\n",roll);

	}


}
void find_student_by_fname(queue_t *students_queue){

	queue_tpye *pstudent = students_queue->tail;
    int i=0,j,flag=0; char temp[20];

	DPRINTF("Enter the first name of student:");
	scanf("%s",temp);

	 for(i=0; i<students_queue->count; i++ ){

		 if(!strcmp(temp,pstudent->fname)){

				DPRINTF("The student details are:\n");
				DPRINTF("the first name is:%s\n", pstudent->fname);
				DPRINTF("the last name is:%s\n", pstudent->lname);
				DPRINTF("the last name is:%f\n", pstudent->GPA);

				// the courses
				for( j = 0; j<NUM_COURSES; j++ ){

					DPRINTF("the course ID is:%d\n", pstudent->cid[j]);
				 }
				// just only if it entered this condition gust one
                 flag = 1;
		    }


		   if(pstudent+1 > students_queue->base + students_queue->leangth){

			  pstudent = students_queue->base ;
		     }

		   else{
			   pstudent++;
		     }

	 }

	 if(!flag){

		 DPRINTF("[ERROR] the first name %s not found\n",temp);
	 }


}
void find_student_by_course(queue_t *students_queue){

	queue_tpye *pstudent = students_queue->tail;
	    int i=0,j,flag=0,c_ID;

		DPRINTF("Enter the course ID:");
		scanf("%d",&c_ID);

		 for(i=0; i<students_queue->count; i++ ){


					// loop on all courses
					for( j = 0; j<NUM_COURSES; j++ ){


						 if( pstudent->cid[j] == c_ID){

									DPRINTF("The student details are:\n");
									DPRINTF("the first name is:%s\n", pstudent->fname);
									DPRINTF("the last name is:%s\n", pstudent->lname);
									DPRINTF("the role number is:%d\n", pstudent->roll);
									DPRINTF("the GPA is:%f\n", pstudent->GPA);
									// just only if it entered this condition gust one
								    flag = 1;
									break;
									// just only if it entered this condition gust one
									 flag = 1;
								}

					 }



				   if(pstudent+1 > students_queue->base + students_queue->leangth){

					  pstudent = students_queue->base ;
					 }

				   else{
					   pstudent++;
					 }


			 }

			 if(!flag){

				 DPRINTF("[ERROR] the course ID %d not found\n",c_ID);
			 }



}
void print_students_num(queue_t *students_queue){




	if (students_queue->count != 0){

		 DPRINTF("[INFO] the total number of student is:%d\n",students_queue->count);
		 DPRINTF("[INFO] you can add up to:%d\n",students_queue->leangth);
		 DPRINTF("[INFO] you can add %d more students:\n",(students_queue->leangth) - (students_queue->count));

	   }
	 else {

		 DPRINTF("\n[ERROR] There are not students\n");
	 }

}
void delete_student_by_roll(queue_t *students_queue){

	Node_info *student;
	int roll;

	DPRINTF("Enter the role number witch you want to delete\n");
	scanf("%d",&roll);
	student = search_by_roll(students_queue, roll);

	if(student != NULL){

			if(student == students_queue->head){

				students_queue->head--;

			}
			else if(student == students_queue->tail){

				students_queue->tail++;
			}
			else{
				while( student != (students_queue->tail) ){

					*student = *(student-1);
					student--;
				}
				students_queue->tail++;
			}

           // modify count
			students_queue->count--;
			DPRINTF("[INFO] The roll number is removed successfully\n");
	}else{

		DPRINTF("[ERROR] the roll number %d not found\n",roll);
	}

}
void update_student_by_roll(queue_t *students_queue){

	Node_info *student;
	int roll,choose,i;

	DPRINTF("Enter the role number to update the entry\n");
	scanf("%d",&roll);
	student = search_by_roll(students_queue, roll);
	if( student != NULL){

		DPRINTF("1. First name\n");
		DPRINTF("2. Last name\n");
		DPRINTF("3. GPA \n");
		DPRINTF("4. Roll number\n");
		DPRINTF("5. courses\n");
		scanf("%d",&choose);

		switch(choose){

		case 1: DPRINTF("Enter the  new First name\n");
		        scanf("%s",student->fname);break;

		case 2: DPRINTF("Enter the New last name\n");
		        scanf("%s",student->lname); break;

		case 3: DPRINTF("Enter the New GPA\n");
		        scanf("%f",&student->GPA); break;

		case 4: DPRINTF("Enter the  New Roll number\n");
		         scanf("%d",&student->roll); break;

		case 5: for(i=0; i<NUM_COURSES; i++ ){
			     DPRINTF("Enter the course %d:\n", i+1);
                 scanf("%d",&student->cid[i]);
	              } break;

		default: DPRINTF("[ERROR]");break;

		}
		DPRINTF("[INFO] UPDATED successfully");


	}else{
		DPRINTF("[ERROR] the roll number %d not found\n",roll);
	}


}
void show_students_info(queue_t *students_queue){


	FIFO_print(students_queue);

}
 /*private APIs*/
Node_info* search_by_roll(queue_t *students_queue, int roll){

	 queue_tpye *pstudent = students_queue->tail;
	 int i=0;
	 for(; i<students_queue->count; i++ ){

		 if(pstudent->roll == roll){

                 break;
		 }

	   if(pstudent+1 > students_queue->base + students_queue->leangth){

		  pstudent = students_queue->base ;
	   }

	   else{
		   pstudent++;
	   }

	 }

  if(students_queue->count == i)
	  pstudent = NULL ;


    return pstudent;
 }
