/*************************************************************************
	> File Name: 5_3.POD.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Dec 2024 04:57:33 PM CST
 ************************************************************************/

// pod.cpp
#include <iostream>
#include <type_traits>
using namespace std;

struct A { };
struct B : A { int j; };
struct C
{
public:
    int a;
private:
    int c;
};
struct D1 {  static int i; };
struct D2 {  int i; };
struct E1 { static int i; };
struct E2 { int i; };
struct D : public D1, public E1 { int a; };
struct E : public D1, public E2 { int a; };
struct F : public D2, public E2 { static int a; };
struct G : public A
{
    int foo;
    A a;
};
struct H : public A
{
    A a;
    int foo;
};

int main() 
{
    cout << std::boolalpha;
    cout << "is_standard_layout:" << std::endl;
    cout << "A: " << is_standard_layout<A>::value << endl;
    cout << "B: " << is_standard_layout<B>::value << endl;
    cout << "C: " << is_standard_layout<C>::value << endl;
    cout << "D: " << is_standard_layout<D>::value << endl;
    cout << "D1: " << is_standard_layout<D1>::value << endl;
    cout << "E: " << is_standard_layout<E>::value << endl;
    cout << "F: " << is_standard_layout<F>::value << endl;
    cout << "G: " << is_standard_layout<G>::value << endl;
    cout << "H: " << is_standard_layout<H>::value << endl;
    return 0;
}



