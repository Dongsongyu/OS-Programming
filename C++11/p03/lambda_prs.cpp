/*************************************************************************
	> File Name: lambda_prs.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Dec 2024 02:13:09 PM CST
 ************************************************************************/

#include<iostream>
#include<functional>
using namespace std;

void func(int x, int y) {
	int a = 2;
	int b = 1;
	[=, &x] (int z) mutable{
		int c = a;
		int d = x;
		b++;
		cout << "b : " << b << endl;
	} (77);
	cout << "b : " << b << endl;
}
int main()
{
	func(1, 2);

	return 0;
}