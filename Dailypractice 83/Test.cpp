// �������ų���С��������ָOffer 45��
// ����һ���Ǹ��������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// ������Щ������ô�������У�λ�����ǲ��ᷢ���仯�ġ�
// ��λ������ԽСԽ��
// �����ֵ�˳�������ǵ�һλ��С�����֣�����һλ�����Ƚϵڶ�λ��
// �����е�����ת�����ַ����ٽ�������
// 3 30 ����30����ǰ������ȷ�ŷ�

class Solution {
public:
	string minNumber(vector<int>& nums) {
		vector<string> str;
		string ret;

		// ����ת�ַ�
		for (int cur = 0; cur<nums.size(); cur++){
			str.push_back(to_string(nums[cur]));
		}

		// ����
		sort(str.begin(), str.end(), [](string& s1, string& s2){return s1 + s2<s2 + s1; });

		// �ַ�������
		for (int cur = 0; cur<str.size(); cur++){
			ret = ret + str[cur];
		}

		return ret;
	}
};