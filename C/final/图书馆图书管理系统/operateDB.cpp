#include "LibBooksMana.h"

/*
"���ݿ�"��ѯ��������(�м亯��):
    �ڴ򿪵�"���ݿ�"��,�Ӹ����ĵ�ַ��ʼ,��ָ���ķ�ʽ������ѯָ���ļ�¼;
    ����ƥ��ļ�¼,�򽫵�һ���ҵ��ļ�¼�������ݿ����ǵڼ�����¼����;
    ����,���� 0.
ע��:�ַ�ƥ����ȫƥ��

ith:�����Ŀ�ʼ���ҵĵ�ַ;(ith>=1)

way:���ҷ�ʽ:
    1 ��ISBN�Ų���
    2 ����������
    3 �����߲���
    4 ���������
    5 �����������
    6 �����������
����ֱ�ӷ���;

str:Ҫƥ����ַ���;

���:���ص�һ���ҵ��������ݿ��м�¼�� "����"
(�Ѳ���)
*/
int findRecInDB(int ith,int way,char str[60])
{
	FILE *fp;
	book_info *book;
	book=(book_info *)malloc(sizeof(book_info));
	if((fp=fopen(fdb,"rb"))==NULL)//��"���ݿ�"
	{
		printf("database�򲻿�,���ڷ���...\n");
		return 0;
	}
	if(fseek(fp,(ith-1)*sizeof(book_info),0)!=0)return 0;//��"���ݿ�"�ļ���ͷΪ��׼,�����ļ�λ�ö�λ
	switch (way)
	{
	case 1:	//��ISBN�Ų���
		while(!feof(fp))//�����ݿ��дӸ����ĵ�ַ��ʼ��������ѯ,�����ҵ�ƥ���¼,��û���ҵ����˳�
		{
			fread(book,sizeof(book_info),1,fp);//��ȡ��¼��Ϣ(�ռ�¼Ҳ��ȡ�ж�)
			if((strlen(book->ISBN)==strlen(str))&&(!strcmp(book->ISBN,str)))//�ҵ���һ����¼,����������
			{
				fclose(fp);
				free(book);
				return ith;
			}
			ith++;//û���ҵ�,����������,����ռ�¼ҲҪ����
		}
		break;
	case 2://����������,
		while(!feof(fp))//�����ݿ��дӸ����ĵ�ַ��ʼ��������ѯ,�����ҵ�ƥ���¼,��û���ҵ����˳�
		{
			fread(book,sizeof(book_info),1,fp);//��ȡ��¼��Ϣ(�ռ�¼Ҳ��ȡ�ж�)
			if((strlen(book->name)==strlen(str))&&(!strcmp(book->name,str)))//�ҵ���һ����¼,����������
			{
				fclose(fp);
				free(book);
				return ith;
			}
			ith++;//û���ҵ�,����������,����ռ�¼ҲҪ����
		}
		break;
	case 3://�����߲���
		while(!feof(fp))//�����ݿ��дӸ����ĵ�ַ��ʼ��������ѯ,�����ҵ�ƥ���¼,��û���ҵ����˳�
		{
			fread(book,sizeof(book_info),1,fp);//��ȡ��¼��Ϣ(�ռ�¼Ҳ��ȡ�ж�)
			if((strlen(book->author)==strlen(str))&&(!strcmp(book->author,str)))//�ҵ���һ����¼,����������
			{
				fclose(fp);
				free(book);
				return ith;
			}
			ith++;//û���ҵ�,����������,����ռ�¼ҲҪ����
		}
		break;
	case 4://���������
		while(!feof(fp))//�����ݿ��дӸ����ĵ�ַ��ʼ��������ѯ,�����ҵ�ƥ���¼,��û���ҵ����˳�
		{
			fread(book,sizeof(book_info),1,fp);//��ȡ��¼��Ϣ(�ռ�¼Ҳ��ȡ�ж�)
			if((strlen(book->editor)==strlen(str))&&(!strcmp(book->editor,str)))//�ҵ���һ����¼,����������
			{
				fclose(fp);
				free(book);
				return ith;
			}
			ith++;//û���ҵ�,����������,����ռ�¼ҲҪ����
		}
		break;
		case 5://�����������
		while(!feof(fp))//�����ݿ��дӸ����ĵ�ַ��ʼ��������ѯ,�����ҵ�ƥ���¼,��û���ҵ����˳�
		{
			fread(book,sizeof(book_info),1,fp);//��ȡ��¼��Ϣ(�ռ�¼Ҳ��ȡ�ж�)
			if((strlen(book->publisher)==strlen(str))&&(!strcmp(book->publisher,str)))//�ҵ���һ����¼,����������
			{
				fclose(fp);
				free(book);
				return ith;
			}
			ith++;//û���ҵ�,����������,����ռ�¼ҲҪ����
		}
		break;
		case 6://�����������
		while(!feof(fp))//�����ݿ��дӸ����ĵ�ַ��ʼ��������ѯ,�����ҵ�ƥ���¼,��û���ҵ����˳�
		{
			fread(book,sizeof(book_info),1,fp);//��ȡ��¼��Ϣ(�ռ�¼Ҳ��ȡ�ж�)
			if((strlen(book->publishYear)==strlen(str))&&(!strcmp(book->publishYear,str)))//�ҵ���һ����¼,����������
			{
				fclose(fp);
				free(book);
				return ith;
			}
			ith++;//û���ҵ�,����������,����ռ�¼ҲҪ����
		}
		break;
	default://��������ֱ���˳�
		break;
	}
	free(book);
	fclose(fp);
	return 0;//û���ҵ�Ҫ�ҵ��ļ�¼
}
/*
����ָ���ķ�ʽ�޸Ĳ�����һ��ָ���ļ�¼�����ݿ���ѯһ�ζ�Ҫ�򿪺͹ر��ļ�
(�Ѳ���)
*/
void alterAndSaveRecToDB(int ith)
{
	FILE *fp;
	book_info *book;
	char str[60];
	int way;
	book=(book_info *)malloc(sizeof(book_info));
	if((fp=fopen(fdb,"rb+"))==NULL)//��"���ݿ�"
	{
		printf("database�򲻿�,���ڷ���...\n");
		return;
	}
	fseek(fp,(ith-1)*sizeof(book_info),0);//��λ
	fread(book,sizeof(book_info),1,fp);//��ȡ
	printf("�Ƿ�Ҫ�޸��Ȿͼ����Ϣ?[Y/n](n):");
	gets(str);
	if(!strcmp(str,"Y")||!strcmp(str,"y"))
	{
		printf("\n\t\t\t*****************************\n");
	    printf("\t\t\t*   �޸ķ�ʽ˵��:           *\n");
	    printf("\t\t\t*       1.�޸�ISBN��        *\n");
	    printf("\t\t\t*       2.�޸�����          *\n");
	    printf("\t\t\t*       3.�޸�����          *\n");
	    printf("\t\t\t*       4.�޸�����          *\n");
	    printf("\t\t\t*       5.�޸ĳ�����        *\n");
	    printf("\t\t\t*       6.�޸ĳ�����        *\n");
		printf("\t\t\t*       7.�޸ĳ����        *\n");
		printf("\t\t\t*       8.�޸ļ۸�          *\n");
		printf("\t\t\t*       9.�޸��ܱ���        *\n");
		printf("\t\t\t*      10.�޸Ľ����        *\n");
	    printf("\t\t\t*    ������������ȫ���޸�   *\n");
	    printf("\t\t\t*****************************\n");
	    printf("\t\t   ������ֶ�Ӧ��Ӧ���޸ķ�ʽ,��ѡ�� 1-10 :");
		gets(str);
		way=atoi(str);
		switch(way)
		{
		case 1:
			puts("����Ҫ�޸ĵ�ISBN��:");//�޸�����
		    gets(str);
		    strcpy(book->ISBN,str);
			break;
		case 2:
			puts("����Ҫ�޸ĵ�����:");//�޸�����
		    gets(str);
		    strcpy(book->name,str);
			break;
		case 3:
			puts("����Ҫ�޸ĵ�����:");//�޸�����
		    gets(str);
			strcpy(book->author,str);
			break;
		case 4:
			puts("����Ҫ�޸ĵ�����:");//�޸�����
		    gets(str);
			strcpy(book->editor,str);
			break;
		case 5:
			puts("����Ҫ�޸ĵĳ�����:");//�޸�����
		    gets(str);
		    strcpy(book->publisher,str);
			break;
		case 6:
			puts("����Ҫ�޸ĵĳ�����:");//�޸�����
		    gets(str);
			strcpy(book->publishYear,str);
			break;
		case 7:
			puts("����Ҫ�޸ĵİ��:");//�޸�����
		    gets(str);
			strcpy(book->printOrder,str);
			break;
		case 8:
			puts("������۸�(Ԫ)--����������:");
			gets(str);
			strcpy(book->price,str);
			break;
		case 9:
			puts("����Ҫ�޸ĵ��ܱ���--����������,������������򱾴�����Ϊ0 :");//�޸�����
		    gets(str);
			book->totalNum=atol(str);
			while(book->totalNum<0)
			{
				if(book->totalNum<0)printf("�������!�ܱ�������Ϊ����,����������:");
				else printf("�������!�ܱ�������С�ڽ������,����������:");
				gets(str);
				book->totalNum=atol(str);
			}
			break;
		case 10:
			puts("����Ҫ�޸ĵĽ����--����������,������������򱾴�����Ϊ0 :");//�޸�����
		    gets(str);
		    book->lendNum=atol(str);
			while((book->lendNum<0)||(book->lendNum>book->totalNum))
			{
				if(book->lendNum<0)
					printf("�������!�����������Ϊ����,����������:");
				else printf("�������!����������ܴ����ܱ���,����������:");
				gets(str);
				book->lendNum=atol(str);
			}
			break;
		default://ȫ���޸�
			puts("����Ҫ�޸ĵ�ISBN��:");//�޸�����
		    gets(str);
			strcpy(book->ISBN,str);
			puts("����Ҫ�޸ĵ�����:");//�޸�����
			gets(str);
			strcpy(book->name,str);
			puts("����Ҫ�޸ĵ�����:");//�޸�����
			gets(str);
			strcpy(book->author,str);
			puts("����Ҫ�޸ĵ�����:");//�޸�����
			gets(str);
			strcpy(book->editor,str);
			puts("����Ҫ�޸ĵĳ�����:");//�޸�����
			gets(str);
			strcpy(book->publisher,str);
			puts("����Ҫ�޸ĵĳ�����:");//�޸�����
			gets(str);
			strcpy(book->publishYear,str);
			puts("����Ҫ�޸ĵİ��:");//�޸�����
			gets(str);
			strcpy(book->printOrder,str);
			puts("������۸�(Ԫ)--����������:");
			gets(str);
			strcpy(book->price,str);
			puts("������ͼ������--����������,������������򱾴�����Ϊ0 :");
			gets(str);
			book->totalNum=atol(str);
			while(book->totalNum<0||book->totalNum<book->lendNum)
			{
				if(book->totalNum<0)printf("�������!�ܱ�������Ϊ����,����������:");
				else printf("�������!�ܱ�������С�ڽ������,���������� :");
				gets(str);
				book->totalNum=atol(str);
			}
			puts("������ͼ������--����������,������������򱾴�����Ϊ0 :");
			gets(str);
			book->lendNum=atol(str);
			while((book->lendNum<0)||(book->lendNum>book->totalNum))
			{
				if(book->lendNum<0)
					printf("�������!�����������Ϊ����,���������� :");
				else printf("�������!����������ܴ����ܱ���,���������� :");
				gets(str);
				book->lendNum=atol(str);
			}
			
			break;
		}
		book->retainNum=book->totalNum- book->lendNum;
		fseek(fp,(ith-1)*sizeof(book_info),0);//��λ
		fwrite(book,sizeof(book_info),1,fp);
		puts("�޸���Ϣ�ѱ���,�����...");
	}
	fclose(fp);
	free(book);
}

