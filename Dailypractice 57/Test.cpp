// ��ת�����е���С���֣���ָOffer 11��
// ��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�Ϊ�������ת��
// ����һ����������������һ����ת�������ת�������СԪ�ء�
// {3��4��5��1��2}Ϊ{1��2��3��4��5}��һ����ת��������������Сֵ1��

#include<iostream>
#include<vector>
using namespace std;

// �ⷨһ��
// ��ͷ��β��������һ�Σ������ҳ���С�����֡�
// ʱ�临�Ӷ� O(N)
class Solution{
public:
	int minArray(vector<int>& numbers){
		if (numbers.empty())
			return -1;
		if (numbers.size() == 1)
			return numbers[0];

		// ���������ҵ���СԪ��
		for (int cur = 0; cur < numbers.size(); cur++){
			if (cur + 1 < numbers.size()){
				if (numbers[cur + 1] < numbers[cur]){
					return numbers[cur + 1];
				}
			}
			else break;
		}

		return numbers[0];
	}
};

// �ⷨ����
// ��ת֮���������Ի���Ϊ���������������
// ǰ����������Ԫ�ض����ڻ���ں����������Ԫ��
// ��С��Ԫ�ظպþ���������������ķֽ���
// �������������ǿ����ö��ֲ���ʵ�� O(logN)�Ĳ���

class Solution{
public:
	int minArray(vector<int>& numbers){
		if (numbers.empty())
			return -1;
		if (numbers.size() == 1)
			return numbers[0];

		// ����ָ��ֱ�ָ����β
		int ptrhead = 0;
		int ptrend = numbers.size() - 1;
		// �м�Ԫ�أ�������תǰ0��Ԫ�أ���ֱ�ӷ�����Ԫ�أ�
		int mid = ptrhead;

		while (numbers[ptrhead] >= numbers[ptrend]){
			if (ptrend - ptrhead == 1){
				mid = ptrend;
				break;
			}
			mid = (ptrhead + ptrend) / 2;
			if (numbers[ptrhead] == numbers[ptrend] && numbers[ptrhead] == numbers[mid]){
				// ���������������ͬ�޷��ж���Сֵ�����䣬��ֻ��˳�����
				return findMin(numbers, ptrhead, ptrend);
			}
			// ��Сֵ��mid����mid�ĺ���
			if (numbers[mid] >= numbers[ptrhead]){
				ptrhead = mid;
			}
			// ��Сֵ��mid����mid��ǰ��
			else{
				ptrend = mid;
			}
		}
		return numbers[mid];
	}

	// ˳�����
	int findMin(vector<int>& numbers, int ptrhead, int ptrend){
		int ret = numbers[0];
		for (int cur = ptrhead + 1; cur <= ptrend; cur++){
			if (numbers[cur]<ret){
				ret = numbers[cur];
				break;
			}
		}
		return ret;
	}
};