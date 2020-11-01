// 把数组排成最小的数（剑指Offer 45）
// 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// 无论这些数字怎么进行排列，位数都是不会发生变化的。
// 高位的数字越小越好
// 放数字的顺序首先是第一位最小的数字，若第一位相等则比较第二位。
// 把所有的数字转换成字符串再进行排列
// 3 30 明显30放在前面是正确排法

class Solution {
public:
	string minNumber(vector<int>& nums) {
		vector<string> str;
		string ret;

		// 整型转字符
		for (int cur = 0; cur<nums.size(); cur++){
			str.push_back(to_string(nums[cur]));
		}

		// 排序
		sort(str.begin(), str.end(), [](string& s1, string& s2){return s1 + s2<s2 + s1; });

		// 字符串排列
		for (int cur = 0; cur<str.size(); cur++){
			ret = ret + str[cur];
		}

		return ret;
	}
};