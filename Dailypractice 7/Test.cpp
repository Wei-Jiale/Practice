// 007：数组形式的整数加法
// 对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。
// 例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。
// 要求给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。
// 输入：A = [1,2,0,0], K = 34
// 输出：[1, 2, 3, 4]

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> addToArrayForm(vector<int>& A, int K) {
		// 不需要额外数组, 翻转后在原数组中操作
		reverse(A.begin(), A.end());
		int index = 0;
		while (K > 0){
			// 判断index是否越界
			if (index < A.size()){
				// 没有越界直接插入
				K = K + A[index];
				A[index] = K % 10;
			}
			else{
				// 越界直接push
				A.push_back(K % 10);
			}
			K = K / 10;
			index++;
		}
		reverse(A.begin(), A.end());
		return A;
	}
};