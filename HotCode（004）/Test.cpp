// HotCode 004�����������������λ��

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// �ⷨһ���������
// ��������������ϲ�Ϊһ����������
// �����������sizeѡ��ż�������������

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // ���÷���ֵ
        double ret = 0.0;
        // ����������
        vector<int> vec;

        // ��������������ϲ�Ϊһ���µ���������
        for (int cur = 0; cur < nums1.size(); cur++) {
            vec.push_back(nums1[cur]);
        }
        for (int cur = 0; cur < nums2.size(); cur++) {
            vec.push_back(nums2[cur]);
        }
        sort(vec.begin(), vec.end());

        // Ѱ����λ��
        int middle = vec.size() / 2;

        if (vec.size() % 2 == 0) {
            // ż��
            ret = (vec[middle - 1] + vec[middle]) / 2.0;
        }
        else {
            // ����
            ret = vec[middle];
        }

        return ret;
    }
};