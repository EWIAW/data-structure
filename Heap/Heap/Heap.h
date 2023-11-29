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

void HeapInit(Heap* php, HPData* arr, int n);//堆的初始化    参数：堆结构体，给定初始化数组，数组中元素的个数   建堆的时间复炸度为O（n）
void HeapDestory(Heap* php);//堆的销毁

void HeapPush(Heap* php, HPData val);//堆的插入
void HeapPop(Heap* php);//删除堆顶
HPData HeapTop(Heap* php);//取堆顶数据





void AdjustDown(HPData* arr, int root, int n);//向下调整函数   n为堆数组元素个数
void AdjustUp(HPData* arr, int child);//向上调整算法  函数

void swap(HPData* num1, HPData* num2);//交换数组中的两个数
void HeapSort(HPData* a, int sz);//堆排序


