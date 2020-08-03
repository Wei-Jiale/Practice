// 006：旋转数组
// 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
// 要求空间复杂度为O（1）的原地算法
// 输入: [1,2,3,4,5,6,7] 和 k = 3
// 输出: [5,6,7,1,2,3,4]

#include<iostream>
#include<vector>
using namespace std;

// 方法一：库函数reverse翻转
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		// 注意k值大于size的情况
		k = k%nums.size();
		// 翻转前一部分元素
		reverse(nums.begin(), nums.end() - k);
		// 翻转后一部分元素
		reverse(nums.end() - k, nums.end());
		// 全部翻转
		reverse(nums.begin(), nums.end());
	}
};

// 方法二：翻转法
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k = k%nums.size();
		// 翻转前一部分元素
		for (int i = 0; i < (nums.size() - k) / 2; i++){
			swap(nums[i], nums[nums.size() - k - 1 - i]);
		}
		// 翻转后一部分元素
		int flag = 0;
		for (int i = nums.size() - k; i < nums.size() - k + k / 2; i++){
			swap(nums[i], nums[nums.size() - 1 - flag]);
			flag++;
		}
		// 全部翻转
		for (int i = 0; i < nums.size() / 2; i++){
			swap(nums[i], nums[nums.size() - 1 - i]);
		}
	}
};