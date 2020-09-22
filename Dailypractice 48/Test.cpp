// 替换空格（剑指Offer 5）
// 把字符串中的每个空格替换成“%20”
// 例如：We are happy  ->  We%20are%20happy

// 解题思路：
// 先遍历字符串，统计空格的总数，并且可以得到替换后新字符串的长度。
// 从字符串末尾开始复制和替换 (不需要开辟新数组)，指针P1指向原字符串的末尾，指针P2指向替换后字符串的末尾。
// 向前移动P1，逐个把它指向的字符复制到P2指向的位置。
// 直到碰到空格，把P1向前移动一个，在P2前插入%20，再将P2向前移动3个字符。
// 当P1和P2指向同一位置时，替换结束。

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string replaceSpace(string s) {
		// 判空
		if (s.empty())
			return s;

		int indexoforiginal = s.size();

		// 统计空格出现次数
		int spacecount = 0;
		for (auto c : s){
			if (c == ' ')
				++spacecount;
		}

		// 扩容
		s.resize(s.size() + spacecount * 2);
		int indexofnew = s.size();

		while (indexofnew != indexoforiginal){
			// 为空格则替换
			if (s[indexoforiginal] == ' '){
				s[indexofnew--] = '0';
				s[indexofnew--] = '2';
				s[indexofnew--] = '%';
			}
			else{
				s[indexofnew--] = s[indexoforiginal];
			}
			--indexoforiginal;
		}
		return s;
	}
};