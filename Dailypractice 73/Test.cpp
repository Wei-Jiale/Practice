// ��������ĸ��ƣ���ָOffer 35��
// �ڸ��������У�ÿ���ڵ������һ�� next ָ��ָ����һ���ڵ㣬����һ�� random ָ��ָ�������е�����ڵ���� null��

#include<iostream>
#include<list>
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

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr)
			return head;
		// ����val��next
		copyNode(head);
		// ����random
		copyRandom(head);
		// ��ȡ���µ�����
		return getCopy(head);
	}

	void copyNode(Node* head){
		Node* cur = head;
		while (cur){
			// a -> b -> c ��Ϊ a -> a' -> b -> b' -> c -> c'
			Node* copy = new Node(cur->val);
			Node* nextPtr = cur->next;
			cur->next = copy;
			copy->next = nextPtr;
			cur = copy->next;
		}
	}

	void copyRandom(Node* head){
		Node* cur = head;
		while (cur){
			// ����a -> a' -> b -> b' -> c -> c'
			// ���� a -> random���ڣ��� a' -> random һ������ a -> random -> next
			// ���� a -> random�����ڣ��� a' -> random == nullptr
			Node* oldRandom = cur->random;
			Node* copy = cur->next;
			if (oldRandom)
				copy->random = oldRandom->next;
			else
				copy->random = nullptr;

			cur = copy->next;
		}
	}

	Node* getCopy(Node* head){
		// ��ԭ�����븴�Ƴ���������ȡ���������������������ظ��Ƴ�������
		Node* cur = head;
		Node* copy = cur->next;
		Node* newHead = copy;
		while (cur){
			cur->next = copy->next;
			cur = cur->next;
			if (cur)
				copy->next = cur->next;
			copy = copy->next;
		}

		return newHead;
	}
};