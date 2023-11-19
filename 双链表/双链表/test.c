#include"List.h"

void Test1()
{
	ListNode* head = ListInit();
	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPushBack(head, 4);

	ListPopBack(head);
	ListPopBack(head);

	ListPushFront(head, 1);
	ListPushFront(head, 2);
	ListPushFront(head, 3);
	ListPushFront(head, 4);

	ListPopFront(head);
	ListPopFront(head);

	ListPrint(head);
}

void Test2()
{
	ListNode* head = ListInit();
	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	ListPushBack(head, 5);

	ListNode* pos = ListFind(head,1);
	if (pos != NULL)
	{
		ListInsert(pos, 10);
	}

	ListErase(pos);

	//ListClear(head);
	ListPrint(head);

	ListDestory(&head);

}

int main()
{
	Test1();
	//Test2();
	return 0;
}