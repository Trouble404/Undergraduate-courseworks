#include <iostream>
using namespace std;

struct match{
	char team;
	int rank;
	int goal_difference;
	int goals;
}match[]={{'A',4,-2,5},{'B',6,3,8},{'C',4,1,6},{'D',2,-2,5}};

void Sort(struct match a[], int n)
{
	int i,j,k;
	struct match m;
	for(i = 0;i< n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(a[k].rank == a[j].rank && a[k].goal_difference == a[j].goal_difference && a[k].goals < a[j].goals)
			{
				    m = a[k];
				    a[k] = a[k+1];
				    a[k+1] = m;
			}

			if(a[k].rank == a[j].rank && a[k].goal_difference < a[j].goal_difference)
			{
					m = a[k];
				    a[k] = a[k+1];
				    a[k+1] = m;
			}
			

			if(a[k].rank < a[j].rank)
			{
				k = j;
			}
			
			if(i != k)
			{
				m = a[i];
				a[i] = a[k];
				a[k] = m;
			}
		}
	}
}


int main(void)
{
	int i;
	int n = sizeof(match)/sizeof(match[0]);
	Sort(match,n);
	for(i=0;i<n;i++)
	{
		cout << match[i].team << "\t" << match[i].rank << "\t" << match[i].goal_difference << "\t" << match[i].goals << endl;
	}
	return 0;
}