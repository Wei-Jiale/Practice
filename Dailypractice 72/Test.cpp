// 之字形打印二叉树（剑指Offer 32）
// 按之字形打印二叉树
// 第一层按照从左到右的顺序打印
// 第二层按照从右到左的顺序打印
// 第三层按照从左到右的顺序打印

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

// 利用deque容器，可以在两端都进行操作。
// 奇数层和偶数层的打印顺序不同，注意区分奇数层和偶数层。
// 还需要维护当前层结点数量和下一层结点数量。


class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		// 根节点为空
		if (root == nullptr)
			return vector<vector<int>>();

		// 返回容器
		vector<vector<int>> ret;
		// 辅助容器
		vector<int> help;
		deque<TreeNode*> deTree;

		// 定义当前层结点数和下一层结点数
		int level = 1;
		int nextlevel = 0;

		// 判断是否是奇数层（起始为第一层）
		bool flag = true;

		deTree.push_back(root);

		while (!deTree.empty()){
			// 奇数层
			if (flag){
				TreeNode* temp = deTree.front();
				help.push_back(temp->val);
				deTree.pop_front();
				level--;

				if (temp->left){
					deTree.push_back(temp->left);
					nextlevel++;
				}
				if (temp->right){
					deTree.push_back(temp->right);
					nextlevel++;
				}
			}
			// 偶数层
			else{
				TreeNode* temp = deTree.back();
				help.push_back(temp->val);
				deTree.pop_back();
				level--;

				if (temp->right){
					deTree.push_front(temp->right);
					nextlevel++;
				}
				if (temp->left){
					deTree.push_front(temp->left);
					nextlevel++;
				}
			}

			if (level == 0){
				ret.push_back(help);
				help.clear();
				level = nextlevel;
				nextlevel = 0;
				flag = !flag;
			}
		}

		return ret;
	}
};