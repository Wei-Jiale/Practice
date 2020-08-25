// 033：二叉树的构建以及遍历
// 读入用户输入的一串前序遍历字符串，根据此字符串建立一个二叉树。
// 建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。

// 入栈时访问 = 前序
// 出栈时访问 = 中序

#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
	string str;
	while (cin >> str){
		stack<char> st;
		for (auto it : str){
			// 非空则入栈（前序）
			if (it != '#'){
				st.push(it);
			}
			else{
				// 空则出栈（中序）
				if (!st.empty()){
					cout << st.top() << ' ';
					st.pop();
				}
			}
		}
	}
}