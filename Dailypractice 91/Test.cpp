// ��ת����
// ��Ҫ�ñ�nextָ���ָ��
// ���ȶ���һ��curָ��ָ��ͷ��㣬�ٶ���һ��prevָ���ʼ��Ϊnullptr
// ÿ����Ҫ��cur->next�����б��棬��Ϊÿ�ζ�Ҫ�ı�cur->next��ָ��ָ��prev
// ����ѭ��curָ��nullptrʱ��ѭ������������prev

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ˫ָ��
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		// ������Ϊ���򷵻�nullptr
		if (head == nullptr){
			return nullptr;
		}
		// ��Ϊ������curָ��ָ��head������prevָ���ʼ��Ϊnullptr
		ListNode* cur = head;
		ListNode* prev = nullptr;
		// ѭ����ת
		while (cur){
			// ����cur->next
			ListNode* temp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = temp;
		}
		// ���ؽ��
		return prev;
	}
};

