#include"SList.h"

SLNode* BuySListNode(Data x)//创建节点
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		printf("申请节点失败\n");
		exit(-1);
	}
	newnode->x = x;
	newnode->next = NULL;
	return newnode;
}

void SListPushBack(SLNode** phead, Data x)//尾部插入
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

void SListPopBack(SLNode** phead)//尾部删除
{
	SLNode* tail = *phead;
	if (tail == NULL)//当链表没有元素时，直接返回
	{
		return;
	}
	else if (tail->next == NULL)//当链表中只有一个元素时，删除
	{
		free(tail);
		tail = NULL;
		*phead = NULL;
	}
	else//当链表中有多个元素时，删除
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

void SListPushFront(SLNode** phead, Data x)//头部插入
{
	SLNode* newnode = BuySListNode(x);
	SLNode* cur = *phead;
		newnode->next = cur;
		*phead = newnode;
}
	
void SListPopFront(SLNode** phead)//头部删除
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

void SListInsertAfter(SLNode** phead, Data x, int pos)//在pos位置之后插入
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

void SListEraseAfter(SLNode** phead, int pos)//在pos位置之后删除
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

void SListPrint(SLNode** phead)//输出
{
	SLNode* cur = *phead;
	while (cur != NULL)
	{
		printf("%d->", cur->x);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLNode* SListFind(SLNode** phead, Data x)//查找
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

void SListDestroy(SLNode** phead)//单链表销毁
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