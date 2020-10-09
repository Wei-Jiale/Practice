// ��ֵ�������η�����ָOffer 16��
// ʵ�ֺ��� doble Power(double base, int exponent)
// ��base��exponent�η�
// ����ʹ�ÿ⺯��������Ҫ���Ǵ�������

#include<iostream>
using namespace std;

// ����ָ��Ϊ0������ʱ��Ľ������

class Solution {
public:
	double myPow(double x, int n){
		// ������������
		if (x == 1.0 || n == 0)
			return 1.0;
		if (x == 0.0 && n < 0)
			return x;

		double ret = 1.0;
		long exponent = n;

		// ָ��Ϊ����
		if (n < 0){
			x = 1 / x;
			exponent = -exponent;
		}

		while (exponent){
			// ���ٳ˷�
			// ����n=9��дΪ�����ƾ���1001
			if (exponent & 1 == 1){
				ret = ret * x;
			}
			// ����ƽ������ƽ���Ļ��������Ĵη������Ĵη��Ļ�������˴η�����
			x = x*x;
			exponent = exponent >> 1;
		}

		return ret;
	}
};