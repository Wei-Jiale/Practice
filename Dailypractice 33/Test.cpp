// 033��ƽ�������
// ����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
// ���������߶Ȳ���� 1
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution {
public:
	int height(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		else {
			return max(height(root->left), height(root->right)) + 1;
		}
	}

	bool isBalanced(TreeNode* root) {
		if (root == nullptr) {
			return true;
		}
		else {
			return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
		}
	}
};