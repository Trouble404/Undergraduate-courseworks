#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>

typedef struct book{
char book[100];
char author[100];
char ISBN[100];
char subject[100];
char loan_type[100];
char shelf[100];
int inventory;
int lend;
char Note[100];
struct book *link;
} book;

typedef struct card{
char username[100];
char password[100];
char type;
char history1[100];
char history2[100];
char history3[100];
struct card *link;
} card;

void login();
void menu_searchbook();
void menu_bookmanage();
void addbook(book *heas);
void searchbook_name(book *head);
void searchbook_author(book *head);
void searchbook_ISBN(book *head);
void searchbook_subject(book *head);
void searchbook_loan(book *head);
void searchbook_shelf(book *head);
void openfile(book *head);
void borrowbook(book *head);
void booklist_unborrowed(book *head);
void booklist_borrowed(book *head);
void delete_book(book* head);
void modifybook(book* head);
void returnbook(book *head);
void Register();
void menu1();
void menu2();
void search();
void Return();       

void modifybook(book* head){
char modify_name[100];
char modify_author[100];
char modify_ISBN[100];
char modify_subject[100];
char modify_loan[100];
char modify_shelf[100];
char null='\0';
int modify_inventory;
int modify_lend;
char modify_Note[100];
char bookISBN[100];
int i=0;
int choose;
FILE *fp;
book *p1,*p2,*p3;  
p1=p2=p3=(book*)malloc(sizeof(book));
fp=fopen("librarybooks.txt","rb"); 
if(fp==NULL)
{
printf("file is opened unseccessfully.\n");
exit(1);
}
p2=head;                         
while(!feof(fp))                 
{
fread(p1,sizeof(book),1,fp); 
p2->link=p1;                     
p2=p1;                           
p1=(book*)malloc(sizeof(book));
}
p2->link=NULL;                  
fclose(fp);
p3=head;
if(head==NULL||head->link==NULL)
{
printf("No books in the library!\n");
}
else
{
printf("Please enter the book'ISBN which you want to modify:\n");
fflush(stdin);
gets(bookISBN);             
while(p3->link!=NULL)
{
p3=p3->link;
 if(strcmp(bookISBN,p3->ISBN)==0)   
 {
 printf("find this book\n");          
 printf("Book name: %s\n",p3->book);
 printf("Author name: %s\n",p3->author);
 printf("ISBN: %s\n",p3->ISBN);
 printf("Subject: %s\n",p3->subject);
 printf("Loan type: %s\n",p3->loan_type);
 printf("Shelf: %s\n",p3->shelf);
 printf("Inventoryt: %d\n",p3->inventory);
 printf("Lend number: %d\n",p3->lend);
 printf("Note: %s\n",p3->Note);
 do
 {
 printf("\nDo you want to modify which information?\n");
 printf("****************************\n");
 printf("*      1>book name         *\n");
 printf("*      2>book author       *\n");
 printf("*      3>book ISBN         *\n");
 printf("*      4>book subject      *\n");
 printf("*      5>book loan type    *\n");
 printf("*      6>book shelf        *\n");
 printf("*      7>book inventory    *\n");
 printf("*      8>book lend         *\n");
 printf("*      9>MODIFY            *\n");
 scanf("%d",&choose);
 getchar();
 switch(choose)
 {
 case 1:
 printf("origin book name: %s\n",p3->book);
 printf("Please enter new book name\n");
 strcpy(p3->book,"");
 gets(modify_name);
 strcpy(p3->book,modify_name);
 break;
 case 2:
 printf("origin book author: %s\n",p3->author);
 printf("Please enter new book author\n");
 strcpy(p3->author,"");
 gets(modify_author);
 strcpy(p3->author,modify_author);
 break;
 case 3:
 printf("origin book ISBN: %s\n",p3->ISBN);
 printf("Please enter new book ISBN\n");
 strcpy(p3->ISBN,"");
 gets(modify_ISBN);
 strcpy(p3->ISBN,modify_ISBN);
 break;
 case 4:
 printf("origin book subject: %s\n",p3->subject);
 printf("Please enter new book subject\n");
 strcpy(p3->subject,"");
 gets(modify_subject);
 strcpy(p3->subject,modify_subject);
 break;
 case 5:
 printf("origin book loan type: %s\n",p3->loan_type);
 printf("Please enter new book loan type\n");
 strcpy(p3->loan_type,"");
 gets(modify_loan);
 strcpy(p3->loan_type,modify_loan);
 break;
 case 6:
 printf("origin book shelf: %s\n",p3->shelf);
 printf("Please enter new book shelf\n");
 strcpy(p3->shelf,"");
 gets(modify_shelf);
 strcpy(p3->shelf,modify_shelf);
 break;
 case 7:
 printf("origin book inventory: %d\n",p3->inventory);
 printf("Please enter new book inventory\n");
 scanf("%d",&modify_inventory);
 getchar();
 p3->inventory=modify_inventory;
 break;
 case 8:
 printf("origin book lend number: %d\n",p3->lend);
 printf("Please enter new book lend number\n");
 scanf("%d",&modify_lend);
 getchar();
 p3->lend=modify_lend;
 break;
 case 9:
 printf("Modify successfully\n");
 break;
 default:
 printf("Please enter the correct integer number.");
 }
 }
 while(choose!=9);
 i=1;                         
 }
 }
 if(i==0)                    
 {
 printf("this book is not in the library\n");
 }
 if(i==1)
 {
fp=fopen("librarybooks.txt","w");
if(fp==NULL)
{
printf("Fail to open the file!\n");
exit(1);
}
p3=head;
while(p3->link!=NULL)
{
p3=p3->link;
fwrite(p3,sizeof(book),1,fp);
}
fclose(fp);
 printf("Please enter any key to continue...");
 getchar();
 fflush(stdin);
 system("cls");  
 }
}
}

