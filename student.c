//=================================================================
//文件名：student.c
//开发者：蒙祯尊
//版  本：V 1.0.0
//完成日：2018年2月5日
//简  介：控制程序，管理菜单命令
//=================================================================


#include "student.h"


//主函数
int main()
{

    int n;            //选择功能的编号
	menu();           //调用菜单选择界面
    scanf("%d",&n);   //用户键入编号
    while(1)
	{
		switch(n)
		{
        case 0:
			exit(0);
            break;
		case 1:
			add();
			break;
		case 2:
			del();
			break;
		case 3:
			search();
			break;
		case 4:
			modify();
			break;
		case 5:
			order();
			break;
		case 6:
			total();
			break;
		default:
			break;

		}

		getch();
		menu();         //执行完功能后再次显示菜单界面
		scanf("%d",&n);
	}
}

//显示菜单
void menu()
{
	system("cls");
	printf("\n\n");
    printf("\t---------这是一个学生管理系统---------\n\n");
	printf("\t1.增加学生信息\n");
	printf("\t2.删除学生信息\n");
	printf("\t3.查询学生信息\n");
	printf("\t4.修改学生信息\n");
	printf("\t5.对学生信息进行排序\n");
	printf("\t6.查看学生总人数\n");
    printf("\t0.退出系统\n");
	printf("\t请选0-6：");

}



