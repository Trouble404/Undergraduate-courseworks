#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

/*define struct of book*/ 
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
/*define struct of user card*/
typedef struct card{
	char username[100];
	char password[100];
	char type;
	char history1[100];
	struct card *link;
} card;

card *User;

void login(card*,book*);
void Register();
void menu_normal(card*,book*);
void menu_Admin(card*,book*);
void menu_welcome(card*,book*);
void AdminOption();
void My_information();
void search();
void Return(card*,book*);
void booklist_unborrowed(book*);
void booklist_borrowed(book*);
void add_book(book*);
void delete_book(book*);
void modify(book*);
void delete_user(card*);
void menu_searchbook();
void searchbook_name(book*);
void searchbook_author(book*);
void searchbook_ISBN(book*);
void searchbook_subject(book*);
void searchbook_loan(book*);
void searchbook_shelf(book*);
void borrow(card*,book*);
/*define user with card login in book system */
void login(card *cardhead,book *head){
	int choice,a=0,b=0,c=1,d;
	char username[100],password[100],B;
	FILE *fp1;
	card *p1,*p2,*p3,*r1,*r2,*r3,*r4,*r5;
	/*allocate memory for card ptr*/
	r5=r1=r2=r3=r4=p1=p2=(card*)malloc(sizeof(card));
	/*open card file which store the information of all user cards*/
	fp1=fopen("card.txt","rb");
	/*if fp1 is NULL output reminder information*/ 
	if(fp1==NULL)
	{
		printf("Thre is not any user in this system. Please register first!\n");
		exit(1);
	}
	p2=cardhead;
	/*if fp1 is not NULL read file*/ 
	while(!feof(fp1))
	{
		fread(p1,sizeof(card),1,fp1);
		p2->link=p1;
		p2=p1;
		p1=(card*)malloc(sizeof(card));
	}
	p2->link=NULL;
	fclose(fp1);
	/*the process of login*/ 
	while(b==0)
	{
		p3=cardhead;
		printf("Please enter your username: \n");
		scanf("%s",&username);
	
		while(p3->link!=NULL)
		{
			p3=p3->link;
			/*if username exist in the card ,it means the user can borrow books */
			if(strcmp(p3->username,username)==0)
			{
				b=1;
				while(a!=1)
				{
					/*enter userpassword*/
					printf("Please enter your password: \n");
					scanf("%s",&password);
					/*if the password typed is same with it in the card */
					if(strcmp(p3->password,password)==0)
					{
						printf("Log in successfully!\n");
						a=1;
						User=p3;

					}
					else
					{
						printf("Password is not correct. Please enter again\n");
					}
				}
			}
		}
		if(b==0)
			printf("This username does not exist! Please enter again.\n");
	}
}


/*define a new user register the system*/  
void Register(card *cardhead)
{
	int choice,a=0,b=0,c=1,d;
	char username[100],password[100];
	FILE *fp1;
	card *p1,*p2,*p3,*r1,*r2,*r3,*r4,*r5;
	r5=r1=r2=r3=r4=p1=p2=(card*)malloc(sizeof(book));
	/*open card in ab+ mode*/
	fp1=fopen("card.txt","ab+");
	if(fp1==NULL)
	{
		printf("Fail to open the file!");
	}
	fclose(fp1);
	/*open card in r mode*/
	fp1=fopen("card.txt","r");
	if(fp1==NULL)
	{
		printf("Fail to open the file!\n");
		exit(1);
	}
	r1=cardhead;

	while(!feof(fp1))
	{
		fread(r5,sizeof(card),1,fp1);
		r1->link=r5;
		r1=r5;
		r5=(card*)malloc(sizeof(card));
	}
	r1->link=NULL;
	fclose(fp1);
	/*open card in ab mode*/
	fp1=fopen("card.txt","ab");
	if(fp1==NULL)
	{
		printf("Fail to open the file!");
	}
	r3=cardhead;
	while(r3->link!=NULL)
	{
		r3=r3->link;
	}
	/*the process of register username you type should be unique*/ 
	while(c==1)
	{
		r4=cardhead;
		printf("Please enter your username (Note: username cannot include space): \n");
		scanf("%s",&username);
		while(r4->link!=NULL)
		{
			r4=r4->link;
			/*check username*/ 
			if(strcmp(r4->username,username)==0)
			{
				printf("This username has existed. Please choose another one.\n");
				c=0;
			}
		}
		c++;
	}
	/*copy username*/
	strcpy(r2->username,username);
	printf("Please enter your password: \n");
	fflush(stdin);
	gets(r2->password);
	printf("Are you the teacher or the student?\n");
	printf("1. Teacher\n");
	printf("2. Student\n");
	scanf("%d",&d);
	/* type role of user*/
	switch(d)
	{
	case 1:
		r2->type='T';
		break;
	case 2:
		r2->type='S';
		break;
	default:
		printf("Please choose correct item!\n");
	}
	/* init borrow history of the user*/
	r2->history1[0]='\0';
	fwrite(r2,sizeof(card),1,fp1);
	fclose(fp1);
	r3->link=r2;
	r2->link=NULL;
	printf("Register successfully!\n");
}