void delete_book(book* head){
char bookISBN[100];
FILE *fp;
book *p1,*p2,*p3,*p4,*p5;
fp=fopen("librarybooks.txt","rb");
if(fp==NULL)
{
printf("Fail to open the file!\n");
exit(1);
}
p5=p4=p3=p1=p2=(book*)malloc(sizeof(book));
p1=head;
while(!feof(fp))
{
fread(p2,sizeof(book),1,fp);
p1->link=p2;
p1=p2;
p2=(book*)malloc(sizeof(book));
}
p1->link=NULL;
fclose(fp);
printf("Please enter the ISBN of book which will be deleted: \n");
gets(bookISBN);
p5=p4=head;
while(p4->link!=NULL)
{
p4=p4->link;
if(strcmp(bookISBN,p4->ISBN)==0)
{
printf("Delete book successfully!\n");
p5->link=p4->link;
}
p5=p5->link;
}
fp=fopen("librarybooks.txt","w");
if(fp==NULL)
{
printf("Fail to open the file!\n");
exit(1);
}
p3=head;
while(p3->link!=NULL)
{
p3=p3->link;
fwrite(p3,sizeof(book),1,fp);
}
fclose(fp);
}


void booklist_unborrowed(book *head)
{
int a,b;
FILE *fp;
book *p1,*p2,*p3;  
p1=p2=p3=(book*)malloc(sizeof(book));
fp=fopen("librarybooks.txt","rb"); 
if(fp==NULL)
{
printf("file is opened unseccessfully.\n");
exit(1);
}
p2=head;                         
while(!feof(fp))                 
{
fread(p1,sizeof(book),1,fp); 
p2->link=p1;                     
p2=p1;                           
p1=(book*)malloc(sizeof(book));
}
p2->link=NULL;                  
fclose(fp);
p3=head;
if(head==NULL||head->link==NULL)
{
printf("No books in the library!\n");
}
else
{
while(p3->link!=NULL)
{
p3=p3->link;
 if(a=p3->inventory>0)   
 { 
 printf("find unborrowed book\n");          
 printf("Book name: %s\n",p3->book);
 printf("ISBN: %s\n",p3->ISBN);
 printf("Inventoryt: %d\n",p3->inventory);
 printf("Lend number: %d\n",p3->lend);
 }
}
}
}

