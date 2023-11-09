#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int Data;

typedef struct SListNode
{
	Data x;
	struct SListNode* next;
}SLNode;


SLNode* BuySListNode(Data x);//创建节点

void SListPushBack(SLNode** phead, Data x);//尾部插入
void SListPopBack(SLNode** phead);//尾部删除

void SListPushFront(SLNode** phead, Data x);//头部插入
void SListPopFront(SLNode** phead);//头部删除

void SListInsertAfter(SLNode** phead, Data x, int pos);//在pos位置之后插入
void SListEraseAfter(SLNode** phead, int pos);//在pos位置之后删除

void SListPrint(SLNode** phead);//输出

SLNode* SListFind(SLNode** phead, Data x);//查找

void SListDestroy(SLNode** phead);//单链表销毁