/* menu.cpp */
/* 菜单类的定义 */ 

#include "manager.h"
#include "menu.h" 
#include "SelCourse.h" 

string menu::Identity=""; 
void menu::SelWho() //选择登入界面 
{ 

student stu; 
course cou; 
cou.cReadFile();
stu.sReadFile(); 
printf("\n\t\t\t欢迎使用学生选课系统\n"); 


for(int i = 0; i < 80; i++) 
cout << "*"; 
cout << endl; 


cout << "\n\t\t\t\t请选择你的身份:\n\n\n"; 
cout << "\t\t\t\t 1.学生\n\n"; 
cout << "\t\t\t\t 2.管理员\n\n"; 
cout << "\t\t\t\t 3.退出系统\n\n\n"; 


for(int j = 0; j < 80; j++) 

cout << "*"; 
cout << endl << endl; 
cout << "请选择(1~3): "; 


switch(choose('3'))
{ 
case'1': 


{ 
Identity = "学生"; 
student studen; 
studen.pass(); 
break; 


} 
case'2': 


{ 
Identity = "管理员"; 
manager mana;
mana.mpass();
break; 


}
}
} 


void menu::StuMenu() //学生信息菜单 
{ 
system("cls"); 

cout << "\t\t\t\t学生菜单:\n\n"; 
for(int i = 0; i < 80; i++) 
cout << "*"; 
cout << "\n\n\n\n"; 


cout << "\t\t\t\t1.开始选课\n\n"; 
cout << "\t\t\t\t2.浏览课程信息\n\n"; 
cout << "\t\t\t\t3.查询课程\n\n"; 
cout << "\t\t\t\t4.修改资料\n\n"; 
cout << "\t\t\t\t5.退出系统\n\n\n\n\n"; 


for(int i = 0; i < 80; i++) 
cout << "*"; 
cout << endl; 


cout << "\n请选择功能(1~5):";//判断选择菜单是否正确 
switch(choose('5'))
{ 

case'1': 

{ 
SelCourseMenu(); 
break; 


} 
case'2': 
{ 


course c; 
c.CourView();
menu::isback(); 
break; 

} 
case'3': 
{ 


CourSearchMenu();

break; 
} 
case'4': 
{ 


StuEditMenu(); 
break; 
}
} 
} 

void menu::ManaMenu() 

{ 
system("cls"); 
cout << "\n\t\t\t\t管理员菜单\n\n"; 
for(int i = 0; i < 80; i++) 

cout << "*"; 
cout << "\n\n\n\n"; 


cout << "\t\t\t\t1.课程信息浏览\n\n"; 
cout << "\t\t\t\t2.学生信息浏览\n\n"; 
cout << "\t\t\t\t3.修改资料\n\n"; 
cout << "\t\t\t\t4.管理系统\n\n"; 
cout << "\t\t\t\t5.退出系统\n\n\n\n\n"; 


for(int i = 0; i < 80; i++) 
cout << "*"; 
cout << endl; 


cout << "\n请选择功能(1~5):";//判断选择菜单是否正确 
switch(choose('5')) 
{ 

case'1': 

{ 
system("cls"); 
manager m;
m.c.CourView(); 



menu::isback();

break; 
} 
case'2': 
{ 


manager m;
m.s.StuView(); 
break; 


} 
case'3': 
{ 


ManaEditMenu();

break; 
} 
case'4': 
{ 


Msystem(); 
break; 
}
} 
} 

void menu::StuEditMenu() 

{ 
system("cls"); 
cout << "\t\t\t\t学生信息修改菜单:\n\n"; 
for(int i = 0; i < 80; i++) 

cout << "*"; 
cout << "\n请选择需要修改的内容:\n\n\n\n"; 


cout << "\t\t\t1.学生学号\t\t2.学生密码\n\n"; 
cout << "\t\t\t3.学生名字\t\t4.学生年龄\n\n"; 
cout << "\t\t\t5.学生性别\t\t6.学生班级\n\n"; 
cout << "\t\t\t7.全部信息\t\t8.退出系统\n\n\n\n\n"; 


for(int i = 0; i < 80; i++) 
cout << "*"; 
cout << "\n" << endl; 


cout << "请选择功能(1~8):";//判断选择菜单是否正确 
student s; 
s.StuEdit(choose('8'));


} 

void menu::ManaEditMenu() 

{ 
system("cls"); 
cout << "\t\t\t\t管理员信息修改菜单:\n\n"; 
for(int i = 0; i < 80; i++) 

cout << "*"; 
cout << "\n请选择需要修改的内容:\n\n\n\n\n"; 


cout << "\t\t\t1.管理员编号\t\t2.管理员密码\n\n"; 
cout << "\t\t\t3.管理员名字\t\t4.管理员年龄\n\n"; 
cout << "\t\t\t5.管理员性别\t\t6.全部信息\n\n"; 
cout << "\t\t\t7.退出系统\n\n\n\n\n\n"; 


for(int i = 0; i < 80; i++) 

cout << "*"; 
cout << "\n" << endl << "请选择功能(1~7):";//判断选择菜单是否正确 
manager m;
m.ManaEdit(choose('7'));
menu::isback(); 

} 

