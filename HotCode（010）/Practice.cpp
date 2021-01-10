// HotCode 010��ɾ������ĵ����� n �����

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
		// ���㴦��ɾ��ͷ���������Ҫ����������
		ListNode* FakeNode = new ListNode(0);
		FakeNode->next = head;

		ListNode* slowptr = FakeNode;
		ListNode* fastptr = FakeNode;

		// ��ָ������n+1��
		while (n-- && fastptr) {
			fastptr = fastptr->next;
		}
		fastptr = fastptr->next;

		// ����ָ��һ����
		while (fastptr) {
			slowptr = slowptr->next;
			fastptr = fastptr->next;
		}
		// slow��ָ��ɾ��������һ�����
		slowptr->next = slowptr->next->next;

		return FakeNode->next;
    }
};