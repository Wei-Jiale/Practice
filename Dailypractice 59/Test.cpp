// 删除链表中的结点（剑指Offer 18）
// 给定单向链表的头指针和一个结点指针，在O(1)时间内删除该结点。

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
	ListNode* deleteNode(ListNode* head, int val) {
		// 要删除链表中值为val的节点，那么递归终止条件即为head为空的时候，因为空的节点是无法删除的。
		if (head == nullptr){
			return head;
		}

		// 如果head不为空，同时head的值又等于val，返回它的下一个节点
		if (head->val == val){
			return head->next;
		}

		// 如果head不为空，同时head的值也不等于val，说明head不能删除，我们递归地去判断下一个节点的情况。
		head->next = deleteNode(head->next, val);

		return head;
	}
};