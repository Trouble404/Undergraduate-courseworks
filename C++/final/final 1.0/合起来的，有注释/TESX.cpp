//�����ȱ�ɾ��д����Ŀ��Կ���

#include <iostream>
#include <string>
#include <fstream>
#include <vector>   //�ļ������ݶ���vector���vector���޸ģ���д���ļ�
#include <cstring>

using namespace std;

//*****************************************************************
int choose(int i)     //ѡ�񣬼ӵ㱣����ʩ
{
	int choose;
	cout << "please choose function" << endl;
	cin >> choose;
	cin.sync();
	return choose;
}

string str_Input()   //�ַ������룬�ӵ㱣����ʩ
{
	string a;
	getline(cin,a); //getline can input string with space, for example: 123 123  string�Ƕ����ո�ͻ�ֹͣ�ģ���������getline(cin,a)��������ո񣬱��磺�������� ����������stringֻ�ܶ�������������getline��cin,a�����Զ����������� ��������
		for(;a=="\0";) //avoid read NUll character ��ֹ�ո����룬��Ϊ����getline��cin,a��������㰴�س�����Ҳ�ܶ���
		getline(cin,a);
	return a;
}
int inte_Input()    //�������룬�ӵ㱣����ʩ
{
	int b;
	cin>>b;
	cin.sync();
	return b;
}
//************************************************************************************


//***********************  class    course *********************************

class course
{
	//��Ե����
	friend class menu;
	friend class adminstrator;
	friend class student;
private:
	   string course_name;
	   string course_ID;
	   string course_teacher;
public:
	   vector<course> COU;   //vector,������Ϣ
	   course();
	   void set_course(string COURSE_NAME , string COURSE_ID , string COURSE_TEACHER);  //��������õ�
	   void course_inf();      //��ʾ�γ���Ϣ
	   void input_course();    //��ȡ�ļ���Ϣ��д��vector��
	   void output_course();   //��vector�����������д���ļ�
	   void course_Add();      //��ӿγ�
	   void course_Delete();   //ɾ��
	   void course_Edit();     //�༭��������γ̱�ţ��ٸ���
	   void course_Browse();   //�����ѡ�񰴱�ţ��γ�������ʦ���
	   ~course()
	   {}
};


//����һ���뷨������ļ���ʲô��û�У��ǲ���Ӧ������ʲô

void course::course_Add()  //Ҫ�󣺱�ź�ID����ʹ��ͬ��
{
					for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++)                              //��ɾ������۲�
					{ 
						cout << it->course_name << '#'<< it->course_ID << '#'<< it->course_teacher<< '#'<<endl;
					}
					cout << "please enter the ID number of course" << endl;
					string COURSE_ID = str_Input(); //����γ���
					for(vector<course>::iterator counter=COU.begin();counter!=COU.end();)   //vector���������÷�http://blog.csdn.net/zhy_cheng/article/details/8041940
					{
						if(COURSE_ID != counter->course_ID)  //ֱ��������vector�����ȫ��ͬ�Ž�����һ��
							counter++;
						else         // �ҵ���ͬ�ģ�Ҫ����������
						{
							cout << endl<<"Such course ID number has existed, please enter a new:"<<endl;
                            COURSE_ID = str_Input();
						    counter = COU.begin();
						}
					}
					cout << "please enter the name of student" << endl;
					string COURSE_NAME = str_Input();  //��������
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
					string COURSE_TEACHER=str_Input();  //������ʦ
					course h;
					h.set_course(COURSE_NAME,COURSE_ID,COURSE_TEACHER);
					COU.push_back(h);  //��vector COUĩβ���� �� h
					for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++)                              //��ɾ������۲�
					{ 
						cout << it->course_name << '#'<< it->course_ID << '#'<< it->course_teacher<< '#'<<endl;
					}
}

void course::course_Delete() //
{
                    for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++)                              //��ɾ������۲�
					{ 
						cout << it->course_name << '#'<< it->course_ID << '#'<< it->course_teacher<< '#'<<endl;
					}
					cout << "please enter the ID number of course you will delete" << endl;
					string COURSE_ID=str_Input();
					vector<course>::iterator counter=COU.begin();//������
					for(;counter!=COU.end();counter++)
					{
						if(COURSE_ID == counter->course_ID)//�ҵ���ͬIDʱ�˳�ѭ��
						   break;
					}
					if(counter==COU.end()) //���ȫ����꣬û��
						cout<<"No found such ID"<<endl;
					else //��ǰ�˳�
					{
						cout << endl<<"find the ID"<<endl;
						counter->course_inf();//��ʾҪ��ɾ������Ϣ
						COU.erase(counter);  //ɾ����Ϣ�� erase��������ɾ������������ָ�룬�����ǵ�������˵��������Լ��ٶ�����
					}
                    for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++)                              //��ɾ������۲�
					{ 
						cout << it->course_name << '#'<< it->course_ID << '#'<< it->course_teacher<< '#'<<endl;
					}
}

