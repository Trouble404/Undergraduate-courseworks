/*

Name: Simple Program to convert strings.( Array )

File Name: EXERCISE 1.c

Copyright: Free

Author: Zhang Junming

Description: To store user's first name and last name, then convert last name to capital letters and display user's full name.

*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char Firstname[20];// to store the user¡¯s first name
	char Lastname[20];// to store the user¡¯s last name
	char Fullname[40] = { };//to store the user¡¯s full name and initialize this array
	int i = 0;
	int j = 0;//for connect first name and last name

	cout << "Enter your first name: \n" << endl;
	cin >> Firstname;

	cout << "\nEnter your last name: \n" << endl;
	cin >> Lastname;


    for(;i < strlen(Lastname);i++)
	{
		if(Lastname[i]>='a'&&Lastname[i]<='z')
		Lastname[i] -= 32;// ACSLL: lowercase ¨C 32 = capital letter
		Fullname[i] = Lastname[i];// Store last name in array Fullname
	}

	Fullname[i] = ',';
	Fullname[i+1] = ' ';// Store ¡°,¡± and ¡° ¡° in array Fullname

	j = i + 2;// next location in array Fullname


	for(i = 0;i < strlen(Firstname); i++ )
	{
		Fullname[j++] = Firstname[i];// connect first name and last name
	}

	cout << "\nYour name is: " << Fullname << endl;

	return 0;
}