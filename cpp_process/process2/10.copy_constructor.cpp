/*************************************************************************
	> File Name: 10.copy_constructor.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 28 Sep 2024 08:16:31 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
    A() : x(0), y(1) {
        cout << this << " default constructor" << endl;
    }
    A(const A &a) : x(a.x), y(a.y) {
        cout << this << " copy constructor" << endl;
    }
    void operator=(const A &a){
        cout << this << " operator=" << endl;
        return ;
    }
    void output(){
        cout << "(" << x << ", " << y << ")" << endl;
    }
private:
    int x, y;
};

int main()
{
    A a, b = a;
    cout << "a : " << &a << endl;
    cout << "b : " << &b <<endl;
    a.output();
    b.output();
    b = a;
    cout << "b : " << &b << endl;
    b.output();

    return 0;
}
