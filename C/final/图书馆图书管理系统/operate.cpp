#include "LibBooksMana.h"

/*
�����ͷ
(�Ѳ���)
*/
void showTable()
{
	printf("\n*******************************************************************************\n");
	printf("ISBN��|��     ��|��  ��|��    ��|������|������|���|�۸�Ԫ|�ܱ���|�����|������\n");
	printf("*******************************************************************************\n");
}
/*
��ӡָ����¼����ϸ��Ϣ//�����д�����
(�Ѳ���)
*/
void printinfo(book_info *book)
{
	printf("%-6s|%-26s|%-8s|%-8s|%-20s|%-8s|%-4s|%-4s|%-5d|%-5d|%-5d\n",book->ISBN,book->name,
		book->author,book->editor,book->publisher,book->publishYear,book->printOrder,book->price,
		book->totalNum,book->lendNum,book->retainNum);
	printf("===============================================================================\n");
}

/*
��ѯ���븨������ :
(�Ѳ���)
*/
void queryInput(char str[],int &way)
{
	printf("\n\t\t\t**************************\n");
	printf("\t\t\t*  ��ѯ��ʽ˵��:         *\n");
	printf("\t\t\t*     1.��ISBN�Ų���     *\n");
	printf("\t\t\t*     2.����������       *\n");
	printf("\t\t\t*     3.�����߲���       *\n");
	printf("\t\t\t*     4.���������       *\n");
	printf("\t\t\t*     5.�����������     *\n");
	printf("\t\t\t*     6.�����������     *\n");
	printf("\t\t\t*  ������������ֱ�ӷ���  *\n");
	printf("\t\t\t**************************\n");
	printf("\t\t  ������ֶ�Ӧ��Ӧ�Ĳ�ѯ��ʽ,��ѡ�� 1-6 :");
	gets(str);
	way=atoi(str);
	switch (way)
	{
	case 1:printf("������ISBN:");break;
	case 2:printf("����������:");break;
	case 3:printf("����������:");break;
    case 4:printf("����������:");break;
	case 5:printf("�����������:");break;
	case 6:printf("�����������:");break;
	default:printf("ѡ�����,���ڷ���...\n");return;
	}
	gets(str);//��ȡ������Ϣ
	if(strlen(str)==0)
	{
		puts("û������,���ڷ���...");
		return;
	}
}
/*
������ѯ : ��ʾ����ƥ��ļ�¼����ϸ��Ϣ
��Ҫ��������:  findRecInDB();���ݿ���Һ���(��������)
(�Ѳ���)
*/
int initialQueRec(int fsite[])
{
	FILE *fp;
	book_info *book;
	int findNum=0;//���ҵ��ļ�¼������
	int fsi=0;//fsite[]���±� , fsi=findnum%198;��֤ ��fsite������200����Сʱ�������
	int ith=1;//��¼��ǰ��¼�����ݿ����ǵڼ��� (ith>=1) ��¼,(ith-1)*sizeof(book_info)��ʾ��ith����¼�����ݿ��еĵ�ַ
	//int fsite[200];// ith �Ļ�������,�Ա���Ҫ��һ����ȷ����ʱ���Կ��ٶ�λ
	int way=0;//��ѯ��ʽ
	char str[60]="";//��ȡ������ַ���
	book=(book_info *)malloc(sizeof(book_info));//��book�����ڴ�ռ�

	if((fp=fopen(fdb,"rb"))==NULL)//��"���ݿ�"
	{
		printf("database�򲻿�,���ڷ���...\n");
		free(book);
		return 0;
	}
	queryInput(str,way);//��ȡstr��way
	if(way<1||way>6)//
	{
		fclose(fp);
		free(book);
		return 0;
	}
	if(strlen(str)==0)
	{
		fclose(fp);
		free(book);
		return 0;
	}
	showTable();
	ith=1;//�ӵ�һ����¼��ʼ����
	while(1)
	{
		if((ith=findRecInDB(ith,way,str))!=0)//�ҵ��Ļ����ӡ,ith��ʾ�����ݿ��е�������
		{
			findNum++;
			fsi=findNum-1;
			if(fsi>=198)fsi=fsi%198;
			fsite[fsi]=ith;//�洢��¼�����ݿ��е��ǵڼ���������, ������
			if(findNum%10==0)//ÿ��ӡ10����Ϣͣһ��
			{
				printf("���������������ʾ��ѯ���...");
				gets(str);
				printf("\n");
				showTable();
			}
			fseek(fp,(ith-1)*sizeof(book_info),0);//��λ
			fread(book,sizeof(book_info),1,fp);
			//printf("�����¼�����ݿ����ǵ� %d ����¼\n",fsite[fsi]);
			printinfo(book);
			ith++;//��ѯǰ��
		}
		else break;//�����˳�
	}
	printf("�ܹ��ҵ� %d ����.\n\n",findNum);
	fclose(fp);
	free(book);//�ͷ�book�ڴ�ռ�
	return findNum;
}
/*
��ȷ��ѯ: �ڳ�����ѯ�Ļ����Ͻ�һ����ȷ��ѯ,ֱ��ֻ��һ����¼������������û�з��������ļ�¼
��Ҫ��������: initialQueRec()->findRecInDB()

���: 
���� 0:û���ҵ�Ҫ��ѯ�ļ�¼
���� �ü�¼�����ݿ����ǵڼ�����¼ (>=1):�ҵ�Ψһ�ļ�¼
(�Ѳ���)
*/
int exactSearchRec()
{
	FILE *fp;
	book_info *book;
	int findnum=0;//�ҵ�������
	int fsite[200];//�����������ļ�¼��"���ݿ�"���ǵ�ith����¼������,�Ա���Ҫ��һ����ȷ����ʱ���Կ��ٶ�λ
	char str[60];

	findnum=initialQueRec(fsite);//��fsite�洢����������� fsite[0]-fsite[findnum-1]�洢�ҵ��ļ�¼"��ַ"

	book=(book_info *)malloc(sizeof(book_info));
	if((fp=fopen(fdb,"rb"))==NULL)//��"���ݿ�"
	{
		printf("database�򲻿�,���ڷ���...\n");
		return 0;
	}
    //1   �������������ֹһ��ͼ��
	if(findnum>1)
	{
		printf("\n��ѯ�����Ψһ,�Ƿ�Ҫ��һ����ȷ����?[Y/n](y):");//�Ƿ�Ҫ��һ����ȷ����
		gets(str);
		if(!strcmp(str,"n")||!strcmp(str,"N"))
		{
			puts("���ڷ���...");
			return 0;
		}
		//��һ���� ��ѯ������ ��ȷ����
		/*
		ͨ��һ��һ���Ĺ��˲����������ļ�¼���������һ����¼��û�м�¼
		*/
		int way=0;
		int ith;
		while(findnum>1)//��ֹ��һ����¼
		{
			queryInput(str,way);//��ѯ����,��� str �� way
			if(way<1||way>6)//ȷ��wayֻ��1-6
			{
				fclose(fp);
				return 0;
			}
			if(strlen(str)==0)//ȷ���в�ѯ����
			{
				fclose(fp);
				return 0;
			}

			int biao=0;
			int ni=0;
			while(fsite[ni]>0)
			{
				//���ݿ��п��ٶ�λ
				fseek(fp,(fsite[ni]-1)*sizeof(book_info),0);
				fread(book,sizeof(book_info),1,fp);//��ȡ��¼
				switch(way)
				{
				case 1://ISBN
					if(!strcmp(book->ISBN,str))break;//��Ȳ�����
					else//�����ɾ��,findenum--
					{
						fsite[ni]=fsite[findnum-1];
						fsite[findnum-1]=-1;
						findnum--;
						biao=1;
					}
					break;
				case 2://����
					if(!strcmp(book->name,str))break;//��Ȳ�����
					else//�����ɾ��,findenum--
					{
						fsite[ni]=fsite[findnum-1];
						fsite[findnum-1]=-1;
						findnum--;
						biao=1;
					}
					break;
				case 3://����
					if(!strcmp(book->author,str))break;//��Ȳ�����
					else//�����ɾ��,findenum--
					{
						fsite[ni]=fsite[findnum-1];
						fsite[findnum-1]=-1;
						findnum--;
						biao=1;
					}
					break;
				case 4://����
					if(!strcmp(book->editor,str))break;//��Ȳ�����
					else//�����ɾ��,findenum--
					{
						fsite[ni]=fsite[findnum-1];
						fsite[findnum-1]=-1;
						findnum--;
						biao=1;
					}
					break;
				case 5://������
					if(!strcmp(book->publisher,str))break;//��Ȳ�����
					else//�����ɾ��,findenum--
					{
						fsite[ni]=fsite[findnum-1];
						fsite[findnum-1]=-1;
						findnum--;
						biao=1;
					}
					break;
				case 6://������
					if(!strcmp(book->publishYear,str))break;//��Ȳ�����
					else//�����ɾ��,findenum--
					{
						fsite[ni]=fsite[findnum-1];
						fsite[findnum-1]=-1;
						findnum--;
						biao=1;
					}
					break;
				}
				if(!biao)ni++;//���ǰ��,����Ȳ�����
				biao=0;
			}
			if(findnum>1)
			{
				printf("��ѯ�����Ψһ,�Ƿ�Ҫ��һ����ȷ����?[Y/n](Y):");
				gets(str);
				if(!strcmp(str,"n")||!strcmp(str,"N"))
				{
					puts("������ȷ��ѯ,���ڷ���...");
					return 0;
				}
			}
			else break;
		}
	}
	//2   û���ҵ�Ҫ�޸ĵ�ͼ��
	if(findnum==0)
	{
		puts("û���ҵ�Ҫ��ѯ��ͼ��!���ڷ���...");
		fclose(fp);
		return 0;
	}
	//3   �����ֻ��һ��ͼ��
	fseek(fp,(fsite[0]-1)*sizeof(book_info),0);//��λ
	fread(book,sizeof(book_info),1,fp);//��ȡ
	showTable();
	printinfo(book);//��ӡ
	fclose(fp);
	free(book);//�ͷ�book�ڴ�ռ�
	return fsite[0];
}
/*
�޸�ָ���ļ�¼����Ϣ(����Աģ��)
��Ҫ��������: initialQueRec()->findRecInDB();

          alterAndSaveRecToDB()(��������)

���ж����ѯ���,��Ҫ��ȷ��һ������û��

(�Ѳ���)
*/
void alterRecInDB()
{
	int ith=0;
	puts("\n�޸�ͼ����Ϣ֮ǰ,����Ҫ��ȷ��ѯ:");
	ith=exactSearchRec();
	if(ith!=0)alterAndSaveRecToDB(ith);
	else puts("û���ҵ�Ҫ�޸ĵ�ͼ��!���ڷ������˵�...");
}

