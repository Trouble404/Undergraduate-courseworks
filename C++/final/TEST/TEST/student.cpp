/* student.cpp */
/* 学生类的定义 */

#include "header.h" 
#include "student.h" 
#include "menu.h" 

vector<student> stu_vec; 
vector<student> student::vStu = stu_vec; 

vector<student>::iterator student::itCurr = vStu.begin(); 

student::student() 

{ 
sNumber = ""; 
sName = ""; 
sPassword = ""; 
sSex = ""; 
classID = ""; 
nAge = 0; 
nSC = 0; 
for(int i = 0; i < 4; i++)

Selcour[i] = ""; 
} 

student::~student()
{ 


} 

void student::StuPutin() 
{ 
student stu; 

do 

{ 
system("clear"); 
cout << "\n开始录入学生信息!\n请输入:\n"; 
cout << "学生学号:"; 


stu.sNumber = inputString(); 
for(vector<student>::iterator it = vStu.begin(); it != vStu.end();) 
{ 


if(stu.sNumber != (*it).sNumber)
it++; 


else 

{ 
cout << "\n该学号已经存在!请重新输入!\n\n学生学号:"; 
stu.sNumber = inputString(); 
it = vStu.begin();

}
} 


cout << "学生名字:"; 
stu.sName = inputString(); 


cout << "初始密码:123456\n"; 
stu.sPassword = "123456"; 


cout << "学生性别(M/F):"; 
stu.sSex = inputString(); 


cout << "学生年龄:"; 
stu.nAge = inputNumber(); 


cout << "学生班级:"; 
stu.classID = inputString(); 


vStu.push_back(stu); 

cout << "\n是否继续录入学生信息？\n\n\t1.是\n\n\t2.否\n\n\t3.退出系统\n\n请选择:"; 
if(choose('3') == '2')

{ 
if(menu::Identity == "管理员") 
break; 
pass();
}
}while(1); 


menu::isback();
} 

void student::StuDelete()

{ 
system("cls");
vector<student>::iterator it = StuSearch('1');
if(it != vStu.end()) 

{ 
cout << "\n\n确定删除？\n\n\t1.是\n\n\t2.否\n\n\t3.退出系统\n\n请选择："; 
if(choose('3') == '1')
{ 

vStu.erase(it); 
} 
cout << "\n删除成功!即将返回！\n"; 


}
menu::isback(); 
} 

vector<student>::iterator student::StuSearch(char c)
{ 
if(vStu.empty())

{ 
cout << "学生记录个数为零!"; 


menu::isback(); 

return vStu.end();
} 
switch(c)
{ 

case'1': 

{ 
cout << "\n请输入学生学号:\t"; 
string s = inputString();
for(vector<student>::iterator it = vStu.begin(); it != vStu.end(); it++) 
{ 

if(s == (*it).sNumber)

{ 
ShowSelf(*it); 
return it; 


}
} 


cout << "\n没有找到该学生!"; 

return vStu.end();
} 
case'2': 


{ 
cout << "\n请输入要查询的学生名字:\t"; 
string s = inputString();
for(vector<student>::iterator it = vStu.begin(); it != vStu.end(); it++) 
{ 

if(s == (*it).sName)

{ 
ShowSelf(*it); 
return it; 


}
} 


cout << "\n没有找到该学生!\n"; 

return vStu.end();
} 
case'3': 


{ 
cout << "\n请输入要查询的学生年龄:\t"; 
int age = inputNumber();
vector<student>::iterator it_temp = vStu.end(); 
for(vector<student>::iterator it = vStu.begin(); it != vStu.end(); it++) 
{ 

if(age == (*it).nAge)

{ 
ShowSelf(*it);
it_temp = it;


} 
}
if(it_temp == vStu.end()) 


cout << "\n没有找到该学生!\n"; 

return it_temp; 
} 
case'4': 


{ 
cout << "\n请输入要查询的学生班级:\t"; 
string s = inputString(); 
vector<student>::iterator it_temp = vStu.end();
for(vector<student>::iterator it = vStu.begin(); it != vStu.end(); it++) 
{ 

if(s == (*it).classID)

{ 
ShowSelf(*it); 
it_temp = it;


}
}
if(it_temp == vStu.end()) 


cout<<"\n没有找到该学生!\n"; 

return it_temp;
} 
case'5': 

{ 
cout << "\n请输入要查询的学生性别(M/F):\t"; 


string s = inputString();
vector<student>::iterator it_temp = vStu.end();
for(vector<student>::iterator it = vStu.begin(); it != vStu.end(); it++) 
{ 


if(s == (*it).sSex)

{ 
ShowSelf(*it); 
it_temp = it;


}
} 
if(it_temp == vStu.end()) 


cout << "\n没有找到该学生!\n"; 

return it_temp;
} 
case'6': 


{ 
cout << "\n即将返回学生菜单!\n"; 
break; 


} 
}
menu::isback(); 
return vStu.end(); 


} 

void student::pass()

