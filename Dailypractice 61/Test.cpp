// ���������˳��ʹ����λ��ż��ǰ����ָOffer 21��
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		// �п�
		if (nums.empty() || nums.size() == 1){
			return nums;
		}

		// ����ǰ��ָ��
		int begin = 0;
		int end = nums.size() - 1;

		while (begin < end){
			// ����ƶ�beginֱ��ָ��ż��
			while (begin < end && ((nums[begin] & 1) != 0)){
				begin++;
			}
			// ��ǰ�ƶ�endֱ��ָ������
			while (begin < end && ((nums[end] & 1) == 0)){
				end--;
			}
			// ��������ż��
			if (begin < end){
				swap(nums[begin], nums[end]);
			}
		}

		return nums;
	}
};