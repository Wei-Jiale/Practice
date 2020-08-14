// 022��ջʵ�ֶ���

#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
	// ������ջ�ͳ�ջ
	stack<int> in;
	stack<int> out;

	MyQueue() {}

	// �����
	void push(int x) {
		// ��������
		in.push(x);
	}

	// ɾ������Ԫ��
	int pop() {
		// ��ջΪ��
		if (out.empty()){
			while (!in.empty()){
				// inջ��Ϊ��
				int x = in.top();
				out.push(x);
				in.pop();
			}
		}
		// ��ջ��ջ��Ԫ��
		int val = out.top();
		out.pop();
		return val;
	}

	// �鿴����Ԫ��
	int peek() {
		if (out.empty()){
			while (!in.empty()){
				int x = in.top();
				out.push(x);
				in.pop();
			}
		}
		// ��ջ��ջ��Ԫ��
		int val = out.top();
		return val;
	}

	// �ж϶����Ƿ�Ϊ��
	bool empty() {
		return in.empty() && out.empty();
	}
};