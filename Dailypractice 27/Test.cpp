// 027����ͬ����
// ����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�
// ���������������Ϊ�գ���������������ͬ���������������������ֻ��һ��Ϊ�գ�������������һ������ͬ��

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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		// ������Ϊ���򷵻�true
		if (p == nullptr && q == nullptr){
			return true;
		}
		// ��������ֻ��һ��Ϊ���򷵻�false
		if (p == nullptr || q == nullptr){
			return false;
		}

		return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};

// �����������
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		// ������Ϊ���򷵻�true
		if (p == nullptr && q == nullptr){
			return true;
		}
		// ��������ֻ��һ��Ϊ���򷵻�false
		if (p == nullptr || q == nullptr){
			return false;
		}
		// �����ڵ�ֱ�������
		queue<TreeNode*> q1;
		q1.push(p);
		queue<TreeNode*> q2;
		q2.push(q);

		// ÿ�δ��������и�ȡ��һ���ڵ�Ƚ�
		while (!q1.empty() && !q2.empty()){
			auto node1 = q1.front();
			auto node2 = q2.front();
			q1.pop();
			q2.pop();
			if (node1->val != node2->val) {
				return false;
			}
			// ����node1�����Һ�node2������
			auto left1 = node1->left, right1 = node1->right, left2 = node2->left, right2 = node2->right;
			// �ж������������Һ����Ƿ�Ϊ��
			if (left1 == nullptr ^ left2 == nullptr){
				return false;
			}
			if (right1 == nullptr ^ right2 == nullptr){
				return false;
			}
			// �����������µĽ��
			if (left1) q1.push(left1);
			if (left2) q2.push(left2);
			if (right1) q1.push(right1);
			if (right2) q2.push(right2);
		}
		return q1.empty() && q2.empty();
	}
};