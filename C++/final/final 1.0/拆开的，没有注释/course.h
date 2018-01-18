
/* course.h */

#ifndef _COURSE_H 
#define _COURSE_H 
#include "input.h"

class course
{
	friend class menu;
	friend class adminstrator;
	friend class student;
private:
	   string course_name;
	   string course_ID;
	   string course_teacher;
public:
	   vector<course> COU;
	   course();
	   void set_course(string COURSE_NAME , string COURSE_ID , string COURSE_TEACHER);
	   void course_inf();
	   void input_course();
	   void output_course();
	   void course_Add();
	   void course_Delete();
	   void course_Edit();
	   void course_Browse();
	   ~course(){}
};

#endif 