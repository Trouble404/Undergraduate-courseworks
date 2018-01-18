#include "LibBooksMana.h"

/*
��userInfoDB�б�����ѯָ�����ǳƵļ�¼,���ؼ�¼������
*/
int findRecInUDB(char name[])
{
	FILE *fp;
	User *user;
	int ith=1;
	user=(User *)malloc(sizeof(User));
	if((fp=fopen(userInfodb,"rb"))==NULL)//��"�û�ע����Ϣ���ݿ�"
	{
		printf("userInfoDB�򲻿�,���ڷ���...\n");
		return 0;
	}
	while(!feof(fp))//�����ݿ��дӸ����ĵ�ַ��ʼ��������ѯ,�����ҵ�ƥ���¼,��û���ҵ����˳�
	{
		fread(user,sizeof(User),1,fp);//��ȡ��¼��Ϣ(�ռ�¼Ҳ��ȡ�ж�)
		if((strlen(user->name)==strlen(name))&&(!strcmp(user->name,name)))//�ҵ���һ����¼,����������
		{
			fclose(fp);
			free(user);
			return ith;
		}
		ith++;//û���ҵ�,����������,����ռ�¼ҲҪ����
	}
	free(user);
	fclose(fp);
	return 0;//û���ҵ�Ҫ�ҵ��ļ�¼
}

/*
�û���¼:
Ҫ�ж��û��Ƿ���ע��;(Ҫ���� userInfoDB �ļ�)
��û��ע��Ҫ��ʾע��;
����ע���¼��Ҫ����;
������������Ը���ע�����õ�����Ĵ��һ�

��Ҫ��������:userRegister();;int findRecInUDB(char str[60])

��¼�ɹ����� 1;���򷵻� 0;
*/
int login()
{
	FILE *fp;
	User *user;
	char str[60];
	int ith=0;
	puts("\t˵��:����Ա��¼���ʺ���: root,����Ĭ��(û���޸�)��: 123");
	printf("�������û���:");
	gets(str);
	ith=findRecInUDB(str);//�ڼ�����¼ (>=1)
	if(ith==0)//����û���û��ע��
	{
		printf("����û���û��ע��,����ע��.\n");
		return 0;
	}
	else//�û���ע��
	{
		if((fp=fopen(userInfodb,"rb"))==NULL)//�����ݿ�
		{
			printf("\tuserInfoDB �ļ��򲻿�,���ڷ���...\n");
			return 0;
		}
		user=(User *)malloc(sizeof(User));
		fseek(fp,(ith-1)*sizeof(User),0);//��λ
		fread(user,sizeof(User),1,fp);//��ȡ��Ϣ
		printf("����������:");
		gets(str);
		if(!strcmp(user->pwd,str))//���
		{
			puts("��¼�ɹ�!");
			fclose(fp);
			return ith;
		}
		else
		{
			puts("�û����������������!");
			fclose(fp);
			return 0;
		}
	}
}
/*
���û�ע��
*/
void userRegister()
{
	FILE *fp;
	User *user;
	char str[60]="";
	int ith=0;
	user=(User *)malloc(sizeof(User));

	while(strlen(str)==0)//����Ϊ��
	{
		printf("������Ҫע����û���:");
		gets(str);
		if(strlen(str))break;
		else printf("�û�������Ϊ��!\n");
	}
	ith=findRecInUDB(str);//�ڼ�����¼ (>=1)
	while(ith)//�û����ѱ�ע��
	{
		printf("����û����ѱ�ע��,������ѡ���û���:");
		strcpy(str,"");//����
		while(strlen(str)==0)//����Ϊ��
		{
			printf("������Ҫע����û���:");
			gets(str);
			if(strlen(str))break;
			else printf("�û�������Ϊ��!\n");
		}
		//gets(str);
		ith=findRecInUDB(str);//�ڼ�����¼ (>=1)
	}
	puts("��ϲ��,����û�������!");//�û���ֻ��Ψһ
	strcpy(user->name,str);
	while(1)
	{
		strcpy(str,"");//����
		while(strlen(str)==0)//����Ϊ��
		{
			printf("�����õ�¼����:");
			gets(str);
			if(strlen(str))break;
			else printf("���벻��Ϊ��!\n");
		}
		//gets(user->pwd);
		printf("���ٴ������¼����:");
		gets(user->pwd);
		if(!strcmp(user->pwd,str))break;
		puts("�����������벻һ��!");
	}
	strcpy(user->pwdIssue,"�ҵ���ʵ������?");
	printf("�������һ����������Ĵ�,���ס�����:\n");
	while(1)
	{
		printf("\"�ҵ���ʵ������?\" :\n");
		strcpy(str,"");//����
		while(strlen(str)==0)//����Ϊ��
		{
			printf("����������Ĵ�:");
			gets(str);
			if(strlen(str))break;
			else printf("�𰸲���Ϊ��!\n");
		}
		printf("���ٴ���������Ĵ�:");
		gets(user->pwdAnswer);
		if(!strcmp(user->pwdAnswer,str))break;
		puts("��������Ĵ𰸲�һ��!");
	}
	if((fp=fopen(userInfodb,"ab"))==NULL)//�����ݿ�
	{
		printf("userInfoDB �ļ��򲻿�,���ڷ���...\n");
		return;
	}
	fwrite(user,sizeof(User),1,fp);//��ȡ��Ϣ
	fclose(fp);
	puts("ע��ɹ�,��ϲ��!");
}

