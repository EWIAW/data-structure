#include<iostream>
#include "UnionFindSet.h"

using namespace std;

//int findCircleNum(vector<vector<int>>& isConnected)
//{
//	UnionFindSet ufs(isConnected.size());
//	for (int i = 0; i < isConnected.size(); i++)
//	{
//		for (int j = 0; j < isConnected[0].size(); j++)
//		{
//			if (isConnected[i][j] == 1)
//			{
//				ufs.Union(i, j);
//			}
//		}
//	}
//	return ufs.Size();
//}

int main()
{
	//vector<vector<int>> vec = { {1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1} };
	//int ret = findCircleNum(vec);
	UnionFindSet ufs(10);
	ufs.Union(8, 9);
	ufs.Union(7, 8);
	ufs.Union(6, 7);
	ufs.Union(5, 6);
	ufs.Union(4, 5);
	ufs.FindRoot(7);
	return 0;
}