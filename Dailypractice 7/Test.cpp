// 007��������ʽ�������ӷ�
// ���ڷǸ����� X ���ԣ�X ��������ʽ��ÿλ���ְ������ҵ�˳���γɵ����顣
// ���磬��� X = 1231����ô��������ʽΪ [1,2,3,1]��
// Ҫ������Ǹ����� X ��������ʽ A���������� X+K ��������ʽ��
// ���룺A = [1,2,0,0], K = 34
// �����[1, 2, 3, 4]

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> addToArrayForm(vector<int>& A, int K) {
		// ����Ҫ��������, ��ת����ԭ�����в���
		reverse(A.begin(), A.end());
		int index = 0;
		while (K > 0){
			// �ж�index�Ƿ�Խ��
			if (index < A.size()){
				// û��Խ��ֱ�Ӳ���
				K = K + A[index];
				A[index] = K % 10;
			}
			else{
				// Խ��ֱ��push
				A.push_back(K % 10);
			}
			K = K / 10;
			index++;
		}
		reverse(A.begin(), A.end());
		return A;
	}
};