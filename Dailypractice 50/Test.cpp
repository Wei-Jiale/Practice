// 重建二叉树（剑指Offer 7）
// 输入二叉树的前序遍历和中序遍历结果，请重建该二叉树。

// 解题思路：
// 前序遍历的第一个结点就是根节点
// 在中序遍历中用根节点划分左右子树
// 得到左右子树的中序子序列，以及左右子树的前序子序列

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		// 检查输入
		if (preorder.empty() || preorder.size() != inorder.size())
			return nullptr;

		// 用四个指针完成递归
		int prestart = 0, instart = 0;
		int preend = preorder.size() - 1, inend = inorder.size() - 1;

		return binaryTree(preorder, inorder, prestart, preend, instart, inend);

	}

	TreeNode* binaryTree(vector<int>& preorder, vector<int>& inorder, int prestart, int preend, int instart, int inend){
		if (prestart>preend || instart>inend)
			return nullptr;
		// 确定根结点
		TreeNode* root = new TreeNode(preorder[prestart]);
		// 在中序遍历中确定根结点的位置
		int middle = 0;
		for (auto e : inorder){
			if (e != preorder[prestart])
				middle++;
			else
				break;
		}
		// 递归左右子树
		root->left = binaryTree(preorder, inorder, prestart + 1, prestart + middle - instart, instart, middle - 1);
		root->right = binaryTree(preorder, inorder, preend - (inend - middle) + 1, preend, middle + 1, inend);

		return root;
	}
};