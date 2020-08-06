// 010��������м���
// ����һ������ͷ��� head �ķǿյ���������������м��㡣
// ����������м��㣬�򷵻صڶ����м��㡣
// ���룺[1,2,3,4,5,6]
// ��������б��еĽ�� 4 (���л���ʽ��[4,5,6])

#include<iostream>
#include<list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ˫ָ��
// slow��һ����fast����������fast��������ĩβʱ��slow��Ȼλ�������м䡣
class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		// ע���ж�����
		while (fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
};

// ��ָ��
// ��һ�α���ͳ��������
// �ڶ��α������������м���
class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		ListNode* cur = head;
		int count = 0;
		// ͳ��������
		while (cur){
			count++;
			cur = cur->next;
		}
		// ���������м��㣬ע���ʱ��Ҫ��cur��Ϊhead
		cur = head;
		for (int i = 0; i < count / 2; i++){
			cur = cur->next;
		}
		return cur;
	}
};