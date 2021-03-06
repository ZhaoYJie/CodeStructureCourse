/*
1、实验目的
通过本实验，掌握线性表链式存储结构的基本原理和基本运算以及在实际问题中的应用。
2、实验内容                                                      
  建立某班学生的通讯录，要求用链表存储。
  具体功能包括：
（1）可以实现插入一个同学的通讯录记录；
 	（2）能够删除某位同学的通讯录；
  	（3）对通讯录打印输出。
3、实验要求
（1）定义通讯录内容的结构体；
（2）建立存储通讯录的链表结构并初始化；                                                 
（3）建立主函数：
       1）建立录入函数（返回主界面）
       2）建立插入函数（返回主界面）
       3）建立删除函数（返回主界面）
       4）建立输出和打印函数（返回主界面）
            I）通过循环对所有成员记录输出
           II）输出指定姓名的某个同学的通讯录记录
       5）退出 
*/


#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/**************************/
/*****链表表现头文件*******/
/**************************/
typedef struct link_node{
	char *info[10]; //学号
	char name[12];  // 姓名
	char *phone[12]; //通讯录记录;
	struct link_node *next;
}node;



//自定义输入数据函数 
node *my_scanf(node *head)
{
	node *p = NULL,*q = NULL;
	char info[10] = {0};
	int n = 0;
	char m[10] = {0};
	printf("请输入数据的个数：\n");
	scanf("%d",&n);
	for(int a = 1;a <= n;a ++)
	{
		printf("请输入第%d个联系人的通讯录信息：\n",a);
		p = (node *)malloc(sizeof(node));
		printf("请输入学号: \n");
		scanf("%s",p->info);
		printf("请输入姓名: \n");
		scanf("%s",p->name);
		printf("请输入号码：\n");
		scanf("%s",p->phone);
		p->next = NULL;
		if(a == 1)
		{
			head = p;
			q = p;
		}
		else
		{
			q->next = p;
			q = p;
		}
	}
	return head;
}

/****************************/
/****建立一个空的单链表******/
/****************************/
node *init()
{
	return NULL;
}

/**********************************/
/****输出单链表中各个节点的值******/
/**********************************/
void display(node *head)
{
	printf("%12s%16s%18s","学号","姓名","通讯录记录\n");
	node *p;
	p = head;
	if(!p)
		printf("\n链表是空的！");
	else
	{
		while(p)
		{
			printf("%15s%15s%15s\n",p->info,p->name,p->phone);
			p = p->next;
		}
	}
	printf("\n");
}


node *find(node *head,int i)
{
	int j = 1;
	node *p = head;
	if(i < 0)
		printf("电话簿中没有该数据！\n");
	while(p && j != i)
	{
		p = p->next;
		j ++;
	}
	return p;
}

/********************************************/
/****单链表第i个结点后插入值为x的新结点******/
/********************************************/
node *insert(node *head,int i)
{
	
	node *p,*q;
	q = find(head,i);
	//查找第i个结点
	if(!q && i < 0)
		printf("\n找不到第%d个结点",i);
	else
	{
		//为p开辟一个空间
		p = (node *)malloc(sizeof(node));
		printf("请输入插入节点数据：\n");
		//设置新节点的数据
		printf("请输入学号：\n"); 
		scanf("%s",p->info);
		printf("请输入姓名：\n") ;
		scanf("%s",p->name);
		printf("请输入电话：\n"); 
		scanf("%s",p->phone);
		//如果插入的结点是单链表的第一个结点
		if(i == 0)
		{
			p->next = head;
			head = p;
		}
		else
		{
			p->next = q->next;
			q->next = p;
		}
	}
	return head;
}


node *dele(node *head)
{
	int id = 0;
	int j = 1;
	printf("请输入想要删除的通讯录的位置：\n");
	scanf("%d",&id);
	node *pre = NULL,*p;
	if(!head)
	{
		printf("单链表是空的！");
		return head;
	}
	p = head;
	//指针指向数据存在并且没有找到符合的数据
	while(p && (id != j));
	{
		pre = p;
		p = p->next;
		j ++;
	}
	if(p)
	{
		//前驱结点不存在，即想要删除第一个数据
		if(!pre)
			head = head->next;
		else
			pre->next = p->next;
		free(p);
	}
	return head;
}

void print(node *head)
{
	char name[12];
	printf("请输入想要查找的学生姓名：\n");
	scanf("%s",name);
	node *p = head;
	if(!head)
		printf("链表为空！无法查询！"); 
	//指针指向数据存在并且没有找到符合的数据
	while(p && (strcmp(name,p->name) != 0))
		p = p->next;
	printf("\n\t查找成功！\n\t该学生的信息为：\n");
	printf("%12s%16s%18s","学号","姓名","通讯录记录\n");
	printf("%15s%15s%15s\n",p->info,p->name,p->phone);
}

void interface()
{
	printf("\t\t------------------------------------\n");
	printf("\t\t******简易学生通讯录******\n\n");
	printf("\t\t0.清屏\n");
	printf("\t\t1.录入联系人信息\n");
	printf("\t\t2.插入联系人信息\n");
	printf("\t\t3.删除联系人信息\n");
	printf("\t\t4.打印所有联系人信息\n");
	printf("\t\t5.根据学生姓名查找通讯录记录并打印\n");
	printf("\t\t6.退出\n");
	printf("\t\t------------------------------------\n");
}


int main()
{
	int i = 0,j = 0;
	node *head,*p;
	head = init();
	interface();
	while(1)
	{
		printf("输入功能编号:\n");
		scanf("%d",&i);
		switch(i)
		{
			case 0:
				system("cls");
				break;
			case 1:{
				head = my_scanf(head);
				printf("\t\t录入成功!\n"); 
				printf("------------------------------------\n");
				break;
			}
			case 2:{
				printf("向通讯录当中插入数据：\n");
				printf("请输入想要插入的位置；\n");
				scanf("%d",&j); 
				head = insert(head,j);
				printf("\n插入完的通讯录：\n");
				display(head);
				printf("------------------------------------\n");
				break;
			}
			case 3:{
				head = dele(head);
				printf("删除完的通讯录：\n");
				display(head);
				printf("------------------------------------\n");
				break;
			}
			case 4:{
				printf("\t\n通讯录中的记录：\n\n");
				display(head);
				printf("------------------------------------\n");
				break;
			}
			case 5:{
				print(head);
				printf("------------------------------------\n");
				break;
			}
			case 6:
				exit(0);
				break;
			default:
				printf("\t->输入有误,重新输入<-\n");
				break;
		}
	}
	return 0;
}


