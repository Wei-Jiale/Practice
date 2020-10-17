// 二叉树的镜像（剑指Offer 27）
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
	TreeNode* mirrorTree(TreeNode* root) {
		// 空树或只有一个结点的树直接返回根
		if (root == nullptr || (root->left == nullptr && root->right == nullptr))
			return root;

		// 交换当前结点的左右子树
		SwapNode(root);

		// 递归左右
		mirrorTree(root->left);
		mirrorTree(root->right);

		return root;
	}

	void SwapNode(TreeNode* Node){
		if (Node == nullptr || (Node->left == nullptr && Node->right == nullptr))
			return;

		TreeNode* temp = Node->left;
		Node->left = Node->right;
		Node->right = temp;
	}
};
