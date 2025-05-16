#pragma once
#include <string>
#include "graph_matrix.h"

namespace test_matrix
{
	void test2()
	{
		std::string a[] = { "张三" };
		Graph_Matrix<std::string, int> g1(a, 1);
		g1.AddEdge("张三", "张三", 0); // 自环边（可选）
		//g1.BFS("张三"); // 预期输出：张三
		g1.DFS("张三");
	}

	void test3()
	{
		std::string a[] = { "张三", "李四", "王五", "赵六", "周七" };
		Graph_Matrix<std::string, int> g1(a, sizeof(a) / sizeof(std::string));
		g1.AddEdge("张三", "李四", 100);
		g1.AddEdge("张三", "王五", 200);
		g1.AddEdge("王五", "赵六", 30);
		g1.AddEdge("王五", "周七", 30);
		//g1.BFS("张三"); // 预期顺序：张三 → 李四 → 王五 → 赵六 → 周七
		g1.DFS("张三");
	}

	void test4()
	{
		std::string a[] = { "A", "B", "C" };
		Graph_Matrix<std::string, int> g1(a, 3);
		// 添加所有可能的边（无向图）
		g1.AddEdge("A", "B", 1);
		g1.AddEdge("A", "C", 1);
		g1.AddEdge("B", "C", 1);
		//g1.BFS("A"); // 预期顺序：A → B → C
		g1.DFS("A");
	}

	void test5()
	{
		std::string a[] = { "A", "B", "C" };
		Graph_Matrix<std::string, int> g1(a, 3);
		g1.AddEdge("A", "B", 1);
		g1.AddEdge("B", "C", 1);
		g1.AddEdge("C", "A", 1); // 形成环
		//g1.BFS("A"); // 预期顺序：A → B → C（避免重复访问）
		g1.DFS("A");
	}

	void test6()
	{
		std::string a[] = { "A", "B", "C", "D" };
		Graph_Matrix<std::string, int> g1(a, 4);
		g1.AddEdge("A", "B", 1); // 子图1: A-B
		g1.AddEdge("C", "D", 1); // 子图2: C-D
		//g1.BFS("A"); // 预期顺序：A → B（不访问C、D）
		g1.DFS("A");
	}

	void test7()
	{
		std::string a[] = { "A", "B", "C", "D" };
		Graph_Matrix<std::string, int> g1(a, 4);
		// 添加有向边（假设AddEdge是单向的）
		g1.AddEdge("A", "B", 1);
		g1.AddEdge("B", "C", 1);
		g1.AddEdge("C", "D", 1);
		//g1.BFS("A"); // 预期顺序：A → B → C → D
		g1.DFS("A");
	}

	void test8()
	{
		std::string a[] = { "A" };
		Graph_Matrix<std::string, int> g1(a, 1);
		g1.AddEdge("A", "A", 1); // 自环
		//g1.BFS("A"); // 预期输出：A（仅一次）
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
		//g1.BFS("Root"); // 预期顺序：Root → L1 → R1 → L2 → R2
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

