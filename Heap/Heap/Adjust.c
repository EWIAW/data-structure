#include"Heap.h"

void swap(HPData* num1, HPData* num2)//���������е�������
{
	assert(num1 && num2);
	HPData tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void AdjustDown(HPData* arr, int root, int n)//���µ����㷨  ���� rootΪ���Ǹ�����ʼ��  nΪ������Ԫ�ظ���  ʱ�临�Ӷ�ΪO��logN��  �����
{
	assert(arr);

	int parent = root;
	int child = 2 * parent + 1;

	while (child < n)
	{
		if ((child + 1) < n && arr[child + 1] > arr[child])//����Һ��Ӵ������ӣ�����Һ��Ӹ���child
		{
			child++;
		}

		if (arr[child] > arr[parent])//������Ӵ��ڸ��ڵ㣬�򽻻�
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

void AdjustUp(HPData* arr, int child)//���ϵ����㷨  ����  ʱ�临�Ӷ�Ϊ O��logN��  ������ϵ���
{
	int parent = (child - 1) / 2;	

	while (child > 0)
	{
		if (arr[child] > arr[parent])
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

void HeapSort(HPData* a, int sz)//������  ʱ�临�Ӷ�ΪO��n*logN��
{
	assert(a);
	for (int i = (sz - 1 - 1); i >= 0; i--)//����
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