/*************************************************************************
	> File Name: return_houzhi.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Dec 2024 11:23:37 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
	return t + u;
}

int main()
{
	int x = 520;
	double y = 13.14;
	auto ret = add(x, y);
	cout << ret << endl;

	return 0;
}