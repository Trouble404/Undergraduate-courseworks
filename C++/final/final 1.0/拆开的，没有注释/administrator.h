/* administrator.h */
/* 管理员类声明 */ 


#ifndef _ADMINSTRATOR_H 
#define _ADMINISTRATOR_H 

#include "student.h" 
#include "course.h" 
#include "input.h"

using namespace std;


class administrator
{
	friend class menu;
	friend class student;
	friend class course;
   private:
	    string name_AD;
		string password_AD;
   public:
	   administrator();
	   void log_ad();
	   ~administrator()
	   {}
};

#endif