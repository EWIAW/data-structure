#include <string>

#include "graph_matrix.h"
#include "graph_table.h"
#include "test.h"

void test1()
{
	Graph_Matrix<char, int, INT_MAX, true> g("0123", 4);
	g.AddEdge('0', '1', 1);
	g.AddEdge('0', '3', 4);
	g.AddEdge('1', '3', 2);
	g.AddEdge('1', '2', 9);
	g.AddEdge('2', '3', 8);
	g.AddEdge('2', '1', 5);
	g.AddEdge('2', '0', 3);
	g.AddEdge('3', '2', 6);
	g.print();

}

void test2()
{
	std::string str[] = { "����","����","����","����" };
	Graph_Table<std::string, int> g(str, 4);
	g.AddEdge("����", "����", 100);
	g.AddEdge("����", "����", 200);
	g.AddEdge("����", "����", 30);

	g.Print();
}

void test3()
{
	std::string a[] = { "����", "����", "����", "����", "����" };
	Graph_Matrix<std::string, int> g1(a, sizeof(a) / sizeof(std::string));
	g1.AddEdge("����", "����", 100);
	g1.AddEdge("����", "����", 200);
	g1.AddEdge("����", "����", 30);
	g1.AddEdge("����", "����", 30);
	g1.BFS("����");
	//g1.DFS("����");
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test_matrix::test_total();
	//test_table::test_total();
	test_minTree::TestGraphMinTree();
	return 0;
}