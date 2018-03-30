//=================================================================
//文件名：function.c
//开发者：蒙祯尊
//版  本：V 1.0.0
//完成日：2018年2月5日
//简  介：功能函数---增、删、查、改、排序、汇总人数
//=================================================================

#include "student.h"


//add()函数：录入学生信息
void add()
{
	int i,m=0;                                    //m表示记录的条数
	char ch[2];

	FILE *fp;                                     //定义文件指针
	if((fp=fopen("data","ab+"))==NULL)     
	{ 
		printf("can not open\n");
		return;
	}
	while(!feof(fp)) 
	{ 
		if(fread(&info[m],LEN,1,fp)==1)
			m++;                                  //统计当前记录条数
	}
	fclose(fp);
	if(m==0) 
		printf("No record!\n");
	else 
	{
		show();                                   //调用show函数显示原有信息
	}
	for(i=0;i<m;i++) 
	{
		fwrite(&info[i] ,LEN,1,fp);               //向指定的磁盘文件写入信息
	}

	printf("是否录入学生信息(y/n):");
	scanf("%s",&ch);

	while (strcmp(ch,"Y")==0||strcmp(ch,"y")==0)  //判断是否录入成绩
	{
		printf("录入学号：");
		scanf("%d",&info[m].num);                 //输入学号
        printf("录入姓名：");
		scanf("%d",&info[m].name);                //输入姓名
	    printf("录入语文成绩：");
	    scanf("%2f",&info[m].language);           //输入语文成绩
	    printf("录入数学成绩：");
	    scanf("%2f",&info[m].math);               //输入数学成绩
	    printf("录入英语成绩：");  
	    scanf("%2f",&info[m].english);            //输入英语成绩
	    info[m].sum=info[m].language+\
			info[m].math+info[m].english;         //计算出总成绩
		
		if(fwrite(&info[m],LEN,1,fp)!=1)          //将新录入的信息写入指定的磁盘文件
		{
			printf("can not save!"); 
			getch(); 
		}
		else
		{ 
			printf("%s saved!\n",info[m].name);
			m++;
		}
		printf("是否继续录入?(y/n):");            //询问是否继续
		scanf("%s",ch);
	}
    fclose(fp);
    printf("OK!\n");
}


//show()函数：显示现存学生信息
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
    printf("学号  姓名  语文成绩 数学成绩 英语成绩 总成绩");
	for (i=0;i<m;i++)
	{
        printf(FORMAT,DATA);                        //按格式显示信息
	}
}

//del()函数：删除学生信息
void del()
{
	FILE *fp;
	int snum,i,j,m=0;                               //snum:键入的学号
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
			printf("没有学生记录\n");
			return;
		}
		printf("请输入学号:");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
		{
			if(snum==info[i].num)
				break;
		}
		printf("找到该学生，是否删除?(y/n)");
		scanf("%s",ch);
		if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)      //判断是否要进行删除
		{
			for(j=i;j<m;j++)
			{
				info[j]=info[j+1];                    //将后一个记录移到前一个记录的位置
			m--;                                      //记录的总个数减1
			}
			for(j=0;j<m;j++)                          //将更改后的记录重新写入指定的磁盘文件中
			{
				if(fwrite(&info[j] ,LEN,1,fp)!=1)     //如果写入不成功将保存不成功
				{ 
					printf("保存不成功!\n");
					getch();
				}
			}
			fclose(fp);
			printf("删除成功！\n");
		}
	}

}

//search():查找信息函数
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
		printf("请输入学生学号:");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
		{
			if(snum==info[i].num)                        //查找输入的学号是否在记录中
			{ 
				printf("查找到该学生，是否显示?(y/n)");
				scanf("%s",ch);
				if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0) 
				{
					printf("学号  姓名  语文成绩 数学成绩 英语成绩 总成绩\t\n");
					printf(FORMAT,DATA);                 //将查找出的结果按指定格式输出
					break;
				}
				else
					return;
			} 
			else
				printf("未查找到该学生\n");
		}
					
}


//modify()函数：修改学生信息
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
			printf("暂无学生记录!\n");
			fclose(fp);
			return;
		}
		printf("请输入需要修改信息的学生学号!\n");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
		{
			if(snum==info[i].num)                  
			{	
				printf("查找到该学生，开始进行修改：\n");
				printf("\n修改学号:");
				scanf("%lf",&info[i].num);
                printf("\n修改名字:");
				scanf("%s",&info[i].name);                       
				printf("\n修改语文成绩:");
				scanf("%lf",&info[i].language);
				printf("\n修改数学成绩:");
				scanf("%lf",&info[i].math);
				printf("\n修改英语成绩:");
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
			for(j=0;j<m;j++)                          //将新修改的信息写入指定的磁盘文件中
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

//order()函数：自定义排序
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
			for(j=i+1;j<m;j++)                           //双重循环实现成绩比较并交换
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
				for(i=0;i<m;i++)                          //将重新排好序的内容重新写入指定的磁盘文件中
					if(fwrite(&info[i] ,LEN,1,fp)!=1)
					{ 
						printf("%s can not save!\n"); 
						getch();
					}
					fclose(fp);
					printf("保存成功！\n");
		}
}

//total()函数：统计现存学生人数
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
			m++;                                           //统计记录个数即学生个数
		if(m==0)
		{
			printf("no record!\n");
			fclose(fp);
			return;
		}
		printf("现存学生信息有 %d人。\n",m);               //将统计的个数输出
		show();
		fclose(fp);
	}
}
