// 019�����ƴ����ָ�������
// ����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
// Ҫ�󷵻��������� �����

#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

// ��ϣ
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr) {
			return head;
		}
		unordered_map<Node*, Node*> ump;
		Node *cur = head;
		//1. ����������ԭ�ڵ���Ϊkey�������ڵ���Ϊvalue������map��
		while (cur) {
			Node *copy = new Node(cur->val);
			ump[cur] = copy;
			cur = cur->next;
		}
		//2. ��������next��randomָ��
		cur = head;
		while (cur) {
			ump[cur]->next = ump[cur->next];
			ump[cur]->random = ump[cur->random];
			cur = cur->next;
		}
		return ump[head];
	}
};

