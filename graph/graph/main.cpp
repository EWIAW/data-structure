#include <string>

#include "graph_matrix.h"
#include "graph_table.h"

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
	std::string str[] = { "张三","李四","王五","赵六" };
	Graph_Table<std::string, int> g(str, 4);
	g.AddEdge("张三", "李四", 100);
	g.AddEdge("张三", "王五", 200);
	g.AddEdge("王五", "赵六", 30);

	g.Print();
}

int main()
{
	//test1();
	test2();
	return 0;
}