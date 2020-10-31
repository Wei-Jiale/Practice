// 连续子数组的最大和（剑指Offer 41）
// 输入一个整型数组
// 数组中一个或者多个连续的整型组成一个子数组
// 求所有子数组的和的最大值

#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		assert(!nums.empty());

		// 设置全局变量maxSum
		int maxSum = nums[0];
		int sz = nums.size();

		for (int cur = 1; cur<sz; cur++){
			// 若前一个数大于0则和当前数累加
			if (nums[cur - 1] > 0){
				nums[cur] = nums[cur - 1] + nums[cur];
			}
			// 更新maxSum
			maxSum = max(nums[cur], maxSum);
		}

		return maxSum;
	}
};