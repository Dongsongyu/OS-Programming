/*************************************************************************
	> File Name: 4.noexcept.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 12 Dec 2024 06:56:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct MyException {
	MyException(string str) : msg(str) {}
	string msg;
};

//noexcept不允许抛出异常
//noexcept后面可以加参数，但是只能是常量表达式bool
void func() noexcept {
	// try {
	// 	//执行一个throw后程序就不会向下运行了
	// 	//throw 1;
	//	throw MyException("string exception!");
	// }
	
}

int main() 
{
	try {
		func();
	}
	catch(MyException e) {
		cout << "Myexception : " << e.msg << endl;
	}
	return 0;
}