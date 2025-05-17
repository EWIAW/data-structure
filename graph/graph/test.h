#pragma once
#include <string>
#include "graph_matrix.h"

namespace test_matrix
{
	void test2()
	{
		std::string a[] = { "����" };
		Graph_Matrix<std::string, int> g1(a, 1);
		g1.AddEdge("����", "����", 0); // �Ի��ߣ���ѡ��
		//g1.BFS("����"); // Ԥ�����������
		g1.DFS("����");
	}

	void test3()
	{
		std::string a[] = { "����", "����", "����", "����", "����" };
		Graph_Matrix<std::string, int> g1(a, sizeof(a) / sizeof(std::string));
		g1.AddEdge("����", "����", 100);
		g1.AddEdge("����", "����", 200);
		g1.AddEdge("����", "����", 30);
		g1.AddEdge("����", "����", 30);
		//g1.BFS("����"); // Ԥ��˳������ �� ���� �� ���� �� ���� �� ����
		g1.DFS("����");
	}

	void test4()
	{
		std::string a[] = { "A", "B", "C" };
		Graph_Matrix<std::string, int> g1(a, 3);
		// ������п��ܵıߣ�����ͼ��
		g1.AddEdge("A", "B", 1);
		g1.AddEdge("A", "C", 1);
		g1.AddEdge("B", "C", 1);
		//g1.BFS("A"); // Ԥ��˳��A �� B �� C
		g1.DFS("A");
	}

	void test5()
	{
		std::string a[] = { "A", "B", "C" };
		Graph_Matrix<std::string, int> g1(a, 3);
		g1.AddEdge("A", "B", 1);
		g1.AddEdge("B", "C", 1);
		g1.AddEdge("C", "A", 1); // �γɻ�
		//g1.BFS("A"); // Ԥ��˳��A �� B �� C�������ظ����ʣ�
		g1.DFS("A");
	}

	void test6()
	{
		std::string a[] = { "A", "B", "C", "D" };
		Graph_Matrix<std::string, int> g1(a, 4);
		g1.AddEdge("A", "B", 1); // ��ͼ1: A-B
		g1.AddEdge("C", "D", 1); // ��ͼ2: C-D
		//g1.BFS("A"); // Ԥ��˳��A �� B��������C��D��
		g1.DFS("A");
	}

	void test7()
	{
		std::string a[] = { "A", "B", "C", "D" };
		Graph_Matrix<std::string, int> g1(a, 4);
		// �������ߣ�����AddEdge�ǵ���ģ�
		g1.AddEdge("A", "B", 1);
		g1.AddEdge("B", "C", 1);
		g1.AddEdge("C", "D", 1);
		//g1.BFS("A"); // Ԥ��˳��A �� B �� C �� D
		g1.DFS("A");
	}

	void test8()
	{
		std::string a[] = { "A" };
		Graph_Matrix<std::string, int> g1(a, 1);
		g1.AddEdge("A", "A", 1); // �Ի�
		//g1.BFS("A"); // Ԥ�������A����һ�Σ�
		g1.DFS("A");
	}

	void test9()
	{
		std::string a[] = { "Root", "L1", "L2", "R1", "R2" };
		Graph_Matrix<std::string, int> g1(a, 5);
		g1.AddEdge("Root", "L1", 1);
		g1.AddEdge("Root", "R1", 1);
		g1.AddEdge("L1", "L2", 1);
		g1.AddEdge("R1", "R2", 1);
		//g1.BFS("Root"); // Ԥ��˳��Root �� L1 �� R1 �� L2 �� R2
		g1.DFS("Root");
	}

	void test_total()
	{
		test2();
		test3();
		test4();
		test5();
		test6();
		test7();
		test8();
		test9();
	}
}

namespace test_table
{
	void test2()
	{
		std::string a[] = { "����" };
		Graph_Table<std::string, int> g1(a, 1);
		g1.AddEdge("����", "����", 0); // �Ի��ߣ���ѡ��
		//g1.BFS("����"); // Ԥ�����������
		g1.DFS("����");
	}

	void test3()
	{
		std::string a[] = { "����", "����", "����", "����", "����" };
		Graph_Table<std::string, int> g1(a, sizeof(a) / sizeof(std::string));
		g1.AddEdge("����", "����", 100);
		g1.AddEdge("����", "����", 200);
		g1.AddEdge("����", "����", 30);
		g1.AddEdge("����", "����", 30);
		//g1.BFS("����"); // Ԥ��˳������ �� ���� �� ���� �� ���� �� ����
		g1.DFS("����");
	}

	void test4()
	{
		std::string a[] = { "A", "B", "C" };
		Graph_Table<std::string, int> g1(a, 3);
		// ������п��ܵıߣ�����ͼ��
		g1.AddEdge("A", "B", 1);
		g1.AddEdge("A", "C", 1);
		g1.AddEdge("B", "C", 1);
		//g1.BFS("A"); // Ԥ��˳��A �� B �� C
		g1.DFS("A");
	}

	void test5()
	{
		std::string a[] = { "A", "B", "C" };
		Graph_Table<std::string, int> g1(a, 3);
		g1.AddEdge("A", "B", 1);
		g1.AddEdge("B", "C", 1);
		g1.AddEdge("C", "A", 1); // �γɻ�
		//g1.BFS("A"); // Ԥ��˳��A �� B �� C�������ظ����ʣ�
		g1.DFS("A");
	}

	void test6()
	{
		std::string a[] = { "A", "B", "C", "D" };
		Graph_Table<std::string, int> g1(a, 4);
		g1.AddEdge("A", "B", 1); // ��ͼ1: A-B
		g1.AddEdge("C", "D", 1); // ��ͼ2: C-D
		//g1.BFS("A"); // Ԥ��˳��A �� B��������C��D��
		g1.DFS("A");
	}

	void test7()
	{
		std::string a[] = { "A", "B", "C", "D" };
		Graph_Table<std::string, int> g1(a, 4);
		// �������ߣ�����AddEdge�ǵ���ģ�
		g1.AddEdge("A", "B", 1);
		g1.AddEdge("B", "C", 1);
		g1.AddEdge("C", "D", 1);
		//g1.BFS("A"); // Ԥ��˳��A �� B �� C �� D
		g1.DFS("A");
	}

	void test8()
	{
		std::string a[] = { "A" };
		Graph_Table<std::string, int> g1(a, 1);
		g1.AddEdge("A", "A", 1); // �Ի�
		g1.BFS("A"); // Ԥ�������A����һ�Σ�
		g1.DFS("A");
	}

	void test9()
	{
		std::string a[] = { "Root", "L1", "L2", "R1", "R2" };
		Graph_Table<std::string, int> g1(a, 5);
		g1.AddEdge("Root", "L1", 1);
		g1.AddEdge("Root", "R1", 1);
		g1.AddEdge("L1", "L2", 1);
		g1.AddEdge("R1", "R2", 1);
		//g1.BFS("Root"); // Ԥ��˳��Root �� L1 �� R1 �� L2 �� R2
		g1.DFS("Root");
	}

	void test_total()
	{
		test2();
		test3();
		test4();
		test5();
		test6();
		test7();
		test8();
		test9();
	}
}
