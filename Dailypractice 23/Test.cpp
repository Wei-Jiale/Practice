// 023：设计循环队列

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class MyCircularQueue {
public:
	vector<int> array;//用数组模拟实现循环队列
	int capacity;//容量
	int size;//实际数据个数
	int front;//当前队首数据下标
	int vear;//当前队尾可用位置下标

	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		array.resize(k);
		capacity = k;
		size = 0;
		front = 0;
		vear = 0;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (size == capacity){
			return false;
		}
		else{
			array[vear] = value;
			// 若vear + 1 = capacity则vear就为循环至队首
			vear = (vear + 1) % capacity;
			size++;
			return true;
		}
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (size == 0){
			return false;
		}
		else{
			// 若front+1 = capacity则front就为循环至队首
			front = (front + 1) % capacity;
			size--;
			return true;
		}
	}

	/** Get the front item from the queue. */
	int Front() {
		if (size == 0){
			return -1;
		}
		else{
			return array[front];
		}
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (size == 0){
			return -1;
		}
		else{
			// vear-1可能为负数所以加以capacity调整
			int index = (vear - 1 + capacity) % capacity;
			return array[index];
		}
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		return size == 0;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		return size == capacity;
	}
};