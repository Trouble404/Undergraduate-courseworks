/* course.h */
/* 课程类的声明 */ 

#ifndef _COURSE_H 
#define _COURSE_H 

#include "header.h" 

class course 


{ 
string sName; //名字 
string sNumber; //编号 
string Teacher; //老师 
string Place; //地点 
string Time; //时间 
int nSlecMax; //选课人数上限 
int nCount; //已选课人数 


public: 
static vector<course> vCou; //记录课程信息 


void CourPutin(); //录入 
void CourView(); //浏览 
vector<course>::iterator CourSearch(char c); //查找 
void CourEdit(); //修改 
void CourDele(); //删除 
void cReadFile(); //读入文件 
void cWriteFile(); //写入文件 
void PrintCour(course cou); //打印课程信息 
friend class SelCourse; 
course();
~course();

}; 

#endif 