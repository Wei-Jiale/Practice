// 对称的二叉树（剑指Offer 28）

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr)
			return true;
		// 左右子树进行对比
		return Judge(root->left, root->right);
	}

	bool Judge(TreeNode* Rleft, TreeNode* Rright){
		// 都为空则对称
		if (Rleft == nullptr && Rright == nullptr)
			return true;
		// 任意一个不为空
		if (Rleft == nullptr || Rright == nullptr)
			return false;
		// 左右子树都存在且值不相等
		if (Rleft->val != Rright->val)
			return false;

		return Judge(Rleft->left, Rright->right) && Judge(Rleft->right, Rright->left);
	}
};