/* student.cpp */
/* ѧ����Ķ��� */

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
cout << "\n��ʼ¼��ѧ����Ϣ!\n������:\n"; 
cout << "ѧ��ѧ��:"; 


stu.sNumber = inputString(); 
for(vector<student>::iterator it = vStu.begin(); it != vStu.end();) 
{ 


if(stu.sNumber != (*it).sNumber)
it++; 


else 

{ 
cout << "\n��ѧ���Ѿ�����!����������!\n\nѧ��ѧ��:"; 
stu.sNumber = inputString(); 
it = vStu.begin();

}
} 


cout << "ѧ������:"; 
stu.sName = inputString(); 


cout << "��ʼ����:123456\n"; 
stu.sPassword = "123456"; 


cout << "ѧ���Ա�(M/F):"; 
stu.sSex = inputString(); 


cout << "ѧ������:"; 
stu.nAge = inputNumber(); 


cout << "ѧ���༶:"; 
stu.classID = inputString(); 


vStu.push_back(stu); 

cout << "\n�Ƿ����¼��ѧ����Ϣ��\n\n\t1.��\n\n\t2.��\n\n\t3.�˳�ϵͳ\n\n��ѡ��:"; 
if(choose('3') == '2')

{ 
if(menu::Identity == "����Ա") 
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
cout << "\n\nȷ��ɾ����\n\n\t1.��\n\n\t2.��\n\n\t3.�˳�ϵͳ\n\n��ѡ��"; 
if(choose('3') == '1')
{ 

vStu.erase(it); 
} 
cout << "\nɾ���ɹ�!�������أ�\n"; 


}
menu::isback(); 
} 

