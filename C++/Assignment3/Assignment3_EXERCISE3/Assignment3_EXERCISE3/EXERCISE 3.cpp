/*

Name: Simple Program to serach the address of objective string in source string

File Name: EXERCISE 3.cpp

Copyright: Free

Author: Zhang Junming

Description: ask user input the source string and objective string and then search whether there are the same letters in source string and return the address of it

*/

#include <iostream>
#include <string>

using namespace std;

char *findC (char const *source , char const *obj)
{
	int i = 0;
	int j = 0;
	int k = 0;// judge to return which type
	char *term;// store the address of matched first letter in source string

	while(obj[j] != '\0')// counting how many letters in objective string
	{
		j++;
	}

	while(source[i] != '\0')
	{
		if(j == 1)// do not need to consider the order
		{
		  if(obj[0] == source[i])// match objective string in one letter in source successful
		  {
			  k = 1;
			  term = (char*)source[i];// store the address of this matched letter in source string
			  break;
		  }
		  else
		  {
			  i++;// keep searcing
		  }
	    }

		if(j>1)// consider the order
		{
			 if((obj[0] == source[i])&&(obj[1] == source[i+1]))// two letters in source string are total same as objective string
		  {
			  k = 1;
			  term = (char*)source[i];
			  break;
		  }
		  else
		  {
			  i++;
		  }
	     }
	}
	if( k == 1)// match successful
	{
		return term;
	}
	else
	{
		return NULL;
	}
}

int main(void)
{
	string source1;// using string is easy to store the letters which user entered
	string obj1;
	cout << "Please enter the strings of source" << endl;
	cin >> source1;
	cout << "Please enter the strings of objective" << endl;
	cin >> obj1;
	const char* source = source1.c_str();// convert the string type to const char* type
	const char* obj = obj1.c_str();      // because the header function findC is (char const*source,char const*obj)

	if(findC(source,obj)!=NULL)
	{
	    printf("returned pointer is %c\n", findC(source,obj));// display the value which store in the return address
	}
	else
	{
		cout << "NULL" << endl;
	}

	return 0;
}
