/*************************************************************************
	> File Name: 5_5.default=delete.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Dec 2024 06:10:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//delete和default的区别是，delete能修改自定义函数和默认函数,而default只能修改默认函数
class Test {
public:
	Test1();
	~Test() = default;
	Test(const Test &t) = default;
	Test(Test&& t) = default;
	Test& operator=(const Test& t) = default;
	Test& operator=(Test&& t) = default;
	Test() {}
};

class Test1 {
public:
	Test1();
	Test1(const Test1& t) = delete;
	Test& operator=(const Test& t) = delete;
};

Test1::Test1() = default;

int main()
{
	//拷贝函数已经被删除
	// Test1 t;
	// Test1 tt(t);
	// Test1 t2;
	// t2 = t;

	return 0;
}