// ջ��ѹ�뵯�����У���ָOffer 31��
// ���������������У���һ�����б�ʾջ��ѹ�����У����жϵڶ��������Ƿ�Ϊջ�ĵ������С�
// ����ѹ��ջ�����־�����ȡ�

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// һ�߽� pushed Ԫ����ջ��һ���ж��Ƿ���ƥ���� popped Ԫ��
// ƥ��һ���ͳ�ջһ����ֱ������ƥ�䣬�ͽ�����ջ
// ά����һ����̬����ջ��ջ���̣�ֱ�� pushed Ԫ��ȫ����ջ�ˣ�Ҳ�ж����Ƿ���ȫ��ƥ����
// ��ʱջ�գ�true��ջ�ǿգ�false

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		// ���帨��ջ
		stack<int> help;

		int pushsize = pushed.size();
		int popsize = popped.size();

		int pos = 0;

		for (int cur = 0; cur < pushsize; cur++){
			// ����ջ��ѹ����ջ����
			help.push(pushed[cur]);
			// �жϸ���ջջ��Ԫ���Ƿ����ջ����ƥ��
			while (pos < popped.size() && !help.empty() && help.top() == popped[pos]){
				help.pop();
				pos++;
			}
		}

		return help.empty();
	}
};