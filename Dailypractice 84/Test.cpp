// �����ַ�����ַ�������ָOffer 46��
// ����һ�����֣����ǰ������¹����������Ϊ�ַ���
// 0 ����� ��a�� ��1 ����� ��b����������11 ����� ��l����������25 ����� ��z��

#include<iostream>
#include<string>
#include<vector>
using namespace std;

// һ�����ֿ����в�ͬ�ķ��뷽������Ϊ���Ժ���һ����Ҳ���Էֿ�����
// ��������DP[i]����ʾǰi+1λ�ķ�����
// ÿ�����һλ����
// �������ֲ����Ժ�ǰһλ���ֺ���һ���룬��dp[i] = dp[i-1]
// �������ֿ��Ժ�ǰһλ���ֺ���һ���룬����ѡ���Ƿ�ϲ�
// ��ǰһλ��Ϊ0���򲻺ϲ�Ϊ dp[i-1] �ϲ�Ϊ dp[i-2]   ��dp[i] = dp[i-1]+dp[i-2]
// ��ǰһλΪ0����dp[i] = dp[i-1]

class Solution {
public:
	int translateNum(int num) {
		// ��λ����ֻ��һ�ַ��뷽ʽ
		if (num < 10){
			return 1;
		}

		vector<int> vec;

		// ������λβ�������
		while (num){
			vec.push_back(num % 10);
			num = num / 10;
		}
		reverse(vec.begin(), vec.end());

		int ret = 0;
		int prev = 1;
		int next = 1;

		for (int cur = 1; cur < vec.size(); cur++){
			// ��ǰλ��ǰһλ�����Ժϲ�
			if (vec[cur - 1] == 0 || vec[cur - 1] * 10 + vec[cur] > 25){
				ret = prev;
			}
			// ��ǰλ������ǰһλ�ϲ�
			else{
				ret = prev + next;
			}

			next = prev;
			prev = ret;
		}

		return ret;
	}
};
