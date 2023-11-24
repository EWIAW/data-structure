#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int Data;

typedef struct SListNode
{
	Data x;
	struct SListNode* next;
}SLNode;


SLNode* BuySListNode(Data x);//�����ڵ�

void SListPushBack(SLNode** phead, Data x);//β������
void SListPopBack(SLNode** phead);//β��ɾ��

void SListPushFront(SLNode** phead, Data x);//ͷ������
void SListPopFront(SLNode** phead);//ͷ��ɾ��

void SListInsertAfter(SLNode** phead, Data x, int pos);//��posλ��֮�����
void SListEraseAfter(SLNode** phead, int pos);//��posλ��֮��ɾ��

void SListPrint(SLNode** phead);//���

SLNode* SListFind(SLNode** phead, Data x);//����

void SListDestroy(SLNode** phead);//����������