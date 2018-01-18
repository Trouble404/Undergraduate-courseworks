#include <stdio.h>
#define SIZE_COLUMN 4
#define SIZE_ROW 4

void trans_mx(int matrix[SIZE_COLUMN][SIZE_ROW])
{
int i,j;
for (i=0;i<SIZE_ROW;i++)
{
for (j=0;j<SIZE_COLUMN;j++)
{
printf("  %d",matrix[j][i]);
}
printf("\n");
}
printf("\n");
}

