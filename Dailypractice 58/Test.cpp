// 数值的整数次方（剑指Offer 16）
// 实现函数 doble Power(double base, int exponent)
// 求base的exponent次方
// 不得使用库函数，不需要考虑大数问题

#include<iostream>
using namespace std;

// 考虑指数为0或负数的时候的解决方案

class Solution {
public:
	double myPow(double x, int n){
		// 考虑特殊输入
		if (x == 1.0 || n == 0)
			return 1.0;
		if (x == 0.0 && n < 0)
			return x;

		double ret = 1.0;
		long exponent = n;

		// 指数为负数
		if (n < 0){
			x = 1 / x;
			exponent = -exponent;
		}

		while (exponent){
			// 快速乘方
			// 假如n=9，写为二进制就是1001
			if (exponent & 1 == 1){
				ret = ret * x;
			}
			// 先求平方，在平方的基础上求四次方，在四次方的基础上求八次方……
			x = x*x;
			exponent = exponent >> 1;
		}

		return ret;
	}
};