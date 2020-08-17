// 024：单值二叉树
// 如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。

#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 方法一：递归
class Solution {
public:
	bool isUnivalTree(TreeNode* root) {
		// 将根节点的值拿来标记作为对比的依据
		return isVaild(root, root->val);
	}

	bool isVaild(TreeNode* root, int n){
		if (!root)
			return true;
		if (root->val != n)
			return false;
		return isVaild(root->left, n) && isVaild(root->right, n);
	}
};

// 方法二：栈
class Solution {
public:
	bool isUnivalTree(TreeNode* root) {
		if (root == nullptr){
			return true;
		}
		// 压入栈中的就是二叉树的各个结点
		stack<TreeNode*> s;
		// 先压入根结点并且获得根结点的值
		s.push(root);
		int val = root->val;
		// tmp用于获取每次的栈顶元素
		TreeNode* tmp = root;
		while (!s.empty()){
			tmp = s.top();
			s.pop();
			if (tmp->val != val)
				return false;
			if (tmp->left)
				s.push(tmp->left);
			if (tmp->right)
				s.push(tmp->right);
		}
		return true;
	}
};