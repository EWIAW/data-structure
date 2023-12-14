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

int GetMidIndex(int* arr, int begin, int end)//用于快速排序  的  三数取中（即在begin、end和 (begin+end)/2之间取一个处在中间的值，这样保证在一趟排序中，key值不会是最大，也不会是最小
{
	assert(arr);

	int mid = (begin + end) / 2;
	if (arr[begin] > arr[mid])
	{
		if (arr[begin] > arr[end])
		{
			return arr[mid] > arr[end] ? mid : end;
		}
	}
	else if (arr[mid] > arr[end])
	{
		if (arr[mid] > arr[begin])
		{
			return arr[end] > arr[begin] ? end : begin;
		}
	}
	else
	{
		return arr[begin] > arr[mid] ? begin : mid;
	}
	//返回的是 中间的数 的下标
}

int PartSort1(int* arr, int begin, int end)//一趟快速排序  //左右指针法//  时间复杂度为O（n）
{
	assert(arr);

	int midIndex = GetMidIndex(arr, begin, end);//三数取中
	Swap(&arr[begin], &arr[midIndex]);//将处在 中间的 数换到begin的位置
	int key = begin;//需要比较的值

	//一趟排序后，使得 arr[key] 处在正确的位置，它的左边都比它小，它的右边都比它大
	while (begin < end)
	{
		while (begin < end && arr[end] >= arr[key])//end从右边开始找小
		{
			end--;
		}

		while (begin < end && arr[begin] <= arr[key])//begin从左边开始找大
		{
			begin++;
		}

		Swap(&arr[begin], &arr[end]); //交换end小值 和 begin大值
		//begin++;
		//end--;
	}

	Swap(&arr[key], &arr[end]);
	return end;//返回key所在的位置
}

int PartSort2(int* arr, int begin, int end)//一趟快速排序  //挖坑法//  时间复杂度为O（n）
{
	assert(arr);

	int midIndex = GetMidIndex(arr, begin, end);//三数取中
	Swap(&arr[midIndex], &arr[end]);//将处在 中间的 数换到end的位置

	int key = arr[end];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
		{
			begin++;
		}

		//Swap(&arr[begin], &arr[end]);
		arr[end] = arr[begin];

		while (begin < end && arr[end] >= key)
		{
			end--;
		}

		//Swap(&arr[end], &arr[begin]);
		arr[begin] = arr[end];

	}

	arr[begin] = key;
	return begin;
}

int PartSort3(int* arr, int begin, int end)//一趟快速排序  前后指针法  时间复杂度为O（n）
{
	//无优化写法
	//assert(arr);

	//int cur = begin;
	//int prev = begin - 1;
	//int key = arr[end];

	//while (cur < end)
	//{
	//	if (arr[cur] <= key)
	//	{
	//		prev++;
	//		Swap(&arr[cur], &arr[prev]);
	//	}
	//	cur++;
	//}
	//prev++;
	//Swap(&arr[prev], &arr[end]);
	//return prev;


	//优化写法
	assert(arr);

	int midIndex = GetMidIndex(arr, begin, end);//三数取中
	Swap(&arr[midIndex], &arr[end]);//让三数取中的数  放到末尾

	int key = arr[end];
	int cur = begin;
	int prev = begin - 1;
	while (cur < end)
	{
		if (arr[cur] <= key && ++prev != cur)
		{
			Swap(&arr[cur], &arr[prev]);
		}
		cur++;
	}

	Swap(&arr[end], &arr[++prev]);

	return prev;
}

void QuickSort(int* arr, int left, int right)//快速排序  时间复杂度为O（n*logN）
{
	assert(arr);

	if (left >= right)
	{
		return;
	}

	if ((right - left + 1) > 10)
	{
		int ret = PartSort1(arr, left, right);//先对数组排一趟，使得key值处在正确的位置
		//int ret = PartSort2(arr, left, right);//先对数组排一趟，使得key值处在正确的位置
		//int ret = PartSort3(arr, left, right);//先对数组排一趟，使得key值处在正确的位置

		QuickSort(arr, left, ret - 1);//后对 key 值前面的数组排序
		QuickSort(arr, ret + 1, right);//后对 key 值后面的数组排序
	}
	else
	{
		InsertSort(arr + left, right - left + 1);
	}

}