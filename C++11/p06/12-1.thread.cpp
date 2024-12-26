/*************************************************************************
	> File Name: 12-1.thread.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 24 Dec 2024 06:18:23 PM CST
 ************************************************************************/

#include<iostream>
#include<functional>
#include<thread>
using namespace std;

class Base {
public:
	void showMsg(string name, int age) {
		cout << "我的名字是" << name << ", 我今年 " << age << " 岁了..." << endl;
	}

	static void message() {
		cout << "1111111111!" << endl;
	}
};

void func() {
	cout << "222222!!!!" << endl;
}

int main()
{
	thread t1(func);

	//传递静态成员函数
	thread tt(&Base::message);

	//传递非静态成员函数
	Base b;
	thread t2(&Base::showMsg, b, "我", 18);
	thread t3(&Base::showMsg, &b, "我", 18);
	thread t4(bind(&Base::showMsg, &b, "我", 18));
	thread t5(bind(&Base::showMsg, b, "我", 18));

	t1.join();
	tt.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	return 0;
}