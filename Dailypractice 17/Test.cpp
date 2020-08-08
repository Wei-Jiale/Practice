// 017����������
// ����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
// Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� 
// ��� pos �� -1�����ڸ�������û�л���
// ���룺head = [3,2,0,-4], pos = 1
// �����tail connects to node index 1
// ���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣

#include<iostream>
#include<list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ˫ָ��
// ��ͷ��㵽������ڽڵ� �Ľڵ���Ϊx��
// ������ڽڵ㵽 fastָ����slowָ�������ڵ� �ڵ���Ϊy��
// �������ڵ� �ٵ�������ڽڵ�ڵ���Ϊ z��
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		// �ж������Ƿ����
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast){
				// �������
				// ����ʱslow�߹��Ľ�㣺x+y
				// ����ʱfast�߹��Ľ�㣺x+y+n(y+z)
				// fastָ���߹��Ľ������slow�߹��Ľ�����Ķ���
				// 2*(x+y) = x+y+n(y+z)
				ListNode* index1 = head;
				ListNode* index2 = slow;
				// fastָ������Ҫ����һȦ��������slowָ��
				// ��Ҫ���x
				// ��ͷ������һ��ָ�룬�������ڵ� Ҳ����һ��ָ�롣
				// ������ָ��ÿ��ֻ��һ���ڵ㣬 ��ô��������ָ��������ʱ����� ������ڵĽڵ㡣
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
