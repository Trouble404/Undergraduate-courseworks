//中文先别删，写报告的可以看看

#include <iostream>
#include <string>
#include <fstream>
#include <vector>   //文件中内容读到vector里，在vector内修改，再写入文件
#include <cstring>

using namespace std;

//*****************************************************************
int choose(int i)     //选择，加点保护措施
{
	int choose;
	cout << "please choose function" << endl;
	cin >> choose;
	cin.sync();
	return choose;
}

string str_Input()   //字符创输入，加点保护措施
{
	string a;
	getline(cin,a); //getline can input string with space, for example: 123 123  string是读到空格就会停止的，但是现在getline(cin,a)可以输入空格，比如：啊啊啊啊 啊啊啊啊，string只能读到啊啊啊啊，getline（cin,a）可以读到啊啊啊啊 啊啊啊啊
		for(;a=="\0";) //avoid read NUll character 防止空格输入，因为用了getline（cin,a），如果你按回车，他也能读入
		getline(cin,a);
	return a;
}
int inte_Input()    //整数输入，加点保护措施
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
	//有缘函数
	friend class menu;
	friend class adminstrator;
	friend class student;
private:
	   string course_name;
	   string course_ID;
	   string course_teacher;
public:
	   vector<course> COU;   //vector,贮存信息
	   course();
	   void set_course(string COURSE_NAME , string COURSE_ID , string COURSE_TEACHER);  //在添加里用到
	   void course_inf();      //显示课程信息
	   void input_course();    //读取文件信息，写入vector里
	   void output_course();   //将vector里的内容重新写入文件
	   void course_Add();      //添加课程
	   void course_Delete();   //删除
	   void course_Edit();     //编辑：先输入课程编号，再更改
	   void course_Browse();   //浏览：选择按编号，课程名，老师浏览
	   ~course()
	   {}
};


//我有一个想法，如果文件里什么对没有，是不是应该做点什么

void course::course_Add()  //要求：编号和ID不能使相同的
{
					for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++)                              //可删，方便观察
					{ 
						cout << it->course_name << '#'<< it->course_ID << '#'<< it->course_teacher<< '#'<<endl;
					}
					cout << "please enter the ID number of course" << endl;
					string COURSE_ID = str_Input(); //输入课程名
					for(vector<course>::iterator counter=COU.begin();counter!=COU.end();)   //vector迭代器：用法http://blog.csdn.net/zhy_cheng/article/details/8041940
					{
						if(COURSE_ID != counter->course_ID)  //直到输入与vector里的完全不同才进行下一步
							counter++;
						else         // 找到相同的，要求重新输入
						{
							cout << endl<<"Such course ID number has existed, please enter a new:"<<endl;
                            COURSE_ID = str_Input();
						    counter = COU.begin();
						}
					}
					cout << "please enter the name of student" << endl;
					string COURSE_NAME = str_Input();  //输入名字
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
					string COURSE_TEACHER=str_Input();  //输入老师
					course h;
					h.set_course(COURSE_NAME,COURSE_ID,COURSE_TEACHER);
					COU.push_back(h);  //在vector COU末尾加上 类 h
					for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++)                              //可删，方便观察
					{ 
						cout << it->course_name << '#'<< it->course_ID << '#'<< it->course_teacher<< '#'<<endl;
					}
}

void course::course_Delete() //
{
                    for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++)                              //可删，方便观察
					{ 
						cout << it->course_name << '#'<< it->course_ID << '#'<< it->course_teacher<< '#'<<endl;
					}
					cout << "please enter the ID number of course you will delete" << endl;
					string COURSE_ID=str_Input();
					vector<course>::iterator counter=COU.begin();//迭代器
					for(;counter!=COU.end();counter++)
					{
						if(COURSE_ID == counter->course_ID)//找到相同ID时退出循环
						   break;
					}
					if(counter==COU.end()) //如果全检查完，没有
						cout<<"No found such ID"<<endl;
					else //提前退出
					{
						cout << endl<<"find the ID"<<endl;
						counter->course_inf();//显示要被删除的信息
						COU.erase(counter);  //删除信息， erase（）用于删除，括号内是指针，这里是迭代器，说不清楚，自己百度啦。
					}
                    for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++)                              //可删，方便观察
					{ 
						cout << it->course_name << '#'<< it->course_ID << '#'<< it->course_teacher<< '#'<<endl;
					}
}

