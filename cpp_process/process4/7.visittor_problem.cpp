/*************************************************************************
	> File Name: 7.visittor_problem.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Jan 2025 07:39:23 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Base {
public:
	virtual void output() = 0;
	virtual ~Base() {}
};

class A : public Base {
public:
	void output() override {
		cout << "Class A" << endl;
		return ;
	}
};
class B : public Base {
public:
	void output() override {
		cout << "Class B" << endl;
		return ;
	}
};
class C : public Base {
public:
	void output() override {
		cout << "Class C" << endl;
		return ;
	}
};

int main()
{
	srand(time(0));
	Base* p;
	int flag;
	switch (rand() % 3) {
		case 0: p = new A(); break;
		case 1: p = new B(); break;
		case 2: p = new C(); break;
	}
	//type-1
	//调用简洁,后期修改简洁,新增功能需要修改类的代码
	//p->output();

	//type-2
	//不需要修改代码,但是不简洁,且后期修改成本高
	// if (dynamic_cast<A *>(p) != nullptr) {
	// 	cout << "Class A : dynamic_cast" << endl;
	// } else if (dynamic_cast<B *>(p) != nullptr) {
	// 	cout << "Class B : dynamic_cast" << endl;
	// } else if (dynamic_cast<C *>(p) != nullptr) {
	// 	cout << "Class C : dynamic_cast" << endl;
	// }

	return 0;
}