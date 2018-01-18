/* cpp文件 */ 

/* student.cpp */
/* 学生类的定义 */


#include "student.h" 
#include "menu.h" 
#include "course.h"

using namespace std;

student :: student()
{
	 name_ST = "***";
     password_ST = "***";
	 student_ID = "***";
	 student_grade = "***";
	 student_mark = 0;
	 for(int i = 0; i < 3; i++)
		 selection_cour[i] = "***";
}

student :: student(string NAME_ST , string PASSWORD_ST , string STUDENT_ID , string STUDENT_GRADE , int STUDENT_MARK , string STUDENT_SEL1, string STUDENT_SEL2,string STUDENT_SEL3)
{
	 name_ST = NAME_ST;
     password_ST = PASSWORD_ST;
	 student_ID = STUDENT_ID;
	 student_grade = STUDENT_GRADE;
	 student_mark = STUDENT_MARK;
	 selection_cour[0] = STUDENT_SEL1;
	 selection_cour[1] = STUDENT_SEL2;
	 selection_cour[2] = STUDENT_SEL3;     
}



void student::course_sel(student stu)
{
	if(stu.student_mark<40)
	{
		cout<<"you have not pass the last exam, can not choose course"<<endl;
	}
	else
	{
	  vector<student>::iterator it=STU.begin();
	  for(;it!=STU.end();it++)
	  {
		  if(it->student_ID == stu.student_ID)
			break;
	  }
	  course xx;
	  xx.input_course();
	  cout<<"******************************************************************************"<<endl;
	  cout<<"*                                                                            *"<<endl;
	  cout<<"*      every one must choose 3 course                                        *"<<endl;
	  cout<<"*      when you choosed your course, you have to re-log to see your choice!  *"<<endl;
	  cout<<"*                                                                            *"<<endl;
	  cout<<"******************************************************************************\n"<<endl;
	  int m;
	  for(m=0;m<3;m++)
	  {
		  if(stu.selection_cour[m]=="***")
		  {
		  cout<<"you have choose "<<m<<" courses, still can choose "<<3-m<<  " course"<<endl;
		  break;
		  }
	  }
	  if(m==3)
	  {
		  cout<<"you have choose 3 courses, no more choose"<<endl;
	  }
	  else
	  {
	    string course_id;
	    for(int i=m;i<3;)
	    {
		    cout<<"Please enter the ID number of course"<<endl;
		    course_id = str_Input();
		    vector<course>::iterator counter=xx.COU.begin();
		    for(;counter!=xx.COU.end();counter++)
		    {
			    if(course_id == counter->course_ID)
				break;
		    }
		    if(counter==xx.COU.end())
		    {
			    cout<<"no found such course"<<endl;
			    cout<<"Enter again"<<endl;
			    continue;
		    }
		    else
		    {
			    int j =0;
			    for(;j<i;j++)
			    {
				    if(course_id ==it->selection_cour[j])
					break;
			    }
			    if(j!=i)
			    {
				    cout<<"such course have been choosen"<<endl;
				    continue;
			    }
			    it->selection_cour[i]=course_id;
			    i++;
			    if(i <3)
			    {
				    cout<<"1- continue choosing course"<<endl;
					cout<<"2- end now"<<endl;
				    int p = inte_Input();
				    if(p!=1)
					break;
			    }
		    }
	      }
	  }
	}
}


void student :: student_inf()
{
	cout << "Student information" << endl;
	cout << "Student name: " << name_ST << "\t"<<"student password: " <<password_ST<<"\t"<< "student ID: " << student_ID << "\t" << "student grade: " << "\t" << student_grade << "\t" << "student mark: " <<student_mark<<endl;
	cout << endl;
}


void student::itself_inf()
{
	cout << "Student own information" << endl;
	cout << "Student name: " << name_ST << "\t" <<"student password: " <<password_ST << "\t" << "student ID: " << student_ID << "\t" << "student grade: " << student_grade << "\t" << "student past mark: "<<student_mark<< "\t" <<"student choose course name: "<<selection_cour[0]<<", "<<selection_cour[1]<<", "<<selection_cour[2]<<endl;
	cout << endl;
}

