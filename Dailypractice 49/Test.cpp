// ��β��ͷ��ӡ������ָOffer 6��
// ����һ�������ͷ��㣬��β��ͷ��ӡ����ÿ������ֵ��

// ����˼·��
// �����������ͷ�����������ȱ����ĺ��ӡ������ջʵ�֡�

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		// ����ջ�ȱ����ĺ��ӡ
		stack<ListNode*> st;
		vector<int> v;
		ListNode* cur = head;
		while (cur){
			st.push(cur);
			cur = cur->next;
		}

		while (!st.empty()){
			ListNode* top = st.top();
			v.push_back(top->val);
			st.pop();
		}

		return v;
	}
};