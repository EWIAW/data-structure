#include"Heap.h"

void test1()
{
	HPData a[] = {27,15,19,18,28,34,65,49,25,37};
	Heap S;
	HeapInit(&S, a, sizeof(a) / sizeof(HPData));//初始化堆

	HeapPush(&S, 1);//堆的插入
	HeapPop(&S);//删除堆顶数据
	HeapTop(&S);//取堆顶数据

	HeapSort(a, sizeof(a) / sizeof(int));//堆数组a进行排序

	for (int i = 0; i < S.size; i++)//排完序后进行输出
	{
		printf("%d ", S.arr[i]);
	}

	HeapDestory(&S);//销毁堆

}

int main()
{
	test1();

	return 0;
}