// 二叉树的最大深度（剑指Offer 55)

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
	int maxDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;

		// 使用层序遍历+计数器求二叉树的最大深度
		queue<TreeNode*> qu;
		int depth = 0;
		qu.push(root);
		// 当前层结点数量
		int level = 1;
		// 下一层结点数量
		int nextlevel = 0;

		while (!qu.empty()){
			depth++;

			while (level){
				TreeNode* node = qu.front();
				qu.pop();

				if (node->left){
					qu.push(node->left);
					nextlevel++;
				}
				if (node->right){
					qu.push(node->right);
					nextlevel++;
				}

				level--;
			}

			level = nextlevel;
			nextlevel = 0;
		}

		return depth;
	}
};