#ifndef _FRACTION
#define _FRACTION

#include<iostream>

using namespace std;

class Fraction
{
	friend class iFraction; // let iFraction could use member function in class Fraction
	friend iFraction convertF(Fraction term); // let convert function could use member function in class Fraction 

    private:

		int top;       // Numerator
		int bottom;    // Denominator

    public:

		Fraction() // default constructor
		{
			top = 0;
	        bottom = 1;
		}

		Fraction(int N , int D) // normal constructor
		{
			  top = N;
			  bottom = D;
		}

		void out()
		{
			cout << top << "/" << bottom << endl;
		}
};

#endif