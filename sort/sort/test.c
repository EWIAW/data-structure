#include"sort.h"

void Print(int* arr, int sz)//´òÓ¡Êý×é
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void InsertSortTest()//²âÊÔ  Ö±½Ó²åÈëÅÅÐò
{
	int arr[] = { 5,78,1,41,6,5,6 };
	Print(arr, sizeof(arr) / sizeof(int));
	InsertSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

void ShellSortTest()//²âÊÔ  Ï£¶ûÅÅÐò
{
	int arr[] = { 5,78,1,41,6,5,6 };
	Print(arr, sizeof(arr) / sizeof(int));
	ShellSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

void SelectSortTest()//²âÊÔ  Ö±½ÓÑ¡ÔñÅÅÐò
{
	//int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	int arr[] = { 5,78,1,41,6,5,6 };

	Print(arr, sizeof(arr) / sizeof(int));
	SelectSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

void HeapSortTest()//²âÊÔ  ¶ÑÅÅÐò
{
	int arr[] = { 5,78,1,41,6,5,6 };
	Print(arr, sizeof(arr) / sizeof(int));
	HeapSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

void BubbleSortTest()//²âÊÔ  Ã°ÅÝÅÅÐò
{
	//int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	int arr[] = { 5,78,1,41,6,5,6 };
	Print(arr, sizeof(arr) / sizeof(int));
	BubbleSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

void QuickSortTest()
{
	//int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	int arr[] = { 5,78,1,41,6,5,6 };
	Print(arr, sizeof(arr) / sizeof(int));
	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	Print(arr, sizeof(arr) / sizeof(int));
}

void TestOP()//²âÊÔ ËùÓÐÅÅÐò ËÙ¶È
{
	int N = 10000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	
	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}

	int begin1 = clock();
	InsertSort(a1, N);//Ö±½Ó²åÈëÅÅÐò
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);//Ï£¶ûÅÅÐò
	int end2 = clock();

	int begin3 = clock();
	SelectSort(a3, N);//Ö±½ÓÑ¡ÔñÅÅÐò
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);//¶ÑÅÅÐò
	int end4 = clock();

	int begin5 = clock();
	BubbleSort(a5, N);//Ã°ÅÝÅÅÐò
	int end5 = clock();

	int begin6 = clock();
	QuickSort(a5, 0, N - 1);//¿ìËÙÅÅÐò
	int end6 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("BubbleSort:%d\n", end5 - begin5);
	printf("QuickSort:%d\n", end6 - begin6);


	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}

int main()
{
	srand((unsigned int)time(NULL));

	//InsertSortTest();
	//ShellSortTest();
	//SelectSortTest();
	//HeapSortTest();
	//BubbleSortTest();
	QuickSortTest();


	//TestOP();

	return 0;
}