// HotCode 009：电话号码的数字组合

#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ret;

		if (digits.empty()) {
			return ret;
		}

		// 用map组织数字和字母的映射关系
		map<char, string> val_map = {
			{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
			{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
		};

		// 工作队列
		queue<string> val_queue;
		val_queue.push("");

		// 遍历输入字符
		for (auto cur : digits) {
			// 在哈希表中查找当前字符对应的字母串
			string cur_str = val_map[cur];
			int sz = val_queue.size();

			// 当前层添加字母串
			for (int index = 0; index < sz; index++) {
				string temp_str = val_queue.front();
				val_queue.pop();
				// 遍历字母串进行逐个添加
				for (auto val_cur : cur_str) {
					val_queue.push(temp_str + val_cur);
				}
			}
		}

		while (!val_queue.empty()) {
			string out_str = val_queue.front();
			val_queue.pop();
			ret.push_back(out_str);
		}

		return ret;
	}
};