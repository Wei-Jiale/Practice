// 031���������ĺ������
// ����һ�����������������ĺ��������

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// �ݹ�
class Solution {
public:
	vector<int> vec;
	vector<int> postorderTraversal(TreeNode* root) {
		if (root == nullptr){
			return vec;
		}
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		vec.push_back(root->val);

		return vec;
	}
};

// ����
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> vec;
		stack<TreeNode*> st;
		st.push(root);

		// �� �� ��
		// ��ǰ������� �� �� ��˳����Ե���
		while (!st.empty()){
			TreeNode* node = st.top();
			st.pop();
			if (node != nullptr) vec.push_back(node->val);
			else continue;
			// ����ǰ����ջ˳��
			st.push(node->left);
			st.push(node->right);
		}
		// ��תvec
		reverse(vec.begin(), vec.end());
		return vec;
	}
};