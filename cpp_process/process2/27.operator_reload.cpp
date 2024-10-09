/*************************************************************************
	> File Name: 27.operator_reload.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 03 Oct 2024 09:31:00 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A{
public:
    A(int x, int y) : x(x), y(y) {}
    void output() {
        cout << "(" << x << "," << y << ")" << endl;
    }
    A &operator*=(int c) {
        x *= c, y *= c;
        return *this;
    }
    int x, y;
};

ostream &operator<<(ostream& out, const A &a){
    out << "operator << : ( " << a.x << ", " << a.y << ")";
    return out;
}

A operator+(A a, A b){
    return A(a.x + b.x, a.y + b.y);
}

int main()
{
    A a(3, 4), b(7, 10);
    A c = a + b;
    c.output();
    cout << c << " end! " << endl;
    c *= 3;
    cout << c << endl;
    (c *= 3) *= 2;
    cout << c << endl;

    return 0;
}
