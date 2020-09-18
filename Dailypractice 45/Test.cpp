// 数组中重复的数字（剑指Offer 3）
// 在一个长度为n的数组里的所有数字都在0到n-1的范围内。
// 数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
// 请找出数组中任意一个重复的数字。
// 例如：输入长度为7的数组{2，3，1，0，2，5，3}，输出数字2或者3。
#include<iostream>
#include<vector>
using namespace std;

// 解法一：排序数组，遍历数组找出重复元素。 O(logN)
// 解法二：扫描数组，利用O(1)的时间复杂度从哈希表中判断是否包含该数字，若没有则加入哈希表，有则找到了重复元素。 空间额外O(n)

// 解法三：假设这个数组中没有重复的数字，当数组排序之后数字i将出现在下标为i的位置。
//         扫描数组，当扫描到下标为i的数字时，首先比较这个数字（m）是不是等于i。
//         如果是则接着扫描下一个数字，如果不是则再拿它和第m个数字进行交换。
//         如果它和第m个数字相等，就找到了一个重复的数字。
//         如果它和第m个数字不相等，就将第i个数字和第m个数字进行交换，重复比较。

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		if (nums.empty())
			return -1;

		for (int i = 0; i < nums.size(); ++i)
		{
			while (nums[i] != i)
			{
				if (nums[i] == nums[nums[i]])
					return nums[i];
				else
					swap(nums[i], nums[nums[i]]);
			}
		}
		return -1;
	}
};