// ��ת������ָOffer 24��
// ���������ͷ��㣬��ת�����������ת�������ͷ��㡣

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
	ListNode* reverseList(ListNode* head) {
		// ����Ϊ�ջ�������ֻ��һ�����
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode* prev = nullptr;
		ListNode* cur = head;

		while (cur){
			// ���浱ǰ����next
			ListNode* temp = cur->next;
			// ��ǰ����nextָ��ǰ����prev
			cur->next = prev;
			prev = cur;
			cur = temp;
		}

		return prev;
	}
};