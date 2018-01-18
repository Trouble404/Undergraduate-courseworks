/* manager.cpp */
/* 管理员类定义 */ 

#include "manager.h" 


#include "menu.h" 

manager man; 

manager::manager()

{ 
sName = "管理员"; 
sNumber = "1"; 
sSex = "男"; 
sPassWord = "1"; 
nAge = 22; 

} 

void manager::ManaShow()

{ 
cout << "\n管理员信息为:\n\n"; 
cout << "名字\t" << "帐号\t" << "性别\t" << "密码\t" << "年龄\n\n"; 
cout << man.sName << "\t" << man.sNumber << "\t" << man.sSex << "\t" << man.sPassWord << "\t" << 

man.nAge << "\n\n"; 
} 

void manager::ManaEdit(char c)

{ 
system("clear");
bool flag = false; 
switch(c)
{ 

case'6': 
flag = true; 
case'1': 


{ 
cout << "\n当前管理员帐号为\t" << man.sNumber << "\n\n请输入新帐号:\t"; 
man.sNumber = inputString(); 
if(!flag)


break; 
} 
case'2': 


{ 
cout << "\n当前管理员密码为\t"<<man.sPassWord<<"\n\n请输入新密码:\t"; 
man.sPassWord = inputString(); 
if(!flag)


break; 
} 
case'3': 


{ 
cout << "\n当前管理员名字为\t" << man.sName << "\n\n请输入新名字:\t"; 
man.sName = inputString();
if(!flag) 


break; 
} 
case'4': 


{ 
cout << "\n当前管理员年龄为\t" << man.nAge << "\n\n请输入新年龄:\t"; 
int age = inputNumber();
while(age > 100 || age < 16)


{ 
cout << "\n输入年龄错误!请重新输入(16~100):"; 

age = inputNumber();
}
man.nAge = age; 
if(!flag)


break; 
} 
case'5': 


{ 
cout << "\n当前管理员性别为:" << man.sSex << "\n\n"; 
cout << "请输入性别(男/女):"; 
string s = inputString(); 
while(s != "男" && s != "女")


{ 
cout << "输入性别错误!请重新输入(男或女):"; 

s = inputString(); 
}
man.sSex = s; 



}
} 
cout << "\n修改后:\n"; 
ManaShow();


} 

void manager::mpass()

{ 
while(1)
{ 

system("cls"); 
cout << "\t\t\t\t管理员登录\n\n"; 
for(int i = 0; i < 80; i++) 


cout << "*"; 
cout << "\n\n\n\n\n" << endl; 


cout << "\t\t\t\t帐号:"; 
string number = inputString();
if(number != man.sNumber)


{ 
cout << "\n\n\n\t\t\t\t帐号错误!重新输入：\n"; 
number = inputString();
} 


cout << "\n\t\t\t\t密码:"; 
string passw = inputString(); 
while(passw != man.sPassWord)


{ 
cout << "\n\n\n\n\n\n\t\t\t密码错误!密码:"; 
passw = inputString(); 
} 


cout << "\n\n\n\n\n\n\t\t\t登录成功!\n\n"; 
system("pause");
menu::ManaMenu(); 
break; 


}
} 

manager::~manager()
{ 

} 