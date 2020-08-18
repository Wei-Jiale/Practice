// 026����ת������
// ����ÿ���������Ӻ��Һ���

#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// �ݹ�
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr){
			return root;
		}

		// swap�����������Һ���
		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;

		// �ݹ������������
		invertTree(root->left);
		invertTree(root->right);

		return root;
	}
};

// ջ
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr){
			return root;
		}

		stack<TreeNode*> st;
		st.push(root);
		TreeNode* node = root;
		while (!st.empty()){
			node = st.top();
			st.pop();
			TreeNode* temp = node->left;
			node->left = node->right;
			node->right = temp;
			if (node->left){
				st.push(node->left);
			}
			if (node->right){
				st.push(node->right);
			}
		}
		return root;
	}
};