// 在排序数组中查找数字（剑指Offer 53）
// 统计一个数字在排序数组中出现的次数

#include<iostream>
#include<vector>
using namespace std;

// 输入: nums = [5,7,7,8,8,10], target = 8
// 输出: 2

class Solution {
public:
	int search(vector<int>& nums, int target) {
		// 数组为空
		if (nums.empty()){
			return 0;
		}

		int count = 0;
		int middle = 0;
		int start = 0;
		int end = nums.size() - 1;

		// 二分查找
		while (start <= end){
			// 每次重新更新middle
			middle = start + (end - start) / 2;

			if (nums[middle] > target){
				// 目标值在中间值的左边则需要调整end位置
				end = middle - 1;
			}
			else if (nums[middle] == target){
				// 找到目标值则计数++ 并且跳出循环
				count++;
				break;
			}
			else{
				// 目标值在中间指的右边则需要调整start位置
				start = middle + 1;
			}
		}

		// 从middle向左右两边寻找该数字
		if (nums[middle] == target){
			start = end = middle;
			while (--start >= 0 && nums[start] == target){
				count++;
			}

			while (++end < nums.size() && nums[end] == target){
				count++;
			}
		}

		return count;
	}
};