/*the main interface of user borrow system */
void menu_normal(card *cardhead,book *head){
	FILE *fp;
	book *p1,*p2;
	char bookname[100];
	int choice;
	p1=p2=(book*)malloc(sizeof(book));
	/*open card in ab+ mode*/
	fp=fopen("librarybooks.txt","ab+");
	if(fp==NULL)
	{
		printf("file is opened unseccessfully.\n");
		exit(1);
	}
	fclose(fp);
	/*open card in rb mode*/
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
	/* init interface of user panel*/
	printf("             *************************************************\n");
	printf("             *                                               *\n");
	printf("             *              Please choose items:             *\n");
	printf("             *                                               *\n");
	printf("             *               1> My information               *\n");
	printf("             *               2> Search book                  *\n");
	printf("             *               3> Borrow book                  *\n");
	printf("             *               4> return book                  *\n");
	printf("             *               5> View all available book      *\n");
	printf("             *               6> Log off                      *\n");
	printf("             *               7> Quit                         *\n");
	printf("             *                                               *\n");
	printf("             *************************************************\n");

	scanf("%d",&choice);
	/*process by different choice*/ 
	switch(choice)
	{
		/*My information*/ 
	case 1:
		system("cls");
		My_information();
		printf("Enter any key to return last menu.\n");
		fflush(stdin);
		getchar();
		system("cls");
		menu_normal(cardhead,head);
		break;
		/*Search book*/
	case 2:
		system("cls");
		search(head);
		menu_normal(cardhead,head);
		break;
	case 3:
		/*Borrow book*/ 
		system("cls");
		borrow(User,head);
		menu_normal(cardhead,head);
		break;
		/*return book*/
	case 4:
		system("cls");
		Return(User,head);
		menu_normal(cardhead,head);
		break;
		/*View all available book*/
	case 5:
		system("cls");
		booklist_unborrowed(head);
		fflush(stdin);
		getchar();
		system("cls");
		menu_normal(cardhead,head);
		break;
		/*Log off*/
	case 6:
		system("cls");
		User=NULL;
		menu_welcome(cardhead,head);
		break;
		/*quit*/
	case 7:
		break;
	default:
		printf("Please choose correct option!\n");
	}
}
/* the main interface of somebody who login as an admin */
void menu_Admin(card *cardhead,book *head){
	/* init panel of admin*/
	int choice;
	printf("              *************************************************\n");
	printf("              *                                               *\n");
	printf("              *            Please choose items below:         *\n");
	printf("              *                                               *\n");
	printf("              *          1> Add books                         *\n");
	printf("              *          2> Delete books                      *\n");
	printf("              *          3> Modify informatons of books       *\n");
	printf("              *          4> Delete Users                      *\n");
	printf("              *          5> View all books on loan            *\n");
	printf("              *          6> Return to previous menu           *\n");
	printf("              *          7> Quit                              *\n");
	printf("              *                                               *\n");
	printf("              *************************************************\n");
	scanf("%d",&choice);
	/*process  by different choice*/ 
	switch(choice)
	{
		/*add book*/
	case 1:
		system("cls");
		add_book(head);
		menu_Admin(cardhead,head);
		break;
		/*delete book*/ 
	case 2:
		system("cls");
		delete_book(head);
		printf("Please enter any key to continue...\n");
		fflush(stdin);
		getchar();
		system("cls");
		menu_Admin(cardhead,head);
		break;
		/*modify book*/
	case 3:
		system("cls");
		modify(head);
		printf("Please enter any key to continue...\n");
		fflush(stdin);
		getchar();
		system("cls");
		menu_Admin(cardhead,head);
		break;
		/*delete user*/ 
	case 4:
		system("cls");
		delete_user(cardhead);
		printf("Enter any key to continue...\n");
		fflush(stdin);
		getchar();
		system("cls");
		menu_Admin(cardhead,head);
		break;
		/*view all users on loan*/
	case 5:
		system("cls");
		booklist_borrowed(head);
		printf("Enter any key to continue...\n");
		fflush(stdin);
		getchar();
		system("cls");
		menu_Admin(cardhead,head);
		break;
		/*Return last menu*/ 	
	case 6:
		system("cls");
		menu_welcome(cardhead,head);
		break;
	case 7:
		break;
	default:
		printf("Please choose correct option!");
	}
}
/*welcome interface */
void menu_welcome(card *cardhead,book *head){
	int choice;
	/*init welcome panel*/
	printf("              *************************************************\n");
	printf("              *                                               *\n");
	printf("              *               Welcome to Library!             *\n");
	printf("              *                                               *\n");
	printf("              *            Please choose items below:         *\n");
	printf("              *                                               *\n");
	printf("              *                  1> Log in                    *\n");
	printf("              *                  2> Register                  *\n");
	printf("              *             3> Administrator option           *\n");
	printf("              *                  4> Quit                      *\n");
	printf("              *                                               *\n");
	printf("              *                              By group B8      *\n");
	printf("              *************************************************\n");
	scanf("%d",&choice);
	/*process by different choice*/ 
	switch(choice)
	{
		/*Log in*/ 
	case 1:
		system("cls");
		login(cardhead,head);
		fflush(stdin);
		getchar();
		system("cls");
		menu_normal(cardhead,head);
		break;
		/*Register*/	
	case 2:
		system("cls");
		Register(cardhead);
		printf("Enter any key to continue...\n");
		fflush(stdin);
		getchar();
		system("cls");
		menu_welcome(cardhead,head);
		break;
		/* Administrator option*/
	case 3:
		system("cls");
		AdminOption(cardhead,head);
		printf("Enter any key to continue...\n");
		getchar();
		system("cls");
		break;
		/*quit*/ 
	case 4:
		break;
	default:
		printf("Please choose correct items!\n");
	}
}
/*interface of search :search book by different choice */
void menu_searchbook()
{
	/*init searchbook panel*/
	printf("***********************************************************************\n");
	printf("*                            -SEARCH BOOK-                            *\n");
	printf("*                           1> Book Name                              *\n");
	printf("*                           2> Author                                 *\n");
	printf("*                           3> ISBN                                   *\n");
	printf("*                           4> Subject                                *\n");
	printf("*                           5> Loan type                              *\n");
	printf("*                           6> Shelf                                  *\n");
	printf("*                           7> back                                   *\n");
	printf("***********************************************************************\n");
}




