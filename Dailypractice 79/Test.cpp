// ���л�����������ָOffer 37��
// ʵ�����������ֱ��������л��ͷ����л�������

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (root == nullptr){
			return "";
		}
		ostringstream out;
		queue<TreeNode*> qu;

		qu.push(root);
		while (!qu.empty()){
			TreeNode* temp = qu.front();
			qu.pop();
			if (temp){
				out << temp->val << " ";
				qu.push(temp->left);
				qu.push(temp->right);
			}
			else{
				out << "null ";
			}
		}
		// ����ת��Ϊ�ַ���
		return out.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.empty()){
			return nullptr;
		}

		istringstream in(data);
		string info;
		vector<TreeNode*> vc;

		while (in >> info){
			if (info == "null"){
				vc.push_back(nullptr);
			}
			else{
				vc.push_back(new TreeNode(stoi(info)));
			}
		}

		// ��vc�е�����Ԫ������������Ϊһ�Ŷ�����
		int pos = 1;
		for (int cur = 0; pos < vc.size(); cur++){
			if (vc[cur] == nullptr){
				continue;
			}

			vc[cur]->left = vc[pos++];
			if (pos < vc.size()){
				vc[cur]->right = vc[pos++];
			}
		}

		return vc[0];

	}
};