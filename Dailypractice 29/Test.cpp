// 029����������ǰ�����
// ����һ������������������ǰ�������

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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		traversal(root, result);
		return result;
	}
	// ȷ���ݹ麯���Ĳ����ͷ���ֵ����ΪҪ��ӡ��ǰ������ڵ����ֵ������vector��Žڵ����ֵ��
	void traversal(TreeNode* cur, vector<int>& vec) {
		// ȷ����ֹ��������ǰ�����Ľڵ��ǿ��ˣ���ô����ݹ��ҪҪ�����ˡ�
		if (cur == nullptr) return;
		// ȷ������ݹ���߼���ǰ������������ҵ�ѭ��
		vec.push_back(cur->val);    // ��
		traversal(cur->left, vec);  // ��
		traversal(cur->right, vec); // ��
	}
};

// ����
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		// ����ջ���б���
		stack<TreeNode*> st;
		st.push(root);
		// ��ű����Ľ��
		vector<int> result;
		while (!st.empty()) {
			TreeNode* node = st.top();
			st.pop();
			// ȡ��ջ��Ԫ�ؽ����ж�
			if (node != nullptr) result.push_back(node->val);
			else continue;
			st.push(node->right);
			st.push(node->left);
		}
		return result;
	}
};