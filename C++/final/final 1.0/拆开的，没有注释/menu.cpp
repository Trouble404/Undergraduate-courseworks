/* menu.cpp */
/* 菜单类的定义 */ 

#include "course.h"
#include "menu.h" 
#include "student.h"
#include "administrator.h"
void menu :: log_type()
{
	int c = 0;
	cout << "Welcome!" << endl;
	cout << "Please choose type" << endl;
	cout << "1-ad" << endl;
	cout << "2-st" << endl;

	switch (choose(c))
	{
	case 1:{
		    administrator term1;
		    cout << "Please enter accout " << endl;	       
	        int d = 0;
	        do
        	{
		    string accout=str_Input();
		      if(accout == term1.name_AD)
		      {
		      	  cout << "successful" << endl;
			      d = 1;
		      }
		      else
		      {
			      cout << "error" << endl;
			      exit(0);
		      }
	        }
	         while(d = 0);

	      cout << "Please enter password" << endl;
	      string password_ac=str_Input();
	     if(password_ac == term1.password_AD)
	      {
		     cout << "successful" << endl;
	      }
	      else
	      {
		      cout << "error" << endl;
		      exit(0);
	      }
	      system("pause");
          menu ::administrator_menu(); 
		  break;
		  }

	case 2:
		{
			student user;
			user.input_inf();
			user=user.student_login();
			menu::student_menu(user);
			system("pause");
			 break;
		}
	}
}

void menu ::administrator_menu()
{
	int c = 0;
	cout << "1-Add student" << endl;
	cout << "2-Delete student" << endl;
	cout << "3-Edit student" << endl;
	cout << "4-Browse student" << endl;
	cout << "5-Add course" << endl;
	cout << "6-Delete course" << endl;
	cout << "7-Edit student" << endl;
	cout << "8-Browse student" <<endl;
	switch (choose(c))
	{
		//*************************************************************************************
			case 1:
				{
					student xx;
					xx.input_inf();
					xx.student_Add();
					xx.output_inf();
					break;
				}
//******************************************************************************

			case 2:
				{
					student xx;
					xx.input_inf();
					xx.student_Delete();
					xx.output_inf();
					break;
				}

//*********************************************************************************************
			case 3:
				{
					student xx;
					xx.input_inf();
					xx.student_Edit();
					xx.output_inf();
					break;
				}

//****************************************************************************************
			case 4:
				{
					student xx;
					xx.input_inf();
					xx.student_Browse();
					xx.output_inf();
					break;
				}
//*******************************************************************************************************

			case 5:
				{
					course xx;
					xx.input_course();
					xx.course_Add();
					xx.output_course();
					break;
				}
//******************************************************************************

			case 6:
				{
					course xx;
					xx.input_course();
					xx.course_Delete();
					xx.output_course();
					break;
				}

//*********************************************************************************************
			case 7:
				{
					course xx;
					xx.input_course();
					xx.course_Edit();
					xx.output_course();
					break;
				}

//****************************************************************************************
			case 8:
				{
					course xx;
					xx.input_course();
					xx.course_Browse();
					xx.output_course();
					break;
				}
    }
	cout<<"1-return to log menu, 2-return to Administrator menu 3-quit"<<endl;
	int s=inte_Input();
	if(s==1)
		menu::log_type();
	if(s==2)
		menu::administrator_menu();
}


void menu :: student_menu(student stu)
{
	int d = 0;
	cout << "Student menu" << endl;
	cout << "1-show student own information" << endl;
	cout << "2-course browse" << endl;
	cout << "3-course select"<<endl;
	switch(choose(d))
	{
	case 1:
		{
			stu.itself_inf();
			break;
		}
	case 2:
		{
			course xx;
			xx.input_course();
			xx.course_Browse();
			xx.output_course();
			break;
		}
	case 3:
		{
			student x;
			x.input_inf();
			x.course_sel(stu);
			x.output_inf();
			break;
		}
	}
	cout<<"1-return to log menu, 2-return to Student menu 3-quit"<<endl;
	int s=inte_Input();
	if(s==1)
		menu::log_type();
	if(s==2)
		menu::student_menu(stu);
	}