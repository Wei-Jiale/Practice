// 022：栈实现队列

#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
	// 定义入栈和出栈
	stack<int> in;
	stack<int> out;

	MyQueue() {}

	// 入队列
	void push(int x) {
		// 无特殊性
		in.push(x);
	}

	// 删除队首元素
	int pop() {
		// 出栈为空
		if (out.empty()){
			while (!in.empty()){
				// in栈不为空
				int x = in.top();
				out.push(x);
				in.pop();
			}
		}
		// 出栈的栈顶元素
		int val = out.top();
		out.pop();
		return val;
	}

	// 查看队首元素
	int peek() {
		if (out.empty()){
			while (!in.empty()){
				int x = in.top();
				out.push(x);
				in.pop();
			}
		}
		// 出栈的栈顶元素
		int val = out.top();
		return val;
	}

	// 判断队列是否为空
	bool empty() {
		return in.empty() && out.empty();
	}
};