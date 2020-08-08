// 016：环形链表
// 给定一个链表，判断链表中是否有环。
// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
// 如果 pos 是 -1，则在该链表中没有环。
// 输入：head = [3,2,0,-4], pos = 1
// 输出：true
// 解释：链表中有一个环，其尾部连接到第二个节点。

#include<iostream>
#include<list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 快慢指针
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