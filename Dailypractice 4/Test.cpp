// 004��ɾ�����������е��ظ���
// ����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
// ��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������飬����ʹ�� O(1) ����ռ����������ɡ�
// ���� nums = [0,0,1,1,1,2,2,3,3,4],
// ����Ӧ�÷����µĳ��� 5, ����ԭ����nums��ǰ���Ԫ�ر��޸�Ϊ 0, 1, 2, 3, 4��

#include<iostream>
#include<vector>
using namespace std;

// �ⷨһ��˫ָ��
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		// ע������Ϊ�յ����
		if (nums.empty()){
			return 0;
		}
		// ����ָ��
		int slow = 0;
		int fast = 1;
		while (fast < nums.size()){
			if (nums[slow] == nums[fast]){
				fast++;
			}
			else{
				slow++;
				nums[slow] = nums[fast];
			}
		}
		return slow + 1;
	}
};

// �ⷨ������������
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		// ͳ�Ƶ�ǰԪ����Ҫǰ�Ƶ�λ��
		int count = 0;
		for (int i = 1; i < nums.size(); i++){
			if (nums[i - 1] == nums[i]){
				count++;
			}
			else{
				nums[i - count] = nums[i];
			}
		}
		return nums.size() - count;
	}
};