void course::course_Edit()  //编辑
{
					for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++)                              //可删，方便观察
					{ 
						cout << it->course_name << '#'<< it->course_ID << '#'<< it->course_teacher<< '#'<<endl;
					}
					cout << "please enter the ID number of course" << endl; // 还是先输入ID，找到后，对那个进行修改
					string COURSE_ID = str_Input();
					vector<course>::iterator counter=COU.begin();
					for(;counter!=COU.end();)
					{
						if(COURSE_ID != counter->course_ID) //如果没找到，继续找
							counter++;
						else   //找到了，就编辑
						{
                           cout << endl<<"find the ID"<<endl;
						   counter->course_inf();
						   cout<<"Please enter your choice to edit"<<endl; //选择怎么编辑
						   cout<<"1-name 2-ID, 3-teacher"<<endl;
						   int h = 0;
						   switch (choose(h))  //实在是不想拆到目录去额了，%>_<%，你可以试下
						   {
						   case 1:
							   {
							   cout<<"Please enter new name"<<endl;  //修改名字,名字不能重复
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
							   cout<<"Please enter new ID"<<endl;   //编号不能重复
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
					if(counter == COU.end())   //没有找到
						cout<<endl<<"no found such ID"<<endl;
					for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++)                              //可删，方便观察
					{ 
						cout << it->course_name << '#'<< it->course_ID << '#'<< it->course_teacher<< '#'<<endl;
					}
}

void course::course_Browse()
{
					for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++)                              //可删，方便观察
					{ 
						cout << it->course_name << '#'<< it->course_ID << '#'<< it->course_teacher<< '#'<<endl;
					}
					cout<<"Please choose which one you will browse"<<endl; //浏览按4总浏览
					cout<<"1-NAME, 2-ID, 3-teacher, 4-ALL"<<endl;
					int n=0;
					switch(choose(n))   //拆不拆，%>_<%
					{
					case 1:
						{
							cout<<"Please enter NAME of course"<<endl;   //输入名字浏览，唯一
							string search_name = str_Input();
							vector<course>::iterator search = COU.begin();  //找你输入的名字，找到了，显示那个vector在那个位子的所有内容
							int w=0;  //判断找没找到
							for(; search != COU.end();search++) 
							{
								if(search_name == search->course_name)
								{
									search->course_inf();
									w=1;  //找到了
									break;  //因为唯一，所以可以break
								}
							}
							if(w==0)//没找到
								cout<<"no found"<<endl;
						    break;
						}
					case 2:                                 //输入ID浏览，唯一
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
					case 3:   //输入老师浏览，可以不只1
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
									w++; //可能同一个老师教多门课，所以不能break
								}
							}
							if(w==0)
								cout<<"no found"<<endl;
						}
						break;
					case 4:   //全部
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
ofstream ostufile("course_data.txt",ios::app);  //如果并没有这个文件，就先创建，因为app表示在末尾，所以不会对原文件有影响
ostufile.close();       //关掉
ifstream istufile("course_data.txt"); //打开读
if(istufile.fail())  //打开失败，退出
{ 
cout << "can not open file, exit" << endl;
exit(0);
} 
char c[100];  //用来读内容的
course cour; 
while(istufile.peek()!=EOF)  //peek()比较eof()，因为peek()读的时候并不会对顺序有影响，但是eof在读内容时，会在末尾多读一位，我试过用eof（），老是出错。还是用peek()吧，不懂问度娘
{
istufile.getline(c,100,'#'); //由于之前输入使用getline（）,这里用也是相同的，因为cin>>string 读到空格就结束了，这里是指读到100个字符或者遇到#号就不继续读下去了
cour.course_name = c;
istufile.getline(c,100,'#');
cour.course_ID = c; 
istufile.getline(c,100,'#');
cour.course_teacher = c;
istufile.ignore(100,'\n');  //清空缓冲区，这个比较cin.sync()更方便处理小的缓冲区，100是缓冲区的大小，把后面缓冲区里前100个字符或者‘\n’的字符消除
COU.push_back(cour);  //在vector末尾加上类cour
}
istufile.close();//关掉
}