/*
���ͼ��(����Ա)
��Ҫ�������� : initialQueRec()->findRecInDB()
(�Ѳ���)
*/
void lendBookAdm()
{
	FILE *fp;
	int ith=0;
	int lendnum=0;
	char str[60];
	book_info *book;
	book=(book_info *)malloc(sizeof(book_info));
	puts("\n���ͼ��֮ǰ,����Ҫ���о�ȷ��ѯ:");

	ith=exactSearchRec();

	if(ith>0)//�ҵ�Ψһ��ͼ��
	{
		if((fp=fopen(fdb,"rb+"))==NULL)//��"���ݿ�"
		{
			printf("database�򲻿�,���ڷ���...\n");
			return;
		}
		fseek(fp,(ith-1)*sizeof(book_info),0);//��λ
		fread(book,sizeof(book_info),1,fp);//��ȡ����Ҫ��ȡ
		printf("ȷ��Ҫ���?[Y/n](y):");
		gets(str);
		if(!strcmp(str,"n")||!strcmp(str,"N"))
		{
			puts("�����˳�...");
			fclose(fp);
			free(book);
			return;
		}
		printf("������Ҫ����Ȿ��ı���--����������,���򱾴�����Ϊ0 :");
		gets(str);
		lendnum=atol(str);
		while((lendnum>book->retainNum)||(lendnum<0))
		{
			if(lendnum>book->retainNum)
				printf("\n�������!�����Ŀ�����ִ���,���������� :");
			else 
				printf("\n�������!���������Ϊ����,���������� :");
			gets(str);
			lendnum=atol(str);
		}
		book->retainNum-=lendnum;
		book->lendNum+=lendnum;

		fseek(fp,-sizeof(book_info),1);//��λ
		fwrite(book,sizeof(book_info),1,fp);
		puts("ͼ���ѽ��,�����...");
		fclose(fp);
	}
	else puts("û���ҵ�Ҫ�����ͼ��!���ڷ������˵�...");
	free(book);
}
/*
�黹ͼ��(����Ա)
(�Ѳ���)
*/
void revertBookAdm()
{
	FILE *fp;
	int ith=0;
	int lendnum=0;
	char str[60];
	book_info *book;
	book=(book_info *)malloc(sizeof(book_info));
	puts("\n�黹ͼ��֮ǰ,����Ҫ���о�ȷ��ѯ:");

	ith=exactSearchRec();

	if(ith>0)//�ҵ�Ψһ��ͼ��
	{
		if((fp=fopen(fdb,"rb+"))==NULL)//��"���ݿ�"
		{
			printf("database�򲻿�,���ڷ���...\n");
			return;
		}
		fseek(fp,(ith-1)*sizeof(book_info),0);//��λ
		fread(book,sizeof(book_info),1,fp);//��ȡ����Ҫ��ȡ
		printf("ȷ��Ҫ�黹?[Y/n](y):");
		gets(str);
		if(!strcmp(str,"n")||!strcmp(str,"N"))
		{
			puts("�����˳�...");
			fclose(fp);
			free(book);
			return;
		}
		printf("������Ҫ�黹�Ȿ��ı���--����������,���򱾴�����Ϊ0 :");
		gets(str);
		lendnum=atol(str);
		while((lendnum>book->lendNum)||(lendnum<0))
		{
			if(lendnum>book->lendNum)
				printf("\n�������!�黹��Ŀ���ڽ����,���������� :");
			else 
				printf("\n�������!�黹������Ϊ����,���������� :");
			gets(str);
			lendnum=atol(str);
		}
		book->retainNum+=lendnum;
		book->lendNum-=lendnum;

		fseek(fp,-sizeof(book_info),1);//��λ
		fwrite(book,sizeof(book_info),1,fp);
		puts("ͼ���ѹ黹,�����...");
		fclose(fp);
	}
	else puts("û���ҵ�Ҫ�黹��ͼ��!���ڷ������˵�...");
	free(book);
}
/*
ɾ��ָ���ļ�¼

��Ҫ��������:initialQueRec()->findRecInDB()

(�Ѳ���)(��������:�ͷſ�(�ѱ�ɾ��)��¼�Ŀռ�)
*/
void delRec()
{
	FILE *fp;
	int ith=0;
	int lendnum=0;
	char str[60];
	book_info *book;
	book=(book_info *)malloc(sizeof(book_info));

	puts("\nɾ��ͼ��֮ǰ,����Ҫ���о�ȷ��ѯ:");

	ith=exactSearchRec();

	if(ith>0)//�ҵ�Ψһ��ͼ��
	{
		if((fp=fopen(fdb,"rb+"))==NULL)//��"���ݿ�"
		{
			printf("database�򲻿�,���ڷ���...\n");
			return;
		}
		fseek(fp,(ith-1)*sizeof(book_info),0);//��λ
		fread(book,sizeof(book_info),1,fp);//��ȡ����Ҫ��ȡ
		printf("ȷ��Ҫɾ��?[Y/n](y):");
		gets(str);
		if(!strcmp(str,"n")||!strcmp(str,"N"))
		{
			puts("�����˳�...");
			fclose(fp);
			free(book);
			return;
		}
		//��Ҫɾ���ļ�¼��ȫ����Ϣ����
		strcpy(book->name,"");
		strcpy(book->ISBN,"");
		strcpy(book->author,"");
		strcpy(book->editor,"");
		strcpy(book->publisher,"");
		strcpy(book->publishYear,"");
		strcpy(book->printOrder,"");
		strcpy(book->price,"");
		book->totalNum=0;
		book->lendNum=0;
		book->retainNum=0;

		fseek(fp,-sizeof(book_info),1);//��λ
		fwrite(book,sizeof(book_info),1,fp);//д��
		puts("ͼ����ɾ��,�����...");
		fclose(fp);
	}
	else puts("û���ҵ�Ҫɾ����ͼ��!���ڷ������˵�...");
	free(book);
}