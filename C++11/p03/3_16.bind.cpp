/*************************************************************************
	> File Name: 3_16.bind.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Dec 2024 03:03:27 PM CST
 ************************************************************************/

#include<iostream>
#include<functional>
using namespace std;

class Test {
public:
    void output(int x, int y) {
        cout << "x : " << x << ", y : " << y << endl;
    }
    int m_number = 100;
};

void testFunc(int x, int y, const function<void(int, int)>& f) {
    if(x %2 == 0) {
        f(x, y);
    }
}

int main(void) 
{
    /*for(int i = 0; i < 10; i++) {
        auto f = bind(output_add, i + 100, i + 200);
        testFunc(i, i, f);
        auto f1 = bind(output_add, placeholders::_1, placeholders::_2);
        testFunc(i, i, f1);
    }*/

    //成员函数绑定
    Test t;
    auto f2 = bind(&Test::output, &t, 520, placeholders::_1);
    function<void(int, int)> f22 = bind(&Test::output, &t, 520, placeholders::_1);
    f2(1314);
    
    //成员变量
    auto f3 = bind(&Test::m_number, &t);
    function<int(void)> f33 = bind(&Test::m_number, &t);
    cout << f3() << endl;
    f3() = 666;
    cout <<f3() << endl;

    return 0;
}
