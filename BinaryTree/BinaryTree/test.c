#include"BinaryTree.h"

BTNode* BuyNode(BTData x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		printf("开辟失败\n");
		exit(-1);
	}
	newnode->val = x;
	newnode->right = NULL;
	newnode->left = NULL;
	return newnode;
}

int main()
{
	BTNode* A = BuyNode('A');
	BTNode* B = BuyNode('B');
	BTNode* C = BuyNode('C');
	BTNode* D = BuyNode('D');
	BTNode* E = BuyNode('E');
	//BTNode* G = BuyNode('G');

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;
	//E->right = G;

	PrevOrder(A);
	printf("\n");

	InOrder(A);
	printf("\n");

	PostOrder(A);
	printf("\n");

	printf("%d\n", TreeSize(A));
	printf("%d\n", TreeSize(B));

	printf("%d\n", TreeLeafSize(A));
	printf("%d\n", TreeLeafSize(B));

	printf("树的深度：%d\n", TreeDepth(A));
	printf("树的深度：%d\n", TreeDepth(B));

	int ret = BinaryTreeLevelKSize(A, 2);
	printf("该层的节点个数为%d\n", ret);

	BinaryTreeLevelOrder(A);

	if (BinaryTreeComplete(A))
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}

	return 0;
}