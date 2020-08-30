// 039：冒泡排序
// 根据序列中相邻两个元素键值的比较结果来对换这两个元素在序列中的位置
// 第一轮完毕将最大元素移动到元素末尾
// 如果某一趟执行完毕，没有做任何一次交换操作，说明剩下的序列已经有序

#include<iostream>
#include<vector>
using namespace std;

void Bubblesort(vector<int>& array){
	int sz = array.size();
	// 外层循环控制每一趟冒泡的次数
	for (int out = 0; out < sz - 1; out++){
		bool flag = true;
		// 内层循环控制单趟排序
		for (int in = 0; in < sz - out - 1; in++){
			if (array[in]>array[in + 1]){
				swap(array[in], array[in + 1]);
				flag = false;
			}
		}
		// 一趟排序中没有进行交换说明已经有序
		if (flag == true){
			break;
		}
	}
}