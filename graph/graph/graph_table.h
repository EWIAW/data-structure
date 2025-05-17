#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>

template<class W>
struct Graph_Node
{
	size_t __index;//�洢���ǣ��������Ķ��� ��_vertex�е��±�
	W __weight;//�洢���� �����ߵ� Ȩֵ
	Graph_Node* __next;

	Graph_Node(const size_t& index,const W& weight)
		:__index(index),
		__weight(weight),
		__next(nullptr)
	{}
};

//�ڽӱ�ͼ
//false ������ ����ͼ
template<class V,class W,bool Direction = false>
class Graph_Table
{
	using Node = Graph_Node<W>;
private:
	std::vector<V> _vertex;//�洢����
	std::unordered_map<V, size_t> _indexmap;//���ڴ洢������_vertex�У��������±��ӳ���ϵ�����ڿ��ٲ��Ҷ���
	std::vector<Node*> _table;//�ڽӱ�

public:
	//string str[] = {"����","�Ϻ�","����","����"};
	//Graph_Table graph(str,size());
	Graph_Table(const V* vertex, const size_t n)
		:_vertex(n),
		_table(n, nullptr)
	{
		for (size_t i = 0; i < n; i++)
		{
			_vertex[i] = vertex[i];
			_indexmap[vertex[i]] = i;
		}
	}

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

	bool AddEdge(const V& src, const V& dest, const W& weight)
	{
		size_t src_index = GetVertexIndex(src);
		size_t dest_index = GetVertexIndex(dest);
		if (src_index == -1 || dest_index == -1)
		{
			return false;
		}

		Node* node = new Node(dest_index, weight);
		Node* tmp = _table[src_index];
		_table[src_index] = node;
		node->__next = tmp;

		if (Direction == false)
		{
			Node* node = new Node(src_index, weight);
			Node* tmp = _table[dest_index];
			_table[dest_index] = node;
			node->__next = tmp;
		}

		return true;
	}

	void Print()
	{
		for (size_t i = 0; i < _vertex.size(); i++)
		{
			std::cout << _vertex[i] << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;

		for (size_t i = 0; i < _table.size(); i++)
		{
			std::cout << _vertex[i] << "->";
			Node* cur = _table[i];
			while (cur != nullptr)
			{
				std::cout << _vertex[cur->__index] << cur->__weight << "->";
				cur = cur->__next;
			}
			std::cout << "nullptr" << std::endl;
		}
	}

	void BFS(const V& vertex)
	{
		std::vector<bool> visited(_vertex.size(), false);
		size_t count = 0;//��¼�ж��ٸ����� �Ѿ���������

		_BFS(vertex, visited, count);

		while (count < _vertex.size())
		{
			for (int i = 0; i < visited.size(); i++)
			{
				if (visited[i] == false)
				{
					_BFS(_vertex[i], visited, count);
				}
			}
		}
		std::cout << std::endl;
	}

	void DFS(const V& vertex)
	{
		std::vector<bool> visited(_vertex.size(), false);
		size_t count = 0;

		_DFS(vertex, visited, count);

		while (count < _vertex.size())
		{
			for (int i = 0; i < visited.size(); i++)
			{
				if (visited[i] == false)
				{
					_DFS(_vertex[i], visited, count);
				}
			}
		}
		std::cout << std::endl;
	}

private:
	void _BFS(const V& vertex, std::vector<bool>& visited, size_t& count)
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
				V tmp = q.front();
				q.pop();

				std::cout << tmp << " ";
				count++;

				size_t index = GetVertexIndex(tmp);
				Node* cur = _table[index];
				while (cur != nullptr && visited[cur->__index] == false)
				{
					q.push(_vertex[cur->__index]);
					visited[cur->__index] = true;
					cur = cur->__next;
				}
			}
			std::cout << std::endl;
		}
	}

	void _DFS(const V& vertex, std::vector<bool>& visited, size_t& count)
	{
		std::cout << vertex << " ";

		size_t index = GetVertexIndex(vertex);
		visited[index] = true;
		count++;

		Node* cur = _table[index];
		while (cur != nullptr)
		{
			if (visited[cur->__index] == false)
			{
				_DFS(_vertex[cur->__index], visited, count);
			}
			else
			{
				cur = cur->__next;
			}
		}
	}
};