void course::course_Edit()  //�༭
{
					for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++)                              //��ɾ������۲�
					{ 
						cout << it->course_name << '#'<< it->course_ID << '#'<< it->course_teacher<< '#'<<endl;
					}
					cout << "please enter the ID number of course" << endl; // ����������ID���ҵ��󣬶��Ǹ������޸�
					string COURSE_ID = str_Input();
					vector<course>::iterator counter=COU.begin();
					for(;counter!=COU.end();)
					{
						if(COURSE_ID != counter->course_ID) //���û�ҵ���������
							counter++;
						else   //�ҵ��ˣ��ͱ༭
						{
                           cout << endl<<"find the ID"<<endl;
						   counter->course_inf();
						   cout<<"Please enter your choice to edit"<<endl; //ѡ����ô�༭
						   cout<<"1-name 2-ID, 3-teacher"<<endl;
						   int h = 0;
						   switch (choose(h))  //ʵ���ǲ����Ŀ¼ȥ���ˣ�%>_<%�����������
						   {
						   case 1:
							   {
							   cout<<"Please enter new name"<<endl;  //�޸�����,���ֲ����ظ�
							   string new_name = str_Input();
							   vector<course>::iterator m = COU.begin();
							   for(; m != COU.end(); ) 
							   { 
								   if(new_name != m->course_name)
									   m++;
								   else
								   {
									   cout<<"Such name exist, enter again"<<endl;
									   new_name = str_Input();
									   counter == COU.begin();
								   }
							   }							  
							   counter->course_name = new_name;
							   }
							
							   break;
						   case 2:
							   {
							   cout<<"Please enter new ID"<<endl;   //��Ų����ظ�
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
							   }
							   break;
						   case 3:
							   cout<<"Please enter new teacher"<<endl;
							   counter->course_teacher = str_Input();
							   break;
						   }
						   break;
						}
					}
					if(counter == COU.end())   //û���ҵ�
						cout<<endl<<"no found such ID"<<endl;
					for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++)                              //��ɾ������۲�
					{ 
						cout << it->course_name << '#'<< it->course_ID << '#'<< it->course_teacher<< '#'<<endl;
					}
}

void course::course_Browse()
{
					for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++)                              //��ɾ������۲�
					{ 
						cout << it->course_name << '#'<< it->course_ID << '#'<< it->course_teacher<< '#'<<endl;
					}
					cout<<"Please choose which one you will browse"<<endl; //�����4�����
					cout<<"1-NAME, 2-ID, 3-teacher, 4-ALL"<<endl;
					int n=0;
					switch(choose(n))   //�𲻲�%>_<%
					{
					case 1:
						{
							cout<<"Please enter NAME of course"<<endl;   //�������������Ψһ
							string search_name = str_Input();
							vector<course>::iterator search = COU.begin();  //������������֣��ҵ��ˣ���ʾ�Ǹ�vector���Ǹ�λ�ӵ���������
							int w=0;  //�ж���û�ҵ�
							for(; search != COU.end();search++) 
							{
								if(search_name == search->course_name)
								{
									search->course_inf();
									w=1;  //�ҵ���
									break;  //��ΪΨһ�����Կ���break
								}
							}
							if(w==0)//û�ҵ�
								cout<<"no found"<<endl;
						    break;
						}
					case 2:                                 //����ID�����Ψһ
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
					case 3:   //������ʦ��������Բ�ֻ1
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
									w++; //����ͬһ����ʦ�̶��ſΣ����Բ���break
								}
							}
							if(w==0)
								cout<<"no found"<<endl;
						}
						break;
					case 4:   //ȫ��
						{
							cout<<"Show all courses"<<endl;
							for(vector<course>::iterator search = COU.begin(); search != COU.end(); search++) 
							{ 
								search->course_inf();
							}
						}
						break;
					}
                    for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++) 
					{ 
						cout << it->course_name << '#'<< it->course_ID << '#'<< it->course_teacher<< '#'<<endl;
					}
}

