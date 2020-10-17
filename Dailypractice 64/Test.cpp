// 树的子结构（剑指Offer 26）
// 输入两颗二叉树A和B，判断B是不是A的子结构。
// 子结构：A中有一部分子树的结构和B是一样的，因此B是A的子结构。

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
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (A == nullptr || B == nullptr)
			return false;

		bool ret = false;
		// 在A中寻找与B根节点相同的值
		if (A->val == B->val)
			ret = doesAHaveB(A, B);

		// 若匹配不到，A遍历到左子树
		if (ret == false)
			ret = isSubStructure(A->left, B);

		// 若匹配不到，A遍历到右子树
		if (ret == false)
			ret = isSubStructure(A->right, B);

		return ret;
	}

	bool doesAHaveB(TreeNode* Ra, TreeNode* Rb){
		// Rb为空，则B树匹配完毕
		if (Rb == nullptr)
			return true;

		// Ra为空，则A树已匹配完毕
		if (Ra == nullptr)
			return false;

		if (Ra->val != Rb->val)
			return false;

		return doesAHaveB(Ra->left, Rb->left) && doesAHaveB(Ra->right, Rb->right);
	}
};