/* menu.cpp */
/* 菜单类的定义 */ 

#include "course.h"
#include "menu.h" 
#include "student.h"
#include "administrator.h"

void menu :: log_type()
{
	system("cls");
	int c = 0;
	cout << "****************************************************" << endl;
	cout << "*    WELCOME TO XJTLU STUDENT MANAGEMENT SYSTEM    *" << endl;
	cout << "*                    Group 57                      *" << endl;
	cout << "*           Please choose your identity            *" << endl;
	cout << "*                                                  *" << endl;
	cout << "*                 1-Administrator                  *" << endl;
	cout << "*                 2-Student                        *" << endl;
	cout << "*                 3-Quit                           *" << endl;
	cout << "*                                                  *" << endl;
	cout << "****************************************************\n" << endl;
	switch (choose(c))
	{
	case 1:{
		    administrator term1;
		    cout << "Please enter administrator account " << endl;	       
	        int d = 0;
	        do
        	{
		    string accout=str_Input();
		      if(accout == term1.name_AD)
		      {
		      	  cout << "find this account" << endl;
			      d = 1;
		      }
		      else
		      {
			      cout << "can't find this account" << endl;
				  system("pause");
			      menu :: log_type();
		      }
	        }
	         while(d = 0);

	      cout << "Please enter the password" << endl;
	      string password_ac=str_Input();
	     if(password_ac == term1.password_AD)
	      {
		     cout << "log in......." << endl;
	      }
	      else
	      {
		      cout << "enter error!" << endl;
			  system("pause");
		      menu :: log_type();
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

	case 3:
		{
			cout << "system is ending......" << endl;
			exit(0);
		}

	default:
		{
			cout << "please check your input information!" << endl;
			system("pause");
			menu :: log_type();
		}
	}
}

void menu ::administrator_menu()
{
	system("cls");
	int c = 0;
	cout << "****************************************************" << endl;
	cout << "*        Welcome to Administrator interface        *" << endl;
	cout << "*                                                  *" << endl;
	cout << "*               1-Add student                      *" << endl;
	cout << "*               2-Delete student                   *" << endl;
	cout << "*               3-Edit student                     *" << endl;
	cout << "*               4-Browse student information       *" << endl;
	cout << "*               5-Add course                       *" << endl;
	cout << "*               6-Delete course                    *" << endl;
	cout << "*               7-Edit course                      *" << endl;
	cout << "*               8-Browse course information        *" << endl;
	cout << "*               9-Return to previous menu          *" << endl;
	cout << "*                                                  *" << endl;
	cout << "****************************************************\n" << endl;
	switch (choose(c))
	{
		//*************************************************************************************
			case 1:
				{
					system("cls");
					cout << "****************************************************" << endl;
					cout << "*                 Add student                      *" << endl;
					cout << "****************************************************\n" << endl;
					student xx;
					xx.input_inf();
					xx.student_Add();
					xx.output_inf();
					break;
				}
//******************************************************************************

			case 2:
				{
					system("cls");
					cout << "****************************************************" << endl;
					cout << "*                 Delete student                   *" << endl;
					cout << "****************************************************\n" << endl;
					student xx;
					xx.input_inf();
					xx.student_Delete();
					xx.output_inf();
					break;
				}

//*********************************************************************************************
			case 3:
				{
					system("cls");
					cout << "****************************************************" << endl;
					cout << "*                 Edit student                     *" << endl;
					cout << "****************************************************\n" << endl;
					student xx;
					xx.input_inf();
					xx.student_Edit();
					xx.output_inf();
					break;
				}

//****************************************************************************************
			case 4:
				{
					system("cls");
					cout << "****************************************************" << endl;
					cout << "*               Browse student information         *" << endl;
					cout << "****************************************************\n" << endl;
					student xx;
					xx.input_inf();
					xx.student_Browse();
					xx.output_inf();
					break;
				}
//*******************************************************************************************************

			case 5:
				{
					system("cls");
					cout << "****************************************************" << endl;
					cout << "*                   Add course                     *" << endl;
					cout << "****************************************************\n" << endl;
					course xx;
					xx.input_course();
					xx.course_Add();
					xx.output_course();
					break;
				}
//******************************************************************************

			case 6:
				{
					system("cls");
					cout << "****************************************************" << endl;
					cout << "*                   Delete course                  *" << endl;
					cout << "****************************************************\n" << endl;
					course xx;
					xx.input_course();
					xx.course_Delete();
					xx.output_course();
					break;
				}

//*********************************************************************************************
			case 7:
				{
					system("cls");
					cout << "****************************************************" << endl;
					cout << "*                   Edit course                    *" << endl;
					cout << "****************************************************\n" << endl;
					course xx;
					xx.input_course();
					xx.course_Edit();
					xx.output_course();
					break;
				}

//****************************************************************************************
			case 8:
				{
					system("cls");
					cout << "****************************************************" << endl;
					cout << "*              Browse course information           *" << endl;
					cout << "****************************************************\n" << endl;
					course xx;
					xx.input_course();
					xx.course_Browse();
					xx.output_course();
					break;
				}

//****************************************************************************************
			case 9:
				{
			        cout << "system is backing......" << endl;
			        system("pause");
			        menu :: log_type();
		        }
//****************************************************************************************

	        default:
		        {
			        cout << "please check your input information!" << endl;
		        }

    }
	cout << "System is backing...." << endl;
	system("pause");
    menu ::administrator_menu();
}


void menu :: student_menu(student stu)
{
	system("cls");
	int d = 0;
	cout << "****************************************************" << endl;
	cout << "*           Welcome to Student interface           *" << endl;
	cout << "*                                                  *" << endl;
	cout << "*           1-show student own information         *" << endl;
	cout << "*           2-course browse                        *" << endl;
	cout << "*           3-course select                        *" << endl;
	cout << "*           4-Return to previous menu              *" << endl;
	cout << "*                                                  *" << endl;
	cout << "****************************************************\n" << endl;
	switch(choose(d))
	{
	case 1:
		{
			system("cls");
			cout << "****************************************************" << endl;
			cout << "*          show student own information            *" << endl;
			cout << "****************************************************\n" << endl;
			stu.itself_inf();
			break;
		}
	case 2:
		{
			system("cls");
			cout << "****************************************************" << endl;
			cout << "*                 course browse                    *" << endl;
			cout << "****************************************************\n" << endl;
			course xx;
			xx.input_course();
			xx.course_Browse();
			xx.output_course();
			break;
		}
	case 3:
		{
			system("cls");
			cout << "****************************************************" << endl;
			cout << "*                 course select                    *" << endl;
			cout << "****************************************************\n" << endl;

			student x;
			x.input_inf();
			x.course_sel(stu);
			x.output_inf();
			break;
		}

	case 4:
		{
			cout << "system is backing......" << endl;
			        system("pause");
			        menu :: log_type();
		}

	default:
		{
			cout << "please check your input information!" << endl;
	    }

	}
	cout << "System is backing...." << endl;
	system("pause");
	menu::student_menu(stu);
}