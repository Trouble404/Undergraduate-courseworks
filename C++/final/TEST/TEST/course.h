/* course.h */
/* �γ�������� */ 

#ifndef _COURSE_H 
#define _COURSE_H 

#include "header.h" 

class course 


{ 
string sName; //���� 
string sNumber; //��� 
string Teacher; //��ʦ 
string Place; //�ص� 
string Time; //ʱ�� 
int nSlecMax; //ѡ���������� 
int nCount; //��ѡ������ 


public: 
static vector<course> vCou; //��¼�γ���Ϣ 


void CourPutin(); //¼�� 
void CourView(); //��� 
vector<course>::iterator CourSearch(char c); //���� 
void CourEdit(); //�޸� 
void CourDele(); //ɾ�� 
void cReadFile(); //�����ļ� 
void cWriteFile(); //д���ļ� 
void PrintCour(course cou); //��ӡ�γ���Ϣ 
friend class SelCourse; 
course();
~course();

}; 

#endif 