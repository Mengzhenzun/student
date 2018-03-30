//=================================================================
//文件名：student.h
//开发者：蒙祯尊
//版  本：V 1.0.0
//完成日：2018年2月5日
//简  介：声明函数，包含文件及自定义宏和数据结构
//=================================================================



#ifndef H_STUDENT_HH                //防止可能出现的重复宏定义
#define H_STUDENT_HH

#include <stdio.h>
#include <stdlib.h>                 //标准库头文件
#include <conio.h>                  //console input/output 
#include <string.h>                 //字符数组


#define LEN sizeof(struct student)         
#define FORMAT "%-5d%-10s%-10.2lf%-10.2lf%-10.2lf%-10.2lf\n"               
#define DATA info[i].num,info[i].name,info[i].language,info[i].math,info[i].english,info[i].sum   


//定义结构体来存储每个学生的信息
extern struct student
{
	int  num;                        //学号
	char name[20];                   //姓名
	double language;                 //语文成绩
	double math;                     // 数学成绩
	double english;                  //英语成绩
    double sum;                      //成绩总分
};
extern struct student info[50];


//函数声明
void menu(void);                    //主菜单
void add(void);                     //录入学生成绩
void search(void);                  //查询学生成绩
void del(void);                     //删除学生成绩
void modify(void);                  //修改学生成绩
void total(void);                   //显示学生总人数
void show(void);                    //显示学生信息
void order(void);                   //按总分排序



#endif //H_STUDENT_HH 结束
