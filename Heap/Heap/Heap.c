#include"Heap.h"

void HeapInit(Heap* php, HPData* arr, int n)//堆的初始化  n为数组元素个数   建堆的时间复炸度为O（n）
{
	assert(php && arr);

	php->arr = (HPData*)malloc(sizeof(HPData) * n);
	if (php->arr == NULL)
	{
		printf("开辟失败\n");
		exit(-1);
	}
	php->capacity = php->size = n;

	memcpy(php->arr, arr, sizeof(HPData) * n);

	for (int i = (n - 1 -1) / 2; i >= 0; i--)//从最后一个节点的父节点开始向上迭代，令每个子树都为 小堆  i为根节点下标 
	{
		AdjustDown(php->arr, i, n);//向下调整堆
	}

}

void HeapDestory(Heap* php)//堆的销毁
{
	assert(php);
	free(php->arr);
	php->capacity = php->size = 0;
}

void HeapPush(Heap* php, HPData val)//堆的插入  时间复杂度O（logN）
{
	assert(php);
	if (php->capacity == php->size)
	{
		php->capacity *= 2;
		HPData* tmp = (HPData*)realloc(php->arr, sizeof(HPData) * php->capacity);
		if (tmp == NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}
		php->arr = tmp;
	}

	php->arr[php->size++] = val;

	AdjustUp(php->arr, (php->size) - 1);
}

void HeapPop(Heap* php)//删除堆顶  时间复杂度为O（logN）
{
	assert(php);
	assert(php->size > 0);
	swap(&php->arr[0], &php->arr[php->size - 1]);
	php->size--;
	AdjustDown(php->arr, 0, php->size);	
}

HPData HeapTop(Heap* php)//取堆顶数据
{
	assert(php);
	assert(php->size > 0);
	return php->arr[0];
}
