/*************************************************************************
	> File Name: 11.thread_extern.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 23 Dec 2024 07:39:30 PM CST
 ************************************************************************/

#include<iostream>
#include<thread>
using namespace std;

void func() {
	cout << "我是子线程,叫做..." << this_thread::get_id() << endl;
}

void func1(string name, int age) {
	cout << "我是子线程,叫做 " << name << ",age: " << age << this_thread::get_id() << endl;
}

int main()
{
	thread t1;
	cout << "t1 joinable: " << t1.joinable() << endl;

	thread t2(func);
	cout << "t2 joinable: " << t2.joinable() << endl;
	t2.join();
	cout << "after t2 joinable: " << t2.joinable() << endl;

	thread t3(func);
	t3.detach();
	cout << "t3 joinable: " << t3.joinable() << endl;

	return 0;
}