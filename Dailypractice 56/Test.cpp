// 青蛙跳台阶（剑指Offer 10(2)）
// 斐波那契数列

#include<iostream>
using namespace std;

class Solution {
public:
	int numWays(int n) {
		if (n < 2){
			return 1;
		}

		int result = 0;
		int slow = 1;
		int fast = 1;

		// 自下向上计算，避免过多重复计算。
		for (int cur = 2; cur <= n; cur++){
			result = slow + fast;
			slow = fast;
			fast = result;
		}

		return result;
	}
};