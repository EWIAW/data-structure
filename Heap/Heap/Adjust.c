#include"Heap.h"

void swap(HPData* num1, HPData* num2)//交换数组中的两个数
{
	assert(num1 && num2);
	HPData tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void AdjustDown(HPData* arr, int root, int n)//向下调整算法  函数 root为从那个根开始调  n为堆数组元素个数  时间复杂度为O（logN）
{
	assert(arr);

	int parent = root;
	int child = 2 * parent + 1;

	while (child < n)
	{
		if ((child + 1) < n && arr[child + 1] < arr[child])//如果右孩子小于左孩子，则把右孩子给给child
		{
			child++;
		}

		if (arr[child] < arr[parent])//如果孩子小于父节点，则交换
		{
			swap(&arr[parent], &arr[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}

}

void AdjustUp(HPData* arr, int child)//向上调整算法  函数  时间复杂度为 O（logN）
{
	int parent = (child - 1) / 2;	

	while (child > 0)
	{
		if (arr[child] < arr[parent])
		{
			swap(&arr[parent], &arr[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(HPData* a, int sz)//堆排序  时间复杂度为O（n*logN）
{
	assert(a);
	for (int i = (sz - 1 - 1); i >= 0; i--)//建堆
	{
		AdjustDown(a, i, sz);
	}

	while (sz)
	{
		swap(&a[0], &a[sz - 1]);
		sz--;
		AdjustDown(a, 0, sz);
	}

}