/* manager.cpp */
/* ����Ա�ඨ�� */ 

#include "manager.h" 


#include "menu.h" 

manager man; 

manager::manager()

{ 
sName = "����Ա"; 
sNumber = "1"; 
sSex = "��"; 
sPassWord = "1"; 
nAge = 22; 

} 

void manager::ManaShow()

{ 
cout << "\n����Ա��ϢΪ:\n\n"; 
cout << "����\t" << "�ʺ�\t" << "�Ա�\t" << "����\t" << "����\n\n"; 
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
cout << "\n��ǰ����Ա�ʺ�Ϊ\t" << man.sNumber << "\n\n���������ʺ�:\t"; 
man.sNumber = inputString(); 
if(!flag)


break; 
} 
case'2': 


{ 
cout << "\n��ǰ����Ա����Ϊ\t"<<man.sPassWord<<"\n\n������������:\t"; 
man.sPassWord = inputString(); 
if(!flag)


break; 
} 
case'3': 


{ 
cout << "\n��ǰ����Ա����Ϊ\t" << man.sName << "\n\n������������:\t"; 
man.sName = inputString();
if(!flag) 


break; 
} 
case'4': 


{ 
cout << "\n��ǰ����Ա����Ϊ\t" << man.nAge << "\n\n������������:\t"; 
int age = inputNumber();
while(age > 100 || age < 16)


{ 
cout << "\n�����������!����������(16~100):"; 

age = inputNumber();
}
man.nAge = age; 
if(!flag)


break; 
} 
case'5': 


{ 
cout << "\n��ǰ����Ա�Ա�Ϊ:" << man.sSex << "\n\n"; 
cout << "�������Ա�(��/Ů):"; 
string s = inputString(); 
while(s != "��" && s != "Ů")


{ 
cout << "�����Ա����!����������(�л�Ů):"; 

s = inputString(); 
}
man.sSex = s; 



}
} 
cout << "\n�޸ĺ�:\n"; 
ManaShow();


} 

void manager::mpass()

{ 
while(1)
{ 

system("cls"); 
cout << "\t\t\t\t����Ա��¼\n\n"; 
for(int i = 0; i < 80; i++) 


cout << "*"; 
cout << "\n\n\n\n\n" << endl; 


cout << "\t\t\t\t�ʺ�:"; 
string number = inputString();
if(number != man.sNumber)


{ 
cout << "\n\n\n\t\t\t\t�ʺŴ���!�������룺\n"; 
number = inputString();
} 


cout << "\n\t\t\t\t����:"; 
string passw = inputString(); 
while(passw != man.sPassWord)


{ 
cout << "\n\n\n\n\n\n\t\t\t�������!����:"; 
passw = inputString(); 
} 


cout << "\n\n\n\n\n\n\t\t\t��¼�ɹ�!\n\n"; 
system("pause");
menu::ManaMenu(); 
break; 


}
} 

manager::~manager()
{ 

} 