vector<student>::iterator student::StuSearch(char c)
{ 
if(vStu.empty())

{ 
cout << "ѧ����¼����Ϊ��!"; 


menu::isback(); 

return vStu.end();
} 
switch(c)
{ 

case'1': 

{ 
cout << "\n������ѧ��ѧ��:\t"; 
string s = inputString();
for(vector<student>::iterator it = vStu.begin(); it != vStu.end(); it++) 
{ 

if(s == (*it).sNumber)

{ 
ShowSelf(*it); 
return it; 


}
} 


cout << "\nû���ҵ���ѧ��!"; 

return vStu.end();
} 
case'2': 


{ 
cout << "\n������Ҫ��ѯ��ѧ������:\t"; 
string s = inputString();
for(vector<student>::iterator it = vStu.begin(); it != vStu.end(); it++) 
{ 

if(s == (*it).sName)

{ 
ShowSelf(*it); 
return it; 


}
} 


cout << "\nû���ҵ���ѧ��!\n"; 

return vStu.end();
} 
case'3': 


{ 
cout << "\n������Ҫ��ѯ��ѧ������:\t"; 
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


cout << "\nû���ҵ���ѧ��!\n"; 

return it_temp; 
} 
case'4': 


{ 
cout << "\n������Ҫ��ѯ��ѧ���༶:\t"; 
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


cout<<"\nû���ҵ���ѧ��!\n"; 

return it_temp;
} 
case'5': 

{ 
cout << "\n������Ҫ��ѯ��ѧ���Ա�(M/F):\t"; 


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


cout << "\nû���ҵ���ѧ��!\n"; 

return it_temp;
} 
case'6': 


{ 
cout << "\n��������ѧ���˵�!\n"; 
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
cout << "��ϵͳ��δ��¼ѧ����Ϣ!���ܵ��룬��¼�������Ϣ!\n"; 
system("pause");
StuPutin();


} 
while(1)
{ 


system("cls"); 
cout << "\t\t\t\tѧ����¼\n\n"; 
for(int i = 0; i < 80; i++) 


cout << "*"; 
for(int i = 0; i <= 5; i++)
cout << endl;


 cout << "\t\t\t\tѧ��:"; 
string snumber = inputString();
vector<student>::iterator it = vStu.begin();


//�ر�ע�������it!=vStu.end()дǰ�档������ʺŲ�����ʱ����ֶδ��󣡣� 


while(it != vStu.end() && snumber != (*it).sNumber) 
it++; 
if(it != vStu.end())


{ 
cout << "\n\t\t\t\t����:"; 
string spassword = inputString();
while(spassword != (*it).sPassword)


{ 
cout << "\n\t\t\t\t�������!��������!\n\n\t\t\t\t����:"; 
spassword = inputString(); 
} 

cout << "\n\n\n\n\n"; 
cout << "\t\t\t\t��¼�ɹ�!\n\n"; 
system("pause"); 


system("cls"); 

itCurr = it; 
menu::StuMenu();
} 


else 

{ 
system("cls"); 
cout << "\n\n\n\n\n\n\n"; 
cout << "\t\t\tѧ�Ŵ���!����������!\n"; 
system("pause");


} 


}
} 

void student::StuView()

{ 
system("cls");
if(vStu.empty()) 

{ 
cout << "\n\n\n\nѧ����¼����Ϊ��!\n\n�Ƿ�����ѧ����Ϣ?\n\n\t1.��\n\n\t2.����\n\n\t3.�˳�\n\n"; 
char c = choose('3');
if(c == '1') 

StuPutin();
else if(c == '2')


menu::isback(); 
} 
cout << "ѧ��\t" << "����\t" << "����\t" << "�Ա�\t" << "����\t" << "�༶" << "\n\n"; 
for(vector<student>::iterator it = vStu.begin(); it != vStu.end(); it++)


ShowSelf(*it);
menu::isback(); 
} 

void student::ShowSelf(student stu)//ѧ���鿴�Լ�����Ϣ 
{ 
cout << stu.sNumber << "\t" << stu.sPassword << "\t" << stu.sName << "\t" << stu.sSex << "\t" 
<< stu.nAge << "\t" << stu.classID << "\n\n"; 
} 

void student::StuEdit(char c)

{ 
system("cls"); 
bool flag = false; //flag����Ƿ������һ���޸� 
student& stu = *itCurr; 
switch(c)
{ 

case '7': 
flag = true; 
case '1': 


{ 
cout << "\n��ǰѧ��Ϊ:" << stu.sNumber << "\n"; 
cout << "������ѧ��:"; 
string s = inputString();
for(vector<student>::iterator it = vStu.begin(); it != vStu.end();)
{ 


if(s != (*it).sNumber) 
it++; 


else 

{ 
cout << "\n��ѧ���Ѿ�����!����������:"; 
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
cout << "\n��ǰ����Ϊ:" << stu.sPassword << "\n"; 
cout << "����������:"; 
stu.sPassword = inputString();
if(!flag)


break; 
} 
case '3': 


{ 
cout << "\n��ǰ����Ϊ:" << stu.sName << "\n"; 
cout << "����������:"; 
stu.sName = inputString(); 
if(!flag)


break; 
} 
case '4': 
{ 



 cout << "\n��ǰ����Ϊ:" << stu.nAge << "\n"; 
int n = inputNumber();
while(n > 35 || n < 15)


{ 
cout << "����Ӧ��(15~35)!��������:"; 


n = inputNumber(); 
}
stu.nAge = n;
if(!flag) 


break; 
} 
case '5': 


{ 
cout << "\n��ǰ�Ա�Ϊ:" << stu.sSex << "\n"; 
cout << "�������Ա�(M/F):"; 
stu.sSex = inputString();
if(!flag)


break; 
} 
case '6': 


{ 
cout << "\n��ǰ�༶Ϊ:" << stu.classID << "\n"; 
cout << "������༶:"; 
stu.classID = inputString(); 


}
} 
cout << "\n�޸ĺ��ѧ����ϢΪ:\n"; 
ShowSelf(stu); 
menu::isback();


} 

void student::sWriteFile() 

{ 
ofstream ostufile("student.txt",ios::binary);
if(ostufile.fail()) 

{ 
cout << "д���ļ�ʱ��ѧ���ļ�ʧ��!" << endl;
} 
exit(0); //�˳����� 


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
cout << "\nѧ���ļ�����ɹ�!\n"; 
ostufile.close();


} 

void student::sReadFile()

{ 
ofstream ostufile("student.txt",ios::binary|ios::app);
ostufile.close();
ifstream istufile("student.txt",ios::binary);
if(istufile.fail()) 

{ 
cout << "��ȡ�ļ�ʱ��ѧ���ļ�ʧ��!" << endl;
} 
exit(0); //�˳����� 


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