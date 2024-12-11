/*************************************************************************
	> File Name: 1.virtual.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 11 Dec 2024 06:38:09 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Animal {
public:
	virtual void run() {
		cout << "I don't know how to run" << endl;
	}
};

class Cat : public Animal {
public:
	void run() override{
		cout << "I can run with four legs" << endl;
		return ;
	}
};

int main()
{
	Cat c;
	Animal *p = &c;
	c.run();
	p->run();

	return 0;
}
