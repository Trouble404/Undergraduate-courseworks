/* menu.cpp */
/* �˵���Ķ��� */ 

#include "manager.h"
#include "menu.h" 
#include "SelCourse.h" 

string menu::Identity=""; 
void menu::SelWho() //ѡ�������� 
{ 

student stu; 
course cou; 
cou.cReadFile();
stu.sReadFile(); 
printf("\n\t\t\t��ӭʹ��ѧ��ѡ��ϵͳ\n"); 


for(int i = 0; i < 80; i++) 
cout << "*"; 
cout << endl; 


cout << "\n\t\t\t\t��ѡ��������:\n\n\n"; 
cout << "\t\t\t\t 1.ѧ��\n\n"; 
cout << "\t\t\t\t 2.����Ա\n\n"; 
cout << "\t\t\t\t 3.�˳�ϵͳ\n\n\n"; 


for(int j = 0; j < 80; j++) 

cout << "*"; 
cout << endl << endl; 
cout << "��ѡ��(1~3): "; 


switch(choose('3'))
{ 
case'1': 


{ 
Identity = "ѧ��"; 
student studen; 
studen.pass(); 
break; 


} 
case'2': 


{ 
Identity = "����Ա"; 
manager mana;
mana.mpass();
break; 


}
}
} 


void menu::StuMenu() //ѧ����Ϣ�˵� 
{ 
system("cls"); 

cout << "\t\t\t\tѧ���˵�:\n\n"; 
for(int i = 0; i < 80; i++) 
cout << "*"; 
cout << "\n\n\n\n"; 


cout << "\t\t\t\t1.��ʼѡ��\n\n"; 
cout << "\t\t\t\t2.����γ���Ϣ\n\n"; 
cout << "\t\t\t\t3.��ѯ�γ�\n\n"; 
cout << "\t\t\t\t4.�޸�����\n\n"; 
cout << "\t\t\t\t5.�˳�ϵͳ\n\n\n\n\n"; 


for(int i = 0; i < 80; i++) 
cout << "*"; 
cout << endl; 


cout << "\n��ѡ����(1~5):";//�ж�ѡ��˵��Ƿ���ȷ 
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
cout << "\n\t\t\t\t����Ա�˵�\n\n"; 
for(int i = 0; i < 80; i++) 

cout << "*"; 
cout << "\n\n\n\n"; 


cout << "\t\t\t\t1.�γ���Ϣ���\n\n"; 
cout << "\t\t\t\t2.ѧ����Ϣ���\n\n"; 
cout << "\t\t\t\t3.�޸�����\n\n"; 
cout << "\t\t\t\t4.����ϵͳ\n\n"; 
cout << "\t\t\t\t5.�˳�ϵͳ\n\n\n\n\n"; 


for(int i = 0; i < 80; i++) 
cout << "*"; 
cout << endl; 


cout << "\n��ѡ����(1~5):";//�ж�ѡ��˵��Ƿ���ȷ 
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
cout << "\t\t\t\tѧ����Ϣ�޸Ĳ˵�:\n\n"; 
for(int i = 0; i < 80; i++) 

cout << "*"; 
cout << "\n��ѡ����Ҫ�޸ĵ�����:\n\n\n\n"; 


cout << "\t\t\t1.ѧ��ѧ��\t\t2.ѧ������\n\n"; 
cout << "\t\t\t3.ѧ������\t\t4.ѧ������\n\n"; 
cout << "\t\t\t5.ѧ���Ա�\t\t6.ѧ���༶\n\n"; 
cout << "\t\t\t7.ȫ����Ϣ\t\t8.�˳�ϵͳ\n\n\n\n\n"; 


for(int i = 0; i < 80; i++) 
cout << "*"; 
cout << "\n" << endl; 


cout << "��ѡ����(1~8):";//�ж�ѡ��˵��Ƿ���ȷ 
student s; 
s.StuEdit(choose('8'));


} 

void menu::ManaEditMenu() 

