// ��������1�ĸ�������ָOffer 15��

#include<iostream>
using namespace std;

// ����˼·��
// n-1����n�����ұߵ�1��Ϊ0��1�����λ��Ϊ1��
// (n-1) & n����n�����ұߵ�1��Ϊ0
// n���м���1���㷨�������������㣬��������Ч�ʡ�

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