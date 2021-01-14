// HotCode 013：括号生成

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		// 定义返回数组 以及 左右括号的个数
		vector<string> ret;
		int leftcount = 0;
		int rightcount = 0;

		// 传入ret 和 path
		dfs(ret, "", n, leftcount, rightcount);
		
		return ret;
	}

	void dfs(vector<string>& ret, string path, int n, int leftcount, int rightcount) {
		// path 动态更新可能的结果
		if (leftcount > n || rightcount > leftcount || rightcount > n) {
			return;
		}
		// 满足要求则压入结果ret
		if (leftcount == rightcount && leftcount == n) {
			ret.push_back(path);
			return;
		}

		dfs(ret, path + '(', n, leftcount + 1, rightcount);
		dfs(ret, path + ')', n, leftcount, rightcount + 1);
	}
};