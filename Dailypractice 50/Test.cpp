// �ؽ�����������ָOffer 7��
// �����������ǰ����������������������ؽ��ö�������

// ����˼·��
// ǰ������ĵ�һ�������Ǹ��ڵ�
// ������������ø��ڵ㻮����������
// �õ��������������������У��Լ�����������ǰ��������

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		// �������
		if (preorder.empty() || preorder.size() != inorder.size())
			return nullptr;

		// ���ĸ�ָ����ɵݹ�
		int prestart = 0, instart = 0;
		int preend = preorder.size() - 1, inend = inorder.size() - 1;

		return binaryTree(preorder, inorder, prestart, preend, instart, inend);

	}

	TreeNode* binaryTree(vector<int>& preorder, vector<int>& inorder, int prestart, int preend, int instart, int inend){
		if (prestart>preend || instart>inend)
			return nullptr;
		// ȷ�������
		TreeNode* root = new TreeNode(preorder[prestart]);
		// �����������ȷ��������λ��
		int middle = 0;
		for (auto e : inorder){
			if (e != preorder[prestart])
				middle++;
			else
				break;
		}
		// �ݹ���������
		root->left = binaryTree(preorder, inorder, prestart + 1, prestart + middle - instart, instart, middle - 1);
		root->right = binaryTree(preorder, inorder, preend - (inend - middle) + 1, preend, middle + 1, inend);

		return root;
	}
};