// HotCode 002���������

#include<iostream>
#include<list>
using namespace std;

// ����һ����Ӧ���
// ��Ӧλ�ĺ�Ϊ x1+x2+carry
// ��ǰλ��ֵΪ��x1+x2+carry��% 10���µĽ�λֵΪ��x1+x2+carry��/ 10
// ���������������carry>0������Ҫ�ڽ�������׷��һ��ֵΪcarry�Ľ��

// ��������Ľ��
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// ���������� �� ��λֵ
		ListNode* head = nullptr;
		ListNode* cur = nullptr;
		int carry = 0;

		// ������������
		while (l1 || l2) {
			// ��l1��l2��Ϊ��ʱ��ȡ�����ǵ�val,����Ĭ��Ϊ0��
			int l1_val = l1 ? l1->val : 0;
			int l2_val = l2 ? l2->val : 0;
			int val_sum = l1_val + l2_val + carry;

			// �ж��Ƿ�Ϊ��һ������
			if (head == nullptr) {
				// ����head��cur���
				head = cur = new ListNode(val_sum % 10);
			}
			else {
				// ����cur����һ�����
				cur->next = new ListNode(val_sum % 10);
				cur = cur->next;
			}
			carry = val_sum / 10;
			
			// ����������
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