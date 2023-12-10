#include"sort.h"

void Swap(int* num1, int* num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void InsertSort(int* arr, int sz)//直接插入排序  时间复杂度为O（n²） 
{
	assert(arr);

	for (int i = 0; i < sz - 1; i++)
	{
		int end = i;//有序区间中的最后一个数
		int tmp = arr[end + 1];//待排的数
		while (end >= 0)
		{
			if (tmp < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}

void ShellSort(int* arr, int sz)//希尔排序  时间复杂的为O（n^1.3)-O（n^2）之间 
{
	assert(arr);

	int gap = sz;
	while (gap > 1) 
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < sz - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];//待排的数
			while (end >= 0)
			{
				if (tmp < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
		//Print(arr, sz);
	}
}

void SelectSort(int* arr, int sz)//直接选择排序
{
	assert(arr);

	int begin = 0;
	int end = sz - 1;

	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;

		for (int i = begin; i <= end; i++)
		{
			if (arr[i] < arr[mini])
			{
				mini = i;
			}

			if (arr[i] > arr[maxi])
			{
				maxi = i;
			}
		}

		Swap(&arr[begin], &arr[mini]);

		if (begin == maxi)
		{
			maxi = mini;
		}

		Swap(&arr[end], &arr[maxi]);

		begin++;
		end--;
	}

}