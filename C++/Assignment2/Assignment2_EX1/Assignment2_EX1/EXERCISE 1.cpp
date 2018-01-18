/*

Name: Simple Program to display the full name of months

File Name: EXERCISE 1.cpp

Copyright: Free

Author: Zhang Junming

Description: Input the integer and first three letters of month, and the program will display the full name of the month

*/

#include <iostream>
#include <string>

using namespace std;

class Month
{
   private:
	   int month; // represent the month(1 for January......12 for December)
   public:
	   Month();
	   void SetMonthOf3Letters( string l1 , string l2 , string l3 );// l1,l2,l3 represent the first three letters of month
	   void SetMonthOfInt( int Month );
	   void InputAndReadMonthAsInt ();
	   void InputAndReadMonthAs3Letters ();
	   void OutputMonth ();
	   Month next()
	  {
        Month t;
        if(month == 11) // 11 represent December
		{
			t.month = 0; // 0 represent January
		}
        else 
		{
			t.month = month + 1; // next month
		}
        return t;
      }
			   
};

Month :: Month()
{
	month = 0;
}

void Month :: SetMonthOf3Letters ( string l1, string l2 , string l3 )
{
	string l[12] = {"Jan","Feb","Mar","Apr","May","Jun",
		            "Jul","Aug","Sep","Out","Nov","Dec"};
	string l4 = l1 + l2 + l3; // l4 represent the connection of the first three letters
	int k = 0;
	for(; k < 12 ; k++)
	{
		if( l4 == l[k] ) // the first three letters match the right value
		{
			month = k; // k represent the integer of the right month
		}
	}
}

void Month :: SetMonthOfInt ( int Month )
{
	month = Month - 1; // 0~11 for month but user input 1~12 represent month
}

void Month :: InputAndReadMonthAsInt()
{
	int n;
	cout << "Please enter the number\n" << endl;
	cin >> n;

		month = n - 1;
}

void Month :: InputAndReadMonthAs3Letters ()
{
	string L[12] = {"Jan","Feb","Mar","Apr","May","Jun",
		            "Jul","Aug","Sep","Out","Nov","Dec"};
	string L1 , L2 , L3 , L4;

	do
	{
	cout << "Please enter the first letter(capital) in the name of the month\n" << endl;
	cin >> L1;
	if(L1.length() != 1)
	{
		cout << "just enter one letter, first letter must be capital letter " << endl;
	}
	}
	while(L1.length() != 1);// limit user enter one letter for once

	do
	{
	cout << "Please enter the first letter in the name of the month\n" << endl;
	cin >> L2;
	if(L2.length() != 1)
	{
		cout << "just enter one letter " << endl;
	}
	}
	while(L2.length() != 1);

	do
	{
	cout << "Please enter the third letter in the name of the month\n" << endl;
	cin >> L3;
	if(L3.length() != 1)
	{
		cout << "just enter one letter " << endl;
	}
	}
	while(L3.length() != 1);

	L4 = L1 + L2 + L3;//connect the first three letters togather

	int i = 0;
	int n = 0;
	for(; i < 12 ; i++)
	{
		if( L4 == L[i] )
		{
			month = i;
		}
		else
		{
			n = n + 1;// for counting
		}
	}
	if( n == 12 )// when n equal to 12 represent the program match the month fail
	{
		month = 13; // in output function,if month > 12, program will tell user there have problem
	}
}

void Month :: OutputMonth()
{
	string Fullname[12] = {"January","February","March","April","May","June",
		                   "July","August","Septmber","Outtober","November","December"};
	if( month >= 0 && month < 12)// it mean match the right month
	{
	cout << " \nNow, the month is: " << Fullname[month] << endl;
	}
	else// not match the right month
	{
	cout << "\nenter error please check " << endl;
	}
}



int main(void)
{

	int j = 0;
	// aims in this assignment, give convenience to test
	cout << "task 1: constructor to set the month using the first three letters in the name of the month as three arguments\n" << endl;
	cout << "task 2: constructor to set the month using an integer as an argument\n" << endl;
	cout << "task 3: A default constructor\n" << endl;
	cout << "task 4: An input function that reads the month as an integer\n" << endl;
	cout << "task 5: An input function that reads the month as the first three letters in the name of the month\n" << endl;
	cout << "task 6: An output function that outputs the month as the whole name of the month\n" << endl;
	cout << "task 7: A member function that returns the next month as a value of type Month\n" << endl;
	cout << "8-quit\n" << endl;

	do
	{
	cout << "Please choose the task number!\n" << endl;
	int chioce = 0;
	cin >> chioce;
	switch(chioce)
	{
	case 1:{ Month test1;
		     test1.SetMonthOf3Letters("J","a","n");// for test, here I enter Jan to test 3 letters constructor
			 test1.OutputMonth();
			 break;
		   }

	case 2:{ Month test2;
		     test2.SetMonthOfInt(10);// for test, here I enter 10 to test integer constructor
			 test2.OutputMonth();
			 break;
		   }

	case 3:{ Month test3;// default constructor
		     test3.OutputMonth();
			 break;
		   }

	case 4:{ Month test4;
		     test4.InputAndReadMonthAsInt();
			 test4.OutputMonth();
			 break;
		   }

	case 5:{ Month test5;
		     test5.InputAndReadMonthAs3Letters();
			 test5.OutputMonth();
			 break;
		   }

	case 6:{ cout << "None!" << endl;break;}// output function, no test for it

	case 7:{ Month test7,test8;
		     test7.SetMonthOf3Letters("J","a","n");// test the next month function and the I set January to the first month
			 test8 = test7.next();
			 test8.OutputMonth();
			 break;
		   }
	case 8:{ j = 1;
		    break;}
	}
	}
	while( j == 0 );
	

	return 0;
}