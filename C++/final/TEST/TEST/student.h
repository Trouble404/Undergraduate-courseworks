/* student.h */
/* 学生类的声明 */ 

#ifndef _STUDENT_H 
#define _STUDENT_H 

#include "header.h" 

class student 

{ 
string sNumber; //学号 
string sName; //姓名 
string sPassword; //密码 
string sSex; //性别 
string classID; //班级 
int nAge; //年龄 
int nSC; //已选课程数 
string Selcour[4]; //选课编号,限选4门课 


public: 
static vector<student>::iterator itCurr; //当前学生序号 
static vector<student> vStu; //记录学生信息 


void pass(); //学生登入 
void StuEdit(char c); //信息修改 
void ShowSelf(student stu); //显示信息 
void sReadFile(); //读取文件 
void sWriteFile(); //写入文件 
vector<student>::iterator StuSearch(char c); //查询 
void StuPutin(); //录入 
void StuDelete(); //删除 
void StuView(); //浏览 
friend class SelCourse; 
student();
~student();

}; 

#endif