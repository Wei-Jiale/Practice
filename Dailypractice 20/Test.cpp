// 020������ƥ��
// ����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��
// �����ű�������ͬ���͵������űպϡ�
// �����ű�������ȷ��˳��պϡ�
// ע����ַ����ɱ���Ϊ����Ч�ַ�����
#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		// �ж��ַ��������Ƿ�Ϊ����
		if (s.size() % 2 == 1){
			return false;
		}
		stack <char> t;
		for (char n : s){
			// ������ջ
			if (n == '(')                t.push(')');
			else if (n == '{')           t.push('}');
			else if (n == '[')           t.push(']');
			// ���Ƴ�ջ
			else{
				// ��ʱnΪ����������֮һ����ջ��Ҳ������������֮һ
				if (t.empty() || t.top() != n)      return false; 
				else        t.pop();
			}
		}
		return t.empty();
	}
};