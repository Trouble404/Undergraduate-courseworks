#include "LibBooksMana.h"

/*
输出表头
(已测试)
*/
void showTable()
{
	printf("\n*******************************************************************************\n");
	printf("ISBN号|书     名|作  者|主    编|出版社|出版年|版次|价格元|总本数|借出数|现余数\n");
	printf("*******************************************************************************\n");
}
/*
打印指定记录的详细信息//美工有待完善
(已测试)
*/
void printinfo(book_info *book)
{
	printf("%-6s|%-26s|%-8s|%-8s|%-20s|%-8s|%-4s|%-4s|%-5d|%-5d|%-5d\n",book->ISBN,book->name,
		book->author,book->editor,book->publisher,book->publishYear,book->printOrder,book->price,
		book->totalNum,book->lendNum,book->retainNum);
	printf("===============================================================================\n");
}

/*
查询输入辅助函数 :
(已测试)
*/
void queryInput(char str[],int &way)
{
	printf("\n\t\t\t**************************\n");
	printf("\t\t\t*  查询方式说明:         *\n");
	printf("\t\t\t*     1.按ISBN号查找     *\n");
	printf("\t\t\t*     2.按书名查找       *\n");
	printf("\t\t\t*     3.按作者查找       *\n");
	printf("\t\t\t*     4.按主编查找       *\n");
	printf("\t\t\t*     5.按出版社查找     *\n");
	printf("\t\t\t*     6.按出版年查找     *\n");
	printf("\t\t\t*  若输入其他则直接返回  *\n");
	printf("\t\t\t**************************\n");
	printf("\t\t  左边数字对应相应的查询方式,请选择 1-6 :");
	gets(str);
	way=atoi(str);
	switch (way)
	{
	case 1:printf("请输入ISBN:");break;
	case 2:printf("请输入书名:");break;
	case 3:printf("请输入作者:");break;
    case 4:printf("请输入主编:");break;
	case 5:printf("请输入出版社:");break;
	case 6:printf("请输入出版年:");break;
	default:printf("选择错误,正在返回...\n");return;
	}
	gets(str);//获取输入信息
	if(strlen(str)==0)
	{
		puts("没有输入,正在返回...");
		return;
	}
}
/*
初步查询 : 显示所有匹配的记录的详细信息
主要函数调用:  findRecInDB();数据库查找函数(基本函数)
(已测试)
*/
int initialQueRec(int fsite[])
{
	FILE *fp;
	book_info *book;
	int findNum=0;//查找到的记录的数量
	int fsi=0;//fsite[]的下标 , fsi=findnum%198;保证 当fsite数组在200个大小时不会溢出
	int ith=1;//记录当前记录在数据库中是第几个 (ith>=1) 记录,(ith-1)*sizeof(book_info)表示第ith个记录在数据库中的地址
	//int fsite[200];// ith 的缓存数组,以便在要进一步精确查找时可以快速定位
	int way=0;//查询方式
	char str[60]="";//获取输入的字符串
	book=(book_info *)malloc(sizeof(book_info));//给book开辟内存空间

	if((fp=fopen(fdb,"rb"))==NULL)//打开"数据库"
	{
		printf("database打不开,正在返回...\n");
		free(book);
		return 0;
	}
	queryInput(str,way);//获取str和way
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
	ith=1;//从第一个记录开始查找
	while(1)
	{
		if((ith=findRecInDB(ith,way,str))!=0)//找到的话便打印,ith表示在数据库中的是序数
		{
			findNum++;
			fsi=findNum-1;
			if(fsi>=198)fsi=fsi%198;
			fsite[fsi]=ith;//存储记录在数据库中的是第几个的数组, 缓存结果
			if(findNum%10==0)//每打印10个信息停一下
			{
				printf("输入任意键继续显示查询结果...");
				gets(str);
				printf("\n");
				showTable();
			}
			fseek(fp,(ith-1)*sizeof(book_info),0);//定位
			fread(book,sizeof(book_info),1,fp);
			//printf("这个记录在数据库中是第 %d 个记录\n",fsite[fsi]);
			printinfo(book);
			ith++;//查询前移
		}
		else break;//否则退出
	}
	printf("总共找到 %d 本书.\n\n",findNum);
	fclose(fp);
	free(book);//释放book内存空间
	return findNum;
}
/*
精确查询: 在初步查询的基础上进一步精确查询,直到只有一个记录符合条件或者没有符合条件的记录
主要函数调用: initialQueRec()->findRecInDB()

结果: 
返回 0:没有找到要查询的记录
返回 该记录在数据库中是第几个记录 (>=1):找到唯一的记录
(已测试)
*/
int exactSearchRec()
{
	FILE *fp;
	book_info *book;
	int findnum=0;//找到的数量
	int fsite[200];//缓存搜索到的记录在"数据库"中是第ith个记录的数组,以便在要进一步精确查找时可以快速定位
	char str[60];

	findnum=initialQueRec(fsite);//用fsite存储初步搜索结果 fsite[0]-fsite[findnum-1]存储找到的记录"地址"

	book=(book_info *)malloc(sizeof(book_info));
	if((fp=fopen(fdb,"rb"))==NULL)//打开"数据库"
	{
		printf("database打不开,正在返回...\n");
		return 0;
	}
    //1   初步搜索结果不止一本图书
	if(findnum>1)
	{
		printf("\n查询结果不唯一,是否要进一步精确查找?[Y/n](y):");//是否要进一步精确查找
		gets(str);
		if(!strcmp(str,"n")||!strcmp(str,"N"))
		{
			puts("正在返回...");
			return 0;
		}
		//进一步在 查询缓存区 精确查找
		/*
		通过一步一步的过滤不符合条件的记录来获得最终一个记录或没有记录
		*/
		int way=0;
		int ith;
		while(findnum>1)//不止有一个记录
		{
			queryInput(str,way);//查询输入,获得 str 和 way
			if(way<1||way>6)//确保way只有1-6
			{
				fclose(fp);
				return 0;
			}
			if(strlen(str)==0)//确保有查询输入
			{
				fclose(fp);
				return 0;
			}

			int biao=0;
			int ni=0;
			while(fsite[ni]>0)
			{
				//数据库中快速定位
				fseek(fp,(fsite[ni]-1)*sizeof(book_info),0);
				fread(book,sizeof(book_info),1,fp);//读取记录
				switch(way)
				{
				case 1://ISBN
					if(!strcmp(book->ISBN,str))break;//相等不处理
					else//不相等删除,findenum--
					{
						fsite[ni]=fsite[findnum-1];
						fsite[findnum-1]=-1;
						findnum--;
						biao=1;
					}
					break;
				case 2://书名
					if(!strcmp(book->name,str))break;//相等不处理
					else//不相等删除,findenum--
					{
						fsite[ni]=fsite[findnum-1];
						fsite[findnum-1]=-1;
						findnum--;
						biao=1;
					}
					break;
				case 3://作者
					if(!strcmp(book->author,str))break;//相等不处理
					else//不相等删除,findenum--
					{
						fsite[ni]=fsite[findnum-1];
						fsite[findnum-1]=-1;
						findnum--;
						biao=1;
					}
					break;
				case 4://主编
					if(!strcmp(book->editor,str))break;//相等不处理
					else//不相等删除,findenum--
					{
						fsite[ni]=fsite[findnum-1];
						fsite[findnum-1]=-1;
						findnum--;
						biao=1;
					}
					break;
				case 5://出版社
					if(!strcmp(book->publisher,str))break;//相等不处理
					else//不相等删除,findenum--
					{
						fsite[ni]=fsite[findnum-1];
						fsite[findnum-1]=-1;
						findnum--;
						biao=1;
					}
					break;
				case 6://出版年
					if(!strcmp(book->publishYear,str))break;//相等不处理
					else//不相等删除,findenum--
					{
						fsite[ni]=fsite[findnum-1];
						fsite[findnum-1]=-1;
						findnum--;
						biao=1;
					}
					break;
				}
				if(!biao)ni++;//相等前移,不相等不用移
				biao=0;
			}
			if(findnum>1)
			{
				printf("查询结果不唯一,是否要进一步精确查找?[Y/n](Y):");
				gets(str);
				if(!strcmp(str,"n")||!strcmp(str,"N"))
				{
					puts("结束精确查询,正在返回...");
					return 0;
				}
			}
			else break;
		}
	}
	//2   没有找到要修改的图书
	if(findnum==0)
	{
		puts("没有找到要查询的图书!正在返回...");
		fclose(fp);
		return 0;
	}
	//3   最后结果只有一本图书
	fseek(fp,(fsite[0]-1)*sizeof(book_info),0);//定位
	fread(book,sizeof(book_info),1,fp);//读取
	showTable();
	printinfo(book);//打印
	fclose(fp);
	free(book);//释放book内存空间
	return fsite[0];
}
/*
修改指定的记录的信息(管理员模块)
主要函数调用: initialQueRec()->findRecInDB();

          alterAndSaveRecToDB()(基本函数)

若有多个查询结果,则要精确到一个或者没有

(已测试)
*/
void alterRecInDB()
{
	int ith=0;
	puts("\n修改图书信息之前,首先要精确查询:");
	ith=exactSearchRec();
	if(ith!=0)alterAndSaveRecToDB(ith);
	else puts("没有找到要修改的图书!正在返回主菜单...");
}

