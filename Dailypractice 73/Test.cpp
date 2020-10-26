// 复杂链表的复制（剑指Offer 35）
// 在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

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
		// 拷贝val和next
		copyNode(head);
		// 拷贝random
		copyRandom(head);
		// 提取出新的链表
		return getCopy(head);
	}

	void copyNode(Node* head){
		Node* cur = head;
		while (cur){
			// a -> b -> c 变为 a -> a' -> b -> b' -> c -> c'
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
			// 例：a -> a' -> b -> b' -> c -> c'
			// 假如 a -> random存在，则 a' -> random 一定等于 a -> random -> next
			// 假如 a -> random不存在，则 a' -> random == nullptr
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
		// 将原链表与复制出的链表提取成两条单独的链表，并返回复制出的链表
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