#pragma once
#include <vector>

class UnionFindSet
{
private:
	std::vector<int> _ufs_;

public:
	UnionFindSet(const size_t n)
		:_ufs_(n, -1)
	{}

	bool Union(const int x1, const int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		if (root1 == root2)
			return false;

		_ufs_[root1] += _ufs_[root2];
		_ufs_[root2] = root1;
		return true;
	}

	//在查找 根节点 的过程中，可以进行路径压缩，已减少树的高度
	size_t FindRoot(const int x1)
	{
		int root = x1;//x1是指下标
		while (_ufs_[root] >= 0)
		{
			root = _ufs_[root];
		}

		//进行一个路径压缩
		int node = x1;
		while (_ufs_[node] >= 0)
		{
			int tmp = _ufs_[node];
			_ufs_[node] = root;
			node = tmp;
		}

		return root;
	}

	size_t Size()
	{
		size_t count = 0;
		for (size_t i = 0; i < _ufs_.size(); i++)
		{
			if (_ufs_[i] < 0)
			{
				count++;
			}
		}
		return count;
	}
};