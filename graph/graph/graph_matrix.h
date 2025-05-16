#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

//�ڽӾ���ͼ
//V�Ƕ�������ͣ�W�Ǳߵ�Ȩֵ�� �����붥��֮��û����ͨ����MAX_XĬ��Ȩֵ���棬Direction == false����������ͼ
template<class V, class W, W MAX_W = INT_MAX, bool Direction = false>
class Graph_Matrix
{
private:
	std::vector<V> _vertex;//�洢����
	std::vector<std::vector<W>> _matrix;//�洢 ����ͱߵĹ�ϵ �ľ���
	std::unordered_map<V, size_t> _indexmap;//���ڴ洢���� �� _vertex�±�Ĺ�ϵ�����ڿ��ٲ��� ������±�

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

	//��ȡһ��������±�
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

	//����һ���ߣ���ӱߵı����Ǹı� �ڽӾ����е�ֵ
	bool AddEdge(const V& src, const V& dest, const W& weight)
	{
		size_t src_index = GetVertexIndex(src);
		size_t dest_index = GetVertexIndex(dest);
		if (src_index == -1 || dest_index == -1)
		{
			return false;
		}
		_matrix[src_index][dest_index] = weight;

		//���������ͼ����
		if (Direction == false)
		{
			_matrix[dest_index][src_index] = weight;
		}
		return true;
	}

	//��ӡͼ����Ϣ���Ա��ڲ��Թ۲�
	void print()
	{
		//�ȴ�ӡ������Ϣ
		for (auto& tmp : _vertex)
		{
			std::cout << tmp << " ";
		}
		std::cout << std::endl;

		//��ӡ������Ϣ
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
		std::vector<bool> visited(_vertex.size(), false);//�ж�һ�������Ƿ��Ѿ������ʹ�
		size_t visited_size = 0;//��¼�ж��ٸ����� �����ʹ�
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
		size_t visited_size = 0;//��¼�ж��ٸ����� �����ʹ�
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
	//������ȱ����Ӻ���
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
				//����һ�����
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

	//������ȱ����Ӻ���
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
