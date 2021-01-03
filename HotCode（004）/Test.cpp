// HotCode 004：两个正序数组的中位数

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 解法一：暴力求解
// 将两个有序数组合并为一个有序数组
// 根据新数组的size选择偶数还是奇数求解

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 设置返回值
        double ret = 0.0;
        // 设置新数组
        vector<int> vec;

        // 将两个有序数组合并为一个新的有序数组
        for (int cur = 0; cur < nums1.size(); cur++) {
            vec.push_back(nums1[cur]);
        }
        for (int cur = 0; cur < nums2.size(); cur++) {
            vec.push_back(nums2[cur]);
        }
        sort(vec.begin(), vec.end());

        // 寻找中位数
        int middle = vec.size() / 2;

        if (vec.size() % 2 == 0) {
            // 偶数
            ret = (vec[middle - 1] + vec[middle]) / 2.0;
        }
        else {
            // 奇数
            ret = vec[middle];
        }

        return ret;
    }
};