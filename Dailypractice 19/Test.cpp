// 019：复制带随机指针的链表
// 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
// 要求返回这个链表的 深拷贝。

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

// 哈希
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr) {
			return head;
		}
		unordered_map<Node*, Node*> ump;
		Node *cur = head;
		//1. 遍历链表，将原节点作为key，拷贝节点作为value保存在map中
		while (cur) {
			Node *copy = new Node(cur->val);
			ump[cur] = copy;
			cur = cur->next;
		}
		//2. 复制链表next和random指针
		cur = head;
		while (cur) {
			ump[cur]->next = ump[cur->next];
			ump[cur]->random = ump[cur->random];
			cur = cur->next;
		}
		return ump[head];
	}
};

