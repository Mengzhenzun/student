//=================================================================
//�ļ�����function.c
//�����ߣ�������
//��  ����V 1.0.0
//����գ�2018��2��5��
//��  �飺���ܺ���---����ɾ���顢�ġ����򡢻�������
//=================================================================

#include "student.h"


//add()������¼��ѧ����Ϣ
void add()
{
	int i,m=0;                                    //m��ʾ��¼������
	char ch[2];

	FILE *fp;                                     //�����ļ�ָ��
	if((fp=fopen("data","ab+"))==NULL)     
	{ 
		printf("can not open\n");
		return;
	}
	while(!feof(fp)) 
	{ 
		if(fread(&info[m],LEN,1,fp)==1)
			m++;                                  //ͳ�Ƶ�ǰ��¼����
	}
	fclose(fp);
	if(m==0) 
		printf("No record!\n");
	else 
	{
		show();                                   //����show������ʾԭ����Ϣ
	}
	for(i=0;i<m;i++) 
	{
		fwrite(&info[i] ,LEN,1,fp);               //��ָ���Ĵ����ļ�д����Ϣ
	}

	printf("�Ƿ�¼��ѧ����Ϣ(y/n):");
	scanf("%s",&ch);

	while (strcmp(ch,"Y")==0||strcmp(ch,"y")==0)  //�ж��Ƿ�¼��ɼ�
	{
		printf("¼��ѧ�ţ�");
		scanf("%d",&info[m].num);                 //����ѧ��
        printf("¼��������");
		scanf("%d",&info[m].name);                //��������
	    printf("¼�����ĳɼ���");
	    scanf("%2f",&info[m].language);           //�������ĳɼ�
	    printf("¼����ѧ�ɼ���");
	    scanf("%2f",&info[m].math);               //������ѧ�ɼ�
	    printf("¼��Ӣ��ɼ���");  
	    scanf("%2f",&info[m].english);            //����Ӣ��ɼ�
	    info[m].sum=info[m].language+\
			info[m].math+info[m].english;         //������ܳɼ�
		
		if(fwrite(&info[m],LEN,1,fp)!=1)          //����¼�����Ϣд��ָ���Ĵ����ļ�
		{
			printf("can not save!"); 
			getch(); 
		}
		else
		{ 
			printf("%s saved!\n",info[m].name);
			m++;
		}
		printf("�Ƿ����¼��?(y/n):");            //ѯ���Ƿ����
		scanf("%s",ch);
	}
    fclose(fp);
    printf("OK!\n");
}


//show()��������ʾ�ִ�ѧ����Ϣ
void show()
{
	FILE *fp;
	int i,m=0;
	fp=fopen("data","ab+");
	while(!feof(fp))
	{
		if(fread(&info[m] ,LEN,1,fp)==1) 
			m++;
	}  
	fclose(fp);
    printf("ѧ��  ����  ���ĳɼ� ��ѧ�ɼ� Ӣ��ɼ� �ܳɼ�");
	for (i=0;i<m;i++)
	{
        printf(FORMAT,DATA);                        //����ʽ��ʾ��Ϣ
	}
}

//del()������ɾ��ѧ����Ϣ
void del()
{
	FILE *fp;
	int snum,i,j,m=0;                               //snum:�����ѧ��
	char ch[2];
	if((fp=fopen("data","ab+"))==NULL)
	{ 
		printf("can not open\n");
		return;
	}
	while(!feof(fp))  
	{
		if(fread(&info[m],LEN,1,fp)==1) 
			m++;
		fclose(fp);
		if(m==0) 
		{
			printf("û��ѧ����¼\n");
			return;
		}
		printf("������ѧ��:");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
		{
			if(snum==info[i].num)
				break;
		}
		printf("�ҵ���ѧ�����Ƿ�ɾ��?(y/n)");
		scanf("%s",ch);
		if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)      //�ж��Ƿ�Ҫ����ɾ��
		{
			for(j=i;j<m;j++)
			{
				info[j]=info[j+1];                    //����һ����¼�Ƶ�ǰһ����¼��λ��
			m--;                                      //��¼���ܸ�����1
			}
			for(j=0;j<m;j++)                          //�����ĺ�ļ�¼����д��ָ���Ĵ����ļ���
			{
				if(fwrite(&info[j] ,LEN,1,fp)!=1)     //���д�벻�ɹ������治�ɹ�
				{ 
					printf("���治�ɹ�!\n");
					getch();
				}
			}
			fclose(fp);
			printf("ɾ���ɹ���\n");
		}
	}

}

