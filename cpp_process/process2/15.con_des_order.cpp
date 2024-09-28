/*************************************************************************
	> File Name: 15.con_des_order.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 28 Sep 2024 11:22:10 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

namespace test1{
class A{
public:
    A(string name) : name(name){
        cout << name << " constructor" << endl;
    }
    ~A(){
        cout << name << " destructor" << endl;
    }
    string name;
};

class B{
public:
    B(A &a, string name) : a(a), name(name){
        cout << name << " constructor" << endl;
        if(a.name == "c"){
            data = new int[10];
        }else{
            data = nullptr;
        }
    }
    ~B(){
        if (a.name == "c"){
            cout << name << " destructor int[]" << endl;
            delete[] data;
        }else{
            cout << name << " destructor int" << endl;
            delete data;
        }
    }
private:
    string name;
    A &a;
    int *data;
};


int main()
{
    A c{"c"}, d{"d"};
    B a{c, "a"}, b{d, "b"};

    return 0;
}
}//test1

class A{
public:
    A(string name) : name(name){
        cout << name << " constructor" << endl;
    }
    ~A(){
        cout << name << " destructor" << endl;
    }
    string name;
};

class B{
public:
    B(string name) : name(name), c(name + ".c"), d(name+ ".d") {
        cout << name << " constructor" << endl;    
    }
    ~B() {
        cout << name << " destructor" << endl;
    }
private:
    string name;
    A c, d;
};

int main()
{
    B b{"b"};

    return 0;
}
