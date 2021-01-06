// HotCode 008：三数之和

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// 方法一：暴力法
// 去重利用到了 set
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

// 方法二：双指针
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        // 设置返回数组
        vector<vector<int>> ret;

        if (nums.size() < 3) {
            return ret;
        }

        // 对目标数组排序
        sort(nums.begin(), nums.end());

        // 固定第一个数
        // 将问题转换为两数求和
        for (int cur = 0; cur < nums.size(); cur++) {
            // 若第一个数就为正则返回
            if (nums[cur] > 0) {
                return ret;
            }
            // 若固定数重复则跳过（第一次去重）
            if (cur > 0 && nums[cur] == nums[cur - 1]) {
                continue;
            }

            // 双指针在nums[cur]后面的区间中寻找和为-nums[i]的两个数
            int start = cur + 1;
            int end = nums.size() - 1;

            while (start < end) {
                if (nums[cur] + nums[start] + nums[end] == 0) {
                    // 组织添加
                    ret.push_back(vector<int>{nums[cur], nums[start], nums[end]});
                    start++;
                    end--;
                    // 第二个数和第三个数也不重复选取（第二次去重）
                    while (start < end && nums[start] == nums[start - 1]) {
                        start++;
                    }
                    while (start < end && nums[end] == nums[end + 1]) {
                        end--;
                    }
                }
                else if (nums[cur] + nums[start] + nums[end] > 0) {
                    // end向左移动
                    end--;
                }
                else {
                    // start向右移动
                    start++;
                }
            }
        }
        return ret;
    }
};