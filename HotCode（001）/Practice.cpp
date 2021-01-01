// HotCode 001：两数之和

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// 方法一：暴力求解
// 双指针，嵌套for循环，若nums[prev] + nums[cur] == target 则将prev和cur尾插进vec。
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;

        // 双指针暴力求解
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

// 方法二：哈希表
// 建立哈希表，将nums中的元素插入哈希表，对于每一个元素x，只需要查找target-x是否存在即可。
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        vector<int> vec;

        for (int cur = 0; cur < nums.size(); cur++) {
            // 在哈希表中查找target-x是否存在
            auto it = hashtable.find(target - nums[cur]);
            if (it != hashtable.end()) {
                // 找到了
                vec.push_back(it->second);
                vec.push_back(cur);
                return vec;
            }
            // 将遍历过的元素以K = V的形式存入哈希表
            hashtable[nums[cur]] = cur;
        }

        return vec;
    }
};