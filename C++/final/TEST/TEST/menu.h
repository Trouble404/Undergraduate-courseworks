/* menu.h */
/* �˵�������� */ 

class menu 
{
public: 

friend char choose(char i);
friend int inputNumber();
static string Identity; 


static void SelWho(); //ѡ���¼��� 
static void StuMenu(); //ѧ���˵� 
static void ManaMenu(); //����Ա�˵� 
static void StuEditMenu(); //ѧ����Ϣ�޸� 
static void ManaEditMenu(); //����Ա��Ϣ�޸� 
static void SelCourseMenu(); //ѡ�β˵� 
static void CourSearchMenu();//�γ���Ϣ��ѯ 
static void StuSearchMenu(); //ѧ����Ϣ��ѯ 
static void Msystem(); //����ϵͳ 
static void isback(); //�������˵� 
~menu(); 


}; 