/*************************************************************************
	> File Name: 7.initialize_list.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 22 Sep 2024 02:22:24 PM CST
 ************************************************************************/
#include<iostream>
using namespace std;

namespace test1{
class A{
public:
    //委托构造
    A() : A(1, 1) {}
    //第一个x代表类里面的字段x,第二个x代表的是参数x
    A(int x, int y) : x(x), y(y){}
    void output(){
        cout << "(" << x << ", " << y << ")"<< endl;
    }
private:
    int x, y;
};

int main()
{
    A a(3, 4), b(101, 202), c;
    a.output();
    b.output();
    c.output();

    return 0;
}
}//test1

namespace test2{    
class B{
public:
    B(int x) : x(x) {
        cout << this << " : Class B constructor " << endl;
    }
    int x;
};

class A{
public:
    //委托构造
    A() : A(1, 1) {}
    //初始化列表中是按照定义顺序执行的
    A(int z) : y(z), x(z + 1) {
        cout << "x : " << &x << endl;
        cout << "y : " << &y << endl;
    }
    //第一个x代表类里面的字段x,第二个x代表的是参数x
    A(int x, int y) : x(x), y(y){}
    void output(){
        cout << "(" << x.x << ", " << y.x << ")"<< endl;
    }
private:
    B x, y;
};

int main()
{
    A a(5);//x = 6, y = 5
    a.output();
    return 0;
}
}//test2


namespace test3{    
class B{
public:
    //当构造函数中存在有参构造，就会默认删除默认构造
    B(){
        cout << this << "default constructor " << endl;
    }
    B(int x) {
        cout << this << " : Class B constructor " << endl;
    }
    int x;
};

class A{
public:
    //委托构造
    A() : A(1, 1) {}
    //初始化列表完成构造行为，显示调用构造函数,如果不初始化，调用默认构造
    //初始化列表完成构造的过程就是完成赋值，提高效率
    A(int x, int y) {
        this->x.x = x;
        this->y.x = y;
    }
    void output(){
        cout << "(" << x.x << ", " << y.x << ")"<< endl;
    }
private:
    B x, y;
};

int main()
{
    A a(3, 4);
    a.output();

    return 0;
}
}//test3

int main()
{
    //test1::main();
    //test2::main();
    test3::main();

    return 0;
}
