// 008：移除链表元素
// 删除链表中等于给定值 val 的所有节点

#include<iostream>
#include<list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 设置哨兵结点：待删结点之前一个结点指向待删结点之后一个结点即可
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		// 判断头结点是否为空
		if (!head){
			return nullptr;
		}
		// 设置哨兵结点位于头结点的前驱结点
		ListNode* prev = new ListNode(0);
		prev->next = head;
		ListNode* cur = prev;
		while (cur->next){
			if (cur->next->val == val){
				cur->next = cur->next->next;
			}
			else{
				cur = cur->next;
			}
		}
		return prev->next;
	}
};

// 递归
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (!head){
			return nullptr;
		}
		head->next = removeElements(head->next, val);
		return head->val == val ? head->next : head;
	}
};