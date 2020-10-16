// 合并两个排序的链表（剑指Offer 25）
// 输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是递增排序的。

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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		// 注意两链表可能为空的情况
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;

		ListNode* ret = new ListNode(INT_MAX);
		ListNode* cur = ret;

		// 两链表都不为空
		while (l1 && l2){
			if (l1->val < l2->val){
				cur->next = l1;
				l1 = l1->next;
			}
			else{
				cur->next = l2;
				l2 = l2->next;
			}

			cur = cur->next;
		}

		// 其中一个链表为空
		if (l1 == nullptr){
			cur->next = l2;
		}
		else{
			cur->next = l1;
		}

		return ret->next;
	}
};