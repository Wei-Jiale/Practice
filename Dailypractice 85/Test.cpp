// 第一个只出现一次的字符（剑指Offer 50）
// 在字符串中找到第一个只出现一次的字符
// 如果没有返回一个单空格

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	char firstUniqChar(string s) {
		vector<char> keys;
		unordered_map<char, bool> dic;

		// 遍历字符串
		for (char c : s) {
			// 查找当前字符是否存在map中
			if (dic.find(c) == dic.end()){
				// 不存在则插入vector
				keys.push_back(c);
			}
			// 存在则修改bool 不存在则插入
			dic[c] = dic.find(c) == dic.end();
		}

		// 遍历vector 在map中查找bool是否为true
		for (char c : keys) {
			if (dic[c]) return c;
		}

		return ' ';
	}
};