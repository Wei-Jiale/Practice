// 033���������Ĺ����Լ�����
// �����û������һ��ǰ������ַ��������ݴ��ַ�������һ����������
// ������˶������Ժ��ٶԶ������������������������������

// ��ջʱ���� = ǰ��
// ��ջʱ���� = ����

#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
	string str;
	while (cin >> str){
		stack<char> st;
		for (auto it : str){
			// �ǿ�����ջ��ǰ��
			if (it != '#'){
				st.push(it);
			}
			else{
				// �����ջ������
				if (!st.empty()){
					cout << st.top() << ' ';
					st.pop();
				}
			}
		}
	}
}