// 039��ð������
// ������������������Ԫ�ؼ�ֵ�ıȽϽ�����Ի�������Ԫ���������е�λ��
// ��һ����Ͻ����Ԫ���ƶ���Ԫ��ĩβ
// ���ĳһ��ִ����ϣ�û�����κ�һ�ν���������˵��ʣ�µ������Ѿ�����

#include<iostream>
#include<vector>
using namespace std;

void Bubblesort(vector<int>& array){
	int sz = array.size();
	// ���ѭ������ÿһ��ð�ݵĴ���
	for (int out = 0; out < sz - 1; out++){
		bool flag = true;
		// �ڲ�ѭ�����Ƶ�������
		for (int in = 0; in < sz - out - 1; in++){
			if (array[in]>array[in + 1]){
				swap(array[in], array[in + 1]);
				flag = false;
			}
		}
		// һ��������û�н��н���˵���Ѿ�����
		if (flag == true){
			break;
		}
	}
}