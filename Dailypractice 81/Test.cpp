// ��С��k��������ָOffer 40��

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

// ����
class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		if (arr.empty() || k == 0){
			return{};
		}
		vector<int> ret;
		sort(arr.begin(), arr.end());

		// ��arr������ȡǰk��������
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

// ���ô�ѣ����ȼ����У�
class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		if (arr.empty() || k == 0){
			return{};
		}
		vector<int> ret;
		priority_queue<int> maxheap;

		// ��arr��ǰk���������
		for (int cur = 0; cur < k; cur++){
			maxheap.push(arr[cur]);
		}

		// ���´��
		for (int pos = k; pos < arr.size(); pos++){
			if (arr[pos] < maxheap.top()){
				maxheap.pop();
				maxheap.push(arr[pos]);
			}
		}

		// ���뷵������
		for (int index = 0; index < k; index++){
			ret.push_back(maxheap.top());
			maxheap.pop();
		}

		return ret;
	}
};