// 从上到下打印二叉树（剑指Offer 32）
// 从上到下打印二叉树的每个结点，同一层的结点按照从左到右的顺序打印。

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 按层打印先打印根节点，从根节点开始分析。
// 打印当前结点的时候，将该结点的左右节点放入容器。

class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {
		// 当根节点为空则直接返回
		if (root == nullptr)
			return vector<int>();

		// 返回容器
		vector<int> ret;
		// 辅助容器
		queue<TreeNode*> quTree;

		quTree.push(root);

		while (!quTree.empty()){
			// 为了之后操作当前结点的左右结点则需要临时保存当前结点
			TreeNode* temp = quTree.front();

			// 打印结束出队列
			ret.push_back(quTree.front()->val);
			quTree.pop();

			if (temp->left != nullptr)
				quTree.push(temp->left);
			if (temp->right != nullptr)
				quTree.push(temp->right);
		}

		return ret;
	}
};