void booklist_borrowed(book *head)
{
int a,b;
FILE *fp;
book *p1,*p2,*p3;  
p1=p2=p3=(book*)malloc(sizeof(book));
fp=fopen("librarybooks.txt","rb"); 
if(fp==NULL)
{
printf("file is opened unseccessfully.\n");
exit(1);
}
p2=head;                         
while(!feof(fp))                 
{
fread(p1,sizeof(book),1,fp); 
p2->link=p1;                     
p2=p1;                           
p1=(book*)malloc(sizeof(book));
}
p2->link=NULL;                  
fclose(fp);
p3=head;
if(head==NULL||head->link==NULL)
{
printf("No books in the library!\n");
}
else
{
while(p3->link!=NULL)
{
p3=p3->link;
 if(b=p3->inventory>0)   
 { 
 printf("find borrowed book\n");          
 printf("Book name: %s\n",p3->book);
 printf("ISBN: %s\n",p3->ISBN);
 printf("Inventoryt: %d\n",p3->inventory);
 printf("Lend number: %d\n",p3->lend);
 }
}
}
}

void returnbook(book *head)
{
int a,b;
int b_choose;
char borrow_ISBN[100];
int i=0;
FILE *fp;
book *p1,*p2,*p3;  
p1=p2=p3=(book*)malloc(sizeof(book));
fp=fopen("librarybooks.txt","rb"); 
if(fp==NULL)
{
printf("file is opened unseccessfully.\n");
exit(1);
}
p2=head;                         
while(!feof(fp))                 
{
fread(p1,sizeof(book),1,fp); 
p2->link=p1;                     
p2=p1;                           
p1=(book*)malloc(sizeof(book));
}
p2->link=NULL;                  
fclose(fp);
p3=head;
if(head==NULL||head->link==NULL)
{
printf("No books in the library!\n");
}
else
{
printf("Please enter the book'ISBN which you want to return:\n");
fflush(stdin);
gets(borrow_ISBN);             
while(p3->link!=NULL)
{
p3=p3->link;
 if(strcmp(p3->ISBN,borrow_ISBN)==0)   
 {
 printf("find this book\n");          
 printf("Book name: %s\n",p3->book);
 printf("Author name: %s\n",p3->author);
 printf("ISBN: %s\n",p3->ISBN);
 printf("Inventoryt: %d\n",p3->inventory);
 printf("Lend number: %d\n",p3->lend);
 printf("Note: %s\n",p3->Note);
 a=p3->inventory;
 b=p3->lend;
 if(b>0)
 {
 printf("\nDo you want to return this book?\n");
 printf("1-Yes and 2-No\n");
 scanf("%d",&b_choose);
 getchar();
  if(b_choose==1)
 {
 p3->inventory=a+1;
 p3->lend=b-1;
 printf("return book successfully!\n");
 }
 if(b_choose==2);
 {
 printf("cancel operation\n");
 }
 }
 if(b==0)
 {
 printf("This book haven't borrowed!\n");
 }
 i=1;                         
 }
 }
 if(i==0)                    
 {
 printf("this book is not in the library\n");
 }
fp=fopen("librarybooks.txt","w");
if(fp==NULL)
{
printf("Fail to open the file!\n");
printf("1");
exit(1);
}
p3=head;
while(p3->link!=NULL)
{
p3=p3->link;
fwrite(p3,sizeof(book),1,fp);
}
fclose(fp);
 printf("Please enter any key to continue...");
 getchar();
 fflush(stdin);
 system("cls");  
}
}
void borrowbook(book *head)
{
int a,b;
int b_choose;
char borrow_ISBN[100];
int i=0;
FILE *fp;
book *p1,*p2,*p3;  
p1=p2=p3=(book*)malloc(sizeof(book));
fp=fopen("librarybooks.txt","rb"); 
if(fp==NULL)
{
printf("file is opened unseccessfully.\n");
exit(1);
}
p2=head;                         
while(!feof(fp))                 
{
fread(p1,sizeof(book),1,fp); 
p2->link=p1;                     
p2=p1;                           
p1=(book*)malloc(sizeof(book));
}
p2->link=NULL;                  
fclose(fp);
p3=head;
if(head==NULL||head->link==NULL)
{
printf("No books in the library!\n");
}
else
{
printf("Please enter the book'ISBN which you want to borrow:\n");
fflush(stdin);
gets(borrow_ISBN);             
while(p3->link!=NULL)
{
p3=p3->link;
 if(strcmp(p3->ISBN,borrow_ISBN)==0)   
 {
 printf("find this book\n");          
 printf("Book name: %s\n",p3->book);
 printf("Author name: %s\n",p3->author);
 printf("ISBN: %s\n",p3->ISBN);
 printf("Inventoryt: %d\n",p3->inventory);
 printf("Lend number: %d\n",p3->lend);
 printf("Note: %s\n",p3->Note);
 a=p3->inventory;
 b=p3->lend;
 if(a>0)
 {
 printf("\nDo you want to borrow this book?\n");
 printf("1-Yes and 2-No\n");
 scanf("%d",&b_choose);
 getchar();
  if(b_choose==1)
 {
 p3->inventory=a-1;
 p3->lend=b+1;
 printf("borrow book successfully!\n");
 }
 if(b_choose==2);
 {
 printf("cancel operation\n");
 }
 }
 else if(a==0)
{
printf("Sorry, this book borrowed out\n");
}
 i=1;                         
 }
 }
 if(i==0)                    
 {
 printf("this book is not in the library\n");
 }
fp=fopen("librarybooks.txt","w");
if(fp==NULL)
{
printf("Fail to open the file!\n");
printf("1");
exit(1);
}
p3=head;
while(p3->link!=NULL)
{
p3=p3->link;
fwrite(p3,sizeof(book),1,fp);
}
fclose(fp);
 printf("Please enter any key to continue...");
 getchar();
 fflush(stdin);
 system("cls");  
}
}



