/*************************************************************************
	> File Name: 24.method.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 02 Oct 2024 04:58:07 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class People{
public:
    void say(){
        cout << "say something : " << this << endl;
    }
    static void say2(){
        cout << "class method : say something" << endl;
        return ;
    }
};

int main()
{
    People a;
    a.say();
    a.say2();//1
    People::say2();//2

    return 0;
}
