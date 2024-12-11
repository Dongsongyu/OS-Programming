/*************************************************************************
	> File Name: 4.final.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 11 Dec 2024 07:32:59 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct Base {
	virtual void test() {
		cout << "Base" << endl;
		return ;
	}
};

struct A : Base {
	//final 可以继承，但是不能修改
	void test() final {
		cout << "A" << endl;
	}
};

struct B : A {
	// void test() override {
	// 	cout << "B" << endl;
	// }
};
int main()
{
	Base *p = new B();
	p->test();

	return 0;
}