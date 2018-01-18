/* course.cpp */
/* 课程类的定义 */

#include "header.h" 
#include "course.h" 
#include "menu.h" 

vector<course> cou_vec; 
vector<course> course::vCou = cou_vec; 

void course::PrintCour(course cou)
{ 
cout << cou.sName << '\t' << cou.sNumber << '\t' << cou.nSlecMax << '\t' << cou.nCount 
<< '\t' << cou.Teacher << '\t' << cou.Place << '\t' << cou.Time << endl; 
} 

void course::CourDele()

{ 
system("cls");
if(vCou.empty())

{ 
cout << "\t\t课程记录个数为零!\n"; 
menu::isback(); 
return ; 


} 
cout << "\n请选择要删除的课程......\n"; 
vector<course>::iterator it = CourSearch('1');//根据课程编号查找课程；i等于-1时没有找到相关课程 
if(it != vCou.end())


{ 
cout << "\n是否删除此课程信息？\n\t1.删除\n\t2.否\n\t3.退出系统\n\n"; 
if(choose('3') == '1')
{ 


vCou.erase(it); 
} 
cout << "删除完成!\n" << endl; 


}
menu::isback();
} 

void course::CourPutin()

{ 
course cou; 
while(1)
{ 

system("cls"); 
cout << "\n现在开始输入信息！\n\n请输入：\n\n"; 
cout << "课程名字:\t"; 
cou.sName = inputString(); 


for(vector<course>::iterator it = vCou.begin(); it != vCou.end(); ) 
{ 
if(cou.sName == (*it).sName)


{ 
cout << "\n该课程已经存在,请重新输入!\n\n课程名字:\t"; 
getline(cin,cou.sName); 



 it = vCou.begin();
}


else 

it++; 
} 


cout << "课程编号:\t"; 
cou.sNumber = inputString(); 


for(vector<course>::iterator it = vCou.begin(); it!= vCou.end();) 
{ 
if(cou.sNumber == (*it).sNumber)


{ 
cout << "该课程编号已经存在!请重新输入:"; 
getline(cin,cou.sNumber);
it = vCou.begin(); 


}

else 

it++; 
} 


cout << "人数上限:\t"; 
cou.nSlecMax = inputNumber(); 


//初始选课人数置0 

cou.nCount = 0; 

cout << "任职老师:\t"; 
cou.Teacher = inputString(); 


cout << "上课地点:\t"; 
cou.Place = inputString(); 


cout << "上课时间:\t"; 
cou.Time = inputString(); 


vCou.push_back(cou); 


cout << "\n\n是否继续录入课程？\n\n\t1.是\n\n\t2.否\n\n\t3.退出系统 \n\n请选择:";//判断是否继续录入课程 

if(choose('3') == '2')

break; 
} 
menu::isback();


} 

void course::CourView()

{ 
system("cls");
if(vCou.empty()) 

{ 
cout << "没有记录课程信息!\n"; 
menu::isback(); 
return ; 


} 
cout << "\n课程信息如下：\n\n"; 
cout << "课程名称\t" << "课程编号\t" << "限选\t" << "已选\t"


 << "老师\t" << "教室\t" << "上课时间" << endl << endl; 

for(vector<course>::iterator it = vCou.begin(); it != vCou.end(); it++)
PrintCour(*it); 
} 

vector<course>::iterator course::CourSearch(char c) 
{ 
if(vCou.empty())

{ 
cout << "没有记录课程信息!"; 
return vCou.end(); 
} 


switch(c) 
{ 



case'1': 

{ 
cout << "\n请输入课程编号:\t"; 
string s = inputString();
for(vector<course>::iterator it = vCou.begin(); it != vCou.end(); it++) 
{ 

if(s == (*it).sNumber)

{ 
PrintCour(*it); 
return it; 


} 
} 
cout << "\n没有找到相关课程!\n"; 
return vCou.end();


} 
case'2': 


{ 
cout << "\n请输入要查询的课程名称:\t"; 
string s = inputString();
for(vector<course>::iterator it = vCou.begin(); it != vCou.end(); it++) 
{ 

if(s == (*it).sName)

{ 
PrintCour(*it); 
return it; 


}
} 
cout << "\n没有找到相关课程!\n"; 
return vCou.end();


} 
case'3': 
{ 


vector<course>::iterator it_temp = vCou.end(); 
cout << "\n请输入要查询的课程任职教师:\t"; 
string s = inputString();
for(vector<course>::iterator it = vCou.begin(); it != vCou.end(); it++) 
{ 


if(s == (*it).Teacher)

{ 
PrintCour(*it);
it_temp = it;


} 
}
if(it_temp == vCou.end())


 cout << "\n没有找到相关课程!\n"; 

return it_temp;
} 
case'4': 
{ 


vector<course>::iterator it_temp = vCou.end(); 
cout << "\n请输入要查询课程的上课时间:\t"; 
string s = inputString();
for(vector<course>::iterator it = vCou.begin(); it != vCou.end(); it++) 
{ 


if(s == (*it).Time) 

{ 
PrintCour(*it);
it_temp = it; 


}
}
if(it_temp == vCou.end()) 


cout << "\n没有找到相关课程!\n"; 
return it_temp;


}
} 
return vCou.end(); 


} 