student student::student_login()
{
	int i = 0;
			cout << "please enter student ID number (enter Q to quit)" << endl;
			string student_ID= str_Input();
			if(student_ID == "Q")
			{
				cout << "system is ending...." << endl;
				exit(0);
			}
			vector<student>::iterator counter;
			for(;i==0;)
			{
			for(counter=STU.begin();counter!=STU.end();counter++)
			{
				if(student_ID == counter->student_ID)
				{
					cout << endl<<"found this account"<<endl;
					break;
				}
			}
			if(counter==STU.end())
			{
				cout<<"no such ID"<<endl;
				cout << "please enter student ID number (enter Q to quit)" << endl;
				student_ID= str_Input();
				if(student_ID == "Q")
			{
				cout << "system is ending...." << endl;
				exit(0);
			}
				continue;
			}
			cout << "please enter student password" << endl;
			string student_password= str_Input();
			if(student_password!=counter->password_ST)
			{
				cout<<"Password is wrong"<<endl;
				cout << "please enter student ID number (enter Q to quit)" << endl;
				student_ID= str_Input();
				if(student_ID == "Q")
			{
				cout << "system is ending...." << endl;
				exit(0);
			}
				continue;
			}
			else
			{
				cout<<"Password is right"<<endl;
				cout<<"log in......"<<endl;
				system("pause");
				i++;
			}
			}
			student itself(counter->name_ST,counter->password_ST,counter->student_ID,counter->student_grade, counter->student_mark,counter->selection_cour[0],counter->selection_cour[1],counter->selection_cour[2]);
			return itself;
}

void student::student_Browse()
{
					cout<<"\nPlease choose which one you will browse"<<endl;
					cout<<"1-NAME, 2-ID, 3-password 4-grade, 5-ALL"<<endl;
					int n=0;
					switch(choose(n))
					{
					case 1:
						{
							cout<<"Please enter NAME"<<endl;
							string search_name = str_Input();
							vector<student>::iterator search = STU.begin();
							int w=0;
							for(; search != STU.end();search++) 
							{
								if(search_name == search->name_ST)
								{
									search->student_inf();
									w++;
								}
							}
							if(w==0)
								cout<<"no found"<<endl;
						    break;
						}
					case 2:
						{
							cout<<"Please enter ID"<<endl;
							string search_ID = str_Input();
							vector<student>::iterator search = STU.begin();
							int w=0;
							for(; search != STU.end();search++) 
							{
								if(search_ID == search->student_ID)
								{
									search->student_inf();
									w=1;
									break;
								}
							}
							if(w==0)
								cout<<"no found"<<endl;
						}
						break;					
					case 3:
						{
							cout<<"Please enter password"<<endl;
							string search_password = str_Input();
							vector<student>::iterator search = STU.begin();
							int w=0;
							for(; search !=STU.end();search++) 
							{
								if(search_password == search->password_ST)
								{
									search->student_inf();
									w++;
								}
							}
							if(w==0)
								cout<<"no found"<<endl;
						}
						break;
					case 4:
						{
							cout<<"Please enter garde"<<endl;
							string search_garde = str_Input();
							vector<student>::iterator search = STU.begin();
							int w = 0;
							for(; search != STU.end();search++) 
							{
								if(search_garde == search->student_grade)
								{
									search->student_inf();
									w++;
								}
							}
						}
						break;
					case 5:
						{
							cout<<"Show all students"<<endl;
							for(vector<student>::iterator search = STU.begin(); search != STU.end(); search++) 
							{ 
								search->student_inf();
							}
						}
						break;

					default:
					    {
							cout <<"please check your input information" << endl;
						}

					}
}

void student::student_Edit()
{
	                cout << "At present, here are existed student accounts \n" << endl;
					for(vector<student>::iterator it = STU.begin(); it != STU.end(); it++) 
					{ 
						cout << it->name_ST << '#'<< it->password_ST << '#'<< it->student_ID << '#' << it->student_grade << '#'<< it->student_mark << ' ' << it->student_mark<<'#'<<endl;;
					}
					cout << "\nplease enter the ID number of student" << endl;
					string student_ID=str_Input();
					vector<student>::iterator counter=STU.begin();
					for(;counter!=STU.end();)
					{
						if(student_ID != counter->student_ID)
							counter++;
						else
						{
                           cout << endl<<"find the ID"<<endl;
						   counter->student_inf();
						   cout<<"Please enter your choice to edit"<<endl;
						   cout<<"1-name 2-ID, 3-password, 4-grade"<<endl;
						   int h=0;
						   switch (choose(h))
						   {
						   case 1:
							   cout<<"Please enter new name"<<endl;
							   counter->name_ST = str_Input();
							   break;
						   case 2:
							   {
							   cout<<"Please enter new ID"<<endl;
							    string new_ID = str_Input();
							   vector<student>::iterator m = STU.begin();
							   for(; m != STU.end(); ) 
							   { 
								   if(new_ID != m->student_ID)
									   m++;
								   else
								   {
									   cout<<"Such ID exist, enter again"<<endl;
									   new_ID = str_Input();
									   counter == STU.begin();
								   }
							   }							  
							   counter->student_ID = new_ID;
							   }
							   break;
						   case 3:
							   cout<<"Please enter new password"<<endl;
							   counter->password_ST = str_Input();
							   break;
						   case 4:
							   cout<<"Please enter new grade"<<endl;
							   counter->student_grade= str_Input();
							   break;
						  default:
					          {
							     cout <<"please check your input information" << endl;
						      }
						   }
						   break;
						   cout << "After editing, here are existed student accounts \n" << endl;
						   for(vector<student>::iterator it = STU.begin(); it != STU.end(); it++) 
					          { 
						         cout << it->name_ST << '#'<< it->password_ST << '#'<< it->student_ID << '#' << it->student_grade << '#'<< it->student_mark << ' ' << it->student_mark<<'#'<<endl;;
					          }
						}
					}
					if(counter == STU.end())
					{
						cout<<"no found such ID"<<endl;
					}
					
}

