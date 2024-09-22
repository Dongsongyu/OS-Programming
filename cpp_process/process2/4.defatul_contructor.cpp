/*************************************************************************
	> File Name: 4.defatul_contructor.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 22 Sep 2024 01:50:12 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A{
public :
    A() {
        cout << "default constructor" << endl;
        x = 10, y = 100;
    }
    void output(){
        cout << "(" << x << "," << y << ")" << endl;
        return ;
    }
private :
    int x, y;
};

int main()
{
    A a;
    a.output();
    //A b();编译器可能将他当成函数声明;
    A b{};//解决了语法歧义
    b.output();
    //b();
    return 0;
}

/*A b()
{
    cout << "error" << endl;
    return A();
}*/
