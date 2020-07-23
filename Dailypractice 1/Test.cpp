// 001：交错序列
// 定义一个由数字0和1组成的序列，当且仅当在这个序列中0和1是轮流出现的，比如，0，010，10101 该序列才是交错序列
// 现在给出了一个由数字0和1组成的序列𝐴
// A可能不是一个交错序列，但是你可以从这个序列中选取𝐴的一个子序列，得到的是一个交错序列
// 这样能得到的交错序列的最长长度是多少。

#include<iostream>
using namespace std;

int main(){
	int n; // 输入的数字个数
	int res = 1; // 返回的交错序列最长长度（最小为1）
	cin >> n;
	int* array = new int[n]; // 读入数字个数n，使用new创建长度为n的动态数组array
	for (int i = 0; i < n; i++){
		cin >> array[i];
	}
	for (int i = 0; i < n - 1; i++){ 
		if (array[i] != array[i + 1]){ // 前一个数和后一个数不同则证明可以组成交错序列
			res++;
		}
	}
	cout << res << endl; // 输出最长交错序列的长度
	return 0;
}