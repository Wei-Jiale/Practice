// ����������һ����㣨��ָOffer 8��
// ����һ�Ŷ����������е�һ����㣬�ҳ������������һ����㡣
// ���г����������ֱ�ָ�������ӽ���ָ�룬����һ��ָ�򸸽���ָ�롣

// ����˼·��
// ���һ�����������������ô���������һ���ڵ�����������������㡣
// ���һ��������������������ҵ�һ��������ָ����������ýڵ�����Ƚڵ㡣

#include<iostream>
using namespace std;

struct BinaryTreeNode{
	BinaryTreeNode* left = nullptr;
	BinaryTreeNode* right = nullptr;
	BinaryTreeNode* parent = nullptr;
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode){
	// �п�
	if (pNode == nullptr)
		return nullptr;

	BinaryTreeNode* next = nullptr;
	// ���һ�������������
	// ���������һ����������������������
	if (pNode->right != nullptr){
		// ��������
		BinaryTreeNode* cur = pNode->right;
		while (cur->left){
			cur = cur->left;
		}
		next = cur;
	}

	// ���û��������
	// �����ҵ�һ��������ָ����������ýڵ�����Ƚڵ�
	else if (pNode->parent != nullptr){
		BinaryTreeNode* cur = pNode;
		BinaryTreeNode* father = pNode->parent;
		while (father != nullptr && cur == father->right){
			cur = father;
			father = father->parent;
		}
		next = father;
	}

	return next;
}
