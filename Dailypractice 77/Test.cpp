// �������к�Ϊĳһֵ��·������ָOffer 34��
// ����һ�Ŷ�������һ������
// ��ӡ���������нڵ�ֵ�ĺ�Ϊ��������������·��
// �����ĸ��ڵ㿪ʼ����һֱ��Ҷ�ڵ��������Ľڵ��γ�һ��·��

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ǰ�����һ����ȡ���ж������д�root��Ҷ�ӽ���·��
// ����·���Ͻ��ĺ���sum�Ƚ�

class Solution {
public:
	vector<vector<int>> ret;
	vector<int> temp;

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		// ������ֱ�ӷ���
		if (root == nullptr){
			return vector<vector<int>>();
		}

		dfs(root, sum);
		return ret;
	}

	void dfs(TreeNode* root, int sum){
		if (root == nullptr){
			return;
		}

		temp.push_back(root->val);
		sum = sum - root->val;

		if (sum == 0 && root->left == nullptr && root->right == nullptr){
			ret.push_back(temp);
		}

		dfs(root->left, sum);
		dfs(root->right, sum);
		// ÿ���л�·����Ҫ������ǰtemp��ĩ��Ԫ��
		temp.pop_back();
	}
};