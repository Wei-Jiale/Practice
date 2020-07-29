// 002：命名风格的转换
// C语言风格，使用下划线分隔多个单词，例如“hello_world”
// JAVA风格，除首个单词以外，所有单词的首字母大写，例如“helloWorld”
// 将C语言风格的变量名转换为JAVA风格的变量名

#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;
	while (cin >> str){
		// 遍历字符串
		for (int i = 0; i < str.size(); i++){
			// 遇到 '_' 直接跳过
			if (str[i] == '_'){
				continue;
			}
			// 若上一个字符是 "_" 则将这个字符转为大写字母
			if (i > 0 && str[i - 1] == '_'){
				// toupper返回值为 int 类型，需要隐式或者显式地将它转换为 char 类型
				cout << (char)toupper(str[i]);
			}
			else{
				cout << str[i];
			}
		}
		cout << endl;
	}
	return 0;
}