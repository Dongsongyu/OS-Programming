/*************************************************************************
	> File Name: 21.test1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 28 Sep 2024 06:16:16 PM CST
 ************************************************************************/
//不能被自动创建的对象
#include<iostream>
using namespace std;

class A{
public:
    A(){
        cout << "constructor" << endl;
    }
    void destroy() {
        delete this;
        return ;
    }
private:
    ~A(){
        cout << "destructor" << endl;
    }
    friend void function_test();
};

void function_test(){
    A a;
    return ;
}

int main()
{
    A *pa = new A();
    pa -> destroy();
    function_test();
    
    return 0;
}
