#include"Heap.h"

void test1()
{
	HPData a[] = {27,15,19,18,28,34,65,49,25,37};
	Heap S;
	HeapInit(&S, a, sizeof(a) / sizeof(HPData));

	HeapPush(&S, 1);
	HeapPop(&S);

	HeapDestory(&S);

}

int main()
{
	test1();

	return 0;
}