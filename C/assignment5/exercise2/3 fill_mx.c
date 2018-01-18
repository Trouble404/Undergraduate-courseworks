#include <stdio.h>
#define SIZE_COLUMN 4
#define SIZE_ROW 4
void fill_mx(int matrix[SIZE_COLUMN][SIZE_ROW])
{
int i,j;
printf("Please enter 16 numbers(1~9) to fill this matrix \n");
for(i=0;i<SIZE_ROW;i++)
for(j=0;j<SIZE_COLUMN;j++)
{
scanf("%d",&matrix[i][j]);
}
printf("\n");
}