/*
借出图书(管理员)
主要函数调用 : initialQueRec()->findRecInDB()
(已测试)
*/
void lendBookAdm()
{
	FILE *fp;
	int ith=0;
	int lendnum=0;
	char str[60];
	book_info *book;
	book=(book_info *)malloc(sizeof(book_info));
	puts("\n借出图书之前,首先要进行精确查询:");

	ith=exactSearchRec();

	if(ith>0)//找到唯一的图书
	{
		if((fp=fopen(fdb,"rb+"))==NULL)//打开"数据库"
		{
			printf("database打不开,正在返回...\n");
			return;
		}
		fseek(fp,(ith-1)*sizeof(book_info),0);//定位
		fread(book,sizeof(book_info),1,fp);//读取必须要读取
		printf("确定要借出?[Y/n](y):");
		gets(str);
		if(!strcmp(str,"n")||!strcmp(str,"N"))
		{
			puts("正在退出...");
			fclose(fp);
			free(book);
			return;
		}
		printf("请输入要借出这本书的本数--请输入数字,否则本次输入为0 :");
		gets(str);
		lendnum=atol(str);
		while((lendnum>book->retainNum)||(lendnum<0))
		{
			if(lendnum>book->retainNum)
				printf("\n输入错误!借出数目大于现存量,请重新输入 :");
			else 
				printf("\n输入错误!借出数不能为负数,请重新输入 :");
			gets(str);
			lendnum=atol(str);
		}
		book->retainNum-=lendnum;
		book->lendNum+=lendnum;

		fseek(fp,-sizeof(book_info),1);//定位
		fwrite(book,sizeof(book_info),1,fp);
		puts("图书已借出,请继续...");
		fclose(fp);
	}
	else puts("没有找到要借出的图书!正在返回主菜单...");
	free(book);
}
/*
归还图书(管理员)
(已测试)
*/
void revertBookAdm()
{
	FILE *fp;
	int ith=0;
	int lendnum=0;
	char str[60];
	book_info *book;
	book=(book_info *)malloc(sizeof(book_info));
	puts("\n归还图书之前,首先要进行精确查询:");

	ith=exactSearchRec();

	if(ith>0)//找到唯一的图书
	{
		if((fp=fopen(fdb,"rb+"))==NULL)//打开"数据库"
		{
			printf("database打不开,正在返回...\n");
			return;
		}
		fseek(fp,(ith-1)*sizeof(book_info),0);//定位
		fread(book,sizeof(book_info),1,fp);//读取必须要读取
		printf("确定要归还?[Y/n](y):");
		gets(str);
		if(!strcmp(str,"n")||!strcmp(str,"N"))
		{
			puts("正在退出...");
			fclose(fp);
			free(book);
			return;
		}
		printf("请输入要归还这本书的本数--请输入数字,否则本次输入为0 :");
		gets(str);
		lendnum=atol(str);
		while((lendnum>book->lendNum)||(lendnum<0))
		{
			if(lendnum>book->lendNum)
				printf("\n输入错误!归还数目大于借出数,请重新输入 :");
			else 
				printf("\n输入错误!归还数不能为负数,请重新输入 :");
			gets(str);
			lendnum=atol(str);
		}
		book->retainNum+=lendnum;
		book->lendNum-=lendnum;

		fseek(fp,-sizeof(book_info),1);//定位
		fwrite(book,sizeof(book_info),1,fp);
		puts("图书已归还,请继续...");
		fclose(fp);
	}
	else puts("没有找到要归还的图书!正在返回主菜单...");
	free(book);
}
/*
删除指定的记录

主要函数调用:initialQueRec()->findRecInDB()

(已测试)(还可完善:释放空(已被删除)记录的空间)
*/
void delRec()
{
	FILE *fp;
	int ith=0;
	int lendnum=0;
	char str[60];
	book_info *book;
	book=(book_info *)malloc(sizeof(book_info));

	puts("\n删除图书之前,首先要进行精确查询:");

	ith=exactSearchRec();

	if(ith>0)//找到唯一的图书
	{
		if((fp=fopen(fdb,"rb+"))==NULL)//打开"数据库"
		{
			printf("database打不开,正在返回...\n");
			return;
		}
		fseek(fp,(ith-1)*sizeof(book_info),0);//定位
		fread(book,sizeof(book_info),1,fp);//读取必须要读取
		printf("确定要删除?[Y/n](y):");
		gets(str);
		if(!strcmp(str,"n")||!strcmp(str,"N"))
		{
			puts("正在退出...");
			fclose(fp);
			free(book);
			return;
		}
		//将要删除的记录的全部信息清零
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

		fseek(fp,-sizeof(book_info),1);//定位
		fwrite(book,sizeof(book_info),1,fp);//写入
		puts("图书已删除,请继续...");
		fclose(fp);
	}
	else puts("没有找到要删除的图书!正在返回主菜单...");
	free(book);
}