/*************************************************************************
	> File Name: 8.left_right_value.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 24 Sep 2024 08:40:55 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define TEST(expr){\
    cout << #expr;\
    f(expr);\
}

void g(int &x){
    cout << "g : left value" << endl;
    return ;
}
void g(int &&x){
    cout << "g : right value" << endl;
    return ;
}

void f(int &x){
    cout << " is left value" << endl;
    g(x);
    return ;
}

void f(int &&x){
    cout << " is right value" << endl;
    g(std::move(x));
    g(std::forward<int &&>(x));
    return ;
}

int main()
{
    int a = 12, b = 13;
    TEST(123);
    TEST(12 + 23);
    TEST(a + b);
    TEST(b);
    TEST(a);
    TEST(a++);//right
    TEST(++a);//left
    (++a) = 1001;
    TEST(a);
    cout << a << endl;

    return 0;
}
