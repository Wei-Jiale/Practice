// ������������˫��������ָOffer 36��
// ����һ�ö��������������ö���������ת����һ�������ѭ��˫������
// Ҫ���ܴ����κ��µĽڵ㣬ֻ�ܵ������нڵ�ָ���ָ��

#include<iostream>
#include<list>
using namespace std;

// �ö���������������������о���ʵ�����������
// ���������ͷ����Ƕ��������������㣬β����Ƕ������������ҽ��
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

		// �״α����ҵ������ͷ���
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