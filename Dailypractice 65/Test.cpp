// �������ľ��񣨽�ָOffer 27��
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
	TreeNode* mirrorTree(TreeNode* root) {
		// ������ֻ��һ��������ֱ�ӷ��ظ�
		if (root == nullptr || (root->left == nullptr && root->right == nullptr))
			return root;

		// ������ǰ������������
		SwapNode(root);

		// �ݹ�����
		mirrorTree(root->left);
		mirrorTree(root->right);

		return root;
	}

	void SwapNode(TreeNode* Node){
		if (Node == nullptr || (Node->left == nullptr && Node->right == nullptr))
			return;

		TreeNode* temp = Node->left;
		Node->left = Node->right;
		Node->right = temp;
	}
};
