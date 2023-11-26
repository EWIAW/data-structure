#include"SeqList.h"

void SeqListTest1()
{
	SL s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);

	SeqListInsert(&s, 10, 3);
	SeqListInsert(&s, 20, 7);


	//int ret=SeqListFind(&s, 20);
	//if (ret != -1)
	//{
	//	printf("找到了，在第%d个\n", ret);
	//}
	//else
	//{
	//	printf("没找到\n");
	//}
	//SeqListPopBack(&s);
	//SeqListPopBack(&s);

	//SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 2);

	SeqListPopFront(&s);

	//for (int i = 1; i <= 1000; i++)
	//{
	//	SeqListPushBack(&s, i);
	//}
	//SeqListSort(s);

	SeqListPrint(&s);
}

int main()
{
	SeqListTest1();
	return 0;
}