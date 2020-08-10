// 018：删除排序链表中的重复元素
// 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现的数字。
// 输入: 1->2->3->3->4->4->5
// 输出: 1->2->5

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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr){
			return nullptr;
		}
		// 创建哨兵结点，使得每个结点都有自己的前驱结点。
		ListNode* fake = new ListNode(-1);
		fake->next = head;
		ListNode* prev = fake;
		ListNode* back = head;
		ListNode* front = head->next;

		while (front){
			if (back->val != front->val){
				prev = back;
				back = front;
				front = front->next;
			}
			else{
				// front->val == back->val  front一直向后遍历
				while (front != nullptr && back->val == front->val){
					front = front->next;
				}
				// front走完或者back->val!=front->val
				prev->next = front;
				back = front;
				if (front != nullptr){
					front = front->next;
				}
			}
		}
		head = fake->next;
		return head;
	}
};