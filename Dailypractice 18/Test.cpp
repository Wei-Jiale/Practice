// 018��ɾ�����������е��ظ�Ԫ��
// ����һ����������ɾ�����к����ظ����ֵĽڵ㣬ֻ����ԭʼ������ û���ظ����ֵ����֡�
// ����: 1->2->3->3->4->4->5
// ���: 1->2->5

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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr){
			return nullptr;
		}
		// �����ڱ���㣬ʹ��ÿ����㶼���Լ���ǰ����㡣
		ListNode* fake = new ListNode(-1);
		fake->next = head;
		ListNode* prev = fake;
		ListNode* back = head;
		ListNode* front = head->next;

		while (front){
			if (back->val != front->val){
				prev = back;
				back = front;
				front = front->next;
			}
			else{
				// front->val == back->val  frontһֱ������
				while (front != nullptr && back->val == front->val){
					front = front->next;
				}
				// front�������back->val!=front->val
				prev->next = front;
				back = front;
				if (front != nullptr){
					front = front->next;
				}
			}
		}
		head = fake->next;
		return head;
	}
};