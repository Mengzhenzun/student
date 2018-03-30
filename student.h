//=================================================================
//�ļ�����student.h
//�����ߣ�������
//��  ����V 1.0.0
//����գ�2018��2��5��
//��  �飺���������������ļ����Զ��������ݽṹ
//=================================================================



#ifndef H_STUDENT_HH                //��ֹ���ܳ��ֵ��ظ��궨��
#define H_STUDENT_HH

#include <stdio.h>
#include <stdlib.h>                 //��׼��ͷ�ļ�
#include <conio.h>                  //console input/output 
#include <string.h>                 //�ַ�����


#define LEN sizeof(struct student)         
#define FORMAT "%-5d%-10s%-10.2lf%-10.2lf%-10.2lf%-10.2lf\n"               
#define DATA info[i].num,info[i].name,info[i].language,info[i].math,info[i].english,info[i].sum   


//����ṹ�����洢ÿ��ѧ������Ϣ
extern struct student
{
	int  num;                        //ѧ��
	char name[20];                   //����
	double language;                 //���ĳɼ�
	double math;                     // ��ѧ�ɼ�
	double english;                  //Ӣ��ɼ�
    double sum;                      //�ɼ��ܷ�
};
extern struct student info[50];


//��������
void menu(void);                    //���˵�
void add(void);                     //¼��ѧ���ɼ�
void search(void);                  //��ѯѧ���ɼ�
void del(void);                     //ɾ��ѧ���ɼ�
void modify(void);                  //�޸�ѧ���ɼ�
void total(void);                   //��ʾѧ��������
void show(void);                    //��ʾѧ����Ϣ
void order(void);                   //���ܷ�����



#endif //H_STUDENT_HH ����
