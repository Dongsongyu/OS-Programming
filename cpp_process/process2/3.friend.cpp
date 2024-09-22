/*************************************************************************
	> File Name: 3.friend.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 22 Sep 2024 11:06:34 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A{
public:
    void output()
    {
        cout << "Class A : " << x << ", " << y << endl;
    }
private : 
    int x, y;
    //友元函数
    friend int main();
    //友元类
    friend class B;
};

/*void test(){
    a.x = 3, a.y =4;
    return ;
}*/

class B{
public:
    void change(A &a){
        a.x = 100, a.y = 200;
        return ;
    }
};

int main()
{
    A a;
    //test(a);//权限无法传给test()
    a.x = 3, a.y = 4;
    a.output();
    
    B b;
    b.change(a);
    a.output();

    return 0;
}
