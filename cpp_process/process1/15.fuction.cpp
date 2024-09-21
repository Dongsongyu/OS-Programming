/*************************************************************************
	> File Name: 15.fuction.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 21 Sep 2024 09:17:07 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<functional>

void test()
{
    cout << "hello test" << endl;
    return ;
}

int add(int a, int b){
    cout << "normal function : ";
    return a + b;
}

class ADD{
public :
    int operator()(int a, int b) const{
        cout << "function object : ";
        return a + b;
    }
}add2;

int main()
{
    function<void()> p1 = test;
    p1();
    function<int(int, int)> p2 = add;
    cout << p2(3, 4) <<endl;
    cout << add2(3, 4) << endl;
    p2 = add2;
    cout << p2(3, 4) << endl;
    auto add3 = [](int a, int b) -> int{
        cout << "lambda : ";
        return a + b;
    };
    p2 = add3;
    cout << p2(3, 4) << endl;
    
    return 0;
}
