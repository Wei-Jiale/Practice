// 二叉树的下一个结点（剑指Offer 8）
// 给定一颗二叉树和其中的一个结点，找出中序遍历的下一个结点。
// 树中除了有两个分别指向左、右子结点的指针，还有一个指向父结点的指针。

// 解题思路：
// 如果一个结点有右子树，那么这个结点的下一个节点就是右子树的最左结点。
// 如果一个结点无右子树，向上找第一个左链接指向的树包含该节点的祖先节点。

#include<iostream>
using namespace std;

struct BinaryTreeNode{
	BinaryTreeNode* left = nullptr;
	BinaryTreeNode* right = nullptr;
	BinaryTreeNode* parent = nullptr;
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode){
	// 判空
	if (pNode == nullptr)
		return nullptr;

	BinaryTreeNode* next = nullptr;
	// 如果一个结点有右子树
	// 这个结点的下一个结点就是右子树的最左结点
	if (pNode->right != nullptr){
		// 找最左结点
		BinaryTreeNode* cur = pNode->right;
		while (cur->left){
			cur = cur->left;
		}
		next = cur;
	}

	// 结点没有右子树
	// 向上找第一个左链接指向的树包含该节点的祖先节点
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
