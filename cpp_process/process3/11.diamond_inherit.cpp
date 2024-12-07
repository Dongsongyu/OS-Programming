/*************************************************************************
	> File Name: 11.diamond_inherit.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Dec 2024 04:34:15 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
	int x;
};

class B : virtual public A {
public:
	void set_x(int x) {
		this->x = x;
		return ;
	}
};

//虚继承最重要的作用就是合并同类项
class C : virtual public A {
public:
	int get_x() {return this->x; }
};

class D : public B, public C {};

int main()
{
	D obj;
	obj.set_x(3);
	cout << obj.get_x() << endl;

	return 0;
}