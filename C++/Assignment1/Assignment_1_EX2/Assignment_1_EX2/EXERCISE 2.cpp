/*

Name: Simple Program to calculate the income of simple interest and compound interest

File Name: EXERCISE 2.c

Copyright: Free

Author: Zhang Junming

Description: Calculate a mathematic problem of simple and compound interest

*/

#include <iostream>

#define simple_interest 0.1// The value of simple interest is 0.1
#define compound_interest 0.05// The value of compound interest is 0.05

using namespace std;

int main(void)
{
	int George_invests = 200;// represents George¡¯s investment is ¡ç200 

	int i = 0;// represents time. (years)
	int j = 0;// to judge whether out the loop

	int George_property = 200;// to store George¡¯s main property and at the first time George has ¡ç200
	float Paul_property = 200;// to store Paul¡¯s main property and at the first time Paul has ¡ç200

	// Tell user this program's function
	cout << "George invests $200 at 10% simple interest.\n" << endl;
	cout << "At the same time, Paul invests $200 at 5% compound interest.\n" << endl;

	do
	{
		George_property = George_invests * simple_interest + George_property;// The formula of George's property (simple interest) 

		Paul_property = Paul_property * compound_interest + Paul_property;// The formula of Paul's property (compound interest) 

		i = i++;// represent time (years)

		if(Paul_property > George_property)
		{
			j = 1;
		}
	}
	while( j != 1 );

	cout << "After " << i << " years. Paul¡¯s investment will exceed the value of George¡¯s investment\n" << endl;
	cout << "At " << i << "th year. Paul gets " << Paul_property << "$;" << " Georage gets " << George_property << "$.\n" << endl;

	return 0;
}