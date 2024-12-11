/*************************************************************************
	> File Name: 3.override.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 11 Dec 2024 07:14:49 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct Base {
	virtual void test() {
		cout << "Base class test" << endl;
		return ;
	}
	virtual void foo() {
		cout << "Base class foo" << endl;
		return ;
	}
};

struct A : Base {
	void test() override{
		cout << "A class test" << endl;
		return ;
	}
	void foo() override {
		cout << "A class foo" << endl;
		return ;
	}
};

int main()
{
	Base *p = new A();
	p->test();
	p->foo();

	return 0;
}