#include<stdio.h>
#include<time.h>

//�������ı����ݽ�ϵ��µ��ı���
void Combine(char* arr1, char* arr2, char* arr3)
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

	int tmp1, tmp2;//��Ŷ�ȡ������
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

	//��δд�������ǿ��д�룬�������ݶ�ʧ
	if (ret1 != EOF)
	{
		fprintf(pf3, "%d\n", tmp1);
	}
	if (ret2 != EOF)
	{
		fprintf(pf3, "%d\n", tmp2);
	}

	//��ʣ�µ�����ȫ��д��
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

//�����������
void MakeData()
{
	int arr[100];
	for (int i = 0; i < 100; i++)
	{
		arr[i] = i + 1;
	}

	//for (int i = 0; i < 100; i++)
	//{
	//	printf("%d ", arr[i]);
	//}

	//printf("\n");

	for (int i = 1; i <= 30; i++)
	{
		int x = rand() % 100;
		int y = rand() % 100;

		int tmp = arr[x];
		arr[x] = arr[y];
		arr[y] = tmp;
	}

	//for (int i = 0; i < 100; i++)
	//{
	//	printf("%d ", arr[i]);
	//}

	char name[20];
	for (int i = 0; i < 10; i++)
	{
		sprintf(name, "data\\sort%d.txt", i);
		FILE* pf = fopen(name, "w");
		if (pf == NULL)
		{
			printf("%s open fail\n", name);
			exit(-1);
		}

		for (int j = 0; j < 10; j++)
		{
			fprintf(pf, "%d\n", arr[i * 10 + j]);
		}

		fclose(pf);
	}
}

int Compare(void* p1, void* p2)
{
	return *(int*)p1 - *(int*)p2;
}

//�������ı��ļ���������
void sort()
{
	int i = 0;
	char name[20];
	while (1)
	{
		sprintf(name, "data\\sort%d.txt", i);
		i++;

		FILE* pf = fopen(name, "r");
		if (pf == NULL)
		{
			printf("�����ı��������\n");
			break;
		}

		int arr[10];
		int tmp = 0;
		for (int j = 0; j < 10; j++)
		{
			int ret = fscanf(pf, "%d\n", &tmp);
			if (ret != EOF)
			{
				arr[j] = tmp;
			}
			else
			{
				break;
			}
		}

		qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), Compare);

		fclose(pf);

		pf = fopen(name, "w");
		if (pf == NULL)
		{
			printf("���ļ�ʧ��\n");
			exit(-1);
		}

		int k = 0;
		for (int i = 0; i < 10; i++)
		{
			fprintf(pf, "%d\n", arr[k++]);
		}
		fclose(pf);
	}
}

int main()
{
	srand(time(NULL));

	MakeData();//�����������

	sort();

	char name1[20];
	char name2[10];
	char name3[10];
	int i = 0;
	int j = 0;

	while (1)
	{
		sprintf(name1, "data\\sort%d.txt", i);
		i++;

		FILE* pf = fopen(name1, "r");
		if (pf == NULL)
		{
			printf("�������\n");
			break;
		}

		fclose(pf);


		sprintf(name2, "all%d.txt", j % 2);
		sprintf(name3, "all%d.txt", (j + 1) % 2);
		j++;

		Combine(name1, name2, name3);
	}

	return 0;
}