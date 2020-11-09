// �����������ĵ�k���㣨��ָOffer 54��
// ���룺root = [3,1,4,null,2], k = 1
// �����4

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// �ݹ鷴���򣬼����жϣ�����˳�
class Solution {
public:
	// ������������k�Ƚ�
	int count = 0;
	int ret = 0;

	int kthLargest(TreeNode* root, int k) {
		TreeKnode(root, k);
		return ret;
	}

	void TreeKnode(TreeNode* root, int k){
		if (root == nullptr){
			return;
		}

		TreeKnode(root->right, k);
		count++;

		if (count == k){
			// ����ǰ����ֵ��ֵ��ret
			ret = root->val;
			return;
		}

		TreeKnode(root->left, k);
	}
};