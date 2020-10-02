// 二进制中1的个数（剑指Offer 15）

#include<iostream>
using namespace std;

// 解题思路：
// n-1：将n的最右边的1变为0，1后面的位变为1。
// (n-1) & n：将n的最右边的1变为0
// n中有几个1，算法就做几次与运算，大大提高了效率。

class Solution {
public:
	int hammingWeight(int n) {
		int count = 0;
		while (n){
			++count;
			n = (n - 1) & n;
		}

		return count;
	}
};