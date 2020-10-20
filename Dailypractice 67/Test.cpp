// 顺时针打印矩阵（剑指Offer 29）
// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

#include<iostream>
#include<vector>
using namespace std;

// 从外圈到内圈的顺序进行打印，每次打印矩阵中的一个圈

// 打印矩阵
// 每一圈起始位置的行标和列标是相同的
// 打印矩阵循环继续的条件是 col>start×2 并且 row>start×2

// 打印一圈
// 从左到右 -> 从上到下 -> 从右到左 -> 从下到上
// 每一行或一列根据起始坐标和终止坐标用一个循环就可以打印
// 不过最后一圈可能退化成一行、一列、一个数字
// 第一步肯定都有
// 第二步的前题：终止行号大于起始行号（两行一列）
// 第三步的前题：终止行号大于起始行号 并且 终止列号大于起始列号（两行两列）
// 第四步的前题：终止行号比起始行号大2 并且 终止列号大于起始列号（三行两列）

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].size() == 0)
			return vector<int>();

		vector<int> ret;
		int row = matrix.size();
		int col = matrix[0].size();

		// 每个圈的起点
		int start = 0;

		while (row > start * 2 && col>start * 2){
			// 循环调用打印每一圈的函数来打印矩阵
			PrintCircle(matrix, row, col, start, ret);
			start++;
		}

		return ret;
	}

	// 像ret数组输入每一圈的元素
	void PrintCircle(vector<vector<int>>& matrix, int row, int col, int start, vector<int>& ret){
		int rowend = row - 1 - start;
		int colend = col - 1 - start;

		// 第一步：从左到右打印
		for (int cur = start; cur <= colend; cur++){
			ret.push_back(matrix[start][cur]);
		}
		// 第二步：从上到下打印
		if (rowend > start){
			for (int cur = start + 1; cur <= rowend; cur++){
				ret.push_back(matrix[cur][colend]);
			}
		}
		// 第三步：从右向左打印
		if (rowend > start && colend > start){
			for (int cur = colend - 1; cur >= start; cur--){
				ret.push_back(matrix[rowend][cur]);
			}
		}
		// 第四步：从下向上打印
		if (rowend - 2 >= start && colend >start){
			for (int cur = rowend - 1; cur>start; cur--){
				ret.push_back(matrix[cur][start]);
			}
		}
	}
};