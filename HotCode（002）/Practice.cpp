// HotCode 002：两数相加

#include<iostream>
#include<list>
using namespace std;

// 方法一：对应相加
// 对应位的和为 x1+x2+carry
// 当前位的值为（x1+x2+carry）% 10，新的进位值为（x1+x2+carry）/ 10
// 若链表遍历结束，carry>0，则需要在结果链表后追加一个值为carry的结点

// 构建链表的结点
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// 定义结果链表 与 进位值
		ListNode* head = nullptr;
		ListNode* cur = nullptr;
		int carry = 0;

		// 遍历两个链表
		while (l1 || l2) {
			// 当l1、l2不为空时再取出它们的val,否则默认为0。
			int l1_val = l1 ? l1->val : 0;
			int l2_val = l2 ? l2->val : 0;
			int val_sum = l1_val + l2_val + carry;

			// 判断是否为第一次运算
			if (head == nullptr) {
				// 构建head和cur结点
				head = cur = new ListNode(val_sum % 10);
			}
			else {
				// 构建cur的下一个结点
				cur->next = new ListNode(val_sum % 10);
				cur = cur->next;
			}
			carry = val_sum / 10;
			
			// 链表向后遍历
			if (l1) {
				l1 = l1->next;
			}
			if (l2) {
				l2 = l2->next;
			}
		}

		if (carry != 0) {
			cur->next = new ListNode(carry);
		}

		return head;
	}
};

int main() {
	ListNode* l1 = new ListNode(0);
	ListNode* cur1 = new ListNode(1);
	l1->next = cur1;
	ListNode* cur2 = new ListNode(2);
	cur1->next = cur2;

	ListNode* l2 = new ListNode(0);
	ListNode* prev1 = new ListNode(1);
	l2->next = prev1;
	ListNode* prev2 = new ListNode(2);
	prev1->next = prev2;
	
	Solution func;
	ListNode* ret = func.addTwoNumbers(l1, l2);
	
	while (ret) {
		cout << ret->val;
		ret = ret->next;
	}

	return 0;
}