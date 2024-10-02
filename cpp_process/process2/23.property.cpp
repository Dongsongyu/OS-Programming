/*************************************************************************
	> File Name: 23.property.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 02 Oct 2024 04:45:29 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class People{
public:
    People() { cnt += 1;}
    string name;
    static int cnt;//类属性的声明
    ~People() {cnt -= 1;}
};
int People::cnt = 0;//类属性的定义

void f()
{
    People a, b;
    cout << "cnt : " << People::cnt << endl;
    return ;
}

int main()
{
    People a, b;
    cout << "cnt : " << People::cnt <<endl;
    People c;
    cout << "cnt : " << People::cnt << endl;
    f();
    cout << "cnt : " << People::cnt << endl;

    return 0;
}
