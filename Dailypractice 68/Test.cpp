// ����min������ջ����ָOffer 30��

#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	stack<int> normalst;
	stack<int> minst;

	MinStack() {}

	void push(int x) {
		normalst.push(x);
		// ��СջΪ�� �� ѹ���ֵ��������Сջ��
		if (minst.empty() || x <= minst.top()){
			minst.push(x);
		}

		if (x > minst.top()){
			int temp = minst.top();
			minst.push(temp);
		}
	}

	void pop() {
		if (!normalst.empty() && !minst.empty())
			normalst.pop();
		minst.pop();
	}

	int top() {
		return normalst.top();
	}

	int min() {
		return minst.top();
	}
};