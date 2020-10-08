// 旋转数组中的最小数字（剑指Offer 11）
// 把一个数组最开始的若干个元素搬到数组的末尾，我们称为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
// {3，4，5，1，2}为{1，2，3，4，5}的一个旋转，输出该数组的最小值1。

#include<iostream>
#include<vector>
using namespace std;

// 解法一：
// 从头到尾遍历数组一次，就能找出最小的数字。
// 时间复杂度 O(N)
class Solution{
public:
	int minArray(vector<int>& numbers){
		if (numbers.empty())
			return -1;
		if (numbers.size() == 1)
			return numbers[0];

		// 遍历数组找到最小元素
		for (int cur = 0; cur < numbers.size(); cur++){
			if (cur + 1 < numbers.size()){
				if (numbers[cur + 1] < numbers[cur]){
					return numbers[cur + 1];
				}
			}
			else break;
		}

		return numbers[0];
	}
};

// 解法二：
// 旋转之后的数组可以划分为两个排序的子数组
// 前面的子数组的元素都大于或等于后面子数组的元素
// 最小的元素刚好就是这两个子数组的分界线
// 排序数组中我们可以用二分查找实现 O(logN)的查找

class Solution{
public:
	int minArray(vector<int>& numbers){
		if (numbers.empty())
			return -1;
		if (numbers.size() == 1)
			return numbers[0];

		// 两个指针分别指向首尾
		int ptrhead = 0;
		int ptrend = numbers.size() - 1;
		// 中间元素（假如旋转前0个元素，则直接返回首元素）
		int mid = ptrhead;

		while (numbers[ptrhead] >= numbers[ptrend]){
			if (ptrend - ptrhead == 1){
				mid = ptrend;
				break;
			}
			mid = (ptrhead + ptrend) / 2;
			if (numbers[ptrhead] == numbers[ptrend] && numbers[ptrhead] == numbers[mid]){
				// 特殊情况：三者相同无法判断最小值的区间，就只能顺序查找
				return findMin(numbers, ptrhead, ptrend);
			}
			// 最小值在mid或者mid的后面
			if (numbers[mid] >= numbers[ptrhead]){
				ptrhead = mid;
			}
			// 最小值在mid或者mid的前面
			else{
				ptrend = mid;
			}
		}
		return numbers[mid];
	}

	// 顺序查找
	int findMin(vector<int>& numbers, int ptrhead, int ptrend){
		int ret = numbers[0];
		for (int cur = ptrhead + 1; cur <= ptrend; cur++){
			if (numbers[cur]<ret){
				ret = numbers[cur];
				break;
			}
		}
		return ret;
	}
};