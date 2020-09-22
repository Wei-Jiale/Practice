// 二维数组中的查找（剑指Offer 4）
// 在一个二维数组中，行和列都是按照从左向右，从上向下依次递增的顺序排列
// 在这个二维数组中查找给出的数

#include<iostream>
#include<vector>
using namespace std;

// 解题思路：
// 选取右上角为基准值与目标值进行比较
// 每一次比较都能剔除一行或者一列，逐渐缩小范围。

class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		// 判空
		if (matrix.empty())
			return false;

		// 定义行列
		int rowsize = matrix.size();
		int colsize = matrix[0].size();
		int row = 0;
		int col = colsize - 1;

		while (row < rowsize && col >= 0){
			// 从矩阵的右上角开始匹配
			if (matrix[row][col] == target)
				return true;
			// 如果目标值比基准值大则去掉一行
			else if (matrix[row][col] < target)
				row++;
			// 如果目标值比基准值小则去掉一列
			else
				col--;
		}

		return false;
	}
};