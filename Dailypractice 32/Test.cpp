// 032����һ����������
// ���������ǿն����� s �� t������ s ���Ƿ������ t ������ͬ�ṹ�ͽڵ�ֵ��������
// s ��һ���������� s ��һ���ڵ������ڵ���������s Ҳ���Կ����������һ��������

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool dfs(TreeNode* s, TreeNode* t){
		if (s == nullptr && t == nullptr){
			return true;
		}
		// t�ǿ�
		if ((s &&!t) || (!s&&t) || (s->val != t->val)){
			return false;
		}
		return dfs(s->left, t->left) && dfs(s->right, t->right);
	}
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (s == nullptr){
			return false;
		}

		// ����s��ÿ������ϼ�飬�Ըýڵ�Ϊ���ڵ��Ƿ������t
		return dfs(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
	}
};