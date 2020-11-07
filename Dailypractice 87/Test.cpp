// �����������в������֣���ָOffer 53��
// ͳ��һ�����������������г��ֵĴ���

#include<iostream>
#include<vector>
using namespace std;

// ����: nums = [5,7,7,8,8,10], target = 8
// ���: 2

class Solution {
public:
	int search(vector<int>& nums, int target) {
		// ����Ϊ��
		if (nums.empty()){
			return 0;
		}

		int count = 0;
		int middle = 0;
		int start = 0;
		int end = nums.size() - 1;

		// ���ֲ���
		while (start <= end){
			// ÿ�����¸���middle
			middle = start + (end - start) / 2;

			if (nums[middle] > target){
				// Ŀ��ֵ���м�ֵ���������Ҫ����endλ��
				end = middle - 1;
			}
			else if (nums[middle] == target){
				// �ҵ�Ŀ��ֵ�����++ ��������ѭ��
				count++;
				break;
			}
			else{
				// Ŀ��ֵ���м�ָ���ұ�����Ҫ����startλ��
				start = middle + 1;
			}
		}

		// ��middle����������Ѱ�Ҹ�����
		if (nums[middle] == target){
			start = end = middle;
			while (--start >= 0 && nums[start] == target){
				count++;
			}

			while (++end < nums.size() && nums[end] == target){
				count++;
			}
		}

		return count;
	}
};