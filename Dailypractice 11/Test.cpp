// 011�������е�����k����㣨��ָoffer 22��
// ����һ����������������е�����k�����
// ���룺1->2->3->4->5, �� k = 2
// �����4->5

#include<iostream>
#include<list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ˫ָ��
class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode* slow = head;
		ListNode* fast = head;
		// ��ָ������k��
		// �п���k>������
		while (k-- && fast){
			fast = fast->next;
		}
		if (!fast){
			return head;
		}
		// ����ָ��һ����
		while (fast){
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};
