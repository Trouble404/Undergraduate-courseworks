#include "LibBooksMana.h"


/*
�����ڽ���һ��exeִ���ļ�����½��г�ʼ��;

���:���� database �� userInfoDB ���������ļ�,�ֱ�洢"ͼ���"����ͼ����Ϣ �� �û�ע����Ϣ(ͬʱд������Ա����Ϣ)
(�Ѳ���)
*/
void initializeSoftware()
{
	FILE *fp;
	User *adm;//����Ա
	if(access(fdb, 0)!=0)//������database�ļ�
	{
		printf("���ڴ���database�ļ�...\n");
		reinstAllRecInDB();//��ʼ�� database �ļ������ʾ��ͼ������
	}
	if(access(userInfodb,0)!=0)//������userInfo�ļ�
	{
		printf("���ڴ���userInfoDB�ļ�...\n");
		if((adm=(User *)malloc(sizeof(User)))==NULL)//�����ڴ�
		{
			puts("user �ڴ����ʧ��,�����˳�����...");
			exit(0);
		}
		if((fp=fopen(userInfodb,"wb"))==NULL)//������userInfoDB�ļ�
		{
			puts("�ļ���ʧ��,�����˳�����...");
			exit(0);
		}
		strcpy(adm->name,"root");//����Ա�ʺ�
		strcpy(adm->pwd,"123");//����Ա����
		strcpy(adm->pwdIssue,"�ҵ���ʵ������?");
		strcpy(adm->pwdAnswer,"123");
		fwrite(adm,sizeof(User),1,fp);
		fclose(fp);
		free(adm);
	}
}

/*
�˵�������,ֻҪ����Ӧ�Ĺ��ܺ�������ȥ���
(�Ѳ���)
*/
void handle_menu(void)
{
	char str[16];
loop:	
	initializeSoftware();//�Ƿ���Ҫ��ʼ��

	int ith=0;
	while(!ith)//û���û���¼
	{
		printf("\n\t\t��¼(a) OR ע��(b) OR �˳�ϵͳ(c)? -[a-c](a):");
		gets(str);
		if(!strcmp(str,"c")||!strcmp(str,"C"))//�˳�
		{
			fcloseall();
			exit(0);
		}
		if(!strcmp(str,"b")||!strcmp(str,"B"))userRegister();
		else ith=login();
	}
	//userInfoDB �й���Ա�ǵ�һ����¼���Ҳ���ı�
	if(ith==1)//����Ա��ݵ�¼���������Աģ��
	{
		for(; ;)
		{
			switch(menu_select(1))//����ģ��
			{
			case 1://����Ա�������
				userInfoGovern(ith);
				break;
			case 2://�����ݿ������ͼ��(���)
				AddRecToDB();
				break;
			case 3://���ͼ��(���)
				lendBookAdm();
				break;
			case 4://�黹ͼ��(���)
				revertBookAdm();
				break;
			case 5://��ʾ����ͼ����Ϣ(���)
				readAndDisAllRecInDB();
				break;
			case 6://��ѯͼ��(���)
				exactSearchRec();
				break;
			case 7://�޸�ָ��ͼ��(���)
				alterRecInDB();
				break;
			case 8://ɾ��ָ��ͼ��
				delRec();
				break;
			case 9://ע����¼(���)
				goto loop;
				break;
			}
		}
	}
	else//��ѧ������ݵ�¼������ѧ��ģ��
	{
		for(; ;)
		{
			switch(menu_select(0))
			{
			case 1://�û��ʺŹ���
				userInfoGovern(ith);
				break;
			case 2://���ͼ��(���)
				lendBookAdm();
				break;
			case 3://�黹ͼ��(���)
				revertBookAdm();
				break;
			case 4://��ʾͼ�������ͼ��(���)
				readAndDisAllRecInDB();
				break;
			case 5://��ͼ����в�ѯָ��ͼ��(���)
				exactSearchRec();
				break;
			case 6://ע����¼(���)
				goto loop;
				break;
			}
		}
	}
}
/*
�˵�ѡ������ menu_selectҪ�� handle_menu() ���ܺ������Ӧ
(�Ѳ���)
*/
int menu_select(int stuOrAdm)
{
	char str[16];
	int select=0;
	if(stuOrAdm==1)//����Ա����ģ��ѡ��
	{   //����ѡ����ʾ��,Ҫ�� handle_menu() ���ܺ������Ӧ
		printf("\n\t\t\t**************************\n");
		printf("\t\t\t*  ����Ա���ܲ˵�:       *\n");
		printf("\t\t\t*  1.  ����Ա�ʺŹ���    *\n");
		printf("\t\t\t*  2.  �����ͼ��        *\n");
		printf("\t\t\t*  3.  ���ͼ��          *\n");
		printf("\t\t\t*  4.  �黹ͼ��          *\n");
		printf("\t\t\t*  5.  ��ʾ����ͼ����Ϣ  *\n");
		printf("\t\t\t*  6.  ��ѯͼ����Ϣ      *\n");
		printf("\t\t\t*  7.  �޸�ͼ����Ϣ      *\n");
	    printf("\t\t\t*  8.  ɾ��ͼ����Ϣ      *\n");
		printf("\t\t\t*  9.  ע����¼          *\n");
		printf("\t\t\t**************************\n");
		//��ʾ��������
		printf("\n\t\t\t������ֶ�Ӧ��Ӧ����,��ѡ 1-9:");
		for(; ;)
		{
			gets(str);
			select=atoi(str);//atoi():���ַ���ת����������.
			if(select<1||select>9)printf("\n\t���������ѡ 1-9 :");
			else break;
		}
	}
	else//ѧ������ģ��ѡ��
	{   //����ѡ����ʾ��,Ҫ�� handle_menu() ���ܺ������Ӧ
		printf("\n\t\t\t**************************\n");
		printf("\t\t\t*  ѧ�����ܲ˵�:         *\n");
		printf("\t\t\t*  1.  �û��ʺŹ���      *\n");
		printf("\t\t\t*  2.  ���ͼ��          *\n");
		printf("\t\t\t*  3.  �黹ͼ��          *\n");
		printf("\t\t\t*  4.  ��ʾ����ͼ����Ϣ  *\n");
		printf("\t\t\t*  5.  ��ѯͼ����Ϣ      *\n");
		printf("\t\t\t*  6.  ע����¼          *\n");
		printf("\t\t\t**************************\n");
		//��ʾ��������
		printf("\n\t\t\t������ֶ�Ӧ��Ӧ����,��ѡ 1-6:");
		for(; ;)
		{
			gets(str);
			select=atoi(str);//atoi():���ַ���ת����������.
			if(select<1||select>6)printf("\n\t\t���������ѡ 1-6 :");
			else break;
		}
	}
	return select;
}
