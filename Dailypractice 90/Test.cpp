// 数组中数字出现的次数（剑指Offer 56）
// 一个整型数组中，除了两个数字，其它数字都出现了两次。
// 找出只出现了一次的数字。
// 输入：nums = [1,2,10,4,1,4,3,3]
// 输出：[2, 10] 或[10, 2]

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		unordered_map<int, int> res;
		vector<int> number;
		for (int i = 0; i < nums.size(); i++) {
			res[nums[i]]++;
		}
		for (auto c : nums) {
			if (res[c] == 1) {
				number.emplace_back(c);
			}
		}
		return number;
	}
};