// 把数字翻译成字符串（剑指Offer 46）
// 给定一个数字，我们按照如下规则把它翻译为字符串
// 0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”

#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 一个数字可以有不同的翻译方法是因为可以合在一起翻译也可以分开翻译
// 定义数组DP[i]，表示前i+1位的翻译数
// 每往后加一位数字
// 若该数字不可以和前一位数字合在一起翻译，则dp[i] = dp[i-1]
// 若该数字可以和前一位数字合在一起翻译，可以选择是否合并
// 若前一位不为0，则不合并为 dp[i-1] 合并为 dp[i-2]   则dp[i] = dp[i-1]+dp[i-2]
// 若前一位为0，则dp[i] = dp[i-1]

class Solution {
public:
	int translateNum(int num) {
		// 个位数字只有一种翻译方式
		if (num < 10){
			return 1;
		}

		vector<int> vec;

		// 将数按位尾插进数组
		while (num){
			vec.push_back(num % 10);
			num = num / 10;
		}
		reverse(vec.begin(), vec.end());

		int ret = 0;
		int prev = 1;
		int next = 1;

		for (int cur = 1; cur < vec.size(); cur++){
			// 当前位与前一位不可以合并
			if (vec[cur - 1] == 0 || vec[cur - 1] * 10 + vec[cur] > 25){
				ret = prev;
			}
			// 当前位可以与前一位合并
			else{
				ret = prev + next;
			}

			next = prev;
			prev = ret;
		}

		return ret;
	}
};
