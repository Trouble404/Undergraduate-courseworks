/*
Name: Simple Program for calculate the sum of the entered number's odd and even digits.

File Name: exercise1.c

Copyright: Free

Author: ZhangJunming

Description: Calculate and display the sum of the odd and even number for entered intger
*/

#include <stdio.h>

main ()

{

int a,b,c,d,e;/* a represent the integer number;b represent the sum of even numbers;c represents the sum of odd numbers.
d represents the entered number(for get value of each digital);e represents the remainder */

int i,j;/* i&j represents the numerical digit and count the numercal digit */

printf(" Please enter a digital \n");

printf(" If this number is not a natural number within tens digit \n");

printf(" This program will automatically end \n");

printf(" Please enter the value of digital \n");/* let user known that entered number cannot over tens digit */

scanf("%d",&a);

if (a>=0&&a<=999999999)/* limit the intger within tens digit */

d=a;

else

return 0;

for (i=1;i<10;)/* judge the numerical digit within tens digit */

{

a=a/10;/* reduce one numerical digit */

if (a==0)

break;

else

i=i++;

}

b=0;

c=0;

for (j=1;j<=i;j++)/* i represent the intger's digits */

{

e=d%10;/* get the number of each digits */

d=d/10;

if (e%2==0)/* judge this number should plues in even or odd, if the remainder is 0, then the number is even */

b=b+e;

else

c=c+e;

}

printf(" The sum of even number is %d \n",b);

printf(" The sum of odd number is %d \n",c);

system ("pause");/* let result display on programe after running */

return 0;

}

