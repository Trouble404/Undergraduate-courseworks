/* course.cpp */
/* �γ���Ķ��� */

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
cout << "\t\t�γ̼�¼����Ϊ��!\n"; 
menu::isback(); 
return ; 


} 
cout << "\n��ѡ��Ҫɾ���Ŀγ�......\n"; 
vector<course>::iterator it = CourSearch('1');//���ݿγ̱�Ų��ҿγ̣�i����-1ʱû���ҵ���ؿγ� 
if(it != vCou.end())


{ 
cout << "\n�Ƿ�ɾ���˿γ���Ϣ��\n\t1.ɾ��\n\t2.��\n\t3.�˳�ϵͳ\n\n"; 
if(choose('3') == '1')
{ 


vCou.erase(it); 
} 
cout << "ɾ�����!\n" << endl; 


}
menu::isback();
} 

void course::CourPutin()

{ 
course cou; 
while(1)
{ 

system("cls"); 
cout << "\n���ڿ�ʼ������Ϣ��\n\n�����룺\n\n"; 
cout << "�γ�����:\t"; 
cou.sName = inputString(); 


for(vector<course>::iterator it = vCou.begin(); it != vCou.end(); ) 
{ 
if(cou.sName == (*it).sName)


{ 
cout << "\n�ÿγ��Ѿ�����,����������!\n\n�γ�����:\t"; 
getline(cin,cou.sName); 



 it = vCou.begin();
}


else 

it++; 
} 


cout << "�γ̱��:\t"; 
cou.sNumber = inputString(); 


for(vector<course>::iterator it = vCou.begin(); it!= vCou.end();) 
{ 
if(cou.sNumber == (*it).sNumber)


{ 
cout << "�ÿγ̱���Ѿ�����!����������:"; 
getline(cin,cou.sNumber);
it = vCou.begin(); 


}

else 

it++; 
} 


cout << "��������:\t"; 
cou.nSlecMax = inputNumber(); 


//��ʼѡ��������0 

cou.nCount = 0; 

cout << "��ְ��ʦ:\t"; 
cou.Teacher = inputString(); 


cout << "�Ͽεص�:\t"; 
cou.Place = inputString(); 


cout << "�Ͽ�ʱ��:\t"; 
cou.Time = inputString(); 


vCou.push_back(cou); 


cout << "\n\n�Ƿ����¼��γ̣�\n\n\t1.��\n\n\t2.��\n\n\t3.�˳�ϵͳ \n\n��ѡ��:";//�ж��Ƿ����¼��γ� 

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
cout << "û�м�¼�γ���Ϣ!\n"; 
menu::isback(); 
return ; 


} 
cout << "\n�γ���Ϣ���£�\n\n"; 
cout << "�γ�����\t" << "�γ̱��\t" << "��ѡ\t" << "��ѡ\t"


 << "��ʦ\t" << "����\t" << "�Ͽ�ʱ��" << endl << endl; 

for(vector<course>::iterator it = vCou.begin(); it != vCou.end(); it++)
PrintCour(*it); 
} 

