#include"SList.h"

void SListTest1()
{
	SLNode* head = NULL;
	//SListPushBack(&head, 1);
	//SListPushBack(&head, 2);
	//SListPushBack(&head, 3);
	//SListPushBack(&head, 4);

	SListPushFront(&head, 10);

	//SListInsertAfter(&head, 20, 1);

	//SListEraseAfter(&head, 0);

	//SLNode* find = SListFind(&head, 50);
	//if (find != NULL)
	//{
	//	printf("%d\n", find->x);
	//}
	//else
	//{
	//	printf("√ª’“µΩ\n");
	//}

	//SListDestroy(&head);

	SListPrint(&head);
}

int main()
{
	SListTest1();
	return 0;
}