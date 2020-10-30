// �ַ��������У���ָOffer 38��
// ����һ���ַ�������ӡ�����ַ������ַ����������С�
// ����������˳�򷵻��ַ������飬���������ظ������֡�
// ���룺s = "abc"
// �����["abc", "acb", "bac", "bca", "cab", "cba"]

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// ���� s = "abc"
// ������a�ڵ�0λ��b���ڵ�0λ��c���ڵ�0λ

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
		// ĳ��·��ͷ�ŵ�β�ˣ��Ͱ�����·����ret
		if (pos == s_copy.length() - 1){
			ret.push_back(s_copy);
			return;
		}

		unordered_set<char> unset;
		for (int cur = pos; cur < s_copy.length(); ++cur){
			if (unset.count(s_copy[cur])){
				// �ظ�Ԫ�ز���Ҫ����
				continue;
			}
			// ���ظ�
			unset.insert(s_copy[cur]);
			swap(s_copy[cur], s_copy[pos]);
			dfs(pos + 1);
			swap(s_copy[cur], s_copy[pos]);
		}
	}
};