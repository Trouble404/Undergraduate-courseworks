/*

Name: Simple Program to set complex number and calculate

File Name: EXERCISE 3.cpp

Copyright: Free

Author: Zhang Junming

Description: construct complex number and the complex number could add, subtract, multiple and divide

*/

#include <iostream>

using namespace std;

class Fraction
{

    private:

		int top;       // Numerator
		int bottom;    // Denominator

    public:

		Fraction(int N=0 , int D=0 )// normal constructor
		{
			top = N;
			bottom = D;
		}

		int Gettop()// obtain the value of numerator
		{
			return top;
		}

		int Getbottom()// obtain the value of denominator
		{
			return bottom;
		}

		Fraction Fadd(Fraction n)// Fraction addition
		{
			Fraction t;
			t.top = ( top * n.bottom ) + ( bottom * n.top );// the value of top after reduction of fractions to a common denominator
			t.bottom = bottom * n.bottom;// the value of bottom after reduction of fractions to a common denominator
	        return t;
		}

		Fraction Fminus(Fraction n)// Fraction subtraction
		{
			Fraction t;
			t.top = ( top * n.bottom ) - ( bottom * n.top );
			t.bottom = bottom * n.bottom;
	        return t;
		}

		Fraction Ftimes(Fraction n)// Fraction multiplication
		{
			Fraction t;
			t.top = top * n.top;
			t.bottom = bottom * n.bottom;
			return t;
		}

		Fraction Fdivision(Fraction n)// Fraction division
		{
			Fraction t;
			t.top = top * n.bottom;// when divide one fraction, it equal to multiply by it's reciprocal
			t.bottom = bottom * n.top;
			return t;
		}
};

class complexClass
{
    private:

		Fraction real;// real part is fraction
		Fraction imag;// imaginary part is fraction

    public:
		complexClass(){}// default constructor
		complexClass(Fraction r , Fraction i):real(r),imag(i){}// normal composite class constructor

		complexClass Csum(complexClass n)// complex number addtion
		{
			complexClass t;
			t.real = n.real.Fadd(real);// sum of real part = real part1 + real part2
			t.imag = n.imag.Fadd(imag);// sum of imaginary part = imaginary part1 + imaginary part2
			return t;
		}

	    complexClass Cminus(complexClass n)// complex subtraction
		{
			complexClass t;
			t.real = n.real.Fminus(real);// sum of real part = real part1 - real part2
			t.imag = n.imag.Fminus(imag);// sum of imaginary part = imaginary part1 - imaginary part2
			return t;
		}

		complexClass Ctimes(complexClass n)//complex multiplication
		{
			complexClass t;
			t.real = (n.real.Ftimes(real)).Fminus(imag.Ftimes(n.imag));// A=(a+bi) B=(c+di)
			t.imag = (n.real.Ftimes(imag)).Fadd(n.imag.Ftimes(real));// A*B=ac-bd+(ad+bc)i
			return t;
		}

		complexClass Cdivision(complexClass n)
		{
			complexClass t;
			t.real = ((n.real.Ftimes(real)).Fadd(n.imag.Ftimes(imag))).Fdivision((real.Ftimes(real)).Fadd(imag.Ftimes(imag)));   //(a+bi)/(c+di) 
			t.imag = ((n.imag.Ftimes(real)).Fminus(n.real.Ftimes(imag))).Fdivision((real.Ftimes(real)).Fadd(imag.Ftimes(imag)));// =(a+bi)*(c-di)/(c+di)*(c-di) 
			return t;                                                                                                           // =(ac+adi+bci+bd)/(c*c+d*d)
		}
		void output()
		{
			cout << real.Gettop() << "/" << real.Getbottom() << " + " << imag.Gettop() << "/" << imag.Getbottom() << " i" << endl;
		}
};