void menu_searchbook()
{
printf("***********************************************************************\n");
printf("*                            -SEARCH BOOK-                            *\n");
printf("*                           1> Book Name                              *\n");
printf("*                           2> Author                                 *\n");
printf("*                           3> ISBN                                   *\n");
printf("*                           4> Subject                                *\n");
printf("*                           5> Loan type                              *\n");
printf("*                           6> Shelf                                  *\n");
printf("*                           7> back                                *\n");
printf("***********************************************************************\n");
}

void menu_bookmanage()
{
printf("***********************************************************************\n");
printf("*                            -BOOK MANAGE-                            *\n");
printf("*                           1> Add Book                               *\n");
printf("*                           2> Delete Book                            *\n");
printf("*                           3> Modify information                     *\n");
printf("*                           4> Check Book List                        *\n");
printf("*                           5> Back To Previous Menu                  *\n");
printf("***********************************************************************\n");
}

void addbook(book *head)        
{
book *p1,*p2,*p3;  
book *new,*last;           
FILE *fp;
p1=p2=p3=(book*)malloc(sizeof(book));
last=head;                         
while(last->link!=NULL)             
{
last=last->link;
}
new=(book*)malloc(sizeof(book));   
if(new==NULL)
{
printf("Out of memory\n");
exit(1);
}
printf("Please enter the name of the book:\n");
fflush(stdin);
gets(new->book);
printf("Please enter the author of the book:\n");
fflush(stdin);
gets(new->author);
printf("Please enter the ISBN of book:\n");
fflush(stdin);
gets(new->ISBN);
/*
fp=fopen("librarybooks.txt","rb"); 
if(fp==NULL)
{
printf("file is opened unseccessfully.\n");
exit(1);
}
p2=head;                         
while(!feof(fp))                 
{
fread(p1,sizeof(book),1,fp); 
p2->link=p1;                     
p2=p1;                           
p1=(book*)malloc(sizeof(book));
}
p2->link=NULL;                  
fclose(fp);
p3=head;
if(head==NULL||head->link==NULL)
{
printf("No books in the library!\n");
}
else 
{
while(p3->link!=NULL)
{
p3=p3->link;
 if(strcmp(p3->ISBN,new->ISBN)==0)
 {
 printf("This ISBN already exists,Please change another!\n");
 exit(1);
 }
 }
 }
 */
printf("Please enter the subject of the book:\n");
fflush(stdin);
gets(new->subject);
printf("Please enter the loan type(normal, short loan, no-take-out) of the book:\n");
fflush(stdin);
gets(new->loan_type);
printf("Please enter the shelf(A1~A10) of book:\n");
fflush(stdin);
gets(new->shelf);
printf("Please enter the inventory(digit) of the book:\n");
fflush(stdin);
scanf("%d",&new->inventory);
getchar();
new->lend=0;
printf("Please enter the note (lost / damaged / ordered, etc.) of book:\n");
fflush(stdin);
gets(new->Note);
fp=fopen("librarybooks.txt","ab");  
if(fp==NULL)                        
{
printf("file is opened unseccessfully.\n");
exit(1);
}
fwrite(new,sizeof(book),1,fp);
fclose(fp);
last->link=new;                    
new->link=NULL;
printf("Add book successfully\n");
printf("Please enter any key to continue...");
getchar();                        
system("cls");
}

