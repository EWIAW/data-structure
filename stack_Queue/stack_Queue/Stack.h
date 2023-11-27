#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int StackData;

typedef struct Stack 
{
	StackData* arr;
	int top;//ջ������һ��λ��
	int capacity;//����
}Stack;

void StackInit(Stack* ps);//ջ�ĳ�ʼ��
void StackDestort(Stack* ps);//ջ������

void StackPush(Stack* ps, StackData x);//��ջ
void StackPop(Stack* ps);//��ջ

StackData StackTop(Stack* ps);//��ȡջ������

int StackSize(Stack* ps);//��ȡջ����ЧԪ�ظ���

bool StackEmpty(Stack* ps);//�ж�ջ�Ƿ�Ϊ��
