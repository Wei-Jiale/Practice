// ������̨�ף���ָOffer 10(2)��
// 쳲���������

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

		// �������ϼ��㣬��������ظ����㡣
		for (int cur = 2; cur <= n; cur++){
			result = slow + fast;
			slow = fast;
			fast = result;
		}

		return result;
	}
};