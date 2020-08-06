// 012���ϲ�������������
// ��������������ϲ�Ϊһ���µ� ���� �������ء�
// ��������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ� 
// ���룺1->2->4, 1->3->4
// �����1->1->2->3->4->4

#include<iostream>
#include<list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ����
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		// ����һ���ڱ���㣬���㷵�غϲ��������
		ListNode* creat = new ListNode(-1);
		ListNode* cur = creat;
		// l1��l2�ж�����Ԫ��
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
		// �ж�l1Ϊ�ջ���l2Ϊ��
		cur->next = l1 == nullptr ? l2 : l1;
		return creat->next;
	}
};

// �ݹ�
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr){
			return l2;
		}
		else if (l2 == nullptr){
			return l1;
		}
		else if (l1->val < l2->val){
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else{
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};