#ifndef H_STUDENT_HH
#define H_STUDENT_HH

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>

typedef struct book_info
{
	char name[60];//���� -- ����
	char ISBN[30];//ISBN�� -- ����
	char author[60];//���� -- ����
	char editor[60];//���� -- ����
	char publisher[50];//������ -- ����
	char publishYear[18];//������ -- ����
	char printOrder[60];//���
	char price[10];//�۸�
	unsigned long totalNum;//ͼ������
	unsigned long lendNum;//�������
	unsigned long retainNum;//���౾��
};

/*
�û���Ϣ�ṹ��
*/
typedef struct User
{
	char name[60];//�ǳ�
	char pwd[30];//����
	char pwdIssue[20];//�һ����������:ͳһ��������Ϊ"�ҵ���ʵ������:"
	char pwdAnswer[40];//��������Ĵ�
};

extern char userInfodb[11];//�û�ע����Ϣ�洢�ļ�, Ϸ��"�û�ע�����ݿ�"
extern char fdb[10];//�������ݴ洢�ļ�(������),�ڱ������м��"���ݿ�"

//operateDB.cpp�ļ�
void reinstAllRecInDB();//�������ݿ���������,�������ü�¼(���Ի��һ�γ�ʼ��ʱ��)
void AddRecToDB();//�����ݿ���Ӽ�¼(����Աģ��)
void readAndDisAllRecInDB();//��ʾ���ݿ����м�¼��Ϣ
int findRecInDB(int ith,int way,char str[60]);//�����ݿ��в���ָ����¼(�м亯��)
void alterAndSaveRecToDB(int ith);//�����ݿ����޸Ĳ�����һ��ָ����¼

//operate.cpp�ļ�
void showTable(void);//�����ͷ
void printinfo(book_info *book);//��ӡָ����¼����ϸ��Ϣ
void queryInput(char str[],int &way);//��ѯѡ�����븨������
int initialQueRec(int fsite[]);//������ѯ����
int exactSearchRec();//��ȷ����
void alterRecInDB();//�޸�һ��ָ����¼
void lendBookAdm();//���ͼ��:��ָ�����û����ͼ��  
void revertBookAdm();//�黹ͼ��:�ض����û��黹ͼ��
void delRec();//ɾ��ָ����ͼ���¼(����Ա)

//usersControl.cpp
int findRecInUDB(char name[]);//��userInfoDB�б�����ѯָ�����ǳƵļ�¼
int login();//�û���¼
void userRegister();//���û�ע��
void userInfoGovern(int ith);//�û��ʺŹ���

//menu.cpp�ļ�
void initializeSoftware();//�����ʼ��
void handle_menu(void);//�˵�����
int menu_select(int stuOrAdm);//�˵�ѡ��

#endif