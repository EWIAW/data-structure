#include"Heap.h"

void HeapInit(Heap* php, HPData* arr, int n)//�ѵĳ�ʼ��  nΪ����Ԫ�ظ���   ���ѵ�ʱ�临ը��ΪO��n��
{
	assert(php && arr);

	php->arr = (HPData*)malloc(sizeof(HPData) * n);
	if (php->arr == NULL)
	{
		printf("����ʧ��\n");
		exit(-1);
	}
	php->capacity = php->size = n;

	memcpy(php->arr, arr, sizeof(HPData) * n);

	for (int i = (n - 1 -1) / 2; i >= 0; i--)//�����һ���ڵ�ĸ��ڵ㿪ʼ���ϵ�������ÿ��������Ϊ С��  iΪ���ڵ��±� 
	{
		AdjustDown(php->arr, i, n);//���µ�����
	}

}

void HeapDestory(Heap* php)//�ѵ�����
{
	assert(php);
	free(php->arr);
	php->capacity = php->size = 0;
}

void HeapPush(Heap* php, HPData val)//�ѵĲ���  ʱ�临�Ӷ�O��logN��
{
	assert(php);
	if (php->capacity == php->size)
	{
		php->capacity *= 2;
		HPData* tmp = (HPData*)realloc(php->arr, sizeof(HPData) * php->capacity);
		if (tmp == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
		php->arr = tmp;
	}

	php->arr[php->size++] = val;

	AdjustUp(php->arr, (php->size) - 1);
}

void HeapPop(Heap* php)//ɾ���Ѷ�  ʱ�临�Ӷ�ΪO��logN��
{
	assert(php);
	assert(php->size > 0);
	swap(&php->arr[0], &php->arr[php->size - 1]);
	php->size--;
	AdjustDown(php->arr, 0, php->size);	
}

HPData HeapTop(Heap* php)//ȡ�Ѷ�����
{
	assert(php);
	assert(php->size > 0);
	return php->arr[0];
}
