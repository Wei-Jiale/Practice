#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

enum STATE{ // ��������ö�ٳ�������ʾ״̬
	VALID, //�Ϸ�
	INVALID,//�Ƿ�
};
enum STATE state = INVALID;

int My_atoi(const char* str){
	assert(str); // �п�ָ��

	long long ret = 0; // �����int�洢��Χ��Ҫ������ͣ���ֹ�ж����ʱ����
	int flag = 1; // �����ű��

	if (*str == '\0'){ // ���ַ���
		state = INVALID;
		return 0;
	}

	while (isspace(*str)){ // �հ��ַ�
		str++;
	}

	if (*str == '+'){ // ������
		str++;
	}
	if (*str == '-'){
		flag = -1;
		str++;
	}

	while (*str){
		if (isdigit(*str)){ // �ж��Ƿ�Ϊ�����ַ�
			ret = ret * 10 + flag*(*str - '0');
			if (ret > INT_MAX || ret < INT_MIN){ // �ж����
				state = INVALID;
				return 0;
			}
		}
		else{ // �쳣�ַ�
			state = INVALID;
			return 0;
		}
		str++;
	}

	state = VALID;
	return ret;
}