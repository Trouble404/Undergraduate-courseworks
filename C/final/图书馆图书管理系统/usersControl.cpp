#include "LibBooksMana.h"

/*
在userInfoDB中遍历查询指定的昵称的记录,返回记录的序数
*/
int findRecInUDB(char name[])
{
	FILE *fp;
	User *user;
	int ith=1;
	user=(User *)malloc(sizeof(User));
	if((fp=fopen(userInfodb,"rb"))==NULL)//打开"用户注册信息数据库"
	{
		printf("userInfoDB打不开,正在返回...\n");
		return 0;
	}
	while(!feof(fp))//在数据库中从给定的地址开始向后遍历查询,或者找到匹配记录,或没有找到而退出
	{
		fread(user,sizeof(User),1,fp);//读取记录信息(空记录也读取判断)
		if((strlen(user->name)==strlen(name))&&(!strcmp(user->name,name)))//找到第一个记录,返回其序数
		{
			fclose(fp);
			free(user);
			return ith;
		}
		ith++;//没有找到,继续向后查找,这里空记录也要计数
	}
	free(user);
	fclose(fp);
	return 0;//没有找到要找到的记录
}

/*
用户登录:
要判断用户是否已注册;(要遍历 userInfoDB 文件)
还没有注册要提示注册;
若已注册登录需要密码;
若忘记密码可以根据注册设置的问题的答案找回

主要函数调用:userRegister();;int findRecInUDB(char str[60])

登录成功返回 1;否则返回 0;
*/
int login()
{
	FILE *fp;
	User *user;
	char str[60];
	int ith=0;
	puts("\t说明:管理员登录的帐号是: root,密码默认(没有修改)是: 123");
	printf("请输入用户名:");
	gets(str);
	ith=findRecInUDB(str);//第几个记录 (>=1)
	if(ith==0)//这个用户还没有注册
	{
		printf("这个用户还没有注册,请先注册.\n");
		return 0;
	}
	else//用户已注册
	{
		if((fp=fopen(userInfodb,"rb"))==NULL)//打开数据库
		{
			printf("\tuserInfoDB 文件打不开,正在返回...\n");
			return 0;
		}
		user=(User *)malloc(sizeof(User));
		fseek(fp,(ith-1)*sizeof(User),0);//定位
		fread(user,sizeof(User),1,fp);//读取信息
		printf("请输入密码:");
		gets(str);
		if(!strcmp(user->pwd,str))//相等
		{
			puts("登录成功!");
			fclose(fp);
			return ith;
		}
		else
		{
			puts("用户名或密码输入错误!");
			fclose(fp);
			return 0;
		}
	}
}
/*
新用户注册
*/
void userRegister()
{
	FILE *fp;
	User *user;
	char str[60]="";
	int ith=0;
	user=(User *)malloc(sizeof(User));

	while(strlen(str)==0)//输入为空
	{
		printf("请输入要注册的用户名:");
		gets(str);
		if(strlen(str))break;
		else printf("用户名不能为空!\n");
	}
	ith=findRecInUDB(str);//第几个记录 (>=1)
	while(ith)//用户名已被注册
	{
		printf("这个用户名已被注册,请重新选择用户名:");
		strcpy(str,"");//清零
		while(strlen(str)==0)//输入为空
		{
			printf("请输入要注册的用户名:");
			gets(str);
			if(strlen(str))break;
			else printf("用户名不能为空!\n");
		}
		//gets(str);
		ith=findRecInUDB(str);//第几个记录 (>=1)
	}
	puts("恭喜您,这个用户名可用!");//用户名只能唯一
	strcpy(user->name,str);
	while(1)
	{
		strcpy(str,"");//清零
		while(strlen(str)==0)//输入为空
		{
			printf("请设置登录密码:");
			gets(str);
			if(strlen(str))break;
			else printf("密码不能为空!\n");
		}
		//gets(user->pwd);
		printf("请再次输入登录密码:");
		gets(user->pwd);
		if(!strcmp(user->pwd,str))break;
		puts("两次输入密码不一致!");
	}
	strcpy(user->pwdIssue,"我的真实名字是?");
	printf("以下是找回密码的问题的答案,请记住这个答案:\n");
	while(1)
	{
		printf("\"我的真实名字是?\" :\n");
		strcpy(str,"");//清零
		while(strlen(str)==0)//输入为空
		{
			printf("请输入问题的答案:");
			gets(str);
			if(strlen(str))break;
			else printf("答案不能为空!\n");
		}
		printf("请再次输入问题的答案:");
		gets(user->pwdAnswer);
		if(!strcmp(user->pwdAnswer,str))break;
		puts("两次输入的答案不一致!");
	}
	if((fp=fopen(userInfodb,"ab"))==NULL)//打开数据库
	{
		printf("userInfoDB 文件打不开,正在返回...\n");
		return;
	}
	fwrite(user,sizeof(User),1,fp);//读取信息
	fclose(fp);
	puts("注册成功,恭喜您!");
}

