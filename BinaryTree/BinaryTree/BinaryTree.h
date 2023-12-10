#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>
#include<stdbool.h>

typedef int BTData;

typedef struct BinaryTreeNode
{
	BTData val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

void PrevOrder(BTNode* root);//前序遍历
void InOrder(BTNode* root);//中序遍历
void PostOrder(BTNode* root);//后序遍历
void BinaryTreeLevelOrder(BTNode* root);//层序遍历

void DestoryTree(BTNode* root);//销毁二叉树


int TreeSize(BTNode* root);//二叉树的结点个数
int TreeLeafSize(BTNode* root);//二叉树叶子结点个数
int TreeDepth(BTNode* root);//二叉树的深度

int BinaryTreeLevelKSize(BTNode* root, int k);//二叉树第K层节点个数

BTNode* BinaryTreeFind(BTNode* root, BTData x);//二叉树查找值为x的结点

bool BinaryTreeComplete(BTNode* root);//判断一棵树是否为 完全二叉树