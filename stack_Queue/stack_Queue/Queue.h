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

void QueueInit(Queue* pq);//队列的初始化
void QueueDestory(Queue* pq);//队列的销毁

void QueuePush(Queue* pq, QueueData val);//入队列
void QueuePop(Queue* pq);//出队列

QueueData QueueFront(Queue* pq);//获取队列头元素
QueueData QueueBack(Queue* pq);//获取队列尾元素

int QueueSize(Queue* pq);//获取队列的有效元素

bool QueueEmpty(Queue* pq);//判断队列为不为空