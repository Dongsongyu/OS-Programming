/*************************************************************************
	> File Name: 5.param_constructor.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 22 Sep 2024 01:59:41 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public :
    //委托构造
    A() : A(100, 1000){}
    //默认构造
    /*A(){
        x = 100, y = 1000;
    }*/
    //有参构造
    A(int x, int y){
        this->x = x, this->y = y;
    }
    void output(){
        cout << "(" << this->x << "," << this->y << ")" << endl;
    }
private:
    int x, y;
};

int main()
{
    A a{10, 100}, b{20, 200};
    a.output();
    b.output();
    A c;
    c.output();

    return 0;
}
