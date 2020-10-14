// ɾ�������е��ڸ���ֵval�����н��
// 1 2 6 3 4 5 6
// 1 2 3 4 5

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
	ListNode* removeElements(ListNode* head, int val) {
		// ͷ���Ϊ�ջ�ͷ����ֵ��Ϊval��ֻ��һ�������ֱ�ӷ���
		if (head == nullptr || (head->val == val && head->next == nullptr))
			return nullptr;

		ListNode* fake = new ListNode(5201314);
		fake->next = head;
		ListNode* prev = fake;

		while (prev && prev->next){
			ListNode* cur = prev->next;
			// ��cur��ֵ����val����prev��next������cur
			if (cur->val == val)
				prev->next = cur->next;
			// ��cur��ֵ������val����prev�͵�cur��λ��
			else
				prev = cur;
		}

		return fake->next;
	}
};
