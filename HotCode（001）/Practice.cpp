// HotCode 001������֮��

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// ����һ���������
// ˫ָ�룬Ƕ��forѭ������nums[prev] + nums[cur] == target ��prev��curβ���vec��
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;

        // ˫ָ�뱩�����
        for (int prev = 0; prev < nums.size(); prev++) {
            for (int cur = prev + 1; cur < nums.size(); cur++) {
                if (nums[prev] + nums[cur] == target) {
                    vec.push_back(prev);
                    vec.push_back(cur);
                    return vec;
                }
            }
        }

        return vec;
    }
};

// ����������ϣ��
// ������ϣ����nums�е�Ԫ�ز����ϣ������ÿһ��Ԫ��x��ֻ��Ҫ����target-x�Ƿ���ڼ��ɡ�
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        vector<int> vec;

        for (int cur = 0; cur < nums.size(); cur++) {
            // �ڹ�ϣ���в���target-x�Ƿ����
            auto it = hashtable.find(target - nums[cur]);
            if (it != hashtable.end()) {
                // �ҵ���
                vec.push_back(it->second);
                vec.push_back(cur);
                return vec;
            }
            // ����������Ԫ����K = V����ʽ�����ϣ��
            hashtable[nums[cur]] = cur;
        }

        return vec;
    }
};