/*************************************************************************
	> File Name: 1.chrono.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 20 Dec 2024 06:24:04 PM CST
 ************************************************************************/

#include<iostream>
#include<chrono>
using namespace std;
using namespace chrono;

int main()
{
	//hour
	duration<int, ratio<3600>> hour(1);
	chrono::hours h(1);
	//min
	duration<int, ratio<60>> min(1);
	chrono::minutes m(1);
	//sec
	duration<int> sec(1);
	duration<double> sec1(2.5);
	chrono::seconds sec2(1);
	//msec
	duration<int, ratio<1, 1000>> msec(1);
	chrono::microseconds msec1(2);
	//micro
	duration<int, ratio<1, 1000000>> micro(1);
	chrono::microseconds micro1(3);
	//nsec
	duration<int, ratio<1, 1000000000>> nsec(1);
	chrono::nanoseconds nsec1(5);

	cout << "count : " << sec1.count() << endl; 
	cout << "count : " << nsec1.count() << endl;


	cout << "---------------------------------" << endl;
	chrono::minutes m1(9);
	chrono::minutes m2(8);
	m1++;
	m2--;
	chrono::minutes m3 = m1 = m2;

	duration<int, ratio<60, 1>> t1(10);
	duration<int, ratio<1, 1>> t2(60);
	duration<int, ratio<1, 1>> t3 = t1 - t2;

	duration<double, ratio<9, 7>> d1(3);
	duration<double, ratio<6, 5>> d2(1);
	duration<double,ratio<3, 35>> d3 = d1 - d2;

	cout << "t3 count: " << t3.count() << endl;
	cout << "d3 count: " << d3. count() << endl;

	return 0;
}
