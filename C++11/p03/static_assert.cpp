/*************************************************************************
	> File Name: static_assert.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 12 Dec 2024 11:16:47 AM CST
 ************************************************************************/

#include<iostream>
//#include<cassert>
using namespace std;

#if 0
char* createArray(int size) {
    assert(size > 0);
    char* array = new char[size];
    return array;
}
#endif
int main()
{
    //char* buf = createArray(10);
    static_assert(sizeof(long) == 8, "当前操作不是64位");
    cout << "hello, world" << endl;

    return 0;

}
