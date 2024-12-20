/*************************************************************************
	> File Name: 3_11.object.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Dec 2024 09:30:06 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<functional>
using namespace std;

/*
是一个函数指针
是一个具有operator()成员函数的类对象(仿函数)
是一个可被转换为函数指针的类对象
是一个类成员函数指针或者类成员指针
*/

//普通函数
void print(int num, string name) {
	cout << "id : " << num << ", name : " << name << endl;
} 

using funcptr = void(*)(int, string);

//类
class Test {
public:
	//重载
	void operator() (string msg) {
		cout << "仿函数: " << msg << endl;
	}
	//将类对象转换为函数指针
	operator funcptr () {
		return world;
	}

	//非静态方法属于对象
	void hello(int a, string s) {
		cout << "number : " << a << ", name : " << s << endl;
	}

	//静态方法属于类
	static void world(int a, string s) {
		cout << "number : " << a << ", name : " << s << endl;
	}

	int m_id =520;
	string m_name = "luffy";
};

class A {
public:
	//构造函数参数是一个包装器对象
	A(const function<void(int, string)>& f) : callback(f) {
	}

	void notify(int id, string name) {
		callback(id, name);//调用通过构造函数得到的函数指针
	}
private:
	function<void(int, string)> callback;
};

int main(int argc, char* argv[]) {
#if 0
	Test t;
	t("hello");

	Test tt;
	tt (10, "luccy");

	//类的函数指针
	funcptr f = Test::world;
	using fptr = void(Test::*) (int, string);
	fptr f1 = &Test::hello;

	//类的成员指针(变量)
	using ptr1 = int Test::*;
	ptr1 pt = &Test::m_id;

	Test ttt;
	(ttt.*f1)(20, "ace");
	ttt.*pt = 100;
	cout << "m_id : " << ttt.m_id << endl;
#endif
	//包装普通函数
	function<void(int, string)> f1 = print;
	//包装类的静态函数
	function<void(int, string)> f2 = Test::world;
	//包装仿函数
	Test ta;
	function<void(string)> f3 = ta;
	//包装转换为函数指针的对象
	Test tb;
	function<void(int, string)> f4 = tb;
	//调用
	f1(1, "ace");
	f2(2, "sabo");
	f3("hello");
	f4(3, "lucy");

	A aa(print);
	aa.notify(1, "ace");

	A ab(Test::world);
	ab.notify(2, "sabo");

	A ac(tb);
	ac.notify(3, "lucy");

	return 0;
}