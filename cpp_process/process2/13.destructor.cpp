/*************************************************************************
	> File Name: 13.destructor.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 28 Sep 2024 10:05:31 AM CST
 ************************************************************************/
#include<iostream>
using namespace std;

class A{
public:
    A() : data(new int[10]){
        cout << this << " default constructor" << endl;
    }
    ~A(){
        cout << this << " destructor" << endl;
        delete[] data;
    }

private:
    int *data;
};

int main()
{
    A a, *pa = new A();
    cout << "a : " << &a << endl;
    cout << "pa : " << pa << endl;
    delete pa;

    return 0;
}
