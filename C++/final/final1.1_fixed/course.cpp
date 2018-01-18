/* course.cpp */
/* 课程类的定义 */


#include "course.h" 
#include "menu.h" 

course :: course()
{
	course_name = "***";
	course_ID = "***";
	course_teacher = "***";
}

void course :: set_course(string COURSE_NAME , string COURSE_ID , string COURSE_TEACHER)
{
	course_name = COURSE_NAME;
	course_ID = COURSE_ID;
	course_teacher = COURSE_TEACHER;
}

void course :: course_inf()
{
	cout << "Course information" << endl;
	cout << "Course name: " << course_name << "\t" << "Course ID: " << course_ID << "\t" << "Course teacher: " << course_teacher << endl;
	cout << endl;
}



void course::course_Add()
{                   
	                cout << "At present, here are existed coureses \n" << endl;
	                for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++) 
					{ 
						cout << it->course_name << '#'<< it->course_ID << '#'<< it->course_teacher<< '#'<<endl;
					}
					cout <<"\nplease enter the ID number of course" << endl;
					string COURSE_ID = str_Input();
					for(vector<course>::iterator counter=COU.begin();counter!=COU.end();)
					{
						if(COURSE_ID != counter->course_ID)
							counter++;
						else
						{
							cout << endl<<"Such course ID number has existed, please enter a new one:"<<endl;
                            COURSE_ID = str_Input();
						    counter = COU.begin();
						}
					}
					cout << "please enter the name of course" << endl;
					string COURSE_NAME = str_Input();
					for(vector<course>::iterator counter=COU.begin();counter!=COU.end();)
					{
						if(COURSE_NAME != counter->course_name)
							counter++;
						else
						{
							cout << endl<<"Such course name has existed, please enter a new:"<<endl;
                            COURSE_NAME = str_Input();
						    counter = COU.begin();
						}
					}
					cout << "please enter the teacher of course" << endl;
					string COURSE_TEACHER=str_Input();
					course h;
					h.set_course(COURSE_NAME,COURSE_ID,COURSE_TEACHER);
					COU.push_back(h);
}

void course::course_Delete()
{
	                cout <<"At present, here are existed coureses \n" << endl;
	                for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++) 
					{ 
						cout << it->course_name << '#'<< it->course_ID << '#'<< it->course_teacher<< '#'<<endl;
					}
					cout << "\nplease enter the ID number of course which you will delete" << endl;
					string COURSE_ID=str_Input();
					vector<course>::iterator counter=COU.begin();
					for(;counter!=COU.end();counter++)
					{
						if(COURSE_ID == counter->course_ID)
						   break;
					}
					if(counter==COU.end())
						cout<<"No found such ID"<<endl;
					else
					{
						cout << endl<<"find the ID"<<endl;
						counter->course_inf();
						COU.erase(counter);

					    cout << "After deleting, here are existed coureses \n" << endl;
					    for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++) 
					    { 
						    cout << it->course_name << '#'<< it->course_ID << '#'<< it->course_teacher<< '#'<<endl;
					    }
					}
}

