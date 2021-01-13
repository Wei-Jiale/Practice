#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // �ж��ַ�����˫
        if (s.size() % 2 != 0) {
            return false;
        }

        stack<char> st;

        // �����ַ���ջģ��ƥ��
        for (auto cur : s) {
            // �������������ѹ�����Ķ�Ӧ�����ŵȴ�������ƥ��
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
                // ������������ƥ�䣨ƥ��֮ǰ���ջ���Ƿ����ַ�����
                if (st.empty() || cur != st.top()) {
                    // ջ��û����ƥ���Ԫ���򷵻�false
                    return false;
                }
                else {
                    // ƥ��ɹ����ջ��Ԫ��
                    st.pop();
                }
            }
        }

        // û��������ƥ��Ҳ����false
        return st.empty();
    }
};