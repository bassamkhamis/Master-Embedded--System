/*
 * Student_MS.h
 *
 *  Created on: Feb 17, 2022
 *      Author: bassa
 */

#ifndef STUDENT_MS_H_
#define STUDENT_MS_H_

#include "_queue.h"
#define NUM_COURSES 5

	void add_student_manually(queue_t *students_queue);
	void add_student_from_file(queue_t *students_queue);
	void find_student_by_roll(queue_t *students_queue);
	void find_student_by_fname(queue_t *students_queue);
	void find_student_by_course(queue_t *students_queue);
	void print_students_num(queue_t *students_queue);
	void delete_student_by_roll(queue_t *students_queue);
	void update_student_by_roll(queue_t *students_queue);
	void show_students_info(queue_t *students_queue);

     /*private APIs*/

	 Node_info *search_by_roll(queue_t *students_queue, int roll);


#endif /* STUDENT_MS_H_ */
