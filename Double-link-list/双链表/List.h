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

ListNode* ListInit();//����ͷ���
void ListDestory(ListNode* head);//����
void ListClear(ListNode* head);//����

void ListPrint(ListNode* head);//��ӡ
ListNode* BuyNode(DataType val);//�����½ڵ�

void ListPushBack(ListNode* head, DataType val);//β��
void ListPopBack(ListNode* head);//βɾ
void ListPushFront(ListNode* head, DataType val);//ͷ��
void ListPopFront(ListNode* head);//ͷɾ

ListNode* ListFind(ListNode* head, DataType val);//����

void ListInsert(ListNode* pos, DataType val);//�м����
void ListErase(ListNode* pos);//�м�ɾ��
