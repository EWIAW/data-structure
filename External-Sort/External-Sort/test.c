#include<stdio.h>

void combine(char* arr1, char* arr2, char* arr3)
{
	FILE* pf1 = fopen(arr1, "r");//打开待排序文件1
	if (pf1 == NULL)
	{
		printf("%s open fail\n", arr1);
		exit(-1);
	}

	FILE* pf2 = fopen(arr2, "r");//打开待排序文件2
	if (pf2 == NULL)
	{
		printf("%s open fail\n", arr2);
		exit(-1);
	}

	FILE* pf3 = fopen(arr3, "w");//打开合并文件
	if (pf3 == NULL)
	{
		printf("%s open fail\n", arr3);
		exit(-1);
	}

	int tmp1, tmp2;//存放排序数据
	int ret1 = fscanf(pf1, "%d\n", &tmp1);//从待排序文件1读取数据
	int ret2 = fscanf(pf2, "%d\n", &tmp2);//从待排序文件2读取数据
	while (ret1 != EOF && ret2 != EOF)
	{
		if (tmp1 < tmp2)
		{
			fprintf(pf3, "%d\n", tmp1);
			ret1 = fscanf(pf1, "%d\n", &tmp1);
		}
		else
		{
			fprintf(pf3, "%d\n", tmp2);
			ret2 = fscanf(pf2, "%d\n", &tmp2);
		}
	}
	while (fscanf(pf1, "%d\n", &tmp1) != EOF)
	{
		fprintf(pf3, "%d\n", tmp1);
	}
	while (fscanf(pf2, "%d\n", &tmp2) != EOF)
	{
		fprintf(pf3, "%d\n", tmp2);
	}

	fclose(pf1);
	fclose(pf2);
	fclose(pf3);
}

int main()
{
	//char arr1[20];//存放 待排序文件名1
	//char arr2[20];//存放 待排序文件名2
	//char arr3[20];//存放 结合文件名

	char arr1[20] = "data\\sort1.txt";
	char arr2[20] = "data\\sort2.txt";
	char arr3[20] = "all1.txt";

	combine(arr1, arr2, arr3);

	return 0;
}