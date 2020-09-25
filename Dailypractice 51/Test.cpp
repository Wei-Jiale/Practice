// ������ջʵ�ֶ��У���ָOffer 9��
#include<iostream>
#include<stack>
using namespace std;

class CQueue {
private:
	stack<int> stack1, stack2;
public:
	CQueue() {}

	// ѹջû��������
	void appendTail(int value) {
		stack1.push(value);
	}

	int deleteHead() {
		int res = 0;
		if (!stack2.empty()){
			// ���stack2���ǿյģ���ô���������Ԫ�ؾ���Ҫ�������ġ�
			res = stack2.top();
			stack2.pop();
		}
		else if (!stack1.empty()){
			// ���stack2�Ѿ����ˣ���stack1��Ԫ��ѹ��ȥ��Ȼ�󵯳�stack2�������Ԫ�ء�
			while (!stack1.empty()){
				stack2.push(stack1.top());
				stack1.pop();
			}

			res = stack2.top();
			stack2.pop();
		}
		else{
			// ���stack1��2���ǿյģ�����-1
			return -1;
		}

		return res;
	}
};