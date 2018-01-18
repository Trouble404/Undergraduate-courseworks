/*

Name: Simple Program to convert strings. ( String )

File Name: EXERCISE 1.2.c

Copyright: Free

Author: Zhang Junming

Description: To store user's first name and last name, then convert last name to capital letters and display user's full name.

*/

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string Firstname;// to store the user¡¯s first name
	string Lastname;// to store the user¡¯s last name
	string Fullname;// to store the user¡¯s full name
	string Other = ", ";// represents ¡°, ¡° between first name and last name
	int i = 0;// ¨C for setting loop to convert and store letters

	cout << "Enter your first name: \n" << endl;
	cin >> Firstname;

	cout << "\nEnter your last name: \n" << endl;
    cin >> Lastname;

	for(;i<Lastname.length();i++)
	{
		if(Lastname[i]>='a'&&Lastname[i]<='z')
		{
		    Lastname[i] = toupper(Lastname[i]);// toupper() function in library string could convert lowercase to capital letter 
		}
		else 
		{
			Lastname[i] = Lastname[i];
		}
	}

        Fullname = Lastname + Other + Firstname;// Connect string Lastname, Other and Firstname to string Fullname.

		cout << "\nYour name is: " << Fullname << endl;

	return 0;
}