#include"Queue.h"

void QueueInit(Queue* pq)//���еĳ�ʼ��
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

void QueueDestory(Queue* pq)//���е�����
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

void QueuePush(Queue* pq, QueueData val)//�����
{
	assert(pq);
	QueueListNode* newnode = (QueueListNode*)malloc(sizeof(QueueListNode));
	if (newnode == NULL)
	{
		printf("����ʧ��\n");
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

void QueuePop(Queue* pq)//������
{
	assert(pq);
	assert(pq->head != NULL);
	QueueListNode* headNext = pq->head->next;
	free(pq->head);
	pq->head = headNext;
}

QueueData QueueFront(Queue* pq)//��ȡ����ͷԪ��
{
	assert(pq);
	assert(pq->head != NULL);
	return pq->head->val;
}

QueueData QueueBack(Queue* pq)//��ȡ����βԪ��
{
	assert(pq);
	assert(pq->tail != NULL);
	return pq->tail->val;
}

int QueueSize(Queue* pq)//��ȡ���е���ЧԪ��
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

bool QueueEmpty(Queue* pq)//�ж϶���Ϊ��Ϊ��
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
