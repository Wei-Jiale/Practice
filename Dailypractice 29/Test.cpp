// 029：二叉树的前序遍历
// 给定一个二叉树，返回它的前序遍历。

#include<iostream>
#include<vector>
#include<stack>
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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		traversal(root, result);
		return result;
	}
	// 确定递归函数的参数和返回值：因为要打印出前序遍历节点的数值，传入vector存放节点的数值。
	void traversal(TreeNode* cur, vector<int>& vec) {
		// 确定终止条件：当前遍历的节点是空了，那么本层递归就要要结束了。
		if (cur == nullptr) return;
		// 确定单层递归的逻辑：前序遍历是中左右的循序。
		vec.push_back(cur->val);    // 中
		traversal(cur->left, vec);  // 左
		traversal(cur->right, vec); // 右
	}
};

// 迭代
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		// 利用栈进行遍历
		stack<TreeNode*> st;
		st.push(root);
		// 存放遍历的结点
		vector<int> result;
		while (!st.empty()) {
			TreeNode* node = st.top();
			st.pop();
			// 取出栈顶元素进行判断
			if (node != nullptr) result.push_back(node->val);
			else continue;
			st.push(node->right);
			st.push(node->left);
		}
		return result;
	}
};