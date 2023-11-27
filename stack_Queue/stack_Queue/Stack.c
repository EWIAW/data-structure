#include"Stack.h"

void StackInit(Stack* ps)//栈的初始化
{
	assert(ps);
	ps->arr = (StackData*)malloc(sizeof(StackData) * 4);
	ps->top = 0;
	ps->capacity = 4;
}

void StackDestort(Stack* ps)//栈的销毁
{
	assert(ps);
	free(ps->arr);
	ps->top = 0;
	ps->capacity = 0;
}

void StackPush(Stack* ps, StackData x)//入栈
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		ps->capacity = ps->capacity * 2;
		StackData* tmp = (StackData*)realloc(ps->arr, sizeof(ps->capacity));
		if (tmp == NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}
		ps->arr = tmp;
	}
	ps->arr[ps->top] = x;
	ps->top++;
}

void StackPop(Stack* ps)//出栈
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

StackData StackTop(Stack* ps)//获取栈顶数据
{
	assert(ps);
	assert(ps->top > 0);
	return ps->arr[ps->top - 1];
}

int StackSize(Stack* ps)//获取栈中有效元素个数
{
	assert(ps);
	return ps->top;
}

bool StackEmpty(Stack* ps)//判断栈是否为空
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