/* SelCourse.cpp */
/* 选课类定义 */ 

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
cout << "你已经选足四科!不能再选!"; 
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
cout << "\n此课程你已经选择不能再选!\n"; 
flag = true; 
break;


 } 
} 


if(flag) 
break; 


if((*it).nCount >= (*it).nSlecMax) 

{ 
cout << "此课程已经达上限,不能再选!"; 
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


cout << "是否继续选课?\n\n\t1.是\n\n\t2.否\n\n\t3.退出系统\n\n请选择:"; 
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
cout << "你还没有选课!\n"; 
menu::isback(); 
return; 


} 
cout << "你所选择的课程如下:\n"; 
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
cout << "你还没有选课!\n"; 
menu::isback(); 
return; 


} 
SelCourView(); 
cout << "\n请输入要退选的课程编号:"; 


vector<course>::iterator it = cou.CourSearch('1');
while(it == course::vCou.end()) 


{ 
cout << "\n错误，请重新输入:"; 

it = cou.CourSearch('1');
} 
for(int i = 0; i < (*student::itCurr).nSC; i++)
{ 



if((*it).sNumber == (*student::itCurr).Selcour[i]) 
{ 
for(int j = i; j < (*student::itCurr).nSC-1; j++) 
(*student::itCurr).Selcour[j] = (*student::itCurr).Selcour[j+1]; 
cout << "退选成功!"; 

(*it).nCount--;
(*student::itCurr).Selcour[i] = ""; 
(*student::itCurr).nSC--;
break; 


} 

else 

{ 
cout << "你没有选择该课程!\n重新输入:"; 
it = cou.CourSearch('1');
i = -1; 


}
}
menu::isback(); 


} 

SelCourse::~SelCourse() 
{ 

} 