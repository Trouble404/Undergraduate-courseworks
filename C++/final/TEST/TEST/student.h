/* student.h */
/* ѧ��������� */ 

#ifndef _STUDENT_H 
#define _STUDENT_H 

#include "header.h" 

class student 

{ 
string sNumber; //ѧ�� 
string sName; //���� 
string sPassword; //���� 
string sSex; //�Ա� 
string classID; //�༶ 
int nAge; //���� 
int nSC; //��ѡ�γ��� 
string Selcour[4]; //ѡ�α��,��ѡ4�ſ� 


public: 
static vector<student>::iterator itCurr; //��ǰѧ����� 
static vector<student> vStu; //��¼ѧ����Ϣ 


void pass(); //ѧ������ 
void StuEdit(char c); //��Ϣ�޸� 
void ShowSelf(student stu); //��ʾ��Ϣ 
void sReadFile(); //��ȡ�ļ� 
void sWriteFile(); //д���ļ� 
vector<student>::iterator StuSearch(char c); //��ѯ 
void StuPutin(); //¼�� 
void StuDelete(); //ɾ�� 
void StuView(); //��� 
friend class SelCourse; 
student();
~student();

}; 

#endif