/*init all the varible */
main(){
	card *cardhead;
	book *head;
	head=(book*)malloc(sizeof(book));
	cardhead=(card*)malloc(sizeof(card));
	User=(card*)malloc(sizeof(card));
	cardhead->link=NULL;
	head->link=NULL;
	menu_welcome(cardhead,head);

}


/*print user information*/
void My_information(){
	char teacher[]="teacher",student[]="student";
	printf("Username: %s\n",User->username);
	/* print by the type of him */
	if(User->type=='S')
		printf("Type: %s\n",student);
	else
		printf("Type: %s\n",teacher);
	/*if not init the history of the user */
	if(User->history1[0]=='\0')
		printf("No history.\n");
	else
	{
		printf("History: %s\n",User->history1);
		if(User->type=='S')
			printf("      Time Limit: 30 days.");
		else
			printf("      Time Limit: 60 days.");
	}


}

/*interface process of  book search*/
void search(book *head){
	int choose;
	menu_searchbook();
	printf(" Please choose a way to search book\n");
	scanf("%d",&choose);
	/*choose by the factor you want to search book by */
	switch(choose)
	{
		/*searchbook by name*/ 
	case 1:
		system("cls");
		searchbook_name(head);
		break;
		/*searchbook by author*/ 
	case 2:
		system("cls");
		searchbook_author(head);
		break;
		/*searchbook by ISBN*/
	case 3:
		system("cls");
		searchbook_ISBN(head);
		break;
		/*searchbook by subject*/
	case 4:
		system("cls");
		searchbook_subject(head);
		break;
		/*searchbook by loan*/
	case 5:
		system("cls");
		searchbook_loan(head);
		break;
		/*searchbook by shelf*/
	case 6:
		system("cls");
		searchbook_shelf(head);
		break;
		/*searchbook by default*/
	case 7:
		system("cls");
		break;
	default:
		printf("Please choose correct option!\n");
	}

}

