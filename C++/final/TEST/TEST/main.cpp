/* main.cpp */
/* 主函数 */

#include "header.h" 
#include "student.h" 
#include "course.h" 
#include "menu.h" 

char choose(char i) 

{ 
char c; 
cin >> c; 
cin.ignore(100,'\n');
while(c < '1' || c > i)

{ 
cout << "输入错误!\t重新输入: "; 
cin >> c; 
cin.ignore(100,'\n');


}
while(c == i) 
{ 


student st; 
st.sWriteFile(); 
course co; 
co.cWriteFile();
exit(0);


 } 
return c; 
} 

int 
inputNumber()

{ 
int temp,temp1; 
temp1 = scanf_s("%d",&temp);
cin.ignore(100,'\n');
while(temp1 == 0) 

{ 
cout << "输入错误!需输入数字!\n重新输入: "; 
cin.ignore(100,'\n');
temp1 = scanf_s("%d",&temp);

} 
return temp;
} 

char inputChar()

{ 
char c = cin.get(); 
cin.ignore(100,'\n'); 
return c; 

} 

string inputString()
{ 
string s; 


getline(cin,s); 
return s; 
} 

int main()

{ 
menu::SelWho(); 
return 0; 

} 