void searchbook_name(book *head)
{
char bookname[100];
int i=0;
FILE *fp;
book *p1,*p2,*p3;  
p1=p2=p3=(book*)malloc(sizeof(book));
fp=fopen("librarybooks.txt","rb"); 
if(fp==NULL)
{
printf("file is opened unseccessfully.\n");
exit(1);
}
p2=head;                         
while(!feof(fp))                 
{
fread(p1,sizeof(book),1,fp); 
p2->link=p1;                     
p2=p1;                           
p1=(book*)malloc(sizeof(book));
}
p2->link=NULL;                  
fclose(fp);
p3=head;
if(head==NULL||head->link==NULL)
{
printf("No books in the library!\n");
}
else
{
printf("Please enter the name of book:\n");
fflush(stdin);
gets(bookname);             
while(p3->link!=NULL)
{
p3=p3->link;
 if(strcmp(p3->book,bookname)==0)   
 {
printf("find following books\n");          
 printf("Book name: %s\n",p3->book);
 printf("Author name: %s\n",p3->author);
 printf("ISBN: %s\n",p3->ISBN);
 printf("Subject: %s\n",p3->subject);
 printf("Loan type: %s\n",p3->loan_type);
 printf("Shelf: %s\n",p3->shelf);
 printf("Inventoryt: %d\n",p3->inventory);
 printf("Lend number: %d\n",p3->lend);
 printf("Note: %s\n",p3->Note);
 i=1;                               
 }
 }
 if(i==0)                    
 {
 printf("this book is not in the library\n");
 }
 printf("Please enter any key to continue...");
 getchar();
 fflush(stdin);
 system("cls");  
}
}

void searchbook_author(book *head)
{
char bookauthor[100];
int i=0;
FILE *fp;
book *p1,*p2,*p3;  
p1=p2=p3=(book*)malloc(sizeof(book));
fp=fopen("librarybooks.txt","rb"); 
if(fp==NULL)
{
printf("file is opened unseccessfully.\n");
exit(1);
}
p2=head;                         
while(!feof(fp))                 
{
fread(p1,sizeof(book),1,fp); 
p2->link=p1;                     
p2=p1;                           
p1=(book*)malloc(sizeof(book));
}
p2->link=NULL;                  
fclose(fp);
p3=head;
if(head==NULL||head->link==NULL)
{
printf("No books in the library!\n");
}
else
{
printf("Please enter the author of book:\n");
fflush(stdin);
gets(bookauthor);             
while(p3->link!=NULL)
{
p3=p3->link;
 if(strcmp(p3->author,bookauthor)==0)   
 {
printf("find following books\n");          
 printf("Book name: %s\n",p3->book);
 printf("Author name: %s\n",p3->author);
 printf("ISBN: %s\n",p3->ISBN);
 printf("Subject: %s\n",p3->subject);
 printf("Loan type: %s\n",p3->loan_type);
 printf("Shelf: %s\n",p3->shelf);
 printf("Inventoryt: %d\n",p3->inventory);
 printf("Lend number: %d\n",p3->lend);
 printf("Note: %s\n",p3->Note);
 i=1;                         
 }
 }
 if(i==0)                    
 {
 printf("this book is not in the library\n");
 }
 printf("Please enter any key to continue...");
 getchar();
 fflush(stdin);
 system("cls"); 
}
}

