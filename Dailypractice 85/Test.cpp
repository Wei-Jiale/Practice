// ��һ��ֻ����һ�ε��ַ�����ָOffer 50��
// ���ַ������ҵ���һ��ֻ����һ�ε��ַ�
// ���û�з���һ�����ո�

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	char firstUniqChar(string s) {
		vector<char> keys;
		unordered_map<char, bool> dic;

		// �����ַ���
		for (char c : s) {
			// ���ҵ�ǰ�ַ��Ƿ����map��
			if (dic.find(c) == dic.end()){
				// �����������vector
				keys.push_back(c);
			}
			// �������޸�bool �����������
			dic[c] = dic.find(c) == dic.end();
		}

		// ����vector ��map�в���bool�Ƿ�Ϊtrue
		for (char c : keys) {
			if (dic[c]) return c;
		}

		return ' ';
	}
};