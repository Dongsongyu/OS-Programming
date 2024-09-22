/*************************************************************************
	> File Name: 1.class_object.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 22 Sep 2024 08:14:15 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Cat{};
class Dog{};
class People{
public:
    string name;
    int age;

    void say(){
        cout << "My name is " << name << " , " << age << " years old ."<< endl;
        return ;
    }
};

int main()
{
    Cat garfiled;
    Dog odie1, odie2;
    People hug,yu;
    
    hug.name = "Captain Hu";
    hug.age = 50;
    hug.say();
    yu.name = "Crew Yu";
    yu.age = 23;
    yu.say();

    return 0;
}
