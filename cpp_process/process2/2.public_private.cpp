/*************************************************************************
	> File Name: 2.public_private.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 22 Sep 2024 10:54:56 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class People{
public:
    string name;
    int age;
    
private:
    void say(){
        cout << "My name is " << name << ", " << age << " years old" << endl;
    }
};

int main()
{
    People hug;
    hug.name = "Captain Hu";
    hug.age = 50;
    
    return 0;
}
