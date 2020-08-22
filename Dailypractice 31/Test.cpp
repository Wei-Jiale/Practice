// 031：二叉树的后序遍历
// 给定一个二叉树，返回它的后序遍历。

#include<iostream>
#include<vector>
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
	vector<int> vec;
	vector<int> postorderTraversal(TreeNode* root) {
		if (root == nullptr){
			return vec;
		}
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		vec.push_back(root->val);

		return vec;
	}
};

// 迭代
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> vec;
		stack<TreeNode*> st;
		st.push(root);

		// 左 右 中
		// 将前序遍历中 左 右 的顺序加以调整
		while (!st.empty()){
			TreeNode* node = st.top();
			st.pop();
			if (node != nullptr) vec.push_back(node->val);
			else continue;
			// 调整前序入栈顺序
			st.push(node->left);
			st.push(node->right);
		}
		// 翻转vec
		reverse(vec.begin(), vec.end());
		return vec;
	}
};