// 020：括号匹配
// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 注意空字符串可被认为是有效字符串。
#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		// 判断字符串长度是否为奇数
		if (s.size() % 2 == 1){
			return false;
		}
		stack <char> t;
		for (char n : s){
			// 控制入栈
			if (n == '(')                t.push(')');
			else if (n == '{')           t.push('}');
			else if (n == '[')           t.push(']');
			// 控制出栈
			else{
				// 此时n为三种右括号之一，而栈顶也是三种右括号之一
				if (t.empty() || t.top() != n)      return false; 
				else        t.pop();
			}
		}
		return t.empty();
	}
};