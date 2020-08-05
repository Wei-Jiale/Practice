// 008���Ƴ�����Ԫ��
// ɾ�������е��ڸ���ֵ val �����нڵ�

#include<iostream>
#include<list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// �����ڱ���㣺��ɾ���֮ǰһ�����ָ���ɾ���֮��һ����㼴��
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		// �ж�ͷ����Ƿ�Ϊ��
		if (!head){
			return nullptr;
		}
		// �����ڱ����λ��ͷ����ǰ�����
		ListNode* prev = new ListNode(0);
		prev->next = head;
		ListNode* cur = prev;
		while (cur->next){
			if (cur->next->val == val){
				cur->next = cur->next->next;
			}
			else{
				cur = cur->next;
			}
		}
		return prev->next;
	}
};

// �ݹ�
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (!head){
			return nullptr;
		}
		head->next = removeElements(head->next, val);
		return head->val == val ? head->next : head;
	}
};