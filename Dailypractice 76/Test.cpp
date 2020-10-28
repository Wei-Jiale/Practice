// �����������ĺ���������У���ָOffer 33��
// ����һ���������飬�жϸ������ǲ���ĳ�����������ĺ���������
// �������������������������ֶ�������ͬ


#include<iostream>
#include<vector>
using namespace std;

// ������������ֵ �� < �� < ��

class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		if (postorder.empty()){
			return true;
		}
		int sz = postorder.size();
		// ���е����һ��Ԫ��Ϊ�����
		return dfs(postorder, 0, sz - 1);
	}

	bool dfs(vector<int>& postorder, int left, int right){
		// û��������
		if (left >= right){
			return true;
		}

		int root = postorder[right];
		int pos = left;

		// �ҵ������������
		for (; pos < right; pos++){
			if (postorder[pos] > root){
				break;
			}
		}

		// ��������������С��root�Ľ���򷵻�false
		for (int cur = pos; cur<right; cur++){
			if (postorder[cur] < root){
				return false;
			}
		}

		// ����������Ƿ�Ҳ�Ǻ������
		if (!dfs(postorder, left, pos - 1)){
			return false;
		}
		// ����������Ƿ�Ҳ�Ǻ������
		if (!dfs(postorder, pos, right - 1)){
			return false;
		}

		return true;
	}
};

//���ݺ���������ص㣬�������һ��Ԫ�ؼ�Ϊ���ڵ㣻
//��ô�ٸ������������ص㣬�����н������������ķָ��Ѱ�ҵ�һ�����ڸ��ڵ��Ԫ�أ���Ԫ��ǰΪ����������Ԫ�غ�Ϊ��������
//����������Ҫ�ж����Ƿ񶼴��ڸ��ڵ㣬�����������ֱ�ӷ���false���ָ�������ͬ���������⣬�����������ݹ鴦���ɡ