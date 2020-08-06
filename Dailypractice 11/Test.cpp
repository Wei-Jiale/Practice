// 011：链表中倒数第k个结点（剑指offer 22）
// 输入一个链表，输出该链表中倒数第k个结点
// 输入：1->2->3->4->5, 和 k = 2
// 输出：4->5

#include<iostream>
#include<list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 双指针
class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode* slow = head;
		ListNode* fast = head;
		// 快指针先走k步
		// 有可能k>链表长度
		while (k-- && fast){
			fast = fast->next;
		}
		if (!fast){
			return head;
		}
		// 快慢指针一起走
		while (fast){
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};
