// 015���ཻ����
// ��дһ�������ҵ������������ཻ����ʼ�ڵ㡣

#include<iostream>
#include<list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ���������
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr){
			return nullptr;
		}

		ListNode* curlong = headA;
		ListNode* curshort = headB;

		// �ֱ�õ���������
		int countlong = 0;
		int countshort = 0;
		while (headA){
			countlong++;
			headA = headA->next;
		}
		while (headB){
			countshort++;
			headB = headB->next;
		}

		// �жϳ�������
		int flag = 0;
		if (countlong < countshort){
			swap(countlong, countshort);
			flag = 1;
		}
		int length = countlong - countshort;

		// �����������������ֵ�Ĳ���
		while (length--){
			if (flag == 0){
				curlong = curlong->next;
			}
			else{
				curshort = curshort->next;
			}
		}

		// �ж����������ַ�Ƿ���ͬ
		while (curlong != curshort){
			curlong = curlong->next;
			curshort = curshort->next;
		}
		return curlong;
	}
};

// ˫ָ��
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr){
			return nullptr;
		}

		// A��ָ�������A����B��ʼ������
		// B��ָ�������B����A��ʼ������
		// ����ָ����඼��m+n����
		ListNode* cur_a = headA;
		ListNode* cur_b = headB;

		// ������ָ��ͬʱΪ��ʱ����ʾ���ཻ�����������ǿ������ʱ����ʾ�ཻ��
		while (cur_a != cur_b){
			cur_a = (cur_a ? cur_a->next : headB);
			cur_b = (cur_b ? cur_b->next : headA);
		}

		return cur_a;
	}
};