// 030�����������������
// ����һ���������������������������
// ��������������ң��ȷ��ʵ��Ƕ����������Ľڵ㣬���ȴ�����Ƕ�������
// ����˳��ͷ���˳���ǲ�һ�µġ�

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
	// ����ȫ��vector��ű������
	vector<int> vec;
	vector<int> inorderTraversal(TreeNode* root) {
		if (root){
			if(root->left) inorderTraversal(root->left);
			vec.push_back(root->val);
			if(root->right) inorderTraversal(root->right);
		}
		return vec;
	}
};

// ����
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		// ����vector��ű������
		vector<int> vec;
		// ����ջ������
		stack<TreeNode*> st;
		TreeNode* node = root;

		// �� �� ��
		while (node != nullptr || !st.empty()){
			if (node != nullptr){
				st.push(node);
				node = node->left;
			}
			else{
				node = st.top();
				st.pop();
				vec.push_back(node->val);
				node = node->right;
			}
		}
		return vec;
	}
};