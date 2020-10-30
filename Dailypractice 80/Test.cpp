// 字符串的排列（剑指Offer 38）
// 输入一个字符串，打印出该字符串中字符的所有排列。
// 可以以任意顺序返回字符串数组，但不能有重复的数字。
// 输入：s = "abc"
// 输出：["abc", "acb", "bac", "bca", "cab", "cba"]

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// 假设 s = "abc"
// 首先让a在第0位，b再在第0位，c再在第0位

class Solution {
	vector<string> ret;
	string s_copy;
public:
	vector<string> permutation(string s) {
		if (s.empty()){
			return vector<string>();
		}

		s_copy = s;
		dfs(0);
		return ret;
	}

	void dfs(int pos){
		// 某条路从头排到尾了，就把这条路输入ret
		if (pos == s_copy.length() - 1){
			ret.push_back(s_copy);
			return;
		}

		unordered_set<char> unset;
		for (int cur = pos; cur < s_copy.length(); ++cur){
			if (unset.count(s_copy[cur])){
				// 重复元素不需要再排
				continue;
			}
			// 不重复
			unset.insert(s_copy[cur]);
			swap(s_copy[cur], s_copy[pos]);
			dfs(pos + 1);
			swap(s_copy[cur], s_copy[pos]);
		}
	}
};