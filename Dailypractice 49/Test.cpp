// 从尾到头打印链表（剑指Offer 6）
// 输入一个链表的头结点，从尾到头打印链表每个结点的值。

// 解题思路：
// 遍历单链表从头遍历，但是先遍历的后打印，借助栈实现。

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
		// 借助栈先遍历的后打印
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