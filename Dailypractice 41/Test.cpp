// �鲢����

#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int>& array, int begin, int mid, int end){
	vector<int> array1;
	vector<int> array2;
	for (int i = begin; i <= mid; i++){
		array1.push_back(array[i]);
	}
	for (int i = mid + 1; i <= end; i++){
		array2.push_back(array[i]);
	}

	// i,j�ֱ����array1��array2
	int i = 0;
	int j = 0;

	// begin��ԭʼ����Ŀ�ʼ
	int k = begin;
	while (i < array1.size() && j < array2.size()){
		if (array1[i] <= array2[j]){
			array[k] = array1[i];
			i++;
			k++;
		}
		else{
			array[k] = array2[j];
			j++;
			k++;
		}
	}

	while (i < array1.size()){
		array[k] = array1[i];
		i++;
		k++;
	}
	while (j < array2.size()){
		array[k] = array2[j];
		j++;
		k++;
	}
}

void Mergesort(vector<int>& array, int begin, int end){
	if (end - begin >= 1){
		// δ������������������������
		int mid = (begin + end) >> 1;
		// ��
		Mergesort(array, begin, mid);
		Mergesort(array, mid + 1, end);
		// ��
		Merge(array, begin, mid, end);
	}
}