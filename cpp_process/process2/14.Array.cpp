/*************************************************************************
	> File Name: 14.Array.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 28 Sep 2024 08:45:44 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Array {
public:
    Array() : n(10), data(new int[n]){
        cout << this << " default constructor" << endl;
        for(int i = 0; i < n; i++) data[i] = 0;
    }
    Array(const Array &a) : n(a.n), data(new int[n]){
        cout << this << " copy constructor" << endl;
        for(int i = 0; i < a.n; i++){
            data[i] = a.data[i];
        }
    }
    //移动构造
    Array(Array &&a) : n(a.n), data(a.data){
        cout << this << " move constructor" << endl;
        a.n = 0;
        a.data = nullptr;
    }
    void set(int ind, int val){
        data[ind] = val;
    }
    int size() {return n;}
    void output(){
        for(int i = 0; i < n; i++){
            cout << data[i] << " ";
        }
        cout << endl;
        return ;
    }
    Array duplicate(){
        return Array(*this);
    }
    ~Array(){
        cout << this << " destrucotr" << endl;
        if(n == 0) return ;
        delete[] data;
        return ;
    }
private:
    int n, *data;
};

int main()
{
    Array a, b = a.duplicate();
    Array c;
    cout << "a : " << &a << endl;
    cout << "b : " << &b << endl;
    Array d = std::move(c);
    cout << "c : " << &c << endl;
    cout << "d : " << &d << endl;
    return 0;
}
