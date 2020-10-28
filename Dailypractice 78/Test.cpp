// 二叉搜索树和双向链表（剑指Offer 36）
// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
// 要求不能创建任何新的节点，只能调整树中节点指针的指向。

#include<iostream>
#include<list>
using namespace std;

// 用二叉搜索树的中序遍历序列就能实现排序的链表
// 最终链表的头结点是二叉搜索树最左结点，尾结点是二叉搜索树最右结点
// 

class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}

	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};

class Solution {
private:
	Node* head;
	Node* tail;
public:
	Node* treeToDoublyList(Node* root) {
		if (root == nullptr){
			return root;
		}

		inorder(root);

		head->left = tail;
		tail->right = head;

		return head;
	}

	void inorder(Node* root){
		if (root == nullptr){
			return;
		}

		inorder(root->left);

		// 首次遍历找到链表的头结点
		if (tail == nullptr){
			head = root;
		}
		else{
			tail->right = root;
			root->left = tail;
		}
		tail = root;

		inorder(root->right);
	}
};