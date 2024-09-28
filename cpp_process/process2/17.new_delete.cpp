/*************************************************************************
	> File Name: 17.new_delete.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 28 Sep 2024 02:24:39 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A{
public:
    A(string msg){
        cout << msg << " constructor" << endl;
    }
    ~A(){
        cout << "destructor" << endl;
    }
};

int main()
{
    //只开辟空间，没完成构造
    A *malloc_a = (A *)malloc(sizeof(A));
    free(malloc_a);//回收空间
    //调用对象的构造函数
    A *new_a = new A("new");
    delete new_a;//先调用对象的析构函数，再回收空间
    
    return 0;
}
