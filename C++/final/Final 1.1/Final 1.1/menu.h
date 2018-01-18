
#ifndef _MENU_H 
#define _MENU_H 
#include "input.h"

class menu
{
	friend class administrator;
	friend class student;
	friend class course;
    private:
    public:
	   friend int choose(int i);
	   friend int choice(int j);
	   void log_type();
	   void student_menu(student);
	   void administrator_menu();
	   ~menu()
	   {}
};

#endif 