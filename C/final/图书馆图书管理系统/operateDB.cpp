#include "LibBooksMana.h"

/*
"数据库"查询基本函数(中间函数):
    在打开的"数据库"中,从给定的地址开始,用指定的方式遍历查询指定的记录;
    若有匹配的记录,则将第一个找到的记录的在数据库中是第几个记录返回;
    否则,返回 0.
注意:字符匹配是全匹配

ith:给定的开始查找的地址;(ith>=1)

way:查找方式:
    1 按ISBN号查找
    2 按书名查找
    3 按作者查找
    4 按主编查找
    5 按出版社查找
    6 按出版年查找
其他直接返回;

str:要匹配的字符串;

结果:返回第一个找到的在数据库中记录的 "排名"
(已测试)
*/
int findRecInDB(int ith,int way,char str[60])
{
	FILE *fp;
	book_info *book;
	book=(book_info *)malloc(sizeof(book_info));
	if((fp=fopen(fdb,"rb"))==NULL)//打开"数据库"
	{
		printf("database打不开,正在返回...\n");
		return 0;
	}
	if(fseek(fp,(ith-1)*sizeof(book_info),0)!=0)return 0;//以"数据库"文件的头为基准,进行文件位置定位
	switch (way)
	{
	case 1:	//按ISBN号查找
		while(!feof(fp))//在数据库中从给定的地址开始向后遍历查询,或者找到匹配记录,或没有找到而退出
		{
			fread(book,sizeof(book_info),1,fp);//读取记录信息(空记录也读取判断)
			if((strlen(book->ISBN)==strlen(str))&&(!strcmp(book->ISBN,str)))//找到第一个记录,返回其序数
			{
				fclose(fp);
				free(book);
				return ith;
			}
			ith++;//没有找到,继续向后查找,这里空记录也要计数
		}
		break;
	case 2://按书名查找,
		while(!feof(fp))//在数据库中从给定的地址开始向后遍历查询,或者找到匹配记录,或没有找到而退出
		{
			fread(book,sizeof(book_info),1,fp);//读取记录信息(空记录也读取判断)
			if((strlen(book->name)==strlen(str))&&(!strcmp(book->name,str)))//找到第一个记录,返回其序数
			{
				fclose(fp);
				free(book);
				return ith;
			}
			ith++;//没有找到,继续向后查找,这里空记录也要计数
		}
		break;
	case 3://按作者查找
		while(!feof(fp))//在数据库中从给定的地址开始向后遍历查询,或者找到匹配记录,或没有找到而退出
		{
			fread(book,sizeof(book_info),1,fp);//读取记录信息(空记录也读取判断)
			if((strlen(book->author)==strlen(str))&&(!strcmp(book->author,str)))//找到第一个记录,返回其序数
			{
				fclose(fp);
				free(book);
				return ith;
			}
			ith++;//没有找到,继续向后查找,这里空记录也要计数
		}
		break;
	case 4://按主编查找
		while(!feof(fp))//在数据库中从给定的地址开始向后遍历查询,或者找到匹配记录,或没有找到而退出
		{
			fread(book,sizeof(book_info),1,fp);//读取记录信息(空记录也读取判断)
			if((strlen(book->editor)==strlen(str))&&(!strcmp(book->editor,str)))//找到第一个记录,返回其序数
			{
				fclose(fp);
				free(book);
				return ith;
			}
			ith++;//没有找到,继续向后查找,这里空记录也要计数
		}
		break;
		case 5://按出版社查找
		while(!feof(fp))//在数据库中从给定的地址开始向后遍历查询,或者找到匹配记录,或没有找到而退出
		{
			fread(book,sizeof(book_info),1,fp);//读取记录信息(空记录也读取判断)
			if((strlen(book->publisher)==strlen(str))&&(!strcmp(book->publisher,str)))//找到第一个记录,返回其序数
			{
				fclose(fp);
				free(book);
				return ith;
			}
			ith++;//没有找到,继续向后查找,这里空记录也要计数
		}
		break;
		case 6://按出版年查找
		while(!feof(fp))//在数据库中从给定的地址开始向后遍历查询,或者找到匹配记录,或没有找到而退出
		{
			fread(book,sizeof(book_info),1,fp);//读取记录信息(空记录也读取判断)
			if((strlen(book->publishYear)==strlen(str))&&(!strcmp(book->publishYear,str)))//找到第一个记录,返回其序数
			{
				fclose(fp);
				free(book);
				return ith;
			}
			ith++;//没有找到,继续向后查找,这里空记录也要计数
		}
		break;
	default://输入其他直接退出
		break;
	}
	free(book);
	fclose(fp);
	return 0;//没有找到要找到的记录
}
/*
按照指定的方式修改并保存一条指定的记录到数据库查查询一次都要打开和关闭文件
(已测试)
*/
void alterAndSaveRecToDB(int ith)
{
	FILE *fp;
	book_info *book;
	char str[60];
	int way;
	book=(book_info *)malloc(sizeof(book_info));
	if((fp=fopen(fdb,"rb+"))==NULL)//打开"数据库"
	{
		printf("database打不开,正在返回...\n");
		return;
	}
	fseek(fp,(ith-1)*sizeof(book_info),0);//定位
	fread(book,sizeof(book_info),1,fp);//读取
	printf("是否要修改这本图书信息?[Y/n](n):");
	gets(str);
	if(!strcmp(str,"Y")||!strcmp(str,"y"))
	{
		printf("\n\t\t\t*****************************\n");
	    printf("\t\t\t*   修改方式说明:           *\n");
	    printf("\t\t\t*       1.修改ISBN号        *\n");
	    printf("\t\t\t*       2.修改书名          *\n");
	    printf("\t\t\t*       3.修改作者          *\n");
	    printf("\t\t\t*       4.修改主编          *\n");
	    printf("\t\t\t*       5.修改出版社        *\n");
	    printf("\t\t\t*       6.修改出版年        *\n");
		printf("\t\t\t*       7.修改出版次        *\n");
		printf("\t\t\t*       8.修改价格          *\n");
		printf("\t\t\t*       9.修改总本数        *\n");
		printf("\t\t\t*      10.修改借出数        *\n");
	    printf("\t\t\t*    若输入其他则全部修改   *\n");
	    printf("\t\t\t*****************************\n");
	    printf("\t\t   左边数字对应相应的修改方式,请选择 1-10 :");
		gets(str);
		way=atoi(str);
		switch(way)
		{
		case 1:
			puts("输入要修改的ISBN号:");//修改内容
		    gets(str);
		    strcpy(book->ISBN,str);
			break;
		case 2:
			puts("输入要修改的书名:");//修改内容
		    gets(str);
		    strcpy(book->name,str);
			break;
		case 3:
			puts("输入要修改的作者:");//修改内容
		    gets(str);
			strcpy(book->author,str);
			break;
		case 4:
			puts("输入要修改的主编:");//修改内容
		    gets(str);
			strcpy(book->editor,str);
			break;
		case 5:
			puts("输入要修改的出版社:");//修改内容
		    gets(str);
		    strcpy(book->publisher,str);
			break;
		case 6:
			puts("输入要修改的出版年:");//修改内容
		    gets(str);
			strcpy(book->publishYear,str);
			break;
		case 7:
			puts("输入要修改的版次:");//修改内容
		    gets(str);
			strcpy(book->printOrder,str);
			break;
		case 8:
			puts("请输入价格(元)--请输入数字:");
			gets(str);
			strcpy(book->price,str);
			break;
		case 9:
			puts("输入要修改的总本数--请输入数字,若输入非数字则本次输入为0 :");//修改内容
		    gets(str);
			book->totalNum=atol(str);
			while(book->totalNum<0)
			{
				if(book->totalNum<0)printf("输入错误!总本数不能为负数,请重新输入:");
				else printf("输入错误!总本数不能小于借出本数,请重新输入:");
				gets(str);
				book->totalNum=atol(str);
			}
			break;
		case 10:
			puts("输入要修改的借出数--请输入数字,若输入非数字则本次输入为0 :");//修改内容
		    gets(str);
		    book->lendNum=atol(str);
			while((book->lendNum<0)||(book->lendNum>book->totalNum))
			{
				if(book->lendNum<0)
					printf("输入错误!借出本数不能为负数,请重新输入:");
				else printf("输入错误!借出本数不能大于总本数,请重新输入:");
				gets(str);
				book->lendNum=atol(str);
			}
			break;
		default://全部修改
			puts("输入要修改的ISBN号:");//修改内容
		    gets(str);
			strcpy(book->ISBN,str);
			puts("输入要修改的书名:");//修改内容
			gets(str);
			strcpy(book->name,str);
			puts("输入要修改的作者:");//修改内容
			gets(str);
			strcpy(book->author,str);
			puts("输入要修改的主编:");//修改内容
			gets(str);
			strcpy(book->editor,str);
			puts("输入要修改的出版社:");//修改内容
			gets(str);
			strcpy(book->publisher,str);
			puts("输入要修改的出版年:");//修改内容
			gets(str);
			strcpy(book->publishYear,str);
			puts("输入要修改的版次:");//修改内容
			gets(str);
			strcpy(book->printOrder,str);
			puts("请输入价格(元)--请输入数字:");
			gets(str);
			strcpy(book->price,str);
			puts("请输入图书总数--请输入数字,若输入非数字则本次输入为0 :");
			gets(str);
			book->totalNum=atol(str);
			while(book->totalNum<0||book->totalNum<book->lendNum)
			{
				if(book->totalNum<0)printf("输入错误!总本数不能为负数,请重新输入:");
				else printf("输入错误!总本数不能小于借出本数,请重新输入 :");
				gets(str);
				book->totalNum=atol(str);
			}
			puts("请输入图书借出数--请输入数字,若输入非数字则本次输入为0 :");
			gets(str);
			book->lendNum=atol(str);
			while((book->lendNum<0)||(book->lendNum>book->totalNum))
			{
				if(book->lendNum<0)
					printf("输入错误!借出本数不能为负数,请重新输入 :");
				else printf("输入错误!借出本数不能大于总本数,请重新输入 :");
				gets(str);
				book->lendNum=atol(str);
			}
			
			break;
		}
		book->retainNum=book->totalNum- book->lendNum;
		fseek(fp,(ith-1)*sizeof(book_info),0);//定位
		fwrite(book,sizeof(book_info),1,fp);
		puts("修改信息已保存,请继续...");
	}
	fclose(fp);
	free(book);
}

