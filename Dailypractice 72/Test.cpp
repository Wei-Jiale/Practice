// ֮���δ�ӡ����������ָOffer 32��
// ��֮���δ�ӡ������
// ��һ�㰴�մ����ҵ�˳���ӡ
// �ڶ��㰴�մ��ҵ����˳���ӡ
// �����㰴�մ����ҵ�˳���ӡ

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

// ����deque���������������˶����в�����
// �������ż����Ĵ�ӡ˳��ͬ��ע�������������ż���㡣
// ����Ҫά����ǰ������������һ����������


class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		// ���ڵ�Ϊ��
		if (root == nullptr)
			return vector<vector<int>>();

		// ��������
		vector<vector<int>> ret;
		// ��������
		vector<int> help;
		deque<TreeNode*> deTree;

		// ���嵱ǰ����������һ������
		int level = 1;
		int nextlevel = 0;

		// �ж��Ƿ��������㣨��ʼΪ��һ�㣩
		bool flag = true;

		deTree.push_back(root);

		while (!deTree.empty()){
			// ������
			if (flag){
				TreeNode* temp = deTree.front();
				help.push_back(temp->val);
				deTree.pop_front();
				level--;

				if (temp->left){
					deTree.push_back(temp->left);
					nextlevel++;
				}
				if (temp->right){
					deTree.push_back(temp->right);
					nextlevel++;
				}
			}
			// ż����
			else{
				TreeNode* temp = deTree.back();
				help.push_back(temp->val);
				deTree.pop_back();
				level--;

				if (temp->right){
					deTree.push_front(temp->right);
					nextlevel++;
				}
				if (temp->left){
					deTree.push_front(temp->left);
					nextlevel++;
				}
			}

			if (level == 0){
				ret.push_back(help);
				help.clear();
				level = nextlevel;
				nextlevel = 0;
				flag = !flag;
			}
		}

		return ret;
	}
};