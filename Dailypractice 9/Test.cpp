// 009����ת����
// ����: 1->2->3->4->5->NULL
// ���: 5->4->3->2->1->NULL

#include<iostream>
#include<list>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// ��ԭ��������ӵ��µ�������
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head){
			return nullptr;
		}
		// ����������
		ListNode* prev = nullptr;
		// ��ǰ����ӽ��
		ListNode* cur = head;
		while (cur){
			// ����ԭcur->next
			ListNode* temp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = temp;
		}
		return prev;
	}
};

// ��ͨ˫ָ��
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head){
			return nullptr;
		}
		// ����ǰ��ָ��
		ListNode* prev = nullptr;
		ListNode* cur = head;
		while (cur){
			// ����ԭcur->next
			ListNode* temp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = temp;
		}
		return prev;
	}
};

// ����˫ָ��
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