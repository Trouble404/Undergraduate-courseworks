/*

Name: Simple Program to set date

File Name: EXERCISE 1.cpp

Copyright: Free

Author: Zhang Junming

Description: construct Date and the date could compare and display the next date

*/

#include <iostream>
#include <string>

using namespace std;

class Date
{
   private:
	   int month;// represent a month
	   int day;// represent one day
   public:
       Date();// default constructor
	   void SetDate( string l1 , int Day );// normal constructor
	   ~Date();// destructor
	   void Display();
	   Date operator =(Date a);// assign the value of one Date object to the other
	   bool operator >(Date a);// judge the first Date bigger than the second is true or false
	   bool operator <(Date a);// judge the first Date smaller than the second is true or false
	   bool operator ==(Date a);// judge the first Date equal to the second is true or false
	   Date operator ++();// return the next day of given date
};

Date::Date()
{
	month = 0;
	day = 1;
}

void Date::SetDate( string l1 , int Day )
{
	string l[12] = {"Jan","Feb","Mar","Apr","May","Jun",
		            "Jul","Aug","Sep","Out","Nov","Dec"};// for match the month which user input
	int k = 0;
	for(; k < 12 ; k++)
	{
		if( (l1 == l[k])&&(Day>0&&Day<32) ) // the first three letters match the right value and the day between 1 to 31
		{
			month = k; // k represent the integer of the right month
			day = Day;
		}
	}
}

Date::~Date()// free memory after display
{
	cout << "destructor successful!" << endl;
}

void Date::Display()
{
	string Fullname[12] = {"January","February","March","April","May","June",
		                   "July","August","Septmber","Outtober","November","December"};
	// Jan->31 Feb->28 Mar->31 Apr->30 May->31 Jun->30 Jul->31 Aug->31 Sep->30 Oct->31 Nov->30 Dec->31
	if( (((month==0)||(month==2)||(month==4)||(month==6)||(month==7)||(month==9)||(month==11))&&(day>0 && day<32)) || (((month==3)||(month==5)||(month==8)||(month==10))&&(day>0&&day<31)) || ((month==1)&&(day>0&&day<29)) )
	{
	cout << " \nThe date is: " << Fullname[month] << " " << day << "th" << endl;
	}
	else// not match the right month or day
	{
	cout << "\nenter error please check " << endl;
	}
}

Date Date::operator =(Date a)
{
	month = a.month;
	day = a.day;
	return a;
}

