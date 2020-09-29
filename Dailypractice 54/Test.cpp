// 斐波那契数列（剑指Offer 10）
#include<iostream>
using namespace std;

// 避免大量的重复计算，使用从下向上计算的方式。

class Solution {
public:
	int fib(int n) {
		int array[2] = { 0, 1 };
		if (n < 2){
			return array[n];
		}

		int N = 0, NMinusOne = 1, NMinusTwo = 0;
		for (int cur = 2; cur <= n; cur++){
			// 采取从下往上的方法，把计算过的中间项保存起来，避免重复计算导致递归调用栈溢出
			N = (NMinusOne + NMinusTwo) % 1000000007;
			NMinusTwo = NMinusOne;
			NMinusOne = N;
		}
		return N;
	}
};
