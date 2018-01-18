/*
Name: Simple Program to caculate the square and square root of entered number and count the number of the iteams

File Name: exercise3.c

Copyright: Free

Author: ZhangJunming

Description: Display each entered number's square and square root, when the number is negative, just
display the square and when input 7777, stop this program and display how many items done and how 
many of them are negative
*/

#include <stdio.h>

#include <math.h>/* math.h is a standard C header file which consists of/declares a set
of functions to compute common mathematical operation */

main ()

{

float a,b,c;/* a represents the value of entered number;b,c represent the value of square and square root */

int i=-1,j=0,k=0;/* i,j represent the positive items and negative items; k represent the number of iteams */

do/* circulate the following command when not satisfy the condion on "while" */
{

printf("Enter 7777 to stop\n");

printf("Please enter a digital \n");

scanf("%f",&a);

b=pow(a,2);/* caculate b=a^2 */

c=sqrt(a); /* sqrt computes square root */

if (a!=7777)/* when enter 7777, will not print the square of 7777 */

printf("Square=%f\n",b);

if (a>=0&&a!=7777)

printf("Square root=%f\n",c);

if (a<0&&a!=7777)

printf("Number is negative\n");

if (a>=0)

i=i++;/* number of the iteams */

else

j=j++;/* number of the  negative iteams */

}

while (a!=7777);/* when a is 7777, out this loop */

k=i+j;/* caculate the sum of positive and negative items */

printf("Number of items done=%d Negative items=%d\n",k,j);

system ("pause");/* let result display on programe after running */

return 0;

}

