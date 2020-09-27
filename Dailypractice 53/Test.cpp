// 用队列实现栈（剑指Offer 9）

#include<iostream>
#include<queue>
using namespace std;

class MyStack{
public:
	queue<int> q;
	MyStack(){

	}

	// 压栈没有特殊性
	void push(int val){
		q.push(val);
	}

	// 出栈
	int pop(){
		// 出栈首先挪动队列中size-1个数据
		int sz = q.size();
		for (int cur = 0; cur < sz - 1; cur++){
			// 将前size-1个数据依次挪到队尾
			int front = q.front();
			q.pop();
			q.push(front);
		}

		int ret = q.front();
		q.pop();
		return ret;
	}
};