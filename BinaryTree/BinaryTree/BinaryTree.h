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

void PrevOrder(BTNode* root);//ǰ�����
void InOrder(BTNode* root);//�������
void PostOrder(BTNode* root);//�������
void BinaryTreeLevelOrder(BTNode* root);//�������

void DestoryTree(BTNode* root);//���ٶ�����


int TreeSize(BTNode* root);//�������Ľ�����
int TreeLeafSize(BTNode* root);//������Ҷ�ӽ�����
int TreeDepth(BTNode* root);//�����������

int BinaryTreeLevelKSize(BTNode* root, int k);//��������K��ڵ����

BTNode* BinaryTreeFind(BTNode* root, BTData x);//����������ֵΪx�Ľ��

bool BinaryTreeComplete(BTNode* root);//�ж�һ�����Ƿ�Ϊ ��ȫ������