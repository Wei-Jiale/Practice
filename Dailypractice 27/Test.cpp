// 027：相同的树
// 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
// 如果两个二叉树都为空，则两个二叉树相同。如果两个二叉树中有且只有一个为空，则两个二叉树一定不相同。

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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		// 两树都为空则返回true
		if (p == nullptr && q == nullptr){
			return true;
		}
		// 两树有且只有一个为空则返回false
		if (p == nullptr || q == nullptr){
			return false;
		}

		return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};

// 广度优先搜索
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		// 两树都为空则返回true
		if (p == nullptr && q == nullptr){
			return true;
		}
		// 两树有且只有一个为空则返回false
		if (p == nullptr || q == nullptr){
			return false;
		}
		// 将根节点分别加入队列
		queue<TreeNode*> q1;
		q1.push(p);
		queue<TreeNode*> q2;
		q2.push(q);

		// 每次从两个队列各取出一个节点比较
		while (!q1.empty() && !q2.empty()){
			auto node1 = q1.front();
			auto node2 = q2.front();
			q1.pop();
			q2.pop();
			if (node1->val != node2->val) {
				return false;
			}
			// 遍历node1的左右和node2的左右
			auto left1 = node1->left, right1 = node1->right, left2 = node2->left, right2 = node2->right;
			// 判断两个结点的左右孩子是否为空
			if (left1 == nullptr ^ left2 == nullptr){
				return false;
			}
			if (right1 == nullptr ^ right2 == nullptr){
				return false;
			}
			// 向队列中添加新的结点
			if (left1) q1.push(left1);
			if (left2) q2.push(left2);
			if (right1) q1.push(right1);
			if (right2) q2.push(right2);
		}
		return q1.empty() && q2.empty();
	}
};