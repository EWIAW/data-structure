#pragma once

#include<stdio.h>
#include<assert.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

//插入排序
void InsertSort(int* arr, int sz);//直接插入排序  时间复杂度为O（n²）
void ShellSort(int* arr, int sz);//希尔排序  时间复杂度为O（n^1.3-n^2）

//选择排序
void SelectSort(int* arr, int sz);//直接选择排序  时间复杂度为O（n²）

void AdjustDown(int* arr, int sz, int root);//向下调整算法  排升序，建大堆  建堆时间复杂度为O（n）
void HeapSort(int* arr, int sz);//堆排序  时间复杂度为O（n*logN）

//选择排序
void BubbleSort(int* arr, int sz);//冒泡排序  时间复杂度为O（n²）


int PartSort1(int* arr, int begin, int end);//一趟快速排序  左右指针法  时间复杂度为O（n）
int PartSort2(int* arr, int begin, int end);//一趟快速排序  挖坑法  时间复杂度为O（n）
int PartSort3(int* arr, int begin, int end);//一趟快速排序  前后指针法  时间复杂度为O（n）

void QuickSort(int* arr, int left, int right);//快速排序  时间复杂度为 O（n*logN）
void QuickSortNonR(int* arr, int left, int right);//快速排序  非递归实现

void MergeSort(int* arr, int sz);//归并排序
void MergeSortNonR(int* arr, int sz);//归并排序非递归
void MergeOutSort();//外部排序
