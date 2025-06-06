#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

#include "UnionFindSet.h"

//邻接矩阵图
//V是顶点的类型，W是边的权值， 顶点与顶点之间没有连通的用MAX_X默认权值代替，Direction == false代表是无向图
template<class V, class W, W MAX_W = INT_MAX, bool Direction = false>
class Graph_Matrix
{
	using Self = Graph_Matrix<V, W, MAX_W, Direction>;
private:
	std::vector<V> _vertex;//存储顶点
	std::vector<std::vector<W>> _matrix;//存储 顶点和边的关系 的矩阵
	std::unordered_map<V, size_t> _indexmap;//用于存储顶点 与 _vertex下标的关系，用于快速查找 顶点的下标

public:
	Graph_Matrix() = default;

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

	//最小生成树
	W Kruskal(Self& minTree)
	{
		//初始化minTree
		minTree._vertex = _vertex;
		minTree._indexmap = _indexmap;
		minTree._matrix = _matrix;
		
		for (int i = 0; i < minTree._matrix.size(); i++)
		{
			minTree._matrix[i].resize(minTree._vertex.size(), MAX_W);
		}

		//先把所有边存储起来
		std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
		for (int i = 0; i < _matrix.size(); i++)
		{
			for (int j = i; j < _matrix[i].size(); j++)
			{
				if (_matrix[i][j] != MAX_W)
				{
					Edge edge(i, j, _matrix[i][j]);
					pq.push(edge);
				}
			}
		}

		//开始选边
		UnionFindSet ufs(_vertex.size());
		int count = 0;//记录已经选了的 边数
		W all_weight = W();//记录权值总和

		while (pq.empty() != true)
		{
			Edge tmp = pq.top();
			pq.pop();

			//说明这两个顶点 连接起来 不会形成回路
			if (ufs.FindRoot(tmp.__src_index) != ufs.FindRoot(tmp.__dest_index))
			{
				minTree._matrix[tmp.__src_index][tmp.__dest_index] = tmp.__weight;

				ufs.Union(tmp.__src_index, tmp.__dest_index);
				count++;
				all_weight += tmp.__weight;
			}
		}

		if (count == _vertex.size() - 1)
		{
			return all_weight;
		}
		else
		{
			return W();
		}
	}

	W Prim(Self& minTree, const V& vertex)
	{
		//初始化minTree
		minTree._vertex = _vertex;
		minTree._indexmap = _indexmap;
		minTree._matrix = _matrix;

		for (int i = 0; i < minTree._matrix.size(); i++)
		{
			minTree._matrix[i].resize(minTree._vertex.size(), MAX_W);
		}

		std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
		std::vector<bool> visited(_vertex.size(), false);
		size_t index = GetVertexIndex(vertex);
		visited[index] = true;

		for (int i = 0; i < _matrix[index].size(); i++)
		{
			if (_matrix[index][i] != MAX_W)
			{
				pq.push(Edge(index, i, _matrix[index][i]));
			}
		}

		W total = W();
		int count = 0;
		while (pq.empty() != true)
		{
			Edge edge = pq.top();
			pq.pop();

			if (visited[edge.__dest_index] == false)
			{
				minTree._matrix[edge.__src_index][edge.__dest_index] = edge.__weight;
				visited[edge.__dest_index] = true;
				total += edge.__weight;
				count++;

				for (int i = 0; i < _matrix[edge.__dest_index].size(); i++)
				{
					if (_matrix[edge.__dest_index][i] != MAX_W && visited[i] != true)
					{
						pq.push(Edge(edge.__dest_index, i, _matrix[edge.__dest_index][i]));
					}
				}
			}
			else
			{
				continue;
			}
		}

		if (count == _vertex.size() - 1)
		{
			return total;
		}
		else
		{
			return W();
		}
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

private:
	//边 对象 辅助结构体
	struct Edge
	{
		size_t __src_index;
		size_t __dest_index;
		W __weight;

		Edge(const size_t src_index,const size_t dest_index,const W weight)
			:__src_index(src_index),
			__dest_index(dest_index),
			__weight(weight)
		{}

		bool operator>(const Edge& tmp) const
		{
			if (__weight > tmp.__weight)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	};
};
