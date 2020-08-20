// 028：对称二叉树
// 给定一个二叉树，检查它是否是镜像对称的。
// 它们的两个根结点具有相同的值
// 每个树的右子树都与另一个树的左子树镜像对称

#include<iostream>
#include<queue>
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
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr){
			return true;
		}
		return check(root->left, root->right);
	}

	// 两个树的层面
	bool check(TreeNode* p, TreeNode* q){
		if (p == nullptr && q == nullptr){
			return true;
		}
		if (p == nullptr || q == nullptr){
			return false;
		}
		return (p->val == q->val) && check(p->left, q->right) && check(p->right, q->left);
	}
};

// 广度优先搜索
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) return true;
		// 设计队列
		queue<TreeNode*> que;
		// 队列中加入root的左右孩子
		que.push(root->left);
		que.push(root->right);
		while (!que.empty()) {
			TreeNode* leftNode = que.front(); que.pop();
			TreeNode* rightNode = que.front(); que.pop();
			if (leftNode == nullptr && rightNode == nullptr) {
				continue;
			}
			if ((leftNode == nullptr || rightNode == nullptr || (leftNode->val != rightNode->val))) {
				return false;
			}
			que.push(leftNode->left);
			que.push(rightNode->right);
			que.push(leftNode->right);
			que.push(rightNode->left);
		}
		return true;
	}
};