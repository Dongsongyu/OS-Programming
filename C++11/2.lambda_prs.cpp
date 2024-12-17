/*************************************************************************
	> File Name: 2.lambda_prs.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Dec 2024 02:34:12 PM CST
 ************************************************************************/

#include<iostream>
#include<functional>
using namespace std;

void func(int x, int y) {
	int a;
	int b;
	using ptr = void(*) (int);

	ptr p1 = [] (int x) {
		cout << "x : " << x << endl;
	};
	p1(11);

	function<void(int)> fff = [=] (int x) {
		cout << "x : " << x << endl;
	};
	fff(11);

	function<void(int)> fff1 = bind([=] (int x) {
		cout << "x : " << x << endl;
	}, placeholders::_1);
	fff1(11);
}

int main()
{
	func(1, 2);
	
	return 0;
}
