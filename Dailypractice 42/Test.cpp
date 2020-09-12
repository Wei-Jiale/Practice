// ʹ�������̴߳�ӡ0��n֮�������һ���̴߳�ӡ������һ���̴߳�ӡż����(���δ�ӡ��

#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

int main(){
	int n = 100;
	mutex mtx0, mtx1;
	condition_variable cv0, cv1;

	// ��ӡż��
	thread th1([&](){
		for (int i = 0; i < n; i+=2){
			cout << i << endl;
			// th1��ӡż��֮��֪ͨth2
			cv1.notify_one();
			cv0.wait(unique_lock<mutex>(mtx0));
		}
	});
	// ��ӡ����
	thread th2([&](){
		for (int i = 1; i < n; i+=2){
			cv1.wait(unique_lock<mutex>(mtx1));
			cout << i << endl;
			cv0.notify_one(); // ����th1
		}
	});

	th1.join();
	th2.join();

	return 0;
}