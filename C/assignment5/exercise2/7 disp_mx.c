#include<stdio.h>
#define SIZE_COLUMN 4
#define SIZE_ROW 4
void disp_mx(int matrix[SIZE_COLUMN][SIZE_ROW])
{
int i,j;
printf("The current matrix is : \n\n");
for (i=0;i<SIZE_ROW;i++)
{
for (j=0;j<SIZE_COLUMN;j++)
{
printf("  %d",matrix[i][j]);
}
printf("\n");
}
printf("\n");
}

