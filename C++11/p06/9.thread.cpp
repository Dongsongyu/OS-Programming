/*************************************************************************
	> File Name: 9.thread.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 22 Dec 2024 04:28:18 PM CST
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
	//多线程执行时是没有顺序的
	//线程执行速度和终端打印速度不成正比
	cout << "主线程: " << this_thread::get_id() << endl;
	//创建空的线程对象
	//因为t1这个线程没有任务,不能工作，所有不用调用join
	thread t1;

	//创建一个可用的子线程
	thread t2(func);
	thread t3(func1, "卡卡西", 18);

	thread t4([=](int id) {
		cout << "arg id: " << id << "thread id: " << this_thread::get_id() << endl;
	}, 1001);

	//t4的线程资源转移给了t5
	thread&& t5 = move(t4);

	t2.join();
	t3.join();

	// //主线程和子线程分离
	// t5.detach();
	// cout << "t5 thread id: " << t5.get_id() << "xxxxxxxxxxx" << endl;
	t5.join();

	return 0;
}