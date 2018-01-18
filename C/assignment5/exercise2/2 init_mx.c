#include <stdio.h>
#define SIZE_COLUMN 4
#define SIZE_ROW 4
void init_mx(int matrix[SIZE_COLUMN][SIZE_ROW])
{
int i,j,a;
printf("Please initialize the matrix with 1 number (1~9)\n");
scanf("%d",&a);
for(i=0;i<SIZE_ROW;i++)
for(j=0;j<SIZE_COLUMN;j++)
{
matrix[i][j]=a;
}
}

