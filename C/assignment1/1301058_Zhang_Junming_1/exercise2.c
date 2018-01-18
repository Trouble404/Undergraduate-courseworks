/*
Name:simple program to convert a temperature in Fahrenheit to Celsius degrees.
File Name: exercise2
Copyright: Free
Author: Zhang Junming
Description: Transform and display the temperature in Fahrenheit to Celsius degrees.
*/
#include <stdio.h>
main ()
{
float Fahrenheit,Celsius;/* declare two variables of the type of float namely Fahrenheit and Celsius. */
printf("Please enter the value of temperature in Fahrenheit\n");/* ask user to input a real number representing the Fahrenheit */
scanf("%f",&Fahrenheit);/*store the value of Fahrenheit*/
printf("The temperature in Fahrenheit is %f degree\n",Fahrenheit);
Celsius=(Fahrenheit-32)*5/9;/* the transform formula of Celsius and Fahrenheit*/
printf("The temperature in Celsius is %f degree\n",Celsius);
system("pause");/*let result always display on programe after running*/
}

