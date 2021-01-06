// HotCode 008������֮��

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// ����һ��������
// ȥ�����õ��� set
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vec;
        vector<int> tmp;
        set<vector<int>> ret;

        sort(nums.begin(), nums.end());

        for (int prev = 0; prev < nums.size() - 2; prev++) {
            for (int cur = prev + 1; cur < nums.size() - 1; cur++) {
                for (int next = cur + 1; next < nums.size(); next++) {
                    if (nums[prev] + nums[cur] + nums[next] == 0) {
                        tmp.clear();
                        tmp.push_back(nums[prev]);
                        tmp.push_back(nums[cur]);
                        tmp.push_back(nums[next]);

                        ret.insert(tmp);
                    }
                }
            }
        }
        for (auto it : ret) {
            vec.push_back(it);
        }

        return vec;
    }
};

// ��������˫ָ��
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        // ���÷�������
        vector<vector<int>> ret;

        if (nums.size() < 3) {
            return ret;
        }

        // ��Ŀ����������
        sort(nums.begin(), nums.end());

        // �̶���һ����
        // ������ת��Ϊ�������
        for (int cur = 0; cur < nums.size(); cur++) {
            // ����һ������Ϊ���򷵻�
            if (nums[cur] > 0) {
                return ret;
            }
            // ���̶����ظ�����������һ��ȥ�أ�
            if (cur > 0 && nums[cur] == nums[cur - 1]) {
                continue;
            }

            // ˫ָ����nums[cur]�����������Ѱ�Һ�Ϊ-nums[i]��������
            int start = cur + 1;
            int end = nums.size() - 1;

            while (start < end) {
                if (nums[cur] + nums[start] + nums[end] == 0) {
                    // ��֯���
                    ret.push_back(vector<int>{nums[cur], nums[start], nums[end]});
                    start++;
                    end--;
                    // �ڶ������͵�������Ҳ���ظ�ѡȡ���ڶ���ȥ�أ�
                    while (start < end && nums[start] == nums[start - 1]) {
                        start++;
                    }
                    while (start < end && nums[end] == nums[end + 1]) {
                        end--;
                    }
                }
                else if (nums[cur] + nums[start] + nums[end] > 0) {
                    // end�����ƶ�
                    end--;
                }
                else {
                    // start�����ƶ�
                    start++;
                }
            }
        }
        return ret;
    }
};