// 014：回文链表
// 请判断一个链表是否为回文链表。
// 输入: 1->2  输出: false
// 输入: 1->2->2->1  输出: true

#include<iostream>
#include<list>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 出入栈
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		stack<int> st;
		ListNode* cur = head;
		// 入栈
		while (cur){
			st.push(cur->val);
			cur = cur->next;
		}
		// 出栈比较
		cur = head;
		while (!st.empty()){
			if (st.top() == cur->val){
				st.pop();
				cur = cur->next;
			}
			else{
				return false;
			}
		}
		return true;
	}
};

// 双指针
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		// 空链表或链表只有一个结点也属于回文链表
		if (!head || !head->next){
			return true;
		}
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* cur = nullptr;
		ListNode* prev = nullptr;
		// 前后指针遍历翻转前一半链表
		while (fast && fast->next){
			cur = slow;
			slow = slow->next;
			fast = fast->next->next;
			cur->next = prev;
			prev = cur;
		}
		// 奇数个结点时跳过中间节点
		// 不能用fast->next == nullptr判断（fast有可能为nullptr）
		if (fast){
			slow = slow->next;
		}

		// 前后部分进行比较
		while (cur){
			if (cur->val != slow->val){
				return false;
			}
			cur = cur->next;
			slow = slow->next;
		}
		return true;
	}
};