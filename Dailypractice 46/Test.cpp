// 不修改数组找出重复的数字（剑指Offer 3(2)）
// 在一个长度为 n+1 的数组里的所有数字都在1到n的范围内
// 所以数组中至少有一个数字是重复的
// 请找出数组中任意一个重复的数字，但不能修改输入的数组

#include<iostream>
#include<vector>
using namespace std;

// 解法一：由于不能修改数组，我们可以创建一个长度为n+1的辅助数组。
//         将原数组中值为m的数字放入辅助数组下标为m的位置，这样就很容易发现哪个数字是重复的。
//         额外空间 O(n)

// 解法二：将1到n的数字从中间数字m分成两组，前一半为1到m，后一半为m+1到n
//         若1到m的数字的数目超过m，那么这一半的区间里一定包含重复的数字
//         否则，另一半m+1到n的区间中包含重复的数字
//         继续将包含重复数字的区间一分为二，直到找到一个重复的数字

int FindDuplicate(vector<int>& array){
	int start = 1;
	int end = array.size();

	while (start < end){
		// 取区间的中值为基准值
		int middle = start + (end - start) >> 1;

		// 计算数组中所有小于等于基准值的元素个数
		int count = 0;
		for (auto e : array){
			if (e <= middle){
				++count;
			}
		}

		// 如果个数小于等于基准值，说明重复元素在[基准值+1，n]的范围内 
		if (count <= middle){
			start = middle + 1;
		}
		else{
			end = middle;
		}
	}

	return start;
}