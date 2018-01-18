/*
Name: Simple Program to caculate the circel's area.
File Name: exercise3.c
Copyright: Free
Author: Zhang Junming
Description: Compute and display the area based on a given radius.
*/
#include <stdio.h>
#define PI 3.1416 /* define the 'PI' is 3.1416.*/ 
main ()
{
float r,Area;/* declare two variables of the type of float namely r and Area */
printf("Please enter the length of r\n");/* ask user to input a real number representing the radius.*/
scanf("%f",&r);/*store the value of entered r*/
Area=PI*r*r;/* the formula of circle's area*/
printf("the area is:%f\n",Area);/*display the value of area*/
system("pause");/*let result always display on programe after running*/
}