void menu::SelCourseMenu() 

{ 
system("cls"); 
cout << "\t\t\t\t选课菜单:\n\n"; 
for(int i = 0; i < 80; i++) 

cout << "*"; 
cout << "\n\n\n\n\n\n"; 


cout << "\t\t\t\t1.选课\n\n"; 


cout << "\t\t\t\t2.退选\n\n"; 
cout << "\t\t\t\t3.选课浏览\n\n"; 
cout << "\t\t\t\t4.退出系统\n\n\n\n"; 


for(int i = 0; i < 80; i++) 

cout << "*"; 
cout << "\n" << endl; 
cout << "请选择所需的功能(1~4):"; 
switch(choose('4'))
{ 


case'1': 

{ 
SelCourse SelCourse1; 
SelCourse1.SelectCour();
break; 

} 
case'2': 
{ 


SelCourse SelCourse1; 
SelCourse1.DeleteCour();
break; 

} 
case'3': 
{ 


SelCourse SelCourse1; 
SelCourse1.SelCourView();
menu::isback();
break; 


}
}
} 

void menu::CourSearchMenu()

{ 
system("cls"); 
cout << "\t\t\t\t课程信息查询菜单:\n\n"; 
for(int i = 0; i < 80; i++) 

cout << "*"; 
cout << "\n\n\t\t\t\t请选择查询方式:\n\n\n\n"; 

cout << "\t\t\t1.课程编号\t\t2.课程名字\n\n"; 
cout << "\t\t\t3.上课教师\t\t4.上课时间\n\n"; 
cout << "\t\t\t5.退出系统\n\n\n\n\n\n"; 

for(int i = 0; i < 80; i++) 
cout << "*"; 
cout << "\n\n"; 


cout << "请选择功能(1~5):";//判断选择菜单是否正确 
course c; 
c.CourSearch(choose('5'));
menu::isback(); 


} 

void menu::StuSearchMenu() 

{ 
system("cls"); 
cout << "\t\t\t\t学生信息查询菜单:\n\n"; 
for(int i = 0; i < 80; i++) 

cout << "*"; 
cout << endl; 
cout << "请选择查询方式:\n\n\n\n"; 


cout << "\t\t\t\t1.学生学号\n\n"; 
cout << "\t\t\t\t2.学生名字\n\n"; 
cout << "\t\t\t\t3.学生年龄\n\n"; 
cout << "\t\t\t\t4.学生班级\n\n"; 
cout << "\t\t\t\t5.学生性别\n\n"; 
cout << "\t\t\t\t6.退出系统\n\n\n\n\n\n"; 
for(int i = 0; i < 80; i++) 

cout << "*"; 
cout << endl; 
cout << "\n请选择功能(1~6):";//判断选择菜单是否正确 
student s; 


s.StuSearch(choose('6'));
} 

void menu::Msystem()

{ 
system("cls"); 
cout << "管理系统:\n"; 
for(int i = 0; i < 80; i++) 

cout << "*"; 
cout << "\n\n\n\n\n\n"; 
cout << "\t\t\t1.录入课程\t5.录入学生\n\n"; 
cout << "\t\t\t2.查询课程\t6.查询学生\n\n"; 
cout << "\t\t\t3.删除课程\t7.删除学生\n\n"; 
cout << "\t\t\t4.修改课程\t8.退出系统\n\n\n\n\n\n"; 
for(int i = 0; i < 80; i++) 


cout << "*"; 
cout << endl; 
cout << "\n请选择:"; 
switch(choose('8'))
{ 


case'1': 

{ 
course c; 
c.CourPutin(); 
break; 


} 
case'2': 
{ 


CourSearchMenu();

break; 
} 
case'3': 
{ 


course c; 
c.CourDele();
break; 


} 
case'4': 
{ 


course c; 
c.CourEdit();
break; 


} 
case'5': 
{ 


student s; 
s.StuPutin(); 
break; 


} 
case'6': 
{ 


StuSearchMenu();

break; 
} 
case'7': 
{ 


student s; 
s.StuDelete();
break; 


} 
}
} 

void menu::isback()

{ 
cout << "\n\n\t是否返回主菜单？\n\n\t 1.是\n\n\t 2.退出系统\n\n请选择:"; 
char c = inputChar();
while(c != '1' && c != '2') 

{ 
cout << "\n选择错误!重新选择:"; 

c = inputChar();
} 
if(c == '1')
{ 



if(Identity == "学生") 
StuMenu();


else 

ManaMenu();
} 


else 

{ 
student stu; 
stu.sWriteFile(); 
course cou; 
cou.cWriteFile(); 
cout << endl; 
exit(0);


} 
} 

menu::~menu()
{ 

}