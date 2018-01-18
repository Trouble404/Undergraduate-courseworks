/*
Name: Simple Program to check strings.

File Name: exercise1.c

Copyright: Free

Author: Zhang Junming

Description: Check srtings, if all of the characters are lower case letters,display 1,
             if any of the characters are not lower case letters,display 0.
*/
#include <stdio.h>
#include <ctype.h>/* C character classification functions */
char is_loweralpha(char *str)/* declare defined function is_loweralpha */
{
int i,j=0;/* for count number of characters and lower letters */
printf("Please enter letters\n");
gets(str);/* read and store characters in str */
for(i=0;str[i]!='\0';i++)/* In the C programming language every string is terminated by a '\0' */
{/* i could count how many characters in str */
if(islower(str[i]))/* islower could check lower letters in str */ 
j=j++;/* j could count how many lower letters in str */
}
if(i==j)/* it mean that all characters are lower letters */
return 1;
else
return 0;
}
int main()
{
char a[666666];
int b;
printf("This program will check letters\n");/* explain the function of this program */
printf("If all of the characters are lower case letters (a-z)\n");
printf("Display number 1\n");
printf("If any of the characters are not the lower case letters (a-z)\n");
printf("Display number 0\n\n");
b=is_loweralpha(a);/* use defined function */
if(b==1)
printf("%d : all of the characters are lower case letters\n",b);
if(b==0)
printf("%d : any of the characters are not lower case letters\n",b);
system("pause");/* Let this shape display on screen after running */
return 0;
}

