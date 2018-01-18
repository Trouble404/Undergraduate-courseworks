#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE_COLUMN 4
#define SIZE_ROW 4
void inner_mx(int matrix[SIZE_COLUMN][SIZE_ROW])
{
int i,j,a;
srand((unsigned)time(NULL));
printf("Please inter 1 number(1~9) fill inner elements\n");
scanf("%d",&a);
for(i=0;i<SIZE_ROW;i++)
for(j=0;j<SIZE_COLUMN;j++)
{
if ((i==1&&j==1)||(i==1&&j==2)||(i==2&&j==1)||(i==2&&j==2))
matrix[i][j]=a;
else
matrix[i][j]=(rand()%(10)+(0));
}
}

