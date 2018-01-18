#include <stdio.h>
#define SIZE_COLUMN 4
#define SIZE_ROW 4
void rot_mx(int matrix[SIZE_COLUMN][SIZE_ROW])
{
int a;
printf("1 for clockwise and 2 for anti-clockwise\n\n");
scanf("%d",&a);
if (a==1)
{
printf("  %d  %d  %d  %d\n",matrix[1][0],matrix[0][0],matrix[0][1],matrix[0][2]);
printf("  %d  %d  %d  %d\n",matrix[2][0],matrix[2][1],matrix[1][1],matrix[0][3]);
printf("  %d  %d  %d  %d\n",matrix[3][0],matrix[2][2],matrix[1][2],matrix[1][3]);
printf("  %d  %d  %d  %d\n",matrix[3][1],matrix[3][2],matrix[3][3],matrix[2][3]);
printf("\n");
}
if (a==2)
{
printf("  %d  %d  %d  %d\n",matrix[0][1],matrix[0][2],matrix[0][3],matrix[1][3]);
printf("  %d  %d  %d  %d\n",matrix[0][0],matrix[1][2],matrix[2][2],matrix[2][3]);
printf("  %d  %d  %d  %d\n",matrix[1][0],matrix[1][1],matrix[2][1],matrix[3][3]);
printf("  %d  %d  %d  %d\n",matrix[2][0],matrix[3][0],matrix[3][1],matrix[3][2]);
printf("\n");
}
}

