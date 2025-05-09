#include<iostream>
#include "UnionFindSet.h"

using namespace std;

int findCircleNum(vector<vector<int>>& isConnected)
{
	UnionFindSet ufs(isConnected.size());
	for (int i = 0; i < isConnected.size(); i++)
	{
		for (int j = 0; j < isConnected[0].size(); j++)
		{
			if (isConnected[i][j] == 1)
			{
				ufs.Union(i, j);
			}
		}
	}
	return ufs.Size();
}

int main()
{
	vector<vector<int>> vec = { {1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1} };
	int ret = findCircleNum(vec);
	return 0;
}