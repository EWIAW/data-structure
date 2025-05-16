#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

//邻接矩阵图
//V是顶点的类型，W是边的权值， 顶点与顶点之间没有连通的用MAX_X默认权值代替，Direction == false代表是无向图
template<class V, class W, W MAX_W = INT_MAX, bool Direction = false>
class Graph_Matrix
{
private:
	std::vector<V> _vertex;//存储顶点
	std::vector<std::vector<W>> _matrix;//存储 顶点和边的关系 的矩阵
	std::unordered_map<V, size_t> _indexmap;//用于存储顶点 与 _vertex下标的关系，用于快速查找 顶点的下标

public:
	Graph_Matrix(const V* vertex, const size_t n)
		:_vertex(n),
		_matrix(n)
	{
		for (size_t i = 0; i < n; i++)
		{
			_vertex[i] = vertex[i];
			_indexmap[vertex[i]] = i;
			_matrix[i].resize(n, MAX_W);
		}
	}

	//获取一个顶点的下标
	size_t GetVertexIndex(const V& vertex)
	{
		auto it = _indexmap.find(vertex);
		if (it == _indexmap.end())
		{
			return -1;
		}
		else
		{
			return it->second;
		}
	}

	//增加一条边，添加边的本质是改变 邻接矩阵中的值
	bool AddEdge(const V& src, const V& dest, const W& weight)
	{
		size_t src_index = GetVertexIndex(src);
		size_t dest_index = GetVertexIndex(dest);
		if (src_index == -1 || dest_index == -1)
		{
			return false;
		}
		_matrix[src_index][dest_index] = weight;

		//如果是无向图，则
		if (Direction == false)
		{
			_matrix[dest_index][src_index] = weight;
		}
		return true;
	}

	//打印图的信息，以便于测试观察
	void print()
	{
		//先打印顶点信息
		for (auto& tmp : _vertex)
		{
			std::cout << tmp << " ";
		}
		std::cout << std::endl;

		//打印矩阵信息
		for (int i = 0; i < _matrix.size(); i++)
		{
			for (int j = 0; j < _matrix[i].size(); j++)
			{
				if (_matrix[i][j] == INT_MAX)
				{
					std::cout << "*" << " ";
				}
				else
				{
					std::cout << _matrix[i][j] << " ";
				}
			}
			std::cout << std::endl;
		}
	}

	void BFS(const V& vertex)
	{
		std::vector<bool> visited(_vertex.size(), false);//判断一个顶点是否已经被访问过
		size_t visited_size = 0;//记录有多少个顶点 被访问过
		_BFS(vertex, visited, visited_size);

		while (visited_size < _vertex.size())
		{
			for (int i = 0; i < visited.size(); i++)
			{
				if (visited[i] == false)
				{
					_BFS(_vertex[i], visited, visited_size);
				}
			}
		}
		std::cout << std::endl;
	}

	void DFS(const V& vertex)
	{
		std::vector<bool> visited(_vertex.size(), false);
		size_t visited_size = 0;//记录有多少个顶点 被访问过
		_DFS(vertex, visited, visited_size);

		while (visited_size < _vertex.size())
		{
			for (int i = 0; i < visited.size(); i++)
			{
				if (visited[i] == false)
				{
					_DFS(_vertex[i], visited, visited_size);
				}
			}
		}
		std::cout << std::endl;
	}

private:
	//广度优先遍历子函数
	void _BFS(const V& vertex, std::vector<bool>& visited, size_t& visited_size)
	{
		std::queue<V> q;
		q.push(vertex);
		size_t index = GetVertexIndex(vertex);
		visited[index] = true;

		while (q.empty() != true)
		{
			size_t n = q.size();

			for (size_t i = 0; i < n; i++)
			{
				//访问一个结点
				V tmp = q.front();
				q.pop();
				std::cout << tmp << " ";
				visited_size++;

				size_t index = GetVertexIndex(tmp);
				for (int i = 0; i < _matrix[index].size(); i++)
				{
					if (_matrix[index][i] != MAX_W && visited[i] != true)
					{
						q.push(_vertex[i]);
						visited[i] = true;
					}
				}
			}
			std::cout << std::endl;
		}
	}

	//深度优先遍历子函数
	void _DFS(const V& vertex, std::vector<bool>& visited, size_t& visited_size)
	{
		std::cout << vertex << " ";
		visited_size++;

		size_t index = GetVertexIndex(vertex);
		visited[index] = true;

		for (int i = 0; i < _matrix[index].size(); i++)
		{
			if (_matrix[index][i] != MAX_W && visited[i] != true)
			{
				_DFS(_vertex[i], visited, visited_size);
			}
		}
	}
};