void course :: input_course()
{
ofstream ostufile("course_data.txt",ios::app);  //�����û������ļ������ȴ�������Ϊapp��ʾ��ĩβ�����Բ����ԭ�ļ���Ӱ��
ostufile.close();       //�ص�
ifstream istufile("course_data.txt"); //�򿪶�
if(istufile.fail())  //��ʧ�ܣ��˳�
{ 
cout << "can not open file, exit" << endl;
exit(0);
} 
char c[100];  //���������ݵ�
course cour; 
while(istufile.peek()!=EOF)  //peek()�Ƚ�eof()����Ϊpeek()����ʱ�򲢲����˳����Ӱ�죬����eof�ڶ�����ʱ������ĩβ���һλ�����Թ���eof���������ǳ���������peek()�ɣ������ʶ���
{
istufile.getline(c,100,'#'); //����֮ǰ����ʹ��getline����,������Ҳ����ͬ�ģ���Ϊcin>>string �����ո�ͽ����ˣ�������ָ����100���ַ���������#�žͲ���������ȥ��
cour.course_name = c;
istufile.getline(c,100,'#');
cour.course_ID = c; 
istufile.getline(c,100,'#');
cour.course_teacher = c;
istufile.ignore(100,'\n');  //��ջ�����������Ƚ�cin.sync()�����㴦��С�Ļ�������100�ǻ������Ĵ�С���Ѻ��滺������ǰ100���ַ����ߡ�\n�����ַ�����
COU.push_back(cour);  //��vectorĩβ������cour
}
istufile.close();//�ص�
}



void course :: output_course()
{
	ofstream ostufile("course_data.txt"); //��д����֮ǰ���������
    if(ostufile.fail()) 
    { 
		cout << "Can not open file!" << endl;
		exit(0);
	} 
	for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++) 
	{ 
		course course = *it; 
		ostufile << course.course_name << '#'<< course.course_ID << '#'<< course.course_teacher << '#'<<endl; //д����ʱд��#�����������ʱ�ҵ�
	}
	ostufile.close();
	cout << "\nfile is saved successful!!!\n"; 
}



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



//***********************  class   student    *********************************

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
	   //������ֻ��ѧ���Լ��ܿ�������ʦ�����Ҹ�
	   int student_mark; //��ȥ�ķ��������룬���Ӧ���������������ҿ��ˣ��Ͳ���ѡ����
	   string selection_cour[3]; //student can choose 3 courses 3�ſ����
   public:
	   vector<student> STU;
	   student();
	   student(string NAME_ST , string PASSWORD_ST , string STUDENT_ID , string STUDENT_GRADE , int STUDENT_MARK, string selection_cour1="***", string selection_cour2="***", string selection_cour3="***");//Ĭ�ϲ��������û������Ĭ��Ϊ***,***����ѡ��ʱ���õ�����ʾ��δ��ѡ��
	 
	   student student_login(); 

	   void student_Add();  //���Ƶ�course
	   void student_Delete();
	   void student_Browse();
	   void student_Edit();
	  
	   void student_inf(); //����Ա�ܿ�����
	   void itself_inf(); //ѧ���Լ��ܿ����ģ���ȥ�ķ�����ѡ�ĿΣ�

	   void input_inf(); //
	   void output_inf();

	   void course_sel(student stu); //ѡ��
	   ~student()
	   {}
};

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



student student::student_login()  //ѧ������ϵͳ ������󷵻���student ��ʾ���Լ������������ʾ�Լ���Ϣ��ѡ�ε�
{
	int i = 0;
			cout << "please enter student ID number" << endl;
			string student_ID= str_Input();//���˺�
			vector<student>::iterator counter;
			for(;i==0;)    //ѭ����û���ҵ�ID���������뽫�������롣 �ɹ��ˣ����˳�ѭ��
			{
			for(counter=STU.begin();counter!=STU.end();counter++)
			{
				if(student_ID == counter->student_ID)//�ҵ���ͬ��
				{
					cout << endl<<"found"<<endl;
					break;
				}
			}
			if(counter==STU.end())  //���ǵ�ĩβ��˵��û�ҵ�
			{
				cout<<"no such ID"<<endl;
				cout << "please enter student ID number" << endl;
				student_ID= str_Input();
				continue;  //�ص�ѭ��
			}
			cout << "please enter student password" << endl;
			string student_password= str_Input();  //������
			if(student_password!=counter->password_ST) //�������
			{
				cout<<"Password is wrong"<<endl; 
				cout << "please enter student ID number" << endl;
				student_ID= str_Input(); //�ص�ѭ��
				continue;
			}
			else
			{
				cout<<"Password is right"<<endl;
				i++;  //��ȷ i�仯���˳�ѭ��
			}
			}
			student itself(counter->name_ST,counter->password_ST,counter->student_ID,counter->student_grade, counter->student_mark,counter->selection_cour[0],counter->selection_cour[1],counter->selection_cour[2]); //��¼��ʱ���student����Ϣ
			return itself;
}


