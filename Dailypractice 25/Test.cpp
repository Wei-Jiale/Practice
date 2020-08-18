// 025：二叉树的最大深度
// 二叉树的深度为根节点到最远叶子结点上的最长路径上的结点数
#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 广度优先搜索
class Solution {
public:
	int maxDepth(TreeNode* root) {
		// 空树的高度为0
		if (root == nullptr){
			return 0;
		}

		queue<TreeNode*> q;
		q.push(root);
		int ret = 0;
		TreeNode* node = root;

		while (!q.empty()){
			// 队列不为空则对当前这一层的所有结点进行遍历
			int sz = q.size();
			while (sz--){
				// 左右结点都加入队列
				node = q.front();
				q.pop();
				if (node->left){
					q.push(node->left);
				}
				if (node->right){
					q.push(node->right);
				}
			}
			ret++;
		}
		return ret;
	}
};

// 递归
class Solution {
public:
	int maxDepth(TreeNode* root) {
		// 空树的高度为0
		if (root == nullptr){
			return 0;
		}
		// 递归到root的左子树和右子树
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};