/*
从图书馆"数据库"中,逐条读取全部记录,并显示每条记录的详细信息
(已测试)(有待完善 : 文件是否到尾部的判断还不精确)
*/
void readAndDisAllRecInDB()
{
	FILE *fp;//数据库文件指针
	book_info *book;//结构体指针
	char str[16];
	book=(book_info *)malloc(sizeof(book_info));//在内存中为book分配一个结构体大小的内存区
	
	if((fp=fopen(fdb,"rb"))==NULL)//以只读方式打开"数据库",并将fp指向其缓冲区(在内存中)的首地址
	{
		puts("database文件打不开,正在返回...");
		return;
	}
	showTable();
	unsigned long i=0;//图书本数
	while(!feof(fp))//判断是否到文件的结尾
	{
		if((i+1)%10==0)//每打印10个信息停一下
		{
			printf("是要返回到主菜单 (y),还是要继续显示查询结果 (n)?--[Y/n](n):");
			gets(str);
			if(!strcmp(str,"y")||!strcmp(str,"Y"))//要返回主菜单
			{
				fclose(fp);
				puts("正在返回到主菜单...");
				return;
			}
			printf("\n");//选否,继续打印
			showTable();
		}
		fread(book,sizeof(book_info),1,fp);//在打开的二进制文件fdb中,将当前fp指向的的数据块(一个book_info结构体)复制给Arr,之后fp向后移动
		if(strcmp(book->name,"")!=0)//过滤掉空的记录:书名不为空,即记录信息不为空
		{
			i++;
			printinfo(book);
		}
	}
	printf("图书馆记录进数据库的图书总共有 %d 册\n",i);
	fclose(fp);//若以写的形式打开文件,则必须要关闭文件,否则数据会丢失
	free(book);
}

