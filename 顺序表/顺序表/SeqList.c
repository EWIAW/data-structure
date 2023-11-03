#include"SeqList.h"

void SeqListInit(SL* ps)//˳����ʼ��
{
	assert(ps);
	ps->arr = (Data*)malloc(sizeof(Data) * 4);
	if (ps->arr == NULL)
	{
		printf("����ʧ��\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}

void SeqListDestory(SL* ps)//˳�������
{
	free(ps->arr);
	ps->capacity = 0;
	ps->size = 0;
	ps->arr = NULL;
}

void SeqListCheckCapacity(SL* ps)//����������������������
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		ps->capacity *= 2;
		ps->arr = (Data*)realloc(ps->arr, ps->capacity * sizeof(Data));
		if (ps->arr == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
	}
}

void SeqListPushBack(SL* ps, Data x)//β������
{
	//SeqListCheckCapacity(ps);
	//ps->arr[ps->size] = x;
	//ps->size++;
	SeqListInsert(ps, x, ps->size + 1);
}

void SeqListPopBack(SL* ps)//β��ɾ��
{
	//assert(ps);
	//assert(ps->size);
	//ps->size--;
	SeqListErase(ps, ps->size);
}

void SeqListPushFront(SL* ps, Data x)//ͷ������
{
	//assert(ps);
	//SeqListCheckCapacity(ps);
	//int end = ps->size - 1;
	//while (end >= 0)
	//{
	//	ps->arr[end + 1] = ps->arr[end];
	//	end--;
	//}
	//ps->arr[0] = x;
	//ps->size++;
	SeqListInsert(ps, x, 1);
}

void SeqListPopFront(SL* ps)//ͷ��ɾ��
{
	//assert(ps);
	//assert(ps->size);
	//int head = 0;
	//while (head < (ps->size -1) )
	//{
	//	ps->arr[head] = ps->arr[head + 1];
	//	head++;
	//}
	//ps->size--;
	SeqListErase(ps, 1);
}

void SeqListInsert(SL* ps, Data x, int pos)//��posλ�ò���
{
	assert(ps);
	assert(pos <= (ps->size + 1));
	assert(pos > 0);
	SeqListCheckCapacity(ps);
	int mid = pos - 1;
	int end = ps->size - 1;
	while (end >= mid)
	{
		ps->arr[end + 1] = ps->arr[end];
		end--;
	}
	ps->arr[mid] = x;
	ps->size++;
}

void SeqListErase(SL* ps, int pos)//��posλ��ɾ��
{
	assert(ps);
	assert(pos > 0);
	assert(pos <= ps->size);
	int mid = pos - 1;
	int end = ps->size - 1;
	while (mid < end)
	{
		ps->arr[mid] = ps->arr[mid + 1];
		mid++;
	}
	ps->size--;
}

void SeqListPrint(SL* ps)//˳����ӡ
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

int SeqListFind(SL* ps, Data x)//˳������
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			return i + 1;
		}
	}
	return -1;
}

void SeqListSort(SL ps)//˳�������
{
	for (int i = 0; i < ps.size - 1; i++)
	{
		for (int j = 0; j < ps.size - 1 - i; j++)
		{
			int tmp;
			if (ps.arr[j] > ps.arr[j + 1])
			{
				tmp = ps.arr[j];
				ps.arr[j] = ps.arr[j + 1];
				ps.arr[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < ps.size; i++)
	{
		printf("%d ", ps.arr[i]);
	}
	printf("\n");
}