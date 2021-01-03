// HotCode 005：最长回文子串

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";

        // 遍历字符数组（设置中心字符）
        for (int cur = 0; cur < s.size(); cur++) {
            string sig_str = Center(s, cur, cur);
            string dou_str = Center(s, cur, cur + 1);

            if (sig_str.length() > result.length()) {
                result = sig_str;
            }

            if (dou_str.length() > result.length()) {
                result = dou_str;
            }
        }

        return result;
    }

    string Center(string& s, int left, int right) {
        // 从中心向两端扩展控制边界条件和约束条件
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }

        // 截断字符串返回
        // 最后一次多了left--；和 right++ 
        return s.substr(left + 1, right - left - 1);
    }
};