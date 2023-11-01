#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int Data;

typedef struct SeqList
{
	Data* arr;//˳���ָ��
	int size;//����Ԫ�ظ���
	int capacity;//˳�������
}SL;

void SeqListInit(SL* ps);//˳����ʼ��
void SeqListDestory(SL* ps);//˳�������

void SeqListPushBack(SL* ps, Data x);//β������
void SeqListPopBack(SL* ps);//β��ɾ��
void SeqListPushFront(SL* ps, Data x);//ͷ������
void SeqListPopFront(SL* ps);//ͷ��ɾ��
void SeqListInsert(SL* ps,Data x,int pos);//��posλ�ò���
void SeqListErase(SL* ps, int pos);//��posλ��ɾ��

void SeqListPrint(SL* ps);//˳����ӡ

int SeqListFind(SL* ps, Data x);//˳������

void SeqListSort(SL ps);//˳�������


