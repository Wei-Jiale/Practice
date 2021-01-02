// HotCode 003���������ظ��ַ�����ִ�

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

//  ����һ����ϣ��
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int prev = 0;
        int cur = 0;
        int count = 0;
        int result = 0;
        unordered_map<char, int> hashtable;

        // �����ַ���
        while (cur < s.size()) {
            auto it = hashtable.find(s[cur]);
            // ��ǰԪ���ڹ�ϣ���� ���� ��ǰԪ�ص��±��Ǵ���prev�ģ��ظ���
            if (it != hashtable.end() && (it->second) >= prev) {
                prev = (it->second) + 1;
                count = cur - prev;
            }

            // ��ǰԪ�ز��ڹ�ϣ���������
            hashtable[s[cur]] = cur;
            cur++;
            count++;
            result = max(result, count);
        }

        return result;
    }
};