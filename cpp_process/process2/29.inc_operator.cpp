#include <iostream>
#include <map>
using namespace std;

class A {
public:
    A(int x = 0) : x(x) {}
    A &operator++(){
        x += 1;
        return *this;
    }
    A operator++(int) {
        A ret(*this);
        x += 1;
        return ret;
    }
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

// A operator++(A &a){
//     a.x += 1;
//     return a;
// }

ostream &operator<<(ostream &out,const A &a){
    out << "class A : x= " << a.x;
    return out;
}

int main() {
    A a(3),b(4);
    cout << a << endl;
    cout << "++a: " << ++a << endl;
    cout << "a++: " << a++ << endl;
    cout << a << endl;

    return 0;
}