/*
在原有数据的基础上向数据库添加新记录(管理员功能模块)
(已测试)
*/
void AddRecToDB()
{
	FILE *fp;
	book_info *book;
	char str[60];
	book=(book_info *)malloc(sizeof(book_info));
	if((fp=fopen(fdb,"ab"))==NULL)//打开"数据库"
	{
		puts("database文件打不开,正在返回...");
		return;
	}
	printf("确定要添加新书?[Y/n](n):");
	gets(str);
	if(strcmp(str,"y")&&strcmp(str,"Y")) //不添加,返回主菜单
	{
		puts("不添加新书,正在返回...");
		fclose(fp);
		return;
	}
	//添加新书记录
	while(1)
	{
		puts("请输入新书的书名:");
		gets(str);
		strcpy(book->name,str);
		puts("请输入ISBN号:");
		gets(str);
		strcpy(book->ISBN,str);
		puts("请输入作者:");
		gets(str);
		strcpy(book->author,str);
		puts("请输入主编:");
		gets(str);
		strcpy(book->editor,str);
		puts("请输入出版社:");
		gets(str);
		strcpy(book->publisher,str);
		puts("请输入出版年:");
		gets(str);
		strcpy(book->publishYear,str);
		puts("请输入版次:");
		gets(str);
		strcpy(book->printOrder,str);
		puts("请输入价格(元)--请输入数字:");
		gets(str);
		strcpy(book->price,str);
		puts("请输入图书总数--请输入数字,若输入非数字则本次输入为0:");
		gets(str);
		book->totalNum=atol(str);
		while(book->totalNum<0)
		{
			printf("输入错误!总本数不能为负数,请重新输入:");
			gets(str);
			book->totalNum=atol(str);
		}
		puts("请输入图书借出数--请输入数字,若输入非数字则本次输入为0:");
		gets(str);
		book->lendNum=atol(str);
		while((book->lendNum<0)||(book->lendNum>book->totalNum))
		{
			if(book->lendNum<0)
				printf("输入错误!借出本数不能为负数,请重新输入:");
			else printf("输入错误!借出本数不能大于总本数,请重新输入:");
			gets(str);
			book->lendNum=atol(str);
		}
		book->retainNum=book->totalNum-book->lendNum;
		fwrite(book,sizeof(book_info),1,fp);

		puts("添加的新书数据已保存,是否继续添加新书?[Y/n](n)");
		gets(str);
		if(strcmp(str,"y")&&strcmp(str,"Y"))
		{
			puts("不继续添加新书,正在返回...");
			break;
		}
	}

	fclose(fp);
	free(book);
}
/*
重新设置8本图书记录(之前所有的记录都被删除),此函数用于调试或数据库初始化时使用
(已测试)
*/
void reinstAllRecInDB()
{
	FILE *fp;
	book_info *book;
	book=(book_info *)malloc(sizeof(book_info));
	if((fp=fopen(fdb,"wb"))==NULL)return;//创建 database 文件或覆盖原 database 文件
	//1
	strcpy(book->name,"java实战开发案例解析");
	strcpy(book->ISBN,"970-2-676-596-1");
	strcpy(book->author,"吴艳");
	strcpy(book->editor,"张海藩");
	strcpy(book->publisher,"北京大学出版社");
	strcpy(book->publishYear,"2007");
	strcpy(book->printOrder,"2007年9月第1版");
	strcpy(book->price,"33");
	book->totalNum=214;
	book->lendNum=34;
	book->retainNum=book->totalNum-book->lendNum;
	fwrite(book,sizeof(book_info),1,fp);
	//2
	strcpy(book->name,"php开发典型模块大全(修订版)");
	strcpy(book->ISBN,"974-7-11-55696-2");
	strcpy(book->author,"王文");
	strcpy(book->editor,"刘仲");
	strcpy(book->publisher,"清华大学出版社");
	strcpy(book->publishYear,"2005");
	strcpy(book->printOrder,"2005年8月第6版");
	strcpy(book->price,"15");
	book->totalNum=432;
	book->lendNum=94;
	book->retainNum=book->totalNum-book->lendNum;
	fwrite(book,sizeof(book_info),1,fp);
	//3
	strcpy(book->name,"html网页设计经典入门");
	strcpy(book->ISBN,"978-7-01-02678-7");
	strcpy(book->author,"葛文静");
	strcpy(book->editor,"李诗妮");
	strcpy(book->publisher,"电子工业出版社");
	strcpy(book->publishYear,"2010");
	strcpy(book->printOrder,"2010年2月第7版");
	strcpy(book->price,"57");
	book->totalNum=453;
	book->lendNum=76;
	book->retainNum=book->totalNum-book->lendNum;
	fwrite(book,sizeof(book_info),1,fp);
	//4
	strcpy(book->name,"css层次样表美工");
	strcpy(book->ISBN,"97-7-01-09356-0");
	strcpy(book->author,"庄韩");
	strcpy(book->editor,"欧娜");
	strcpy(book->publisher,"人民邮电出版社");
	strcpy(book->publishYear,"2012");
	strcpy(book->printOrder,"2012年3月第4版");
	strcpy(book->price,"97");
	book->totalNum=567;
	book->lendNum=324;
	book->retainNum=book->totalNum-book->lendNum;
	fwrite(book,sizeof(book_info),1,fp);
	//5
	strcpy(book->name,"深入理解计算机系统");
	strcpy(book->ISBN,"974-7-01-05666-2");
	strcpy(book->author,"(美)Randal E.Bryant David R.O'Hallaron");
	strcpy(book->editor,"雷迎春");
	strcpy(book->publisher,"机械工业出版社");
	strcpy(book->publishYear,"2012");
	strcpy(book->printOrder,"2012年1月第1版");
	strcpy(book->price,"56");
	book->totalNum=214;
	book->lendNum=34;
	book->retainNum=book->totalNum-book->lendNum;
	fwrite(book,sizeof(book_info),1,fp);
	//6
	strcpy(book->name,"php网络编程技术与实例");
	strcpy(book->ISBN,"97-7-01-025696-9");
	strcpy(book->author,"赵斯思");
	strcpy(book->editor,"曹衍龙");
	strcpy(book->publisher,"人民邮电出版社");
	strcpy(book->publishYear,"2011");
	strcpy(book->printOrder,"2011年7月第1版");
	strcpy(book->price,"15");
	book->totalNum=432;
	book->lendNum=94;
	book->retainNum=book->totalNum-book->lendNum;
	fwrite(book,sizeof(book_info),1,fp);
	//7
	strcpy(book->name,"计算机组成原理与汇编语言程序设计(第2版)");
	strcpy(book->ISBN,"97-7-0257-0466-1");
	strcpy(book->author,"徐洁");
	strcpy(book->editor,"徐洁 俸远祯");
	strcpy(book->publisher,"电子工业出版社");
	strcpy(book->publishYear,"2011");
	strcpy(book->printOrder,"2011年12月第5版");
	strcpy(book->price,"97");
	book->totalNum=567;
	book->lendNum=324;
	book->retainNum=book->totalNum-book->lendNum;
	fwrite(book,sizeof(book_info),1,fp);
	//8
	strcpy(book->name,"数据结构(C语言版)");
	strcpy(book->ISBN,"97-7-5635-0696-5");
	strcpy(book->author,"吴艳");
	strcpy(book->editor,"严蔚敏 吴伟民");
	strcpy(book->publisher,"清华大学出版社");
	strcpy(book->publishYear,"2012");
	strcpy(book->printOrder,"2012年5月第3版");
	strcpy(book->price,"97");
	book->totalNum=567;
	book->lendNum=324;
	book->retainNum=book->totalNum-book->lendNum;
	fwrite(book,sizeof(book_info),1,fp);
	//9
	strcpy(book->name,"概率论与数理统计(经管类.第四版)");
	strcpy(book->ISBN,"978-7-04-046696-8");
	strcpy(book->author,"吴昌");
	strcpy(book->editor,"吴昌");
	strcpy(book->publisher,"中国人民大学出版社");
	strcpy(book->publishYear,"2012");
	strcpy(book->printOrder,"2012年2月第3版");
	strcpy(book->price,"56");
	book->totalNum=227;
	book->lendNum=34;
	book->retainNum=book->totalNum-book->lendNum;
	//10
	fwrite(book,sizeof(book_info),1,fp);
	strcpy(book->name,"离散数学");
	strcpy(book->ISBN,"979-7-3462-5796-1");
	strcpy(book->author,"屈婉玲 耿素云 张立昂");
	strcpy(book->editor,"屈婉玲 耿素云 张立昂");
	strcpy(book->publisher,"高等教育出版社");
	strcpy(book->publishYear,"2008");
	strcpy(book->printOrder,"2008年3月第1版");
	strcpy(book->price,"97");
	book->totalNum=247;
	book->lendNum=143;
	book->retainNum=book->totalNum-book->lendNum;
	fwrite(book,sizeof(book_info),1,fp);
	//11
	strcpy(book->name,"高等数学");
	strcpy(book->ISBN,"97-7-04-021277-8");
	strcpy(book->author,"同济大学数学系");
	strcpy(book->editor,"同济大学数学系");
	strcpy(book->publisher,"高等教育出版社");
	strcpy(book->publishYear,"2010");
	strcpy(book->printOrder,"2007年6月第6版");
	strcpy(book->price,"97");
	book->totalNum=957;
	book->lendNum=674;
	book->retainNum=book->totalNum-book->lendNum;
	fwrite(book,sizeof(book_info),1,fp);

	fclose(fp);
	free(book);
}