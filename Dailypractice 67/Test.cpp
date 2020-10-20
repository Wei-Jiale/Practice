// ˳ʱ���ӡ���󣨽�ָOffer 29��
// ����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֡�

#include<iostream>
#include<vector>
using namespace std;

// ����Ȧ����Ȧ��˳����д�ӡ��ÿ�δ�ӡ�����е�һ��Ȧ

// ��ӡ����
// ÿһȦ��ʼλ�õ��б���б�����ͬ��
// ��ӡ����ѭ�������������� col>start��2 ���� row>start��2

// ��ӡһȦ
// ������ -> ���ϵ��� -> ���ҵ��� -> ���µ���
// ÿһ�л�һ�и�����ʼ�������ֹ������һ��ѭ���Ϳ��Դ�ӡ
// �������һȦ�����˻���һ�С�һ�С�һ������
// ��һ���϶�����
// �ڶ�����ǰ�⣺��ֹ�кŴ�����ʼ�кţ�����һ�У�
// ��������ǰ�⣺��ֹ�кŴ�����ʼ�к� ���� ��ֹ�кŴ�����ʼ�кţ��������У�
// ���Ĳ���ǰ�⣺��ֹ�кű���ʼ�кŴ�2 ���� ��ֹ�кŴ�����ʼ�кţ��������У�

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].size() == 0)
			return vector<int>();

		vector<int> ret;
		int row = matrix.size();
		int col = matrix[0].size();

		// ÿ��Ȧ�����
		int start = 0;

		while (row > start * 2 && col>start * 2){
			// ѭ�����ô�ӡÿһȦ�ĺ�������ӡ����
			PrintCircle(matrix, row, col, start, ret);
			start++;
		}

		return ret;
	}

	// ��ret��������ÿһȦ��Ԫ��
	void PrintCircle(vector<vector<int>>& matrix, int row, int col, int start, vector<int>& ret){
		int rowend = row - 1 - start;
		int colend = col - 1 - start;

		// ��һ���������Ҵ�ӡ
		for (int cur = start; cur <= colend; cur++){
			ret.push_back(matrix[start][cur]);
		}
		// �ڶ��������ϵ��´�ӡ
		if (rowend > start){
			for (int cur = start + 1; cur <= rowend; cur++){
				ret.push_back(matrix[cur][colend]);
			}
		}
		// �����������������ӡ
		if (rowend > start && colend > start){
			for (int cur = colend - 1; cur >= start; cur--){
				ret.push_back(matrix[rowend][cur]);
			}
		}
		// ���Ĳ����������ϴ�ӡ
		if (rowend - 2 >= start && colend >start){
			for (int cur = rowend - 1; cur>start; cur--){
				ret.push_back(matrix[cur][start]);
			}
		}
	}
};