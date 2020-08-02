// 004：删除排序数组中的重复项
// 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须在原地修改输入数组，并在使用 O(1) 额外空间的条件下完成。
// 给定 nums = [0,0,1,1,1,2,2,3,3,4],
// 函数应该返回新的长度 5, 并且原数组nums的前五个元素被修改为 0, 1, 2, 3, 4。

#include<iostream>
#include<vector>
using namespace std;

// 解法一：双指针
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		// 注意数组为空的情况
		if (nums.empty()){
			return 0;
		}
		// 快慢指针
		int slow = 0;
		int fast = 1;
		while (fast < nums.size()){
			if (nums[slow] == nums[fast]){
				fast++;
			}
			else{
				slow++;
				nums[slow] = nums[fast];
			}
		}
		return slow + 1;
	}
};

// 解法二：计数排序
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		// 统计当前元素需要前移的位数
		int count = 0;
		for (int i = 1; i < nums.size(); i++){
			if (nums[i - 1] == nums[i]){
				count++;
			}
			else{
				nums[i - count] = nums[i];
			}
		}
		return nums.size() - count;
	}
};