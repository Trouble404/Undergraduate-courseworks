/************************************************************
*程序说明:
*   本程序采用二进制文件形式存储数据
*   每本图书数据包含如下几方面的信息：
*        主编、出版社、出版年、版次、ISBN书号、书名、定价、拥有本数、借出本数、现余本数、作者。
*
*   程序分为两个大模块
*   
*   要使用本程序首先都要登录
*       登录功能
*   然后再分为:
*   <一>管理员模块:
*       （1）管理员帐号管理:首先要登录,修改需要密码,初始时没有密码要设置密码,找回密码功能
*       （2）向"数据库"添加新的图书信息功能                             //完成
*       （3）借出功能:可以批量借出                                     //完成(还可完善)
*       （4）归还功能:可以批量归还                                     //完成(还可完善)
*       （5）显示数据库所有图书信息                                     //完成
*       （6）查找功能:按需要查找的项查找"数据库"                        //完成
*       （7）修改指定的图书的信息功能                                   //完成
*       （8）从“数据库”中删除指定的图书记录                             //完成(还可完善)
*       （9）退出程序                                                  //完成
*   <二>学生模块:
*       （1）注册功能:初次使用需要注册,包括设置用户名,密码,找回密码的问题及问题的答案
*       （2）帐号管理功能:首先已登录,修改要输入密码,忘记密码可以根据设置的问题可以找回
*       （3）借出功能:可以批量借出                                     //完成(还可完善)
*       （4）归还功能:可以批量归还                                     //完成(还可完善)
*       （5）查找功能:按需要查找的项查找"图书馆数据库"                   //完成
*       （6）退出程序                                                   //完成
*
*    程序文件结构:
*
***************************************************************/

#include "LibBooksMana.h"

char userInfodb[11]="userInfoDB";//用户注册信息存储文件, 戏称"用户注册数据库"
char fdb[10]="database";//程序数据存储文件(二进制),在此戏称为 "数据库"

/*
主函数
*/
void main()
{
	printf("\n");
	printf("\t\t*****************************************\n");
	printf("\t\t*               这是一个                *\n");
	printf("\t\t*      图书馆图书基本信息管理软件       *\n");
	printf("\t\t*       可以对图书馆图书进行管理        *\n");
	printf("\t\t*           欢迎使用管理程序            *\n");
	printf("\t\t*****************************************\n");
	printf("\n");
	handle_menu();
     //userRegister();
}
