/*************************************************************************
	> File Name: 3_3.using_prs.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Dec 2024 03:19:25 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;

int mytest(int a, string b) {
	cout << "a : " << a << ", b : " << b << endl;
	return 0;
}

typedef int (*func) (int, string);
using func1 = int(*) (int, string);

int main(int argc, char* argv[])
{
	func f = mytest;
	func1 f1 = mytest;
	f(10, "hello");
	f1(100, "no");
	(*f1) (10, "s");

	return 0;
}