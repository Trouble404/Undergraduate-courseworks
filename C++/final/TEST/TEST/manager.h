/* manager.h */
/* ����Ա������ */ 

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
void ManaEdit(char); //����Ա��Ϣ�޸� 
void ManaShow(); //��ʾ����Ա��Ϣ 
manager(); 
~manager();

}; 