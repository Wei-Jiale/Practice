// 二叉搜索树的后序遍历序列（剑指Offer 33）
// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果
// 假设输入的数组的任意两个数字都互不相同


#include<iostream>
#include<vector>
using namespace std;

// 二叉搜索树的值 左 < 根 < 右

class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		if (postorder.empty()){
			return true;
		}
		int sz = postorder.size();
		// 序列的最后一个元素为根结点
		return dfs(postorder, 0, sz - 1);
	}

	bool dfs(vector<int>& postorder, int left, int right){
		// 没有左子树
		if (left >= right){
			return true;
		}

		int root = postorder[right];
		int pos = left;

		// 找到右子树的起点
		for (; pos < right; pos++){
			if (postorder[pos] > root){
				break;
			}
		}

		// 若右子树部分有小于root的结点则返回false
		for (int cur = pos; cur<right; cur++){
			if (postorder[cur] < root){
				return false;
			}
		}

		// 检查左子树是否也是后序遍历
		if (!dfs(postorder, left, pos - 1)){
			return false;
		}
		// 检查右子树是否也是后序遍历
		if (!dfs(postorder, pos, right - 1)){
			return false;
		}

		return true;
	}
};

//根据后序遍历的特点，序列最后一个元素即为根节点；
//那么再根据搜索树的特点，对序列进行左右子树的分割，即寻找第一个大于根节点的元素，该元素前为左子树，该元素后为右子树；
//右子树还需要判断下是否都大于根节点，如果不满足则直接返回false。分割完后就是同样的子问题，将左右子树递归处理即可。