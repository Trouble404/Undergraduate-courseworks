/*
Name: Simple Program for calculate polynomial

File Name: exercise1.c

Copyright: Free

Author: Zhang Junming

Description: Input four parameters a,b,c,x, then display the result of this polynomial
*/

#include <stdio.h>
double f(double a, double b, double c, double x)/* declare defined function f */
{
double sum;/* double mean double precision */
sum=a*x*x + b*x + c;/* required polynomial a,b,c,x are variables */
return (sum);/* return calling funtion */
}
main ()
{
double a,b,c,x,sum;
printf(" Please enter a: ");
scanf("%lf",&a);/* when using 'double' define , use '%lf'long float */
printf("\n");
printf(" Please enter b: ");
scanf("%lf",&b);
printf("\n");
printf(" Please enter c: ");
scanf("%lf",&c);
printf("\n");
printf(" Please enter x: ");
scanf("%lf",&x);
printf("\n");
sum=f(a,b,c,x);/* using defined function f */
printf(" The polynomial %lf*x^2 + %lf*x + %lf at the point x=%lf is %lf ",a,b,c,x,sum);
}

