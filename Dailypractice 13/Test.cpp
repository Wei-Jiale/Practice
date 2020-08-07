// 013：分隔链表
// 给定一个链表和一个特定值 x，对链表进行分隔。
// 使得所有小于 x 的节点都在大于或等于 x 的节点之前。
// 保留两个分区中每个节点的初始相对位置。
// 输入: head = 1->4->3->2->5->2, x = 3
// 输出: 1->2->2->4->3->5

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
	ListNode* partition(ListNode* head, int x) {
		// 定义两条链表，一条存储小于基准值的结点，一条存储大于基准值的结点。
		ListNode* low = new ListNode(-1);
		ListNode* high = new ListNode(-1);
		ListNode* lowcur = low;
		ListNode* highcur = high;

		// 先拆分原有链表，再合并新建链表。
		while (head){
			if (head->val < x){
				lowcur->next = head;
				lowcur = lowcur->next;
			}
			else{
				highcur->next = head;
				highcur = highcur->next;
			}
			head = head->next;
		}

		// 存储大于基准值的链表末尾需要指向nullptr
		highcur->next = nullptr;
		lowcur->next = high->next;
		return low->next;
	}
};