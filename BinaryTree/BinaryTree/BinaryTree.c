#include"BinaryTree.h"
#include"Queue.h"
void PrevOrder(BTNode* root)//ǰ�����
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

void InOrder(BTNode* root)//�������
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

void PostOrder(BTNode* root)//�������
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

int TreeSize(BTNode* root)//���Ľ�����
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

int TreeLeafSize(BTNode* root)//Ҷ�ӽ�����
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

int TreeDepth(BTNode* root)//�������
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

int BinaryTreeLevelKSize(BTNode* root, int k)//��������K��ڵ����
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

BTNode* BinaryTreeFind(BTNode* root, BTData x)//����������ֵΪx�Ľ��
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->val == x)//�����ǰ���ǣ��򷵻�
	{
		return root;
	}

	BTNode* node = BinaryTreeFind(root->left, x);//����������ҵ��ˣ��򷵻�
	if (node != NULL)
	{
		return node;
	}

	node = BinaryTreeFind(root->right, x);//����������ҵ��ˣ��򷵻�
	if (node != NULL)
	{
		return node;
	}

	return NULL;
}

void DestoryTree(BTNode* root)//���ٶ�����
{
	if (root == NULL)
	{
		return;
	}

	DestoryTree(root->left);
	DestoryTree(root->right);
	free(root);
}

void BinaryTreeLevelOrder(BTNode* root)//�������
{
	if (root == NULL)
	{
		return;
	}

	Queue Q;//��������
	QueueInit(&Q);//��ʼ������

	QueuePush(&Q, root);//����ͷ��

	while (!QueueEmpty(&Q)) //������в�Ϊ��
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
	QueueDestory(&Q);//���ٶ���
}


bool BinaryTreeComplete(BTNode* root)//�ж�һ�����Ƿ�Ϊ ��ȫ������
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
