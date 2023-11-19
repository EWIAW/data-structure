#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;
typedef struct ListNode
{
	DataType val;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

ListNode* ListInit();//创建头结点
void ListDestory(ListNode* head);//销毁
void ListClear(ListNode* head);//清理

void ListPrint(ListNode* head);//打印
ListNode* BuyNode(DataType val);//开辟新节点

void ListPushBack(ListNode* head, DataType val);//尾插
void ListPopBack(ListNode* head);//尾删
void ListPushFront(ListNode* head, DataType val);//头插
void ListPopFront(ListNode* head);//头删

ListNode* ListFind(ListNode* head, DataType val);//查找

void ListInsert(ListNode* pos, DataType val);//中间插入
void ListErase(ListNode* pos);//中间删除
