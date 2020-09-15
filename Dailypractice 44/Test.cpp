// ��ֵ�������������ָOffer 1��
// ��Ŀ����������CMyString����Ϊ��������Ӹ�ֵ�����������
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

// 1. �ѷ���ֵ��������Ϊ�����͵����ã������ں�������ǰ����ʵ����������á���������ֵ��
// 2. �Ѵ���Ĳ�����������Ϊ�������á�����ʵ���ᵼ�´��βε�ʵ�ε��ø��ƹ��캯�����������û����������ν�Ŀ�����
// 3. �Ƿ��ͷ�ʵ���������е��ڴ档�������ͷſ��ܻ�����ڴ�й©���⣩
// 4. �жϵ�ǰ��ʵ����*this���͵�ǰ����Ĳ����ǲ���ͬһ��ʵ������ͬһ���򲻽��и�ֵ��
//    ���������жϣ���*this�봫��Ĳ�����ͬһ��ʵ����ʱ���ͷ���������ڴ棬����Ĳ����ڴ�Ҳͬʱ���ͷţ���Ҳ�Ҳ�����Ҫ��ֵ�����ݡ�

// �ⷨһ������ⷨ
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

// �ⷨ�������Žⷨ��������ʱ����
CMyString& CMyString::operator=(const CMyString& str){
	if (this != &str){
		// ����һ����ʱʵ��strTemp���������ڽ���ʵ���Զ����١�
		CMyString strTemp(str);

		char* pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}

	return *this;
}
