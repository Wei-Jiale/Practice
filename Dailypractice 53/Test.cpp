// �ö���ʵ��ջ����ָOffer 9��

#include<iostream>
#include<queue>
using namespace std;

class MyStack{
public:
	queue<int> q;
	MyStack(){

	}

	// ѹջû��������
	void push(int val){
		q.push(val);
	}

	// ��ջ
	int pop(){
		// ��ջ����Ų��������size-1������
		int sz = q.size();
		for (int cur = 0; cur < sz - 1; cur++){
			// ��ǰsize-1����������Ų����β
			int front = q.front();
			q.pop();
			q.push(front);
		}

		int ret = q.front();
		q.pop();
		return ret;
	}
};