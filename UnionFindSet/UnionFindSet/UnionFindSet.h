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

	size_t FindRoot(const int x1)
	{
		int root = x1;
		while (_ufs_[root] >= 0)
		{
			root = _ufs_[root];
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