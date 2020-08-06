// 012：合并两个有序链表
// 将两个升序链表合并为一个新的 升序 链表并返回。
// 新链表是通过拼接给定的两个链表的所有节点组成的。 
// 输入：1->2->4, 1->3->4
// 输出：1->1->2->3->4->4

#include<iostream>
#include<list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 迭代
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		// 设置一个哨兵结点，方便返回合并后的链表。
		ListNode* creat = new ListNode(-1);
		ListNode* cur = creat;
		// l1与l2中都还有元素
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
		// 判断l1为空还是l2为空
		cur->next = l1 == nullptr ? l2 : l1;
		return creat->next;
	}
};

// 递归
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr){
			return l2;
		}
		else if (l2 == nullptr){
			return l1;
		}
		else if (l1->val < l2->val){
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else{
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};