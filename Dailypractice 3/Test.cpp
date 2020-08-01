// 003：移除元素
// 给你一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，并返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。
// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
#include<iostream>
#include<vector>
using namespace std;

// 方法一：迭代器
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		vector<int>::iterator it = nums.begin();
		// 终止条件迭代器不走到数组的结尾
		while (it != nums.end()){
			if (*it == val){
				// 删除val元素
				it = nums.erase(it);
			}
			else{
				++it;
			}
		}
		return nums.size();
	}
};

// 方法二：快慢指针
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int slow = 0;
		int fast = 0;
		while (fast<nums.size()){
			// 当fast！=val的时候，快慢指针一起向前
			if (nums[fast] != val){
				swap(nums[fast], nums[slow]);
				fast++;
				slow++;
			}
			else{
				// fast找到了val
				fast++;
			}
		}
		return slow;
	}
};
