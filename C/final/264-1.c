# include <stdio.h>
# include <string.h>
# include <malloc.h>
# include <windows.h>
# define TNUM 5
# define T12NUM 10*4
# define T45NUM 15*6
# define NAME "mushroom"
# define PASS "woaiwo"
typedef struct CarriageA
{
	int num;
	int A, B, C, D, E, F;
}CarA, *pCarA;
typedef struct CarriageB
{
	int num;
	int A, B, C, D;
}CarB, *pCarB;
typedef struct T123
{
	CarB num[10];
	double money;
	char ToName[50];
	char FromName[50];
}T12, *pT12;
typedef struct T456
{
	CarA num[15];
	double money;
	char ToName[50];
	char FromName[50];
}T45, *pT45;
typedef struct People
{
	char name[20];
	int tnum;
	int Carrnum;
	char Carriage[3];
}Poe, *pPoe;
typedef struct Tain
{
	char name[10];
	int pnum;
	int spnum;
	pT12 t12;
	pT45 t45;
	pPoe poenum;
}Tai, *pTai;
void TrainOut(Tai tra[], int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("�г���ţ�%d\n", i + 1);
		printf("����    ��%s\n", tra[i].name);
		printf("����������%d\n", tra[i].pnum);
		printf("ʵ��������%d\n", tra[i].spnum);
		if (tra[i].t12 != NULL)
		{
			printf("Ŀ�ĵص㣺%s\n", tra[i].t12->ToName);
			printf("�����ص㣺%s\n", tra[i].t12->FromName);
		}
		else if (tra[i].t45 != NULL)
		{
			printf("Ŀ�ĵص㣺%s\n", tra[i].t45->ToName);
			printf("�����ص㣺%s\n", tra[i].t45->FromName);
		}
		printf("\n\n");
	}
}
pT12 OpenT123()
{
	pT12 t = (pT12)calloc(1, sizeof(T12));
	strcpy(t->FromName, "�й�");
	strcpy(t->ToName, "���ô�");
	t->money = 12345.6;
	return t;
}
pT45 OpenT456()
{
	pT45 t = (pT45)calloc(1, sizeof(T45));
	strcpy(t->FromName, "�й�");
	strcpy(t->ToName, "����");
	t->money = 23456.7;
	return t;
}
int OpenTrain(Tai tra[], int num)
{
	char name[10] = { 0 };
	if (num == TNUM)
	{
		printf("�г����ﵽ����дΣ��޷�������");
		return num;
	}
	printf("ѡ��������(T123|T456)��");
	scanf("%s", name); getchar();
	if (strcmp(name, "T123") == 0)
	{
		tra[num].t12 = OpenT123();
		strcpy(tra[num].name, "T123");
		tra[num].t45 = NULL;
		tra[num].pnum = T12NUM;
		tra[num].spnum = 0;
		tra[num].poenum = (pPoe)calloc(T12NUM, sizeof(Poe));
	}
	else if (strcmp(name, "T456") == 0)
	{
		tra[num].t45 = OpenT456();
		strcpy(tra[num].name, "T456");
		tra[num].t12 = NULL;
		tra[num].pnum = T45NUM;
		tra[num].spnum = 0;
		tra[num].poenum = (pPoe)calloc(T45NUM,sizeof(Poe));
	}
	num++;
	return num;
}
void OutCarriage(Tai tra)
{
	int i;
	if (tra.t12 != NULL)
	{
		printf("0Ϊ��λ��1Ϊ�۳���\n");
		for (i = 0; i < 10; i++)
		{
			printf("%d�ڳ��᣺\n", i + 1);
			printf("A:%d  B:%d\n", tra.t12->num[i].A, tra.t12->num[i].B);
			printf("C:%d  D:%d\n", tra.t12->num[i].B, tra.t12->num[i].D);
			system("pause");
		}
	}
	if (tra.t45 != NULL)
	{
		printf("0Ϊ��λ��1Ϊ�۳���\n");
		for (i = 0; i < 15; i++)
		{
			printf("%d�ڳ��᣺\n", i + 1);
			printf("A:%d  B:%d\n", tra.t45->num[i].A, tra.t45->num[i].B);
			printf("C:%d  D:%d\n", tra.t45->num[i].B, tra.t45->num[i].D);
			printf("E:%d  F:%d\n", tra.t45->num[i].E, tra.t45->num[i].F);
			system("pause");
		}
	}
}
char *BuyCarriage(Tai tra, int x)
{
	char c[3] = { 0 };
	system("cls");
	if (tra.t12 != NULL)
	{
	int1:
		printf("��ѡ����λ��A|B|C|D����");
		scanf("%s", c); getchar();
		if (strcmp(c, "A") == 0)
		{
			if (tra.t12->num[x].A != 1)
			{
				tra.t12->num[x].A = 1;
				printf("��λ�ɹ���");
				return "A";
			}
			else
			{
				printf("��λʧ�ܣ�");
				return "0";
			}
		}
		else if (strcmp(c, "B") == 0)
		{
			if (tra.t12->num[x].B != 1)
			{
				tra.t12->num[x].B = 1;
				printf("��λ�ɹ���");
				return "B";
			}
			else
			{
				printf("��λʧ�ܣ�");
				return "0";
			}
		}
		else if (strcmp(c, "C") == 0)
		{
			if (tra.t12->num[x].C != 1)
			{
				tra.t12->num[x].C = 1;
				printf("��λ�ɹ���");
				return "C";
			}
			else
			{
				printf("��λʧ�ܣ�");
				return "0";
			}
		}
		else if (strcmp(c, "D") == 0)
		{
			if (tra.t12->num[x].D != 1)
			{
				tra.t12->num[x].D = 1;
				printf("��λ�ɹ���");
				return "D";
			}
			else
			{
				printf("��λʧ�ܣ�");
				return "0";
			}
		}
		else
		{
			printf("ѡ����ڣ��������룡\n");
			goto int1;
		}
	}
	if (tra.t45 != NULL)
	{
	int2:
		printf("��ѡ����λ��A|B|C|D|E|F����");
		scanf("%s", c); getchar();
		if (strcmp(c, "A") == 0)
		{
			if (tra.t45->num[x].A != 1)
			{
				tra.t45->num[x].A = 1;
				printf("��λ�ɹ���");
				return "A";
			}
			else
			{
				printf("��λʧ�ܣ�");
				return "0";
			}
		}
		else if (strcmp(c, "B") == 0)
		{
			if (tra.t45->num[x].B != 1)
			{
				tra.t45->num[x].B = 1;
				printf("��λ�ɹ���");
				return "B";
			}
			else
			{
				printf("��λʧ�ܣ�");
				return "0";
			}
		}
		else if (strcmp(c, "C") == 0)
		{
			if (tra.t45->num[x].C != 1)
			{
				tra.t45->num[x].C = 1;
				printf("��λ�ɹ���");
				return "C";
			}
			else
			{
				printf("��λʧ�ܣ�");
				return "0";
			}
		}
		else if (strcmp(c, "D") == 0)
		{
			if (tra.t45->num[x].D != 1)
			{
				tra.t45->num[x].D = 1;
				printf("��λ�ɹ���");
				return "D";
			}
			else
			{
				printf("��λʧ�ܣ�");
				return "0";
			}
		}
		else if (strcmp(c, "E") == 0)
		{
			if (tra.t45->num[x].E != 1)
			{
				tra.t45->num[x].E = 1;
				printf("��λ�ɹ���");
				return "E";
			}
			else
			{
				printf("��λʧ�ܣ�");
				return "0";
			}
		}
		else if (strcmp(c, "F") == 0)
		{
			if (tra.t45->num[x].F != 1)
			{
				tra.t45->num[x].F = 1;
				printf("��λ�ɹ���");
				return "F";
			}
			else
			{
				printf("��λʧ�ܣ�");
				return "0";
			}
		}
		else
		{
			printf("ѡ����ڣ��������룡\n");
			goto int2;
		}
	}
	return "0";
}
void Pay(double money)
{
	double number = 0;
	printf("Ӧ����%.2lf ʵ��:", money);
	scanf("%lf", &number); getchar();
	printf("����:%.2lf\n ֧���ɹ���\n", number - money);
}
int Buy(Tai tra[], int num)
{
	int x = 0, y = 0;
	char a[3] = { 0 };
	TrainOut(tra, num);
	printf("�����г���ţ�");
	scanf("%d", &x); getchar(); x--;
	if ((0 <= x) && (x < num))
	{
		if ((tra[x].spnum + 1) < tra[x].pnum)
		{
			printf("�������û�����");
			scanf("%s", tra[x].poenum[tra[x].spnum].name); getchar();
			OutCarriage(tra[x]);
			printf("��ѡ������ţ�");
			scanf("%d", &y); getchar(); y--;
			strcpy(a, BuyCarriage(tra[x], y));
			if (strcmp(a, "0") != 0)
			{
				if (tra[x].t12 != NULL)
				{
					Pay(tra[x].t12->money);
				}
				if (tra[x].t45 != NULL)
				{
					Pay(tra[x].t45->money);
				}
				strcpy(tra[x].poenum[tra[x].spnum].Carriage, a);
				tra[x].poenum[tra[x].spnum].tnum = num;
				tra[x].poenum[tra[x].spnum].Carrnum = x;
				tra[x].spnum++;
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		printf("�г��Ų����ڣ�\n");
		return 0;
	}
}
void OutUser(Tai tra[], int num)
{
	int i, j;
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < tra[i].spnum; j++)
		{
			printf("�ͻ�������%s\n", tra[i].poenum[j].name);
			printf("���Σ�%d �ڣ�%d  λ��%s\n\n", tra[i].poenum[j].tnum, tra[i].poenum[j].Carrnum + 1, tra[i].poenum[j].Carriage);
		}
	}
}
int Login()
{
	char name[10] = { 0 };
	char pass[10] = { 0 };
	printf("������ ����Ա�˺ţ�");
	scanf("%s", name); getchar();
	printf("������ ���룺");
	scanf("%s", pass); getchar();
	if (strcmp(name, NAME) == 0)
	{
		if (strcmp(pass, PASS) == 0)
		{
			return 1;
		}
		else
		{
			printf("�������\n");
			return 0;
		}
	}
	else
	{
		printf("�û�������\n");
		return 0;
	}
	return 0;
}
int Menu_1(Tai tra[], int num)
{
	int x;
	system("cls");
	if (Login())
	{
		while (1)
		{
			system("cls");
			printf("\n\n\n\n\n\n");
			printf("                   ****************************************************\n");
			printf("                   **                   1.���ӳ���                   **\n");
			printf("                   **                 2.�鿴�ͻ���Ϣ                 **\n");
			printf("                   **                   3.�˳���½                   **\n");
			printf("                   ****************************************************\n");
			scanf("%d", &x); getchar();
			switch (x)
			{
			case 1:
				num = OpenTrain(tra, num);
				break;
			case 2:
				OutUser(tra, num);
				break;
			case 3:
				system("pause");
				return num;
				break;
			default:printf("û�����ѡ�\n");
			}
			system("pause");
			system("cls");
		}
	}
	else
	{
		printf("��½ʧ�ܣ�\n");
	}
	return num;
}
int Menu(Tai tra[], int num)
{
	int x;
	printf("\n\n\n\n\n\n");
	printf("                 ****************************************************\n");
	printf("                 **                     1.��Ʊ                     **\n");
	printf("                 **                    2.�г���                    **\n");
	printf("                 **                  3.����Ա��½                  **\n");
	printf("                 ****************************************************\n");
	scanf("%d", &x); getchar();
	system("cls");
	switch (x)
	{
	case 1:
		if (Buy(tra, num))
		{
			printf("����ɹ�!\n");
		}
		else
		{
			printf("����ʧ��!\n");
		}
		break;
	case 2:
		TrainOut(tra, num);
		break;
	case 3:
		num = Menu_1(tra, num);
		break;
	case 0:
		system("pause");
		exit(0);
		break;
	default:printf("û�����ѡ�\n");
	}
	system("pause");
	system("cls");
	return num;
}

int main()
{
	int num = 0;
	Tai train[TNUM] = { 0 };
	system("color f0");
	while (1)
	{
		num = Menu(train, num);
	}
	return 0;
}

