/*

Name: Simple Program to convert improper fraction to mixed fraction

File Name: EXERCISE 1.cpp

Copyright: Free

Author: Zhang Junming

Description: input a improper fraction first and then display the mixed fraction which convert from the input fraction

*/

#include <iostream>
#include "Fraction.h"
#include "iFraction.h"

using namespace std;


int max(int x,int y) // find the greatest common divisor in fraction
{
    int i; // to store the remainder

	if(x>0 && y>0) // numerator and denominator are positive
	{
    while(y > 0) // when y = 0, it mean the x is the greatest common divisor now
    {
      i = x % y;
      x = y;
      y = i;
    }
     return x;
	}
	if(x>0 && y<0) // numerator is negative and denominator is positive
	{
		y = -1 * y; // let y become positive first and then fllowing function could run
		while(y > 0)
      {
        i = x % y;
        x = y;
        y = i;
      }
       return -1 * x; // greatest common divisor is negative when numerator or denominator is negative
	}
	if(x<0 && y>0) // numerator is positive and denominator is negative
	{
		x = -1 * x;
		while(y > 0)
      {
        i = x % y;
        x = y;
        y = i;
      }
       return -1 * x;
	}
	if(x<0 && y<0) // numerator and denominator are negative
	{
		x = -1 * x;
		y = -1 * y;
		while(y > 0)
      {
        i = x % y;
        x = y;
        y = i;
      }
     return x;
	}
	return x;
}

iFraction convertF(Fraction term) // convert improper function to mixed function
{
	int i = 0; // represent the remainder of fraction
	int k = 0; // represent the greatest common divisor
	iFraction result; // store result

	k = max(term.top,term.bottom); // find treastest common divisor
	//simplify
	term.top = term.top / k;
	term.bottom = term.bottom / k;

	i = term.top / term.bottom;// find the remainder 

	if( (term.top>0 && term.bottom>0) || (term.top<0 && term.bottom<0)) // numerator and denominator are positive or numerator and denominator are negative
	{
	  if( i <= 1 ) // do not need to change
	  {
		  if(term.top<0 && term.bottom<0) // dliminate minus 
		  {
			  term.top = -1 * term.top;
		      term.bottom = -1 * term.bottom;
		  }
		  // give related data to result
		  result.number = 1;
		  result.top = term.top;
		  result.bottom = term.bottom;
	  }
	  if( i > 1 ) // could convert to mixed fraction
	  {
          if(term.top<0 && term.bottom<0)
		  {
			  term.top = -1 * term.top;
		      term.bottom = -1 * term.bottom;
		  }
		  result.number = i; // integer part equal to the remainder
		  result.top = term.top - (term.bottom * i); // after convert 
		  result.bottom = term.bottom; // after convert
	  }
	}
	else // numerator or denominator is negative and another is positive
	{
		if( i >= -1 ) // similar as last one but change the negative value to positive first 
	  {
		  if(term.top<0)
		  {
			  term.top = -1 * term.top;
		  }
		  if(term.bottom<0)
		  {
			  term.bottom = -1 * term.bottom;
		  }

		  result.number = -1; // because one of numrator or denominator is negative
		  result.top = term.top;
		  result.bottom = term.bottom;
	  }
	  if( i < -1 )
	  {
		  if(term.top<0)
		  {
			  term.top = -1 * term.top;
		  }
		  if(term.bottom<0)
		  {
			  term.bottom = -1 * term.bottom;
		  }

		  result.number = i;
		  result.top = term.top - (term.bottom * -i);
		  result.bottom = term.bottom; 
	  }
	}

	return result;
}

int main(void)
{
	int numerator = 0;
	int denominator = 0;
	cout << "This program could covert improper fraction to mixed fraction" << endl;

	cout << "\nfor part 1: constructor test" << endl;
	Fraction t1(8,9);
	iFraction t2(2,t1);
	t2.display();

	cout << "\nPlease set up a improper fraction" << endl;
	cout << "Please enter the value of numerator" << endl;
	cin >> numerator;
	cout << "Please enter the value of denominator" << endl;
	cin >> denominator;
	Fraction term1(numerator,denominator);
	iFraction result;
	result = convertF(term1);
	cout << "Entered fraction is " << endl;
	term1.out();
	cout << "The mixed fraction of entered fraction is: " << endl;
	result.display();

	return 0;
}