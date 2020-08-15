// 023�����ѭ������

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class MyCircularQueue {
public:
	vector<int> array;//������ģ��ʵ��ѭ������
	int capacity;//����
	int size;//ʵ�����ݸ���
	int front;//��ǰ���������±�
	int vear;//��ǰ��β����λ���±�

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
			// ��vear + 1 = capacity��vear��Ϊѭ��������
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
			// ��front+1 = capacity��front��Ϊѭ��������
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
			// vear-1����Ϊ�������Լ���capacity����
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