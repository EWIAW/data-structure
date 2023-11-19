#include"List.h"

ListNode* ListInit()//创建头结点
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	if (head == NULL)
	{
		printf("malloc false\n");
		exit(-1);
	}
	head->next = head;
	head->prev = head;
	return head;
}

void ListDestory(ListNode** phead)//销毁
{
	assert(phead);
	ListClear(*phead);
	*phead = NULL;
}

void ListClear(ListNode* head)//清理
{
	assert(head);
	ListNode* cur = head->next;
	ListNode* curNext;
	while (cur != head)
	{
		curNext = cur->next;
		free(cur);
		cur = curNext;
	}
	head->prev = head;
	head->next = head;
}

ListNode* BuyNode(DataType val)//开辟新节点
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		printf("malloc false\n");
		exit(-1);
	}
	newnode->val = val;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

void ListPrint(ListNode* head)//打印
{
	assert(head);
	ListNode* cur = head->next;
	while (cur != head)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(ListNode* head, DataType val)//尾插
{
	//assert(head);
	//ListNode* newnode = BuyNode(val);
	//ListNode* tail = head->prev;
	//tail->next = newnode;
	//newnode->prev = tail;

	//newnode->next = head;
	//head->prev = newnode;
	ListInsert(head, val);
}

void ListPopBack(ListNode* head)//尾删
{
	//assert(head);
	//assert(head->next != head);
	//ListNode* tail = head->prev;
	//ListNode* tailPrev = tail->prev;

	//tailPrev->next = head;
	//head->prev = tailPrev;
	//free(tail);
	//tail = NULL;
	ListErase(head->prev);
}

void ListPushFront(ListNode* head, DataType val)//头插
{
	//assert(head);
	//ListNode* newnode = BuyNode(val);
	//ListNode* headtail = head->next;
	//newnode->next = headtail;
	//newnode->prev = head;

	//head->next = newnode;
	//headtail->prev = newnode;
	ListInsert(head->next, val);
}

void ListPopFront(ListNode* head)//头删
{
	//assert(head);
	//assert(head->next != head);
	//ListNode* mid = head->next;
	//ListNode* midtail = mid->next;
	//head->next = midtail;
	//midtail->prev = head;

	//free(mid);
	//mid = NULL;
	ListErase(head->next);
}

ListNode* ListFind(ListNode* head, DataType val)//查找
{
	assert(head);
	ListNode* cur = head->next;
	while (cur != head)
	{
		if (cur->val == val)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, DataType val)//中间插入
{
	assert(pos);
	ListNode* newnode = BuyNode(val);
	ListNode* posPrev = pos->prev;
	
	newnode->next = pos;
	newnode->prev = posPrev;

	pos->prev = newnode;
	posPrev->next = newnode;
}

void ListErase(ListNode* pos)//中间删除
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
}