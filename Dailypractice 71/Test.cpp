// ���д��ϵ��´�ӡ����������ָOffer 32��
// ���ϵ��·ֲ��ӡ������
// ͬһ��Ľ�㰴�����ҵ�˳����д�ӡ��ÿһ���ӡ��һ�С�

#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		// �������Ϊ��ʱ
		if (root == nullptr)
			return vector<vector<int>>();

		// ��������
		vector<vector<int>> ret;
		// ��������
		vector<int> help;
		queue<TreeNode*> quTree;
		// ��¼��ǰ�����һ��Ľ������
		int level = 1;
		int nextlevel = 0;

		quTree.push(root);

		while (!quTree.empty()){
			TreeNode* temp = quTree.front();
			help.push_back(temp->val);
			quTree.pop();
			level--;

			if (temp->left){
				quTree.push(temp->left);
				nextlevel++;
			}
			if (temp->right){
				quTree.push(temp->right);
				nextlevel++;
			}

			// ��ǰ��Ԫ��ȫ����ӡ���
			if (level == 0){
				ret.push_back(help);
				help.clear();
				level = nextlevel;
				nextlevel = 0;
			}
		}
		return ret;
	}
};