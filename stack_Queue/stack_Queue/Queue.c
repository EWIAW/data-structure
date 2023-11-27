#include"Queue.h"

void QueueInit(Queue* pq)//队列的初始化
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

void QueueDestory(Queue* pq)//队列的销毁
{
	assert(pq);
	QueueListNode* cur = pq->head;
	while (cur != NULL)
	{
		QueueListNode* curNext = cur->next;
		free(cur);
		cur = curNext;
	}
}

void QueuePush(Queue* pq, QueueData val)//入队列
{
	assert(pq);
	QueueListNode* newnode = (QueueListNode*)malloc(sizeof(QueueListNode));
	if (newnode == NULL)
	{
		printf("开辟失败\n");
		exit(-1);
	}
	newnode->val = val;
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)//出队列
{
	assert(pq);
	assert(pq->head != NULL);
	QueueListNode* headNext = pq->head->next;
	free(pq->head);
	pq->head = headNext;
}

QueueData QueueFront(Queue* pq)//获取队列头元素
{
	assert(pq);
	assert(pq->head != NULL);
	return pq->head->val;
}

QueueData QueueBack(Queue* pq)//获取队列尾元素
{
	assert(pq);
	assert(pq->tail != NULL);
	return pq->tail->val;
}

int QueueSize(Queue* pq)//获取队列的有效元素
{
	assert(pq);
	QueueListNode* cur = pq->head;
	int size = 0;
	while (cur != NULL)
	{
		size++;
		cur = cur->next;
	}
	return size;
}

bool QueueEmpty(Queue* pq)//判断队列为不为空
{
	if (pq->head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
