// 036��ϣ������

#include<iostream>
#include<vector>
using namespace std;

void Shellsort(vector<int>& array){
	// ��������������С����
	int sz = array.size();
	for (int gap = sz / 2; gap > 0; gap /= 2){
		// �ӵ�gap��Ԫ�أ�����������������ֱ�Ӳ����������
		for (int disorder = gap; disorder < sz; disorder++){
			int goal = disorder;
			while (goal - gap >= 0 && array[goal] < array[goal - gap]){
				swap(array[goal], array[goal - gap]);
				goal -= gap;
			}
		}
	}
}