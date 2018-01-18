/*

Name: Simple Program to set fraction and calculate

File Name: EXERCISE 2.cpp

Copyright: Free

Author: Zhang Junming

Description: construct fraction and the fraction could add, subtract, multiple and divide

*/

#include <iostream>

using namespace std;

class Fraction
{

    private:

		int top;       // Numerator
		int bottom;    // Denominator

    public:

		Fraction() // default constructor
		{
			top = 0;
	        bottom = 1;
		}

		Fraction(int N , int D = 1)// normal constructor
		{
			top = N;
			bottom = D;
		}

		void Output()
		{
		    cout << "represents " << top << "/" << bottom << endl;
		}

		void output()
		{
			cout << top << "/" << bottom << endl;
		}

		Fraction operator+(const Fraction & n )//re-define the symbol + , two fraction could use + to calculate directly
		{
	        Fraction t;
	        t.top = ( top * n.bottom ) + ( bottom * n.top );// the value of top after reduction of fractions to a common denominator
	        t.bottom = bottom * n.bottom;// the value of bottom after reduction of fractions to a common denominator
	        return t;
        }

		Fraction operator-(const Fraction & n )//same as last one
		{
	        Fraction t;
	        t.top = ( top * n.bottom ) - ( bottom * n.top );
	        t.bottom = bottom * n.bottom;
	        return t;
        }

		Fraction operator*(const Fraction & n )//same as last one
		{
			Fraction t;
			t.top = top * n.top;
			t.bottom = bottom * n.bottom;
			return t;
		}

		Fraction operator/(const Fraction & n )//same as last one 
		{
			Fraction t;
			t.top = top * n.bottom;// when divide one fraction, it equal to multiply by it's reciprocal
			t.bottom = bottom * n.top;
			return t;
		}

		Fraction operator>(const Fraction & n )
		{
			Fraction t,d;
			t.top = top * n.bottom;
			t.bottom = bottom * n.bottom;
			d.top = n.top * bottom;
			d.bottom = n.bottom * bottom;
			//  reduction of fractions to a common denominator
			if( t.top > d.top )
			{
				cout << top << "/" << bottom << " > " << n.top << "/" << n.bottom << endl;
				return n;
			}
			if( t.top == d.top )
			{
				cout << top << "/" << bottom << " = " << n.top << "/" << n.bottom << endl;
				return n;
			}
			if( t.top < d.top )
			{
				cout << top << "/" << bottom << " < " << n.top << "/" << n.bottom << endl;
				return n;
			}
		}

};

int main(void)
{
	int chioce;
	cout << "1-Task " << endl;// combine all task in part 1
	cout << "2-Fraction plus" << endl;
	cout << "3-Fraction minus" << endl;
	cout << "4-Fraction multiple" << endl;
	cout << "5-Fraction divide" << endl;
	cout << "6-Compare" << endl;
	cout << "7-Quit\n" << endl;
	do
	 {
		cout << "\nPlease choose the function" << endl;
		cin >> chioce;
		if(chioce == 1)
		{

	      cout << "Task\n" << endl;
	      cout << "Fraction a; " << endl;
	      Fraction a;
	      a.Output();

	      cout << "\nFraction b(3,4); " << endl;
          Fraction b(3,4);
	      b.Output();

	      cout << "\nFraction c(5); " << endl;
	      Fraction c(5);
	      c.Output();

      	  cout << "\nFraction d(2,3) test + - * / > function with Fraction b(3,4) " << endl;
	      cout << "\nc + d = " << endl;
	      Fraction d(2,3);
	      Fraction e;
	      e = b + d;
	      e.output();

	      cout << "\nc - d = " << endl;
	      Fraction f;
	      f = b - d;
	      f.output();

	      cout << "\nc * d = " << endl;
	      Fraction g;
	      g = b * d;
	      g.output();

	      cout << "\nc / d = " << endl;
	      Fraction h;
	      h = b / d;
	      h.output();

	      cout << "\nc compare d = " << endl;
	      Fraction i;
	      i = b > d;
		}

		if( chioce == 2 )// Function: add two fraction
		{
			cout << "please enter the value of first Fraction" << endl;
			cout << "Numerator" << endl;
			int a;
			cin >> a;
			cout << "Denorminator" << endl;
			int b;
			cin >> b;

			cout << "please enter the value of second Fraction" << endl;
			cout << "Numerator" << endl;
			int c;
			cin >> c;
			cout << "Denorminator" << endl;
			int d;
			cin >> d;
			
			Fraction term1(a,b);
			Fraction term2(c,d);
			Fraction result;
			result = term1 + term2;// symbol + is re-define
			result.output();
		}

		if( chioce == 3 )// Function: minus two fraction
		{
			cout << "please enter the value of first Fraction" << endl;
			cout << "Numerator" << endl;
			int a;
			cin >> a;
			cout << "Denorminator" << endl;
			int b;
			cin >> b;

			cout << "please enter the value of second Fraction" << endl;
			cout << "Numerator" << endl;
			int c;
			cin >> c;
			cout << "Denorminator" << endl;
			int d;
			cin >> d;
			
			Fraction term1(a,b);
			Fraction term2(c,d);
			Fraction result;
			result = term1 - term2;// symbol - is re-define
			result.output();
		}

		if( chioce == 4 )// Function: multiple two fraction
		{
			cout << "please enter the value of first Fraction" << endl;
			cout << "Numerator" << endl;
			int a;
			cin >> a;
			cout << "Denorminator" << endl;
			int b;
			cin >> b;

			cout << "please enter the value of second Fraction" << endl;
			cout << "Numerator" << endl;
			int c;
			cin >> c;
			cout << "Denorminator" << endl;
			int d;
			cin >> d;
			
			Fraction term1(a,b);
			Fraction term2(c,d);
			Fraction result;
			result = term1 * term2;// symbol * is re-define
			result.output();
		}

		if( chioce == 5 )// Function: divide two fraction
		{
			cout << "please enter the value of first Fraction" << endl;
			cout << "Numerator" << endl;
			int a;
			cin >> a;
			cout << "Denorminator" << endl;
			int b;
			cin >> b;

			cout << "please enter the value of second Fraction" << endl;
			cout << "Numerator" << endl;
			int c;
			cin >> c;
			cout << "Denorminator" << endl;
			int d;
			cin >> d;
			
			Fraction term1(a,b);
			Fraction term2(c,d);
			Fraction result;
			result = term1 / term2;// symbol / is re-define
			result.output();
		}

		if( chioce == 6 )// compare two fraction
		{
			cout << "please enter the value of first Fraction" << endl;
			cout << "Numerator" << endl;
			int a;
			cin >> a;
			cout << "Denorminator" << endl;
			int b;
			cin >> b;

			cout << "please enter the value of second Fraction" << endl;
			cout << "Numerator" << endl;
			int c;
			cin >> c;
			cout << "Denorminator" << endl;
			int d;
			cin >> d;
			
			Fraction term1(a,b);
			Fraction term2(c,d);
			Fraction result;
			result = term1 > term2;// symbol > re-define to compare fractions
		}
		}
		while( chioce != 7 );
	
	return 0;
}