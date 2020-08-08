// 014����������
// ���ж�һ�������Ƿ�Ϊ��������
// ����: 1->2  ���: false
// ����: 1->2->2->1  ���: true

#include<iostream>
#include<list>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ����ջ
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		stack<int> st;
		ListNode* cur = head;
		// ��ջ
		while (cur){
			st.push(cur->val);
			cur = cur->next;
		}
		// ��ջ�Ƚ�
		cur = head;
		while (!st.empty()){
			if (st.top() == cur->val){
				st.pop();
				cur = cur->next;
			}
			else{
				return false;
			}
		}
		return true;
	}
};

// ˫ָ��
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		// �����������ֻ��һ�����Ҳ���ڻ�������
		if (!head || !head->next){
			return true;
		}
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* cur = nullptr;
		ListNode* prev = nullptr;
		// ǰ��ָ�������תǰһ������
		while (fast && fast->next){
			cur = slow;
			slow = slow->next;
			fast = fast->next->next;
			cur->next = prev;
			prev = cur;
		}
		// ���������ʱ�����м�ڵ�
		// ������fast->next == nullptr�жϣ�fast�п���Ϊnullptr��
		if (fast){
			slow = slow->next;
		}

		// ǰ�󲿷ֽ��бȽ�
		while (cur){
			if (cur->val != slow->val){
				return false;
			}
			cur = cur->next;
			slow = slow->next;
		}
		return true;
	}
};