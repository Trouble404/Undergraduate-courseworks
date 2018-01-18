/*
Name: Simple Program for creat a shaple using letters.

File Name: exercise2.c

Copyright: Free

Author: Zhang Junming

Description: Choose two characters, then create a rhombus using these two characters.
*/
#include<stdio.h>
char info()/* declar a defined function info */
{
char z[666];/* It can store 667 characters in 'z' */
printf("Please enter a letter(A-Z): ");
scanf("%s",&z);
return(z[0]);/* only return the first character */
}
int shape(char a,char b)/* declar a defined function shape */
{
int i,j;
for(i=1;i<=7;i++)
{
for(j=1;j<=7;j++)
{
if(((i==1||i==7)&&j==4)||((i==2||i==6)&&(j==3||j==5))||((i==3||i==5)&&(j==2||j==6))||(i==4&&(j==1||j==7)))
printf("%c",a);/* The edge of rhombus */
else
if((i+j<=4)||(i+j>=12)||((j-i<=6)&&(j-i>=4))||((i-j<=6)&&(i-j>=4)))
printf("%c",b);/* The part which surround this rhombus */
else
printf(" ");/* The part which in this rhombus */
}
printf("\n");
}
}
int main()
{
char a,b;
printf("Only the first letter is effective \n\n");
a=info();/* Using defined function info */
printf("\n");
b=info();
printf("\n");
printf("Diamond shape of the letters: \n\n");
shape(a,b);/* Using defined function shape */
printf("\n");
system("pause");/* Let this shape display on screen after running */
}

