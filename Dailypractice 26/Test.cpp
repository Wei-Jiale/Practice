// 026：翻转二叉树
// 交换每个结点的左孩子和右孩子

#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr){
			return root;
		}

		// swap交换结点的左右孩子
		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;

		// 递归结点的左右子树
		invertTree(root->left);
		invertTree(root->right);

		return root;
	}
};

// 栈
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