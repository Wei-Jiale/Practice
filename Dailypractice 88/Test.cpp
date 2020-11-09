// ������ȱʧ�����֣���ָOffer 53��
// һ������Ϊn-1�ĵ������������е��������ֶ���Ψһ��
// ����ÿ�����ֶ��ڷ�Χ0��n-1֮�ڡ�
// �ڷ�Χ0��n-1�ڵ�n������������ֻ��һ�����ֲ��ڸ������У����ҳ�������֡�

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		assert(!nums.empty());

		int start = 0;
		int end = nums.size() - 1;

		// ������С�ڵ�������Ԫ��ʱ����ѭ��
		while (end > start){
			int middle = start + (end - start) / 2;

			if (nums[middle] > middle){
				// ȱʧ���������������
				end = middle - 1;
			}
			else{
				// ȱʧ���������Ұ�����
				start = middle + 1;
			}
		}


		if (nums[start] > start){
			return start;
		}

		return end + 1;
	}
};