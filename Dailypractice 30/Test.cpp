// 030：二叉树的中序遍历
// 给定一个二叉树，返回它的中序遍历。
// 中序遍历是左中右，先访问的是二叉树顶部的节点，而先处理的是二叉树左。
// 处理顺序和访问顺序是不一致的。

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
	// 设置全局vector存放遍历结点
	vector<int> vec;
	vector<int> inorderTraversal(TreeNode* root) {
		if (root){
			if(root->left) inorderTraversal(root->left);
			vec.push_back(root->val);
			if(root->right) inorderTraversal(root->right);
		}
		return vec;
	}
};

// 迭代
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		// 设置vector存放遍历结点
		vector<int> vec;
		// 设置栈遍历树
		stack<TreeNode*> st;
		TreeNode* node = root;

		// 左 根 右
		while (node != nullptr || !st.empty()){
			if (node != nullptr){
				st.push(node);
				node = node->left;
			}
			else{
				node = st.top();
				st.pop();
				vec.push_back(node->val);
				node = node->right;
			}
		}
		return vec;
	}
};