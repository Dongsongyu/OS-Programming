/*************************************************************************
	> File Name: 34.rvo.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 01 Dec 2024 06:43:57 PM CST
 ************************************************************************/
#include<iostream>
using namespace std;

class A {
public:
	A() {
		cout << this << " :default constructor" << endl;
	}
	A(const A &a) {
		cout << this << " :copy constructor" << endl;
	}
};

A f() {
	A temp;
	cout << "temp : " << &temp << endl;
	return temp;
}

int main()
{
	A a = f();
	cout << "a : " << &a << endl;
	return 0;
}
