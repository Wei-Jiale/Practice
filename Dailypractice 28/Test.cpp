// 028���Գƶ�����
// ����һ����������������Ƿ��Ǿ���ԳƵġ�
// ���ǵ���������������ͬ��ֵ
// ÿ������������������һ����������������Գ�

#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// �ݹ�
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr){
			return true;
		}
		return check(root->left, root->right);
	}

	// �������Ĳ���
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

// �����������
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) return true;
		// ��ƶ���
		queue<TreeNode*> que;
		// �����м���root�����Һ���
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