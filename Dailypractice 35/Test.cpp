// 035����������

#include <iostream>
#include <vector>
using namespace std;

void InsertSort(vector<int>& array){
	// ֱ�Ӳ�������
	int sz = array.size();
	for (int disorder = 1; disorder < sz; disorder++){
		int goal = disorder;
		// ��δ���򲿷ֵĵ�һ��Ԫ�غ����򲿷ֵ����һ��Ԫ�رȽ�
		while (goal > 0 && array[goal] < array[goal - 1]){
			swap(array[goal], array[goal - 1]);
			goal--;
		}
	}
}