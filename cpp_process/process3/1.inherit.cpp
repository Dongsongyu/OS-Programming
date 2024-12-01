/*************************************************************************
	> File Name: 1.inherit.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 01 Dec 2024 07:33:16 PM CST
 ************************************************************************/
#include<iostream>
using namespace std;

class Animal {
public:
	Animal() {}
	void set(string name ) { this->name = name; }
	void say() {
		cout << "My name is " << name << endl;
	}

private:
	string name;
};

class Cat : public Animal {};
class Dog : public Animal {};
class Bat : public Animal {};

int main()
{
	Cat a1;
	Dog a2;
	Bat a3;
	a1.set("Garfield");
	a2.set("Odie");
	a3.set("Dracula");
	a1.say();
	a2.say();
	a3.say();

	return 0;
}