vector<course>::iterator course::CourSearch(char c) 
{ 
if(vCou.empty())

{ 
cout << "û�м�¼�γ���Ϣ!"; 
return vCou.end(); 
} 


switch(c) 
{ 



case'1': 

{ 
cout << "\n������γ̱��:\t"; 
string s = inputString();
for(vector<course>::iterator it = vCou.begin(); it != vCou.end(); it++) 
{ 

if(s == (*it).sNumber)

{ 
PrintCour(*it); 
return it; 


} 
} 
cout << "\nû���ҵ���ؿγ�!\n"; 
return vCou.end();


} 
case'2': 


{ 
cout << "\n������Ҫ��ѯ�Ŀγ�����:\t"; 
string s = inputString();
for(vector<course>::iterator it = vCou.begin(); it != vCou.end(); it++) 
{ 

if(s == (*it).sName)

{ 
PrintCour(*it); 
return it; 


}
} 
cout << "\nû���ҵ���ؿγ�!\n"; 
return vCou.end();


} 
case'3': 
{ 


vector<course>::iterator it_temp = vCou.end(); 
cout << "\n������Ҫ��ѯ�Ŀγ���ְ��ʦ:\t"; 
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


 cout << "\nû���ҵ���ؿγ�!\n"; 

return it_temp;
} 
case'4': 
{ 


vector<course>::iterator it_temp = vCou.end(); 
cout << "\n������Ҫ��ѯ�γ̵��Ͽ�ʱ��:\t"; 
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


cout << "\nû���ҵ���ؿγ�!\n"; 
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
cout << "\n\t\tû�м�¼�γ���Ϣ!"; 


menu::isback(); 
return ; 
} 


cout << "\n��������Ҫ�޸ĵĿγ̱��:\n"; 

string s = inputString(); 

vector<course>::iterator it; 
for(it = vCou.begin(); it != vCou.end(); it++)
{ 


if(s == (*it).sNumber) 

break; 
}
if(it == vCou.end()) 


{ 
cout << "\nû���ҵ���ؿγ���Ϣ\n"; 
menu::isback();
} 


cout << "\n\t��ǰ�γ���Ϣ\n\n"; 


PrintCour(*it); 


cout << "~~~~~~~���ڿ�ʼ���������Ϣ~~~~~~~~~\n\n"; 
cout << "�γ�����:\t"; 
(*it).sName = inputString();
for(vector<course>::iterator it_temp = vCou.begin(); it_temp != vCou.end();) 
{ 


if((*it).sName != (*it_temp).sName || it_temp == it)
it_temp++; 


else 

{ 
cout << "�ÿγ��Ѿ�����!����������:"; 
(*it).sName = inputString();
it_temp = vCou.begin();


 }
} 


cout << "�γ̱��:\t"; 
(*it).sNumber = inputString();
for(vector<course>::iterator it_temp = vCou.begin(); it_temp != vCou.end();) 
{ 


if((*it_temp).sNumber != (*it).sNumber || it_temp == it)
it_temp++;

else 

{ 
cout << "�ÿγ̱���Ѿ�����!����������:"; 
(*it).sNumber = inputString();
it_temp = vCou.begin();


} 
} 


cout << "��������:\t"; 

(*it).nSlecMax = inputNumber();

 cout << "��ѡ����:\t"; 

(*it).nCount = inputNumber(); 

cout << "��ְ��ʦ:\t"; 
(*it).Teacher = inputString(); 


cout << "�Ͽεص�:\t"; 

(*it).Place = inputString(); 

cout << "�Ͽ�ʱ��:\t"; 

(*it).Time = inputString(); 

cout << "�޸ĺ�γ���ϢΪ:\n"; 
PrintCour(*it);
menu::isback();


} 

void course::cWriteFile()

{ 
ofstream ocoufile("course.txt",ios::binary); 


if(ocoufile.fail())

{ 
cout << "д���ļ�ʱ�򿪿γ��ļ�ʧ��!"<<endl;
} 
exit(0); //�˳����� 


ocoufile << "/* ��ʽ���γ��� #�γ̱��#���ѡ��������ѡ��������ʦ #�ص�#ʱ��# */" << endl; 

for(vector<course>::iterator it = vCou.begin(); it != vCou.end(); it++) 
{ 
ocoufile << (*it).sName << '#' << (*it).sNumber << '#' << (*it).nSlecMax << ' ' 
<< (*it).nCount << ' ' << (*it).Teacher << '#' << (*it).Place << '#' << (*it).Time <<

'#' << endl; 
} 
cout << "\n�γ��ļ�����ɹ�!\n"; 
ocoufile.close();

} 

void course::cReadFile()

{ 
ofstream ocoufile("course.txt",ios::binary|ios::app); 
ocoufile.close();
ifstream icoufile("course.txt",ios::binary);
if(icoufile.fail())

{ 
cout << "��ȡ�ļ�ʱ�򿪿γ��ļ�ʧ��!"<<endl;
} 
exit(0); //�˳����� 


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
