// 025����������������
// �����������Ϊ���ڵ㵽��ԶҶ�ӽ���ϵ��·���ϵĽ����
#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// �����������
class Solution {
public:
	int maxDepth(TreeNode* root) {
		// �����ĸ߶�Ϊ0
		if (root == nullptr){
			return 0;
		}

		queue<TreeNode*> q;
		q.push(root);
		int ret = 0;
		TreeNode* node = root;

		while (!q.empty()){
			// ���в�Ϊ����Ե�ǰ��һ������н����б���
			int sz = q.size();
			while (sz--){
				// ���ҽ�㶼�������
				node = q.front();
				q.pop();
				if (node->left){
					q.push(node->left);
				}
				if (node->right){
					q.push(node->right);
				}
			}
			ret++;
		}
		return ret;
	}
};

// �ݹ�
class Solution {
public:
	int maxDepth(TreeNode* root) {
		// �����ĸ߶�Ϊ0
		if (root == nullptr){
			return 0;
		}
		// �ݹ鵽root����������������
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};