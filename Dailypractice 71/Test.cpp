// 分行从上到下打印二叉树（剑指Offer 32）
// 从上到下分层打印二叉树
// 同一层的结点按从左到右的顺序进行打印，每一层打印到一行。

#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		// 当根结点为空时
		if (root == nullptr)
			return vector<vector<int>>();

		// 返回容器
		vector<vector<int>> ret;
		// 辅助容器
		vector<int> help;
		queue<TreeNode*> quTree;
		// 记录当前层和下一层的结点数量
		int level = 1;
		int nextlevel = 0;

		quTree.push(root);

		while (!quTree.empty()){
			TreeNode* temp = quTree.front();
			help.push_back(temp->val);
			quTree.pop();
			level--;

			if (temp->left){
				quTree.push(temp->left);
				nextlevel++;
			}
			if (temp->right){
				quTree.push(temp->right);
				nextlevel++;
			}

			// 当前层元素全部打印完成
			if (level == 0){
				ret.push_back(help);
				help.clear();
				level = nextlevel;
				nextlevel = 0;
			}
		}
		return ret;
	}
};