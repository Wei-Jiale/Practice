// �滻�ո񣨽�ָOffer 5��
// ���ַ����е�ÿ���ո��滻�ɡ�%20��
// ���磺We are happy  ->  We%20are%20happy

// ����˼·��
// �ȱ����ַ�����ͳ�ƿո�����������ҿ��Եõ��滻�����ַ����ĳ��ȡ�
// ���ַ���ĩβ��ʼ���ƺ��滻 (����Ҫ����������)��ָ��P1ָ��ԭ�ַ�����ĩβ��ָ��P2ָ���滻���ַ�����ĩβ��
// ��ǰ�ƶ�P1���������ָ����ַ����Ƶ�P2ָ���λ�á�
// ֱ�������ո񣬰�P1��ǰ�ƶ�һ������P2ǰ����%20���ٽ�P2��ǰ�ƶ�3���ַ���
// ��P1��P2ָ��ͬһλ��ʱ���滻������

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string replaceSpace(string s) {
		// �п�
		if (s.empty())
			return s;

		int indexoforiginal = s.size();

		// ͳ�ƿո���ִ���
		int spacecount = 0;
		for (auto c : s){
			if (c == ' ')
				++spacecount;
		}

		// ����
		s.resize(s.size() + spacecount * 2);
		int indexofnew = s.size();

		while (indexofnew != indexoforiginal){
			// Ϊ�ո����滻
			if (s[indexoforiginal] == ' '){
				s[indexofnew--] = '0';
				s[indexofnew--] = '2';
				s[indexofnew--] = '%';
			}
			else{
				s[indexofnew--] = s[indexoforiginal];
			}
			--indexoforiginal;
		}
		return s;
	}
};