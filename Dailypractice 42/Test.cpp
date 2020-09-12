// 使用两个线程打印0到n之间的数，一个线程打印奇数，一个线程打印偶数。(依次打印）

#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

int main(){
	int n = 100;
	mutex mtx0, mtx1;
	condition_variable cv0, cv1;

	// 打印偶数
	thread th1([&](){
		for (int i = 0; i < n; i+=2){
			cout << i << endl;
			// th1打印偶数之后，通知th2
			cv1.notify_one();
			cv0.wait(unique_lock<mutex>(mtx0));
		}
	});
	// 打印奇数
	thread th2([&](){
		for (int i = 1; i < n; i+=2){
			cv1.wait(unique_lock<mutex>(mtx1));
			cout << i << endl;
			cv0.notify_one(); // 解锁th1
		}
	});

	th1.join();
	th2.join();

	return 0;
}