#include"Stack.h"

void StackInit(Stack* ps)//ջ�ĳ�ʼ��
{
	assert(ps);
	ps->arr = (StackData*)malloc(sizeof(StackData) * 4);
	ps->top = 0;
	ps->capacity = 4;
}

void StackDestort(Stack* ps)//ջ������
{
	assert(ps);
	free(ps->arr);
	ps->top = 0;
	ps->capacity = 0;
}

void StackPush(Stack* ps, StackData x)//��ջ
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		ps->capacity = ps->capacity * 2;
		StackData* tmp = (StackData*)realloc(ps->arr, sizeof(StackData) * ps->capacity);
		if (tmp == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
		ps->arr = tmp;
	}
	ps->arr[ps->top] = x;
	ps->top++;
}

void StackPop(Stack* ps)//��ջ
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

StackData StackTop(Stack* ps)//��ȡջ������
{
	assert(ps);
	assert(ps->top > 0);
	return ps->arr[ps->top - 1];
}

int StackSize(Stack* ps)//��ȡջ����ЧԪ�ظ���
{
	assert(ps);
	return ps->top;
}

bool StackEmpty(Stack* ps)//�ж�ջ�Ƿ�Ϊ��
{
	assert(ps);
	if (ps->top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}