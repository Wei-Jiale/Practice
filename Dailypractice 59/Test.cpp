// ɾ�������еĽ�㣨��ָOffer 18��
// �������������ͷָ���һ�����ָ�룬��O(1)ʱ����ɾ���ý�㡣

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
	ListNode* deleteNode(ListNode* head, int val) {
		// Ҫɾ��������ֵΪval�Ľڵ㣬��ô�ݹ���ֹ������ΪheadΪ�յ�ʱ����Ϊ�յĽڵ����޷�ɾ���ġ�
		if (head == nullptr){
			return head;
		}

		// ���head��Ϊ�գ�ͬʱhead��ֵ�ֵ���val������������һ���ڵ�
		if (head->val == val){
			return head->next;
		}

		// ���head��Ϊ�գ�ͬʱhead��ֵҲ������val��˵��head����ɾ�������ǵݹ��ȥ�ж���һ���ڵ�������
		head->next = deleteNode(head->next, val);

		return head;
	}
};