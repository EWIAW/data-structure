#include"SList.h"

SLNode* BuySListNode(Data x)//�����ڵ�
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		printf("����ڵ�ʧ��\n");
		exit(-1);
	}
	newnode->x = x;
	newnode->next = NULL;
	return newnode;
}

void SListPushBack(SLNode** phead, Data x)//β������
{
	SLNode* newnode = BuySListNode(x);
	SLNode* tail = *phead;
	if (tail == NULL)
	{
		*phead = newnode;
	}
	else
	{
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPopBack(SLNode** phead)//β��ɾ��
{
	SLNode* tail = *phead;
	if (tail == NULL)//������û��Ԫ��ʱ��ֱ�ӷ���
	{
		return;
	}
	else if (tail->next == NULL)//��������ֻ��һ��Ԫ��ʱ��ɾ��
	{
		free(tail);
		tail = NULL;
		*phead = NULL;
	}
	else//���������ж��Ԫ��ʱ��ɾ��
	{
		SLNode* prev = *phead;
		tail = tail->next;
		while (tail->next != NULL)
		{
			tail = tail->next;
			prev = prev->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

void SListPushFront(SLNode** phead, Data x)//ͷ������
{
	SLNode* newnode = BuySListNode(x);
	SLNode* cur = *phead;
		newnode->next = cur;
		*phead = newnode;
}
	
void SListPopFront(SLNode** phead)//ͷ��ɾ��
{
	SLNode* cur = *phead;
	if (cur == NULL)
	{
		return;
	}
	else
	{
		SLNode* curnext = cur->next;
		*phead = curnext;
		free(cur);
		cur = NULL;
	}
}

void SListInsertAfter(SLNode** phead, Data x, int pos)//��posλ��֮�����
{
	SLNode* newnode = BuySListNode(x);
	SLNode* mid = *phead;
	if (pos == 0 || mid==NULL)
	{
		SListPushFront(phead, x);
	}
	else
	{
		while ((pos - 1) > 0)
		{
			mid = mid->next;
			pos--;
		}
		newnode->next = mid->next;
		mid->next = newnode;
	}
}

void SListEraseAfter(SLNode** phead, int pos)//��posλ��֮��ɾ��
{
	SLNode* mid = *phead;
	if (pos == 0 || mid==NULL)
	{
		SListPopFront(phead);
	}
	else
	{
		while ((pos - 1) > 0)
		{
			mid = mid->next;
			pos--;
		}
		SLNode* midafter = mid->next;
		mid->next = midafter->next;
		free(midafter);
		midafter = NULL;
	}
}

void SListPrint(SLNode** phead)//���
{
	SLNode* cur = *phead;
	while (cur != NULL)
	{
		printf("%d->", cur->x);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLNode* SListFind(SLNode** phead, Data x)//����
{
	SLNode* tail = *phead;
	while (tail != NULL)
	{
		if (tail->x == x)
		{
			return tail;
		}
		tail = tail->next;
	}
	return NULL;
}

void SListDestroy(SLNode** phead)//����������
{
	SLNode* tail = *phead;
	SLNode* head = *phead;
	while (tail != NULL)
	{
		tail = tail->next;
		free(head);
		head = tail;
	}
	*phead = NULL;
}