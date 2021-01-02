// HotCode 003：不含有重复字符的最长字串

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

//  方法一：哈希表
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int prev = 0;
        int cur = 0;
        int count = 0;
        int result = 0;
        unordered_map<char, int> hashtable;

        // 遍历字符串
        while (cur < s.size()) {
            auto it = hashtable.find(s[cur]);
            // 当前元素在哈希表中 并且 当前元素的下标是大于prev的（重复）
            if (it != hashtable.end() && (it->second) >= prev) {
                prev = (it->second) + 1;
                count = cur - prev;
            }

            // 当前元素不在哈希表中则存入
            hashtable[s[cur]] = cur;
            cur++;
            count++;
            result = max(result, count);
        }

        return result;
    }
};