void student::student_Delete()
{
	                cout << "At present, here are existed student accounts \n" << endl;
					for(vector<student>::iterator it = STU.begin(); it != STU.end(); it++) 
					{ 
						cout << it->name_ST << '#'<< it->password_ST << '#'<< it->student_ID << '#' << it->student_grade << '#'<< it->student_mark << ' ' << it->student_mark<<'#'<<endl;;
					}
					cout << "\nplease enter the ID number of student" << endl;
					string student_ID=str_Input();
					vector<student>::iterator counter=STU.begin();
					for(;counter!=STU.end();counter++)
					{
						if(student_ID == counter->student_ID)
						   break;
					}
					if(counter==STU.end())
						cout<<"No found such ID"<<endl;
					else
					{
						cout << endl<<"find the ID"<<endl;
						counter->student_inf();
						STU.erase(counter);
						cout << "After editing, here are existed student accounts \n" << endl;
						for(vector<student>::iterator it = STU.begin(); it != STU.end(); it++) 
					{ 
						cout << it->name_ST << '#'<< it->password_ST << '#'<< it->student_ID << '#' << it->student_grade << '#'<< it->student_mark << ' ' << it->student_mark<<'#'<<endl;;
					}
					}		
}

void student::student_Add()
{
	                cout << "At present, here are existed student accounts \n" << endl;
					for(vector<student>::iterator it = STU.begin(); it != STU.end(); it++) 
					{ 
						cout << it->name_ST << '#'<< it->password_ST << '#'<< it->student_ID << '#' << it->student_grade << '#'<< it->student_mark << ' ' << it->student_mark<<'#'<<endl;;
					}
					cout << "\nplease enter the ID number of student" << endl;
					string student_ID=str_Input();
					for(vector<student>::iterator counter=STU.begin();counter!=STU.end();)
					{
						if(student_ID != counter->student_ID)
							counter++;
						else
						{
							cout << endl<<"Such student ID number has existed, please enter a new:"<<endl;
                            student_ID = str_Input();
						    counter = STU.begin();
						}
					}
					cout << "please enter the password of student" << endl;
					string student_password=str_Input();
					cout << "please enter the accout of student" << endl;
					string student_accout=str_Input();
					cout << "please enter the grade of this student" << endl;
					string student_grade=str_Input();
					cout << "please enter the past mark of this student(if past mark < 40 this student can't select new course)" << endl;
					int student_mark=inte_Input();
					student h(student_accout,student_password,student_ID,student_grade,student_mark );
					STU.push_back(h);
}

 

void student :: input_inf()
{
ofstream ostufile("student_data.txt",ios::app);
ostufile.close();
ifstream istufile("student_data.txt");
if(istufile.fail()) 
{ 
cout << "can not open file, exit" << endl;
exit(0); 
} 
vector<student> ::iterator h = STU.begin();
char c[100]; 

student stu; 
while(istufile.peek()!=EOF)
{
istufile.getline(c,100,'#'); 
stu.name_ST = c;
istufile.getline(c,100,'#');
stu.password_ST = c; 
istufile.getline(c,100,'#');
stu.student_ID = c;
istufile.getline(c,100,'#'); 
stu.student_grade= c;
istufile >> stu.student_mark;
istufile.ignore(1,'\n');   //
for(int i = 0; i < 3; i++)
{
istufile.getline(c,100,'#');
stu.selection_cour[i] = c;
}
istufile.ignore(100,'\n');
STU.push_back(stu);
}
istufile.close();
cout<<endl<<"file is read successfully"<<endl;
}



void student :: output_inf()
{
	ofstream ostufile("student_data.txt");
    if(ostufile.fail()) 
    { 
		cout << "Can not open file!" << endl;
		exit(0);
	} 
	for(vector<student>::iterator it = STU.begin(); it != STU.end(); it++) 
	{ 
		student stu = *it; 
		ostufile << stu.name_ST << '#'<< stu.password_ST << '#'<< stu.student_ID << '#' << stu.student_grade << '#'<< stu.student_mark <<' '<< stu.selection_cour[0]<<'#'<<stu.selection_cour[1]<<'#'<<stu.selection_cour[2]<<'#'<<endl;
	}
	ostufile.close();
	cout << endl<<"file is saved successful!"<<endl; 
}
