// 015：相交链表
// 编写一个程序，找到两个单链表相交的起始节点。

#include<iostream>
#include<list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 求得链表长度
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr){
			return nullptr;
		}

		ListNode* curlong = headA;
		ListNode* curshort = headB;

		// 分别得到两链表长度
		int countlong = 0;
		int countshort = 0;
		while (headA){
			countlong++;
			headA = headA->next;
		}
		while (headB){
			countshort++;
			headB = headB->next;
		}

		// 判断长短链表
		int flag = 0;
		if (countlong < countshort){
			swap(countlong, countshort);
			flag = 1;
		}
		int length = countlong - countshort;

		// 长链表先走两链表差值的步数
		while (length--){
			if (flag == 0){
				curlong = curlong->next;
			}
			else{
				curshort = curshort->next;
			}
		}

		// 判断两链表结点地址是否相同
		while (curlong != curshort){
			curlong = curlong->next;
			curshort = curshort->next;
		}
		return curlong;
	}
};

// 双指针
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr){
			return nullptr;
		}

		// A的指针遍历完A，从B开始遍历。
		// B的指针遍历完B，从A开始遍历。
		// 两个指针最多都走m+n步。
		ListNode* cur_a = headA;
		ListNode* cur_b = headB;

		// 当两个指针同时为空时，表示不相交；当两个都非空且相等时，表示相交。
		while (cur_a != cur_b){
			cur_a = (cur_a ? cur_a->next : headB);
			cur_b = (cur_b ? cur_b->next : headA);
		}

		return cur_a;
	}
};