// 用两个栈实现队列（剑指Offer 9）
#include<iostream>
#include<stack>
using namespace std;

class CQueue {
private:
	stack<int> stack1, stack2;
public:
	CQueue() {}

	// 压栈没有特殊性
	void appendTail(int value) {
		stack1.push(value);
	}

	int deleteHead() {
		int res = 0;
		if (!stack2.empty()){
			// 如果stack2不是空的，那么其最上面的元素就是要被弹出的。
			res = stack2.top();
			stack2.pop();
		}
		else if (!stack1.empty()){
			// 如果stack2已经空了，把stack1的元素压过去，然后弹出stack2最上面的元素。
			while (!stack1.empty()){
				stack2.push(stack1.top());
				stack1.pop();
			}

			res = stack2.top();
			stack2.pop();
		}
		else{
			// 如果stack1和2都是空的，返回-1
			return -1;
		}

		return res;
	}
};