int main(void)
{
    int chioce;
	cout << "1-Complex number plus " << endl;
	cout << "2-Complex number minus" << endl;
	cout << "3-Complex number multiple" << endl;
	cout << "4-Complex number divide" << endl;
	cout << "5-Quit\n" << endl;
    
	do
	{
        cout << "\nPlease choose the function" << endl;
		cin >> chioce;

		switch(chioce)
		{
			case 1:{
				    int a = 0,b = 0;
	                cout << "Please enter the value of first complex number's real part's numerator" << endl;
	                cin >> a;
	                cout << "Please enter the value of first complex number's real part's denominator" << endl;
	                cin >> b;
	                Fraction term1(a,b);
					int c = 0,d = 0;
	                cout << "Please enter the value of first complex number's imaginary part's numerator" << endl;
	                cin >> c;
	                cout << "Please enter the value of first complex number's imaginary part's denominator" << endl;
	                cin >> d;		
	                Fraction term2(c,d);

					int e = 0,f = 0;
	                cout << "Please enter the value of second complex number's real part's numerator" << endl;
	                cin >> e;
	                cout << "Please enter the value of second complex number's real part's denominator" << endl;
	                cin >> f;
	                Fraction term3(e,f);
					int g = 0,h = 0;
	                cout << "Please enter the value of second complex number's imaginary part's numerator" << endl;
	                cin >> g;
	                cout << "Please enter the value of second complex number's imaginary part's denominator" << endl;
	                cin >> h;		
	                Fraction term4(g,h);

					complexClass t1(term1,term2);
					complexClass t2(term3,term4);
					complexClass result;
					result = t2.Csum(t1);// result = t1 + t2
					result.output();

					break;
	                }

			case 2:
				{
					int a = 0,b = 0;
	                cout << "Please enter the value of first complex number's real part's numerator" << endl;
	                cin >> a;
	                cout << "Please enter the value of first complex number's real part's denominator" << endl;
	                cin >> b;
	                Fraction term1(a,b);
					int c = 0,d = 0;
	                cout << "Please enter the value of first complex number's imaginary part's numerator" << endl;
	                cin >> c;
	                cout << "Please enter the value of first complex number's imaginary part's denominator" << endl;
	                cin >> d;		
	                Fraction term2(c,d);

					int e = 0,f = 0;
	                cout << "Please enter the value of second complex number's real part's numerator" << endl;
	                cin >> e;
	                cout << "Please enter the value of second complex number's real part's denominator" << endl;
	                cin >> f;
	                Fraction term3(e,f);
					int g = 0,h = 0;
	                cout << "Please enter the value of second complex number's imaginary part's numerator" << endl;
	                cin >> g;
	                cout << "Please enter the value of second complex number's imaginary part's denominator" << endl;
	                cin >> h;		
	                Fraction term4(g,h);

					complexClass t1(term1,term2);
					complexClass t2(term3,term4);
					complexClass result;
					result = t2.Cminus(t1);// result = t1 - t2
					result.output();

					break;
	                }

            case 3:{
				    int a = 0,b = 0;
	                cout << "Please enter the value of first complex number's real part's numerator" << endl;
	                cin >> a;
	                cout << "Please enter the value of first complex number's real part's denominator" << endl;
	                cin >> b;
	                Fraction term1(a,b);
					int c = 0,d = 0;
	                cout << "Please enter the value of first complex number's imaginary part's numerator" << endl;
	                cin >> c;
	                cout << "Please enter the value of first complex number's imaginary part's denominator" << endl;
	                cin >> d;		
	                Fraction term2(c,d);

					int e = 0,f = 0;
	                cout << "Please enter the value of second complex number's real part's numerator" << endl;
	                cin >> e;
	                cout << "Please enter the value of second complex number's real part's denominator" << endl;
	                cin >> f;
	                Fraction term3(e,f);
					int g = 0,h = 0;
	                cout << "Please enter the value of second complex number's imaginary part's numerator" << endl;
	                cin >> g;
	                cout << "Please enter the value of second complex number's imaginary part's denominator" << endl;
	                cin >> h;		
	                Fraction term4(g,h);

					complexClass t1(term1,term2);
					complexClass t2(term3,term4);
					complexClass result;
					result = t2.Ctimes(t1);// result = t1 * t2
					result.output();

					break;
	                }

			case 4:
				{
					int a = 0,b = 0;
	                cout << "Please enter the value of first complex number's real part's numerator" << endl;
	                cin >> a;
	                cout << "Please enter the value of first complex number's real part's denominator" << endl;
	                cin >> b;
	                Fraction term1(a,b);
					int c = 0,d = 0;
	                cout << "Please enter the value of first complex number's imaginary part's numerator" << endl;
	                cin >> c;
	                cout << "Please enter the value of first complex number's imaginary part's denominator" << endl;
	                cin >> d;		
	                Fraction term2(c,d);

					int e = 0,f = 0;
	                cout << "Please enter the value of second complex number's real part's numerator" << endl;
	                cin >> e;
	                cout << "Please enter the value of second complex number's real part's denominator" << endl;
	                cin >> f;
	                Fraction term3(e,f);
					int g = 0,h = 0;
	                cout << "Please enter the value of second complex number's imaginary part's numerator" << endl;
	                cin >> g;
	                cout << "Please enter the value of second complex number's imaginary part's denominator" << endl;
	                cin >> h;		
	                Fraction term4(g,h);

					complexClass t1(term1,term2);
					complexClass t2(term3,term4);
					complexClass result;
					result = t2.Cdivision(t1);//result = t1 / t2
					result.output();

					break;
	                }
			case 5:{break;}
      }
	  }
	  while(chioce != 5);

      return 0;
}