void course::course_Edit()
{
	                cout <<"At present, here are existed coureses \n" << endl;
	                for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++) 
					{ 
						cout << it->course_name << '#'<< it->course_ID << '#'<< it->course_teacher<< '#'<<endl;
					}
					cout << "\nplease enter the ID number of course" << endl;
					string COURSE_ID = str_Input();
					vector<course>::iterator counter=COU.begin();
					for(;counter!=COU.end();)
					{
						if(COURSE_ID != counter->course_ID)
							counter++;
						else
						{
                           cout << endl<<"find the ID"<<endl;
						   counter->course_inf();
						   cout<<"Please enter your choice to edit"<<endl;
						   cout<<"1-name 2-ID, 3-teacher"<<endl;
						   int h = 0;
						   switch (choose(h))
						   {
						   case 1:
							   {
							   cout<<"Please enter new name"<<endl;
							   counter->course_name = str_Input();
							   break;
							   }
						   case 2:
							   {
							   cout<<"Please enter new ID"<<endl;
							    string new_ID = str_Input();
							   vector<course>::iterator m = COU.begin();
							   for(; m != COU.end(); ) 
							   { 
								   if(new_ID != m->course_ID)
									   m++;
								   else
								   {
									   cout<<"Such ID exist, enter again"<<endl;
									   new_ID = str_Input();
									   counter == COU.begin();
								   }
							   }							  
							   counter->course_ID = new_ID;
							   break;
							   }
						   case 3:
							   {
							   cout<<"Please enter new teacher"<<endl;
							   counter->course_teacher = str_Input();
							   break;
							   }
						   default:
							   {
								   cout <<"please check your input information" << endl;
							   }
						   }
						   break;

						   cout << "After editing, here are existed coureses \n" << endl;
					       for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++) 
					      { 
						    cout << it->course_name << '#'<< it->course_ID << '#'<< it->course_teacher<< '#'<<endl;
					      }
					   }
					}
					if(counter == COU.end())
					{
						cout<<"no found such ID"<<endl;
					}				
}

void course::course_Browse()
{
					cout<<"Please choose which one you will browse"<<endl;
					cout<<"1-NAME, 2-ID, 3-teacher, 4-ALL"<<endl;
					int n=0;
					switch(choose(n))
					{
					case 1:
						{
							cout<<"Please enter NAME of course"<<endl;
							string search_name = str_Input();
							vector<course>::iterator search = COU.begin();
							int w=0;
							for(; search != COU.end();search++) 
							{
								if(search_name == search->course_name)
								{
									search->course_inf();
									w=1;
									break;
								}
							}
							if(w==0)
								cout<<"no found"<<endl;
						    break;
						}
					case 2:
						{
							cout<<"Please enter ID of course"<<endl;
							string search_ID = str_Input();
							vector<course>::iterator search = COU.begin();
							int w=0;
							for(; search != COU.end();search++) 
							{
								if(search_ID == search->course_ID)
								{
									search->course_inf();
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
							cout<<"Please enter teacher of course"<<endl;
							string search_teacher = str_Input();
							vector<course>::iterator search = COU.begin();
							int w=0;
							for(; search != COU.end();search++) 
							{
								if(search_teacher == search->course_teacher)
								{
									search->course_inf();
									w++;
								}
							}
							if(w==0)
								cout<<"no found"<<endl;
						}
						break;
					case 4:
						{
							cout<<"Show all courses"<<endl;
							for(vector<course>::iterator search = COU.begin(); search != COU.end(); search++) 
							{ 
								search->course_inf();
							}
						}
						break;

						default:
							   {
								   cout <<"please check your input information" << endl;
							   }
					}
}

void course :: input_course()
{
	ofstream ostufile("course_data.txt",ios::app);
	ostufile.close();
	ifstream istufile("course_data.txt");
	if(istufile.fail()) 
	{ 
		cout << "can not open file, exit" << endl;
		exit(0);
	} 
	vector<course> ::iterator h = COU.begin();
	char c[100]; 
	course cour; 
	while(istufile.peek()!=EOF)
	{
		istufile.getline(c,100,'#'); 
		cour.course_name = c;
		istufile.getline(c,100,'#');
		cour.course_ID = c; 
		istufile.getline(c,100,'#');
		cour.course_teacher = c;
		istufile.ignore(100,'\n');
		COU.push_back(cour);
	}
	istufile.close();
}



void course :: output_course()
{
	ofstream ostufile("course_data.txt");
    if(ostufile.fail()) 
    { 
		cout << "Can not open file!" << endl;
		exit(0);
	} 
	for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++) 
	{ 
		course course = *it; 
		ostufile << course.course_name << '#'<< course.course_ID << '#'<< course.course_teacher << '#'<<endl;
	}
	ostufile.close();
	cout << "\nfile is saved successful!!!\n"; 
}




