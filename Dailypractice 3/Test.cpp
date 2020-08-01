// 003���Ƴ�Ԫ��
// ����һ������ nums ��һ��ֵ val������Ҫԭ���Ƴ�������ֵ���� val ��Ԫ�أ��������Ƴ���������³��ȡ�
// ��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢ԭ���޸��������顣
// Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
#include<iostream>
#include<vector>
using namespace std;

// ����һ��������
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		vector<int>::iterator it = nums.begin();
		// ��ֹ�������������ߵ�����Ľ�β
		while (it != nums.end()){
			if (*it == val){
				// ɾ��valԪ��
				it = nums.erase(it);
			}
			else{
				++it;
			}
		}
		return nums.size();
	}
};

// ������������ָ��
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int slow = 0;
		int fast = 0;
		while (fast<nums.size()){
			// ��fast��=val��ʱ�򣬿���ָ��һ����ǰ
			if (nums[fast] != val){
				swap(nums[fast], nums[slow]);
				fast++;
				slow++;
			}
			else{
				// fast�ҵ���val
				fast++;
			}
		}
		return slow;
	}
};
