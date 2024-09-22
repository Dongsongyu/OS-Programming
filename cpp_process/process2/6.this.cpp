/*************************************************************************
	> File Name: 6.this.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 22 Sep 2024 02:10:52 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A{
public:
    A() : A(100, 1999){
        cout << this << " : default constructor" << endl;
    }
    A(int x, int y){
        cout << this << " : param constructor" << endl;
        this->x = x, this->y = y;
    }
    void output()
    {
        cout << this << " : call function" << endl;
        cout << this->x << ", " << this->y << endl;
        return ;
    }
private:
    int x, y;
};

int main()
{
    A a{10, 100}, b;
    cout << "a : " << &a << endl;
    //先执行有参构造，再跳回到默认构造
    cout << "b : " << &b << endl;
    a.output();
    b.output();
    a.output();

    return 0;
}
