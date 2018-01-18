/*
Name: Simple Program to encrypt and decrypt a message.

File Name: exercise1.c

Copyright: Free

Author: Zhang Junming

Description: Ask user to choose functions using number (1~3): 
             1- Encrypt a message and output files;
             2- Decrypt a message stored in a file; 
             3- Quit program;
*/
#include <stdio.h>
#include <stdlib.h>/* rand function in this library */
#include <time.h>
#include <string.h>
#define string_length 5000/* maximum value of entered strings */
void menu()/* defined function of menu */
{
printf("1) Encrypt a message and output files \n");
printf("2) Decrypt a message stored in a file \n");
printf("3) Quit program \n");
printf("Please enter 1~3 choose function \n");
}
void option1()/* declar a defined function option1 */
{
 char file1[90];/* for store encrtpted file's name */
 char file2[90];/* for store key file's name */
 int i;/* for looping */
 int length;/* for countion */
 char Origin[256];
 char Key[string_length];
 char Encrypted[string_length];
 FILE *fp1,*fp2;/* represents Encrypted and Key file */
 printf("Please enter strings \n");
 gets(Origin);
 length = strlen(Origin);/* counting how many characters in entered strings */
 srand((unsigned)time(NULL));/* Resetting time */
 for(i=0; i<length; i++)
 {
  Key[i]=(rand()%(10)+(0));/* create random number between 0 to 10 */
  Encrypted[i] = Origin[i] + Key[i];/* Produce an encrypted form of the message using ASCII table */
 }
 printf("Please enter address and name(include suffix .txt) of Encrypted file \n");
 printf("e.g:xxx.txt or d:\\\\ xxx.txt \n");/* file name include suffix(.txt) */
 scanf("%s",&file1);
 fp1=fopen(file1,"w");/* create encrypted file */
 for(i=0; i<length; i++)
 {
 fprintf(fp1,"%c",Encrypted[i]);/* input encrypted strings to file using "fprintf" */
 }
 fclose(fp1);/* when use file over, should close it */
 printf("Please enter address and name(include suffix .txt) of Key file \n");
 printf("e.g:xxx.txt or d:\\\\ xxx.txt \n");/* file name include suffix(.txt) */
 scanf("%s",&file2);
 fp2=fopen(file2,"w");/* create key file */
 for(i=0; i<length; i++)
 {
 fprintf(fp2,"%d ",Key[i]);/* input key strings to file using "fprintf" */
 }
 fclose(fp2);/* when use file over, should close it */
 printf("\n");
 system("pause");/* let result display on the screen before press any key to continue */
 system("cls");/* system("cls") clears whatever is display on the screen */
}
void option2()/* declar a defined function option2 */
{
 char file1[90];/* for store encrtpted file's name */
 char file2[90];/* for store key file's name */
 int i;/* for looping */
 int length;/* for countion */
 char Origin[string_length];
 char Key[string_length];
 char Encrypted[string_length];
 FILE *fp1,*fp2;/* represents Encrypted and Key file */
 printf("Please enter Encrypted file's address and name(include suffix .txt) \n");
 printf("e.g:xxx.txt or d:\\\\ xxx.txt \n");/* file name include suffix(.txt) */
 scanf("%s",&file1);
 if(!(fp1=fopen(file1,"r")))/* if can't find and open this file */
 {
 printf("can't open this file,please try again! \n");
 system("pause");/* let result display on the screen before press any key to continue */
 system("cls");/* system("cls") clears whatever is display on the screen */
 return;
 }
 else
 {
 printf("enter data successful \n");
 }
 printf("Please enter Key file's address and name(include suffix .txt) \n");
 printf("e.g:xxx.txt or d:\\\\ xxx.txt \n");/* file name include suffix(.txt) */
 scanf("%s",&file2);
 if(!(fp2=fopen(file2,"r")))/* if can't find and open this file */
 {
 printf("can't open this file,please try again \n");
 system("pause");/* let result display on the screen before press any key to continue */
 system("cls");/* system("cls") clears whatever is display on the screen */
 return;
 }
 else
 {
 printf("enter data successful \n\n");
 printf("Decrypted message is: \n\n");
 }
 for(i=0;i<string_length;i++)
 {
 fscanf(fp1,"%s",Encrypted);/* lode encrypted data and store in Encrypted */
 fscanf(fp2,"%d ",&Key[i]);/* lode key data and store in Key */
 Origin[i] = Encrypted[i]-Key[i];/* Produce an origin form of the message using ASCII table */
 }
 fclose(fp1);
 fclose(fp2);/* when use file over, should close it */
 length = strlen(Origin);/* counting how many characters in entered strings */
 for(i=0;i<length;i++)
 {
 printf("%c",Origin[i]);/* display original strings */
 }
 printf("\n\n");
 system("pause");/* let result display on the screen before press any key to continue */
 system("cls");/* system("cls") clears whatever is display on the screen */
}
main()
{
int ch;/* for receive EHTER */
int choose;/* represents options */
do/* setting up a loop for run following commands */
{
menu();
scanf("%d",&choose);
ch=getchar();/* receive EHTER */
switch (choose)/* choose options */
{
case 1: option1();break;/* 1- Encrypt a message and output files */
case 2: option2();break;/* 2- Decrypt a message stored in a file */
case 3: printf("\n");break;
default: printf("enter data error!\n");/* when input wrong command, display enter data error */
}
}
while (choose!=3);/* if input 3, out of this loop */
system("pause");/* let result display on the screen before press any key to continue */
return 0;
}

