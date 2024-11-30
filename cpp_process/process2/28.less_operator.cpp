#include <iostream>
#include <map>
using namespace std;

class A {
public:
    A(int x = 0) : x(x) {}
    bool operator<(const A &a) const {
        return x < a.x;
    }
    bool operator>(const A &a) const {
        return a < *this;
    }
    bool operator==(const A &a) const{
        return !(*this < a) && !(a < *this);
    }
    bool operator!=(const A &a) const{
        return !(*this == a);
    }
    bool operator>=(const A &a) const{
        return (a < *this) || (a == *this);
    }
    bool operator<=(const A &a) const{
        return (*this < a) || (a == *this);
    }
    int x;
};

map<A, int> h; // 全局声明

#define P(stmt) { \
    cout << #stmt << ":" << (stmt) << endl; \
}

int main() {
    A a(3),b(4);
    h[a] = 123; // 正确使用全局变量
    cout << h[a] << endl;
    P(a < b);
    P(a > b);
    P(a == b);
    P(a != b);
    P(a >= b);
    P(a <= b);

    return 0;
}
