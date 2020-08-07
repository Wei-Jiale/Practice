// 013���ָ�����
// ����һ�������һ���ض�ֵ x����������зָ���
// ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ��
// ��������������ÿ���ڵ�ĳ�ʼ���λ�á�
// ����: head = 1->4->3->2->5->2, x = 3
// ���: 1->2->2->4->3->5

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
		// ������������һ���洢С�ڻ�׼ֵ�Ľ�㣬һ���洢���ڻ�׼ֵ�Ľ�㡣
		ListNode* low = new ListNode(-1);
		ListNode* high = new ListNode(-1);
		ListNode* lowcur = low;
		ListNode* highcur = high;

		// �Ȳ��ԭ�������ٺϲ��½�����
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

		// �洢���ڻ�׼ֵ������ĩβ��Ҫָ��nullptr
		highcur->next = nullptr;
		lowcur->next = high->next;
		return low->next;
	}
};