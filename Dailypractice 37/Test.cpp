// 037��ѡ������

#include<iostream>
#include<vector>
using namespace std;

void Selectsort(vector<int>& array){
	int sz = array.size();
	for (int disorder = 0; disorder < sz - 1; disorder++){
		// ����min�洢��СԪ�ص��±꣨�����������Ԫ�أ�
		int min = disorder;
		// ����Ѱ�����������е���СԪ�ص��±�
		for (int goal = disorder + 1; goal < sz; goal++){
			if (array[goal] < array[min]){
				min = goal;
			}
		}
		// �����СԪ�ز������������еĵ�һ��Ԫ�����������������Ԫ�ؽ���
		if (min != disorder){
			swap(array[min], array[disorder]);
		}
	}
}