/*return book*/ 
void Return(card *cardhead, book *head)
{
	FILE *fp,*fp1;
	int a,b;
	int b_choose;
	char borrow_ISBN[100],tem[100];
	int i=0;
	book *p3;
	card *c1,*c2,*c3,*c4;
	p3=(book*)malloc(sizeof(book));
	c4=c1=c2=c3=(card*)malloc(sizeof(card));
	p3=head;
	/*if book ptr is NULL it means no information for the book before */
	if(head==NULL||head->link==NULL)
	{
		printf("No books in the library!\n");
	}
	else
	{
		/*return book by ISBN the book should be exist in the booklibrary*/
		printf("Please enter the book'ISBN which you want to return:\n");
		fflush(stdin);
		gets(borrow_ISBN);
		while(p3->link!=NULL)
		{
			p3=p3->link;
			/*if borrow ISBN exist in the book library*/
			if(strcmp(p3->ISBN,borrow_ISBN)==0)
			{
				printf("find this book\n");
				printf("Book name: %s\n",p3->book);
				printf("Author name: %s\n",p3->author);
				printf("ISBN: %s\n",p3->ISBN);
				printf("Inventory: %d\n",p3->inventory);
				printf("Lend number: %d\n",p3->lend);
				printf("Note: %s\n",p3->Note);
				a=p3->inventory;
				b=p3->lend;
				/* if b>0 it means the book has been lent to this user */
				if(b>0)
				{
					printf("\nDo you want to return this book?\n");
					printf("1-Yes and 2-No\n");
					scanf("%d",&b_choose);
					getchar();
					/* the user will return this borrowed book*/
					if(b_choose==1)
					{

						if(strcmp(User->history1,p3->book)==0)
						{
							/*open library and change the book information*/
							p3->inventory=a+1;
							p3->lend=b-1;
							strcpy(User->history1,"\0");
							strcpy(tem,User->username);

							fp1=fopen("card.txt","r");
							if(fp1==NULL)
							{
								printf("Fail to open the file!\n");
								exit(1);
							}
							c1=cardhead;
							while(!feof(fp1))
							{
								fread(c2,sizeof(card),1,fp1);
								c1->link=c2;
								c1=c2;
								c2=(card*)malloc(sizeof(card));
							}
							c1->link=NULL;
							fclose(fp1);
							c3=cardhead;
							while(c3->link!=NULL)
							{
								c3=c3->link;
								if(strcmp(c3->username,tem)==0)
									strcpy(c3->history1,"\0");
							}
							/*open user and change the borrowed information*/
							fp1=fopen("card.txt","w");
							c4=cardhead;
							while(c4->link!=NULL)
							{
								c4=c4->link;
								fwrite(c4,sizeof(card),1,fp1);
							}
							fclose(fp1);
							printf("return book successfully!\n");
						}
						else
						{printf("You do not borrow this book!\n");
						menu_normal(cardhead,head);}



					}
					/*do not return*/ 
					if(b_choose==2)
					{
						printf("cancel operation\n");
						break;
					}
				}
				/*the book did not lend to this user ever before*/ 
				if(b==0)
				{
					printf("This book haven't borrowed!\n");
				}
				i=1;
			}
		}
		/*book not exist in the library*/
		if(i==0)
		{
			printf("this book is not in the library\n");
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
		printf("Please enter any key to continue...");
		getchar();
		fflush(stdin);
		system("cls");
	}
}


void viewBook(book *head){}

void AdminOption(card *cardhead,book *head){
	menu_Admin(cardhead,head);
}

/*add a book to the system*/ 
void add_book(book *head)
{
	int i=1;
	book *p1,*p2,*p3;
	book *new,*last;
	FILE *fp;
	/*open library*/
	fp=fopen("librarybooks.txt","ab+");
	if(fp=NULL)
	{
		printf("Fail to open the file!\n");
		exit(1);
	}
	fclose(fp);
	p1=p2=p3=(book*)malloc(sizeof(book));
	new=(book*)malloc(sizeof(book));
	/*allocate memory failed*/
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
	/*type the information of the new book*/ 
	while(i==1)
	{
		printf("Please enter the ISBN of book:\n");
		fflush(stdin);
		gets(new->ISBN);
		fp=fopen("librarybooks.txt","rb");
		
		if(fp==NULL)
		{
			printf("file is opened unseccessfully.\n");
			exit(1);
		}
		/*read file*/ 
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
		/*check if the adding book already exists in the library*/
		if(head==NULL||head->link==NULL)
		{
			printf("No books in the library!\n");
		}
		else
		{
			while(p3->link!=NULL)
			{
				p3=p3->link;
				/* the ISBN typed is already existed*/
				if(strcmp(p3->ISBN,new->ISBN)==0)
				{
					printf("This ISBN already exists,Please change another!\n");
					i=0;
				}
			}
		}
		i++;
	}
	/*type all the information of the new book*/ 
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
	printf("Add book successfully\n");
	printf("Please enter any key to continue...");
	fflush(stdin);
	getchar();
	system("cls");
}


/*delete a book from the book library*/ 
void delete_book(book *head)
{
	char bookISBN[100];
	FILE *fp;
	book *p1,*p2,*p3,*p4,*p5;
	int i=1;
	fp=fopen("librarybooks.txt","rb");
	/*no such book exist*/ 
	if(fp==NULL)
	{
		printf("There is no book in the system. Please add first!\n");
		exit(1);
	}
	p5=p4=p3=p1=p2=(book*)malloc(sizeof(book));
	p1=head;
	/*read file*/ 
	while(!feof(fp))
	{
		fread(p2,sizeof(book),1,fp);
		p1->link=p2;
		p1=p2;
		p2=(book*)malloc(sizeof(book));
	}
	p1->link=NULL;
	fclose(fp);
	/*delete book by ISBN*/ 
	while(i==1)
	{
		printf("Please enter the ISBN of book which will be deleted: \n");
		fflush(stdin);
		gets(bookISBN);
		p5=p4=head;
		while(p4->link!=NULL)
		{
			p4=p4->link;
			if(strcmp(bookISBN,p4->ISBN)==0)
			{
				i=0;
				p5->link=p4->link;
				/*open file in w mode to type information*/
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
				printf("Delete book successfully!\n");
			}
			p5=p5->link;
		}
		if(i==1)
			printf("This book does not exist! Please enter anain!\n");

	}


}
/*modify the information of the book*/ 
void modify(book *head){
	char modify_name[100];
	char modify_author[100];
	char modify_ISBN[100];
	char modify_subject[100];
	char modify_loan[100];
	char modify_shelf[100];
	int modify_inventory;
	int modify_lend;
	char modify_Note[100];
	char bookISBN[100];
	char modify_note[100];
	int i=0;
	int choose;
	FILE *fp;
	book *p1,*p2,*p3;
	p1=p2=p3=(book*)malloc(sizeof(book));

	/*open file in rb mode*/ 
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
	/*no such book exist*/
	if(head==NULL||head->link==NULL)
	{
		printf("No books in the library!\n");
	}
	/*modify by the ISBN of the book*/ 
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
					/*init modify book information panel*/
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
					printf("*      9>book note         *\n");
					printf("*                          *\n");
					printf("*      10>MODIFY           *\n");
					printf("****************************\n");
					fflush(stdin);
					scanf("%d",&choose);
					getchar();
					/* modify the information the user want*/ 
					switch(choose)
					{
						/*book name*/
					case 1:
						printf("origin book name: %s\n",p3->book);
						printf("Please enter new book name\n");
						strcpy(p3->book,"");
						gets(modify_name);
						strcpy(p3->book,modify_name);
						break;
						/*book author*/
					case 2:
						printf("origin book author: %s\n",p3->author);
						printf("Please enter new book author\n");
						strcpy(p3->author,"");
						gets(modify_author);
						strcpy(p3->author,modify_author);
						break;
						/*book ISBN */
					case 3:
						printf("origin book ISBN: %s\n",p3->ISBN);
						printf("Please enter new book ISBN\n");
						strcpy(p3->ISBN,"");
						gets(modify_ISBN);
						strcpy(p3->ISBN,modify_ISBN);
						break;
						/*book subject*/
					case 4:
						printf("origin book subject: %s\n",p3->subject);
						printf("Please enter new book subject\n");
						strcpy(p3->subject,"");
						gets(modify_subject);
						strcpy(p3->subject,modify_subject);
						break;
						/*book loan type*/
					case 5:
						printf("origin book loan type: %s\n",p3->loan_type);
						printf("Please enter new book loan type\n");
						strcpy(p3->loan_type,"");
						gets(modify_loan);
						strcpy(p3->loan_type,modify_loan);
						break;
						/*book shelf*/
					case 6:
						printf("origin book shelf: %s\n",p3->shelf);
						printf("Please enter new book shelf\n");
						strcpy(p3->shelf,"");
						gets(modify_shelf);
						strcpy(p3->shelf,modify_shelf);
						break;
						/*book inventory*/
					case 7:
						printf("origin book inventory: %d\n",p3->inventory);
						printf("Please enter new book inventory\n");
						scanf("%d",&modify_inventory);
						getchar();
						p3->inventory=modify_inventory;
						break;
						/*book lend*/
					case 8:
						printf("origin book lend number: %d\n",p3->lend);
						printf("Please enter new book lend number\n");
						scanf("%d",&modify_lend);
						getchar();
						p3->lend=modify_lend;
						break;
						/*book note*/
					case 9:
						printf("origin book note: %s\n",p3->Note);
						printf("Please enter new book note\n");
						strcpy(p3->Note,"");
						gets(modify_note);
						strcpy(p3->Note,modify_note);
						break;
						/* modify*/
					case 10:
						printf("Modify successfully\n");
						break;
					default:
						printf("Please enter the correct integer number.");
					}
				}
				while(choose!=10);
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

		}
	}
}
/* deleter user from the card */
/* when deleted the user can not borrow a book again*/
void delete_user(card* cardhead){
	char username[100];
	FILE *fp;
	card *p1,*p2,*p3,*p4,*p5;
	int i=1;
	User=NULL;
	/*open file*/ 
	fp=fopen("card.txt","rb");
	if(fp==NULL)
	{
		printf("Fail to open the file!\n");
		exit(1);
	}
	p5=p4=p3=p1=p2=(card*)malloc(sizeof(card));
	p1=cardhead;
	/*read file*/ 
	while(!feof(fp))
	{
		fread(p2,sizeof(card),1,fp);
		p1->link=p2;
		p1=p2;
		p2=(card*)malloc(sizeof(card));
	}
	p1->link=NULL;
	fclose(fp);
	/*delete user by username*/
	while(i==1)
	{
		printf("Please enter the username which will be deleted: \n");
		scanf("%s",&username);
		p5=p4=cardhead;

		while(p4->link!=NULL)
		{
			p4=p4->link;
			if(strcmp(username,p4->username)==0)
			{
				i=0;
				p5->link=p4->link;
				fp=fopen("card.txt","w");
				if(fp==NULL)
				{
					printf("Fail to open the file!\n");
					exit(1);
				}
				p3=cardhead;
				/*delete user from system*/
				while(p3->link!=NULL)
				{
					p3=p3->link;
					fwrite(p3,sizeof(card),1,fp);
				}
				fclose(fp);
				printf("Delete user successfully!\n");
			}
			p5=p5->link;
		}

		if(i==1)
			printf("This username does not exist! Please enter again!\n");

	}

}
/*search a book by the name */
void searchbook_name(book *head){
	char bookname[100];
	book *p3;
	int i=0;
	p3=(book*)malloc(sizeof(book));
	p3=head;
	if(head==NULL||head->link==NULL)
	{
		printf("No books in the library!\n");
		exit(1);
	}
	else
	{
		printf("Please enter the name of book:\n");
		fflush(stdin);
		gets(bookname);
		/*list all the information of the book */
		while(p3->link!=NULL)
		{
			p3=p3->link;
			/*init search panel*/
			if(strcmp(p3->book,bookname)==0)
			{
				printf("find following books\n");          
				printf("Book name: %s\n",p3->book);
				printf("Author name: %s\n",p3->author);
				printf("ISBN: %s\n",p3->ISBN);
				printf("Subject: %s\n",p3->subject);
				printf("Loan type: %s\n",p3->loan_type);
				printf("Shelf: %s\n",p3->shelf);
				printf("Inventory: %d\n",p3->inventory);
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

/*search the book by author */
void searchbook_author(book* head)
{
	char bookauthor[100];
	int i=0;
	book* p3;
	p3=(book*)malloc(sizeof(book));
	p3=head;
	if(head==NULL||head->link==NULL)
	{
		printf("No books in the library!\n");
	}
	else
	{
		/* list all the information of the book */
		printf("Please enter the author of book:\n");
		fflush(stdin);
		gets(bookauthor);             
		while(p3->link!=NULL)
		{
			p3=p3->link;
			/*init search panel*/
			if(strcmp(p3->author,bookauthor)==0)   
			{
				printf("find following books\n");          
				printf("Book name: %s\n",p3->book);
				printf("Author name: %s\n",p3->author);
				printf("ISBN: %s\n",p3->ISBN);
				printf("Subject: %s\n",p3->subject);
				printf("Loan type: %s\n",p3->loan_type);
				printf("Shelf: %s\n",p3->shelf);
				printf("Inventory: %d\n",p3->inventory);
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
/*search book by ISBN */
void searchbook_ISBN(book *head)
{
	char bookISBN[100];
	int i=0;
	book *p3;
	p3=(book*)malloc(sizeof(book));
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
		{/*init search panel*/
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
				printf("Inventory: %d\n",p3->inventory);
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
/*search book by subject*/
void searchbook_subject(book* head)
{
	char booksubject[100];
	int i=0;
	book *p3;
	p3=(book*)malloc(sizeof(book));
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
		{/*init search panel*/
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
				printf("Inventory: %d\n",p3->inventory);
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
/*search book by loan*/
void searchbook_loan(book *head)
{
	char bookloan[100];
	int i=0;
	book *p3;
	p3=(book*)malloc(sizeof(book));
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
		{/*init search panel*/
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
				printf("Inventory: %d\n",p3->inventory);
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
/*search book by shelf */
void searchbook_shelf(book *head)
{
	char bookshelf[100];
	int i=0;
	book *p3;
	p3=(book*)malloc(sizeof(book));
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
		{/*init search panel*/
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
				printf("Inventory: %d\n",p3->inventory);
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
/* borrow book by ISBN*/ 
void borrow(card* cardhead, book *head)
{
	FILE *fp,*fp1;
	int a,b;
	int b_choose;
	char borrow_ISBN[100],tem[100];
	int i=0;
	book *p3;
	card *c1,*c2,*c3,*c4,*c5;
	c5=c4=c3=c1=c2=(card*)malloc(sizeof(card));
	p3=(book*)malloc(sizeof(book));
	p3=head;
	/*no such book*/
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
			{/*init borrow panel*/
				printf("find this book\n");          
				printf("Book name: %s\n",p3->book);
				printf("Author name: %s\n",p3->author);
				printf("ISBN: %s\n",p3->ISBN);
				printf("Inventory: %d\n",p3->inventory);
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
						if(User->history1[0]=='\0')
						{
							p3->inventory=a-1;
							p3->lend=b+1;
							strcpy(User->history1,p3->book);
							strcpy(tem,User->username);
							fp1=fopen("card.txt","r");
							if(fp1==NULL)
							{
								printf("Fail to open the file!\n");
								exit(1);
							}
							c1=cardhead;
							while(!feof(fp1))
							{
								fread(c2,sizeof(card),1,fp1);
								c1->link=c2;
								c1=c2;
								c2=(card*)malloc(sizeof(card));
							}
							c1->link=NULL;
							fclose(fp1);
							c3=cardhead;
							while(c3->link!=NULL)
							{
								c3=c3->link;
								if(strcmp(c3->username,tem)==0)
								{
									strcpy(c3->history1,p3->book);
								}
							}
							fp1=fopen("card.txt","w");
							if(fp1==NULL)
							{
								printf("Fail to open the file!\n");
								exit(1);
							}
							c4=cardhead;
							while(c4->link!=NULL)
							{
								c4=c4->link;
								fwrite(c4,sizeof(card),1,fp1);
							}

                            fclose(fp1);
							printf("borrow book successfully!\n");
							if(User->type=='T')
							{
								printf("You are a teacher and you can keep this book for 60 days. Please return it on time.\n");
							}
							else
								printf("You are a student and you can keep this book for 30 days. Please return it on time.\n");
						}
						else
						{
							printf("You can only borrow one book per time! Please return your book first!\n");
							getchar();
							system("cls");
							menu_normal(cardhead,head);
						}
					}
					if(b_choose==2)
					{
						printf("cancel operation\n");
						break;
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

/*list all the unborrowed book*/ 
void booklist_unborrowed(book *head)
{
	int a,i=0;
	book *p3;
	p3=(book*)malloc(sizeof(book));
	p3=head;
	/*no such book*/
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
				i=1;
				printf("find unborrowed book\n");          
				printf("Book name: %s\n",p3->book);
				printf("ISBN: %s\n",p3->ISBN);
				printf("Inventoryt: %d\n",p3->inventory);
				printf("Lend number: %d\n\n",p3->lend);
			}
		}
		if(i==0)
		{
			printf("There is not any book left.\n");
		}
	}
}

void booklist_borrowed(book *head)
{
	int a,b,i=0;
	FILE *fp;
	book *p1,*p2,*p3;  
	p1=p2=p3=(book*)malloc(sizeof(book));
	/*find it in librarybooks*/
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
	/*no such book*/
	if(head==NULL||head->link==NULL)
	{
		printf("No books in the library!\n");
	}
	else
	{
		while(p3->link!=NULL)
		{
			p3=p3->link;
			if(b=p3->lend>0)   
			{ 
				i=1;
				printf("find borrowed book\n");          
				printf("Book name: %s\n",p3->book);
				printf("ISBN: %s\n",p3->ISBN);
				printf("Inventoryt: %d\n",p3->inventory);
				printf("Lend number: %d\n",p3->lend);
			}
		}
		if(i==0)
		{
			printf("There is not any book on loan.\n");
		}
	}
}



