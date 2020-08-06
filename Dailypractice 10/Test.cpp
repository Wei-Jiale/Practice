// 010：链表的中间结点
// 给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
// 如果有两个中间结点，则返回第二个中间结点。
// 输入：[1,2,3,4,5,6]
// 输出：此列表中的结点 4 (序列化形式：[4,5,6])

#include<iostream>
#include<list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 双指针
// slow走一步，fast走两步，当fast到达链表末尾时，slow自然位于链表中间。
class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		// 注意判断条件
		while (fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
};

// 单指针
// 第一次遍历统计链表长度
// 第二次遍历返回链表中间结点
class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		ListNode* cur = head;
		int count = 0;
		// 统计链表长度
		while (cur){
			count++;
			cur = cur->next;
		}
		// 返回链表中间结点，注意此时需要将cur置为head
		cur = head;
		for (int i = 0; i < count / 2; i++){
			cur = cur->next;
		}
		return cur;
	}
};