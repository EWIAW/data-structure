#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int StackData;

typedef struct Stack 
{
	StackData* arr;
	int top;//栈顶的下一个位置
	int capacity;//容量
}Stack;

void StackInit(Stack* ps);//栈的初始化
void StackDestort(Stack* ps);//栈的销毁

void StackPush(Stack* ps, StackData x);//入栈
void StackPop(Stack* ps);//出栈

StackData StackTop(Stack* ps);//获取栈顶数据

int StackSize(Stack* ps);//获取栈中有效元素个数

bool StackEmpty(Stack* ps);//判断栈是否为空
