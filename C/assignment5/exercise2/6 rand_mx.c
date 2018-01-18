#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE_COLUMN 4
#define SIZE_ROW 4
void rand_mx(int matrix[SIZE_COLUMN][SIZE_ROW])
{
int i,j;
int d = -20,e = 31;
srand((unsigned)time(NULL));
for (i=0;i<SIZE_ROW;i++)
{
for (j=0;j<SIZE_COLUMN;j++)
{
matrix[i][j]=(rand()%(50)+(-20));
printf("  %d",matrix[i][j]);
}
printf("\n");
}
printf("\n");
}

