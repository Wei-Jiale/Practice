// 009：反转链表
// 输入: 1->2->3->4->5->NULL
// 输出: 5->4->3->2->1->NULL

#include<iostream>
#include<list>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// 将原链表结点添加到新的链表中
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head){
			return nullptr;
		}
		// 新链表的最后
		ListNode* prev = nullptr;
		// 当前待添加结点
		ListNode* cur = head;
		while (cur){
			// 保存原cur->next
			ListNode* temp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = temp;
		}
		return prev;
	}
};

// 普通双指针
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head){
			return nullptr;
		}
		// 定义前后指针
		ListNode* prev = nullptr;
		ListNode* cur = head;
		while (cur){
			// 保存原cur->next
			ListNode* temp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = temp;
		}
		return prev;
	}
};

// 升级双指针
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head){
			return nullptr;
		}
		ListNode* cur = head;
		while (head->next){
			ListNode* temp = head->next->next;
			head->next->next = cur;
			cur = head->next;
			head->next = temp;
		}
		return cur;
	}
};