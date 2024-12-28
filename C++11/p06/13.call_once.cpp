/*************************************************************************
	> File Name: 13.call_once.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 26 Dec 2024 07:25:20 PM CST
 ************************************************************************/

#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

once_flag g_flag;
//编写一个单例模式的类--懒汉模式
class Base {
public:
	Base(const Base& obj) = delete;
	Base& operator=(const Base& obj) = delete;
	static Base* getInstance() {
		call_once(g_flag, [&] () {
			obj = new Base;
			cout << "实例对象被创建..." << endl;
		});
		return obj;
	}

	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
private:
	Base() {};
	static Base* obj;
	string name;
};
Base* Base::obj = nullptr;

void myFunc(string name) {
	Base::getInstance()->setName(name);
	cout << "my name is: " << Base::getInstance()->getName() << endl;
}

int main()
{
	thread t1(myFunc, "你猜");
	thread t2(myFunc, "我猜");
	thread t3(myFunc, "你不猜");
	thread t4(myFunc, "我不猜");

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	return 0;
}