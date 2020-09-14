#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

enum STATE{ // 定义两个枚举常量来表示状态
	VALID, //合法
	INVALID,//非法
};
enum STATE state = INVALID;

int My_atoi(const char* str){
	assert(str); // 判空指针

	long long ret = 0; // 定义比int存储范围还要大的类型，防止判断溢出时出错。
	int flag = 1; // 正负号标记

	if (*str == '\0'){ // 空字符串
		state = INVALID;
		return 0;
	}

	while (isspace(*str)){ // 空白字符
		str++;
	}

	if (*str == '+'){ // 正负号
		str++;
	}
	if (*str == '-'){
		flag = -1;
		str++;
	}

	while (*str){
		if (isdigit(*str)){ // 判断是否为数字字符
			ret = ret * 10 + flag*(*str - '0');
			if (ret > INT_MAX || ret < INT_MIN){ // 判断溢出
				state = INVALID;
				return 0;
			}
		}
		else{ // 异常字符
			state = INVALID;
			return 0;
		}
		str++;
	}

	state = VALID;
	return ret;
}