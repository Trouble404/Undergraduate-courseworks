#include"input.h"

using namespace std;

int choose(int i)
{
	int choose;
	cout << "please choose function" << endl;
	cin >> choose;
	cin.sync();
	return choose;
}

string str_Input()
{
	string a;
	getline(cin,a); //getline can input string with space, for example: 123 123
		for(;a=="\0";) //avoid read NUll character
		getline(cin,a);
	return a;
}
int inte_Input()
{
	int b;
	cin>>b;
	cin.sync();
	return b;
}