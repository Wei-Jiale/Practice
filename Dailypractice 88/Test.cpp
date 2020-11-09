// 数组中缺失的数字（剑指Offer 53）
// 一个长度为n-1的递增排序数组中的所有数字都是唯一的
// 并且每个数字都在范围0～n-1之内。
// 在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		assert(!nums.empty());

		int start = 0;
		int end = nums.size() - 1;

		// 被划分小于等于三个元素时跳出循环
		while (end > start){
			int middle = start + (end - start) / 2;

			if (nums[middle] > middle){
				// 缺失的数字在左半区间
				end = middle - 1;
			}
			else{
				// 缺失的数字在右半区间
				start = middle + 1;
			}
		}


		if (nums[start] > start){
			return start;
		}

		return end + 1;
	}
};