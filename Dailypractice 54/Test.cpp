// 쳲��������У���ָOffer 10��
#include<iostream>
using namespace std;

// ����������ظ����㣬ʹ�ô������ϼ���ķ�ʽ��

class Solution {
public:
	int fib(int n) {
		int array[2] = { 0, 1 };
		if (n < 2){
			return array[n];
		}

		int N = 0, NMinusOne = 1, NMinusTwo = 0;
		for (int cur = 2; cur <= n; cur++){
			// ��ȡ�������ϵķ������Ѽ�������м���������������ظ����㵼�µݹ����ջ���
			N = (NMinusOne + NMinusTwo) % 1000000007;
			NMinusTwo = NMinusOne;
			NMinusOne = N;
		}
		return N;
	}
};
