// ��������������ͣ���ָOffer 41��
// ����һ����������
// ������һ�����߶���������������һ��������
// ������������ĺ͵����ֵ

#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		assert(!nums.empty());

		// ����ȫ�ֱ���maxSum
		int maxSum = nums[0];
		int sz = nums.size();

		for (int cur = 1; cur<sz; cur++){
			// ��ǰһ��������0��͵�ǰ���ۼ�
			if (nums[cur - 1] > 0){
				nums[cur] = nums[cur - 1] + nums[cur];
			}
			// ����maxSum
			maxSum = max(nums[cur], maxSum);
		}

		return maxSum;
	}
};