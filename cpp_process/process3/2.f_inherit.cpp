/*************************************************************************
	> File Name: 2.f_inherit.cpp
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

private:
	string name;
};

class Cat : public Animal {
public:
	Cat(string name) : Animal(name) {}
};
class Dog : public Animal {
public:
	Dog(string name) : Animal(name) {}
};
class Bat : public Animal {
public:
	Bat(string name) : Animal(name) {}
};

int main()
{
	Cat a1("Garfield");
	Dog a2("Odie");
	Bat a3("Dracula");
	a1.say();
	a2.say();
	a3.say();

	return 0;
}