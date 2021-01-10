// HotCode 010：删除链表的倒数第 n 个结点

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x):val(x),next(nullptr){}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		// 方便处理删除头结点的情况需要设置虚拟结点
		ListNode* FakeNode = new ListNode(0);
		FakeNode->next = head;

		ListNode* slowptr = FakeNode;
		ListNode* fastptr = FakeNode;

		// 快指针先走n+1步
		while (n-- && fastptr) {
			fastptr = fastptr->next;
		}
		fastptr = fastptr->next;

		// 快慢指针一起走
		while (fastptr) {
			slowptr = slowptr->next;
			fastptr = fastptr->next;
		}
		// slow会指向删除结点的上一个结点
		slowptr->next = slowptr->next->next;

		return FakeNode->next;
    }
};