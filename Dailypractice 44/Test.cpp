// 赋值运算符函数（剑指Offer 1）
// 题目：声明类型CMyString，请为该类型添加赋值运算符函数。
#include<iostream>
using namespace std;

class CMyString{
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);
private:
	char* m_pData;
};

// 1. 把返回值类型声明为该类型的引用，并且在函数结束前返回实例自身的引用。（连续赋值）
// 2. 把传入的参数类型声明为常量引用。（传实例会导致从形参到实参调用复制构造函数，传入引用会减少这种无谓的开销）
// 3. 是否释放实例自身已有的内存。（忘记释放可能会出现内存泄漏问题）
// 4. 判断当前的实例（*this）和当前传入的参数是不是同一个实例。（同一个则不进行赋值）
//    若不进行判断，则当*this与传入的参数是同一个实例的时候，释放了自身的内存，传入的参数内存也同时被释放，再也找不到需要赋值的内容。

// 解法一：经典解法
CMyString& CMyString::operator=(const CMyString& str){
	if (this == &str){
		return *this;
	}
	delete[]m_pData;
	m_pData = nullptr;

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);

	return *this;
}

// 解法二：较优解法（创建临时对象）
CMyString& CMyString::operator=(const CMyString& str){
	if (this != &str){
		// 创建一个临时实例strTemp，生命周期结束实例自动销毁。
		CMyString strTemp(str);

		char* pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}

	return *this;
}
