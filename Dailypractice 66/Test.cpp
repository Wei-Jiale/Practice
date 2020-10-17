// �ԳƵĶ���������ָOffer 28��

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
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr)
			return true;
		// �����������жԱ�
		return Judge(root->left, root->right);
	}

	bool Judge(TreeNode* Rleft, TreeNode* Rright){
		// ��Ϊ����Գ�
		if (Rleft == nullptr && Rright == nullptr)
			return true;
		// ����һ����Ϊ��
		if (Rleft == nullptr || Rright == nullptr)
			return false;
		// ����������������ֵ�����
		if (Rleft->val != Rright->val)
			return false;

		return Judge(Rleft->left, Rright->right) && Judge(Rleft->right, Rright->left);
	}
};