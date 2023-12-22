#include"sort.h"
#include"Stack.h"

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

void QuickSortNonR(int* arr, int left, int right)//快速排序  非递归实现
{
	assert(arr);

	Stack st;
	StackInit(&st);

	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);
		if (begin < end)
		{
			int div = PartSort3(arr, begin, end);

			StackPush(&st, end);
			StackPush(&st, div + 1);
			StackPush(&st, div - 1);
			StackPush(&st, begin);
		}

	}
	StackDestort(&st);
}

void MergeArr(int* arr, int* tmp, int left, int right, int mid)//归并
{
	int begin1 = left;//左区间的起点
	int end1 = mid;//左区间的终点
	int begin2 = mid + 1;//右区间的起点
	int end2 = right;//右区间的终点
	int index = begin1;//tmp临时数组的起点

	//对两段区间合并
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[index++] = arr[begin1++];
		}
		else
		{
			tmp[index++] = arr[begin2++];
		}
	}

	//对剩余后半段放入tmp中
	while (begin1 <= end1)
	{
		tmp[index++] = arr[begin1++];
	}

	//对剩余后半段放入tmp中
	while (begin2 <= end2)
	{
		tmp[index++] = arr[begin2++];
	}

	//将数据从tmp拷贝回arr中
	for (int i = left; i <= right; i++)
	{
		arr[i] = tmp[i];
	}
}

void MergeSortPart(int* arr, int* tmp, int left, int right)
{
	assert(arr && tmp);

	if (left >= right)
	{
		return;
	}
		
	//分区间
	int mid = (left + right) / 2;

	MergeSortPart(arr, tmp, left, mid);
	MergeSortPart(arr, tmp, mid+1, right);

	//归并

	MergeArr(arr, tmp, left, right, mid);
}

void MergeSort(int* arr, int sz)//归并排序  时间复杂度O（n*logN）  空间复杂度O（n）
{
	assert(arr);

	int* tmp = (int*)malloc(sizeof(int) * sz);
	if (tmp == NULL)
	{
		printf("malloc false\n");
		exit(-1);
	}
	MergeSortPart(arr, tmp, 0, sz - 1);

}

void MergeSortNonR(int* arr, int sz)//归并排序非递归
{
	assert(arr);

	int* tmp = (int*)malloc(sizeof(int) * sz);//创建临时数组来存放归并的结果
	if (tmp == NULL)
	{
		printf("malloc false\n");
		exit(-1);
	}

	int left = 0;//总区间的起点
	int right = sz - 1;//总区间的终点

	int gap = 1;//每次归并区间中的元素个数

	while (gap < sz)
	{
		//归并区间 [i,i+gap-1]  [i+gap,i+2*gap-1]

		for (int i = left; i <= right; i = i + 2 * gap)//每次i自增调到下两个区间
		{
			int begin = i;//左区间的起点
			int end = i + 2 * gap - 1;//右区间的终点
			int mid = i + gap - 1;//中间
			if (end > right)//判断右区间是存在越界，如果是，则右区间给到末尾的位置
			{
				end = right;
			}
			MergeArr(arr, tmp, begin, end, mid);//归并两个区间
		}
		gap = gap * 2;
	}

}

void WriteData()//写数据到一个文件中
{
	int arr[100] = { 0 };
	//随机生成N个数
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		arr[i] = rand() % 100 + 1;
	}
	//for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	//{
	//	arr[i] = 100 - i;
	//}

	FILE* all = fopen("Out//allnum.txt", "w");//以写的方式打开文件
	if (all == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	//将arr数组中的数 写到 allnum文件中
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		fprintf(all, "%d\n", arr[i]);
	}

	fclose(all);//关闭文件
}

void MergeFile(char* one, char* two, char* MF)//将两个文件 合并 到一个文件中
{
	FILE* oneFile = fopen(one, "r");
	if (oneFile == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	FILE* twoFile = fopen(two, "r");
	if (twoFile == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	FILE* mf = fopen(MF, "w");
	if (mf == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	int num1 = 0;
	int num2 = 0;

	int ret1 = fscanf(oneFile, "%d\n", &num1);
	int ret2 = fscanf(twoFile, "%d\n", &num2);

	while (ret1 != -1 && ret2 != -1)
	{
		if (num1 < num2)
		{
			fprintf(mf, "%d\n", num1);
			ret1 = fscanf(oneFile, "%d\n", &num1);
		}
		else
		{
			fprintf(mf, "%d\n", num2);
			ret2 = fscanf(twoFile, "%d\n", &num2);
		}
	}

	while (ret1 != EOF)
	{
		fprintf(mf, "%d\n", num1);
		ret1 = fscanf(oneFile, "%d\n", &num1);

	}

	while (ret2 != EOF)
	{
		fprintf(mf, "%d\n", num2);
		ret2 = fscanf(twoFile, "%d\n", &num2);
	}

	//关闭文件
	fclose(oneFile);
	fclose(twoFile);
	fclose(mf);
}

void MergeOutSort()//外部排序
{
	WriteData();//写数据到一个文件中

	FILE* all = fopen("Out//allnum.txt", "r");
	if (all == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	//分文件
	int arr[10];//每个子文件的数据 数组
	int sz = sizeof(arr) / sizeof(int);//每个子文件的数据个数
	memset(arr, 0, sz * sizeof(int));
	int num = 0;
	int i = 0;
	int FileNum = 1;

	while (fscanf(all, "%d\n", &num) != EOF)
	{
		if (i < (sz - 1))//读9个数据到数组中
		{
			arr[i] = num;
			i++;
		}
		else
		{
			arr[sz - 1] = num;//把最后读的一个放入数组中
			QuickSort(arr, 0, sz - 1);

			char FileName[20];
			sprintf(FileName, "Out//sort%d.txt", FileNum++);

			FILE* sonFile = fopen(FileName, "w");
			if (sonFile == NULL)
			{
				printf("打开文件失败\n");
				exit(-1);
			}

			for (int i = 0; i < sz; i++)
			{
				fprintf(sonFile, "%d\n", arr[i]);
			}

			fclose(sonFile);

			i = 0;
		}
	}

	FileNum--;

	fclose(all);
	//归并文件

	char one[20];
	char two[20];

	char tmp1[20] = "tmp1.txt";
	char tmp2[20] = "tmp2.txt";

	char hebing[20];

	sprintf(one, "Out//sort1.txt");
	sprintf(two, "Out//sort2.txt");

	strcpy(hebing, tmp1);
	MergeFile(one, two, hebing);

	int swap1 = 1;
	int swap2 = 2;

	for (int i = 3; i <= FileNum; i++)
	{
		sprintf(one, "tmp%d.txt",swap1);
		sprintf(two, "Out//sort%d.txt",i);

		Swap(&swap1, &swap2);

		sprintf(tmp1, "tmp%d.txt", swap1);
		MergeFile(one, two, tmp1);

	}
}