// ���ϵ��´�ӡ����������ָOffer 32��
// ���ϵ��´�ӡ��������ÿ����㣬ͬһ��Ľ�㰴�մ����ҵ�˳���ӡ��

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// �����ӡ�ȴ�ӡ���ڵ㣬�Ӹ��ڵ㿪ʼ������
// ��ӡ��ǰ����ʱ�򣬽��ý������ҽڵ����������

class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {
		// �����ڵ�Ϊ����ֱ�ӷ���
		if (root == nullptr)
			return vector<int>();

		// ��������
		vector<int> ret;
		// ��������
		queue<TreeNode*> quTree;

		quTree.push(root);

		while (!quTree.empty()){
			// Ϊ��֮�������ǰ�������ҽ������Ҫ��ʱ���浱ǰ���
			TreeNode* temp = quTree.front();

			// ��ӡ����������
			ret.push_back(quTree.front()->val);
			quTree.pop();

			if (temp->left != nullptr)
				quTree.push(temp->left);
			if (temp->right != nullptr)
				quTree.push(temp->right);
		}

		return ret;
	}
};