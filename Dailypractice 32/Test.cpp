// 032：另一个树的子树
// 给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
// s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool dfs(TreeNode* s, TreeNode* t){
		if (s == nullptr && t == nullptr){
			return true;
		}
		// t非空
		if ((s &&!t) || (!s&&t) || (s->val != t->val)){
			return false;
		}
		return dfs(s->left, t->left) && dfs(s->right, t->right);
	}
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (s == nullptr){
			return false;
		}

		// 在树s的每个结点上检查，以该节点为根节点是否包含树t
		return dfs(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
	}
};