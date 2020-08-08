// 017：环形链表
// 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
// 如果 pos 是 -1，则在该链表中没有环。
// 输入：head = [3,2,0,-4], pos = 1
// 输出：tail connects to node index 1
// 解释：链表中有一个环，其尾部连接到第二个节点。

#include<iostream>
#include<list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 双指针
// 从头结点到环形入口节点 的节点数为x。
// 环形入口节点到 fast指针与slow指针相遇节点 节点数为y。
// 从相遇节点 再到环形入口节点节点数为 z。
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		// 判断链表是否带环
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast){
				// 链表带环
				// 相遇时slow走过的结点：x+y
				// 相遇时fast走过的结点：x+y+n(y+z)
				// fast指针走过的结点数是slow走过的结点数的二倍
				// 2*(x+y) = x+y+n(y+z)
				ListNode* index1 = head;
				ListNode* index2 = slow;
				// fast指针至少要多走一圈才能相遇slow指针
				// 需要求解x
				// 从头结点出发一个指针，从相遇节点 也出发一个指针。
				// 这两个指针每次只走一个节点， 那么当这两个指针相遇的时候就是 环形入口的节点。
				while (index1 != index2){
					index1 = index1->next;
					index2 = index2->next;
				}
				return index1;
			}
		}
		return nullptr;
	}
};
