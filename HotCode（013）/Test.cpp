// HotCode 013����������

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		// ���巵������ �Լ� �������ŵĸ���
		vector<string> ret;
		int leftcount = 0;
		int rightcount = 0;

		// ����ret �� path
		dfs(ret, "", n, leftcount, rightcount);
		
		return ret;
	}

	void dfs(vector<string>& ret, string path, int n, int leftcount, int rightcount) {
		// path ��̬���¿��ܵĽ��
		if (leftcount > n || rightcount > leftcount || rightcount > n) {
			return;
		}
		// ����Ҫ����ѹ����ret
		if (leftcount == rightcount && leftcount == n) {
			ret.push_back(path);
			return;
		}

		dfs(ret, path + '(', n, leftcount + 1, rightcount);
		dfs(ret, path + ')', n, leftcount, rightcount + 1);
	}
};