/*
Name: Simple Program to show all possible situations while 2,5,10 pence obtan 2 pounds and how many situations are.

File Name: exercise2.c

Copyright: Free

Author: ZhangJunming

Description: prints out all different possibilities of obtaining 2 pounds using 
coins of values 2 pence, 5 pence, and 10 pence. Indicate also how many possibilities have 
been found
*/

#include<stdio.h>

main ()

{

int a,b,c,i=0;/* a,b,c represent the amounts of 2 pence,5 pence and 10; i for statistics all possible answers */
 
for (a=0;a<=100;a++)/* a loop to circulate all possible 2 pence's amount */

for (b=0;b<=40;b++)/* a loop to circulate all possible 5 pence's amount */

for (c=0;c<=20;c++)/* a loop to circulate all possible 10 pence's amount */

{

if (200==2*a+5*b+10*c)/* the limiting condions (the relationship of a,b,c) */

printf("2Pounds = %d*2P + %d*5P + %d*10P \n",a,b,c);

if (200==2*a+5*b+10*c)

i=i++;/* statistics all requried answers */

}

printf("In total,there are %d possibilities to make 2 pounds \n",i);

system ("pause");/* let result display on programe after running */

return 0;

}

