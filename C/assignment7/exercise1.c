/*
Name: Simple Program to add book and search book

File Name: exercise1.c

Copyright: Free

Author: Zhang Junming

Description: Ask user to choose functions using number (1~3): 
             1- add book in librarybooks.txt
             2- search book name in librarybooks.txt and display the related information 
             3- quit program;
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>/* for malloc(), free() */
void menu();/* defined function of menu */
void addbook();/* declar a defined function addbook */
void searchbook();/* declar a defined function searchbook */
struct library_book /* setting up the structure declaration */
{
  char book_name[50];/* represents the name of added book */
  char author_name[20];/* represents the name of book author */
  char library_ID[8];/* represents 7 digits of the book ID number */
};

main()
{
int choose;/* represents options */
do/* setting up a loop for run following commands */
 {
  menu();
  printf("Please enter 1~3 to choose function\n");
  scanf("%d",&choose);
  getchar();/* receive EHTER */
  system("cls");/* system("cls") clears whatever is display on the screen */
  switch(choose)/* choose options */
  {
   case 1:addbook();break;/* 1- add book in librarybooks.txt  */
   case 2:searchbook();break;/* 2- search book name in librarybooks.txt and display the related information */
   case 3:printf("Quit program!!\n");break;
   default:printf("enter error! Please enter again!\n");/* when input wrong command, display enter data error */
  }
 }
while(choose!=3);/* if input 3, out of this loop */
system("pause");/* let result display on the screen before press any key to continue */
}

void menu()/* defined function of menu */
{
  printf("**********************\n");
  printf("******  menu  ********\n");
  printf("**  1- add book  *****\n");
  printf("**  2- search book  **\n");
  printf("**  3- quit  *********\n");
  printf("**********************\n\n");
}

void addbook()/* declar a defined function addbook */
{
  struct library_book lib;
  int choose;/* for choosing options */
  int count;/* for counting */
  char ID1[10] = "Sc";/* represents Science library ID number */
  char ID2[10] = "EN";/* represents Engineering library ID number */
  FILE*fp;/* represents librarybooks.txt */
  
  printf("Please follow 1~4 steps\n");
  
  printf("***********************\n");
  printf("(1 add book name \n");
  printf("(2 add author name \n");
  printf("(3 choose book types \n");
  printf("(4 add library ID number\n");
  printf("***********************\n\n");/* tell user how to use this function */
 
  printf("Please enter book name\n");
  gets(lib.book_name);
  printf("\n");
  
  printf("Please enter author name\n");
  gets(lib.author_name);
  printf("\n");
  
  printf("Please choose types: 1-science 2-engineering\n");
  scanf("%d",&choose);
  getchar();/* receive EHTER */
  if(choose==1)
   {
    do
	 {
      printf("Please enter library ID (7 digits) \n");
      gets(lib.library_ID);
	  count=strlen(lib.library_ID);/* counting how many digits in library_ID */
	  }
	 while(count!=7);/* limit library ID is a 7 digit number */
    strncat(ID1,lib.library_ID,10);/* add library ID to 'Sc' */
	fp=fopen("librarybooks.txt","a");/* open or create librarybooks.txt */
    if(fp==NULL){
    printf("Failed opening librarybooks.txt!\n");
    return;}
    fprintf(fp,"%s ",lib.book_name);/* input bookname in librarybooks.txt */
    fprintf(fp,"%s ",lib.author_name);/* input author in librarybooks.txt */
    fprintf(fp,"%s ",ID1);/* input library ID in librarybooks.txt */
    fprintf(fp,"\n");
    fclose(fp);/* when use file over, should close it */
    system("pause");/* let result display on the screen before press any key to continue */
    system("cls");/* system("cls") clears whatever is display on the screen */
   }
   if(choose==2)/* same as choose==1 */
   {
    do
	{
     printf("Please enter library ID\n");
     gets(lib.library_ID);
	 count=strlen(lib.library_ID);
	}
	while(count!=7);
    strncat(ID2,lib.library_ID,10);/* add library ID to 'EN' */
    fp=fopen("librarybooks.txt","a");
    if(fp==NULL){
    printf("Failed opening librarybooks.txt!\n");
    return;}
    fprintf(fp,"%s ",lib.book_name);
    fprintf(fp,"%s ",lib.author_name);
    fprintf(fp,"%s ",ID2);
    fprintf(fp,"\n");
    fclose(fp);
    system("pause");/* let result display on the screen before press any key to continue */
    system("cls");/* system("cls") clears whatever is display on the screen */
   }
   if(choose!=1&&choose!=2)/* when enter error,back to menu */
    {
	 printf("Please enter 1 or 2!\n");
	 system("pause");/* let result display on the screen before press any key to continue */
	 system("cls");/* system("cls") clears whatever is display on the screen */
	 return;
	}
}

void searchbook()/* declar a defined function searchbook */
{
    struct library_book lib;
	int i=0,j=0,count=0;/* - for counting */
	char aim[50];/* represents the name of searching book */
	FILE *fp;/* represents librarybooks.txt */
	char **bookname; /* for storing information in librarybooks.txt */
	fp=fopen("librarybooks.txt","r");/* open librarybooks.txt */
	if(fp==NULL)
	{
		printf("Open File error!");
	}
	else
	{
		while(!feof(fp))/* before go to the end of librarybooks.txt */
		{
			fscanf(fp,"%s",lib.book_name);
			count++;/* counting how many items in librarybooks.txt */
		} 
		rewind(fp);/* Return to the outset of librarybooks.txt */
		bookname = (char**)malloc(sizeof(char*)*count);/* Request a block of memory of a give size for bookname */
		for (i=0; i<count; i++)   
		bookname[i] = (char*)malloc(sizeof(char)*20); /* Request a block of memory of a give size for bookname[i] */
	
		for (i=0;i<count;i++)
		{
			fscanf(fp,"%s",lib.book_name);
			strcpy(bookname[i],lib.book_name);/* put each item in bookname[i] */
		}
		printf("Please follow 1 step\n");
  
        printf("*************************************\n");
		printf("(1 Please enter seachered information\n");
		printf("*************************************\n\n");/* tell user how to use this function */
		printf("There are %d books in library\n\n",count);/* display how many books in librarybooks.txt */
		printf("Please enter name of searching book\n");
		gets(aim);
		for (i=0;i<count;i++)
		{
          if(strcmp(aim,bookname[i])==0){/* compare each item in bookname[i] and aim. if they are the same, return 0 to strcmp */
			printf("%s %s %s\n",bookname[i],bookname[i+1],bookname[i+2]);}
		  else
		    j=j++;/* record number of searching times that bookname[i] is different with aim */
		}
		for (i=0; i<count; i++)
			free(bookname[i]);/* To release memory allocated with malloc() */
		    free(lib.book_name); /* To release memory allocated with malloc() */
	}
	      if(i==j)/* it mean that didn't find aim in librarybooks.txt */
		  {
			printf("can't find this book\n");
			system("pause");/* let result display on the screen before press any key to continue */
			system("cls");/* system("cls") clears whatever is display on the screen */
			return;
		  }
	fclose(fp);
	system("pause");/* let result display on the screen before press any key to continue */
	system("cls");/* system("cls") clears whatever is display on the screen */
}

