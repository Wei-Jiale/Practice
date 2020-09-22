// ��ά�����еĲ��ң���ָOffer 4��
// ��һ����ά�����У��к��ж��ǰ��մ������ң������������ε�����˳������
// �������ά�����в��Ҹ�������

#include<iostream>
#include<vector>
using namespace std;

// ����˼·��
// ѡȡ���Ͻ�Ϊ��׼ֵ��Ŀ��ֵ���бȽ�
// ÿһ�αȽ϶����޳�һ�л���һ�У�����С��Χ��

class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		// �п�
		if (matrix.empty())
			return false;

		// ��������
		int rowsize = matrix.size();
		int colsize = matrix[0].size();
		int row = 0;
		int col = colsize - 1;

		while (row < rowsize && col >= 0){
			// �Ӿ�������Ͻǿ�ʼƥ��
			if (matrix[row][col] == target)
				return true;
			// ���Ŀ��ֵ�Ȼ�׼ֵ����ȥ��һ��
			else if (matrix[row][col] < target)
				row++;
			// ���Ŀ��ֵ�Ȼ�׼ֵС��ȥ��һ��
			else
				col--;
		}

		return false;
	}
};