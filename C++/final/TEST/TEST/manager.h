/* manager.h */
/* 管理员类声明 */ 

#include "header.h" 
#include "student.h" 
#include "course.h" 

class manager

{ 
string sName; 
string sNumber;
string sSex; 


string sPassWord;
int nAge;


public: 
student s; 
course c; 
void mpass(); 
void ManaEdit(char); //管理员信息修改 
void ManaShow(); //显示管理员信息 
manager(); 
~manager();

}; 