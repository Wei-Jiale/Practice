// 038��������

#include<iostream>
#include<vector>
using namespace std;

void Adjustdown(vector<int>& array, int start, int end){
	int parent = start;
	int child = parent * 2 + 1;

	while (child < end){
		// ѡ�����Һ����нϴ��
		if (child + 1 < end && array[child + 1] > array[child]){
			child++;
		}
		// ���Ӻ͸��ױȽ�
		if (array[child] > array[parent]){
			// ���Ӵ��ڸ����򽻻�
			swap(array[child], array[parent]);
			// ���¼�������
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}

void Heapsort(vector<int>& array){
	// ���ѣ������һ����Ҷ�ӽ�㣨���һ�����ĸ���㣩��ʼ�������µ���
	int sz = array.size();
	for (int index = (sz - 1 - 1) / 2; index >= 0; index--){
		Adjustdown(array, index, sz);
	}
	// ������
	while (sz > 0){
		swap(array[0], array[sz - 1]);
		sz--;
		Adjustdown(array, 0, sz);
	}
}