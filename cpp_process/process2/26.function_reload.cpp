/*************************************************************************
	> File Name: 26.function_reload.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 03 Oct 2024 08:50:29 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int add(int a, int b)
{
    cout << "add(int, int) : " << a + b << endl;
    return a + b;
}

int add(int a, int b, int c)
{
    cout << "add(int, int, int) : " << a + b + c << endl;
    return a + b + c;
}

double add(double a, double b)
{
    cout << "add(double, double) : " << a + b << endl;
    return a + b;
}

int main()
{
    add(3, 4);
    add(1, 2, 3);
    add(3.4, 5.6);

    return 0;
}
