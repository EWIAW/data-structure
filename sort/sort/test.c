#include"sort.h"

void Print(int* arr, int sz)//打印数组
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void InsertSortTest()//测试  直接插入排序
{
	int arr[] = { 5,78,1,41,6,5,6 };
	Print(arr, sizeof(arr) / sizeof(int));
	InsertSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

void ShellSortTest()//测试  希尔排序
{
	int arr[] = { 5,78,1,41,6,5,6 };
	Print(arr, sizeof(arr) / sizeof(int));
	ShellSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

void SelectSortTest()//测试  直接选择排序
{
	//int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	int arr[] = { 5,78,1,41,6,5,6 };

	Print(arr, sizeof(arr) / sizeof(int));
	SelectSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

void TestOP()//测试 所有排序 速度
{
	int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	
	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
	}

	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);


	free(a1);
	free(a2);
}

int main()
{
	srand((unsigned int)time(NULL));

	//InsertSortTest();
	//ShellSortTest();
	SelectSortTest();

	//TestOP();

	return 0;
}