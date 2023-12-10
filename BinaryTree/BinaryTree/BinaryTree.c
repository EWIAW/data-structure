#include"BinaryTree.h"
#include"Queue.h"
void PrevOrder(BTNode* root)//前序遍历
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->val);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(BTNode* root)//中序遍历
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}

void PostOrder(BTNode* root)//后序遍历
{
	if (root == NULL)
	{ 
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->val);
}

int TreeSize(BTNode* root)//树的结点个数
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + TreeSize(root->left) + TreeSize(root->right);
	}
}

int TreeLeafSize(BTNode* root)//叶子结点个数
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	else
	{
		return TreeLeafSize(root->left) + TreeLeafSize(root->right);
	}
}

int TreeDepth(BTNode* root)//树的深度
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + fmax(TreeDepth(root->left), TreeDepth(root->right));
	}
}

int BinaryTreeLevelKSize(BTNode* root, int k)//二叉树第K层节点个数
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	else
	{
		return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
	}
}

BTNode* BinaryTreeFind(BTNode* root, BTData x)//二叉树查找值为x的结点
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->val == x)//如果当前根是，则返回
	{
		return root;
	}

	BTNode* node = BinaryTreeFind(root->left, x);//如果左子树找到了，则返回
	if (node != NULL)
	{
		return node;
	}

	node = BinaryTreeFind(root->right, x);//如果右子树找到了，则返回
	if (node != NULL)
	{
		return node;
	}

	return NULL;
}

void DestoryTree(BTNode* root)//销毁二叉树
{
	if (root == NULL)
	{
		return;
	}

	DestoryTree(root->left);
	DestoryTree(root->right);
	free(root);
}

void BinaryTreeLevelOrder(BTNode* root)//层序遍历
{
	if (root == NULL)
	{
		return;
	}

	Queue Q;//创建队列
	QueueInit(&Q);//初始化队列

	QueuePush(&Q, root);//先入头根

	while (!QueueEmpty(&Q)) //如果队列不为空
	{
		BTNode* node = QueueFront(&Q);
		printf("%c ", node->val);

		if (node->left != NULL)
		{
			QueuePush(&Q, node->left);
		}

		if (node->right != NULL)
		{
			QueuePush(&Q, node->right);
		}

		QueuePop(&Q);
	}
		
	printf("\n");
	QueueDestory(&Q);//销毁队列
}


bool BinaryTreeComplete(BTNode* root)//判断一棵树是否为 完全二叉树
{
	if (root == NULL)
	{
		return true;
	}

	Queue Q;
	QueueInit(&Q);

	QueuePush(&Q, root);

	while (!QueueEmpty(&Q))
	{
		BTNode* node = QueueFront(&Q);
		QueuePop(&Q);

		if (node == NULL)
		{
			break;
		}

		QueuePush(&Q, node->left);
		QueuePush(&Q, node->right);

	}


	while (!QueueEmpty(&Q))
	{
		BTNode* node = QueueFront(&Q);
		if (node != NULL)
		{
			QueueDestory(&Q);
			return false;
		}
		QueuePop(&Q);
	}

	QueueDestory(&Q);
	return true;
}
