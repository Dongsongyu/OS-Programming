/*************************************************************************
	> File Name: 3.fun_inherit.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 01 Dec 2024 07:33:16 PM CST
 ************************************************************************/
#include<iostream>
using namespace std;

class Animal {
public:
	Animal(string name) : name(name) {}
	void say() {
		cout << "My name is " << name << endl;
	}

//protected可以让子类访问到，但是外界无法访问
//private子类无法访问
protected:
	string name;
};

class Cat : public Animal {
public:
	Cat(string name) : Animal(name) {}
	void run() {
		cout << "I can run with four legs" << endl;
		return ;
	}
};
class Dog : public Animal {
public:
	Dog(string name) : Animal(name) {}
	void run() {
		cout << "I can run with four legs" << endl;
		return ;
	}
};
class Bat : public Animal {
public:
	Bat(string name) : Animal(name) {}
	void fly() {
		cout << "I can fly, I am " << this->name << endl;
		return ;
	}
};

int main()
{
	Cat a1("Garfield");
	Dog a2("Odie");
	Bat a3("Dracula");
	a1.say();
	a1.run();
	a2.say();
	a2.run();
	a3.say();
	a3.fly();

	return 0;
}