bool Date::operator >(Date a)
{
	if((month > a.month)||((month == a.month)&&(day > a.day)))// compare month first, if cannot get result thourgh it, compare day of them
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::operator <(Date a)
{
	if((month < a.month)||((month == a.month)&&(day < a.day)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::operator ==(Date a)
{
	if((month == a.month)&&(day == a.day))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Date Date::operator ++()
{
	Date a;
	day= day++;
	if( ((month==0)||(month==2)||(month==4)||(month==6)||(month==7)||(month==9))&&(day>31))// the month which have 31 days per month except Dem
	{
		month = month++;
		day = 1;// when come to next month,it will become the first day
	}
	if( ((month==3)||(month==5)||(month==8)||(month==10))&&(day>30))// the month which have 30 days per month
	{
		month = month++;
		day = 1;
	}
	if( month==11 && day>31)// next year
	{
		month = 0;// month become January
		day = 1;
	}
	if(month == 1 && day > 28)// Feb only has 28 days per month
	{
		month = month++;
		day = 1;
	}
	return a;
}

int main(void)
{
	cout << "1-Part 1" << endl;
	cout << "2-Part 2: assign the value of one Date object to the other" << endl;
	cout << "3-Part 2: compare two dates" << endl;
	cout << "4-Part 2: add one day to a date object" << endl;
	cout << "5-Quit" << endl;

	int chioce = 0;
	do
	{
	 cout << "Please choose the task number!\n" << endl;
	 cin >> chioce;
	 switch(chioce)
	 {
	 case 1:{ cout << "Write the constructors, destructor and output function members of this class" << endl;
		      Date t1,t2;
			  t1.Display();
			  t2.SetDate("Aug",19);
			  t2.Display();
			  break;}

	 case 2:{ cout << "assign the value of one Date object to the other" << endl;
		      Date t3,t4;
			  t4.SetDate("Jun",1);
			  t3 = t4;
			  t4.Display();
			  break;}

	 case 3:{ cout << "compare two dates" << endl;
		      string l[12] = {"Jan","Feb","Mar","Apr","May","Jun",
		                      "Jul","Aug","Sep","Out","Nov","Dec"};

		      cout << "Please enter the first date" << endl;
			  cout << "the first three letters of month" << endl;
			  string m1;
			  cin >> m1;
			  int k = 0;
			  int j = 0;
	          for(; k < 12 ; k++)
	           {
		         if( m1 == l[k] ) // the first three letters match the right value and day
	       	   {
		         j = 1;
	           }
             	}
			  if(j != 1)
			  {
				  cout << "enter error just three letters" << endl;
				  break;
			  }

			  cout << "integer number of day" << endl;
			  int d1 = 0;
			  cin >> d1;
			  if(d1<1 || d1>31)
			  {
				  cout << "enter error" << endl;
				  break;
			  }

			  cout << "Please enter the second date" << endl;
			  cout << "the first three letters of month" << endl;
			  string m2;
			  cin >> m2;
			  int n = 0;
			  int i = 0;
	          for(; n < 12 ; n++)
	           {
		         if( m2 == l[n] ) // the first three letters match the right value and day
	       	   {
		         i = 1;
	           }
             	}
			  if(i != 1)
			  {
				  cout << "enter error just three letters" << endl;
				  break;
			  }

			  cout << "integer number of day" << endl;
			  int d2 = 0;
			  cin >> d2;
			  if(d2<1 || d2>31)
			  {
				  cout << "enter error" << endl;
				  break;
			  }

			  Date t5,t6;
			  t5.SetDate(m1,d1);
			  t6.SetDate(m2,d2);

			  cout << "1 for >" << endl;
			  cout << "2 for <" << endl;
			  cout << "3 for ==" << endl;
			  cout << "4 over" << endl;// set loop to compare two Date for all operators

			  int choose;
			  do
			  {
			  cout << "Please choose the compare ways" << endl;
			  cin >> choose;
			  if(choose == 1)
			  {
				  if(t5 > t6)// using bool operator >
				  {
					  cout << "true" << endl;
				  }
				  else
				  {
					  cout << "false" << endl;
				  }
			  }
			  if(choose == 2)
			  {
				  if(t5 < t6)// using bool operator <
				  {
					  cout << "true" << endl;
				  }
				  else
				  {
					  cout << "false" << endl;
				  }
			  }
			  if(choose == 3)// using bool operator ==
			  {
				  if(t5 == t6)
				  {
					  cout << "true" << endl;
				  }
				  else
				  {
					  cout << "false" << endl;
				  }
			  }
			  }
			  while(choose != 4);
			  break;}

	 case 4:{ cout << "add one day to a date object" << endl;
		      cout << "Please enter the date which you want to add one day" << endl;
			  cout << "the first three letters of month" << endl;
			  string m;
			  cin >> m;
			  string l[12] = {"Jan","Feb","Mar","Apr","May","Jun",
		                      "Jul","Aug","Sep","Out","Nov","Dec"};
			  int b = 0;
			  int v = 0;
	          for(; b < 12 ; b++)
	           {
		         if( m == l[b] ) // the first three letters match the right value and day
	       	   {
		         v = 1;
	           }
             	}
			  if(v != 1)
			  {
				  cout << "enter error just three letters" << endl;
				  break;
			  }

			  cout << "integer number of day" << endl;
			  int d = 0;
			  cin >> d;
			   if(d<1 || d>31)
			  {
				  cout << "enter error" << endl;
				  break;
			  }

			  Date t7;
			  t7.SetDate(m,d);
			  t7.Display();
			  ++t7;// add one day of given Date
			  t7.Display();
			  break;}

	 case 5:{break;}
	 }
	 }
	 while(chioce != 5);

	return 0;
}