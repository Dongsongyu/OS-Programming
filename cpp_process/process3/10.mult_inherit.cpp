/*************************************************************************
	> File Name: 10.mult_inherit.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Dec 2024 04:25:11 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Base1 {};
class Base2 {};
class A : public Base1, protected Base2 {};

class Flyable {
public:
	void fly() {
		cout << "flying in the sky" << endl;
		return ;
	}
};

class Swimmable {
public:
	void swim() {
		cout << "swimming in the water" << endl;
		return ;
	}
};

class Duck : public Flyable, public Swimmable {
public:
	void quack() {
		cout << "Quack, GA GA GA" << endl;
		return ;
	}
};

int main()
{
	Duck d;
	d.fly();
	d.swim();
	d.quack();

	return 0;
}