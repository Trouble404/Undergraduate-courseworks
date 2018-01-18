/*

Name: Simple Program to fit curve

File Name: EXERCISE 1.cpp

Copyright: Free

Author: Zhang Junming

Description: applying regression analysis in coordinates
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

// input value of coordinates
 int i, j, k, n, m; // i j k n for counting 
 cout << "Please enter the number of coordinates£º";
 cin >> m; // m for store the number x[m] or y[m]
 double **P = new double *[m]; // P for sotre coordinates and allocate a memory to it
 
 for (i = 0; i < m; ++i)
 {
      P[i] = new double[2]; // x and y needs two rows
  	  
      for (j = 0; j < 2; ++j)
	  {
		  if(j == 0)
		  {
		    cout << "x[" << i+1 << "] = " << endl;
            cin >> P[i][j];
		  }
		  if(j == 1)
		  {
		    cout << "y[" << i+1 << "] = " << endl;
            cin >> P[i][j];
		  }
	  }
 }

 cout << endl;
 
 // display the coordinates which user entered
 for (i = 0; i < m; ++i)
 {
  for (j = 0; j < 2; ++j)
  {
   cout << P[i][j] << ' ';
  }
  cout << endl;
 }
 

 // output coordinates information in text
 ofstream outfile ("data.txt");
	for(k = 0; k < m; ++k)
	{
	  outfile << P[k][0] << "\t" << P[k][1] << endl;
	}
	outfile.close();
	cout << "output at a text file named data.txt" << endl;


// applying regression analysis
	cout << "Please choose the type of fitting these data" << endl;
    cout << "1-straight line" << endl;
	cout << "2-second order polynomial equation" << endl;
	int choose;
	cin >> choose;
	switch(choose)
	{
	case 1:{
		     cout << " For straight line " << endl;

			 // reading coordinates in data.txt

			  double **P1 = new double *[m]; // for store coordinates in data.txt
			  ifstream fin1("data.txt");
			  for (i = 0; i < m; ++i)
                {
                  P1[i] = new double[2];
  	  
                  for (j = 0; j < 2; ++j)
	               {
		             if(j == 0) // the value of it is x
		             {
		                  fin1 >> P1[i][j];
		             }
		             if(j == 1) // the value of it is y
		             {
                          fin1 >> P1[i][j];
	                 }
                   }
			     }
			  fin1.close();
			
			
			  // applying regression analysis in the way of stright line: calculate part
			  double a1 = 0;
			  double a2 = 0;
			  double b1 = 0;
			  double b2 = 0;
			  double d1 = 0;
			  double d2 = 0;

			  for(n = 0;n < m; ++n)
			  {
				 a1 = a1 + P1[n][0]*P1[n][0];
				 a2 = a2 + P1[n][0];
				 b1 = b1 + P1[n][0];
				 d1 = d1 + P1[n][0]*P1[n][1];
				 d2 = d2 + P1[n][1];
			  }
			  b2 = m;
			  d1 = -1 * d1;
			  d2 = -1 * d2;

			  double a = 0;
			  double b = 0;

			  a = ((b1*d2)-(d1*b2)) / ((a1*b2)-(a2*b1));
			  b = ((a1*d2)-(d1*a2)) / ((a1*b2)-(a2*b1));

			  double *cy;
			  cy = new double[m];
			  for(n = 0;n < m; ++n)
			  {
				  cy[n] = a * P1[n][0] + b;
			  }
			 

			  //output the result of  regression analysis in stright line
			  ofstream outfile1 ("data_straight line.txt");
			  outfile1 << "Line" << endl;
			  outfile1 << "a = " << a << "\t" << "b = " << b << endl;
			  for(n = 0;n < m; ++n)
			  {
				  outfile1 << P1[n][0] << "\t" << P1[n][1] << "\t" << cy[n] << endl;
			  }
			  outfile1.close();
			  cout << "output at a text file named data_straight.txt" << endl;

			 break;
		   }


	case 2:{
		    cout << " For second order polynomial equation " << endl;

			// reading coordinates in data.txt

			  double **P2 = new double *[m];
			  ifstream fin2("data.txt");
			  for (i = 0; i < m; ++i)
                {
                  P2[i] = new double[2];
  	  
                  for (j = 0; j < 2; ++j)
	               {
		             if(j == 0) // x
		             {
		                  fin2 >> P2[i][j];
		             }
		             if(j == 1) // y
		             {
                          fin2 >> P2[i][j];
	                 }
                   }
			     }
			  fin2.close();
			 

			  // applying regression analysis in the way of second order polynomial: calculate part
			  double a1 = 0;
			  double a2 = 0;
			  double a3 = 0;
			  double b1 = 0;
			  double b2 = 0;
			  double b3 = 0;
			  double c1 = 0;
			  double c2 = 0;
			  double c3 = 0;
			  double d1 = 0;
			  double d2 = 0;
			  double d3 = 0;

			  for(n = 0;n < m; ++n)
			  {
				 a1 = a1 + P2[n][0]*P2[n][0]*P2[n][0]*P2[n][0];
				 a2 = a2 + P2[n][0]*P2[n][0]*P2[n][0];
				 a3 = a3 + P2[n][0]*P2[n][0];
				 b1 = b1 + P2[n][0]*P2[n][0]*P2[n][0];
				 b2 = b2 + P2[n][0]*P2[n][0];
				 b3 = b3 + P2[n][0];
				 c1 = c1 + P2[n][0]*P2[n][0];
				 c3 = c3 + P2[n][0];
				 d1 = d1 + P2[n][0]*P2[n][0]*P2[n][1];
				 d2 = d2 + P2[n][0]*P2[n][1];
				 d3 = d3 + P2[n][1];
			  }
			  c3 = m;
			  d1 = -1 * d1;
			  d2 = -1 * d2;
			  d3 = -1 * d3;


			  double a = 0;
			  double b = 0;
			  double c = 0;

			  a=(b1*c2*d3+c1*d2*b3+d1*b2*c3-d1*c2*b3-d2*c3*b1-b2*c1*d3)/(a1*b2*c3-a1*b3*c2-b1*a2*c3+b1*a3*c2+c1*a2*b3-c1*b2*a3);
              b=(a1*c2*d3+c1*d2*a3+d1*a2*c3-d1*c2*a3-d2*c3*a1-a2*c1*d3)/(a1*b2*c3-a1*b3*c2-b1*a2*c3+b1*a3*c2+c1*a2*b3-c1*b2*a3);
              c=-(a1*b2*d3-a1*b3*d2-b1*a2*d3+b1*a3*d2+d1*a2*b3-d1*b2*a3)/(a1*b2*c3-a1*b3*c2-b1*a2*c3+b1*a3*c2+c1*a2*b3-c1*b2*a3);

			  double *cy;
			  cy = new double[m];
			  for(n = 0;n < m; ++n)
			  {
				  cy[n] = a*P2[n][0]*P2[n][0] + b*P2[n][0] + c;
			  }
			

			  //output the result of  regression analysis in second order polynomial
			  ofstream outfile1 ("data_second order polynomial.txt");
			  outfile1 << "polynomial" << endl;
			  outfile1 << "a = " << a << "\t" << "b = " << b << "\t" << "c = " << c << endl;
			  for(n = 0;n < m; ++n)
			  {
				  outfile1 << P2[n][0] << "\t" << P2[n][1] << "\t" << cy[n] << endl;
			  }
			  outfile1.close();
			  cout << "output at a text file named data_second order polynomial.txt" << endl;

			 break;
		   }

	default: cout<<"enter error"<<endl;

	}
 
 return 0;
}