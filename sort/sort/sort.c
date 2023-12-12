#include"sort.h"

void Swap(int* num1, int* num2)//交换数组中的两个数
{
	assert(num1 && num2);

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

void SelectSort(int* arr, int sz)//直接选择排序  时间复杂的为O（n²）
{
	assert(arr);

	int begin = 0;//头
	int end = sz - 1;//尾

	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;

		for (int i = begin; i <= end; i++)//遍历数组 选出 最大 和 最小 的两个数
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

		Swap(&arr[begin], &arr[mini]);//把最小的数 放到 头

		if (begin == maxi)//如果最大的数 和 头重叠
		{
			maxi = mini;
		}

		Swap(&arr[end], &arr[maxi]);//把最大的数 放到 尾

		begin++;
		end--;
	}
}

void AdjustDown(int* arr,int sz,int root)//向下调整算法  排升序，建大堆  建堆时间复杂度为 O（n）
{
	assert(arr);

	int parent = root;
	int child = parent * 2 + 1;

	while (child < sz)
	{
		if ((child + 1) < sz && arr[child + 1] > arr[child])
		{
			child++;
		}

		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* arr, int sz)//堆排序  排升序，建大堆  时间复杂度为O（n*logN）
{
	assert(arr);

	for (int i = (sz - 1 - 1) / 2; i >= 0; i--)//建堆  时间复杂度O（n）
	{
		AdjustDown(arr, sz, i);
	}

	for (int i = sz - 1; i > 0; i--)
	{
		Swap(&arr[0], &arr[i]);
		AdjustDown(arr, i, 0);
	}
}

void BubbleSort(int* arr, int sz)//冒泡排序 时间复杂度为O（n²）
{
	assert(arr);

	for (int j = sz - 1; j > 0; j--)
	{
		for (int i = 0; i < j; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				Swap(&arr[i], &arr[i + 1]);
			}
		}
	}
}

int PartSort(int* arr, int begin, int end)//一趟快速排序
{
	assert(arr);

	int key = begin;

	while (begin < end)
	{
		while (begin < end && arr[end] > arr[key])
		{
			end--;
		}

		while (begin < end && arr[begin] < arr[key])
		{
			begin++;
		}

		Swap(&arr[begin], &arr[end]); 
		//begin++;
		//end--;
	}

	Swap(&arr[key], &arr[end]);
	return end;
}

void QuickSort(int* arr, int left, int right)//快速排序
{
	assert(arr);

	if (left >= right)
	{
		return;
	}

	int ret = PartSort(arr, left, right);

	QuickSort(arr, left, ret - 1);
	QuickSort(arr, ret + 1, right);

}