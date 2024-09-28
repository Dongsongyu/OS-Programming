/*************************************************************************
	> File Name: 19.emplace_new.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 28 Sep 2024 02:55:50 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A{
public:
    A() = delete;
    A(int x) : x(x){
        cout << "constructor" << endl;
    }
    void output(){
        cout << "x : " << x << endl;
    }
    ~A(){
        cout << "desturctor" << endl;
    }
    int x;
};

int main()
{
    A *arr = (A *)malloc(sizeof(A) * 5);
    for(int i = 0; i < 5; i++){
        new(arr + i) A(i);
    }
    for(int i = 0; i < 5; i++){
        arr[i].output();
    }
    for(int i = 0; i < 5; i++){
        arr[i].~A();
    }
    free(arr);
    
    return 0;
}
