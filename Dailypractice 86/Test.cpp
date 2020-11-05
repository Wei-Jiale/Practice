// ����������ཻ��㣨��ָOffer 52��
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr){
			return nullptr;
		}

		// ��ͷ��β�����������������ĳ��Ȳ�ֵ
		int listA = 0;
		int listB = 0;

		ListNode* curA = headA;
		ListNode* curB = headB;

		while (curA){
			listA++;
			curA = curA->next;
		}
		while (curB){
			listB++;
			curB = curB->next;
		}

		curA = headA;
		curB = headB;

		if (listB > listA){
			swap(listA, listB);
			swap(curA, curB);
		}

		int dif = listA - listB;

		// A��
		while (dif--){
			curA = curA->next;
		}

		// һ����
		while (curA){
			if (curA == curB){
				return curA;
			}

			curA = curA->next;
			curB = curB->next;
		}

		return nullptr;
	}
};