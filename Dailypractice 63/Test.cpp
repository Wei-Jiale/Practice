// �ϲ����������������ָOffer 25��
// ����������������������ϲ�����������ʹ�������еĽ����Ȼ�ǵ�������ġ�

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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		// ע�����������Ϊ�յ����
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;

		ListNode* ret = new ListNode(INT_MAX);
		ListNode* cur = ret;

		// ��������Ϊ��
		while (l1 && l2){
			if (l1->val < l2->val){
				cur->next = l1;
				l1 = l1->next;
			}
			else{
				cur->next = l2;
				l2 = l2->next;
			}

			cur = cur->next;
		}

		// ����һ������Ϊ��
		if (l1 == nullptr){
			cur->next = l2;
		}
		else{
			cur->next = l1;
		}

		return ret->next;
	}
};