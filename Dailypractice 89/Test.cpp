// 二叉搜索树的第k大结点（剑指Offer 54）
// 输入：root = [3,1,4,null,2], k = 1
// 输出：4

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归反中序，计数判断，相等退出
class Solution {
public:
	// 计数器用来和k比较
	int count = 0;
	int ret = 0;

	int kthLargest(TreeNode* root, int k) {
		TreeKnode(root, k);
		return ret;
	}

	void TreeKnode(TreeNode* root, int k){
		if (root == nullptr){
			return;
		}

		TreeKnode(root->right, k);
		count++;

		if (count == k){
			// 将当前结点的值赋值给ret
			ret = root->val;
			return;
		}

		TreeKnode(root->left, k);
	}
};