//search():������Ϣ����
void search()
{
	FILE *fp;
	int snum,i,m=0;
	char ch[2];
	if((fp=fopen("data","ab+"))==NULL)
	{ 
		printf("can not open\n");
		return;
	}
	while(!feof(fp)) 
		if(fread(&info[m],LEN,1,fp)==1) 
			m++;
		fclose(fp);
		if(m==0)
		{
			printf("no record!\n");
			return;
		}
		printf("������ѧ��ѧ��:");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
		{
			if(snum==info[i].num)                        //���������ѧ���Ƿ��ڼ�¼��
			{ 
				printf("���ҵ���ѧ�����Ƿ���ʾ?(y/n)");
				scanf("%s",ch);
				if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0) 
				{
					printf("ѧ��  ����  ���ĳɼ� ��ѧ�ɼ� Ӣ��ɼ� �ܳɼ�\t\n");
					printf(FORMAT,DATA);                 //�����ҳ��Ľ����ָ����ʽ���
					break;
				}
				else
					return;
			} 
			else
				printf("δ���ҵ���ѧ��\n");
		}
					
}


//modify()�������޸�ѧ����Ϣ
void modify()
{
	FILE *fp;
	int i,j,m=0,snum;
	if((fp=fopen("data","ab+"))==NULL)
	{ 
		printf("can not open\n");
		return;
	}
	while(!feof(fp))  
		if(fread(&info[m],LEN,1,fp)==1) 
			m++;
		if(m==0)
		{
			printf("����ѧ����¼!\n");
			fclose(fp);
			return;
		}
		printf("��������Ҫ�޸���Ϣ��ѧ��ѧ��!\n");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
		{
			if(snum==info[i].num)                  
			{	
				printf("���ҵ���ѧ������ʼ�����޸ģ�\n");
				printf("\n�޸�ѧ��:");
				scanf("%lf",&info[i].num);
                printf("\n�޸�����:");
				scanf("%s",&info[i].name);                       
				printf("\n�޸����ĳɼ�:");
				scanf("%lf",&info[i].language);
				printf("\n�޸���ѧ�ɼ�:");
				scanf("%lf",&info[i].math);
				printf("\n�޸�Ӣ��ɼ�:");
				scanf("%lf",&info[i].english);               
				info[i].sum=info[i].language+info[i].math+info[i].english;
			}
			else 
			{
				printf("can not find!");
				getchar();
				return;
			}
			if((fp=fopen("data","wb"))==NULL)
			{
				printf("can not open\n");
				return;
			}
			for(j=0;j<m;j++)                          //�����޸ĵ���Ϣд��ָ���Ĵ����ļ���
			{
				if(fwrite(&info[j] ,LEN,1,fp)!=1)
				{ 
					printf("can not save!"); 
					getch(); 
				}
				fclose(fp);
			}
		}
}

//order()�������Զ�������
void order()
{ 
	FILE *fp;
	int i=0,j=0,m=0;
	struct student t;
	if((fp=fopen("data","ab+"))==NULL)
	{ 
		printf("can not open!\n");
		return;
	}
	while(!feof(fp)) 
		if(fread(&info[m] ,LEN,1,fp)==1) 
			m++;
		fclose(fp);
		if(m==0) 
		{
			printf("no record!\n");
			return;
		}
		for(i=0;i<m-1;i++)
		{
			for(j=i+1;j<m;j++)                           //˫��ѭ��ʵ�ֳɼ��Ƚϲ�����
				if(info[i].sum<info[j].sum)
				{ 
					t=info[i];
					info[i]=info[j];
					info[j]=t;
				}
				if((fp=fopen("data","wb"))==NULL)
				{ 
					printf("can not open\n");
					return;
				}
				for(i=0;i<m;i++)                          //�������ź������������д��ָ���Ĵ����ļ���
					if(fwrite(&info[i] ,LEN,1,fp)!=1)
					{ 
						printf("%s can not save!\n"); 
						getch();
					}
					fclose(fp);
					printf("����ɹ���\n");
		}
}

//total()������ͳ���ִ�ѧ������
void total()
{ 
	FILE *fp;
	int m=0;
	if((fp=fopen("data","ab+"))==NULL)
	{         
		printf("can not open\n");
		return;
	}
	while(!feof(fp)) 
	{
		if(fread(&info[m],LEN,1,fp)==1) 
			m++;                                           //ͳ�Ƽ�¼������ѧ������
		if(m==0)
		{
			printf("no record!\n");
			fclose(fp);
			return;
		}
		printf("�ִ�ѧ����Ϣ�� %d�ˡ�\n",m);               //��ͳ�Ƶĸ������
		show();
		fclose(fp);
	}
}
