// 反转链表
// 需要该表next指针的指向
// 首先定义一个cur指针指向头结点，再定义一个prev指针初始化为nullptr
// 每次需要将cur->next结点进行保存，因为每次都要改变cur->next的指向，指向prev
// 进行循环cur指向nullptr时，循环结束，返回prev

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 双指针
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		// 若链表为空则返回nullptr
		if (head == nullptr){
			return nullptr;
		}
		// 不为空则定义cur指针指向head，定义prev指针初始化为nullptr
		ListNode* cur = head;
		ListNode* prev = nullptr;
		// 循环反转
		while (cur){
			// 保存cur->next
			ListNode* temp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = temp;
		}
		// 返回结果
		return prev;
	}
};

