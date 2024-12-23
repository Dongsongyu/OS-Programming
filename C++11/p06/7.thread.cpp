/*************************************************************************
	> File Name: 7.thread.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 22 Dec 2024 04:15:14 PM CST
 ************************************************************************/

#include<iostream>
#include<thread>
using namespace std;

void func()
{
	cout << "子线程 : " << this_thread::get_id() << endl;
}

int main()
{
	cout << "主线程: " << this_thread::get_id() << endl;
	thread(func);

	return 0;
}
