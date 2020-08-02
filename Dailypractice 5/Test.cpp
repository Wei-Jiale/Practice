// 005���ϲ�������������
// �������������������� nums1 �� nums2�����㽫 nums2 �ϲ��� nums1 �У�ʹ nums1 ��Ϊһ���������顣
// ��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n 
// ����Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�
// ���룺nums1 = [1,2,3,0,0,0], m = 3��nums2 = [2, 5, 6], n = 3
// ���: [1,2,2,3,5,6]

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		// nums1�����һ��Ԫ�ص��±�
		int first = m - 1;
		// nums2�����һ��Ԫ�ص��±�
		int second = n - 1;
		// nums1�����һ��λ�õ��±�
		int end = m + n - 1;
		while (second >= 0 && first >= 0){
			// ����Ƚ���������Ԫ�أ��ϴ�Ĳ���nums1��end��
			if (nums1[first] >= nums2[second]){
				nums1[end] = nums1[first];
				first--;
				end--;
			}
			else{
				nums1[end] = nums2[second];
				second--;
				end--;
			}
		}
		// nums2�л�������û�в���nums1��
		while (second >= 0){
			nums1[end] = nums2[second];
			second--;
			end--;
		}
	}
};