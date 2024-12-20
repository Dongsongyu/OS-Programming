/*************************************************************************
	> File Name: 3_10.initializer_list.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Dec 2024 05:21:23 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

void traversal(std::initializer_list<int> a)
{
    for (auto it = a.begin(); it != a.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main(void)
{
    initializer_list<int> list;
    cout << "current list size: " << list.size() << endl;
    traversal(list);

    list = { 1,2,3,4,5,6,7,8,9,0};
    cout << "current list size: " << list.size() << endl;
    traversal(list);
    cout << endl;
    
    list = { 1,3,5,7,9};
    cout << "current list size: " << list.size() << endl;
    traversal(list);
    cout << endl;

    ////////////////////////////////////////////////////
    ////////////// 直接通过初始化列表传递数据 //////////////
    ////////////////////////////////////////////////////
    traversal({ 2, 4, 6, 8, 0});
    cout << endl;

    traversal({ 11,12,13,14,15,16});
    cout << endl;


    return 0;
}


