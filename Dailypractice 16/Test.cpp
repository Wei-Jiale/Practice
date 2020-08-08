// 016����������
// ����һ�������ж��������Ƿ��л���
// Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� 
// ��� pos �� -1�����ڸ�������û�л���
// ���룺head = [3,2,0,-4], pos = 1
// �����true
// ���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣

#include<iostream>
#include<list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ����ָ��
class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode* slow = head;
		ListNode* fast = head;

		while (fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;

			if (fast == slow){
				return true;
			}
		}

		return false;
	}
};