/*
�û��ʺŹ���
ith:ʶ���ǹ���Ա��¼����ѧ����¼
*/
void userInfoGovern(int ith)
{
	FILE *fp;
	User *user;
	char str[60]="";

	if((fp=fopen(userInfodb,"rb+"))==NULL)//�����ݿ�
	{
		printf("userInfoDB �ļ��򲻿�,���ڷ���...\n");
		return;
	}
	user=(User *)malloc(sizeof(User));
	fseek(fp,(ith-1)*sizeof(User),0);
	fread(user,sizeof(User),1,fp);
	printf("\t�ʺ���ϸ��Ϣ:\n");
	printf("\t�ʺ�:%s,����:%s,�һ����������:%s,�����:%s\n",user->name,user->pwd,user->pwdIssue,user->pwdAnswer);
	if(ith==1)//����Ա
	{
		///printf("�������Աģ��\n");
		printf("\t�޸�����(a) OR �����(b) OR ����(c)?-[a-c](c):");
		gets(str);
		if(!strcmp(str,"a")||!strcmp(str,"A"))//�޸�����
		{
			while(1)
			{
				strcpy(str,"");//����
				while(strlen(str)==0)//����Ϊ��
				{
					printf("�����õ�¼����:");
					gets(str);
					if(strlen(str))break;
					else printf("���벻��Ϊ��!\n");
				}
				printf("���ٴ������¼����:");
				gets(user->pwd);
				if(!strcmp(user->pwd,str))break;
				puts("�����������벻һ��!");
			}
			fseek(fp,(ith-1)*sizeof(User),0);
			fwrite(user,sizeof(User),1,fp);//��ȡ��Ϣ
			fclose(fp);
			puts("�޸ĳɹ�!");
		}
	    if(!strcmp(str,"b")||!strcmp(str,"B"))//�޸������
		{
			printf("�������һ����������Ĵ�,���ס�����:\n");
			while(1)
			{   
				printf("\"�ҵ���ʵ������?\" :\n");
				strcpy(str,"");//����
				while(strlen(str)==0)//����Ϊ��
				{
					printf("����������Ĵ�:");
					gets(str);
					if(strlen(str))break;
					else printf("�𰸲���Ϊ��!\n");
				}
				printf("���ٴ���������Ĵ�:");
				gets(user->pwdAnswer);
				if(!strcmp(user->pwdAnswer,str))break;
				puts("��������Ĵ𰸲�һ��!");
			}
						fseek(fp,(ith-1)*sizeof(User),0);
			fwrite(user,sizeof(User),1,fp);//��ȡ��Ϣ
			fclose(fp);
			puts("�޸ĳɹ�!");
		}
	    else 
		{
			fclose(fp);
			return;
		}
	}
	else//�ǹ���Ա
	{
		///printf("�������Աģ��\n");
		printf("\t�޸��û���(a) OR ����(b) OR �����(c) OR ����(d)?-[a-d](d):");
		gets(str);
		if(!strcmp(str,"a")||!strcmp(str,"A"))//�޸��û���
		{
			while(1)
			{
				strcpy(str,"");//����
				while(strlen(str)==0)//����Ϊ��
				{
					printf("�������û���:");
					gets(str);
					if(strlen(str))break;
					else printf("�û�������Ϊ��!\n");
				}
				printf("���ٴ������û���:");
				gets(user->name);

				if(findRecInUDB(str))printf("����û����ѱ�����ʹ��,��������һ���û���.");

				if((!strcmp(user->name,str))&&!findRecInUDB(str))break;
				if(strcmp(user->name,str)!=0)printf("���������û�����һ��!");
			}
			fseek(fp,(ith-1)*sizeof(User),0);
			fwrite(user,sizeof(User),1,fp);//��ȡ��Ϣ
			fclose(fp);
			puts("�޸ĳɹ�!");
		}
		if(!strcmp(str,"b")||!strcmp(str,"B"))//�޸�����
		{
			while(1)
			{
				strcpy(str,"");//����
				while(strlen(str)==0)//����Ϊ��
				{
					printf("�����õ�¼����:");
					gets(str);
					if(strlen(str))break;
					else printf("���벻��Ϊ��!\n");
				}
				printf("���ٴ������¼����:");
				gets(user->pwd);
				if(!strcmp(user->pwd,str))break;
				puts("�����������벻һ��!");
			}
			fseek(fp,(ith-1)*sizeof(User),0);
			fwrite(user,sizeof(User),1,fp);//��ȡ��Ϣ
			fclose(fp);
			puts("�޸ĳɹ�!");
		}
	    if(!strcmp(str,"c")||!strcmp(str,"C"))//�޸������
		{
			printf("�������һ����������Ĵ�,���ס�����:\n");
			while(1)
			{   
				printf("\"�ҵ���ʵ������?\" :\n");
				strcpy(str,"");//����
				while(strlen(str)==0)//����Ϊ��
				{
					printf("����������Ĵ�:");
					gets(str);
					if(strlen(str))break;
					else printf("�𰸲���Ϊ��!\n");
				}
				printf("���ٴ���������Ĵ�:");
				gets(user->pwdAnswer);
				if(!strcmp(user->pwdAnswer,str))break;
				puts("��������Ĵ𰸲�һ��!");
			}
						fseek(fp,(ith-1)*sizeof(User),0);
			fwrite(user,sizeof(User),1,fp);//��ȡ��Ϣ
			fclose(fp);
			puts("�޸ĳɹ�!");
		}
	    else 
		{
			fclose(fp);
			return;
		}
	}
}