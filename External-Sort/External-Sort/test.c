#include<stdio.h>

void combine(char* arr1, char* arr2, char* arr3)
{
	FILE* pf1 = fopen(arr1, "r");//�򿪴������ļ�1
	if (pf1 == NULL)
	{
		printf("%s open fail\n", arr1);
		exit(-1);
	}

	FILE* pf2 = fopen(arr2, "r");//�򿪴������ļ�2
	if (pf2 == NULL)
	{
		printf("%s open fail\n", arr2);
		exit(-1);
	}

	FILE* pf3 = fopen(arr3, "w");//�򿪺ϲ��ļ�
	if (pf3 == NULL)
	{
		printf("%s open fail\n", arr3);
		exit(-1);
	}

	int tmp1, tmp2;//�����������
	int ret1 = fscanf(pf1, "%d\n", &tmp1);//�Ӵ������ļ�1��ȡ����
	int ret2 = fscanf(pf2, "%d\n", &tmp2);//�Ӵ������ļ�2��ȡ����
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
	//char arr1[20];//��� �������ļ���1
	//char arr2[20];//��� �������ļ���2
	//char arr3[20];//��� ����ļ���

	char arr1[20] = "data\\sort1.txt";
	char arr2[20] = "data\\sort2.txt";
	char arr3[20] = "all1.txt";

	combine(arr1, arr2, arr3);

	return 0;
}