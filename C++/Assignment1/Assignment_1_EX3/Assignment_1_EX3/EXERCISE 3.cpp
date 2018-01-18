/*

Name: Simple Program to rank teams

File Name: EXERCISE 3.c

Copyright: Free

Author: Zhang Junming

Description: to rank 4 football teams' matches result according to their rank points, goal difference and goals

*/

#include <iostream>

using namespace std;

int main(void)
{
	// a,b,c,d represent at the beginning, 4 teams' rank are 4th
	// in the sort part, a,b,c,d will use to represent their rank result
	int a = 4;
	int b = 4;
	int c = 4;
	int d = 4;

	// display the match result at beginning and it's easy for user to check
	cout << "football match result\n" << endl;
	cout << "A VS B  2:1" << endl;
	cout << "A VS C  1:4" << endl;
	cout << "A VS D  2:2" << endl;
	cout << "B VS C  3:1" << endl;
	cout << "B VS D  4:2" << endl;
	cout << "C VS D  1:1\n" << endl;

	// to store the rank points of 4 teams
	int A_Rank = 0;
	int B_Rank = 0;
	int C_Rank = 0;
	int D_Rank = 0;

	// to store the goal difference of 4 teams
	int A_GD = 0;
	int B_GD = 0;
	int C_GD = 0;
	int D_GD = 0;

	// to store the goals of 4 teams.
	int A_goal = 0;
	int B_goal = 0;
	int C_goal = 0;
	int D_goal = 0;

	// represent the result of 6 matches,A_B = 2 mean that A got 2 goals in the match of A and B
	//                                   B_A = 1 mean that B got 1 goals in the match of A and B
	// when I write this program I haven't learned the class, if I have time, using calss to input match result is esaier
	int A_B = 2;
	int A_C = 1;
	int A_D = 2;
	int B_A = 1;
	int B_C = 3;
	int B_D = 4;
	int C_A = 4;
	int C_B = 1;
	int C_D = 1;
	int D_A = 2;
	int D_B = 2;
	int D_C = 1;

	// Calculate the rank points of each team
	// A_B - B_A > 0 mean that A won the match, therefore A will get 3 points
	// if A_B - B_A == 0 mean that they are tie, both A and B will get 1 pionts
	// based on this rule, calculate all matches result and get the rank points of each team
	if(A_B - B_A > 0)
		{
			A_Rank = A_Rank + 3;
		}
	if(A_B - B_A == 0)
		{
			A_Rank = A_Rank + 1;
			B_Rank = B_Rank + 1;
		}
	if(A_C - C_A > 0)
		{
			A_Rank = A_Rank + 3;
		}
	if(A_C - C_A == 0)
		{
			A_Rank = A_Rank + 1;
			C_Rank = C_Rank + 1;
		}
	if(A_D - D_A > 0)
		{
			A_Rank = A_Rank + 3;
		}
	if(A_D - D_A == 0)
		{
			A_Rank = A_Rank + 1;
			D_Rank = D_Rank + 1;
		}
	// the Rank point of team A

	if(B_A - A_B > 0)
		{
			B_Rank = B_Rank + 3;
		}

	if(B_C - C_B > 0)
		{
			B_Rank = B_Rank + 3;
		}
	if(B_C - C_B == 0)
		{
			B_Rank = B_Rank + 1;
			C_Rank = C_Rank + 1;
		}
	if(B_D - D_B > 0)
		{
			B_Rank = B_Rank + 3;
		}
	if(B_D - D_B == 0)
		{
			B_Rank = B_Rank + 1;
			D_Rank = D_Rank + 1;
		}
	// the Rank point of team B

	if(C_A - A_C > 0)
		{
			C_Rank = C_Rank + 3;
		}
	if(C_B - B_C > 0)
		{
			C_Rank = C_Rank + 3;
		}
	if(C_D - D_C > 0)
		{
			C_Rank = C_Rank + 3;
		}
	if(C_D - D_C == 0)
		{
			C_Rank = C_Rank + 1;
			D_Rank = D_Rank + 1;
		}
	// the Rank point of team C

	if(D_A - A_D > 0)
		{
			D_Rank = D_Rank + 3;
		}
	if(D_B - B_D > 0)
		{
			D_Rank = D_Rank + 3;
		}
	if(D_C - C_D > 0)
		{
			D_Rank = D_Rank + 3;
		}
	// the Rank point of team D


	// Calculate the goals of each team
	A_goal = A_B + A_C + A_D;
	B_goal = B_A + B_C + B_D;
	C_goal = C_A + C_B + C_D;
	D_goal = D_A + D_B + D_C;

	// Calculate the goal difference of each team
	A_GD = A_goal - ( B_A + C_A + D_A );
	B_GD = B_goal - ( A_B + C_B + D_B );
	C_GD = C_goal - ( A_C + B_C + D_C );
	D_GD = D_goal - ( A_D + B_D + C_D );

	
    // sort part
	// based on following rule
	// at the beginning, all teams are rank 4th
	// compare the rank points of two team, the team which has higher rank points, his rank will improve. ex: rank 4th to 3rd
	// if the rank points are same, then compare their goal difference, the team which has higher goal difference, his rank will improve
	// if the rank points and goal difference of two teams are same, then compare their goals, the team which has higher goals, his rank will improve
	// in the end, the value of rank will store in a,b,c,d when all teams comparing over

    if( A_Rank > B_Rank )
	{
		a = a--;
	}
	else if( A_Rank == B_Rank )
	{
		if( A_GD > B_GD )
		{
			a = a--;
		}
		else if( A_GD == B_GD )
		{
			if( A_goal > B_goal )
			{
				a = a--;
			}
			else if( A_goal < B_goal )
			{
				b = b--;
			}
		}
		else if( A_GD < B_GD)
		{
			b = b--;
		}
	}
	else if ( A_Rank < B_Rank )
	{
		b = b--;
	}
	// A>B && A=B && A<B

    if( A_Rank > C_Rank )
	{
		a = a--;
	}
	else if( A_Rank == C_Rank )
	{
		if( A_GD > C_GD )
		{
			a = a--;
		}
		else if( A_GD == C_GD )
		{
			if( A_goal > C_goal )
			{
				a = a--;
			}
			else if( A_goal < C_goal )
			{
				c = c--;
			}
		}
		 else if( A_GD < C_GD)
		 {
			c = c--;
		 }
	}
	else if ( A_Rank < C_Rank )
	{
		c = c--;
	}
	// A>C && A=C && A<C

	if( A_Rank > D_Rank )
	{
		a = a--;
	}
	else if( A_Rank == D_Rank )
	{
		if( A_GD > D_GD )
		{
			a = a--;
		}
		else if( A_GD == D_GD )
		{
			if( A_goal > D_goal )
			{
				a = a--;
			}
			else if( A_goal < D_goal )
			{
				d = d--;
			}
		}
		 else if( A_GD < D_GD)
		 {
			d = d--;
		 }
	  }
	else if ( A_Rank < D_Rank )
	{
		d = d--;
	}
	// A>D && A=D && A<D

	if( B_Rank > C_Rank )
	{
		b = b--;
	}
	else if( B_Rank == C_Rank )
	{
		if( B_GD > C_GD )
		{
			b = b--;
		}
		else if( B_GD == C_GD )
		{
			if( B_goal > C_goal )
			{
				b = b--;
			}
			else if( B_goal < C_goal )
			{
				c = c--;
			}
		}
		 else if( B_GD < C_GD)
		 {
			c = c--;
		 }
	  }
	else if ( B_Rank < C_Rank )
	{
		c = c--;
	}
	// B>C && B=C && B<C

	if( B_Rank > D_Rank )
	{
		b = b--;
	}
	else if( B_Rank == D_Rank )
	{
		if( B_GD > D_GD )
		{
			b = b--;
		}
		else if( B_GD == D_GD )
		{
			if( B_goal > D_goal )
			{
				b = b--;
			}
			else if( B_goal < D_goal )
			{
				d = d--;
			}
		}
		 else if( B_GD < D_GD)
		 {
			d = d--;
		 }
	  }
	else if ( B_Rank < D_Rank )
	{
		d = d--;
	}
	// B>D && B=D && B<D

	if( C_Rank > D_Rank )
	{
		c = c--;
	}
	else if( C_Rank == D_Rank )
	{
		if( C_GD > D_GD )
		{
			c = c--;
		}
		else if( C_GD == D_GD )
		{
			if( C_goal > D_goal )
			{
				c = c--;
			}
			else if( C_goal < D_goal )
			{
				d = d--;
			}
		}
		 else if( C_GD < D_GD)
		 {
			d = d--;
		 }
	  }
	else if ( C_Rank < D_Rank )
	{
		d = d--;
	}
	// C>D && C=D && C<D


	// now, the value of rank store in a,b,c,d
	// if a == 1 , team A is the NO.1
	// judge each value in a,b,c,d then display their detailed information
    if( a == 1 )
	{
		cout << "1\tA" << "\tRANK " << A_Rank << "\tGOAL DIFFERENCE " << A_GD << "\tGOALS " << A_goal << endl;
	}
	if( b == 1 )
	{
		cout << "1\tB" << "\tRANK " << B_Rank << "\tGOAL DIFFERENCE " << B_GD << "\tGOALS " << B_goal << endl;
	}
	if( c == 1 )
	{
		cout << "1\tC" << "\tRANK " << C_Rank << "\tGOAL DIFFERENCE " << C_GD << "\tGOALS " << C_goal << endl;
	}
	if( d == 1 )
	{
		cout << "1\tD" << "\tRANK " << D_Rank << "\tGOAL DIFFERENCE " << D_GD << "\tGOALS " << D_goal << endl;
	}
	// NO.1

    if( a == 2 )
	{
		cout << "2\tA" << "\tRANK " << A_Rank << "\tGOAL DIFFERENCE " << A_GD << "\tGOALS " << A_goal << endl;
	}
	if( b == 2 )
	{
		cout << "2\tB" << "\tRANK " << B_Rank << "\tGOAL DIFFERENCE " << B_GD << "\tGOALS " << B_goal << endl;
	}
	if( c == 2 )
	{
		cout << "2\tC" << "\tRANK " << C_Rank << "\tGOAL DIFFERENCE " << C_GD << "\tGOALS " << C_goal << endl;
	}
	if( d == 2 )
	{
		cout << "2\tD" << "\tRANK " << D_Rank << "\tGOAL DIFFERENCE " << D_GD << "\tGOALS " << D_goal << endl;
	}
	// NO.2

    if( a == 3 )
	{
		cout << "3\tA" << "\tRANK " << A_Rank << "\tGOAL DIFFERENCE " << A_GD << "\tGOALS " << A_goal << endl;
	}
	if( b == 3 )
	{
		cout << "3\tB" << "\tRANK " << B_Rank << "\tGOAL DIFFERENCE " << B_GD << "\tGOALS " << B_goal << endl;
	}
	if( c == 3 )
	{
		cout << "3\tC" << "\tRANK " << C_Rank << "\tGOAL DIFFERENCE " << C_GD << "\tGOALS " << C_goal << endl;
	}
	if( d == 3 )
	{
		cout << "3\tD" << "\tRANK " << D_Rank << "\tGOAL DIFFERENCE " << D_GD << "\tGOALS " << D_goal << endl;
	}
	// NO.3

    if( a == 4 )
	{
		cout << "4\tA" << "\tRANK " << A_Rank << "\tGOAL DIFFERENCE " << A_GD << "\tGOALS " << A_goal << endl;
	}
	if( b == 4 )
	{
		cout << "4\tB" << "\tRANK " << B_Rank << "\tGOAL DIFFERENCE " << B_GD << "\tGOALS " << B_goal << endl;
	}
	if( c == 4 )
	{
		cout << "4\tC" << "\tRANK " << C_Rank << "\tGOAL DIFFERENCE " << C_GD << "\tGOALS " << C_goal << endl;
	}
	if( d == 4 )
	{
		cout << "4\tD" << "\tRANK " << D_Rank << "\tGOAL DIFFERENCE " << D_GD << "\tGOALS " << D_goal << endl;
	}
	// NO.4

	return 0;
}