/*
��ͼ���"���ݿ�"��,������ȡȫ����¼,����ʾÿ����¼����ϸ��Ϣ
(�Ѳ���)(�д����� : �ļ��Ƿ�β�����жϻ�����ȷ)
*/
void readAndDisAllRecInDB()
{
	FILE *fp;//���ݿ��ļ�ָ��
	book_info *book;//�ṹ��ָ��
	char str[16];
	book=(book_info *)malloc(sizeof(book_info));//���ڴ���Ϊbook����һ���ṹ���С���ڴ���
	
	if((fp=fopen(fdb,"rb"))==NULL)//��ֻ����ʽ��"���ݿ�",����fpָ���仺����(���ڴ���)���׵�ַ
	{
		puts("database�ļ��򲻿�,���ڷ���...");
		return;
	}
	showTable();
	unsigned long i=0;//ͼ�鱾��
	while(!feof(fp))//�ж��Ƿ��ļ��Ľ�β
	{
		if((i+1)%10==0)//ÿ��ӡ10����Ϣͣһ��
		{
			printf("��Ҫ���ص����˵� (y),����Ҫ������ʾ��ѯ��� (n)?--[Y/n](n):");
			gets(str);
			if(!strcmp(str,"y")||!strcmp(str,"Y"))//Ҫ�������˵�
			{
				fclose(fp);
				puts("���ڷ��ص����˵�...");
				return;
			}
			printf("\n");//ѡ��,������ӡ
			showTable();
		}
		fread(book,sizeof(book_info),1,fp);//�ڴ򿪵Ķ������ļ�fdb��,����ǰfpָ��ĵ����ݿ�(һ��book_info�ṹ��)���Ƹ�Arr,֮��fp����ƶ�
		if(strcmp(book->name,"")!=0)//���˵��յļ�¼:������Ϊ��,����¼��Ϣ��Ϊ��
		{
			i++;
			printinfo(book);
		}
	}
	printf("ͼ��ݼ�¼�����ݿ��ͼ���ܹ��� %d ��\n",i);
	fclose(fp);//����д����ʽ���ļ�,�����Ҫ�ر��ļ�,�������ݻᶪʧ
	free(book);
}

