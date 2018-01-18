/* student.h */
/* 学生类的声明 */ 

#ifndef _STUDENT_H 
#define _STUDENT_H 
#include "input.h"
using namespace std;

class student
{
	friend class menu;
	friend class course;
	friend class adminstrator;
   private:
	   string name_ST;
	   string password_ST;
	   string student_ID;
	   string student_grade;
	   int student_mark;
	   string selection_cour[3]; //student can choose 3 courses
   public:
	   vector<student> STU;
	   student();
	   student(string NAME_ST , string PASSWORD_ST , string STUDENT_ID , string STUDENT_GRADE , int STUDENT_MARK, string selection_cour1="***", string selection_cour2="***", string selection_cour3="***");
	 
	   student student_login();
	   void student_Add();
	   void student_Delete();
	   void student_Browse();
	   void student_Edit();

	   void student_inf();
	   void itself_inf(); 

	   void input_inf(); //
	   void output_inf();

	   void course_sel(student stu);
	   ~student()
	   {}
};




#endif 


