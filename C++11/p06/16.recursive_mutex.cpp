/*************************************************************************
	> File Name: 16.recursive_mutex.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 26 Dec 2024 09:44:47 PM CST
 ************************************************************************/

#include<iostream>
#include<mutex>
#include<thread>
#include<chrono>
using namespace std;

//互斥锁
class Base {
public:
	void increment(int count) {
		for(int i = 0; i < count; ++i) {
			mx.lock();
			++number;
			cout << "++current number: " << number << endl;
			mx.unlock();
			this_thread::sleep_for(chrono::milliseconds(500));
		}
	}
	void decrement(int count) {
		for(int i = 0; i < count; ++i) {
			{
				lock_guard<recursive_mutex> guard(mx);
				increment(2);
				--number;
				cout << "--current number: " << number << endl;
			}
			this_thread::yield();
		}
	}
private:
	int number = 999;
	recursive_mutex mx;
};

int main()
{
	Base b;
	thread t1(&Base::increment, &b, 10);
	thread t2(&Base::decrement, &b, 10);
	t1.join();
	t2.join();

	return 0;
}

