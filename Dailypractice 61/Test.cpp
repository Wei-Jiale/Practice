// 调整数组的顺序使奇数位于偶数前（剑指Offer 21）
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		// 判空
		if (nums.empty() || nums.size() == 1){
			return nums;
		}

		// 设置前后指针
		int begin = 0;
		int end = nums.size() - 1;

		while (begin < end){
			// 向后移动begin直到指向偶数
			while (begin < end && ((nums[begin] & 1) != 0)){
				begin++;
			}
			// 向前移动end直到指向奇数
			while (begin < end && ((nums[end] & 1) == 0)){
				end--;
			}
			// 交换奇数偶数
			if (begin < end){
				swap(nums[begin], nums[end]);
			}
		}

		return nums;
	}
};