/*************************************************************************
	> File Name: 2.runtime_polymorphic.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 11 Dec 2024 06:55:38 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int f(int x) {
	return 2 * x;
}

double f(double x) {
	return 3 * x;
}

class Base {
public:
	virtual void test() {
		cout << "Base class test" << endl;
		return ;
	}
};

class A : public Base {
public:
	void test() override {
		cout << "A class test" << endl;
		return ;
	}
};

class B : public Base {
public:
	void test() override {
		cout << "B class test" << endl;
		return ;
	}
};

Base *rand_object() {
	switch (rand() % 3) {
		case 0: return new Base();
		case 1: return new A();
		case 2: return new B();
	}
	return nullptr;
}

int main()
{
	srand(time(0));
	cout << f(123) << endl;
	cout << f(12.3) << endl;
	rand_object()->test();

	return 0;
}