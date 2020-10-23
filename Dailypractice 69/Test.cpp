// 栈的压入弹出序列（剑指Offer 31）
// 输入两个整数序列，第一个序列表示栈的压入序列，请判断第二个序列是否为栈的弹出序列。
// 假设压入栈的数字均不相等。

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// 一边将 pushed 元素入栈，一边判断是否能匹配上 popped 元素
// 匹配一个就出栈一个，直到不能匹配，就接着入栈
// 维持着一个动态的入栈出栈进程，直到 pushed 元素全部入栈了，也判断完是否能全部匹配了
// 此时栈空，true；栈非空，false

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		// 定义辅助栈
		stack<int> help;

		int pushsize = pushed.size();
		int popsize = popped.size();

		int pos = 0;

		for (int cur = 0; cur < pushsize; cur++){
			// 向辅助栈中压入入栈序列
			help.push(pushed[cur]);
			// 判断辅助栈栈顶元素是否与出栈序列匹配
			while (pos < popped.size() && !help.empty() && help.top() == popped[pos]){
				help.pop();
				pos++;
			}
		}

		return help.empty();
	}
};