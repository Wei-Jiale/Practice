// ƽ�����������ָOffer 55��
// ����һ�ö������ĸ��ڵ㣬�жϸ����ǲ���ƽ�������
// ƽ������������������߶Ȳ�ľ���ֵ������1

#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ����һ���Ӷ�����
// ����ڶ����㱻�ظ�������ȱ��
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (root == nullptr)
			return true;
		int leftdepth = maxDepth(root->left);
		int rightdepth = maxDepth(root->right);

		int diff = leftdepth - rightdepth;
		if (diff>1 || diff <-1){
			return false;
		}
		return isBalanced(root->left) && isBalanced(root->right);
	}

	// ����������
	int maxDepth(TreeNode* root){
		if (root == nullptr)
			return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

// ��������
// �ú�������ķ�ʽ������������ÿ�����
// �ڱ���ĳ���������ӽ�֮�󣬾Ϳ��Ը��������ӽ�������ж����ǲ���ƽ��ģ����õ���ǰ�������
// �Ϳ���һ�߱���һ���ж�ÿ������ǲ���ƽ���

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		int depth = 0;
		return helpBalanced(root, &depth);
	}

	bool helpBalanced(TreeNode* root, int* depth){
		if (root == nullptr){
			*depth = 0;
			return true;
		}

		int left, right;
		if (helpBalanced(root->left, &left) && helpBalanced(root->right, &right)){
			int diff = left - right;
			if (diff <= 1 && diff >= -1){
				*depth = 1 + (left>right ? left : right);
				return true;
			}
		}
		return false;
	}
};