{ 
system("cls"); 
cout << "\t\t\t\t����Ա��Ϣ�޸Ĳ˵�:\n\n"; 
for(int i = 0; i < 80; i++) 

cout << "*"; 
cout << "\n��ѡ����Ҫ�޸ĵ�����:\n\n\n\n\n"; 


cout << "\t\t\t1.����Ա���\t\t2.����Ա����\n\n"; 
cout << "\t\t\t3.����Ա����\t\t4.����Ա����\n\n"; 
cout << "\t\t\t5.����Ա�Ա�\t\t6.ȫ����Ϣ\n\n"; 
cout << "\t\t\t7.�˳�ϵͳ\n\n\n\n\n\n"; 


for(int i = 0; i < 80; i++) 

cout << "*"; 
cout << "\n" << endl << "��ѡ����(1~7):";//�ж�ѡ��˵��Ƿ���ȷ 
manager m;
m.ManaEdit(choose('7'));
menu::isback(); 

} 

void menu::SelCourseMenu() 

{ 
system("cls"); 
cout << "\t\t\t\tѡ�β˵�:\n\n"; 
for(int i = 0; i < 80; i++) 

cout << "*"; 
cout << "\n\n\n\n\n\n"; 


cout << "\t\t\t\t1.ѡ��\n\n"; 


cout << "\t\t\t\t2.��ѡ\n\n"; 
cout << "\t\t\t\t3.ѡ�����\n\n"; 
cout << "\t\t\t\t4.�˳�ϵͳ\n\n\n\n"; 


for(int i = 0; i < 80; i++) 

cout << "*"; 
cout << "\n" << endl; 
cout << "��ѡ������Ĺ���(1~4):"; 
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
cout << "\t\t\t\t�γ���Ϣ��ѯ�˵�:\n\n"; 
for(int i = 0; i < 80; i++) 

cout << "*"; 
cout << "\n\n\t\t\t\t��ѡ���ѯ��ʽ:\n\n\n\n"; 

cout << "\t\t\t1.�γ̱��\t\t2.�γ�����\n\n"; 
cout << "\t\t\t3.�Ͽν�ʦ\t\t4.�Ͽ�ʱ��\n\n"; 
cout << "\t\t\t5.�˳�ϵͳ\n\n\n\n\n\n"; 

for(int i = 0; i < 80; i++) 
cout << "*"; 
cout << "\n\n"; 


cout << "��ѡ����(1~5):";//�ж�ѡ��˵��Ƿ���ȷ 
course c; 
c.CourSearch(choose('5'));
menu::isback(); 


} 

void menu::StuSearchMenu() 

{ 
system("cls"); 
cout << "\t\t\t\tѧ����Ϣ��ѯ�˵�:\n\n"; 
for(int i = 0; i < 80; i++) 

cout << "*"; 
cout << endl; 
cout << "��ѡ���ѯ��ʽ:\n\n\n\n"; 


cout << "\t\t\t\t1.ѧ��ѧ��\n\n"; 
cout << "\t\t\t\t2.ѧ������\n\n"; 
cout << "\t\t\t\t3.ѧ������\n\n"; 
cout << "\t\t\t\t4.ѧ���༶\n\n"; 
cout << "\t\t\t\t5.ѧ���Ա�\n\n"; 
cout << "\t\t\t\t6.�˳�ϵͳ\n\n\n\n\n\n"; 
for(int i = 0; i < 80; i++) 

cout << "*"; 
cout << endl; 
cout << "\n��ѡ����(1~6):";//�ж�ѡ��˵��Ƿ���ȷ 
student s; 


s.StuSearch(choose('6'));
} 

void menu::Msystem()

{ 
system("cls"); 
cout << "����ϵͳ:\n"; 
for(int i = 0; i < 80; i++) 

cout << "*"; 
cout << "\n\n\n\n\n\n"; 
cout << "\t\t\t1.¼��γ�\t5.¼��ѧ��\n\n"; 
cout << "\t\t\t2.��ѯ�γ�\t6.��ѯѧ��\n\n"; 
cout << "\t\t\t3.ɾ���γ�\t7.ɾ��ѧ��\n\n"; 
cout << "\t\t\t4.�޸Ŀγ�\t8.�˳�ϵͳ\n\n\n\n\n\n"; 
for(int i = 0; i < 80; i++) 


cout << "*"; 
cout << endl; 
cout << "\n��ѡ��:"; 
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
cout << "\n\n\t�Ƿ񷵻����˵���\n\n\t 1.��\n\n\t 2.�˳�ϵͳ\n\n��ѡ��:"; 
char c = inputChar();
while(c != '1' && c != '2') 

{ 
cout << "\nѡ�����!����ѡ��:"; 

c = inputChar();
} 
if(c == '1')
{ 



if(Identity == "ѧ��") 
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