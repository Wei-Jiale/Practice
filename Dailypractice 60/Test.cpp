// 删除链表中等于给定值val的所有结点
// 1 2 6 3 4 5 6
// 1 2 3 4 5

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
	ListNode* removeElements(ListNode* head, int val) {
		// 头结点为空或头结点的值就为val且只有一个结点则直接返回
		if (head == nullptr || (head->val == val && head->next == nullptr))
			return nullptr;

		ListNode* fake = new ListNode(5201314);
		fake->next = head;
		ListNode* prev = fake;

		while (prev && prev->next){
			ListNode* cur = prev->next;
			// 若cur的值等于val，则prev的next就跳过cur
			if (cur->val == val)
				prev->next = cur->next;
			// 若cur的值不等于val，则prev就到cur的位置
			else
				prev = cur;
		}

		return fake->next;
	}
};
