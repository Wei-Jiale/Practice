// 005：合并两个有序数组
// 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
// 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 
// 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
// 输入：nums1 = [1,2,3,0,0,0], m = 3，nums2 = [2, 5, 6], n = 3
// 输出: [1,2,2,3,5,6]

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		// nums1中最后一个元素的下标
		int first = m - 1;
		// nums2中最后一个元素的下标
		int second = n - 1;
		// nums1中最后一个位置的下标
		int end = m + n - 1;
		while (second >= 0 && first >= 0){
			// 倒序比较两数组中元素，较大的插入nums1的end中
			if (nums1[first] >= nums2[second]){
				nums1[end] = nums1[first];
				first--;
				end--;
			}
			else{
				nums1[end] = nums2[second];
				second--;
				end--;
			}
		}
		// nums2中还有数据没有插入nums1中
		while (second >= 0){
			nums1[end] = nums2[second];
			second--;
			end--;
		}
	}
};