void student::course_sel(student stu) //ѡ�Σ�stu���Ե���ϵͳ
{
	if(stu.student_mark<40)  //�������ҿ��ˣ�������ѡ��
			{
				cout<<"you have not pass the last exam, can not choose course"<<endl;
				exit(1);
			}

			vector<student>::iterator it=STU.begin();
			for(;it!=STU.end();it++)
			{
				if(it->student_ID == stu.student_ID)   //���ҵ���ͬ��ID��ȷ����ʱλ����VECTOR
					break;
			}
			course xx;
			xx.input_course();
			cout<<"every one can choose 3 course"<<endl;
			int m;//m��ʾ�ѿ�ѡ�γ�
			for(m=0;m<3;m++)
			{
				if(stu.selection_cour[m]=="***") //***��ʾ��û��ѡ
				{
				cout<<"you have choose "<<m<<" courses, still can choose "<<3-m<<  " course"<<endl;
				break;
				}
			}
			if(m==3)//
			{
				cout<<"you have choose 3 courses, no more choose"<<endl;
				exit(1);  //��������ˣ���ֱ���˳�
			}
			string course_id;  //��ʾ�����courseID
			for(int i=m;i<3;) //��ʣ�µ�δѡ�γ̽���ѡ��
			{
			cout<<"Please enter the ID number of course"<<endl;
			course_id = str_Input();
			vector<course>::iterator counter=xx.COU.begin();
			for(;counter!=xx.COU.end();counter++)
			{
				if(course_id == counter->course_ID)//��course���ҵ���Ҫѡ�ĵĿ�
					break;
			}
			if(counter==xx.COU.end())  //û���ҵ����ſΣ�����������course����
			{
				cout<<"no found such course"<<endl;
				cout<<"Enter again"<<endl;
				continue;
			}
			else
			{
				int j =0;
				for(;j<i;j++) //����ѡ�ν����ж�
				{
					if(course_id ==it->selection_cour[j]) 
						break;
				}
				if(j!=i)  //������������Ѿ���ѡȡ�ˣ���������
				{
					cout<<"such course have been choosen"<<endl;
					continue;
				}
			it->selection_cour[i]=course_id;
			i++;  //�γ̼� 1
			if(i <3)
			{
			cout<<"Please enter 1 to choose course ,2 to quit?"<<endl; //ÿ�����һ�ſΣ��������һ�ţ���ѯ���Ƿ��ټ���ѡ�Σ���ѡ���˳��˺���
				int p = inte_Input();
			if(p!=1)
				break;
			}
			}
			}
}
void student :: student_inf()//��ʾ��Ϣ������Ա��
{
	cout << "Student information" << endl;
	cout << "Student name: " << name_ST << "\t"<<"student password" <<password_ST<< "student ID: " << student_ID << "\t" << "student grade: " <<"\t"<< student_grade <<"student mark"<<student_mark<<endl;
	cout << endl;
}

void student::itself_inf() //��ʾ������Ϣ
{
	cout << "Student own information" << endl;
	cout << "Student name: " << name_ST << "\t"<<"student password" <<password_ST<< "student ID: " << student_ID << "\t" << "student grade: " << student_grade <<"\t"<< "student past mark"<<student_mark<<"\t"<<"student choose course name"<<selection_cour[0]<<", "<<selection_cour[1]<<", "<<selection_cour[2]<<endl;
	cout << endl;
}

//�����course���Ƶģ����ི�ˣ������پ���ĳЩ�ط�
//ֻ��ID�ǲ����ظ���
void student::student_Browse()
{
					for(vector<student>::iterator it = STU.begin(); it != STU.end(); it++) 
					{ 
						cout << it->name_ST << '#'<< it->password_ST << '#'<< it->student_ID << '#' << it->student_grade << '#'<< it->student_mark << ' ' << it->student_mark<<'#'<<endl;;
					}
					cout<<"Please choose which one you will browse"<<endl;
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
								if(search_garde != search->student_grade)
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
					}
					for(vector<student>::iterator it = STU.begin(); it != STU.end(); it++) 
					{ 
						cout << it->name_ST << '#'<< it->password_ST << '#'<< it->student_ID << '#' << it->student_grade << '#'<< it->student_mark << ' ' << it->student_mark<<'#'<<endl;;
					}
}

