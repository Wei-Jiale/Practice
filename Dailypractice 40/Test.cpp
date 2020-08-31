// 040����������
// ��ȡ���������е��е�ĳԪ��Ϊ��׼ֵ�����������������䡣
// �Ȼ�׼ֵС��Ԫ�طŵ���׼ֵ����ߣ��Ȼ�׼ֵ���Ԫ�طŵ���׼ֵ���ұߣ�������ͬ�ķ�ʽ���������������������䣬ֱ��С��������
// ����ȡ�з�ѡȡ��׼ֵ����ֹ����������� ȡ��ˡ��м䡢�Ҷ��������������򣬽��м�����Ϊ��׼ֵ��

#include<iostream>
#include<vector>
using namespace std;

// ����ȡ�з�ѡȡ��׼ֵ
int GetMiddle(vector<int>& array, int begin, int end){
	if (array.size() >= 3){
		// ��ȡ��λ���±�
		int mid = (begin + end) >> 1;
		// �����Ƚ�
		if (array[begin] < array[mid]){
			if (array[mid] < array[end]){
				// begin < mid < end
				return mid;
			}
			else if (array[begin] < array[end]){
				// mid > end > begin
				return end;
			}
			else{
				// mid > begin > end
				return begin;
			}
		}
		else{
			// begin > mid
			if (array[end] < array[mid]){
				// begin > mid > end
				return mid;
			}
			else if (array[begin]>array[end]){
				// begin > end > mid
				return end;
			}
			else{
				// end > begin > mid 
				return begin;
			}
		}
	}
	else{
		if (array[begin] > array[end]){
			swap(array[begin], array[end]);
		}
		return 0;
	}
}

// ǰ��ָ��
int Partsort(vector<int>& array, int begin, int end){
	// ��׼ֵ
	int midindex = GetMiddle(array, begin, end);
	swap(array[end], array[midindex]);

	int cur = begin;
	int prev = begin - 1;

	while (cur < end){
		// �ҵ�С�ڻ�׼ֵ��Ԫ��
		// ����ָ��һ���ߣ����������ڻ�׼ֵ��Ԫ��ǰָ��ͣ�£���ָ�����++
		if (array[cur] < array[end] && ++prev != cur){
			swap(array[cur], array[prev]);
		}
		cur++;
	}

	prev++;
	// �ͻ�׼ֵ����
	swap(array[prev], array[end]);
	return prev;
}

void Quicksort(vector<int>& array, int begin, int end){
	if (end - begin < 1){
		return;
	}

	int keyindex = Partsort(array, begin, end);
	Quicksort(array, begin, keyindex - 1);
	Quicksort(array, keyindex + 1, end);
}