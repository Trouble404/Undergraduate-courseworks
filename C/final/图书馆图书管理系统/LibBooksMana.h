#ifndef H_STUDENT_HH
#define H_STUDENT_HH

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>

typedef struct book_info
{
	char name[60];//书名 -- 索引
	char ISBN[30];//ISBN号 -- 索引
	char author[60];//作者 -- 索引
	char editor[60];//主编 -- 索引
	char publisher[50];//出版社 -- 索引
	char publishYear[18];//出版年 -- 索引
	char printOrder[60];//版次
	char price[10];//价格
	unsigned long totalNum;//图书总数
	unsigned long lendNum;//借出本数
	unsigned long retainNum;//现余本数
};

/*
用户信息结构体
*/
typedef struct User
{
	char name[60];//昵称
	char pwd[30];//密码
	char pwdIssue[20];//找回密码的问题:统一设置问题为"我的真实名字是:"
	char pwdAnswer[40];//密码问题的答案
};

extern char userInfodb[11];//用户注册信息存储文件, 戏称"用户注册数据库"
extern char fdb[10];//程序数据存储文件(二进制),在本程序中简称"数据库"

//operateDB.cpp文件
void reinstAllRecInDB();//重置数据库所有数据,重新设置记录(调试或第一次初始化时用)
void AddRecToDB();//向数据库添加记录(管理员模块)
void readAndDisAllRecInDB();//显示数据库所有记录信息
int findRecInDB(int ith,int way,char str[60]);//在数据库中查找指定记录(中间函数)
void alterAndSaveRecToDB(int ith);//在数据库中修改并保存一条指定记录

//operate.cpp文件
void showTable(void);//输出表头
void printinfo(book_info *book);//打印指定记录的详细信息
void queryInput(char str[],int &way);//查询选择输入辅助函数
int initialQueRec(int fsite[]);//初步查询函数
int exactSearchRec();//精确查找
void alterRecInDB();//修改一条指定记录
void lendBookAdm();//借出图书:向指定的用户借出图书  
void revertBookAdm();//归还图书:特定的用户归还图书
void delRec();//删除指定的图书记录(管理员)

//usersControl.cpp
int findRecInUDB(char name[]);//在userInfoDB中遍历查询指定的昵称的记录
int login();//用户登录
void userRegister();//新用户注册
void userInfoGovern(int ith);//用户帐号管理

//menu.cpp文件
void initializeSoftware();//程序初始化
void handle_menu(void);//菜单处理
int menu_select(int stuOrAdm);//菜单选择

#endif