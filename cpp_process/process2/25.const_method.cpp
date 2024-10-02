/*************************************************************************
	> File Name: 25.const_method.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 02 Oct 2024 05:04:13 PM CST
 ************************************************************************/
#include<iostream>
using namespace std;

class A{
public:
    A(int x, int y) : x(x), y(y), z(0) {}
    void output() const {
        z ++;
        cout << x << ", " << y << ", " << z <<endl;
        return ;
    }
    int x, y;
    mutable int z;//可以在const方法中修改
};

int main()
{
    const A a(3, 4);
    a.output();
    a.output();
    a.output();
    a.output();
    a.output();

    return 0;
}
