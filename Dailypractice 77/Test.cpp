// 二叉树中和为某一值的路径（剑指Offer 34）
// 输入一颗二叉树和一个整数
// 打印出二叉树中节点值的和为输入整数的所有路径
// 从树的根节点开始往下一直到叶节点所经过的节点形成一条路径

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 前序遍历一次提取所有二叉树中从root到叶子结点的路径
// 并把路径上结点的和与sum比较

class Solution {
public:
	vector<vector<int>> ret;
	vector<int> temp;

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		// 空树则直接返回
		if (root == nullptr){
			return vector<vector<int>>();
		}

		dfs(root, sum);
		return ret;
	}

	void dfs(TreeNode* root, int sum){
		if (root == nullptr){
			return;
		}

		temp.push_back(root->val);
		sum = sum - root->val;

		if (sum == 0 && root->left == nullptr && root->right == nullptr){
			ret.push_back(temp);
		}

		dfs(root->left, sum);
		dfs(root->right, sum);
		// 每次切换路径都要弹出当前temp的末端元素
		temp.pop_back();
	}
};