void student::student_Edit()
{
					for(vector<student>::iterator it = STU.begin(); it != STU.end(); it++) 
					{ 
						cout << it->name_ST << '#'<< it->password_ST << '#'<< it->student_ID << '#' << it->student_grade << '#'<< it->student_mark << ' ' << it->student_mark<<'#'<<endl;;
					}
					cout << "please enter the ID number of student" << endl;
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
						   }
						   break;
						}
					}
					if(counter == STU.end())
						cout<<"no found such ID"<<endl;
					for(vector<student>::iterator it = STU.begin(); it != STU.end(); it++) 
					{ 
						cout << it->name_ST << '#'<< it->password_ST << '#'<< it->student_ID << '#' << it->student_grade << '#'<< it->student_mark << ' ' << it->student_mark<<'#'<<endl;;
					}
}
void student::student_Delete()
{
					for(vector<student>::iterator it = STU.begin(); it != STU.end(); it++) 
					{ 
						cout << it->name_ST << '#'<< it->password_ST << '#'<< it->student_ID << '#' << it->student_grade << '#'<< it->student_mark << ' ' << it->student_mark<<'#'<<endl;;
					}
					cout << "please enter the ID number of student" << endl;
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
					}
					for(vector<student>::iterator it = STU.begin(); it != STU.end(); it++) 
					{ 
						cout << it->name_ST << '#'<< it->password_ST << '#'<< it->student_ID << '#' << it->student_grade << '#'<< it->student_mark << ' ' << it->student_mark<<'#'<<endl;;
					}
}

void student::student_Add()
{
					for(vector<student>::iterator it = STU.begin(); it != STU.end(); it++) 
					{ 
						cout << it->name_ST << '#'<< it->password_ST << '#'<< it->student_ID << '#' << it->student_grade << '#'<< it->student_mark << ' ' << it->student_mark<<'#'<<endl;;
					}
					cout << "please enter the ID number of student" << endl;
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
					cout << "please enter the past mark of this student" << endl;
					int student_mark=inte_Input();
					student h(student_accout,student_password,student_ID,student_grade,student_mark );
					STU.push_back(h);
					for(vector<student>::iterator it = STU.begin(); it != STU.end(); it++) 
					{ 
						cout << it->name_ST << '#'<< it->password_ST << '#'<< it->student_ID << '#' << it->student_grade << '#'<< it->student_mark << ' ' << it->student_mark<<'#'<<endl;;
					}
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
istufile.ignore(1,'\n');   //����Ҫȥ��һ���ַ�������������Դ���ļ���Ŀո���Ϊ����mark�⣬���඼���ַ�������#������ʾ��β��������ֹ������mark��int���͵ģ�����ֱ�Ӷ�ȡ�����ü�#��������д���ļ��п��Կ�����ֻ����һ��' '�ո񣬴�����#�����������ʱ������ո�ᱻ��һ���γ�ID����ȥ�������᲻���룬���һ�ո�Խ��Խ�࣬��������Ҫɾ��һ��������
for(int i = 0; i < 3; i++) //����3���γ̵�ID
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
		ostufile << stu.name_ST << '#'<< stu.password_ST << '#'<< stu.student_ID << '#' << stu.student_grade << '#'<< stu.student_mark <<' '<< stu.selection_cour[0]<<'#'<<stu.selection_cour[1]<<'#'<<stu.selection_cour[2]<<'#'<<endl; //�����Ǹ��ո���û��
	}
	ostufile.close();
	cout << endl<<"file is saved successful!"<<endl; 
}




//***********************  class     administrator *********************************

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

administrator :: administrator() //�˻�����
{
	name_AD = "1";
    password_AD = "1";
}

////***********************  class     menu *********************************

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
	   void student_menu(student); //2���˵�������Ա��ѧ��
	   void administrator_menu();
	   ~menu()
	   {}
};


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
		    administrator term1;        //��������˸��ˣ�����˰�
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

void menu ::administrator_menu()  //8���������ټӸ��˳���
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
	cout<<"1-return to log menu, 2-return to Administrator menu 3-quit"<<endl;  //����ʱѯ�ʷ����Ǹ��˵�
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



int main()
{ 
menu menu;
menu.log_type(); 
return 0; 

} 