{ 
system("cls");
while(vStu.empty())

{ 
cout << "该系统还未记录学生信息!不能登入，请录入你的信息!\n"; 
system("pause");
StuPutin();


} 
while(1)
{ 


system("cls"); 
cout << "\t\t\t\t学生登录\n\n"; 
for(int i = 0; i < 80; i++) 


cout << "*"; 
for(int i = 0; i <= 5; i++)
cout << endl;


 cout << "\t\t\t\t学号:"; 
string snumber = inputString();
vector<student>::iterator it = vStu.begin();


//特别注意这里把it!=vStu.end()写前面。否则该帐号不存在时会出现段错误！！ 


while(it != vStu.end() && snumber != (*it).sNumber) 
it++; 
if(it != vStu.end())


{ 
cout << "\n\t\t\t\t密码:"; 
string spassword = inputString();
while(spassword != (*it).sPassword)


{ 
cout << "\n\t\t\t\t密码错误!重新输入!\n\n\t\t\t\t密码:"; 
spassword = inputString(); 
} 

cout << "\n\n\n\n\n"; 
cout << "\t\t\t\t登录成功!\n\n"; 
system("pause"); 


system("cls"); 

itCurr = it; 
menu::StuMenu();
} 


else 

{ 
system("cls"); 
cout << "\n\n\n\n\n\n\n"; 
cout << "\t\t\t学号错误!请重新输入!\n"; 
system("pause");


} 


}
} 

void student::StuView()

{ 
system("cls");
if(vStu.empty()) 

{ 
cout << "\n\n\n\n学生记录个数为零!\n\n是否输入学生信息?\n\n\t1.是\n\n\t2.返回\n\n\t3.退出\n\n"; 
char c = choose('3');
if(c == '1') 

StuPutin();
else if(c == '2')


menu::isback(); 
} 
cout << "学号\t" << "密码\t" << "名字\t" << "性别\t" << "年龄\t" << "班级" << "\n\n"; 
for(vector<student>::iterator it = vStu.begin(); it != vStu.end(); it++)


ShowSelf(*it);
menu::isback(); 
} 

void student::ShowSelf(student stu)//学生查看自己的信息 
{ 
cout << stu.sNumber << "\t" << stu.sPassword << "\t" << stu.sName << "\t" << stu.sSex << "\t" 
<< stu.nAge << "\t" << stu.classID << "\n\n"; 
} 

void student::StuEdit(char c)

{ 
system("cls"); 
bool flag = false; //flag标记是否进入下一项修改 
student& stu = *itCurr; 
switch(c)
{ 

case '7': 
flag = true; 
case '1': 


{ 
cout << "\n当前学号为:" << stu.sNumber << "\n"; 
cout << "请输入学号:"; 
string s = inputString();
for(vector<student>::iterator it = vStu.begin(); it != vStu.end();)
{ 


if(s != (*it).sNumber) 
it++; 


else 

{ 
cout << "\n该学号已经存在!请重新输入:"; 
s = inputString();
it = vStu.begin();


} 
}
stu.sNumber = s; 
if(!flag)


break; 
} 
case '2': 


{ 
cout << "\n当前密码为:" << stu.sPassword << "\n"; 
cout << "请输入密码:"; 
stu.sPassword = inputString();
if(!flag)


break; 
} 
case '3': 


{ 
cout << "\n当前名字为:" << stu.sName << "\n"; 
cout << "请输入名字:"; 
stu.sName = inputString(); 
if(!flag)


break; 
} 
case '4': 
{ 



 cout << "\n当前年龄为:" << stu.nAge << "\n"; 
int n = inputNumber();
while(n > 35 || n < 15)


{ 
cout << "年龄应在(15~35)!重新输入:"; 


n = inputNumber(); 
}
stu.nAge = n;
if(!flag) 


break; 
} 
case '5': 


{ 
cout << "\n当前性别为:" << stu.sSex << "\n"; 
cout << "请输入性别(M/F):"; 
stu.sSex = inputString();
if(!flag)


break; 
} 
case '6': 


{ 
cout << "\n当前班级为:" << stu.classID << "\n"; 
cout << "请输入班级:"; 
stu.classID = inputString(); 


}
} 
cout << "\n修改后的学生信息为:\n"; 
ShowSelf(stu); 
menu::isback();


} 

void student::sWriteFile() 

{ 
ofstream ostufile("student.txt",ios::binary);
if(ostufile.fail()) 

{ 
cout << "写入文件时打开学生文件失败!" << endl;
} 
exit(0); //退出程序 


for(vector<student>::iterator it = vStu.begin(); it != vStu.end(); it++) 

{ 
student stu = *it; 
ostufile << stu.sNumber << '#' << stu.sName << '#'


 << stu.sPassword << '#' << stu.sSex << '#' 
<< stu.nAge << ' ' << stu.classID << '#' 
<< stu.nSC << ' '; 

for(int j = 0; j < 4; j++) 
{ 


ostufile << stu.Selcour[j] << '#'; 
}
ostufile << endl; 


} 
cout << "\n学生文件保存成功!\n"; 
ostufile.close();


} 

void student::sReadFile()

{ 
ofstream ostufile("student.txt",ios::binary|ios::app);
ostufile.close();
ifstream istufile("student.txt",ios::binary);
if(istufile.fail()) 

{ 
cout << "读取文件时打开学生文件失败!" << endl;
} 
exit(0); //退出程序 


char c[N]; 
student stu; 
while(istufile.peek()!=EOF)
{ 


istufile.getline(c,N,'#'); 
stu.sNumber = c; 
istufile.getline(c,N,'#');
stu.sName = c; 



istufile.getline(c,N,'#');
stu.sPassword = c; 
istufile.getline(c,N,'#'); 
stu.sSex = c; 
istufile >> stu.nAge;
istufile.getline(c,N,'#');
stu.classID = c; 
istufile >> stu.nSC; 
for(int i = 0; i < 4; i++)
{ 


istufile.getline(c,N,'#');

stu.Selcour[i] = c;
} 
istufile.ignore(100,'\n'); 


vStu.push_back(stu);
} 
istufile.close();


} 