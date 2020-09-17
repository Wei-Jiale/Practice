#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

namespace WJL{
	template<class T>
	class shared_ptr{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _pmtx(new mutex)
		{}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _pmtx(sp._pmtx)
		{
			add_ref_count();
		}

		// sp1 = sp4
		shared_ptr<T>& operator=(const shared_ptr<T>& sp){
			if (this != &sp){
				// 减减引用计数，如果我是最后一个管理资源的对象，则释放资源
				release();
				// 我开始跟你一起管理资源
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_pmtx = sp._pmtx;

				add_ref_count();
			}
			return *this;
		}

		void add_ref_count(){
			_pmtx->lock();
			++(*_pcount);
			_pmtx->unlock();
		}

		void release(){
			bool flag = false;
			_pmtx->lock();
			if (--(*_pcount) == 0){
				if (_ptr){
					cout << "delete:" << _ptr << endl;
					delete _ptr;
					_ptr = nullptr;
				}

				delete _pcount;
				_pcount = nullptr;
				flag = true;
			}
			_pmtx->unlock();

			if (flag == true){
				delete _pmtx;
				_pmtx = nullptr;
			}
		}

		~shared_ptr(){
			release();
		}

		int use_count(){
			return *_pcount;
		}

		T* get_ptr() const{
			return _ptr;
		}

		T& operator*(){
			return *_ptr;
		}

		T* operator->() {
			return _ptr;
		}
	private:
		T* _ptr;
		// 记录有多少个对象一起共享管理资源，最后一个析构释放资源
		int* _pcount;
		mutex* _pmtx;
	};
}