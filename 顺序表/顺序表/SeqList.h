#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int Data;

typedef struct SeqList
{
	Data* arr;//顺序表指针
	int size;//现有元素个数
	int capacity;//顺序表容量
}SL;

void SeqListInit(SL* ps);//顺序表初始化
void SeqListDestory(SL* ps);//顺序表销毁

void SeqListPushBack(SL* ps, Data x);//尾部插入
void SeqListPopBack(SL* ps);//尾部删除
void SeqListPushFront(SL* ps, Data x);//头部插入
void SeqListPopFront(SL* ps);//头部删除
void SeqListInsert(SL* ps,Data x,int pos);//在pos位置插入
void SeqListErase(SL* ps, int pos);//在pos位置删除

void SeqListPrint(SL* ps);//顺序表打印

int SeqListFind(SL* ps, Data x);//顺序表查找

void SeqListSort(SL ps);//顺序表排序


