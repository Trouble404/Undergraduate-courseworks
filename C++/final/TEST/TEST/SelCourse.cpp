/* SelCourse.cpp */
/* ѡ���ඨ�� */ 

#include "header.h" 
#include "SelCourse.h" 
#include "menu.h" 
#include "student.h" 
#include "course.h" 

course cou; 

void SelCourse::SelectCour()

{ 
while(1)
{ 

system("cls"); 
cou.CourView(); 


if((*student::itCurr).nSC >= 4) 

{ 
cout << "���Ѿ�ѡ���Ŀ�!������ѡ!"; 
menu::isback(); 
return; 


} 

else 

{ 
bool flag = false; 
vector<course>::iterator it = cou.CourSearch('1');
for(int j = 0; j < (*student::itCurr).nSC; j++)
{ 


if((*it).sNumber == (*student::itCurr).Selcour[j] && it != course::vCou.end()) 


 { 
cout << "\n�˿γ����Ѿ�ѡ������ѡ!\n"; 
flag = true; 
break;


 } 
} 


if(flag) 
break; 


if((*it).nCount >= (*it).nSlecMax) 

{ 
cout << "�˿γ��Ѿ�������,������ѡ!"; 
menu::isback(); 
return; 


} 

else 

{ 
(*student::itCurr).Selcour[(*student::itCurr).nSC] = (*it).sNumber; 
(*student::itCurr).nSC++;
(*it).nCount++;
menu::isback(); 
return; 

}
} 


cout << "�Ƿ����ѡ��?\n\n\t1.��\n\n\t2.��\n\n\t3.�˳�ϵͳ\n\n��ѡ��:"; 
if(choose('3') == '2')


break; 
} 
menu::isback();


} 

void SelCourse::SelCourView()

{ 
system("clear");
if((*student::itCurr).nSC == 0) 

{ 
cout << "�㻹û��ѡ��!\n"; 
menu::isback(); 
return; 


} 
cout << "����ѡ��Ŀγ�����:\n"; 
for(int i = 0; i < (*student::itCurr).nSC; i++)
{ 


string temp = (*student::itCurr).Selcour[i]; 
for(vector<course>::iterator it = course::vCou.begin(); it != course::vCou.end(); it++) 
{ 


if(temp == (*it).sNumber) 
cou.PrintCour(*it);
}
} 
} 

void SelCourse::DeleteCour() 

{ 
system("cls");
if((*student::itCurr).nSC == 0)

{ 
cout << "�㻹û��ѡ��!\n"; 
menu::isback(); 
return; 


} 
SelCourView(); 
cout << "\n������Ҫ��ѡ�Ŀγ̱��:"; 


vector<course>::iterator it = cou.CourSearch('1');
while(it == course::vCou.end()) 


{ 
cout << "\n��������������:"; 

it = cou.CourSearch('1');
} 
for(int i = 0; i < (*student::itCurr).nSC; i++)
{ 



if((*it).sNumber == (*student::itCurr).Selcour[i]) 
{ 
for(int j = i; j < (*student::itCurr).nSC-1; j++) 
(*student::itCurr).Selcour[j] = (*student::itCurr).Selcour[j+1]; 
cout << "��ѡ�ɹ�!"; 

(*it).nCount--;
(*student::itCurr).Selcour[i] = ""; 
(*student::itCurr).nSC--;
break; 


} 

else 

{ 
cout << "��û��ѡ��ÿγ�!\n��������:"; 
it = cou.CourSearch('1');
i = -1; 


}
}
menu::isback(); 


} 

SelCourse::~SelCourse() 
{ 

} 