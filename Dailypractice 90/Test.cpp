// ���������ֳ��ֵĴ�������ָOffer 56��
// һ�����������У������������֣��������ֶ����������Ρ�
// �ҳ�ֻ������һ�ε����֡�
// ���룺nums = [1,2,10,4,1,4,3,3]
// �����[2, 10] ��[10, 2]

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		unordered_map<int, int> res;
		vector<int> number;
		for (int i = 0; i < nums.size(); i++) {
			res[nums[i]]++;
		}
		for (auto c : nums) {
			if (res[c] == 1) {
				number.emplace_back(c);
			}
		}
		return number;
	}
};