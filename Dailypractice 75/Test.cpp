// 平衡二叉树（剑指Offer 55）
// 输入一棵二叉树的根节点，判断该树是不是平衡二叉树
// 平衡二叉树的左右子树高度差的绝对值不超过1

#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 方法一：从顶到底
// 会存在多个结点被重复遍历的缺陷
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (root == nullptr)
			return true;
		int leftdepth = maxDepth(root->left);
		int rightdepth = maxDepth(root->right);

		int diff = leftdepth - rightdepth;
		if (diff>1 || diff <-1){
			return false;
		}
		return isBalanced(root->left) && isBalanced(root->right);
	}

	// 求二叉树深度
	int maxDepth(TreeNode* root){
		if (root == nullptr)
			return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

// 方法二：
// 用后序遍历的方式遍历二叉树的每个结点
// 在遍历某结点的左右子结之后，就可以根据左右子结点的深度判断它是不是平衡的，并得到当前结点的深度
// 就可以一边遍历一边判断每个结点是不是平衡的

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		int depth = 0;
		return helpBalanced(root, &depth);
	}

	bool helpBalanced(TreeNode* root, int* depth){
		if (root == nullptr){
			*depth = 0;
			return true;
		}

		int left, right;
		if (helpBalanced(root->left, &left) && helpBalanced(root->right, &right)){
			int diff = left - right;
			if (diff <= 1 && diff >= -1){
				*depth = 1 + (left>right ? left : right);
				return true;
			}
		}
		return false;
	}
};