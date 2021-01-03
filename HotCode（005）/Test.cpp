// HotCode 005��������Ӵ�

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";

        // �����ַ����飨���������ַ���
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
        // ��������������չ���Ʊ߽�������Լ������
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }

        // �ض��ַ�������
        // ���һ�ζ���left--���� right++ 
        return s.substr(left + 1, right - left - 1);
    }
};