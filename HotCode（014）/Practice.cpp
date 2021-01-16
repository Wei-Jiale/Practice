// HotCode 014：合并n个升序链表

#include<iostream>
#include<vector>
using namespace std;

typedef struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
}ListNode;

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		// 分治策略
		return DivideAndMerge(lists, 0, lists.size() - 1); 
	}

	ListNode* DivideAndMerge(vector<ListNode*>& lists, int left, int right) {
		// 将输入的链表每一次都一分为二，直到不能再分时进行归并。
		if (left == right) {
			return lists[left];
		}
		if (left > right) {
			return nullptr;
		}

		int middle = (left + right) / 2;

		return MergeTwoLists(DivideAndMerge(lists, left, middle), DivideAndMerge(lists, middle + 1, right));
	}

	ListNode* MergeTwoLists(ListNode* list1, ListNode* list2) {
		// 合并两链表
		ListNode* prev = new ListNode(0);
		ListNode* cur = prev;

		while (list1 && list2) {
			if (list1->val < list2->val) {
				cur->next = list1;
				list1 = list1->next;
				cur = cur->next;
			}
			else {
				cur->next = list2;
				list2 = list2->next;
				cur = cur->next;
			}
		}

		if (list1 == nullptr) {
			cur->next = list2;
		}
		else {
			cur->next = list1;
		}

		return prev->next;
		
	}
};