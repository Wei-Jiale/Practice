// 002����������ת��
// C���Է��ʹ���»��߷ָ�������ʣ����硰hello_world��
// JAVA��񣬳��׸��������⣬���е��ʵ�����ĸ��д�����硰helloWorld��
// ��C���Է��ı�����ת��ΪJAVA���ı�����

#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;
	while (cin >> str){
		// �����ַ���
		for (int i = 0; i < str.size(); i++){
			// ���� '_' ֱ������
			if (str[i] == '_'){
				continue;
			}
			// ����һ���ַ��� "_" ������ַ�תΪ��д��ĸ
			if (i > 0 && str[i - 1] == '_'){
				// toupper����ֵΪ int ���ͣ���Ҫ��ʽ������ʽ�ؽ���ת��Ϊ char ����
				cout << (char)toupper(str[i]);
			}
			else{
				cout << str[i];
			}
		}
		cout << endl;
	}
	return 0;
}