/*
��ԭ�����ݵĻ����������ݿ�����¼�¼(����Ա����ģ��)
(�Ѳ���)
*/
void AddRecToDB()
{
	FILE *fp;
	book_info *book;
	char str[60];
	book=(book_info *)malloc(sizeof(book_info));
	if((fp=fopen(fdb,"ab"))==NULL)//��"���ݿ�"
	{
		puts("database�ļ��򲻿�,���ڷ���...");
		return;
	}
	printf("ȷ��Ҫ�������?[Y/n](n):");
	gets(str);
	if(strcmp(str,"y")&&strcmp(str,"Y")) //�����,�������˵�
	{
		puts("���������,���ڷ���...");
		fclose(fp);
		return;
	}
	//��������¼
	while(1)
	{
		puts("���������������:");
		gets(str);
		strcpy(book->name,str);
		puts("������ISBN��:");
		gets(str);
		strcpy(book->ISBN,str);
		puts("����������:");
		gets(str);
		strcpy(book->author,str);
		puts("����������:");
		gets(str);
		strcpy(book->editor,str);
		puts("�����������:");
		gets(str);
		strcpy(book->publisher,str);
		puts("�����������:");
		gets(str);
		strcpy(book->publishYear,str);
		puts("��������:");
		gets(str);
		strcpy(book->printOrder,str);
		puts("������۸�(Ԫ)--����������:");
		gets(str);
		strcpy(book->price,str);
		puts("������ͼ������--����������,������������򱾴�����Ϊ0:");
		gets(str);
		book->totalNum=atol(str);
		while(book->totalNum<0)
		{
			printf("�������!�ܱ�������Ϊ����,����������:");
			gets(str);
			book->totalNum=atol(str);
		}
		puts("������ͼ������--����������,������������򱾴�����Ϊ0:");
		gets(str);
		book->lendNum=atol(str);
		while((book->lendNum<0)||(book->lendNum>book->totalNum))
		{
			if(book->lendNum<0)
				printf("�������!�����������Ϊ����,����������:");
			else printf("�������!����������ܴ����ܱ���,����������:");
			gets(str);
			book->lendNum=atol(str);
		}
		book->retainNum=book->totalNum-book->lendNum;
		fwrite(book,sizeof(book_info),1,fp);

		puts("��ӵ����������ѱ���,�Ƿ�����������?[Y/n](n)");
		gets(str);
		if(strcmp(str,"y")&&strcmp(str,"Y"))
		{
			puts("�������������,���ڷ���...");
			break;
		}
	}

	fclose(fp);
	free(book);
}
/*
��������8��ͼ���¼(֮ǰ���еļ�¼����ɾ��),�˺������ڵ��Ի����ݿ��ʼ��ʱʹ��
(�Ѳ���)
*/
void reinstAllRecInDB()
{
	FILE *fp;
	book_info *book;
	book=(book_info *)malloc(sizeof(book_info));
	if((fp=fopen(fdb,"wb"))==NULL)return;//���� database �ļ��򸲸�ԭ database �ļ�
	//1
	strcpy(book->name,"javaʵս������������");
	strcpy(book->ISBN,"970-2-676-596-1");
	strcpy(book->author,"����");
	strcpy(book->editor,"�ź���");
	strcpy(book->publisher,"������ѧ������");
	strcpy(book->publishYear,"2007");
	strcpy(book->printOrder,"2007��9�µ�1��");
	strcpy(book->price,"33");
	book->totalNum=214;
	book->lendNum=34;
	book->retainNum=book->totalNum-book->lendNum;
	fwrite(book,sizeof(book_info),1,fp);
	//2
	strcpy(book->name,"php��������ģ���ȫ(�޶���)");
	strcpy(book->ISBN,"974-7-11-55696-2");
	strcpy(book->author,"����");
	strcpy(book->editor,"����");
	strcpy(book->publisher,"�廪��ѧ������");
	strcpy(book->publishYear,"2005");
	strcpy(book->printOrder,"2005��8�µ�6��");
	strcpy(book->price,"15");
	book->totalNum=432;
	book->lendNum=94;
	book->retainNum=book->totalNum-book->lendNum;
	fwrite(book,sizeof(book_info),1,fp);
	//3
	strcpy(book->name,"html��ҳ��ƾ�������");
	strcpy(book->ISBN,"978-7-01-02678-7");
	strcpy(book->author,"���ľ�");
	strcpy(book->editor,"��ʫ��");
	strcpy(book->publisher,"���ӹ�ҵ������");
	strcpy(book->publishYear,"2010");
	strcpy(book->printOrder,"2010��2�µ�7��");
	strcpy(book->price,"57");
	book->totalNum=453;
	book->lendNum=76;
	book->retainNum=book->totalNum-book->lendNum;
	fwrite(book,sizeof(book_info),1,fp);
	//4
	strcpy(book->name,"css�����������");
	strcpy(book->ISBN,"97-7-01-09356-0");
	strcpy(book->author,"ׯ��");
	strcpy(book->editor,"ŷ��");
	strcpy(book->publisher,"�����ʵ������");
	strcpy(book->publishYear,"2012");
	strcpy(book->printOrder,"2012��3�µ�4��");
	strcpy(book->price,"97");
	book->totalNum=567;
	book->lendNum=324;
	book->retainNum=book->totalNum-book->lendNum;
	fwrite(book,sizeof(book_info),1,fp);
	//5
	strcpy(book->name,"�����������ϵͳ");
	strcpy(book->ISBN,"974-7-01-05666-2");
	strcpy(book->author,"(��)Randal E.Bryant David R.O'Hallaron");
	strcpy(book->editor,"��ӭ��");
	strcpy(book->publisher,"��е��ҵ������");
	strcpy(book->publishYear,"2012");
	strcpy(book->printOrder,"2012��1�µ�1��");
	strcpy(book->price,"56");
	book->totalNum=214;
	book->lendNum=34;
	book->retainNum=book->totalNum-book->lendNum;
	fwrite(book,sizeof(book_info),1,fp);
	//6
	strcpy(book->name,"php�����̼�����ʵ��");
	strcpy(book->ISBN,"97-7-01-025696-9");
	strcpy(book->author,"��˹˼");
	strcpy(book->editor,"������");
	strcpy(book->publisher,"�����ʵ������");
	strcpy(book->publishYear,"2011");
	strcpy(book->printOrder,"2011��7�µ�1��");
	strcpy(book->price,"15");
	book->totalNum=432;
	book->lendNum=94;
	book->retainNum=book->totalNum-book->lendNum;
	fwrite(book,sizeof(book_info),1,fp);
	//7
	strcpy(book->name,"��������ԭ���������Գ������(��2��)");
	strcpy(book->ISBN,"97-7-0257-0466-1");
	strcpy(book->author,"���");
	strcpy(book->editor,"��� ٺԶ��");
	strcpy(book->publisher,"���ӹ�ҵ������");
	strcpy(book->publishYear,"2011");
	strcpy(book->printOrder,"2011��12�µ�5��");
	strcpy(book->price,"97");
	book->totalNum=567;
	book->lendNum=324;
	book->retainNum=book->totalNum-book->lendNum;
	fwrite(book,sizeof(book_info),1,fp);
	//8
	strcpy(book->name,"���ݽṹ(C���԰�)");
	strcpy(book->ISBN,"97-7-5635-0696-5");
	strcpy(book->author,"����");
	strcpy(book->editor,"��ε�� ��ΰ��");
	strcpy(book->publisher,"�廪��ѧ������");
	strcpy(book->publishYear,"2012");
	strcpy(book->printOrder,"2012��5�µ�3��");
	strcpy(book->price,"97");
	book->totalNum=567;
	book->lendNum=324;
	book->retainNum=book->totalNum-book->lendNum;
	fwrite(book,sizeof(book_info),1,fp);
	//9
	strcpy(book->name,"������������ͳ��(������.���İ�)");
	strcpy(book->ISBN,"978-7-04-046696-8");
	strcpy(book->author,"���");
	strcpy(book->editor,"���");
	strcpy(book->publisher,"�й������ѧ������");
	strcpy(book->publishYear,"2012");
	strcpy(book->printOrder,"2012��2�µ�3��");
	strcpy(book->price,"56");
	book->totalNum=227;
	book->lendNum=34;
	book->retainNum=book->totalNum-book->lendNum;
	//10
	fwrite(book,sizeof(book_info),1,fp);
	strcpy(book->name,"��ɢ��ѧ");
	strcpy(book->ISBN,"979-7-3462-5796-1");
	strcpy(book->author,"������ ������ ������");
	strcpy(book->editor,"������ ������ ������");
	strcpy(book->publisher,"�ߵȽ���������");
	strcpy(book->publishYear,"2008");
	strcpy(book->printOrder,"2008��3�µ�1��");
	strcpy(book->price,"97");
	book->totalNum=247;
	book->lendNum=143;
	book->retainNum=book->totalNum-book->lendNum;
	fwrite(book,sizeof(book_info),1,fp);
	//11
	strcpy(book->name,"�ߵ���ѧ");
	strcpy(book->ISBN,"97-7-04-021277-8");
	strcpy(book->author,"ͬ�ô�ѧ��ѧϵ");
	strcpy(book->editor,"ͬ�ô�ѧ��ѧϵ");
	strcpy(book->publisher,"�ߵȽ���������");
	strcpy(book->publishYear,"2010");
	strcpy(book->printOrder,"2007��6�µ�6��");
	strcpy(book->price,"97");
	book->totalNum=957;
	book->lendNum=674;
	book->retainNum=book->totalNum-book->lendNum;
	fwrite(book,sizeof(book_info),1,fp);

	fclose(fp);
	free(book);
}