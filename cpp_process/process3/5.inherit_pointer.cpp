/*************************************************************************
	> File Name: 5.inherit_pointer.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Dec 2024 11:36:46 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Base {
public:
	Base(int x, int y) : x(x), y(y) {}
	int x, y;
};

class A : public Base {
public:
	A(int x, int y, int z) : Base(x, y), z(z) {}
	int z;
};

void func1(Base *p) {
	cout << "Base : " << p->x << ", " << p->y << endl;
	return ;
}

ostream &operator<<(ostream &out, const Base &obj) {
	out << "Base (" << obj.x << ", "<< obj.y << ")";
	return out;
}

int main()
{
	A a(3, 4, 5);
	func1(&a);
	Base &b = a;
	b.x = 5;
	b.y = 6;
	func1(&a);
	func1(&b);
	cout << a << endl;
	cout << b << endl;
	
	return 0;
}
