// 最小的k个数（剑指Offer 40）

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

// 排序
class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		if (arr.empty() || k == 0){
			return{};
		}
		vector<int> ret;
		sort(arr.begin(), arr.end());

		// 对arr排序再取前k个数即可
		for (auto cur : arr){
			if (k <= 0){
				break;
			}
			ret.push_back(cur);
			k--;
		}

		return ret;
	}
};

// 利用大堆（优先级队列）
class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		if (arr.empty() || k == 0){
			return{};
		}
		vector<int> ret;
		priority_queue<int> maxheap;

		// 用arr的前k个数填充大堆
		for (int cur = 0; cur < k; cur++){
			maxheap.push(arr[cur]);
		}

		// 更新大堆
		for (int pos = k; pos < arr.size(); pos++){
			if (arr[pos] < maxheap.top()){
				maxheap.pop();
				maxheap.push(arr[pos]);
			}
		}

		// 输入返回数组
		for (int index = 0; index < k; index++){
			ret.push_back(maxheap.top());
			maxheap.pop();
		}

		return ret;
	}
};