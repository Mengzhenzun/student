//=================================================================
//�ļ�����student.c
//�����ߣ�������
//��  ����V 1.0.0
//����գ�2018��2��5��
//��  �飺���Ƴ��򣬹���˵�����
//=================================================================


#include "student.h"


//������
int main()
{

    int n;            //ѡ���ܵı��
	menu();           //���ò˵�ѡ�����
    scanf("%d",&n);   //�û�������
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
		menu();         //ִ���깦�ܺ��ٴ���ʾ�˵�����
		scanf("%d",&n);
	}
}

//��ʾ�˵�
void menu()
{
	system("cls");
	printf("\n\n");
    printf("\t---------����һ��ѧ������ϵͳ---------\n\n");
	printf("\t1.����ѧ����Ϣ\n");
	printf("\t2.ɾ��ѧ����Ϣ\n");
	printf("\t3.��ѯѧ����Ϣ\n");
	printf("\t4.�޸�ѧ����Ϣ\n");
	printf("\t5.��ѧ����Ϣ��������\n");
	printf("\t6.�鿴ѧ��������\n");
    printf("\t0.�˳�ϵͳ\n");
	printf("\t��ѡ0-6��");

}



