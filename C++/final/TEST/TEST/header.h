/* 头文件 */ 

/* header.h */
/* 几个共用的成员和声明 */

#ifndef _HEADER_H 
#define _HEADER_H 

#include <iostream> 
#include <cstdlib> 
#include <string>
#include <vector> 
#include <fstream> 


using namespace std; 

const int N(100); 

char choose(char c); //菜单中的选择函数 
int inputNumber(); //输入数字 
char inputChar(); //输入字符 
string inputString();//输入字符串 


#endif 