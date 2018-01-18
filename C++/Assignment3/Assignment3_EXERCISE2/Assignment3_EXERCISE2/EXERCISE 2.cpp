/*

Name: Simple Program to compare vector

File Name: EXERCISE 2.cpp

Copyright: Free

Author: Zhang Junming

Description: ask user input elements for two vector and judge whether they are the same

*/

#include <iostream>
#include <vector>

using namespace std;

bool same_vec(vector<int>a , vector<int>b)
{
	unsigned int n = 0;
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int t1 = 0;
	unsigned int t2 = 0;
	// n i j t1 t2 for counting

	vector<int>x1,x2;// x1 to store the large vector and x2 to store the samll one

	if(a.size()>=b.size())
	{
		t1 = a.size();// t1 store the number of elements of large vector
		t2 = b.size();// t2 store the number of elements of small vector
		x1 = a;
		x2 = b;
	}
	else
	{
		t1 = b.size();
		t2 = a.size();
		x1 = b;
        x2 = a;
	}

	for(n = 0;n < t1; n++)// judge all elements in the large vector
	{
		for(;i < t2; i++)// judge all elements in the samll vector
		{
			if( x1[n] == x2[i] )// two elements are the same
			{
				j = j + 1;
				i = 0;// make sure the next compare begin at the first element
				break;// out this loop now because ignoring the multiplicities
			}
			if( i == (t2 - 1))// there are not same elements in source
			{
				i = 0;
				break;
			}
		}
	}
	if(j == t1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

vector<int> Input_vec(vector<int>&arr)// conveniet to aks user to constuct two vectors
{
	int k = 0;
	
	cout << "Please enter elements of the vector" << endl;
	cout << "Enter 950819 to finish" << endl;// enter 950819 to finish add elements to the first vector
    do
	{
		cout << "Please enter elements" << endl;
		cin >> k;
		arr.push_back(k);
	}
	while(k != 950819);
	arr.pop_back();// delete 950819 at the last of this vector

	cout << "This vector is:" << endl;

	for(unsigned int h = 0;h < arr.size();h++)
	{
	cout << arr[h] << endl;
	}
	return arr;
}

int main(void)
{
	vector<int>a,b;
	Input_vec(a);
	Input_vec(b);
	if(same_vec(a,b))// it will return true or false
	{
		cout << "two of these vector are same" << endl;
	}
	else
	{
		cout << "two of these vector are not same" << endl;
	}
	return 0;
}