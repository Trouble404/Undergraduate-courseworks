#ifndef _IFRACTION
#define _IFRACTION
#include <iostream>
#include "Fraction.h"
using namespace std;

class iFraction : private Fraction
{
	friend class Fraction; // let Fraction could use member function in class iFraction
	friend iFraction convertF(Fraction term); // let convert function could use member function in class Fraction 

   private:

	   int number; // represent integer part

   public:

	   iFraction() // default constructor
	   {
		   number = 0;
	   }


	   iFraction(int Number , Fraction Term) // normal constructor
	   {
		   number = Number;
		   // fraction part
		   top = Term.top;
		   bottom = Term.bottom;
	   }

	   void display()
	   {
		   cout << number << " " << top << "/" << bottom << endl;
	   }
};

#endif