void searchbook_ISBN(book *head)
{
char bookISBN[100];
int i=0;
FILE *fp;
book *p1,*p2,*p3;  
p1=p2=p3=(book*)malloc(sizeof(book));
fp=fopen("librarybooks.txt","rb"); 
if(fp==NULL)
{
printf("file is opened unseccessfully.\n");
exit(1);
}
p2=head;                         
while(!feof(fp))                 
{
fread(p1,sizeof(book),1,fp); 
p2->link=p1;                     
p2=p1;                           
p1=(book*)malloc(sizeof(book));
}
p2->link=NULL;                  
fclose(fp);
p3=head;
if(head==NULL||head->link==NULL)
{
printf("No books in the library!\n");
}
else
{
printf("Please enter the ISBN of book:\n");
fflush(stdin);
gets(bookISBN);             
while(p3->link!=NULL)
{
p3=p3->link;
 if(strcmp(p3->ISBN,bookISBN)==0)   
 {
printf("find following books\n");          
 printf("Book name: %s\n",p3->book);
 printf("Author name: %s\n",p3->author);
 printf("ISBN: %s\n",p3->ISBN);
 printf("Subject: %s\n",p3->subject);
 printf("Loan type: %s\n",p3->loan_type);
 printf("Shelf: %s\n",p3->shelf);
 printf("Inventoryt: %d\n",p3->inventory);
 printf("Lend number: %d\n",p3->lend);
 printf("Note: %s\n",p3->Note);
 i=1;                         
 }
 }
 if(i==0)                    
 {
 printf("this book is not in the library\n");
 }
 printf("Please enter any key to continue...");
 getchar();
 fflush(stdin);
 system("cls"); 
}
}

void searchbook_subject(book *head)
{
char booksubject[100];
int i=0;
FILE *fp;
book *p1,*p2,*p3;  
p1=p2=p3=(book*)malloc(sizeof(book));
fp=fopen("librarybooks.txt","rb"); 
if(fp==NULL)
{
printf("file is opened unseccessfully.\n");
exit(1);
}
p2=head;                         
while(!feof(fp))                 
{
fread(p1,sizeof(book),1,fp); 
p2->link=p1;                     
p2=p1;                           
p1=(book*)malloc(sizeof(book));
}
p2->link=NULL;                  
fclose(fp);
p3=head;
if(head==NULL||head->link==NULL)
{
printf("No books in the library!\n");
}
else
{
printf("Please enter the subject of book:\n");
fflush(stdin);
gets(booksubject);             
while(p3->link!=NULL)
{
p3=p3->link;
 if(strcmp(p3->subject,booksubject)==0)   
 {
printf("find following books\n");          
 printf("Book name: %s\n",p3->book);
 printf("Author name: %s\n",p3->author);
 printf("ISBN: %s\n",p3->ISBN);
 printf("Subject: %s\n",p3->subject);
 printf("Loan type: %s\n",p3->loan_type);
 printf("Shelf: %s\n",p3->shelf);
 printf("Inventoryt: %d\n",p3->inventory);
 printf("Lend number: %d\n",p3->lend);
 printf("Note: %s\n",p3->Note);
 i=1;                         
 }
 }
 if(i==0)                    
 {
 printf("this book is not in the library\n");
 }
 printf("Please enter any key to continue...");
 getchar();
 fflush(stdin);
 system("cls"); 
}
}

void searchbook_loan(book *head)
{
char bookloan[100];
int i=0;
FILE *fp;
book *p1,*p2,*p3;  
p1=p2=p3=(book*)malloc(sizeof(book));
fp=fopen("librarybooks.txt","rb"); 
if(fp==NULL)
{
printf("file is opened unseccessfully.\n");
exit(1);
}
p2=head;                         
while(!feof(fp))                 
{
fread(p1,sizeof(book),1,fp); 
p2->link=p1;                     
p2=p1;                           
p1=(book*)malloc(sizeof(book));
}
p2->link=NULL;                  
fclose(fp);
p3=head;
if(head==NULL||head->link==NULL)
{
printf("No books in the library!\n");
}
else
{
printf("Please enter the loan type of book:\n");
fflush(stdin);
gets(bookloan);             
while(p3->link!=NULL)
{
p3=p3->link;
 if(strcmp(p3->loan_type,bookloan)==0)   
 {
printf("find following books\n");          
 printf("Book name: %s\n",p3->book);
 printf("Author name: %s\n",p3->author);
 printf("ISBN: %s\n",p3->ISBN);
 printf("Subject: %s\n",p3->subject);
 printf("Loan type: %s\n",p3->loan_type);
 printf("Shelf: %s\n",p3->shelf);
 printf("Inventoryt: %d\n",p3->inventory);
 printf("Lend number: %d\n",p3->lend);
 printf("Note: %s\n",p3->Note);
 i=1;                         
 }
 }
 if(i==0)                    
 {
 printf("this book is not in the library\n");
 }
 printf("Please enter any key to continue...");
 getchar();
 fflush(stdin);
 system("cls"); 
}
}