/*
用户帐号管理
ith:识别是管理员登录还是学生登录
*/
void userInfoGovern(int ith)
{
	FILE *fp;
	User *user;
	char str[60]="";

	if((fp=fopen(userInfodb,"rb+"))==NULL)//打开数据库
	{
		printf("userInfoDB 文件打不开,正在返回...\n");
		return;
	}
	user=(User *)malloc(sizeof(User));
	fseek(fp,(ith-1)*sizeof(User),0);
	fread(user,sizeof(User),1,fp);
	printf("\t帐号详细信息:\n");
	printf("\t帐号:%s,密码:%s,找回密码的问题:%s,问题答案:%s\n",user->name,user->pwd,user->pwdIssue,user->pwdAnswer);
	if(ith==1)//管理员
	{
		///printf("进入管理员模块\n");
		printf("\t修改密码(a) OR 问题答案(b) OR 返回(c)?-[a-c](c):");
		gets(str);
		if(!strcmp(str,"a")||!strcmp(str,"A"))//修改密码
		{
			while(1)
			{
				strcpy(str,"");//清零
				while(strlen(str)==0)//输入为空
				{
					printf("请设置登录密码:");
					gets(str);
					if(strlen(str))break;
					else printf("密码不能为空!\n");
				}
				printf("请再次输入登录密码:");
				gets(user->pwd);
				if(!strcmp(user->pwd,str))break;
				puts("两次输入密码不一致!");
			}
			fseek(fp,(ith-1)*sizeof(User),0);
			fwrite(user,sizeof(User),1,fp);//读取信息
			fclose(fp);
			puts("修改成功!");
		}
	    if(!strcmp(str,"b")||!strcmp(str,"B"))//修改问题答案
		{
			printf("以下是找回密码的问题的答案,请记住这个答案:\n");
			while(1)
			{   
				printf("\"我的真实名字是?\" :\n");
				strcpy(str,"");//清零
				while(strlen(str)==0)//输入为空
				{
					printf("请输入问题的答案:");
					gets(str);
					if(strlen(str))break;
					else printf("答案不能为空!\n");
				}
				printf("请再次输入问题的答案:");
				gets(user->pwdAnswer);
				if(!strcmp(user->pwdAnswer,str))break;
				puts("两次输入的答案不一致!");
			}
						fseek(fp,(ith-1)*sizeof(User),0);
			fwrite(user,sizeof(User),1,fp);//读取信息
			fclose(fp);
			puts("修改成功!");
		}
	    else 
		{
			fclose(fp);
			return;
		}
	}
	else//非管理员
	{
		///printf("进入管理员模块\n");
		printf("\t修改用户名(a) OR 密码(b) OR 问题答案(c) OR 返回(d)?-[a-d](d):");
		gets(str);
		if(!strcmp(str,"a")||!strcmp(str,"A"))//修改用户名
		{
			while(1)
			{
				strcpy(str,"");//清零
				while(strlen(str)==0)//输入为空
				{
					printf("请设置用户名:");
					gets(str);
					if(strlen(str))break;
					else printf("用户名不能为空!\n");
				}
				printf("请再次输入用户名:");
				gets(user->name);

				if(findRecInUDB(str))printf("这个用户名已被别人使用,请输入另一个用户名.");

				if((!strcmp(user->name,str))&&!findRecInUDB(str))break;
				if(strcmp(user->name,str)!=0)printf("两次输入用户名不一致!");
			}
			fseek(fp,(ith-1)*sizeof(User),0);
			fwrite(user,sizeof(User),1,fp);//读取信息
			fclose(fp);
			puts("修改成功!");
		}
		if(!strcmp(str,"b")||!strcmp(str,"B"))//修改密码
		{
			while(1)
			{
				strcpy(str,"");//清零
				while(strlen(str)==0)//输入为空
				{
					printf("请设置登录密码:");
					gets(str);
					if(strlen(str))break;
					else printf("密码不能为空!\n");
				}
				printf("请再次输入登录密码:");
				gets(user->pwd);
				if(!strcmp(user->pwd,str))break;
				puts("两次输入密码不一致!");
			}
			fseek(fp,(ith-1)*sizeof(User),0);
			fwrite(user,sizeof(User),1,fp);//读取信息
			fclose(fp);
			puts("修改成功!");
		}
	    if(!strcmp(str,"c")||!strcmp(str,"C"))//修改问题答案
		{
			printf("以下是找回密码的问题的答案,请记住这个答案:\n");
			while(1)
			{   
				printf("\"我的真实名字是?\" :\n");
				strcpy(str,"");//清零
				while(strlen(str)==0)//输入为空
				{
					printf("请输入问题的答案:");
					gets(str);
					if(strlen(str))break;
					else printf("答案不能为空!\n");
				}
				printf("请再次输入问题的答案:");
				gets(user->pwdAnswer);
				if(!strcmp(user->pwdAnswer,str))break;
				puts("两次输入的答案不一致!");
			}
						fseek(fp,(ith-1)*sizeof(User),0);
			fwrite(user,sizeof(User),1,fp);//读取信息
			fclose(fp);
			puts("修改成功!");
		}
	    else 
		{
			fclose(fp);
			return;
		}
	}
}