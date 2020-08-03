// 006����ת����
// ����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����
// Ҫ��ռ临�Ӷ�ΪO��1����ԭ���㷨
// ����: [1,2,3,4,5,6,7] �� k = 3
// ���: [5,6,7,1,2,3,4]

#include<iostream>
#include<vector>
using namespace std;

// ����һ���⺯��reverse��ת
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		// ע��kֵ����size�����
		k = k%nums.size();
		// ��תǰһ����Ԫ��
		reverse(nums.begin(), nums.end() - k);
		// ��ת��һ����Ԫ��
		reverse(nums.end() - k, nums.end());
		// ȫ����ת
		reverse(nums.begin(), nums.end());
	}
};

// ����������ת��
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k = k%nums.size();
		// ��תǰһ����Ԫ��
		for (int i = 0; i < (nums.size() - k) / 2; i++){
			swap(nums[i], nums[nums.size() - k - 1 - i]);
		}
		// ��ת��һ����Ԫ��
		int flag = 0;
		for (int i = nums.size() - k; i < nums.size() - k + k / 2; i++){
			swap(nums[i], nums[nums.size() - 1 - flag]);
			flag++;
		}
		// ȫ����ת
		for (int i = 0; i < nums.size() / 2; i++){
			swap(nums[i], nums[nums.size() - 1 - i]);
		}
	}
};