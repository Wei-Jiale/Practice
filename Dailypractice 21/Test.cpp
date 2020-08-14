// 021������ʵ��ջ

#include<iostream>
#include<queue>
using namespace std;

class MyStack {
public:
	queue<int> q;
	MyStack() {}

	// ѹջ
	void push(int x) {
		// û��������
		q.push(x);
	}

	// ɾ��ջ��Ԫ��
	int pop() {
		// ջ��Ԫ�ؾ��Ƕ���ĩβԪ��
		for (int i = 0; i < q.size() - 1; i++){
			// Ų��ǰsize-1��Ԫ��
			int x = q.front();
			q.push(x);
			q.pop();
		}
		int val = q.front();
		q.pop();
		return val;
	}

	// ��ȡջ��Ԫ��
	int top() {
		// ջ��Ԫ�ؾ��Ƕ���ĩβԪ��
		for (int i = 0; i < q.size() - 1; i++){
			// Ų��ǰsize-1��Ԫ��
			int x = q.front();
			q.push(x);
			q.pop();
		}
		int val = q.front();
		q.push(val);
		q.pop();
		return val;
	}

	// �ж�ջ�Ƿ�Ϊ��
	bool empty() {
		return q.empty();
	}
};