/*
Name: Simple Program for input and output the information about name and ID number
File Name:exercise1.c
Copyright:Free
Author: Zhang Junming
Description:To ask user to input name and student ID number, then display the name and ID number on screen
*/
#include <stdio.h>
main ()
{
char name[30];/* declare variables of name and store name[0] to name[30] total 30 characters */
int ID_number;
printf("please enter your name\n");
gets(name);/* ask user to input characters of name and store the value of named characters */ 
printf("please enter your ID number\n");
scanf("%d",&ID_number);
printf("your name is %s\n",name);
printf("your ID number is %d\n",ID_number);
system("pause");/* let result always display on programe after running */
}

