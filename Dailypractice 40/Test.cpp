// 040：快速排序。
// 任取待排序序列的中的某元素为基准值，遍历整个数组区间。
// 比基准值小的元素放到基准值的左边，比基准值大的元素放到基准值的右边，再用相同的方式处理左右两个无序子区间，直到小区间有序。
// 三数取中法选取基准值（防止极端情况）： 取左端、中间、右端三个数进行排序，将中间数作为基准值。

#include<iostream>
#include<vector>
using namespace std;

// 三数取中法选取基准值
int GetMiddle(vector<int>& array, int begin, int end){
	if (array.size() >= 3){
		// 获取中位数下标
		int mid = (begin + end) >> 1;
		// 三数比较
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

// 前后指针
int Partsort(vector<int>& array, int begin, int end){
	// 基准值
	int midindex = GetMiddle(array, begin, end);
	swap(array[end], array[midindex]);

	int cur = begin;
	int prev = begin - 1;

	while (cur < end){
		// 找到小于基准值的元素
		// 两个指针一起走，若碰到大于基准值的元素前指针停下，后指针继续++
		if (array[cur] < array[end] && ++prev != cur){
			swap(array[cur], array[prev]);
		}
		cur++;
	}

	prev++;
	// 和基准值交换
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