void searchbook_shelf(book *head)
{
char bookshelf[100];
int i=0;
FILE *fp;
book *p1,*p2,*p3;  
p1=p2=p3=(book*)malloc(sizeof(book));
fp=fopen("librarybooks.txt","rb"); 
if(fp==NULL)
{
printf("file is opened unseccessfully.\n");
exit(1);
}
p2=head;                         
while(!feof(fp))                 
{
fread(p1,sizeof(book),1,fp); 
p2->link=p1;                     
p2=p1;                           
p1=(book*)malloc(sizeof(book));
}
p2->link=NULL;                  
fclose(fp);
p3=head;
if(head==NULL||head->link==NULL)
{
printf("No books in the library!\n");
}
else
{
printf("Please enter the book shelf of book:\n");
fflush(stdin);
gets(bookshelf);             
while(p3->link!=NULL)
{
p3=p3->link;
 if(strcmp(p3->shelf,bookshelf)==0)   
 {
printf("find following books\n");          
 printf("Book name: %s\n",p3->book);
 printf("Author name: %s\n",p3->author);
 printf("ISBN: %s\n",p3->ISBN);
 printf("Subject: %s\n",p3->subject);
 printf("Loan type: %s\n",p3->loan_type);
 printf("Shelf: %s\n",p3->shelf);
 printf("Inventoryt: %d\n",p3->inventory);
 printf("Lend number: %d\n",p3->lend);
 printf("Note: %s\n",p3->Note);
 i=1;                                    
 }
 }
 if(i==0)                    
 {
 printf("this book is not in the library\n");
 }
 printf("Please enter any key to continue...");
 getchar();
 fflush(stdin);
 system("cls"); 
}
}


main()                              
{
int choice=0;
int choose=0;
int option;
book *head;                 
head=(book*)malloc(sizeof(book));  
head->link=NULL;
printf(" 1-for adm \n");
printf(" 2-for student \n");
scanf("%d",&option);
getchar();
if(option==1)
{
for(;choice!=3;)                    
{
printf("***********************************************************************\n");
printf("*                  Welcome to library manage system                   *\n");
printf("*                           1> Book manage                            *\n");
printf("*                           2> User manage                            *\n");
printf("*                           3> Log out                                *\n");
printf("***********************************************************************\n");
scanf("%d",&choice);
switch(choice)                      
{
case 1: 
system("cls");
menu_bookmanage();
printf(" Please choose options\n");
scanf("%d",&choose);
getchar();
if(choose==1)
{
system("cls");
addbook(head);
}
if(choose==2)
{
system("cls");
delete_book(head);
}
if(choose==3)
{
system("cls");
modifybook(head);
}
if(choose==4)
{
system("cls");
booklist_unborrowed(head);
printf("******************************\n");
booklist_borrowed(head);
}
break;
case 2:
system("cls");

break;
case 3:
break;
default:
printf("Please enter the correct integer number.");
}
}
}
if(option==2)
{
for(;choice!=4;)                    
{
printf("***********************************************************************\n");
printf("*                      Welcome to library system                      *\n");
printf("*                           1> Search Book                            *\n");
printf("*                           2> Borrow book                            *\n");
printf("*                           3> Return book                            *\n");
printf("*                           4> Log out                                *\n");
printf("*                                                    student account  *\n");
printf("***********************************************************************\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
system("cls");
menu_searchbook();
printf(" Please choose a way to search book\n");
scanf("%d",&choose);
getchar();
if(choose==1)
{
system("cls");
searchbook_name(head);
}
if(choose==2)
{
system("cls");
searchbook_author(head);
}
if(choose==3)
{
system("cls");
searchbook_ISBN(head);
}
if(choose==4)
{
system("cls");
searchbook_subject(head);
}
if(choose==5)
{
system("cls");
searchbook_loan(head);
}
if(choose==6)
{
system("cls");
searchbook_shelf(head);
}
if(choose==7)
{
system("cls");
}
break;
case 2:
system("cls");
borrowbook(head);
break;
case 3:
system("cls");
returnbook(head);
break;
case 4:
break;
default:
printf("Please enter the correct integer number.");
}
}
}
}