void course::CourEdit() 

{ 
system("cls");
if(vCou.empty()) 

{ 
cout << "\n\t\t没有记录课程信息!"; 


menu::isback(); 
return ; 
} 


cout << "\n请输入你要修改的课程编号:\n"; 

string s = inputString(); 

vector<course>::iterator it; 
for(it = vCou.begin(); it != vCou.end(); it++)
{ 


if(s == (*it).sNumber) 

break; 
}
if(it == vCou.end()) 


{ 
cout << "\n没有找到相关课程信息\n"; 
menu::isback();
} 


cout << "\n\t当前课程信息\n\n"; 


PrintCour(*it); 


cout << "~~~~~~~现在开始输入更改信息~~~~~~~~~\n\n"; 
cout << "课程名字:\t"; 
(*it).sName = inputString();
for(vector<course>::iterator it_temp = vCou.begin(); it_temp != vCou.end();) 
{ 


if((*it).sName != (*it_temp).sName || it_temp == it)
it_temp++; 


else 

{ 
cout << "该课程已经存在!请重新输入:"; 
(*it).sName = inputString();
it_temp = vCou.begin();


 }
} 


cout << "课程编号:\t"; 
(*it).sNumber = inputString();
for(vector<course>::iterator it_temp = vCou.begin(); it_temp != vCou.end();) 
{ 


if((*it_temp).sNumber != (*it).sNumber || it_temp == it)
it_temp++;

else 

{ 
cout << "该课程编号已经存在!请重新输入:"; 
(*it).sNumber = inputString();
it_temp = vCou.begin();


} 
} 


cout << "人数上限:\t"; 

(*it).nSlecMax = inputNumber();

 cout << "已选人数:\t"; 

(*it).nCount = inputNumber(); 

cout << "任职老师:\t"; 
(*it).Teacher = inputString(); 


cout << "上课地点:\t"; 

(*it).Place = inputString(); 

cout << "上课时间:\t"; 

(*it).Time = inputString(); 

cout << "修改后课程信息为:\n"; 
PrintCour(*it);
menu::isback();


} 

void course::cWriteFile()

{ 
ofstream ocoufile("course.txt",ios::binary); 


if(ocoufile.fail())

{ 
cout << "写入文件时打开课程文件失败!"<<endl;
} 
exit(0); //退出程序 


ocoufile << "/* 格式：课程名 #课程编号#最大选课人数已选课人数老师 #地点#时间# */" << endl; 

for(vector<course>::iterator it = vCou.begin(); it != vCou.end(); it++) 
{ 
ocoufile << (*it).sName << '#' << (*it).sNumber << '#' << (*it).nSlecMax << ' ' 
<< (*it).nCount << ' ' << (*it).Teacher << '#' << (*it).Place << '#' << (*it).Time <<

'#' << endl; 
} 
cout << "\n课程文件保存成功!\n"; 
ocoufile.close();

} 

void course::cReadFile()

{ 
ofstream ocoufile("course.txt",ios::binary|ios::app); 
ocoufile.close();
ifstream icoufile("course.txt",ios::binary);
if(icoufile.fail())

{ 
cout << "读取文件时打开课程文件失败!"<<endl;
} 
exit(0); //退出程序 


char c[N]; 
icoufile.getline(c,N,'/');
icoufile.ignore(100,'\n'); 


course cou; 
while(icoufile.peek() != EOF)
{ 


icoufile.getline(c,N,'#'); 
cou.sName = c; 
icoufile.getline(c,N,'#');
cou.sNumber = c; 
icoufile >> cou.nSlecMax >> cou.nCount; 
icoufile.getline(c,N,'#');
cou.Teacher = c; 
icoufile.getline(c,N,'#'); 
cou.Place = c; 
icoufile.getline(c,N,'#');
cou.Time = c; 
icoufile.ignore(100,'\n'); 


vCou.push_back(cou); 
}
icoufile.close();


} 

course::course()

{ 
sName = ""; 
sNumber = ""; 
Teacher = ""; 
Place = ""; 
Time = ""; 
nSlecMax = 0; 
nCount = 0; 

} 

course::~course() 
{ 

} 
