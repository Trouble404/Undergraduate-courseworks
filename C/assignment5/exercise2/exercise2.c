/*
Name: Simple Program to perform the following operations on a 4 x 4 matrix

File Name: exercise2.c

Copyright: Free

Author: Zhang Junming

Description: Ask user to choose functions using number (1~9), 1~9 represent different function of matrix: 
             1- initialize the matrix with a value;
             2- fill each matrix element with entered values; 
             3- rotate the matrix clockwise or anti-clockwise; 
             4- transpose the matrix; 
             5- fill the matrix with random values from -20 to 30; 
             6- display the current matrix; 
             7- fill the outer elements of the matrix with a value;
             8- fill the inner elements of the matrix with a value; 
             9-quit.
*/
#include<stdio.h>
#include<stdlib.h>/* rand function in this library */
#include<time.h>/* for reset time */
#define SIZE_COLUMN 4
#define SIZE_ROW 4
void menu()/* defined function of menu */
{
printf("Please enter a number(1~9) to choose the function\n\n");
printf("******************Matrix Operation******************** *\n");
printf("*(1)initialize the matrix with a value                 *\n");
printf("*(2)fill each matrix element with entered values       *\n");
printf("*(3)rotate the matrix clockwise or anti-clockwise      *\n");
printf("*(4)transpose the matrix                               *\n");
printf("*(5)fill the matrix with random values from -20 to 30  *\n");
printf("*(6)display the current matrix                         *\n");
printf("*(7)fill the outer elements of the matrix with a value *\n");
printf("*(8)fill the inner elements of the matrix with a value *\n");
printf("*(9)quit                                               *\n");
printf("\n");
}
void init_mx(int (*matrix)[SIZE_COLUMN])/* declar a defined function init_mx and a 4*4 matrix */
{
int i,j,a;/* i,j represent rows and columns. a represents initialized value */
printf("Please initialize the matrix with 1 number \n");
scanf("%d",&a);
for(i=0;i<SIZE_ROW;i++)
for(j=0;j<SIZE_COLUMN;j++)
{
matrix[i][j]=a;/* let each elements equal to initialized value */
}
printf("Required matrix is : \n\n");
for (i=0;i<SIZE_ROW;i++)
{
for (j=0;j<SIZE_COLUMN;j++)
{
printf("  %d",matrix[i][j]);
}
printf("\n");
}
printf("\n");
system("pause");/* let result display on the screen before press any key to continue */
system("cls");/* system("cls") clears whatever is currently on the output screen */
}
void fill_mx(int (*matrix)[SIZE_COLUMN])/* declar a defined function fill_mx and a 4*4 matrix */
{
int i,j;/* i,j represent rows and columns */
printf("Please enter 16 numbers to fill this matrix \n");
for(i=0;i<SIZE_ROW;i++)
for(j=0;j<SIZE_COLUMN;j++)
{
scanf("%d",&matrix[i][j]);/* store each entered value in their elements */
}
printf("\n");
printf("Required matrix is : \n\n");/* display required matrix */
for (i=0;i<SIZE_ROW;i++)
{
for (j=0;j<SIZE_COLUMN;j++)
{
printf("  %d",matrix[i][j]);
}
printf("\n");
}
printf("\n");
system("pause");/* let result display on the screen before press any key to continue */
system("cls");/* system("cls") clears whatever is currently on the output screen */
}
void rot_mx(int (*matrix)[SIZE_COLUMN])/* declar a defined function rot_mx and a 4*4 matrix */
{
int i,j;/* i,j represent rows and columns */
int a;/* represents two branches */
printf("Origin matrix is : \n\n");
for (i=0;i<SIZE_ROW;i++)
{
for (j=0;j<SIZE_COLUMN;j++)
{
printf("  %d",matrix[i][j]);/* display origin matrix */
}
printf("\n");
}
printf("\n");
printf("1 for clockwise and 2 for anti-clockwise\n\n");
scanf("%d",&a);
if (a==1)/* my understanding of "all elements one element clockwise" is same as 1 2 3 4    1 1 2 3
                                                                                1 2 3 4    1 2 2 4
																				1 2 3 4 to 1 3 3 4 
																				1 2 3 4    2 3 4 4
																				*/
{
printf("Required matrix is : \n\n");
printf("  %d  %d  %d  %d\n",matrix[1][0],matrix[0][0],matrix[0][1],matrix[0][2]);
printf("  %d  %d  %d  %d\n",matrix[2][0],matrix[2][1],matrix[1][1],matrix[0][3]);
printf("  %d  %d  %d  %d\n",matrix[3][0],matrix[2][2],matrix[1][2],matrix[1][3]);
printf("  %d  %d  %d  %d\n",matrix[3][1],matrix[3][2],matrix[3][3],matrix[2][3]);
printf("\n");
}
if (a==2)/* my understanding of "all elements one element anti-clockwise" is same as 1 2 3 4    2 3 4 4
                                                                                     1 2 3 4    1 3 3 4
																				     1 2 3 4 to 1 2 2 4 
																				     1 2 3 4    1 1 2 3
																				*/
{
printf("Required matrix is : \n\n");
printf("  %d  %d  %d  %d\n",matrix[0][1],matrix[0][2],matrix[0][3],matrix[1][3]);
printf("  %d  %d  %d  %d\n",matrix[0][0],matrix[1][2],matrix[2][2],matrix[2][3]);
printf("  %d  %d  %d  %d\n",matrix[1][0],matrix[1][1],matrix[2][1],matrix[3][3]);
printf("  %d  %d  %d  %d\n",matrix[2][0],matrix[3][0],matrix[3][1],matrix[3][2]);
printf("\n");
}
system("pause");/* let result display on the screen before press any key to continue */
system("cls");/* system("cls") clears whatever is currently on the output screen */
}
void trans_mx(int (*matrix)[SIZE_COLUMN])/* declar a defined function trans_mx and a 4*4 matrix */
{
int i,j;/* i,j represent rows and columns */
printf("Origin matrix is : \n\n");
for (i=0;i<SIZE_ROW;i++)
{
for (j=0;j<SIZE_COLUMN;j++)
{
printf("  %d",matrix[i][j]);/* display origin matrix */
}
printf("\n");
}
printf("\n");
printf("Transposed matrix is : \n\n");
for (i=0;i<SIZE_ROW;i++)
{
for (j=0;j<SIZE_COLUMN;j++)
{
printf("  %d",matrix[j][i]);/* display transposed matrix, printf when change i and j */
}
printf("\n");
}
printf("\n");
system("pause");/* let result display on the screen before press any key to continue */
system("cls");/* system("cls") clears whatever is currently on the output screen */
}
void rand_mx(int (*matrix)[SIZE_COLUMN])/* declar a defined function rand_mx and a 4*4 matrix */
{
int i,j;/* i,j represent rows and columns */
srand((unsigned)time(NULL));/* Reset time */
for (i=0;i<SIZE_ROW;i++)
{
for (j=0;j<SIZE_COLUMN;j++)
{
matrix[i][j]=(rand()%(50)+(-20));/* produce random number between -20 and 30; 50=30-(-20) */
printf("  %d",matrix[i][j]);
}
printf("\n");
}
printf("\n");
system("pause");/* let result display on the screen before press any key to continue */
system("cls");/* system("cls") clears whatever is currently on the output screen */
}
void disp_mx(int (*matrix)[SIZE_COLUMN])/* declar a defined function disp_mx and a 4*4 matrix */
{
int i,j;/* i,j represent rows and columns */
printf("The current matrix is : \n\n");
for (i=0;i<SIZE_ROW;i++)
{
for (j=0;j<SIZE_COLUMN;j++)
{
printf("  %d",matrix[i][j]);/* display current matrix */
}
printf("\n");
}
printf("\n");
system("pause");/* let result display on the screen before press any key to continue */
system("cls");/* system("cls") clears whatever is currently on the output screen */
}
void outer_mx(int (*matrix)[SIZE_COLUMN])/* declar a defined function outer_mx and a 4*4 matrix */
{
int i,j,a;/* i,j represent rows and columns; a represents the value of outer elements */
srand((unsigned)time(NULL));/* Reset time */
printf("Please inter 1 number fill outer elements\n");
scanf("%d",&a);
for(i=0;i<SIZE_ROW;i++)
for(j=0;j<SIZE_COLUMN;j++)
{
if ((i==1&&j==1)||(i==1&&j==2)||(i==2&&j==1)||(i==2&&j==2))/* inner elements */
matrix[i][j]=(rand()%(10)+(0));/* produce random number between 0 and 10 */
else
matrix[i][j]=a;/* let outer elements equal to entered value */
}
printf("Required matrix is : \n\n");
for (i=0;i<SIZE_ROW;i++)
{
for (j=0;j<SIZE_COLUMN;j++)
{
printf("  %d",matrix[i][j]);
}
printf("\n");
}
printf("\n");
system("pause");/* let result display on the screen before press any key to continue */
system("cls");/* system("cls") clears whatever is currently on the output screen */
}
void inner_mx(int (*matrix)[SIZE_COLUMN])/* declar a defined function inner_mx and a 4*4 matrix */
{
int i,j,a;/* i,j represent rows and columns; a represents the value of inner elements */
srand((unsigned)time(NULL));/* Reset time */
printf("Please inter 1 number fill inner elements\n");
scanf("%d",&a);
for(i=0;i<SIZE_ROW;i++)
for(j=0;j<SIZE_COLUMN;j++)
{
if ((i==1&&j==1)||(i==1&&j==2)||(i==2&&j==1)||(i==2&&j==2))/* inner elements */
matrix[i][j]=a;/* let inner elements equal to entered value */
else
matrix[i][j]=(rand()%(10)+(0));/* produce random number between 0 and 10 */
}
printf("Required matrix is : \n\n");
for (i=0;i<SIZE_ROW;i++)
{
for (j=0;j<SIZE_COLUMN;j++)
{
printf("  %d",matrix[i][j]);
}
printf("\n");
}
printf("\n");
system("pause");/* let result display on the screen before press any key to continue */
system("cls");/* system("cls") clears whatever is currently on the output screen */
}
main()
{
int z;/* z represents options */
int matrix1[SIZE_ROW][SIZE_COLUMN]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};/* declar matrix1[4][4] */
do/* setting up a loop for run following commands */
{
menu();
scanf("%d",&z);
switch (z)/* choose options */
{
case 1: init_mx(matrix1);break;/* 1- initialize the matrix with a value */
case 2: fill_mx(matrix1);break;/* 2- fill each matrix element with entered values */
case 3: rot_mx(matrix1);break;/* 3- rotate the matrix clockwise or anti-clockwise */
case 4: trans_mx(matrix1);break;/* 4- transpose the matrix */
case 5: rand_mx(matrix1);break;/* 5- fill the matrix with random values from -20 to 30 */
case 6: disp_mx(matrix1);break;/* 6- display the current matrix */
case 7: outer_mx(matrix1);break;/* 7- fill the outer elements of the matrix with a value */
case 8: inner_mx(matrix1);break;/* 8- fill the inner elements of the matrix with a value */
case 9: printf("\n");break;
default: printf("enter data error!\n");/* when input wrong command, display enter data error */
}
}
while (z!=9);/* if input 9, out of this loop */
return 0;
}