void course :: output_course()
{
	ofstream ostufile("course_data.txt"); //打开写，把之前的内容清空
    if(ostufile.fail()) 
    { 
		cout << "Can not open file!" << endl;
		exit(0);
	} 
	for(vector<course>::iterator it = COU.begin(); it != COU.end(); it++) 
	{ 
		course course = *it; 
		ostufile << course.course_name << '#'<< course.course_ID << '#'<< course.course_teacher << '#'<<endl; //写数据时写入#，方便读数据时找到
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
	   //这两个只有学生自己能看到，老师不能乱改
	   int student_mark; //过去的分数，我想，这个应该是用来，如果你挂科了，就不能选课了
	   string selection_cour[3]; //student can choose 3 courses 3门课最多
   public:
	   vector<student> STU;
	   student();
	   student(string NAME_ST , string PASSWORD_ST , string STUDENT_ID , string STUDENT_GRADE , int STUDENT_MARK, string selection_cour1="***", string selection_cour2="***", string selection_cour3="***");//默认参数，如果没给出就默认为***,***将在选课时被用到，表示尚未被选课
	 
	   student student_login(); 

	   void student_Add();  //类似的course
	   void student_Delete();
	   void student_Browse();
	   void student_Edit();
	  
	   void student_inf(); //管理员能看到的
	   void itself_inf(); //学生自己能看到的（过去的分数和选的课）

	   void input_inf(); //
	   void output_inf();

	   void course_sel(student stu); //选课
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



student student::student_login()  //学生登入系统 ，他最后返回类student 表示他自己，这个用来显示自己信息和选课的
{
	int i = 0;
			cout << "please enter student ID number" << endl;
			string student_ID= str_Input();//输账号
			vector<student>::iterator counter;
			for(;i==0;)    //循环：没有找到ID，错误密码将重新输入。 成功了，将退出循环
			{
			for(counter=STU.begin();counter!=STU.end();counter++)
			{
				if(student_ID == counter->student_ID)//找到相同的
				{
					cout << endl<<"found"<<endl;
					break;
				}
			}
			if(counter==STU.end())  //不是到末尾，说明没找到
			{
				cout<<"no such ID"<<endl;
				cout << "please enter student ID number" << endl;
				student_ID= str_Input();
				continue;  //回到循环
			}
			cout << "please enter student password" << endl;
			string student_password= str_Input();  //输密码
			if(student_password!=counter->password_ST) //密码错误
			{
				cout<<"Password is wrong"<<endl; 
				cout << "please enter student ID number" << endl;
				student_ID= str_Input(); //回到循环
				continue;
			}
			else
			{
				cout<<"Password is right"<<endl;
				i++;  //正确 i变化，退出循环
			}
			}
			student itself(counter->name_ST,counter->password_ST,counter->student_ID,counter->student_grade, counter->student_mark,counter->selection_cour[0],counter->selection_cour[1],counter->selection_cour[2]); //记录此时这个student的信息
			return itself;
}


void student::course_sel(student stu) //选课，stu来自登入系统
{
	if(stu.student_mark<40)  //如果，你挂科了，不能再选了
			{
				cout<<"you have not pass the last exam, can not choose course"<<endl;
				exit(1);
			}

			vector<student>::iterator it=STU.begin();
			for(;it!=STU.end();it++)
			{
				if(it->student_ID == stu.student_ID)   //先找到相同的ID，确定此时位子在VECTOR
					break;
			}
			course xx;
			xx.input_course();
			cout<<"every one can choose 3 course"<<endl;
			int m;//m表示已可选课程
			for(m=0;m<3;m++)
			{
				if(stu.selection_cour[m]=="***") //***表示还没有选
				{
				cout<<"you have choose "<<m<<" courses, still can choose "<<3-m<<  " course"<<endl;
				break;
				}
			}
			if(m==3)//
			{
				cout<<"you have choose 3 courses, no more choose"<<endl;
				exit(1);  //如果满课了，就直接退出
			}
			string course_id;  //表示输入的courseID
			for(int i=m;i<3;) //对剩下的未选课程进行选课
			{
			cout<<"Please enter the ID number of course"<<endl;
			course_id = str_Input();
			vector<course>::iterator counter=xx.COU.begin();
			for(;counter!=xx.COU.end();counter++)
			{
				if(course_id == counter->course_ID)//在course里找到你要选的的课
					break;
			}
			if(counter==xx.COU.end())  //没有找到这门课，就重新输入course名字
			{
				cout<<"no found such course"<<endl;
				cout<<"Enter again"<<endl;
				continue;
			}
			else
			{
				int j =0;
				for(;j<i;j++) //对已选课进行判断
				{
					if(course_id ==it->selection_cour[j]) 
						break;
				}
				if(j!=i)  //当输入的名字已经被选取了，重新输入
				{
					cout<<"such course have been choosen"<<endl;
					continue;
				}
			it->selection_cour[i]=course_id;
			i++;  //课程加 1
			if(i <3)
			{
			cout<<"Please enter 1 to choose course ,2 to quit?"<<endl; //每添加了一门课（除了最后一门），询问是否再继续选课，不选就退出此函数
				int p = inte_Input();
			if(p!=1)
				break;
			}
			}
			}
}
void student :: student_inf()//显示信息（管理员）
{
	cout << "Student information" << endl;
	cout << "Student name: " << name_ST << "\t"<<"student password" <<password_ST<< "student ID: " << student_ID << "\t" << "student grade: " <<"\t"<< student_grade <<"student mark"<<student_mark<<endl;
	cout << endl;
}

void student::itself_inf() //显示个人信息
{
	cout << "Student own information" << endl;
	cout << "Student name: " << name_ST << "\t"<<"student password" <<password_ST<< "student ID: " << student_ID << "\t" << "student grade: " << student_grade <<"\t"<< "student past mark"<<student_mark<<"\t"<<"student choose course name"<<selection_cour[0]<<", "<<selection_cour[1]<<", "<<selection_cour[2]<<endl;
	cout << endl;
}

//下面和course类似的，不多讲了，除了再具体某些地方
//只有ID是不可重复的
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
istufile.ignore(1,'\n');   //这里要去除一个字符缓冲区，是来源于文件里的空格，因为除了mark外，其余都是字符创，用#号来表示结尾，方便终止，但是mark是int类型的，可以直接读取，不用加#，所以在写入文件中可以看到，只用了一个' '空格，代替了#。但是你读的时候这个空格会被下一个课程ID读进去，这样会不对齐，而且会空格越读越多，所以这里要删掉一个缓冲区
for(int i = 0; i < 3; i++) //读出3个课程的ID
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
		ostufile << stu.name_ST << '#'<< stu.password_ST << '#'<< stu.student_ID << '#' << stu.student_grade << '#'<< stu.student_mark <<' '<< stu.selection_cour[0]<<'#'<<stu.selection_cour[1]<<'#'<<stu.selection_cour[2]<<'#'<<endl; //看到那个空格了没有
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

administrator :: administrator() //账户密码
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
	   void student_menu(student); //2个菜单，管理员和学生
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
		    administrator term1;        //这个我忘了改了，你改了吧
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

void menu ::administrator_menu()  //8个操作，再加个退出吧
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
	cout<<"1-return to log menu, 2-return to Administrator menu 3-quit"<<endl;  //结束时询问返回那个菜单
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