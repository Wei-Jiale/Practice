// 反转链表（剑指Offer 24）
// 输入链表的头结点，反转该链表并输出反转后链表的头结点。

#include<iostream>
#include<list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		// 链表为空或链表中只有一个结点
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode* prev = nullptr;
		ListNode* cur = head;

		while (cur){
			// 保存当前结点的next
			ListNode* temp = cur->next;
			// 当前结点的next指向当前结点的prev
			cur->next = prev;
			prev = cur;
			cur = temp;
		}

		return prev;
	}
};