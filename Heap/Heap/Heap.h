#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int HPData;

typedef struct Heap
{
	HPData* arr;
	int size;
	int capacity;
}Heap;

void HeapInit(Heap* php, HPData* arr, int n);//�ѵĳ�ʼ��    �������ѽṹ�壬������ʼ�����飬������Ԫ�صĸ���   ���ѵ�ʱ�临ը��ΪO��n��
void HeapDestory(Heap* php);//�ѵ�����

void HeapPush(Heap* php, HPData val);//�ѵĲ���
void HeapPop(Heap* php);//ɾ���Ѷ�
HPData HeapTop(Heap* php);//ȡ�Ѷ�����





void AdjustDown(HPData* arr, int root, int n);//���µ�������   nΪ������Ԫ�ظ���
void AdjustUp(HPData* arr, int child);//���ϵ����㷨  ����

void swap(HPData* num1, HPData* num2);//���������е�������
void HeapSort(HPData* a, int sz);//������


