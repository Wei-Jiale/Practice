// 024����ֵ������
// ���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������

#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ����һ���ݹ�
class Solution {
public:
	bool isUnivalTree(TreeNode* root) {
		// �����ڵ��ֵ���������Ϊ�Աȵ�����
		return isVaild(root, root->val);
	}

	bool isVaild(TreeNode* root, int n){
		if (!root)
			return true;
		if (root->val != n)
			return false;
		return isVaild(root->left, n) && isVaild(root->right, n);
	}
};

// ��������ջ
class Solution {
public:
	bool isUnivalTree(TreeNode* root) {
		if (root == nullptr){
			return true;
		}
		// ѹ��ջ�еľ��Ƕ������ĸ������
		stack<TreeNode*> s;
		// ��ѹ�����㲢�һ�ø�����ֵ
		s.push(root);
		int val = root->val;
		// tmp���ڻ�ȡÿ�ε�ջ��Ԫ��
		TreeNode* tmp = root;
		while (!s.empty()){
			tmp = s.top();
			s.pop();
			if (tmp->val != val)
				return false;
			if (tmp->left)
				s.push(tmp->left);
			if (tmp->right)
				s.push(tmp->right);
		}
		return true;
	}
};