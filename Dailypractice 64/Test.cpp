// �����ӽṹ����ָOffer 26��
// �������Ŷ�����A��B���ж�B�ǲ���A���ӽṹ��
// �ӽṹ��A����һ���������Ľṹ��B��һ���ģ����B��A���ӽṹ��

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (A == nullptr || B == nullptr)
			return false;

		bool ret = false;
		// ��A��Ѱ����B���ڵ���ͬ��ֵ
		if (A->val == B->val)
			ret = doesAHaveB(A, B);

		// ��ƥ�䲻����A������������
		if (ret == false)
			ret = isSubStructure(A->left, B);

		// ��ƥ�䲻����A������������
		if (ret == false)
			ret = isSubStructure(A->right, B);

		return ret;
	}

	bool doesAHaveB(TreeNode* Ra, TreeNode* Rb){
		// RbΪ�գ���B��ƥ�����
		if (Rb == nullptr)
			return true;

		// RaΪ�գ���A����ƥ�����
		if (Ra == nullptr)
			return false;

		if (Ra->val != Rb->val)
			return false;

		return doesAHaveB(Ra->left, Rb->left) && doesAHaveB(Ra->right, Rb->right);
	}
};