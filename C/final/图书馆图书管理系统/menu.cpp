#include "LibBooksMana.h"


/*
程序在仅有一个exe执行文件情况下进行初始化;

结果:创建 database 和 userInfoDB 两二进制文件,分别存储"图书馆"所有图书信息 和 用户注册信息(同时写进管理员的信息)
(已测试)
*/
void initializeSoftware()
{
	FILE *fp;
	User *adm;//管理员
	if(access(fdb, 0)!=0)//不存在database文件
	{
		printf("正在创建database文件...\n");
		reinstAllRecInDB();//初始化 database 文件并添加示例图书数据
	}
	if(access(userInfodb,0)!=0)//不存在userInfo文件
	{
		printf("正在创建userInfoDB文件...\n");
		if((adm=(User *)malloc(sizeof(User)))==NULL)//分配内存
		{
			puts("user 内存分配失败,正在退出程序...");
			exit(0);
		}
		if((fp=fopen(userInfodb,"wb"))==NULL)//创建打开userInfoDB文件
		{
			puts("文件打开失败,正在退出程序...");
			exit(0);
		}
		strcpy(adm->name,"root");//管理员帐号
		strcpy(adm->pwd,"123");//管理员密码
		strcpy(adm->pwdIssue,"我的真实名字是?");
		strcpy(adm->pwdAnswer,"123");
		fwrite(adm,sizeof(User),1,fp);
		fclose(fp);
		free(adm);
	}
}

/*
菜单处理函数,只要将相应的功能函数挂上去便可
(已测试)
*/
void handle_menu(void)
{
	char str[16];
loop:	
	initializeSoftware();//是否需要初始化

	int ith=0;
	while(!ith)//没有用户登录
	{
		printf("\n\t\t登录(a) OR 注册(b) OR 退出系统(c)? -[a-c](a):");
		gets(str);
		if(!strcmp(str,"c")||!strcmp(str,"C"))//退出
		{
			fcloseall();
			exit(0);
		}
		if(!strcmp(str,"b")||!strcmp(str,"B"))userRegister();
		else ith=login();
	}
	//userInfoDB 中管理员是第一个记录并且不会改变
	if(ith==1)//管理员身份登录，进入管理员模块
	{
		for(; ;)
		{
			switch(menu_select(1))//功能模块
			{
			case 1://管理员密码管理
				userInfoGovern(ith);
				break;
			case 2://向数据库添加新图书(完成)
				AddRecToDB();
				break;
			case 3://借出图书(完成)
				lendBookAdm();
				break;
			case 4://归还图书(完成)
				revertBookAdm();
				break;
			case 5://显示所有图书信息(完成)
				readAndDisAllRecInDB();
				break;
			case 6://查询图书(完成)
				exactSearchRec();
				break;
			case 7://修改指定图书(完成)
				alterRecInDB();
				break;
			case 8://删除指定图书
				delRec();
				break;
			case 9://注销登录(完成)
				goto loop;
				break;
			}
		}
	}
	else//以学生的身份登录，进入学生模块
	{
		for(; ;)
		{
			switch(menu_select(0))
			{
			case 1://用户帐号管理
				userInfoGovern(ith);
				break;
			case 2://借出图书(完成)
				lendBookAdm();
				break;
			case 3://归还图书(完成)
				revertBookAdm();
				break;
			case 4://显示图书馆所有图书(完成)
				readAndDisAllRecInDB();
				break;
			case 5://在图书馆中查询指定图书(完成)
				exactSearchRec();
				break;
			case 6://注销登录(完成)
				goto loop;
				break;
			}
		}
	}
}
/*
菜单选择处理函数 menu_select要和 handle_menu() 功能函数相对应
(已测试)
*/
int menu_select(int stuOrAdm)
{
	char str[16];
	int select=0;
	if(stuOrAdm==1)//管理员功能模块选择
	{   //功能选择提示块,要和 handle_menu() 功能函数相对应
		printf("\n\t\t\t**************************\n");
		printf("\t\t\t*  管理员功能菜单:       *\n");
		printf("\t\t\t*  1.  管理员帐号管理    *\n");
		printf("\t\t\t*  2.  添加新图书        *\n");
		printf("\t\t\t*  3.  借出图书          *\n");
		printf("\t\t\t*  4.  归还图书          *\n");
		printf("\t\t\t*  5.  显示所有图书信息  *\n");
		printf("\t\t\t*  6.  查询图书信息      *\n");
		printf("\t\t\t*  7.  修改图书信息      *\n");
	    printf("\t\t\t*  8.  删除图书信息      *\n");
		printf("\t\t\t*  9.  注销登录          *\n");
		printf("\t\t\t**************************\n");
		//提示输入数字
		printf("\n\t\t\t左边数字对应相应功能,请选 1-9:");
		for(; ;)
		{
			gets(str);
			select=atoi(str);//atoi():把字符串转换成整型数.
			if(select<1||select>9)printf("\n\t输入错误，重选 1-9 :");
			else break;
		}
	}
	else//学生功能模块选择
	{   //功能选择提示块,要和 handle_menu() 功能函数相对应
		printf("\n\t\t\t**************************\n");
		printf("\t\t\t*  学生功能菜单:         *\n");
		printf("\t\t\t*  1.  用户帐号管理      *\n");
		printf("\t\t\t*  2.  借出图书          *\n");
		printf("\t\t\t*  3.  归还图书          *\n");
		printf("\t\t\t*  4.  显示所有图书信息  *\n");
		printf("\t\t\t*  5.  查询图书信息      *\n");
		printf("\t\t\t*  6.  注销登录          *\n");
		printf("\t\t\t**************************\n");
		//提示输入数字
		printf("\n\t\t\t左边数字对应相应功能,请选 1-6:");
		for(; ;)
		{
			gets(str);
			select=atoi(str);//atoi():把字符串转换成整型数.
			if(select<1||select>6)printf("\n\t\t输入错误，重选 1-6 :");
			else break;
		}
	}
	return select;
}
