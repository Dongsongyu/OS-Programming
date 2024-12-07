/*************************************************************************
	> File Name: 9.inherit_permission.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Dec 2024 04:01:54 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Base {
public:
	int public_x;
protected:
	int protected_x;
private:
	int private_x;
};

class A : public Base {
public:
	void set() {
		this->public_x = 3;
		this->protected_x = 3;
		return ;
	}
};

class B : public A {
public:
	void set() {
		this->public_x = 3;
		this->protected_x = 3;
		return ;
	}	
};

int main()
{
	B a;
	a.public_x = 3;

	return 0;
}
