// 021：队列实现栈

#include<iostream>
#include<queue>
using namespace std;

class MyStack {
public:
	queue<int> q;
	MyStack() {}

	// 压栈
	void push(int x) {
		// 没有特殊性
		q.push(x);
	}

	// 删除栈顶元素
	int pop() {
		// 栈顶元素就是队列末尾元素
		for (int i = 0; i < q.size() - 1; i++){
			// 挪动前size-1个元素
			int x = q.front();
			q.push(x);
			q.pop();
		}
		int val = q.front();
		q.pop();
		return val;
	}

	// 获取栈顶元素
	int top() {
		// 栈顶元素就是队列末尾元素
		for (int i = 0; i < q.size() - 1; i++){
			// 挪动前size-1个元素
			int x = q.front();
			q.push(x);
			q.pop();
		}
		int val = q.front();
		q.push(val);
		q.pop();
		return val;
	}

	// 判断栈是否为空
	bool empty() {
		return q.empty();
	}
};