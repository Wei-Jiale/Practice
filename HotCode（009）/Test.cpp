// HotCode 009���绰������������

#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ret;

		if (digits.empty()) {
			return ret;
		}

		// ��map��֯���ֺ���ĸ��ӳ���ϵ
		map<char, string> val_map = {
			{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
			{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
		};

		// ��������
		queue<string> val_queue;
		val_queue.push("");

		// ���������ַ�
		for (auto cur : digits) {
			// �ڹ�ϣ���в��ҵ�ǰ�ַ���Ӧ����ĸ��
			string cur_str = val_map[cur];
			int sz = val_queue.size();

			// ��ǰ�������ĸ��
			for (int index = 0; index < sz; index++) {
				string temp_str = val_queue.front();
				val_queue.pop();
				// ������ĸ������������
				for (auto val_cur : cur_str) {
					val_queue.push(temp_str + val_cur);
				}
			}
		}

		while (!val_queue.empty()) {
			string out_str = val_queue.front();
			val_queue.pop();
			ret.push_back(out_str);
		}

		return ret;
	}
};