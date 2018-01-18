/* menu.h */
/* 菜单类的声明 */ 

class menu 
{
public: 

friend char choose(char i);
friend int inputNumber();
static string Identity; 


static void SelWho(); //选择登录身份 
static void StuMenu(); //学生菜单 
static void ManaMenu(); //管理员菜单 
static void StuEditMenu(); //学生信息修改 
static void ManaEditMenu(); //管理员信息修改 
static void SelCourseMenu(); //选课菜单 
static void CourSearchMenu();//课程信息查询 
static void StuSearchMenu(); //学生信息查询 
static void Msystem(); //管理系统 
static void isback(); //返回主菜单 
~menu(); 


}; 