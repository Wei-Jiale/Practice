#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // 判断字符串单双
        if (s.size() % 2 != 0) {
            return false;
        }

        stack<char> st;

        // 遍历字符串栈模拟匹配
        for (auto cur : s) {
            // 若是左括号则就压入它的对应右括号等待右括号匹配
            if (cur == '(') {
                st.push(')');
            }
            else if (cur == '{') {
                st.push('}');
            }
            else if (cur == '[') {
                st.push(']');
            }
            else {
                // 不是左括号则匹配（匹配之前检查栈中是否有字符串）
                if (st.empty() || cur != st.top()) {
                    // 栈中没有再匹配的元素则返回false
                    return false;
                }
                else {
                    // 匹配成功则出栈顶元素
                    st.pop();
                }
            }
        }

        // 没有右括号匹配也返回false
        return st.empty();
    }
};