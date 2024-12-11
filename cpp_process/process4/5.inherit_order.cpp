/*************************************************************************
	> File Name: 7.inherit_order.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Dec 2024 02:31:38 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Base {
public:
	Base() {
		cout << "Base constructor" << endl;
	}
	//虚函数的作用是让对象准确的执行他的操作
	virtual ~Base() {
		cout << "Base destructor" << endl;
	}
};

class A : public Base {
public:
	A() {
		data = new int[10];
		cout << "A constructor, data : " << data << endl;
	}
	~A() {
		if (data != nullptr) delete[] data;
		cout << "A destructor, data done" << endl;
	}
	int *data;
};

class B : public Base {
public:
	B() {
		cout << "B constructor" << endl;
	}
	~B() {
		cout << "B destructor" << endl;
	}
};
class C : public Base {
public:
	C() {
		cout << "C constructor" << endl;
	}
	~C() {
		cout << "C destructor" << endl;
	}
};

void func1() {
	cout << "func1 : " << endl;
	A a;
	return ;
}

void func2() {
	cout << "func2 : " << endl;
	Base *p = new A();
	delete (A *)(p);
	return ;
}

void func3() {
	cout << "func3 : " << endl;
	Base *p;
	switch (rand() % 3) {
		case 0 : p = new A(); break;
		case 1 : p = new B(); break;
		case 2 : p = new C(); break;
	}
	//question: 无法得知父类指向哪一个子类对象，该怎么调用子类对象的析构函数
	delete p; 

	return ;
}

int main()
{
	srand(time(0));
	//func1();
	//func2();
	func3();

	return 0;
}