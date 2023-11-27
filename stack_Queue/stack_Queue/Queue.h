#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QueueData;

typedef struct QueueListNode
{
	QueueData val;
	struct QueueListNode* next;
}QueueListNode;

typedef struct Queue
{
	QueueListNode* head;
	QueueListNode* tail;
}Queue;

void QueueInit(Queue* pq);//���еĳ�ʼ��
void QueueDestory(Queue* pq);//���е�����

void QueuePush(Queue* pq, QueueData val);//�����
void QueuePop(Queue* pq);//������

QueueData QueueFront(Queue* pq);//��ȡ����ͷԪ��
QueueData QueueBack(Queue* pq);//��ȡ����βԪ��

int QueueSize(Queue* pq);//��ȡ���е���ЧԪ��

bool QueueEmpty(Queue* pq);//�ж϶���Ϊ��Ϊ��